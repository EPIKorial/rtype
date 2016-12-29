//
// Utils.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Utils
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Dec 26 12:51:41 2016 Gandoulf
// Last update Mon Dec 26 15:43:41 2016 Gandoulf
//

#include "Utils/Chrono.hpp"
#include <iostream>

namespace rtype
{
  Chrono::Chrono()
  {
    _initial = time(0) * 1000;
    _start = 0;
  }

  Chrono::~Chrono()
  {

  }

  void Chrono::update()
  {
    _end = (_initial - time(0) * 1000);
    _diff = _end - _start;
    std::cout << "Elasped time is " << _diff << " seconds." << std::endl;
    _start = (_initial - time(0) * 1000);
  }

  long double Chrono::getDeltaTime()
  {
    return (_diff);
  }
}
