//
// UdpEvent.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Prorocol
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed Dec  7 15:48:45 2016 Gandoulf
// Last update Fri Dec 16 15:56:54 2016 Gandoulf
//

#include "Protocol/UdpEvent.hpp"
#include <cstring>

namespace rtype
{
  UdpEvent::UdpEvent(EventType const & type)
    : _type(type)
  {

  }

  UdpEvent::~UdpEvent()
  {

  }

  EventType const UdpEvent::getType() const
  {
    return (_type);
  }

  Header              UdpEvent::getHeader() const
  {
    Header header;

    header.magicNumber = MAGIC_NUMBER;
    header.size = getSize();
    header.checksum = 1; //TODO
    header.messageType = _type;
    return (header);
  }

  namespace udpEvent
  {
    /*---------------------------------------fire-------------------------------------*/

    EFire::EFire()
      : UdpEvent(FIRE)
    {

    }

    EFire::EFire(Fire const & _fire)
      : UdpEvent(FIRE)
    {
      std::memcpy((void *)(&fire), (void *)(&_fire), sizeof(Fire));
    }

    EFire::EFire(char const *data)
      : UdpEvent(FIRE)
    {
      std::memcpy((void *)(&fire), data, sizeof(Fire));
    }

    EFire::~EFire()
    {

    }

    unsigned int      EFire::getSize() const
    {
      return (sizeof(Fire));
    }

    void              *EFire::getData() const
    {
      return ((void *)(&fire));
    }

    /*---------------------------------------Deletion-------------------------------------*/

    EDeletion::EDeletion()
      : UdpEvent(DELETION)
    {

    }

    EDeletion::EDeletion(Deletion const & _deletion)
      : UdpEvent(DELETION)
    {
      std::memcpy((void *)(&deletion), (void *)(&_deletion), sizeof(Deletion));
    }

    EDeletion::EDeletion(char const *data)
      : UdpEvent(DELETION)
    {
      std::memcpy((void *)(&deletion), data, sizeof(Deletion));
    }


    EDeletion::~EDeletion()
    {

    }

    unsigned int      EDeletion::getSize() const
    {
      return (sizeof(Deletion));
    }

    void              *EDeletion::getData() const
    {
      return ((void *)(&deletion));
    }

    /*---------------------------------------PosUpdate-------------------------------------*/

    EPosUpdate::EPosUpdate()
      : UdpEvent(POSUPDATE)
    {

    }

    EPosUpdate::EPosUpdate(PosUpdate const & _posUpdate)
      : UdpEvent(POSUPDATE)
    {
      std::memcpy((void *)(&posUpdate), (void *)(&_posUpdate), sizeof(PosUpdate));
    }

    EPosUpdate::EPosUpdate(char const *data)
      : UdpEvent(POSUPDATE)
    {
      std::memcpy((void *)(&posUpdate), data, sizeof(PosUpdate));
    }

    EPosUpdate::~EPosUpdate()
    {

    }

    unsigned int      EPosUpdate::getSize() const
    {
      return (sizeof(PosUpdate));
    }

    void              *EPosUpdate::getData() const
    {
      return ((void *)(&posUpdate));
    }

    /*---------------------------------------Instantiate-------------------------------------*/

    EInstantiate::EInstantiate()
      : UdpEvent(INSTANTIATE)
    {

    }

    EInstantiate::EInstantiate(Instantiate const & _instantiate)
      : UdpEvent(INSTANTIATE)
    {
      std::memcpy((void *)(&instantiate), (void *)(&_instantiate), sizeof(Instantiate));
    }

    EInstantiate::EInstantiate(char const *data)
      : UdpEvent(INSTANTIATE)
    {
      std::memcpy((void *)(&instantiate), data, sizeof(Instantiate));
    }

    EInstantiate::~EInstantiate()
    {

    }

    unsigned int      EInstantiate::getSize() const
    {
      return (sizeof(Instantiate));
    }

    void              *EInstantiate::getData() const
    {
      return ((void *)(&instantiate));
    }

    /*---------------------------------------Collision-------------------------------------*/

    ECollision::ECollision()
      : UdpEvent(COLLISION)
    {

    }

    ECollision::ECollision(Collision const & _collision)
      : UdpEvent(COLLISION)
    {
      std::memcpy((void *)(&collision), (void *)(&_collision), sizeof(Collision));
    }

    ECollision::ECollision(char const *data)
      : UdpEvent(COLLISION)
    {
      std::memcpy((void *)(&collision), data, sizeof(Collision));
    }

    ECollision::~ECollision()
    {

    }

    unsigned int      ECollision::getSize() const
    {
      return (sizeof(Collision));
    }

    void              *ECollision::getData() const
    {
      return ((void *)(&collision));
    }
  }
}
