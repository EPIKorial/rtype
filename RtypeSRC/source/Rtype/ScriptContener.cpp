//
// ScriptContener.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Server
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed Dec 21 18:20:29 2016 Gandoulf
// Last update Wed Dec 21 18:43:43 2016 Gandoulf
//

#include "Rtype/ScriptContener.hpp"

namespace rtype
{
  ScriptContener::ScriptContener()
  {

  }

  ScriptContener::~ScriptContener()
  {

  }

  std::map<std::string, Prefabs> &ScriptContener::getPrefab()
  {
    _prefabMutex.lock();
    return (_prefab);
  }

  std::map<std::string, Memory::LibraryLoader> &ScriptContener::getLib()
  {
    _libMutex.lock();
    return (_lib);
  }

  void ScriptContener::giveBackPrefab()
  {
    _prefabMutex.unlock();
  }

  void ScriptContener::giveBackLib()
  {
    _libMutex.unlock();
  }
}
