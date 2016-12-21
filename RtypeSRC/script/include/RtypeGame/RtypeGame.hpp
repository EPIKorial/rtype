//
// RtypeGame.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/include/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:54:52 2016 Gandoulf
// Last update Mon Nov 28 19:20:53 2016 Gandoulf
//

#ifndef RTYPEGAME_HPP_
# define RTYPEGAME_HPP_

# include "Script/AScript.hpp"

class RtypeGame : public rtype::AScript
{
  public:
  RtypeGame(rtype::GameObject *&_gameObject);
  virtual ~RtypeGame();

  virtual void Start();
  virtual void Update();
  virtual void OnCollisionEnter(rtype::GameObject *);
};

# ifdef SCRIPT_RTYPEGAME
static RtypeGame *instantiateScript(rtype::GameObject *_gameObject)
  {
    return (new RtypeGame(_gameObject));
  }

  extern "C"
  {
    RtypeGame     *getScriptInstance(rtype::GameObject *_gameObject)
    {
      return (instantiateScript(_gameObject));
    }
  }
# endif

#endif /* RTYPEGAME_HPP_ */
