//
// IPacketReader.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/IONetwork
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Dec  6 15:15:29 2016 Gandoulf
// Last update Wed Dec  7 15:04:02 2016 Gandoulf
//

#ifndef IPACKETREADER_HPP_
# define IPACKETREADER_HPP_

# include "Network/sockets/Server.hpp"

namespace rtype
{
  class IPacketReader
  {
  public:
    virtual char *read(Socket::Server & server, int const &fd, size_t const &length) = 0;
  };
}

#endif /* IPACKETREADER_HPP_ */
