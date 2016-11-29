//
// server.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Nov 28 17:01:47 2016 Gandoulf
// Last update Tue Nov 29 18:30:58 2016 Gandoulf
//

#ifndef RTYPE_SERVER_HPP_
# define RTYPE_SERVER_HPP_

# include <string>
# include <vector>
#include "Network/sockets/Server.hpp"

# define MAX_CLIENT 10000

namespace rtype
{
  class Server
  {
  public:
    Server(unsigned int const &maxClient = MAX_CLIENT);
    ~Server();

    void run(unsigned short const &port, std::vector<std::string> const & script);

  private:
    void start();
    void stop();

  private:
    Socket::Server			_server;
    unsigned int			_maxClient;
    unsigned short			_port;
    std::vector<std::string>		_script;
  };
}

#endif /* RTYPE_SERVER_HPP_ */
