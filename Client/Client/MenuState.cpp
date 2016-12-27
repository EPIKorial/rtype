#include <iostream>
#include "LobbyState.hpp"
#include "MenuState.hpp"
#include "UITools.hpp"

void MenuState::start()
{
	uiComponents.push_back(new Button(app.win, "Play", [&]() { 
		app.setState(new LobbyState(app, background, upper));
		std::cout << "LEAVE MENU" << std::endl;
	}, 20, 10, 5, 70));
	uiComponents.push_back(new Button(app.win, "Quit", [&]() {
		app.quit();
		std::cout << "QUIT" << std::endl;
	}, 20, 10, 5, 85));
	uiComponents.push_back(new Label(app.win, "R-TYPE", IUIComponent::CENTERED,
		sf::Color(Palette::GOLD), "Nova", 50, 6, 50));
	
}

MenuState::MenuState(App &ap) : AState(ap), loaded(false),
	background(ap.win, "Assets/Images/blue2.png", 3), upper(ap.win, "Assets/Images/transp-stars.png", 5)
{
	start();
}

MenuState::MenuState(App &ap, const ScrollingBack &bk, const ScrollingBack &up) : AState(ap), loaded(false),
	background(bk), upper(up)
{
	start();
}

MenuState::~MenuState()
{
}

void MenuState::draw(float elapsed)
{
	if (background.getSpeed() > 3.f)
	{
		background.setSpeed(background.getSpeed() - 0.25);
		if (background.getSpeed() < 3.f)
			background.setSpeed(3.f);
		upper.setSpeed(background.getSpeed() * 1.50);
	}
	background.draw(elapsed);
	upper.draw(elapsed);
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