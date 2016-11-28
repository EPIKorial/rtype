#include "MenuState.hpp"

MenuState::MenuState(App &ap) : app(ap)
{
}

MenuState::~MenuState()
{
}

void MenuState::update(float elapsed)
{
	sf::Event e;
	while (app.win.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
			app.quit();
	}
}

void MenuState::draw(float elapsed)
{
	sf::CircleShape shape(100);
	shape.setFillColor(sf::Color::Green);
	app.win.draw(shape);
}
