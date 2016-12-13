//
// IONetworkManager.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/IONetworkManager
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Dec  6 14:09:53 2016 Gandoulf
// Last update Wed Dec  7 18:30:20 2016 Gandoulf
//

#ifndef IONETWORKMANAGER_HPP_
# define IONETWORKMANAGER_HPP_

#include "IONetwork/ISerializer.hpp"
#include "IONetwork/IPacketReader.hpp"
#include "Network/sockets/Server.hpp"
#include <queue>

namespace rtype
{
  template<typename Packet, template <class> class Serializer, class PacketReader>
  class IONetworkManager
  {
  public:
    IONetworkManager()
    {
      _serializer = new Serializer<Packet>();
      _packetReader = new PacketReader();
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

    void	update(Socket::Server & server, int const &fd, size_t const &length)
    {
      Packet *packet;
      packet = _serializer->deserialize(_packetReader->read(server, fd, length));
      if (packet != NULL)
	_received.push(packet);
      if (_toSend.size() > 0) {
	char *msg;
	int size;
	packet = _toSend.front();
	_toSend.pop();
	msg = _serializer.serialize(packet, &size);
	delete (packet);
	if (msg != NULL) {
	  server.write(fd, msg, size);
	  delete (msg);
	}
      }
    }

  private:


  private:
    std::queue<Packet *>	_received;
    std::queue<Packet *>	_toSend;
    ISerializer<Packet>		*_serializer;
    IPacketReader		*_packetReader;
  };
}

#endif /* IONETWORKMANAGER_HPP_ */
