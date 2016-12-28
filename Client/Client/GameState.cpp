#include "GameState.hpp"

GameState::GameState(App &a, const ScrollingBack &bk, const ScrollingBack &up) :
	AState(a)
{
	env.push_back(new ScrollingBack(bk));
	env.push_back(new ScrollingBack(up));
}

GameState::~GameState()
{
	for (std::vector<IDrawable *>::iterator it = env.begin(); it != env.end(); it++)
	{
		delete *it;
	}
}

void GameState::update(float elapsed)
{
	for (std::vector<IDrawable *>::iterator it = env.begin(); it != env.end(); it++)
	{
		(*it)->update(elapsed);
	}
	sf::Event e;
	while (app.win.pollEvent(e))
	{
		updateUI(e, elapsed);
	}
}

void GameState::draw(float elapsed)
{
	for (std::vector<IDrawable *>::iterator it = env.begin(); it != env.end(); it++)
	{
		(*it)->draw(elapsed);
	}
	drawUI(elapsed);
}
