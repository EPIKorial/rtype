//
// Enemy2.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/source/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:53:57 2016 Gandoulf
// Last update Fri Dec 23 09:07:56 2016 Gandoulf
//

#include "Enemy2/Enemy2.hpp"

Enemy2::Enemy2(rtype::GameObject *&_gameObject)
  : AScript(_gameObject)
{

}

Enemy2::~Enemy2()
{

}

void Enemy2::Start()
{
  std::cout << "Enemy2 start" << std::endl;
  gameObject->getGameManager()->destroy(gameObject);
}

void Enemy2::Update()
{
}

void Enemy2::OnCollisionEnter(rtype::GameObject *coll)
{
}
