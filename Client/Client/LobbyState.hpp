#pragma once

#ifndef LOBBYSTATE_HPP_
# define LOBBYSTATE_HPP_

# include "AState.hpp"

class LobbyState : public AState
{
public:
	LobbyState(App &);
	virtual ~LobbyState();

	virtual void update(float elapsed) override;

	virtual void draw(float elapsed) override;
};

#endif /* !LOBBYSTATE_HPP_ */
