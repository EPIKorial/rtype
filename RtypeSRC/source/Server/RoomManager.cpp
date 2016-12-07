//
// RoomManager.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Server
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed Nov 30 10:35:00 2016 Gandoulf
// Last update Tue Dec  6 10:32:36 2016 Gandoulf
//

#include "Server/RoomManager.hpp"
#include <iostream>
#include <cctype>
#include <sstream>
#include <cstring>

namespace rtype
{
  RoomManager::RoomManager()
    : _nextPort(STARTING_PORT)
  {
  }

  RoomManager::~RoomManager()
  {
  }

  bool RoomManager::connect(std::string const & nickName)
  {
    if (!isalnum(nickName))
      return (false);
    if (isConnected(nickName))
      return(false);
    _clients.push_back(nickName);
    _clientsMessage.insert(std::make_pair(nickName, std::vector<std::string>()));
    return (true);
  }

  void RoomManager::disconnect(std::string const & nickName)
  {
    std::string message;
    std::string room = getClientRoom(nickName);
    auto client = _clientsRoom.find(nickName);
    auto clientMsg = _clientsMessage.find(nickName);
    for (int i = 0; i < _clients.size(); ++i)
      if (!std::strcmp(nickName.c_str(), _clients[i].c_str()))
      _clients.erase(_clients.begin() + i);
    if (client != _clientsRoom.end())
    _rooms.find(client->second)->second->disconnect(message, nickName);
    if (clientMsg != _clientsMessage.end())
      _clientsMessage.erase(clientMsg);
    sendRoomPlayerMsg(room, message);
  }

  void RoomManager::getRoomList(std::string const &nickName)
  {
    std::stringstream roomList;

    for (auto ite = _rooms.begin(); ite != _rooms.end(); ite++)
      roomList << ite->first << "," << ite->second->getPlayerNbr() << "\n";
    sendPlayerMsg(nickName, roomList.str());
  }

  void RoomManager::joinRoom(std::string const & room, std::string const & nickName)
  {
    std::string message;
    if (!isalnum(room) || !isConnected(nickName)) {
      sendPlayerMsg(nickName, joinError(nickName));
      return ;
    }
    if (_rooms.find(room) == _rooms.end()) {
      sendPlayerMsg(nickName, joinError(nickName));
      return ;
    }
    if (_rooms.find(room)->second->join(message, nickName))
      _clientsRoom.insert(std::make_pair(nickName, room));
    sendPlayerMsg(nickName, message);
  }

  void RoomManager::createRoom(std::string const & name, std::string const & nickName)
  {
    if (!isalnum(name)) {
      sendPlayerMsg(nickName, joinError(nickName));
      return ;
    }
    if (_rooms.find(name) != _rooms.end()) {
      sendPlayerMsg(nickName, joinError(nickName));
      return ;
    }
    room_ptr room(new Room(name, _nextPort++));
    _rooms.insert(std::make_pair(name, std::move(room)));
    joinRoom(name, nickName);
  }

  void RoomManager::setReady(std::string const & nickName, bool const & isReady)
  {
    std::string message;
    sendPlayerMsg(nickName, message);
    sendRoomPlayerMsg(getClientRoom(nickName), message);
  }

  std::string RoomManager::getMessage(std::string const & nickName)
  {
    std::string message("");
    auto client = _clientsMessage.find(nickName);
    if (client != _clientsMessage.end() && client->second.size() > 0)
      {
	message = client->second.front();
	client->second.erase(client->second.begin());
      }
    return (message);
  }

  //private

  bool RoomManager::isConnected(std::string const & nickName)
  {
    for (auto ite = _clients.begin(); ite != _clients.end(); ite++)
      if (!std::strcmp(nickName.c_str(), ite->c_str()))
	return (true);
    return (false);
  }

  bool RoomManager::isalnum(std::string const & str)
  {
    for (int i = 0; i < str.length(); i++)
      if (!std::isalnum(str.c_str()[i]))
	return (false);
    return (true);
  }

  std::string RoomManager::joinError(std::string const & name) const
  {
    return std::string(name + ",KO");
  }

  std::string RoomManager::joinOk(std::string const & name) const
  {
    return std::string(name + ",OK");
  }

  void        RoomManager::sendPlayerMsg(std::string const & name, std::string const & msg)
  {
    auto client = _clientsMessage.find(name);
    if (msg.size() == 0)
      return ;
    if (client == _clientsMessage.end())
      return ;
    client->second.push_back(msg);
  }

  void        RoomManager::sendRoomPlayerMsg(std::string const & room, std::string const & msg)
  {
    std::vector<std::string> players;
    auto roomPtr = _rooms.find(room);
    if (msg.size() == 0)
      return ;
    if (roomPtr == _rooms.end())
      return ;
    players = roomPtr->second->getRoomPlayers();
    for (int i = 0; i < players.size(); ++i)
      sendPlayerMsg(players[i], msg);
  }

  std::string RoomManager::getClientRoom(std::string const &name)
  {
    auto client = _clientsRoom.find(name);
    if (client != _clientsRoom.end())
      return (client->second);
    return (std::string(""));
  }
}
