//
// GameServer.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Server
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Fri Dec 16 22:02:19 2016 Gandoulf
// Last update Sat Dec 17 12:03:41 2016 Gandoulf
//

#ifndef GAMESERVER_HPP_
# define GAMESERVER_HPP_

# include <map>
# include <queue>
# include <memory>
# include "Network/Raw/ARawServer.hpp"
# include "Server/RoomClient.hpp"
# include "IONetwork/IONetworkManager.hpp"
# include "IONetwork/RtypeSerializer.hpp"
# include "IONetwork/RtypePacketReader.hpp"
# include "Protocol/TcpEvent.hpp"
# include "Protocol/UdpEvent.hpp"
# include "Rtype/GameManager.hpp"

namespace rtype
{
  class GameClient;
  typedef std::unique_ptr<GameClient> GameClient_ptr;

  class GameClient
  {
    typedef IONetworkManager<IEvent, Socket::Server, RtypeSerializer, RtypePacketReader> IOServer;
  public:
    GameClient(int const & fd, Socket::Server &server, std::queue<IEvent *> & event,
	       std::queue<IEvent *> & clientInputs);
    ~GameClient();

    void read(Socket::Server & server, int fd, size_t length);
    void write(Socket::Server & server, int fd);

  private:
    void disconnect();

  private:
    int				_fd;
    IOServer			_networkManager;
    std::queue<IEvent *>	&_event;
    std::queue<IEvent *>	&_clientInputs;
    Socket::Server		&_server;
  };

  class GameServer : public ARawServer
  {
  public:
    GameServer(unsigned short const &port, std::string proto = "tcp",
	       unsigned int const &maxClient = 4);
    virtual ~GameServer();

    virtual void run();

    void stopServer();
    void setMaxClient(unsigned int const & maxClient);
    void setPlayers(std::map<int, Client> const & players);

  protected:
    virtual void onConnect(Socket::Server & server, int fd);
    virtual void onDisconnect(Socket::Server & server, int fd);
    virtual void onRead(Socket::Server & server, int fd, size_t length);
    virtual void onWrite(Socket::Server & server, int fd);
    virtual void onStart(Socket::Server & server, int fd);

    virtual void start();
    virtual void stop();

  private:
    void accept(int fd);

  private:
    unsigned int				_maxClient;
    std::map<int, Client>			_players;
    std::map<int, GameClient_ptr>		_clients;
    std::map<int, std::queue<IEvent *>>		_event;
    std::queue<IEvent *>			_clientInputs;
    GameManager					_gameManager;
  };
}

#endif /* GAMESERVER_HPP_ */
