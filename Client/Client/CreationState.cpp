#include <iostream>
#include "CreationState.hpp"
#include "SelectionState.hpp"
#include "ReadyState.hpp"
#include "UITools.hpp"

CreationState::CreationState(App &a, const ScrollingBack &bk, const ScrollingBack &up) :
	AState(a), upper(up), back(bk)
{
	InputField *field = new InputField(app.win, "Room name", 10, 50, 80);
	InputField &rf = *field;

	uiComponents.push_back(field);

	uiComponents.push_back(new Button(app.win, "Create", [&]() {
		std::cout << "create room: " << rf.getText() << std::endl;
		app.setState(new ReadyState(app, back, upper));
	}, 20, 10, 75, 85));

	uiComponents.push_back(new Button(app.win, "Back", [&]() {
		app.setState(new SelectionState(app, back, upper));
		std::cout << "Back to selection " << std::endl;
	}, 20, 10, 5, 85));

	uiComponents.push_back(new Label(app.win, "R-TYPE", IUIComponent::CENTERED,
		sf::Color(Palette::GOLD), "Nova", 50, 6, 50));

}

CreationState::~CreationState()
{
}

void CreationState::update(float elapsed)
{
	sf::Event e;
	while (app.win.pollEvent(e))
	{
		updateUI(e, elapsed);
	}
}

void CreationState::draw(float elapsed)
{
	back.draw(elapsed);
	upper.draw(elapsed);
	drawUI(elapsed);
}
