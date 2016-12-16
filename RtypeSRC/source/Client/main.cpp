//
// main.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Client
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Dec 13 14:56:00 2016 Gandoulf
// Last update Tue Dec 13 16:12:03 2016 Gandoulf
//

#include "Client/ClientTcp.hpp"
#include <iostream>

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
