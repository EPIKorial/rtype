//
// GameObject.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Rtype
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Dec 19 12:46:49 2016 Gandoulf
// Last update Mon Dec 19 13:17:00 2016 Gandoulf
//

#include "Rtype/GameObject.hpp"

namespace rtype
{
  GameObject::GameObject()
  {

  }

  GameObject::~GameObject()
  {
    if (!_script.empty())
      for (int i = 0; i < _script.size(); ++i)
	{
	  delete _script.back();
	  _script.pop_back();
	}
  }

  void GameObject::Start()
  {
    if (!_script.empty())
      for (int i = 0; i < _script.size(); ++i)
	_script[i]->Start();
  }

  void GameObject::Update()
  {
    if (!_script.empty())
      for (int i = 0; i < _script.size(); ++i)
	_script[i]->Update();
  }

  void GameObject::OnCollisionEnter(GameObject *gameObject)
  {
    if (!_script.empty())
      for (unsigned int i = 0; i < _script.size(); ++i)
	{
	  _script[i]->OnCollisionEnter(gameObject);
	}
  }

  bool GameObject::setPositionF(rtype::Vector2F const& position)
  {
    _position = position;
    return (true);
  }

  void GameObject::setScale(rtype::Vector2F const& scale)
  {
    _scale = scale;
  }

  void GameObject::setTag(std::string const &tag)
  {
    _tag = tag;
  }

  /*bool GameObject::setName(std::string const &name)
  {

  }*/

  void GameObject::setScript(AScript *script)
  {
    _script.push_back(script);
  }

  rtype::Vector2F const& GameObject::getPosition() const
  {
    return (_position);
  }

  rtype::Vector2F const& GameObject::getScale() const
  {
    return (_scale);
  }

  std::string const & GameObject::getName() const
  {
    return (_name);
  }

  std::string const & GameObject::getTag() const
  {
    return (_tag);
  }
}
