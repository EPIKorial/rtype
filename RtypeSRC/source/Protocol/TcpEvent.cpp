//
// TcpEvent.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Prorocol
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed Dec  7 16:04:18 2016 Gandoulf
// Last update Wed Dec  7 16:32:23 2016 Gandoulf
//

#include "Protocol/TcpEvent.hpp"

namespace rtype
{
  TcpEvent::TcpEvent()
  {

  }

  TcpEvent::~TcpEvent()
  {

  }

  namespace tcpEvent
  {
    /*---------------------------------------Message-------------------------------------*/

    Message::Message(std::string const &msg)
      : message(msg)
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
