//
// IPacketReader.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/IONetwork
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Dec  6 15:15:29 2016 Gandoulf
// Last update Thu Dec 15 16:09:31 2016 Gandoulf
//

#ifndef IPACKETREADER_HPP_
# define IPACKETREADER_HPP_

# include "Server.hpp"
# include "Client.hpp"

namespace rtype
{
  template <class socket>
  class IPacketReader
  {
  public:
    virtual char *read(socket & server, int const &fd, size_t const &length) = 0;
  };
}

#endif /* IPACKETREADER_HPP_ */
