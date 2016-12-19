//
// Default.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/include/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:54:52 2016 Gandoulf
// Last update Mon Nov 28 19:20:53 2016 Gandoulf
//

#ifndef DEFAULT_HPP_
# define DEFAULT_HPP_

# include "Script/AScript.hpp"

class Default : public rtype::AScript
{
  public:
  Default(rtype::GameObject *&_gameObject);
  virtual ~Default();

  virtual void Start();
  virtual void Update();
  virtual void OnCollisionEnter(rtype::GameObject *);
};

# ifdef SCRIPT_DEFAULT
static Default *instantiateScript(rtype::GameObject *_gameObject)
  {
    return (new Default(_gameObject));
  }

  extern "C"
  {
    Default     *getScriptInstance(rtype::GameObject *_gameObject)
    {
      return (instantiateScript(_gameObject));
    }
  }
# endif

#endif /* DEFAULT_HPP_ */
