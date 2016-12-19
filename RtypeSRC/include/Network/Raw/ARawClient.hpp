//
// ARawServer.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Network/Raw
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Dec  5 15:21:12 2016 Gandoulf
// Last update Tue Dec 13 14:29:57 2016 Gandoulf
//

#ifndef ARAWSERVER_HPP_
# define ARAWSERVER_HPP_

# include "Network/Raw/IRawClient.hpp"

class ARawClient : public IRawClient
{
public:
  ARawClient(unsigned short const &port, std::string const & adresse, std::string proto = "tcp");
  virtual ~ARawClient();

  virtual void run();

protected:
  virtual void onDisconnect(Socket::Client & client);
  virtual void onRead(Socket::Client & client, size_t length);
  virtual void onWrite(Socket::Client & client);
  virtual void onStart(Socket::Client & client, std::string const &address, int port);

  virtual void start();
  virtual void stop();

protected:
  Socket::Client	_client;
  unsigned short	_port;
  std::string		_adresse;
  std::string		_protocol;
};

#endif /* ARAWSERVER_HPP_ */
