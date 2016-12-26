//
// IGameManager.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Rtype
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed Dec 21 12:11:35 2016 Gandoulf
// Last update Mon Dec 26 11:39:41 2016 Gandoulf
//

#ifndef IGAMEMANAGER_HPP_
# define IGAMEMANAGER_HPP_

# include <string>
# include <queue>
# include "Utils/Vector.hpp"
# include "Rtype/GameObjectManager.hpp"
# include "Rtype/Synchroniser.hpp"
# include "Protocol/IEvent.hpp"

namespace rtype
{
  class GameObjectManager;
  class Synchroniser;

  class IGameManager
  {
  public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void managerUpdate() = 0;

    virtual std::queue<IEvent *>        *getClientEvent(GameObject *gameObject) = 0;
    virtual Synchroniser		&synchronise() = 0;
    virtual GameObjectManager		&getGameObjects() = 0;
    virtual GameObject			*instantiate(std::string const &prefabFile,
						     Vector2F const &pos = (0,0),
						     Vector2F const &scale = (0,0)) = 0;
    virtual void			destroy(GameObject *gameObject) = 0;
  };
}

#endif /* IGAMEMANAGER_HPP_ */
