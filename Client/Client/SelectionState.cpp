#include <iostream>
#include "SelectionState.hpp"
#include "LobbyState.hpp"
#include "UITools.hpp"

SelectionState::SelectionState(App & a, const ScrollingBack &bk, const ScrollingBack &up) :
	AState(a), back(bk), upper(up), first(nullptr), second(nullptr), third(nullptr), fourth(nullptr)
{
	first = new Button(app.win, "Room 1", [&]() {
		std::cout << "room 1" << std::endl;
	}, 70, 10, 10, 20);
	second = new Button(app.win, "Room 2", [&]() {
		std::cout << "room 2" << std::endl;
	}, 70, 10, 10, 35);
	third = new Button(app.win, "Room 3", [&]() {
		std::cout << "room 3" << std::endl;
	}, 70, 10, 10, 50);
	fourth = new Button(app.win, "Room 4", [&]() {
		std::cout << "room 4" << std::endl;
	}, 70, 10, 10, 65);

	uiComponents.push_back(first);
	uiComponents.push_back(second);
	uiComponents.push_back(third);
	uiComponents.push_back(fourth);

	uiComponents.push_back(new Button(app.win, "/\\", [&]() {
		std::cout << "up" << std::endl;
	}, 7.75, 10, 82.5, 20));

	uiComponents.push_back(new Button(app.win, "\\/", [&]() {
		std::cout << "down" << std::endl;
	}, 7.75, 10, 82.5, 65));

	uiComponents.push_back(new Button(app.win, "Create", [&]() {
		app.setState(new SelectionState(app, back, upper));
		std::cout << "Reload Selection state" << std::endl;
	}, 20, 10, 50, 85));

	uiComponents.push_back(new Button(app.win, "Reload", [&]() {
		app.setState(new SelectionState(app, back, upper));
		std::cout << "Reload Selection state" << std::endl;
	}, 20, 10, 75, 85));
	
	uiComponents.push_back(new Button(app.win, "Back", [&]() {
		app.setState(new LobbyState(app, back, upper));
		std::cout << "Back to lobby" << std::endl;
	}, 20, 10, 5, 85));

	uiComponents.push_back(new Label(app.win, "R-TYPE", IUIComponent::CENTERED,
		sf::Color(Palette::GOLD), "Nova", 50, 6, 50));
	uiComponents.push_back(new Label(app.win, "Pick a room", IUIComponent::LEFT,
		sf::Color(Palette::DEEPSKYBLUE), "Nova", 5, 15, IUIComponent::RECOMMENDED_FONT_SIZE * 0.6));
}

SelectionState::~SelectionState()
{
}

void SelectionState::update(float elapsed)
{
	sf::Event e;
	while (app.win.pollEvent(e))
	{
		updateUI(e, elapsed);
	}
}

void SelectionState::draw(float elapsed)
{
	if (back.getSpeed() > 3.f)
	{
		back.setSpeed(back.getSpeed() - 0.25);
		if (back.getSpeed() < 3.f)
			back.setSpeed(3.f);
		upper.setSpeed(back.getSpeed() * 1.50);
	}
	back.draw(elapsed);
	upper.draw(elapsed);
	drawUI(elapsed);
}
