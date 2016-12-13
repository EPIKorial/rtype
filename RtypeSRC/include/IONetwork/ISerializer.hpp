//
// ISerializer.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Protocol
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Dec  6 13:25:24 2016 Gandoulf
// Last update Wed Dec  7 18:27:22 2016 Gandoulf
//

#ifndef ISERIALIZER_HPP_
# define ISERIALIZER_HPP_

namespace rtype
{
  template<class Packet>
  class ISerializer
  {
  public:
    virtual char *serialize(Packet const *packet, int *size) = 0;
    virtual Packet *deserialize(char *msg) = 0;
  };
}

#endif /* ISERIALIZER_HPP_ */
