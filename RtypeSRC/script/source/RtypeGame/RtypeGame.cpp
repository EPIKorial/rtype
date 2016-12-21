//
// RtypeGame.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/source/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:53:57 2016 Gandoulf
// Last update Wed Dec 21 14:53:04 2016 Gandoulf
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
}

void RtypeGame::OnCollisionEnter(rtype::GameObject *coll)
{
}
