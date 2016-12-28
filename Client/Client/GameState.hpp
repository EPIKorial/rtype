#pragma once

#ifndef GAMESTATE_HPP_
# define GAMESTATE_HPP_

# include <vector>
# include "ScrollingBack.hpp"
# include "AState.hpp"
# include "IDrawable.hpp"

class GameState : public AState
{
	// Prob better as a map
	std::vector<IDrawable *> env;

public:
	GameState(App &, const ScrollingBack &, const ScrollingBack &);
	virtual ~GameState();

	// Inherited via AState
	virtual void update(float elapsed) override;

	virtual void draw(float elapsed) override;

};

#endif /* !GAMESTATE_HPP_ */
