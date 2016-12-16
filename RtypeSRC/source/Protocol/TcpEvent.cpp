//
// TcpEvent.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Prorocol
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed Dec  7 16:04:18 2016 Gandoulf
// Last update Fri Dec 16 16:33:42 2016 Gandoulf
//

#include <iostream> //TODO delete

#include "Protocol/TcpEvent.hpp"
#include <cstring>

namespace rtype
{
  TcpEvent::TcpEvent(EventType const & type)
    : _type(type)
  {

  }

  TcpEvent::~TcpEvent()
  {

  }

  EventType const TcpEvent::getType() const
  {
    return (_type);
  }

  Header              TcpEvent::getHeader() const
  {
    Header header;

    header.magicNumber = MAGIC_NUMBER;
    header.size = getSize();
    header.checksum = 1;//TODO
    header.messageType = _type;
    return (header);
  }

  namespace tcpEvent
  {
    /*---------------------------------------Message-------------------------------------*/

    Message::Message(std::string const &msg, size_t const & length)
      : TcpEvent(MESSAGE)
    {
      if (msg[length])
	message = "\0";
      else
	message = msg;
    }

    Message::Message(char const *msg, size_t const & length)
      : TcpEvent(MESSAGE)
    {
      char * tmp = new char[length + 1];
      std::memset(tmp, 0, length + 1);
      std::memcpy(tmp, msg, length);
      message = tmp;
      delete[] tmp;
    }

    Message::~Message()
    {

    }

    unsigned int      Message::getSize() const
    {
      return (message.size());
    }

    void              *Message::getData() const
    {
      return ((void *)(message.c_str()));
    }
  }
}
