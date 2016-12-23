//
// Enemy2.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/include/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:54:52 2016 Gandoulf
// Last update Mon Nov 28 19:20:53 2016 Gandoulf
//

#ifndef ENEMY2_HPP_
# define ENEMY2_HPP_

# include "Script/AScript.hpp"

class Enemy2 : public rtype::AScript
{
  public:
  Enemy2(rtype::GameObject *&_gameObject);
  virtual ~Enemy2();

  virtual void Start();
  virtual void Update();
  virtual void OnCollisionEnter(rtype::GameObject *);
};

# ifdef SCRIPT_ENEMY2
static Enemy2 *instantiateScript(rtype::GameObject *_gameObject)
  {
    return (new Enemy2(_gameObject));
  }

  extern "C"
  {
    Enemy2     *getScriptInstance(rtype::GameObject *_gameObject)
    {
      return (instantiateScript(_gameObject));
    }
  }
# endif

#endif /* ENEMY2_HPP_ */
