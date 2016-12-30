//
// ARawServer.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Network/Raw
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Dec  5 15:21:12 2016 Gandoulf
// Last update Tue Dec  6 09:34:30 2016 Gandoulf
//

#ifndef ARAWSERVER_HPP_
# define ARAWSERVER_HPP_

# include "IRawServer.hpp"
# define RAW_MAW_CLIENT 1000

class ARawServer : public IRawServer
{
public:
  ARawServer(unsigned short const &port, std::string proto = "tcp");
  virtual ~ARawServer();

  virtual void run();

protected:
  virtual void onConnect(Socket::Server & server, int fd);
  virtual void onDisconnect(Socket::Server & server, int fd);
  virtual void onRead(Socket::Server & server, int fd, size_t length);
  virtual void onWrite(Socket::Server & server, int fd);
  virtual void onStart(Socket::Server & server, int fd);
  virtual void onTick(Socket::Server & server);

  virtual void start();
  virtual void stop();

protected:
  Socket::Server	_server;
  unsigned short	_port;
  std::string		_protocol;
};

#endif /* ARAWSERVER_HPP_ */
