//
// ScriptContener.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Rtype
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed Dec 21 18:14:04 2016 Gandoulf
// Last update Wed Dec 21 18:43:24 2016 Gandoulf
//

#ifndef SCRIPTCONTENER_HPP_
# define SCRIPTCONTENER_HPP_

# include <map>
# include "Rtype/LibraryLoader.hpp"
# include "Rtype/Properties.hpp"
# include "mutex"

namespace rtype
{
  struct Prefabs
  {
    Prefabs()
      : _usable(true)
    {}
    bool                        _usable;
    Properties                  _properties;
  };

  class ScriptContener
  {
  public:
    ScriptContener();
    ~ScriptContener();

    std::map<std::string, Prefabs> &getPrefab();
    std::map<std::string, Memory::LibraryLoader> &getLib();
    void giveBackPrefab();
    void giveBackLib();

  private:
    std::map<std::string, Prefabs>                       _prefab;
    std::map<std::string, Memory::LibraryLoader>        _lib;

    std::mutex						_prefabMutex;
    std::mutex						_libMutex;
  };
}

#endif /* SCRIPTCONTENER_HPP_ */
