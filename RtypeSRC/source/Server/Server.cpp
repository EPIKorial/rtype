//
// server.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/server
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Nov 28 16:58:59 2016 Gandoulf
// Last update Sat Dec 17 11:12:35 2016 Gandoulf
//

#include "Server/Server.hpp"
#include <iostream>
#include <cstdlib>

namespace rtype
{
  TcpClient::TcpClient(int const & fd, Socket::Server &server, RoomManager &room)
    : _fd(fd), _server(server), _room(room)
  {
    std::cout << "client on fd : " << fd << " connected" << std::endl;
    std::cout << "client connected " << std::boolalpha << _room.connect("macouille") << std::endl;
    std::cout << room.getMessage("macouille") << std::endl;
    _room.getRoomList("macouille");
    std::cout << "room list\n" << room.getMessage("macouille") << std::endl;
    _room.createRoom("TOTO", "macouille");
    std::cout << room.getMessage("macouille") << std::endl;
  }

  TcpClient::~TcpClient()
  {
    std::cout << "client on fd : " << _fd << " disconnected" << std::endl;
    _room.disconnect("macouille");
  }

  void TcpClient::leaveRoom()
  {

  }

  void TcpClient::read(Socket::Server & server, int fd, size_t length)
  {
    IEvent *paquet;

    _networkManager.updateR(server, fd, length);
    paquet = _networkManager.pop();
    if (paquet != NULL && paquet->getType() == MESSAGE) //TODO delete
      std:: cout << static_cast<tcpEvent::Message *>(paquet)->message << std::endl;
    delete paquet;
  }

  void TcpClient::write(Socket::Server & server, int fd)
  {
    _networkManager.updateW(server, fd);
    if (_name.size() > 0) {
      std::string msg = _room.getMessage(_name);
      if (msg.size() > 0) {
	tcpEvent::Message *tcpMsg = new tcpEvent::Message(msg, msg.size());
	_networkManager.push(tcpMsg);
      }
    }
  }

  //private

  void TcpClient::disconnect()
  {
    _server.disconnect(_fd);
  }

  /*----------------------------------------server------------------------------------------*/
  Server::Server(unsigned short const &port, std::vector<std::string> const & script,
		 std::string proto, unsigned int const &maxClient)
    : ARawServer(port, proto), _script(script), _maxClient(maxClient)
  {
  }

  Server::~Server()
  {
    for (auto clients = _clients.begin(); clients != _clients.end(); clients = _clients.begin())
      _clients.erase(clients);
  }

  void Server::run()
  {
    start();

    char line[100];
    while (std::cin.getline(line, 100)) {
      if (!std::strncmp(line, "quit", 4))
	{
	  stop();
	  break;
	}
    }
  }

  //protected

  void Server::onConnect(Socket::Server & server, int fd)
  {
    std::cout << "connection" << std::endl;
    accept(fd);
  }

  void Server::onDisconnect(Socket::Server & server, int fd)
  {
    std::cout << "disconnection" << std::endl;
    auto disconnectedClient = _clients.find(fd);
    if (disconnectedClient != _clients.end())
      {
	disconnectedClient->second->leaveRoom();
	_clients.erase(disconnectedClient);
      }
  }

  void Server::onRead(Socket::Server & server, int fd, size_t length)
  {
    auto readingClient = _clients.find(fd);
    if (readingClient != _clients.end())
      readingClient->second->read(server, fd, length);
  }

  void Server::onWrite(Socket::Server & server, int fd)
  {
    auto writingClient = _clients.find(fd);
    if (writingClient != _clients.end())
      writingClient->second->write(server, fd);
  }

  void Server::onStart(Socket::Server & server, int fd)
  {
    std::cout << "starting TCP server" << std::endl;
  }

  void Server::start()
  {
    try {
      _server.start(_port, _maxClient, _protocol.c_str());
    } catch (const std::exception e) {
      std::cout << "can't launch server" << std::endl;
    }
  }

  void Server::stop()
  {
    try {
      _server.stop();
    } catch (const std::exception error) {
      std::cout << "server already close" << std::endl;
    }
  }

  void Server::accept(int fd)
  {
    client_ptr client(new TcpClient(fd, _server, _room));
    _clients.insert(std::make_pair(fd, std::move(client)));
  }
}
