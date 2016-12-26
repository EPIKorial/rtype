//
// Player.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/include/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:54:52 2016 Gandoulf
// Last update Mon Dec 26 11:39:05 2016 Gandoulf
//

#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include "Script/AScript.hpp"

class Player : public rtype::AScript
{
  public:
  Player(rtype::GameObject *&_gameObject);
  virtual ~Player();

  virtual void Start();
  virtual void Update();
  virtual void OnCollisionEnter(rtype::GameObject *);

private:
  std::queue<rtype::IEvent *>	*_event;
};

# ifdef SCRIPT_PLAYER
static Player *instantiateScript(rtype::GameObject *_gameObject)
  {
    return (new Player(_gameObject));
  }

  extern "C"
  {
    Player     *getScriptInstance(rtype::GameObject *_gameObject)
    {
      return (instantiateScript(_gameObject));
    }
  }
# endif

#endif /* PLAYER_HPP_ */
