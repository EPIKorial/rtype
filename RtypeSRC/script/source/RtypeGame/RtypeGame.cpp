//
// RtypeGame.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/source/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:53:57 2016 Gandoulf
// Last update Thu Dec 29 11:19:10 2016 Gandoulf
//

#include "RtypeGame/RtypeGame.hpp"

RtypeGame::RtypeGame(rtype::GameObject *&_gameObject)
  : AScript(_gameObject)
{
  //duration = 0; //TODO delete
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
  /*duration += gameObject->getGameManager()->deltaTime();
    std::cout << "server start since " << duration << std::endl;*/
}

void RtypeGame::OnCollisionEnter(rtype::GameObject *coll)
{
}
