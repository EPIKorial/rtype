//
// TcpEvent.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Prorocol
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed Dec  7 16:04:18 2016 Gandoulf
// Last update Tue Dec 13 13:24:23 2016 Gandoulf
//

#include "Protocol/TcpEvent.hpp"

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

    header.magicNumber =MAGIC_NUMBER;
    header.size = getSize();
    header.checksum = 1;//TODO
    header.messageType =_type;
  }

  namespace tcpEvent
  {
    /*---------------------------------------Message-------------------------------------*/

    Message::Message(std::string const &msg)
      : TcpEvent(MESSAGE), message(msg)
    {

    }

    Message::Message(char const *data)
      : TcpEvent(MESSAGE), message(data)
    {

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
