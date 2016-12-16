//
// UdpEvent.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Protocol
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed Dec  7 15:29:16 2016 Gandoulf
// Last update Fri Dec 16 16:46:02 2016 Gandoulf
//

#ifndef UDPEVENT_HPP_
# define UDPEVENT_HPP_

#include "Protocol/IEvent.hpp"

namespace rtype
{
  class UdpEvent : public IEvent
  {
  public:
    UdpEvent(EventType const & type);
    ~UdpEvent();

    virtual unsigned int        getSize() const = 0;
    virtual void                *getData() const = 0;
    virtual EventType const     getType() const;
    virtual Header              getHeader() const;

  private:
    EventType	_type;
  };

  namespace udpEvent
  {
    class EFire : public UdpEvent
    {
    public:
      EFire();
      EFire(Fire const & _fire);
      EFire(char const *data);
      ~EFire();

      virtual unsigned int	getSize() const;
      virtual void		*getData() const;

    public:
      Fire			fire;
    };

    class EDeletion : public UdpEvent
    {
    public:
      EDeletion();
      EDeletion(Deletion const & _deletion);
      EDeletion(char const *data);
      ~EDeletion();

      virtual unsigned int	getSize() const;
      virtual void		*getData() const;

    public:
      Deletion			deletion;
    };

    class EPosUpdate : public UdpEvent
    {
    public:
      EPosUpdate();
      EPosUpdate(PosUpdate const & _posUpdate);
      EPosUpdate(char const *data);
      ~EPosUpdate();

      virtual unsigned int	getSize() const;
      virtual void		*getData() const;

    public:
      PosUpdate			posUpdate;
    };

    class EInstantiate : public UdpEvent
    {
    public:
      EInstantiate();
      EInstantiate(Instantiate const & _instantiate);
      EInstantiate(char const *data);
      ~EInstantiate();

      virtual unsigned int	getSize() const;
      virtual void		*getData() const;

    public:
      Instantiate		instantiate;
    };

    class ECollision : public UdpEvent
    {
    public:
      ECollision();
      ECollision(Collision const & _collision);
      ECollision(char const *data);
      ~ECollision();

      virtual unsigned int	getSize() const;
      virtual void		*getData() const;

    public:
      Collision			collision;
    };
  }
}

#endif /* UDPEVENT_HPP_ */
