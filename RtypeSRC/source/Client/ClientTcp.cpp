//
// ARawClient.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Server
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Dec 13 14:24:29 2016 Gandoulf
// Last update Fri Dec 16 21:41:18 2016 Gandoulf
//

# include "Client/ClientTcp.hpp"
# include <iostream>

namespace rtype
{
  ClientTcp::ClientTcp(unsigned short const &port, std::string const & adresse, std::string proto)
    : ARawClient(port, adresse, proto)
  {
  }

  ClientTcp::~ClientTcp()
  {

  }

  void ClientTcp::run()
  {
    start();

    char line[100];
    while (std::cin.getline(line, 100)) {
      if (!std::strncmp(line, "quit", 4))
	{
	  stop();
	  break;
	}
      else if (!std::strncmp(line, "M", 1)) {
	if (strlen(line) > 2) {
	  rtype::tcpEvent::Message *msg = new rtype::tcpEvent::Message(line + 1, strlen(line + 1));
	  _networkManager.push(msg);
	}
      }
      else if (!std::strncmp(line, "P", 1)) {
	PosUpdate data;
	data.ID =39;
	data.x = 2;
	data.y = 90;
	rtype::udpEvent::EPosUpdate *msg = new rtype::udpEvent::EPosUpdate(data);
	_networkManager.push(msg);
      }
      else if (!std::strncmp(line, "F", 1)) {
	Fire data;
	data.ID =39;
	data.x = 2;
	data.y = 90;
	data.bulletID = 20;
	rtype::udpEvent::EFire *msg = new rtype::udpEvent::EFire(data);
	_networkManager.push(msg);
      }
      else if (!std::strncmp(line, "I", 1)) {
	Instantiate data;
	data.ID =39;
	data.x = 2;
	data.y = 90;
	data.scale_x = 200;
	data.scale_y = 190;
	data.goID = 42;
	rtype::udpEvent::EInstantiate *msg = new rtype::udpEvent::EInstantiate(data);
	_networkManager.push(msg);
      }
      else if (!std::strncmp(line, "C", 1)) {
	Collision data;
	data.ID1 =39;
	data.ID2 =93;
	rtype::udpEvent::ECollision *msg = new rtype::udpEvent::ECollision(data);
	_networkManager.push(msg);
      }
      else if (!std::strncmp(line, "D", 1)) {
	Deletion data;
	data.ID = 63;
	rtype::udpEvent::EDeletion *msg = new rtype::udpEvent::EDeletion(data);
	_networkManager.push(msg);
      }
    }
  }

  void ClientTcp::onDisconnect(Socket::Client & client)
  {
    std::cout << "disconnection" << std::endl;
  }

  void ClientTcp::onRead(Socket::Client & client, size_t length)
  {
    _networkManager.updateR(client, 0, length);
  }

  void ClientTcp::onWrite(Socket::Client & client)
  {
    _networkManager.updateW(client, 0);
  }

  void ClientTcp::onStart(Socket::Client & client, std::string const &address, int port)
  {
    std::cout << "client starting" << std::endl;
  }

  void ClientTcp::start()
  {
    try {
      _client.start(_adresse, _port, _protocol.c_str());
    } catch (const std::exception e) {
      std::cout << "server not connected" << std::endl;
    }
  }

  void ClientTcp::stop()
  {
    try {
      _client.stop();
    } catch (const std::exception error) {
      std::cout << "client already close" << std::endl;
    }
  }
}
