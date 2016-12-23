//
// Enemy.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/source/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:53:57 2016 Gandoulf
// Last update Fri Dec 23 16:08:40 2016 Gandoulf
//

#include "Enemy/Enemy.hpp"

Enemy::Enemy(rtype::GameObject *&_gameObject)
  : AScript(_gameObject)
{

}

Enemy::~Enemy()
{

}

void Enemy::Start()
{
  std::cout << "Enemy start" << std::endl;
  gameObject->getGameManager()->destroy(gameObject);
  gameObject->getGameManager()->synchronise().deletion(gameObject);
}

void Enemy::Update()
{
}

void Enemy::OnCollisionEnter(rtype::GameObject *coll)
{
}
