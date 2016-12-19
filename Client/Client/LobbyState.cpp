#include "LobbyState.hpp"
#include <iostream>
#include "Button.hpp"

LobbyState::LobbyState(App &ap) : AState(ap)
{
	uiComponents.push_back(new Button(app.win, "Lobby Btn", []() { std::cout << "coucou" << std::endl; }, 20, 10, 5, 85));
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
