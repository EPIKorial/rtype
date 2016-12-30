//
// IONetworkManager.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/IONetworkManager
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Dec  6 14:09:53 2016 Gandoulf
// Last update Fri Dec 23 17:13:25 2016 Gandoulf
//

#ifndef IONETWORKMANAGER_HPP_
# define IONETWORKMANAGER_HPP_

#include <iostream> //TODO delete

#include "ISerializer.hpp"
#include "IPacketReader.hpp"
#include "Server.hpp"
#include "Client.hpp"
#include <queue>

namespace rtype
{
  template<typename Packet, typename Connection, template <class> class Serializer,
	   template <class> class PacketReader>
  class IONetworkManager
  {
  public:
    IONetworkManager();
    ~IONetworkManager();
    void        push(Packet *event);
    Packet      *pop();
    void        updateR(Connection & connection, int const &fd, size_t const &length);
    void        updateW(Connection & connection, int const &fd);

  private:
    std::queue<Packet *>	_received;
    std::queue<Packet *>	_toSend;
    ISerializer<Packet>		*_serializer;
    IPacketReader<Connection>	*_packetReader;
  };


  template<typename Packet, template <class> class Serializer,
	   template <class> class PacketReader>
  class IONetworkManager <Packet, Socket::Server, Serializer, PacketReader>
  {
  public:
    IONetworkManager()
    {
      _serializer = new Serializer<Packet>();
      _packetReader = new PacketReader<Socket::Server>();
    }

    ~IONetworkManager() {}

    void	push(Packet *event)
    {
      _toSend.push(event);
    }

    Packet	*pop()
    {
      if (_received.size() > 0) {
	Packet *packet = _received.front();
	_received.pop();
	return (packet);
      }
      return (NULL);
    }

    void	updateR(Socket::Server & connection, int const &fd, size_t const &length)
    {
      Packet *packet;
      packet = _serializer->deserialize(_packetReader->read(connection, fd, length));
      if (packet != NULL)
	_received.push(packet);
      }

    void	updateW(Socket::Server & connection, int const &fd)
    {
      Packet *packet;
      if (_toSend.size() > 0) {
	char *msg;
	int size;
	packet = _toSend.front();
	msg = _serializer->serialize(packet, &size);
	if (msg != NULL) {
	  connection.write(fd, msg, size);
	  delete[] (msg);
	}
	_toSend.pop();
	delete (packet);
      }
    }

  private:
    std::queue<Packet *>		_received;
    std::queue<Packet *>		_toSend;
    ISerializer<Packet>			*_serializer;
    IPacketReader<Socket::Server>	*_packetReader;
  };

template<typename Packet, template <class> class Serializer,
	   template <class> class PacketReader>
  class IONetworkManager <Packet, Socket::Client, Serializer, PacketReader>
  {
  public:
    IONetworkManager()
    {
      _serializer = new Serializer<Packet>();
      _packetReader = new PacketReader<Socket::Client>();
    }

    ~IONetworkManager() {}

    void	push(Packet *event)
    {
      _toSend.push(event);
    }

    Packet	*pop()
    {
      if (_received.size() > 0) {
	Packet *packet = _received.front();
	_received.pop();
	return (packet);
      }
      return (NULL);
    }

    void	updateR(Socket::Client & connection, int const &fd, size_t const &length)
    {
      Packet *packet;
      packet = _serializer->deserialize(_packetReader->read(connection, fd, length));
      if (packet != NULL)
	_received.push(packet);
      }

    void	updateW(Socket::Client & connection, int const &fd)
    {
      char *msg;
      Packet *packet;
      if (_toSend.size() > 0) {
	int size;
	packet = _toSend.front();
	msg = _serializer->serialize(packet, &size);
	if (msg != NULL) {
	  connection.write(msg, size);
	  delete[] (msg);
	}
	_toSend.pop();
	delete (packet);
      }
    }

  private:
    std::queue<Packet *>		_received;
    std::queue<Packet *>		_toSend;
    ISerializer<Packet>			*_serializer;
    IPacketReader<Socket::Client>	*_packetReader;
  };
}

#endif /* IONETWORKMANAGER_HPP_ */
