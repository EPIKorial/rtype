//
// Synchroniser.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Rtype
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Fri Dec 23 12:50:42 2016 Gandoulf
// Last update Fri Dec 23 17:25:01 2016 Gandoulf
//

#ifndef SYNCHRONISER_HPP_
# define SYNCHRONISER_HPP_

# include <map>
# include <queue>
# include "Protocol/TcpEvent.hpp"
# include "Protocol/UdpEvent.hpp"
# include "Utils/Vector.hpp"
# include "Rtype/GameObject.hpp"

namespace rtype
{
  class Synchroniser
  {
  public:
    Synchroniser(std::map<int, std::queue<IEvent *> > &event);
    ~Synchroniser();

    void position(GameObject const *go);
    void instantiation(GameObject const *go, unsigned int const & itemID);
    void fire(GameObject const *go, unsigned short const & itemID);
    void deletion(GameObject const *go);

  private:
    std::map<int, std::queue<IEvent *> >	&_event;
  };
}

#endif /* SYNCHRONISER_HPP */
