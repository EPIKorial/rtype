#pragma once

#ifndef GAMESTATE_HPP_
# define GAMESTATE_HPP_

# include <vector>
# include <map>
# include "ScrollingBack.hpp"
# include "AState.hpp"
# include "Entity.hpp"
# include "PlayerController.hpp"
# include "Button.hpp"

class GameState : public AState
{
	// UI
	ScrollingBack back;
	ScrollingBack upper;
	float backTimer;
	void drawBack(float elapsed);
	bool haveEsc;
	Button *quitBtn;
	Button *leaveBtn;
	void handleEsc(bool);

	// Game
	std::map<int, Entity *> entities;

	PlayerController player;
	int myId;

public:
	GameState(App &, const ScrollingBack &, const ScrollingBack &);
	virtual ~GameState();

	// Inherited via AState
	virtual void update(float elapsed) override;

	virtual void draw(float elapsed) override;

};

#endif /* !GAMESTATE_HPP_ */
