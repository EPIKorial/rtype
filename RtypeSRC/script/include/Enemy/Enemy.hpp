//
// Enemy.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/include/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:54:52 2016 Gandoulf
// Last update Mon Nov 28 19:20:53 2016 Gandoulf
//

#ifndef ENEMY_HPP_
# define ENEMY_HPP_

# include "Script/AScript.hpp"

class Enemy : public rtype::AScript
{
  public:
  Enemy(rtype::GameObject *&_gameObject);
  virtual ~Enemy();

  virtual void Start();
  virtual void Update();
  virtual void OnCollisionEnter(rtype::GameObject *);
};

# ifdef SCRIPT_ENEMY
static Enemy *instantiateScript(rtype::GameObject *_gameObject)
  {
    return (new Enemy(_gameObject));
  }

  extern "C"
  {
    Enemy     *getScriptInstance(rtype::GameObject *_gameObject)
    {
      return (instantiateScript(_gameObject));
    }
  }
# endif

#endif /* ENEMY_HPP_ */
