//
// ARawClient.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Server
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Dec 13 14:24:29 2016 Gandoulf
// Last update Thu Dec 29 11:25:35 2016 Gandoulf
//

# include "ARawClient.hpp"
# include <iostream>

ARawClient::ARawClient(unsigned short const &port, std::string const & adresse, std::string proto)
  : _port(port), _adresse(adresse), _protocol(proto)
{
  _client.setTimeout(50);
  _client.OnReadPossible([this](Socket::Client &client, size_t length)
			 {
			   onRead(client, length);
			 });
  _client.OnWritePossible([this](Socket::Client &client)
			  {
			    onWrite(client);
			  });
  _client.OnStart([this](Socket::Client &client, std::string const &adresse, int port)
		  {
		    onStart(client, adresse, port);
		  });
  _client.OnDisconnect([this](Socket::Client &client)
		       {
			 onDisconnect(client);
		       });
}

ARawClient::~ARawClient()
{

}

void ARawClient::run()
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

void ARawClient::onDisconnect(Socket::Client & client)
{
  std::cout << "disconnection" << std::endl;
}

void ARawClient::onRead(Socket::Client & client, size_t length)
{

}

void ARawClient::onWrite(Socket::Client & client)
{

}

void ARawClient::onStart(Socket::Client & client, std::string const &address, int port)
{
  std::cout << "client starting" << std::endl;
}

void ARawClient::start()
{
  try {
    _client.start(_adresse, _port);
  } catch (const std::exception e) {
    std::cout << "server not connected" << std::endl;
  }
}

void ARawClient::stop()
{
  try {
    _client.stop();
  } catch (const std::exception error) {
    std::cout << "client already close" << std::endl;
  }
}
