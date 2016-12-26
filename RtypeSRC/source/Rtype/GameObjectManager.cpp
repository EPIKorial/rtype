//
// GameObjectManager.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Rtype
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Dec 19 12:37:17 2016 Gandoulf
// Last update Mon Dec 26 11:12:15 2016 Gandoulf
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

  GameObjectManager::~GameObjectManager()
  {
    for (auto ite = _staticObjects.begin(); ite != _staticObjects.end(); ite++)
      delete ite->second;
    for (auto ite = _dynamicObjects.begin(); ite != _dynamicObjects.end(); ite++)
      delete ite->second;
  }

  void GameObjectManager::update()
  {
    for(auto it = _dynamicObjects.begin(); it != _dynamicObjects.end(); ++it ) {
      try {
	it->second->Update();
      } catch (...) {
	std::cout << "script fail" << std::endl;
      }
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
    /*if (_dynamicObjects[nameObject]) {
      delete _dynamicObjects[nameObject];
      _dynamicObjects.erase(nameObject);
    }
    else if (_staticObjects[nameObject]) {
      delete _staticObjects[nameObject];
      _staticObjects.erase(nameObject);
    }
    else
      return (false);
      return (true);*/
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
