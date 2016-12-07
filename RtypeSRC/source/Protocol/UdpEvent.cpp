//
// UdpEvent.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Prorocol
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed Dec  7 15:48:45 2016 Gandoulf
// Last update Wed Dec  7 16:36:13 2016 Gandoulf
//

#include "Protocol/UdpEvent.hpp"

namespace rtype
{
  UdpEvent::UdpEvent()
  {

  }

  UdpEvent::~UdpEvent()
  {

  }

  namespace udpEvent
  {
    /*---------------------------------------fire-------------------------------------*/

    EFire::EFire()
    {

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
    {

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
    {

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
    {

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
    {

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
