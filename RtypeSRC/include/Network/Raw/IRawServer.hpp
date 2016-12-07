//
// IRawServer.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Network/Raw
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Dec  5 15:57:39 2016 Gandoulf
// Last update Tue Dec  6 09:36:27 2016 Gandoulf
//

#ifndef IRAWSERVER_HPP_
# define IRAWSERVER_HPP_

# include <string>
# include "Network/sockets/Server.hpp"

class IRawServer
{
public:
  virtual void run() = 0;

protected:
  virtual void onConnect(Socket::Server & server, int fd) = 0;
  virtual void onDisconnect(Socket::Server & server, int fd) = 0;
  virtual void onRead(Socket::Server & server, int fd, size_t length) = 0;
  virtual void onWrite(Socket::Server & server, int fd) = 0;
  virtual void onStart(Socket::Server & server, int fd) = 0;

  virtual void start() = 0;
  virtual void stop() = 0;
};

#endif /* IRAWSERVER_HPP_ */
