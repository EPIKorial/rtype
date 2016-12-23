//
// RtypeGame.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/source/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:53:57 2016 Gandoulf
// Last update Fri Dec 23 10:32:20 2016 Gandoulf
//

#include "RtypeGame/RtypeGame.hpp"

RtypeGame::RtypeGame(rtype::GameObject *&_gameObject)
  : AScript(_gameObject)
{

}

RtypeGame::~RtypeGame()
{

}

void RtypeGame::Start()
{
  std::cout << "game start" << std::endl;
}

void RtypeGame::Update()
{
  std::cout << "coucou" << std::endl;
  gameObject->getGameManager()->instantiate("Enemy.prefab");
}

void RtypeGame::OnCollisionEnter(rtype::GameObject *coll)
{
}
