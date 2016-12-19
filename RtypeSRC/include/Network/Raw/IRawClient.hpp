//
// IRawServer.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Network/Raw
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Dec  5 15:57:39 2016 Gandoulf
// Last update Tue Dec 13 15:10:18 2016 Gandoulf
//

#ifndef IRAWCLIEBT_HPP_
# define IRAWCLIEBT_HPP_

# include <string>
# include "Network/sockets/Client.hpp"

class IRawClient
{
public:
  virtual void run() = 0;

protected:
  virtual void onDisconnect(Socket::Client & client) = 0;
  virtual void onRead(Socket::Client & client, size_t length) = 0;
  virtual void onWrite(Socket::Client & client) = 0;
  virtual void onStart(Socket::Client & client, std::string const &adresse, int port) = 0;

  virtual void start() = 0;
  virtual void stop() = 0;
};

#endif /* IRAWCLIEBT_HPP_ */
