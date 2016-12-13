//
// RtypePacketReader.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/IONetworkManager
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed Dec  7 15:08:04 2016 Gandoulf
// Last update Wed Dec  7 18:16:44 2016 Gandoulf
//

#include "IONetwork/RtypePacketReader.hpp"
#include <cstring>

namespace rtype
{
  RtypePacketReader::RtypePacketReader()
    :_header(NULL)
  {

  }

  RtypePacketReader::~RtypePacketReader()
  {

  }

  char *RtypePacketReader::read(Socket::Server & server, int const &fd, size_t const &length)
  {
    getHeader(server, fd, length);
    getData(server, fd, length);
    return (getPacket());
  }

  /*-----------------------------------private----------------------------------*/

  // TODO getHeader counter, kick client when counter is to hight(inc counder when getHeader fail)
  // TODO same for Data
  // TODO reset socket
  void RtypePacketReader::getHeader(Socket::Server & server, int const &fd, size_t const &length)
  {
    if (_header != NULL)
      return ;
    if (length >= sizeof(Header))
      {
	_header = new Header;
	if (server.read(fd, (void *)(_header), sizeof(Header)) != sizeof(Header)) {
	  deleteHeader();
	  return ;
	}
	if (_header->magicNumber != MAGIC_NUMBER || _header->size > MAX_PAQUET_SIZE) {
	  deleteHeader();
	  return ;
	}
      }
  }

  void RtypePacketReader::getData(Socket::Server & server, int const &fd, size_t const &length)
  {
    if (_header == NULL)
      return ;
    if (length >= _header->size)
      {
	_data = new char[_header->size];
	if (server.read(fd, (void *)(_data), _header->size) != _header->size) {
	  deleteHeader();
	  deleteData();
	  return ;
	}
      }
  }

  char *RtypePacketReader::getPacket()
  {
    if (_header == NULL || _data == NULL)
      return (NULL);
    char *packet;
    packet = new char[sizeof(Header) + _header->size];
    std::memcpy(packet, _header, sizeof(Header));
    std::memcpy(packet + sizeof(Header), _data, _header->size);
    deleteHeader();
    deleteData();
    return (packet);
  }

  inline void RtypePacketReader::deleteHeader()
  {
    delete _header;
    _header = NULL;
  }

  inline void RtypePacketReader::deleteData()
  {
    delete _data;
    _data = NULL;
  }
}
