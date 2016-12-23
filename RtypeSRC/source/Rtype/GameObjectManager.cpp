//
// GameObjectManager.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Rtype
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Dec 19 12:37:17 2016 Gandoulf
// Last update Fri Dec 23 10:03:34 2016 Gandoulf
//

#include "Rtype/GameObjectManager.hpp"

namespace rtype
{
  GameObjectManager::GameObjectManager() {}

  GameObjectManager::GameObjectManager(GameObjectManager &newMap)
  {
    _staticObjects = newMap.getStaticObjects();
    _dynamicObjects = newMap.getDynamicObjects();
  }

  GameObjectManager::~GameObjectManager() {}

  void GameObjectManager::update()
  {
    for(auto it = _dynamicObjects.begin(); it != _dynamicObjects.end(); ++it ) {
      it->second->Update();
    }
  }

  GameObjectManager *GameObjectManager::addObject(GameObject *newObject,
						 bool dynamic)
  {
    if (!dynamic)
      _staticObjects[newObject->getName()] = newObject;
    else if (dynamic)
      {
	_dynamicObjects[newObject->getName()] = newObject;
	newObject->Start();
      }
    return this;
  }

  bool GameObjectManager::deleteObject(std::string const& nameObject)
  {
    if (!_dynamicObjects.erase(nameObject))
      if (!_staticObjects.erase(nameObject))
	return false;
    return true;
  }

  GameObject *GameObjectManager::getObject(std::string const& nameObject)
  {
    std::map<std::string, rtype::GameObject *>::iterator wanted;

    wanted = _dynamicObjects.find(nameObject);
    if (wanted == _dynamicObjects.end())
      wanted = _staticObjects.find(nameObject);
    return wanted == _staticObjects.end() ? NULL : wanted->second;
  }

  std::map<std::string, GameObject *> &GameObjectManager::getStaticObjects()
  {
    return _staticObjects;
  }

  std::map<std::string, GameObject *> &GameObjectManager::getDynamicObjects()
  {
    return _dynamicObjects;
  }

  std::vector <GameObject *> GameObjectManager::getObjectsWithTag(std::string const &tag)
  {
    std::vector<GameObject *> objects;

    for (auto it = _staticObjects.begin(); it != _staticObjects.end(); ++it)
      {
	if ((*it).second->getTag() == tag)
	  objects.push_back((*it).second);

      }
    for (auto it = _dynamicObjects.begin(); it != _dynamicObjects.end(); ++it)
      {
	if ((*it).second->getTag() == tag)
	  objects.push_back((*it).second);

      }

    return objects;
  }
}
