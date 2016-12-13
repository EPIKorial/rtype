//
// IEvent.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Protocol
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Dec  6 13:33:51 2016 Gandoulf
// Last update Tue Dec 13 13:20:26 2016 Gandoulf
//

#ifndef IEVENT_HPP_
# define IEVENT_HPP_

# include "Protocol/Protocol.h"

namespace rtype
{
  class IEvent
  {
  public:
    virtual unsigned int	getSize() const = 0;
    virtual void		*getData() const = 0;
    virtual EventType const	getType() const = 0;
    virtual Header		getHeader() const = 0;
  };
}

#endif /* IEVENT_HPP_ */
