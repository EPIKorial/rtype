#include <iostream>
#include "LobbyState.hpp"
#include "MenuState.hpp"
#include "UITools.hpp"

MenuState::MenuState(App &ap) : AState(ap), loaded(false), background(ap.win, "Assets/Images/stars.jpg", 3)
{
	uiComponents.push_back(new Button(app.win, "Play", [&]() { 
		ap.setState(new LobbyState(ap));
		std::cout << "LEAVE MENU" << std::endl;
	}, 20, 10, 5, 70));
	uiComponents.push_back(new Button(app.win, "Quit", [&]() {
		ap.quit();
		std::cout << "QUIT" << std::endl;
	}, 20, 10, 5, 85));
	uiComponents.push_back(new Label(app.win, "R-TYPE", IUIComponent::CENTERED,
		sf::Color(Palette::GOLD), "Nova", 50, 6, 50));
	/*loaded = texture.loadFromFile("Assets/Images/Background-3.png");
	sprite.setTexture(texture);*/
}

MenuState::~MenuState()
{
}

void MenuState::draw(float elapsed)
{
	/*sprite.setScale(Dim.getRealWidth(100) / 1600.f, Dim.getRealHeight(100) / 1200.f);
	app.win.draw(sprite);*/
	background.draw(elapsed);
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