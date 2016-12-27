#pragma once

#ifndef LOBBYSTATE_HPP_
# define LOBBYSTATE_HPP_

# include "AState.hpp"
# include "ScrollingBack.hpp"

class LobbyState : public AState
{
	ScrollingBack background;
	ScrollingBack upper;
	float backTimer;

public:
	LobbyState(App &, const ScrollingBack &, const ScrollingBack &);
	virtual ~LobbyState();

	virtual void update(float elapsed) override;

	virtual void draw(float elapsed) override;
};

#endif /* !LOBBYSTATE_HPP_ */
