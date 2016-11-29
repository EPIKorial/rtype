//
// Default.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/source/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:53:57 2016 Gandoulf
// Last update Mon Nov 28 19:21:05 2016 Gandoulf
//

#include "Default/Default.hpp"

Default::Default(rtype::GameObject *&_gameObject)
  : AScript(_gameObject)
{

}

Default::~Default()
{

}

void Default::Start()
{
  std::cout << "default start" << std::endl;
}

void Default::Update()
{
}

void Default::OnCollisionEnter(rtype::GameObject *coll)
{
}
