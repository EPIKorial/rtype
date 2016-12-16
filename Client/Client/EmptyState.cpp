#include "EmptyState.hpp"

void EmptyState::update(float elapsed)
{
	sf::Event e;
	while (app.win.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
			app.quit();
	}
}

void EmptyState::draw(float elapsed)
{
}
