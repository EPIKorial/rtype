//
// Vector.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/script/include/Utils
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Nov 28 18:32:39 2016 Gandoulf
// Last update Mon Dec 19 13:16:42 2016 Gandoulf
//

#ifndef RTYPE_VECTOR_HPP_
# define RTYPE_VECTOR_HPP_

namespace rtype
{
  struct Vector2F
  {
    Vector2F(float const &_x = 0, float const &_y = 0)
      : x(_x), y(_y)
    {}
    Vector2F(Vector2F const &copy)
    {
      *this = copy;
    }

    Vector2F &operator=(Vector2F const &copy)
    {
      x = copy.x;
      y = copy.y;
      return (*this);
    }

    float x;
    float y;
  };
}

#endif /* RTYPE_VECTOR_HPP_ */
