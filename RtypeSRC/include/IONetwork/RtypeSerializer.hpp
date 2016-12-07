//
// RtypeSerializer.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/IONetwork
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Dec  6 15:34:12 2016 Gandoulf
// Last update Tue Dec  6 15:44:31 2016 Gandoulf
//

#ifndef RTYPESERIALIZER_HPP_
# define RTYPESERIALIZER_HPP_

# include "IONetwork/ISerializer.hpp"

namespace rtype
{
  template<class Packet>
  class RtypeSerializer : public ISerializer<Packet>
  {
  public:
    RtypeSerializer() {}
    ~RtypeSerializer() {}

    virtual char *serialize(Packet const *packet, int *size)
    {
      return (NULL);
    }

    virtual Packet *deserialize(char const *msg)
    {
      return (NULL);
    }
  };
}

#endif /* RTYPESERIALIZER_HPP_ */
