//
// RtypePacketReader.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/IONetwork
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Dec  6 15:31:16 2016 Gandoulf
// Last update Fri Dec 16 16:12:55 2016 Gandoulf
//

#ifndef RTYPEPACKETREADER_HPP_
# define RTYPEPACKETREADER_HPP_

# include "IPacketReader.hpp"
# include "Protocol.h"

namespace rtype
{
  template <class socket>
  class RtypePacketReader : public IPacketReader<socket>
  {
  public:
    RtypePacketReader();
    ~RtypePacketReader();

    virtual char *read(socket & connection, int const &fd, size_t const &length);

  private:
    void getHeader(socket & connection, int const &fd, size_t const &length);
    void getData(socket & connection, int const &fd, size_t const &length);
    char *getPacket();

    void deleteHeader();
    void deleteData();

  private:
    Header	*_header;
    char	*_data;
  };

  template <>
  class RtypePacketReader<Socket::Server> : public IPacketReader<Socket::Server>
  {
  public:
    RtypePacketReader()
      :_header(NULL)
    {}
    ~RtypePacketReader()
    {}

    virtual char *read(Socket::Server & connection, int const &fd, size_t const &length)
    {
      getHeader(connection, fd, length);
      getData(connection, fd, length);
      return (getPacket());
    }

  private:
    void getHeader(Socket::Server & connection, int const &fd, size_t const &length)
    {
      if (_header != NULL)
	return ;
      if (length >= sizeof(Header))
	{
	  _header = new Header;
	  if (connection.read(fd, (void *)(_header), sizeof(Header)) != sizeof(Header)) {
	    deleteHeader();
	    return ;
	  }
	  if (_header->magicNumber != MAGIC_NUMBER || _header->size > MAX_PAQUET_SIZE) {
	    deleteHeader();
	    return ;
	  }
      }
    }

    void getData(Socket::Server & connection, int const &fd, size_t const &length)
    {
      if (_header == NULL)
	return ;
      if (length >= _header->size)
	{
	  _data = new char[_header->size];
	  if (connection.read(fd, (void *)(_data), _header->size) != _header->size) {
	    deleteHeader();
	    deleteData();
	    return ;
	  }
	}
    }

    char *getPacket()
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

    void deleteHeader()
    {
      delete _header;
      _header = NULL;
    }

    void deleteData()
    {
      delete[] _data;
      _data = NULL;
    }

  private:
    Header	*_header;
    char	*_data;
  };

  template <>
  class RtypePacketReader<Socket::Client> : public IPacketReader<Socket::Client>
  {
  public:
    RtypePacketReader()
      :_header(NULL)
    {}
    ~RtypePacketReader()
    {}

    virtual char *read(Socket::Client & connection, int const &fd, size_t const &length)
    {
      getHeader(connection, fd, length);
      getData(connection, fd, length);
      return (getPacket());
    }

  private:
    void getHeader(Socket::Client & connection, int const &fd, size_t const &length)
    {
      if (_header != NULL)
	return ;
      if (length >= sizeof(Header))
	{
	  _header = new Header;
	  if (connection.read((void *)(_header), sizeof(Header)) != sizeof(Header)) {
	    deleteHeader();
	    return ;
	  }
	  if (_header->magicNumber != MAGIC_NUMBER || _header->size > MAX_PAQUET_SIZE) {
	    deleteHeader();
	    return ;
	  }
	}
    }

    void getData(Socket::Client & connection, int const &fd, size_t const &length)
    {
      if (_header == NULL)
	return ;
      if (length >= _header->size)
	{
	  _data = new char[_header->size];
	  if (connection.read((void *)(_data), _header->size) != _header->size) {
	    deleteHeader();
	    deleteData();
	    return ;
	  }
	}
    }

    char *getPacket()
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

    void deleteHeader()
    {
      delete _header;
      _header = NULL;
    }

    void deleteData()
    {
      delete[] _data;
      _data = NULL;
    }

  private:
    Header	*_header;
    char	*_data;
  };
}

#endif /* RTYPEPACKETREADER_HPP_ */
