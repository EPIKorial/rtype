//
// GameManager.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Rtype
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Sat Dec 17 11:53:40 2016 Gandoulf
// Last update Sat Dec 17 12:01:38 2016 Gandoulf
//

#include "Rtype/GameManager.hpp"

namespace rtype
{
  GameManager::GameManager(std::map<int, std::queue<IEvent *>> & event,
			   std::queue<IEvent *> &clientInputs)
    : _event(event), _clientInputs(clientInputs)
  {

  }

  GameManager::~GameManager()
  {

  }
}
