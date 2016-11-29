//
// GameObject.hpp for  in /home/agor_m/epitech/cpp_indie_studio/rtype-studio
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Thu Jun  2 15:32:14 2016 Maxime Agor
// Last update Mon Nov 28 19:15:13 2016 Gandoulf
//

#ifndef GAMEOBJECT_HPP_
# define GAMEOBJECT_HPP_

# include "Script/AScript.hpp"
# include "Utils/Vector.hpp"
# include <typeinfo>
# include <vector>
# include <string>
# include <iostream>

namespace rtype
{
  class AScript;

  class GameObject
  {
  protected:
    std::vector<rtype::AScript *>	_script;
    std::string				_tag;
    std::string				_name;
    rtype::Vector2F			_position;
    rtype::Vector2F			_scale;

    //TODO: need collider + gameManager

  public:
    GameObject();
    virtual ~GameObject();

    virtual void			Start();
    virtual void			Update();
    virtual void			OnCollisionEnter(GameObject *gameObject);

    bool				setPositionF(rtype::Vector2F const&);
    void				setScale(rtype::Vector2F const&);
    void				setTag(std::string const &tag);
    bool				setName(std::string const &name);
    void				setScript(AScript *script);

    rtype::Vector2F const&		getPosition() const;
    rtype::Vector2F const&		getScale() const;
    std::string const &			getName() const;
    std::string const &			getTag() const;

    //TODO: need an exeption
    template<class Script>
    Script				*GetScript()
    {
      for (auto it = _script.begin(); it != _script.end(); ++it)
    	{
    	  try {
	    return dynamic_cast<Script *>(*it);
    	  } catch (std::bad_cast) {}
    	}
      return (NULL);
    }
  };
};

#endif /* !GAMEOBJECT_HPP_ */
