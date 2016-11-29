//
// server.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/server
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Nov 28 16:58:59 2016 Gandoulf
// Last update Tue Nov 29 18:31:33 2016 Gandoulf
//

#include "Server/Server.hpp"
#include <iostream>
#include <cstdlib>

namespace rtype
{
  Server::Server(unsigned int const &maxClient)
    : _maxClient(maxClient)
  {
    _server.OnConnect([this](Socket::Server & server, int fd)
		      {
			std::cout << "connection" << std::endl;
		      });
    _server.OnDisconnect([this](Socket::Server & server, int fd)
			 {
			   std::cout << "disconnection" << std::endl;
			 });
    _server.OnReadPossible([this](Socket::Server & server, int fd, size_t length)
			   {
			   });
    _server.OnWritePossible([this](Socket::Server & server, int fd)
			    {
			    });
    _server.OnStart([this](Socket::Server & server, int port)
		    {
		      std::cout << "starting TCP server" << std::endl;
		    });
  }

  Server::~Server()
  {

  }

  void Server::run(unsigned short const &port, std::vector<std::string> const & script)
  {
    _port = port;
    _script = script;
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

  //private

  void Server::start()
  {
    _server.start(_port, _maxClient);
  }

  void Server::stop()
  {
    _server.stop();
  }
}
