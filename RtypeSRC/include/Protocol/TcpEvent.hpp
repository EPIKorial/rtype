//
// TcpEvent.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Protocol
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed Dec  7 15:29:16 2016 Gandoulf
// Last update Tue Dec 13 13:45:17 2016 Gandoulf
//

#ifndef TCPEVENT_HPP_
# define TCPEVENT_HPP_

#include "Protocol/IEvent.hpp"
#include <string>

namespace rtype
{
  class TcpEvent : public IEvent
  {
  public:
    TcpEvent(EventType const & type);
    ~TcpEvent();

    virtual unsigned int        getSize() const = 0;
    virtual void                *getData() const = 0;
    virtual EventType const 	getType() const;
    virtual Header		getHeader() const;

  private:
    EventType	_type;
  };

  namespace tcpEvent
  {
    class Message : public TcpEvent
    {
    public:
      Message(std::string const &msg);
      Message(char const *data);
      ~Message();

      virtual unsigned int	getSize() const;
      virtual void		*getData() const;

    private:
      std::string		message;
    };
  }
}

#endif /* TCPEVENT_HPP_ */
