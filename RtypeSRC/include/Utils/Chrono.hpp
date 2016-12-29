//
// Chrono.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Utils
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Dec 26 12:49:21 2016 Gandoulf
// Last update Thu Dec 29 10:58:34 2016 Gandoulf
//

#ifndef CHRONO_HPP_
# define CHRONO_HPP_

#include <iomanip>
#include <ctime>
#include <chrono>

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
    //long double _initial;
    //long double	_start;
    //long double	_end;
    //long double	_diff;

    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point end;
    long double diff;
  };
}

#endif /* CHRONO_HPP_ */
