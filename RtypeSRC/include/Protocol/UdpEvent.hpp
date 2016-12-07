//
// UdpEvent.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Protocol
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed Dec  7 15:29:16 2016 Gandoulf
// Last update Wed Dec  7 16:35:28 2016 Gandoulf
//

#ifndef UDPEVENT_HPP_
# define UDPEVENT_HPP_

#include "Protocol/IEvent.hpp"

namespace rtype
{
  class UdpEvent : public IEvent
  {
  public:
    UdpEvent();
    ~UdpEvent();

    virtual unsigned int        getSize() const = 0;
    virtual void                *getData() const = 0;
  };

  namespace udpEvent
  {
    class EFire : public UdpEvent
    {
    public:
      EFire();
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
      ~ECollision();

      virtual unsigned int	getSize() const;
      virtual void		*getData() const;

    private:
      Collision			collision;
    };
  }
}

#endif /* UDPEVENT_HPP_ */
