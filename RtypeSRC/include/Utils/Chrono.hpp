//
// Chrono.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Utils
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Dec 26 12:49:21 2016 Gandoulf
// Last update Mon Dec 26 15:42:34 2016 Gandoulf
//

#ifndef CHRONO_HPP_
# define CHRONO_HPP_



namespace rtype
{
  class Chrono
  {
  public:
    Chrono();
    ~Chrono();

    void update();
    long double getDeltaTime();

  private:
    long double _initial;
    long double	_start;
    long double	_end;
    long double	_diff;
  };
}

#endif /* CHRONO_HPP_ */
