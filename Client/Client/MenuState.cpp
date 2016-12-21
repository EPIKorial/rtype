#include <iostream>
#include "LobbyState.hpp"
#include "MenuState.hpp"
#include "Button.hpp"

MenuState::MenuState(App &ap) : AState(ap)
{
	uiComponents.push_back(new Button(app.win, "Play", [&]() { 
		ap.setState(new LobbyState(ap));
		std::cout << "LEAVE MENU" << std::endl;
	}, 20, 10, 5, 85));
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