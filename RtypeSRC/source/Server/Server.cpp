//
// server.cpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/source/server
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Nov 28 16:58:59 2016 Gandoulf
// Last update Fri Dec 23 12:21:31 2016 Gandoulf
//

#include "Server/Server.hpp"
#include <iostream>
#include <cstdlib>

namespace rtype
{
  //
  // TcpRequest
  //

  TcpClient::TcpRequest::TcpRequest(std::string const& str)
  {
    std::stringstream stream(str);
    std::string token;

    while (std::getline(stream, token, ','))
      _tokens.push_back(token);

    _isValid = false;
    if (_tokens.size() > 0)
      {
	_isValid = true;
        cmd = _tokens[0];
	if (_tokens.size() > 1 && ((cmd.compare("CONNECT") == 0) || (cmd.compare("ROOM_READY") == 0)))
	  {
	    nickName = _tokens[1];
	  }
	else if (_tokens.size() > 1 && ((cmd.compare("ROOM_CREATE") == 0) || (cmd.compare("ROOM_JOIN") == 0)))
	  {
	    roomName = _tokens[1];
	  }
	else if (cmd.compare("ROOM_PLAYERS") == 0)
	  {

	  }
	else
	  {
	    _isValid = false;
	  }
      }
  }

  TcpClient::TcpRequest::~TcpRequest() {}

  bool TcpClient::TcpRequest::isValid() const
  {
    return _isValid;
  }

  //
  // TcpClient
  //

  TcpClient::TcpClient(int const & fd, Socket::Server &server, RoomManager &room)
    : _fd(fd), _server(server), _room(room)
  {
    std::cout << "client on fd : " << fd << " connected" << std::endl;
    std::cout << "client connected " << std::boolalpha << _room.connect("macouille") << std::endl;
    std::cout << room.getMessage("macouille") << std::endl;
    _room.getRoomList("macouille");
    std::cout << "room list\n" << room.getMessage("macouille") << std::endl;
    _room.createRoom("TOTO", "macouille");
    std::cout << room.getMessage("macouille") << std::endl;
  }

  TcpClient::~TcpClient()
  {
    // std::cout << "client on fd : " << _fd << " disconnected" << std::endl;
    // _room.disconnect("macouille");
  }

  void TcpClient::leaveRoom()
  {

  }

  void TcpClient::read(Socket::Server & server, int fd, size_t length)
  {
    IEvent *paquet;
    tcpEvent::Message *event;
    TcpRequest *req;

    req = NULL;
    event = NULL;
    _networkManager.updateR(server, fd, length);
    paquet = _networkManager.pop();
    if (paquet != NULL && paquet->getType() == MESSAGE) //TODO delete
      {
        event = static_cast<tcpEvent::Message *>(paquet);
	std::cout << "Message  = " << event->message << std::endl;
	req = new TcpRequest(event->message);
	if (!req->isValid())
	  {
	    delete req;
	    std::cerr << "Invalid request" << std::endl;
	  }
	std::cout << "CMD = " << req->cmd << std::endl;
	handleRequest(req);
	delete paquet;
      }
  }

  int TcpClient::handleRequest(const TcpRequest *req)
  {
    if (req->cmd.compare("CONNECT") == 0)
      {
	std::cout << "NINJA" << std::endl;
	_room.connect(req->nickName);
	_room.getRoomList(req->nickName);
	return (1); // labrez_f : To compile on Windows
      }
	return (0); // labrez_f : To compile on Windows
  }

  void TcpClient::write(Socket::Server & server, int fd)
  {
    _networkManager.updateW(server, fd);
    if (_name.size() > 0) {
      std::string msg = _room.getMessage(_name);
      if (msg.size() > 0) {
	tcpEvent::Message *tcpMsg = new tcpEvent::Message(msg, msg.size());
	_networkManager.push(tcpMsg);
      }
    }
  }

  //private

  void TcpClient::disconnect()
  {
    _server.disconnect(_fd);
  }

  /*----------------------------------------server------------------------------------------*/
  ScriptContener				Server::_scriptContener;
  MutexContener<std::vector<std::string> >	Server::_gameServerEnded;
  MutexContener<int>				Server::_gameServerPort;

  Server::Server(unsigned short const &port, std::vector<std::string> const & script,
		 std::string proto, unsigned int const &maxClient)
    : ARawServer(port, proto), _script(script), _maxClient(maxClient)
  {
    _gameServerPort.setContener(7180);
  }

  Server::~Server()
  {
    _room.closeAllGameServer();
    for (auto clients = _clients.begin(); clients != _clients.end(); clients = _clients.begin())
      _clients.erase(clients);
  }

  void Server::run()
  {
    start();

    char line[100];
    while (std::cin.getline(line, 100)) {
      std::string stringLine(line);
      if (!std::strncmp(line, "quit", 4))
	{
	  stop();
	  break;
	}
      else if (stringLine.find(".prefab") != std::string::npos)
	{
	  _prefabName = stringLine;
	}
      else
	{
	  IndieParser _parser;
	  _parser._insertInMap(std::string(line));
	  std::vector<std::string> rawScript = _parser.stoa(_parser.getValue("Script"), ';');
	  std::vector<std::string> script;

	  if (!rawScript.empty())
	    for (int i = 0; i < rawScript.size(); ++i)
	      {
#if defined(__GNUC__)
		script.push_back(std::string("RtypeSRC/script/binaries/lib" + rawScript[i]));
#elif defined(_MSC_VER)
		script.push_back(std::string(rawScript[i]));
#endif
	      }
	  if (_prefabName.size() > 7)
	    try{
	      updatePrefab(std::string(_prefabName), script);
	    } catch (std::exception e) {
	      std::cout << "error while prefab script update " << e.what() <<std::endl;
	    }
	}
    }
  }

