//
// Room.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Server
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed Nov 30 10:11:31 2016 Gandoulf
// Last update Tue Dec  6 15:28:26 2016 Gandoulf
//

#ifndef ROOM_HPP_
# define ROOM_HPP_

# include <memory>
# include <vector>
# include <map>
# include <string>

namespace rtype
{
  class Room
  {
    class Client
    {
    public:
      Client(std::string const &name);
      ~Client();

      std::string const &getName() const;
      bool		getReady() const;
      void		setReady(bool const &);
    private:
      std::string	_name;
      bool		_ready;
    };

  public:
    Room(std::string const & name, unsigned short const & port,
	 unsigned int const & maxPlayers = 4);
    ~Room();

    bool join(std::string &message, std::string const & nickName);
    void disconnect(std::string &message, std::string const & nickName);
    int getPlayerNbr() const;
    void setReady(std::string &message, std::string const & nickName, bool const & isready);

    std::vector<std::string>	getRoomPlayers();

  private:
    std::string joinError() const;
    std::string joinOk() const;

  private:
    std::string			_name;
    unsigned int		_maxPlayers;
    //std::vector<std::string>	_players;
    std::map<int, Client>	_players;
    unsigned short		_port;
  };

  typedef std::unique_ptr<Room>	room_ptr;
}

#endif /* ROOM_HPP_ */
