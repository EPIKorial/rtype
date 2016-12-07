//
// RtypePacketReader.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/IONetwork
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Dec  6 15:31:16 2016 Gandoulf
// Last update Wed Dec  7 16:38:07 2016 Gandoulf
//

#ifndef RTYPEPACKETREADER_HPP_
# define RTYPEPACKETREADER_HPP_

# include "IONetwork/IPacketReader.hpp"

namespace rtype
{
  class RtypePacketReader : public IPacketReader
  {
  public:
    RtypePacketReader();
    ~RtypePacketReader();

    virtual char *read(Socket::Server & server, int const &fd, size_t const &length);

  private:

  };
}

#endif /* RTYPEPACKETREADER_HPP_ */
