//
// GameObjectManager.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Rtype
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Dec 19 12:36:16 2016 Gandoulf
// Last update Wed Dec 21 15:06:44 2016 Gandoulf
//

#ifndef GAMEOBJECTMANAGER_HPP_
# define GAMEOBJECTMANAGER_HPP_

# include <map>
# include <vector>
# include <string>
# include "Rtype/GameObject.hpp"

namespace rtype
{
  class GameObject;
  class GameManager;

  class GameObjectManager
  {
  public:
    typedef enum e_ObjType
      {
	STATIC,
	DYNAMIC
      }		ObjType;

  public:
    GameObjectManager();
    GameObjectManager(GameObjectManager &newMap);
    ~GameObjectManager();

    void update();

    GameObjectManager *addObject(GameObject *newObject, bool dynamic);
    bool deleteObject(std::string const& nameObject);
    GameObject *getObject(std::string const& nameObject);
    std::map<std::string, GameObject *> &getStaticObjects();
    std::map<std::string, GameObject *> &getDynamicObjects();
    std::vector<GameObject *> getObjectsWithTag(std::string const &tag);

  private:
    std::map<std::string, GameObject *> _staticObjects;
    std::map<std::string, GameObject *> _dynamicObjects;
  };
}

#endif /* GAMEOBJECTMANAGER_HPP_ */
