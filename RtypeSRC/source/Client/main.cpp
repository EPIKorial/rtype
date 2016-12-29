//
// main.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Client
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Dec 13 14:56:00 2016 Gandoulf
// Last update Wed Dec 28 00:28:17 2016 Gandoulf
//

#include "Client/ClientTcp.hpp"
#include <iostream>

#ifndef ARM_ANDROID
int main(int ac, char **av)
{
  if (ac != 3) {
    std::cout << av[0] << " port adresse" << std::endl;
    return (0);
  }
  rtype::ClientTcp client(atoi(av[1]), av[2]);
  client.run();
  return (0);
}
#endif
