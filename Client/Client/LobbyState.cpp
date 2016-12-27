#include <iostream>
#include "LobbyState.hpp"
#include "MenuState.hpp"
#include "UITools.hpp"

LobbyState::LobbyState(App &ap) : AState(ap), background(ap.win, "Assets/Images/stars.jpg", 3)
{
	backTimer = 0;
	Label *label = new Label(app.win, "Lobby", IUIComponent::CENTERED, sf::Color(Palette::CRIMSON),
		"Nova", 50, 6, 50);
	Label &refLabel = *label;

	InputField *field = new InputField(app.win, "IP Adress", 5, 50, 25);
	InputField &rf = *field;

	uiComponents.push_back(field);
	uiComponents.push_back(new Button(app.win, "Connect", [&]() {
		std::cout << "Connecting" << std::endl;
	}, 20, 10, 5, 70));
	uiComponents.push_back(new Button(app.win, "Back", [&]() {
		ap.setState(new MenuState(ap));
		std::cout << "BACK TO THE MENUUU" << std::endl;
	}, 20, 10, 5, 85));
	


	uiComponents.push_back(label);
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
	if (backTimer < 14.f)
		backTimer += elapsed;
	if (backTimer > 3.f && backTimer < 14.f)
	{
		background.setSpeed(background.getSpeed() + backTimer / 9.f);
	}
	background.draw(elapsed);
	drawUI(elapsed);
}
