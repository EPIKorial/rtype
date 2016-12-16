#include <iostream>
#include "MenuState.hpp"
#include "Button.hpp"

MenuState::MenuState(App &ap) : AState(ap)
{
	uiComponents.push_back(new Button(app.win, "Hello there", 50, 50, 25, 25));
}

MenuState::~MenuState()
{
}

void MenuState::draw(float elapsed)
{
	drawUI(elapsed);
}

void MenuState::update(float elapsed)
{
	sf::Event e;
	while (app.win.pollEvent(e))
	{
		updateUI(e, elapsed);
	}
}