#pragma once

#ifndef GAMESTATE_HPP_
# define GAMESTATE_HPP_

# include <vector>
# include <map>
# include "ScrollingBack.hpp"
# include "AState.hpp"
# include "Entity.hpp"
# include "PlayerController.hpp"

class GameState : public AState
{
	ScrollingBack back;
	ScrollingBack upper;
	std::map<int, Entity *> entities;

	PlayerController player;
	int myId;

	float backTimer;
	void drawBack(float elapsed);
public:
	GameState(App &, const ScrollingBack &, const ScrollingBack &);
	virtual ~GameState();

	// Inherited via AState
	virtual void update(float elapsed) override;

	virtual void draw(float elapsed) override;

};

#endif /* !GAMESTATE_HPP_ */
