//
// UdpEvent.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Protocol
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed Dec  7 15:29:16 2016 Gandoulf
// Last update Tue Dec 13 13:24:44 2016 Gandoulf
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
      EFire(char const *data);
      ~EFire();

      virtual unsigned int	getSize() const;
      virtual void		*getData() const;

    private:
      Fire			fire;
    };

    class EDeletion : public UdpEvent
    {
    public:
      EDeletion();
      EDeletion(char const *data);
      ~EDeletion();

      virtual unsigned int	getSize() const;
      virtual void		*getData() const;

    private:
      Deletion			deletion;
    };

    class EPosUpdate : public UdpEvent
    {
    public:
      EPosUpdate();
      EPosUpdate(char const *data);
      ~EPosUpdate();

      virtual unsigned int	getSize() const;
      virtual void		*getData() const;

    private:
      PosUpdate			posUpdate;
    };

    class EInstantiate : public UdpEvent
    {
    public:
      EInstantiate();
      EInstantiate(char const *data);
      ~EInstantiate();

      virtual unsigned int	getSize() const;
      virtual void		*getData() const;

    private:
      Instantiate		instantiate;
    };

    class ECollision : public UdpEvent
    {
    public:
      ECollision();
      ECollision(char const *data);
      ~ECollision();

      virtual unsigned int	getSize() const;
      virtual void		*getData() const;

    private:
      Collision			collision;
    };
  }
}

#endif /* UDPEVENT_HPP_ */
