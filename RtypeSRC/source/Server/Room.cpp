//
// Room.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Server
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed Nov 30 11:04:49 2016 Gandoulf
// Last update Tue Dec  6 10:32:12 2016 Gandoulf
//

#include "Server/Room.hpp"
#include <cstring>

namespace rtype
{
  Room::Client::Client(std::string const &name)
    :_name(name)
  {
  }

  Room::Client::~Client()
  {
  }

  std::string const &Room::Client::getName() const
  {
    return (_name);
  }

  bool              Room::Client::getReady() const
  {
    return (_ready);
  }

  void              Room::Client::setReady(bool const &ready)
  {
    _ready = ready;
  }

  /*----------------------------------Room------------------------------------*/

  Room::Room(std::string const & name, unsigned short const & port,
	     unsigned int const & maxPlayers)
    : _name(name), _port(port), _maxPlayers(maxPlayers)
  {

  }

  Room::~Room()
  {

  }

  bool Room::join(std::string &message, std::string const & nickName)
  {
    if (_players.size() >= _maxPlayers)
      {
	message = joinError();
	return (false);
      }
    for (int i = 0; i < _maxPlayers; ++i)
      if (_players.find(i) == _players.end()) {
	_players.insert(std::make_pair(i, Client(nickName)));
	break;
      }
    message = joinOk();
    return (true);
  }

  void Room::disconnect(std::string &message, std::string const & nickName)
  {
    message = "";
    for (auto player = _players.begin(); player != _players.end(); player = _players.begin())
      if (!player->second.getName().compare(nickName)){
	_players.erase(player);
	message = "player disconnect";
      }
  }

  int Room::getPlayerNbr() const
  {
    return (_players.size());
  }

  void Room::setReady(std::string &message, std::string const & nickName, bool const & isReady)
  {
    message = "";
    for (auto player = _players.begin(); player != _players.end(); ++player)
      if (!player->second.getName().compare(nickName)) {
	player->second.setReady(isReady);
	message = "player Ready";
      }
  }

  //private

  std::string Room::joinError() const
  {
    return std::string(_name + ",KO");
  }

  std::string Room::joinOk() const
  {
    return std::string(_name + ",OK");
  }

  std::vector<std::string>    Room::getRoomPlayers()
  {
    std::vector<std::string> players;
    return (players);
  }
}
