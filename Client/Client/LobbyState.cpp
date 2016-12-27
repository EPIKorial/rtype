#include <iostream>
#include "LobbyState.hpp"
#include "MenuState.hpp"
#include "SelectionState.hpp"
#include "UITools.hpp"

LobbyState::LobbyState(App &ap, const ScrollingBack &back, const ScrollingBack &up) : AState(ap),
	background(back), upper(up)
{
	backTimer = 0;
	Label *label = new Label(app.win, "", IUIComponent::CENTERED,
		sf::Color(Palette::ORANGERED), "Nova", 50, 50);
	Label &refLabel = *label;

	InputField *field = new InputField(app.win, "IP Adress", 5, 70, 50);
	InputField &rf = *field;

	uiComponents.push_back(field);
	uiComponents.push_back(new Button(app.win, "Connect", [&]() {
		std::cout << "CONNECT BUTTON" << std::endl;
		
		refLabel.setText("");
		if (rf.getText().compare("ninja") == 0)
		{
			app.setState(new SelectionState(app, background, upper));
		}
		else
		{
			refLabel.setText("Could not connect");
		}
	}, 20, 10, 75, 85));
	uiComponents.push_back(new Button(app.win, "Back", [&]() {
		ap.setState(new MenuState(ap, background, upper));
		std::cout << "BACK TO THE MENUUU" << std::endl;
	}, 20, 10, 5, 85));
	

	uiComponents.push_back(new Label(app.win, "R-TYPE", IUIComponent::CENTERED,
		sf::Color(Palette::GOLD), "Nova", 50, 6, 50));
	uiComponents.push_back(label);
	uiComponents.push_back(new Label(app.win, "Connect to a server", IUIComponent::LEFT,
		sf::Color(Palette::DEEPSKYBLUE), "Nova", 6.5, 65, IUIComponent::RECOMMENDED_FONT_SIZE * 0.6));
}

LobbyState::~LobbyState()
{
}

void LobbyState::add(IUIComponent *uc)
{
	uiComponents.push_back(uc);
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
		background.setSpeed(background.getSpeed() + backTimer / 12.f);
		if (background.getSpeed() > 50.f)
			background.setSpeed(50.f);
		upper.setSpeed(background.getSpeed() * 1.20);
	}
	background.draw(elapsed);
	upper.draw(elapsed);
	drawUI(elapsed);
}
