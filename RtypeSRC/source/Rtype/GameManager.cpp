//
// GameManager.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Rtype
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Sat Dec 17 11:53:40 2016 Gandoulf
// Last update Wed Dec 21 12:58:01 2016 Gandoulf
//

#include "Rtype/GameManager.hpp"
#include "Utils/Vector.hpp"

namespace rtype
{
  GameManager::GameManager(std::map<int, std::queue<IEvent *>> & event,
			   std::queue<IEvent *> &clientInputs)
    : _event(event), _clientInputs(clientInputs)
  {

  }

  GameManager::~GameManager()
  {
    //TODO delete all Go, message
  }

  void GameManager::start()
  {
    _game = instantiate("game.prefab", Vector2F(0,0));
    _game->setGameManager(static_cast<IGameManager *>(this));
  }

  void GameManager::stop()
  {
  }

  void GameManager::managerUpdate()
  {
    if (!_deleteList.empty())
      {
	while (_deleteList.size() > 0)
	  {
	    _gameObjects.deleteObject(_deleteList.back()->getName());
	    delete _deleteList.back();
	    _deleteList.pop_back();
	  }
      }
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
    go->setGameManager(static_cast<IGameManager *>(this));
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
