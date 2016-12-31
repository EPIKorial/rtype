//
// ClientTcp.hpp for  in /home/gandoulf/epitech/rtype/RtypeSRC/include/Client
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Dec 13 16:05:47 2016 Gandoulf
// Last update Thu Dec 15 17:27:58 2016 Gandoulf
//

#ifndef CLIENTTCP_HPP_
# define  CLIENTTCP_HPP_

# include <mutex>
# include "ARawClient.hpp"
# include "IONetworkManager.hpp"
# include "RtypeSerializer.hpp"
# include "RtypePacketReader.hpp"
# include "TcpEvent.hpp"
# include "ClientErrors.hpp"

namespace rtype
{
	class ClientTcp : public ARawClient
	{
		typedef IONetworkManager<IEvent, Socket::Client, RtypeSerializer, RtypePacketReader> IOClient;

	public:
		ClientTcp(unsigned short const &port, std::string const & adresse, std::string proto = "tcp");
		virtual ~ClientTcp();

		virtual void run();
		virtual void start();
		virtual void stop();

		bool isActive();
	protected:
		std::mutex NetManagerMutex;
		std::mutex ActiveMutex;

		bool active;

		virtual void onDisconnect(Socket::Client & client);
		virtual void onRead(Socket::Client & client, size_t length);
		virtual void onWrite(Socket::Client & client);
		virtual void onStart(Socket::Client & client, std::string const &address, int port);


	protected:
		IOClient	_networkManager;
	};
}

#endif /* CLIENTTCP_HPP_ */
