//
// server.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Nov 28 17:01:47 2016 Gandoulf
// Last update Fri Dec 23 10:15:28 2016 Gandoulf
//

#ifndef RTYPE_SERVER_HPP_
# define RTYPE_SERVER_HPP_

# include <string>
# include <vector>
# include <memory>
# include <map>
# include <sstream>
# include "Network/sockets/Server.hpp"
# include "Server/RoomManager.hpp"
# include "Network/Raw/ARawServer.hpp"
# include "IONetwork/IONetworkManager.hpp"
# include "IONetwork/RtypeSerializer.hpp"
# include "IONetwork/RtypePacketReader.hpp"
# include "Protocol/TcpEvent.hpp"
# include "Rtype/ScriptContener.hpp"
# include "Utils/MutexedContener.hpp"

# define MAX_CLIENT 10000

namespace rtype
{
  class TcpClient;
  typedef std::unique_ptr<TcpClient> client_ptr;

  class TcpClient
  {
    typedef IONetworkManager<IEvent, Socket::Server, RtypeSerializer, RtypePacketReader> IOServer;
  public:
    TcpClient(int const & fd, Socket::Server &server, RoomManager &_room);
    ~TcpClient();

    void leaveRoom();
    void read(Socket::Server & server, int fd, size_t length);
    void write(Socket::Server & server, int fd);

    class TcpRequest
    {
    public:
      TcpRequest(std::string const& str);
      ~TcpRequest();

      std::string nickName;
      std::string cmd;
      std::string roomName;

      bool isValid() const;

    private:
      std::vector<std::string> _tokens;
      bool _isValid;
    };

  private:
    void disconnect();

  private:
    int	handleRequest(const TcpRequest *req);

    //Network
    int									_fd;
    Socket::Server							&_server;
    IOServer								_networkManager;

    //client
    std::string								_name;
    RoomManager								&_room;
  };

  class Server : public ARawServer
  {
  public:
    Server(unsigned short const &port, std::vector<std::string> const & script,
	   std::string proto = "tcp", unsigned int const &maxClient = MAX_CLIENT);
    virtual ~Server();

    virtual void run();

    static ScriptContener &getScriptContenener();
    static int getPort();

  protected:
    virtual void onConnect(Socket::Server & server, int fd);
    virtual void onDisconnect(Socket::Server & server, int fd);
    virtual void onRead(Socket::Server & server, int fd, size_t length);
    virtual void onWrite(Socket::Server & server, int fd);
    virtual void onStart(Socket::Server & server, int fd);
    virtual void onTick(Socket::Server & server);

    virtual void start();
    virtual void stop();
    void accept(int fd);

  private:
    void updatePrefab(std::string prefabName, std::vector<std::string> & libs);
    void loadLibrary(Properties & _properties, Memory::LibraryLoader & _library,
		     bool &_usable, int it);

  public:
    static MutexContener<std::vector<std::string> >	_gameServerEnded;

  private:
    //Network
    unsigned int					_maxClient;

    //clients
    std::map<int, client_ptr>				_clients;
    RoomManager						_room;

    //script
    static ScriptContener				_scriptContener;
    static MutexContener<int>				_gameServerPort;
    std::vector<std::string>				_script;
    std::string						_prefabName;
  };
}

#endif /* RTYPE_SERVER_HPP_ */
