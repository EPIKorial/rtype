//
// RoomManager.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Server
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed Nov 30 10:12:03 2016 Gandoulf
// Last update Thu Dec 22 16:12:46 2016 Gandoulf
//

#ifndef ROOMANAGER_HPP_
# define ROOMANAGER_HPP_

# include <map>
# include <string>
# include <vector>
# include "Server/Room.hpp"

namespace rtype
{
  class RoomManager
  {
  public:
    RoomManager();
    ~RoomManager();

    bool connect(std::string const & nickName);
    void disconnect(std::string const & nickName);
    void getRoomList(std::string const & nickName);
    void joinRoom(std::string const & room, std::string const & nickName);
    void createRoom(std::string const & name, std::string const & nickName);
    void setReady(std::string const & nickName, bool const & isReady);

    std::string getMessage(std::string const & nickName);

    void closeGameServer(std::string const & name);
    void closeAllGameServer();

  private:
    bool	isConnected(std::string const & nickName);
    bool	isalnum(std::string const & str);
    std::string joinError(std::string const & name) const;
    std::string joinOk(std::string const & name) const;

    void	sendPlayerMsg(std::string const & name, std::string const & msg);
    void	sendRoomPlayerMsg(std::string const & room, std::string const & msg);

    std::string getClientRoom(std::string const &name);

  private:
    std::map<std::string, room_ptr>			_rooms;
    std::map<std::string, std::string>			_clientsRoom;
    std::map<std::string, std::vector<std::string> >	_clientsMessage;
    std::vector<std::string>				_clients;
  };
}

#endif /* ROOMANAGER_HPP_ */
