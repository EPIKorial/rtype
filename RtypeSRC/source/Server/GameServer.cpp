//
// GameServer.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Server
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Fri Dec 16 22:03:12 2016 Gandoulf
// Last update Fri Dec 23 15:09:33 2016 Gandoulf
//

#include "Server/GameServer.hpp"
#include "Server/Server.hpp"
#include <iostream>
#ifdef _WIN32
# include <windows.h>
#else
# include <unistd.h>
#endif

namespace rtype
{
  GameClient::GameClient(int const & fd, Socket::Server &server, std::queue<IEvent *> & event,
			 std::queue<IEvent *> & clientInputs)
    : _fd(fd), _server(server), _event(event), _clientInputs(clientInputs)
  {

  }

  GameClient::~GameClient()
  {

  }

  void GameClient::read(Socket::Server & server, int fd, size_t length)
  {
    IEvent *paquet;

    _networkManager.updateR(server, fd, length);
    paquet = _networkManager.pop();
    if (paquet != NULL && paquet->getType() == MESSAGE) //TODO delete
      std:: cout << static_cast<tcpEvent::Message *>(paquet)->message << std::endl;
    if (paquet != NULL)
      _clientInputs.push(paquet);
  }

  void GameClient::write(Socket::Server & server, int fd)
  {
    _networkManager.updateW(server, fd);
    if (_event.size() > 0) {
      _networkManager.push(_event.front());
      _event.pop();
    }
  }

  /* ----------------------------GameServer------------------------ */

  GameServer::GameServer(unsigned short &port, std::string proto, std::string const & name,
			 unsigned int const &maxClient)
    : ARawServer(port, proto), _name(name), _maxClient(maxClient),
      _gameManager(_name, _event, _clientInputs), _roomPort(port)
  {

  }

  GameServer::~GameServer()
  {
    stop();
  }

  void GameServer::run()
  {
    start();
  }

  void GameServer::stopServer()
  {
    stop();
  }

  void GameServer::setMaxClient(unsigned int const & maxClient)
  {
    _maxClient = maxClient;
  }

  void GameServer::setPlayers(std::map<int, Client> const & players)
  {
    _players = players;
  }

  /* -----------------------------Protected----------------------------*/

  void GameServer::onConnect(Socket::Server & server, int fd)
  {
    std::cout << "connection" << std::endl;
    accept(fd);
  }

  void GameServer::onDisconnect(Socket::Server & server, int fd)
  {
    std::cout << "disconnection" << std::endl;
    auto disconnectedClient = _clients.find(fd);
    if (disconnectedClient != _clients.end())
      _clients.erase(disconnectedClient);
    auto eventClient = _event.find(fd);
    if (eventClient != _event.end())
      _event.erase(eventClient);
  }

  void GameServer::onRead(Socket::Server & server, int fd, size_t length)
  {
    auto readingClient = _clients.find(fd);
    if (readingClient != _clients.end())
      readingClient->second->read(server, fd, length);
  }

  void GameServer::onWrite(Socket::Server & server, int fd)
  {
    auto writingClient = _clients.find(fd);
    if (writingClient != _clients.end())
      writingClient->second->write(server, fd);
  }

  void GameServer::onStart(Socket::Server & server, int fd)
  {
    std::cout << "starting UDP server" << std::endl;
    _gameManager.start();
  }

  void GameServer::onTick(Socket::Server & server)
  {
    std::cout << "tick" << std::endl;
    _gameManager.managerUpdate();
  }

  void GameServer::start()
  {
    bool connected = false;
    while (connected == false)
      try {
	std::cout << _roomPort << std::endl;
	_server.start(_roomPort, _maxClient, "tcp");
	connected = true;
      } catch (const std::exception e) {
	std::cout << "port taken can't launch server" << std::endl;
	_roomPort = Server::getPort();
#ifdef _WIN32
	Sleep(10);
#else
	usleep(10);
#endif
      }
  }

  void GameServer::stop()
  {
    for (auto clients = _clients.begin(); clients != _clients.end(); clients = _clients.begin())
      _clients.erase(clients);
    try {
      _server.stop();
    } catch (const std::exception error){
      std::cout << "server already close" << std::endl;
    }
  }

  /* -------------------------------Private-------------------------------- */

  void GameServer::accept(int fd)
  {
    _event.insert(std::make_pair(fd, std::queue<IEvent *>()));
    _clientInputs.insert(std::make_pair(fd, std::queue<IEvent *>()));
    GameClient_ptr client(new GameClient(fd, _server, _event[fd], _clientInputs[fd]));
    _clients.insert(std::make_pair(fd, std::move(client)));
  }
}
