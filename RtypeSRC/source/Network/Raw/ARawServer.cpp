//
// ARawServer.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Network/Raw
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Dec  5 15:31:10 2016 Gandoulf
// Last update Tue Dec  6 09:35:03 2016 Gandoulf
//

#include <iostream>
#include "Network/Raw/ARawServer.hpp"

ARawServer::ARawServer(unsigned short const &port, std::string proto)
  : _port(port), _protocol(proto)
{
  _server.OnConnect([this](Socket::Server & server, int fd)
		    {
		      onConnect(server, fd);
		    });
  _server.OnDisconnect([this](Socket::Server & server, int fd)
		       {
			 onDisconnect(server, fd);
		       });
  _server.OnReadPossible([this](Socket::Server & server, int fd, size_t length)
			 {
			   onRead(server, fd, length);
			 });
  _server.OnWritePossible([this](Socket::Server & server, int fd)
			  {
			    onWrite(server, fd);
			  });
  _server.OnStart([this](Socket::Server & server, int port)
		  {
		    onStart(server, port);
		  });
}

ARawServer::~ARawServer()
{
}

void ARawServer::run()
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

void ARawServer::onConnect(Socket::Server & server, int fd)
{
  std::cout << "raw server : connection" << std::endl;
}

void ARawServer::onDisconnect(Socket::Server & server, int fd)
{
    std::cout << "raw server : disconnection" << std::endl;
}

void ARawServer::onRead(Socket::Server & server, int fd, size_t length)
{

}

void ARawServer::onWrite(Socket::Server & server, int fd)
{

}

void ARawServer::onStart(Socket::Server & server, int fd)
{
  std::cout << "raw server : start" << std::endl;
}

void ARawServer::start()
{
  _server.start(_port, RAW_MAW_CLIENT);
}

void ARawServer::stop()
{
  _server.stop();
}