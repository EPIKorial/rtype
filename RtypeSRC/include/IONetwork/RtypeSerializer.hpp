//
// RtypeSerializer.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/IONetwork
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Dec  6 15:34:12 2016 Gandoulf
// Last update Tue Dec 13 13:55:57 2016 Gandoulf
//

#ifndef RTYPESERIALIZER_HPP_
# define RTYPESERIALIZER_HPP_

# include "IONetwork/ISerializer.hpp"
# include "Protocol/UdpEvent.hpp"
# include "Protocol/TcpEvent.hpp"

namespace rtype
{
  template<class Packet>
  class RtypeSerializer : public ISerializer<Packet>
  {
  public:
    RtypeSerializer() {}
    ~RtypeSerializer() {}

    virtual char *serialize(Packet const *packet, int *size)
    {
      if (packet == NULL)
	return (NULL);
      char *msg = new char[sizeof(Header) + packet->getSize()];
      Header header = packet->getHeader();
      std::memcpy(msg, &header, sizeof(Header));
      std::memcpy(msg + sizeof(Header), packet->getData(), packet->getSize());
      return (msg);
    }

    virtual Packet *deserialize(char *msg)
    {
      Header header;
      std::memcpy((void *)(&header), msg, sizeof(Header));
      switch (header.messageType) {
      case MESSAGE:
	return (new tcpEvent::Message(msg + sizeof(Header)));
	break;
      case POSUPDATE:
	if (header.size != sizeof(PosUpdate))
	  return (NULL);
	return (new udpEvent::EPosUpdate(msg + sizeof(Header)));
	break;
      case FIRE:
	if (header.size != sizeof(Fire))
	  return (NULL);
	return (new udpEvent::EFire(msg + sizeof(Header)));
	break;
      case INSTANTIATE:
	if (header.size != sizeof(Instantiate))
	  return (NULL);
	return (new udpEvent::EInstantiate(msg + sizeof(Header)));
	break;
      case COLLISION:
	if (header.size != sizeof(Collision))
	  return (NULL);
	return (new udpEvent::ECollision(msg + sizeof(Header)));
	break;
      case DELETION:
	if (header.size != sizeof(Deletion))
	  return (NULL);
	return (new udpEvent::EDeletion(msg + sizeof(Header)));
	break;
      default:
	return (NULL);
      }
    }
  };
}

#endif /* RTYPESERIALIZER_HPP_ */
