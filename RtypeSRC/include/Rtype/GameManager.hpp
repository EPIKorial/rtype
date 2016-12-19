//
// GameManager.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Rtype
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Nov 29 17:27:14 2016 Gandoulf
// Last update Mon Dec 19 13:11:24 2016 Gandoulf
//

#ifndef GAMEMANAGER_HPP_
# define GAMEMANAGER_HPP_

# include <queue>
# include <map>
# include "Protocol/TcpEvent.hpp"
# include "Protocol/UdpEvent.hpp"
# include "Rtype/GameObjectManager.hpp"

namespace rtype
{
  class GameManager
  {
  public:
    GameManager(std::map<int, std::queue<IEvent *>> & event, std::queue<IEvent *> &clientInputs);
    ~GameManager();

    GameObjectManager     &getGameObjects();

  private:
    std::map<int, std::queue<IEvent *>>         &_event;
    std::queue<IEvent *>                        &_clientInputs;
    GameObjectManager				_gameObjects;
  };
}

#endif /* GAMEMANAGER_HPP_ */
