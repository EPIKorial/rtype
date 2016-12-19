//
// Script.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/include/Script
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 15:49:39 2016 Gandoulf
// Last update Mon Dec 19 13:13:16 2016 Gandoulf
//

#ifndef ASCRIPT_HPP_
# define ASCRIPT_HPP_

# include <cstdarg>
# include <string>
# include "Rtype/GameObject.hpp"

namespace rtype
{
  class GameObject;

  class AScript
  {
  public:
    AScript(GameObject *&_gameObject)
    : gameObject(_gameObject)
    {}
    virtual ~AScript()
    {}

    virtual void Start() {}
    virtual void Update() {}
    virtual void OnCollisionEnter(GameObject *) {}
    virtual void Use(std::string str, ...) {}

  protected:
    GameObject	*gameObject;
  };
}

#endif /* SCRIPT_HPP_ */
