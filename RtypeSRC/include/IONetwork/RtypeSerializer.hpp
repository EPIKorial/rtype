//
// RtypeSerializer.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/IONetwork
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Dec  6 15:34:12 2016 Gandoulf
// Last update Fri Dec 16 21:58:25 2016 Gandoulf
//

#ifndef RTYPESERIALIZER_HPP_
# define RTYPESERIALIZER_HPP_

# include <iostream> //TODO delete

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
      std::memset(msg, 0, sizeof(Header) + packet->getSize());
      Header header = packet->getHeader();
      std::memcpy(msg, &header, sizeof(Header));
      std::memcpy(msg + sizeof(Header), packet->getData(), packet->getSize());
      *size = sizeof(Header) + packet->getSize();
      return (msg);
    }

    virtual Packet *deserialize(char *msg)
    {
      if (msg == NULL)
	return (NULL);
      Header header;
      std::memcpy((void *)(&header), msg, sizeof(Header));
      switch (header.messageType) {
      case MESSAGE:	// return message packet
	return (new tcpEvent::Message(msg + sizeof(Header), header.size));
	break;
      case POSUPDATE:	// return position update packet
	{
	  if (header.size != sizeof(PosUpdate)) {
	    delete[] msg;
	    return (NULL);
	  }
	  udpEvent::EPosUpdate *Ptmp = new udpEvent::EPosUpdate(msg + sizeof(Header));
	  delete[] msg;
	  return (Ptmp);
	}
	break;
      case FIRE:	// return Fire packe
	{
	  if (header.size != sizeof(Fire)) {
	    delete[] msg;
	    return (NULL);
	  }
	  udpEvent::EFire *Ftmp = new udpEvent::EFire(msg + sizeof(Header));
	  delete[] msg;
	  return (Ftmp);
	}
	break;
      case INSTANTIATE:	// return Instantiate packet
	{
	  if (header.size != sizeof(Instantiate)) {
	    delete[] msg;
	    return (NULL);
	  }
	  udpEvent::EInstantiate *Itmp = new udpEvent::EInstantiate(msg + sizeof(Header));
	  delete[] msg;
	  return (Itmp);
	}
	break;
      case COLLISION:	// return Collision packet
	{
	  if (header.size != sizeof(Collision)) {
	    delete[] msg;
	    return (NULL);
	  }
	  udpEvent::ECollision *Ctmp = new udpEvent::ECollision(msg + sizeof(Header));
	  delete[] msg;
	  return (Ctmp);
	}
	break;
      case DELETION:	// return Deletion packet
	{
	  if (header.size != sizeof(Deletion)) {
	    delete[] msg;
	    return (NULL);
	  }
	  udpEvent::EDeletion *Dtmp = new udpEvent::EDeletion(msg + sizeof(Header));
	  delete[] msg;
	  return (Dtmp);
	}
	break;
      default:
	delete[] msg;
	return (NULL);
      }
    }
  };
}

#endif /* RTYPESERIALIZER_HPP_ */
