//
// GameManager.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Rtype
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Nov 29 17:27:14 2016 Gandoulf
// Last update Wed Dec 21 12:24:46 2016 Gandoulf
//

#ifndef GAMEMANAGER_HPP_
# define GAMEMANAGER_HPP_

class GameManager;

# include <queue>
# include <map>
# include "Protocol/TcpEvent.hpp"
# include "Protocol/UdpEvent.hpp"
# include "Utils/Vector.hpp"
# include "Rtype/IGameManager.hpp"
# include "Rtype/GameObjectManager.hpp"
# include "Rtype/GameObject.hpp"
# include "Rtype/PrefabCreator.hpp"

namespace rtype
{
  class GameObject;
  class GameObjectManager;

  class GameManager : public IGameManager
  {
  public:
    GameManager(std::map<int, std::queue<IEvent *>> & event, std::queue<IEvent *> &clientInputs);
    ~GameManager();

    virtual void start();
    virtual void stop();
    virtual void managerUpdate();

    virtual GameObjectManager	&getGameObjects();
    virtual GameObject		*instantiate(std::string const &prefabFile,
				     Vector2F const &pos = (0,0),
				     Vector2F const &scale = (0,0));
    virtual void		destroy(GameObject *gameObject);

  private:
    bool checkDeleteList(std::string const &name);

  private:
    std::map<int, std::queue<IEvent *>>         &_event;
    std::queue<IEvent *>                        &_clientInputs;
    GameObjectManager				_gameObjects;
    std::vector<GameObject *>			_deleteList;
    PrefabCreator			        _prefabCreator;
    GameObject					*_game;
  };
}

#endif /* GAMEMANAGER_HPP_ */
