//
// SkillProperties.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/include/IndieStudio
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon May 23 18:29:15 2016 Gandoulf
// Last update Wed Dec 21 12:07:25 2016 Gandoulf
//

#ifndef SKILLPROPERTIES_HPP_
# define SKILLPROPERTIES_HPP_

# include <string>
# include "Script/AScript.hpp"
# include "Rtype/GameObject.hpp"
# include "Utils/Vector.hpp"

namespace rtype
{
  class GameObject;
  class AScript;

  struct Properties
  {
    Properties()
    {
      name = "Unknow";
      tag = "Unknow";
      //collider = true;
      position = Vector2F(0, 0);
      scale = Vector2F(1, 1);
    }

    ~Properties()
    {}

    Properties &operator=(Properties const &SP)
    {
      name = SP.name;
      tag = SP.tag;
      script = SP.script;
      //collider = SP.collider;
      position = SP.position;
      scale = SP.scale;
      skillFunction = SP.skillFunction;
      return (*this);
    }

    std::string			name;
    std::string			tag;
    std::vector<std::string>	script;
    //bool			collider;
    Vector2F			position;
    Vector2F			scale;
    std::vector<AScript *(*)(GameObject *)> skillFunction;
  };
};

#endif /* SKILLPROPERTIES_HPP_ */
