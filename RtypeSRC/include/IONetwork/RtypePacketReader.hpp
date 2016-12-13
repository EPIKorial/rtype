//
// RtypePacketReader.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/IONetwork
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Dec  6 15:31:16 2016 Gandoulf
// Last update Wed Dec  7 18:13:49 2016 Gandoulf
//

#ifndef RTYPEPACKETREADER_HPP_
# define RTYPEPACKETREADER_HPP_

# include "IONetwork/IPacketReader.hpp"
# include "Protocol/Protocol.h"

namespace rtype
{
  class RtypePacketReader : public IPacketReader
  {
  public:
    RtypePacketReader();
    ~RtypePacketReader();

    virtual char *read(Socket::Server & server, int const &fd, size_t const &length);

  private:
    void getHeader(Socket::Server & server, int const &fd, size_t const &length);
    void getData(Socket::Server & server, int const &fd, size_t const &length);
    char *getPacket();

    void deleteHeader();
    void deleteData();

  private:
    Header	*_header;
    char	*_data;
  };
}

#endif /* RTYPEPACKETREADER_HPP_ */
