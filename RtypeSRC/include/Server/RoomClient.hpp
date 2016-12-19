//
// RoomClient.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Client
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Fri Dec 16 22:48:03 2016 Gandoulf
// Last update Fri Dec 16 22:49:17 2016 Gandoulf
//

#ifndef ROOMCLIENT_HPP_
# define ROOMCLIENT_HPP_

#include <string>

namespace rtype
{
  class Client
  {
  public:
    Client(std::string const &name);
    ~Client();

    std::string const &getName() const;
    bool                getReady() const;
    void                setReady(bool const &);
  private:
    std::string _name;
    bool                _ready;
  };
}

#endif /* ROOMCLIENT_HPP_ */
