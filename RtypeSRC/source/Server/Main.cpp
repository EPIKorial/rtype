//
// Main.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Server
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Nov 29 17:40:23 2016 Gandoulf
// Last update Tue Nov 29 18:48:23 2016 Gandoulf
//

#include "Server/Server.hpp"
#include <stdlib.h>
#include <iostream>

int main(int ac, char **av)
{
  if (ac != 2) {
    std::cout << "using " << av[0] << " port" << std::endl;
    return (0);
  }
  rtype::Server server;
  std::vector<std::string> script;

  server.run(atoi(av[1]), script);
  return (0);
}
