#include <iostream>
#include "LobbyState.hpp"
#include "MenuState.hpp"
#include "Button.hpp"
#include "Label.hpp"
#include "Palette.hpp"

LobbyState::LobbyState(App &ap) : AState(ap)
{
	Label *label = new Label(app.win, "Lobby", IUIComponent::CENTERED, sf::Color(Palette::CRIMSON),
		"Nova", 50, 6, 50);
	Label &refLabel = *label;

	uiComponents.push_back(label);
	uiComponents.push_back(new Button(app.win, "Connect", [&]() {
		std::cout << "Connecting" << std::endl;
		refLabel.setText("Connecting....");
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
