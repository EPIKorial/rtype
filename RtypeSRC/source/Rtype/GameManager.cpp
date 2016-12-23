//
// GameManager.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Rtype
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Sat Dec 17 11:53:40 2016 Gandoulf
// Last update Fri Dec 23 15:16:32 2016 Gandoulf
//

#include "Rtype/GameManager.hpp"
#include "Server/Server.hpp"
#include "Utils/Vector.hpp"

namespace rtype
{
  GameManager::GameManager(std::string const &name, std::map<int, std::queue<IEvent *>> & event,
			   std::map<int, std::queue<IEvent *> > &clientInputs)
    : _name(name), _synchroniser(event), _closing(false)
  {

  }

  GameManager::~GameManager()
  {
    //TODO delete all Go, message
  }

  void GameManager::start()
  {
    _game = instantiate("game.prefab", Vector2F(0,0));
  }

  void GameManager::stop()
  {
    Server::closeGameServer(_name);
    _closing = true;
  }

  void GameManager::managerUpdate()
  {
    if (_closing)
      return ;
    if (!_deleteList.empty())
      {
	while (_deleteList.size() > 0)
	  {
	    std::cout << "deleted obj " << _deleteList.back()->getName() << std::endl;
	    _gameObjects.deleteObject(_deleteList.back()->getName());
	    delete _deleteList.back();
	    _deleteList.pop_back();
	  }
      }
    _gameObjects.update();
  }

  Synchroniser        &GameManager::synchronise()
  {
    return (_synchroniser);
  }

  GameObjectManager   &GameManager::getGameObjects()
  {
    return (_gameObjects);
  }

  GameObject *GameManager::instantiate(std::string const &prefabFile,
				       Vector2F const &pos,
				       Vector2F const &scale)
  {
    GameObject *go = _prefabCreator.instantiate(prefabFile, pos, scale);
    if (go != NULL)
      {
	go->setGameManager(static_cast<IGameManager *>(this));
	_gameObjects.addObject(go, go->_dynamic);
      }
    return (go);
  }

  void                GameManager::destroy(GameObject *gameObject)
  {
    if (gameObject == NULL)
      return ;
    if (_gameObjects.getObject(gameObject->getName()) != NULL &&
	checkDeleteList(gameObject->getName()) == false)
      _deleteList.push_back(gameObject);
  }

  /* ----------------------------------private---------------------------------- */

  bool GameManager::checkDeleteList(std::string const &name)
  {
    for (int i = 0; i < _deleteList.size(); ++i)
      if (_deleteList[i]->getName() == name)
	{
	  return (true);
	}
    return (false);
  }
}
