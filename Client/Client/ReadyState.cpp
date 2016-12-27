#include <iostream>
#include "ReadyState.hpp"
#include "SelectionState.hpp"
#include "UITools.hpp"

ReadyState::ReadyState(App &a, const ScrollingBack &bk, const ScrollingBack &up) :
	AState(a), back(bk), upper(up)
{
	players.push_back(new Label(app.win, "Not Ready", IUIComponent::LEFT,
		sf::Color(Palette::CRIMSON), "Nova", 10, 15));
	players.push_back(new Label(app.win, "Not Ready", IUIComponent::LEFT,
		sf::Color(Palette::CRIMSON), "Nova", 10, 30));
	players.push_back(new Label(app.win, "Not Ready", IUIComponent::LEFT,
		sf::Color(Palette::CRIMSON), "Nova", 10, 45));
	players.push_back(new Label(app.win, "Not Ready", IUIComponent::LEFT,
		sf::Color(Palette::CRIMSON), "Nova", 10, 60));

	uiComponents.push_back(new Button(app.win, "Ready", [&]() {
		std::cout << "Ready" << std::endl;
		players[0]->setColor(sf::Color(Palette::GREEN));
	}, 20, 10, 75, 85)); uiComponents.push_back(new Button(app.win, "Back", [&]() {
		app.setState(new SelectionState(app, back, upper));
		std::cout << "BACK TO THE MENUUU" << std::endl;
	}, 20, 10, 5, 85));

	uiComponents.push_back(new Label(app.win, "R-TYPE", IUIComponent::CENTERED,
		sf::Color(Palette::GOLD), "Nova", 50, 6, 50));
	for (std::vector<Label *>::iterator it = players.begin(); it != players.end(); it++)
	{
		uiComponents.push_back(*it);
	}
}

ReadyState::~ReadyState()
{
}

void ReadyState::update(float elapsed)
{
	sf::Event e;
	while (app.win.pollEvent(e))
	{
		updateUI(e, elapsed);
	}
}

void ReadyState::draw(float elapsed)
{
	back.draw(elapsed);
	upper.draw(elapsed);
	drawUI(elapsed);
}
