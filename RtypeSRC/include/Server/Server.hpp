//
// server.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Nov 28 17:01:47 2016 Gandoulf
// Last update Sat Dec 17 11:02:11 2016 Gandoulf
//

#ifndef RTYPE_SERVER_HPP_
# define RTYPE_SERVER_HPP_

# include <string>
# include <vector>
# include <memory>
# include <map>
# include "Network/sockets/Server.hpp"
# include "Server/RoomManager.hpp"
# include "Network/Raw/ARawServer.hpp"
# include "IONetwork/IONetworkManager.hpp"
# include "IONetwork/RtypeSerializer.hpp"
# include "IONetwork/RtypePacketReader.hpp"
# include "Protocol/TcpEvent.hpp"

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

  private:
    void disconnect();

  private:
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

  protected:
    virtual void onConnect(Socket::Server & server, int fd);
    virtual void onDisconnect(Socket::Server & server, int fd);
    virtual void onRead(Socket::Server & server, int fd, size_t length);
    virtual void onWrite(Socket::Server & server, int fd);
    virtual void onStart(Socket::Server & server, int fd);

    virtual void start();
    virtual void stop();
    void accept(int fd);

  private:
    //Network
    unsigned int			_maxClient;

    //clients
    std::map<int, client_ptr>		_clients;
    RoomManager				_room;

    //script
    std::vector<std::string>		_script;
  };
}

#endif /* RTYPE_SERVER_HPP_ */