  ScriptContener &Server::getScriptContenener()
  {
    return (_scriptContener);
  }

  int Server::getPort()
  {
    int &tmp = _gameServerPort.getContener();
    tmp = (tmp % 0xFFFF) + 1;
    if (tmp < 7180)
      tmp = 7180;
    _gameServerPort.giveBackContener();
    return (tmp);
  }

  void Server::closeGameServer(std::string const & name)
  {
    _gameServerEnded.getContener().push_back(name);
    _gameServerEnded.giveBackContener();
  }

  //protected

  void Server::onConnect(Socket::Server & server, int fd)
  {
    std::cout << "connection" << std::endl;
    accept(fd);
  }

  void Server::onDisconnect(Socket::Server & server, int fd)
  {
    std::cout << "disconnection" << std::endl;
    auto disconnectedClient = _clients.find(fd);
    if (disconnectedClient != _clients.end())
      {
	disconnectedClient->second->leaveRoom();
	_clients.erase(disconnectedClient);
      }
  }

  void Server::onRead(Socket::Server & server, int fd, size_t length)
  {
    auto readingClient = _clients.find(fd);
    if (readingClient != _clients.end())
      readingClient->second->read(server, fd, length);
  }

  void Server::onWrite(Socket::Server & server, int fd)
  {
    auto writingClient = _clients.find(fd);
    if (writingClient != _clients.end())
      writingClient->second->write(server, fd);
  }

  void Server::onStart(Socket::Server & server, int fd)
  {
    std::cout << "starting TCP server" << std::endl;
  }

  void Server::onTick(Socket::Server & server)
  {
    std::vector<std::string> &games = _gameServerEnded.getContener();
    while (games.size() > 0) {
      std::cout << "gameServer name: " << games.back() << std::endl;
      std::string name = games.back();
      _gameServerEnded.giveBackContener();
      _room.closeGameServer(name);
      _gameServerEnded.getContener();
      games.pop_back();
      std::cout << "deleted" << std::endl;
    }
    _gameServerEnded.giveBackContener();
  }

  void Server::start()
  {
    try {
      _server.start(_port, _maxClient, _protocol.c_str());
    } catch (const std::exception e) {
      std::cout << "can't launch server" << std::endl;
    }
  }

  void Server::stop()
  {
    try {
      _server.stop();
    } catch (const std::exception error) {
      std::cout << "server already close" << std::endl;
    }
  }

  void Server::accept(int fd)
  {
    client_ptr client(new TcpClient(fd, _server, _room));
    _clients.insert(std::make_pair(fd, std::move(client)));
  }

  void Server::updatePrefab(std::string prefabName, std::vector<std::string> & libs)
  {
    std::map<std::string, Prefabs>::iterator it;
    std::map<std::string, Prefabs>       &prefabTmp = _scriptContener.getPrefab();
#if defined(__GNUC__)
    prefabName = std::string("RtypeSRC/prefab/" + prefabName);
#elif defined(_MSC_VER)
    prefabName = std::string("../prefab/" + prefabName);
#endif
    if ((it = prefabTmp.find(prefabName)) == prefabTmp.end())
      {
	std::cout << "can't instantiate gameobject" << std::endl;
	_scriptContener.giveBackPrefab();
	return ;
      }
    it->second._properties.script.clear();
    it->second._properties.skillFunction.clear();
    it->second._properties.script = libs;
    for (int i = 0; i < libs.size(); ++i)
      {
	std::map<std::string, Memory::LibraryLoader> &tmp = _scriptContener.getLib();
	std::map<std::string, Memory::LibraryLoader>::iterator itLib;
	if ((itLib = tmp.find(it->second._properties.script[i])) == tmp.end())
	  {
	    tmp[it->second._properties.script[i]] = Memory::LibraryLoader();
	    itLib = tmp.find(it->second._properties.script[i]);
	  }
	try {
	  loadLibrary(it->second._properties, itLib->second, it->second._usable, i);
	} catch (PrefabLibraryLoaderError e) {
	  std::cout << e.what() << std::endl;
	  _scriptContener.giveBackPrefab();
	  _scriptContener.giveBackLib();
	  throw PrefabLoadFileError();
	}
	_scriptContener.giveBackLib();
	std:: cout << "lib found " << it->second._properties.script[i]
		   << ", loading script" << std::endl;
      }
    _scriptContener.giveBackPrefab();
  }

  void Server::loadLibrary(Properties & _properties, Memory::LibraryLoader & _library,
		   bool &_usable, int it)
  {
    try {
      _library.loadSharedLibrary(_properties.script[it]);
      _usable = true;
    } catch (Memory::LibraryLoadError e) {
      std ::cout << e.what() << std::endl;
      std::cout << std::string("load error message") + _library.logError() << std::endl;
      _usable = false;
      throw PrefabLibraryLoaderError();
    }
    try {
      _properties.skillFunction.push_back((skillScript)_library.getFunction("getScriptInstance"));
    } catch (Memory::LibraryFunctionLoadError e) {
      std::cout << e.what() << std::endl;
      _usable = false;
      throw PrefabLibraryLoaderError();
    }
  }
}
