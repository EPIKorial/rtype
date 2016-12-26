//
// GameManager.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Rtype
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Nov 29 17:27:14 2016 Gandoulf
// Last update Mon Dec 26 11:37:47 2016 Gandoulf
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
# include "Rtype/Synchroniser.hpp"



namespace rtype
{
  class GameObject;
  class GameObjectManager;

  class GetClientEventError : public std::exception
  {
  public:
    virtual const char *what() const throw()
    {
      return "no any ClientEvent associate to this gameObject";
    }
  };

  class GameManager : public IGameManager
  {
  public:
    GameManager(std::string const &name, std::map<int, std::queue<IEvent *> > & event,
		std::map<int, std::queue<IEvent *> > &clientInputs,
		std::map<int, GameObject *> &clientGO);
    ~GameManager();

    virtual void start();
    virtual void stop();
    virtual void managerUpdate();

    virtual std::queue<IEvent *>	*getClientEvent(GameObject *go);
    virtual Synchroniser		&synchronise();
    virtual GameObjectManager		&getGameObjects();
    virtual GameObject			*instantiate(std::string const &prefabFile,
						     Vector2F const &pos = (0,0),
						     Vector2F const &scale = (0,0));
    virtual void			destroy(GameObject *gameObject);

  private:
    bool checkDeleteList(std::string const &name);

  private:
    std::string					_name;
    Synchroniser				_synchroniser;
    GameObjectManager				_gameObjects;
    std::vector<GameObject *>			_deleteList;
    PrefabCreator			        _prefabCreator;
    GameObject					*_game;
    std::map<int, std::queue<IEvent *> >	&_clientInputs;
    std::map<int, GameObject *>			&_clientGO;

    bool					_closing;
  };
}

#endif /* GAMEMANAGER_HPP_ */
