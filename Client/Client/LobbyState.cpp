#include <iostream>
#include "LobbyState.hpp"
#include "MenuState.hpp"
#include "Button.hpp"

LobbyState::LobbyState(App &ap) : AState(ap)
{
	uiComponents.push_back(new Button(app.win, "Connect", [&]() {
		std::cout << "Connecting" << std::endl;
	}, 20, 10, 5, 70));
	uiComponents.push_back(new Button(app.win, "Back", [&]() {
		ap.setState(new MenuState(ap));
		std::cout << "BACK TO THE MENUUU" << std::endl;
	}, 20, 10, 5, 85));
}

LobbyState::~LobbyState()
{
}

void LobbyState::update(float elapsed)
{
	sf::Event e;
	while (app.win.pollEvent(e))
	{
		updateUI(e, elapsed);
	}
}

void LobbyState::draw(float elapsed)
{
	drawUI(elapsed);
}
