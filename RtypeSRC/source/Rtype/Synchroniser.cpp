//
// Synchroniser.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Rtype
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Fri Dec 23 12:50:30 2016 Gandoulf
// Last update Fri Dec 23 16:00:10 2016 Gandoulf
//

#include "Rtype/Synchroniser.hpp"

namespace rtype
{
  Synchroniser::Synchroniser(std::map<int, std::queue<IEvent *> > &event)
    : _event(event)
  {

  }

  Synchroniser::~Synchroniser()
  {

  }

  void Synchroniser::position(GameObject const *go)
  {
    PosUpdate	posUpate;

    posUpate.ID = go->getID();
    posUpate.x = go->getPosition().x;
    posUpate.y = go->getPosition().y;
    for (auto ite = _event.begin(); ite != _event.end(); ite++)
      ite->second.push(new udpEvent::EPosUpdate(posUpate));
  }

  void Synchroniser::instantiation(GameObject const *go, unsigned int const & itemID)
  {
    Instantiate	instantiate;

    instantiate.ID = itemID;
    instantiate.x = go->getPosition().x;
    instantiate.y = go->getPosition().y;
    instantiate.scale_x = go->getScale().x;
    instantiate.scale_y = go->getScale().y;
    instantiate.goID = go->getID();
    for (auto ite = _event.begin(); ite != _event.end(); ite++)
      ite->second.push(new udpEvent::EInstantiate(instantiate));
  }

  void Synchroniser::fire(GameObject const *go, unsigned short const & itemID)
  {
    Fire	fire;

    fire.ID = go->getID();
    fire.x = go->getPosition().x;
    fire.y = go->getPosition().y;
    fire.bulletID = itemID;
    for (auto ite = _event.begin(); ite != _event.end(); ite++)
      ite->second.push(new udpEvent::EFire(fire));
  }

  void Synchroniser::deletion(GameObject const *go)
  {
    Deletion	deletion;

    deletion.ID = go->getID();
    for (auto ite = _event.begin(); ite != _event.end(); ite++)
      ite->second.push(new udpEvent::EDeletion(deletion));
  }
}
