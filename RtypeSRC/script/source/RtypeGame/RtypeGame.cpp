//
// RtypeGame.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/source/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:53:57 2016 Gandoulf
// Last update Mon Dec 26 12:33:14 2016 Gandoulf
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
  rtype::GameObject *go = gameObject->getGameManager()->instantiate("Enemy.prefab");
  gameObject->getGameManager()->synchronise().instantiation(go, 2000);
}

void RtypeGame::Update()
{
}

void RtypeGame::OnCollisionEnter(rtype::GameObject *coll)
{
}
