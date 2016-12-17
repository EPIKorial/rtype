//
// RoomClient.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Client
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Fri Dec 16 22:50:07 2016 Gandoulf
// Last update Fri Dec 16 22:52:54 2016 Gandoulf
//

#include "Server/RoomClient.hpp"

namespace rtype
{
  Client::Client(std::string const &name)
    :_name(name)
  {
  }

  Client::~Client()
  {
  }

  std::string const &Client::getName() const
  {
    return (_name);
  }

  bool              Client::getReady() const
  {
    return (_ready);
  }

  void              Client::setReady(bool const &ready)
  {
    _ready = ready;
  }
}
