//
// Main.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/Server
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Nov 29 17:40:23 2016 Gandoulf
// Last update Tue Dec  6 09:52:50 2016 Gandoulf
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
  unsigned short port = atoi(av[1]);
  std::vector<std::string> script;
  rtype::Server server(port, script);

  server.run();
  return (0);
}