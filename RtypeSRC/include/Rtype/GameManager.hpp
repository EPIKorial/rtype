//
// GameManager.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Rtype
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Nov 29 17:27:14 2016 Gandoulf
// Last update Sat Dec 17 12:03:46 2016 Gandoulf
//

#ifndef GAMEMANAGER_HPP_
# define GAMEMANAGER_HPP_

# include <queue>
# include <map>
# include "Protocol/TcpEvent.hpp"
# include "Protocol/UdpEvent.hpp"

namespace rtype
{
  class GameManager
  {
  public:
    GameManager(std::map<int, std::queue<IEvent *>> & event, std::queue<IEvent *> &clientInputs);
    ~GameManager();

  private:
    std::map<int, std::queue<IEvent *>>         &_event;
    std::queue<IEvent *>                        &_clientInputs;
  };
}

#endif /* GAMEMANAGER_HPP_ */
