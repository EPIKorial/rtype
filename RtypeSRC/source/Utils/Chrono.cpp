//
// Utils.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Utils
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Dec 26 12:51:41 2016 Gandoulf
// Last update Thu Dec 29 11:03:24 2016 Gandoulf
//

#include "Utils/Chrono.hpp"
#include <iostream>

namespace rtype
{
  Chrono::Chrono()
  {
    start = std::chrono::system_clock::now();
  }

  Chrono::~Chrono()
  {

  }

  void Chrono::update()
  {
    end = std::chrono::system_clock::now();
    diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    start = std::chrono::system_clock::now();
  }

  long double Chrono::getDeltaTime()
  {
    return (diff);
  }
}
