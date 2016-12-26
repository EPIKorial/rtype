//
// Player.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/source/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:53:57 2016 Gandoulf
// Last update Mon Dec 26 11:40:06 2016 Gandoulf
//

#include "Player/Player.hpp"
#include "Rtype/GameManager.hpp"

Player::Player(rtype::GameObject *&_gameObject)
  : AScript(_gameObject)
{

}

Player::~Player()
{

}

void Player::Start()
{
  std::cout << "Player start" << std::endl;
    try {
    _event = gameObject->getGameManager()->getClientEvent(gameObject);
  } catch (rtype::GetClientEventError e) {
    std::cout << e.what() << std::endl;
  }
}

void Player::Update()
{
}

void Player::OnCollisionEnter(rtype::GameObject *coll)
{
}
