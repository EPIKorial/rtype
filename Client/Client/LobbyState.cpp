#include <iostream>
#include <sstream>
#include "LobbyState.hpp"
#include "Jukebox.hpp"
#include "MenuState.hpp"
#include "SelectionState.hpp"
#include "UITools.hpp"
#include "ClientTcp.hpp"

LobbyState::LobbyState(App &ap, const ScrollingBack &back, const ScrollingBack &up) : AState(ap),
	background(back), upper(up)
{
	backTimer = 0;
	Label *label = new Label(app.win, "", IUIComponent::CENTERED,
		sf::Color(Palette::ORANGERED), "Nova", 50, 25);
	Label &refLabel = *label;

	InputField *field = new InputField(app.win, "Nickname", 5, 55, 50);
	InputField &nick = *field;
	uiComponents.push_back(field);

	field = new InputField(app.win, "Host", 5, 70, 50);
	InputField &hostInput = *field;
	uiComponents.push_back(field);

	field = new InputField(app.win, "Port", 56, 70, 20);
	InputField &portInput = *field;
	uiComponents.push_back(field);


	uiComponents.push_back(new Button(app.win, "Connect", [&]() {
		std::cout << "CONNECT BUTTON" << std::endl;
		
		refLabel.setText("");
		if (nick.getText().size() < 1)
		{
			if (Jukebox::have("error"))
				Jukebox::get("error").play();
			refLabel.setText("Nickname has to be at least one letter");
			return;
		}
		std::stringstream stream(portInput.getText());
		int port = 0;
		stream >> port;
		if (port == 0)
		{
			if (Jukebox::have("error"))
				Jukebox::get("error").play();
			refLabel.setText("Port is invalid");
			return;
		}

		// Bypass to show
		if (hostInput.getText().compare("ninja") == 0)
		{
			app.setState(new SelectionState(app, background, upper));
			return;
		}

		// Lets try to connect:
		refLabel.setText("Connecting...");
		std::cout << hostInput.getText() << ":" << port << std::endl;
		
		
		rtype::ClientTcp con(port, hostInput.getText());

		con.start();
		
		// Connected:
		if (con.isActive())
		{
			app.setState(new SelectionState(app, background, upper));
		}
		else
		{
			if (Jukebox::have("error"))
				Jukebox::get("error").play();
			refLabel.setText("Could not connect");
		}
		con.stop();
	}, 20, 10, 75, 85));
	uiComponents.push_back(new Button(app.win, "Back", [&]() {
		ap.setState(new MenuState(ap, background, upper));
		std::cout << "BACK TO THE MENUUU" << std::endl;
	}, 20, 10, 5, 85));
	

	uiComponents.push_back(new Label(app.win, "R-TYPE", IUIComponent::CENTERED,
		sf::Color(Palette::GOLD), "Nova", 50, 6, 50));
	uiComponents.push_back(label);
	uiComponents.push_back(new Label(app.win, "Connect to a server", IUIComponent::LEFT,
		sf::Color(Palette::DEEPSKYBLUE), "Nova", 6.5, 50, IUIComponent::RECOMMENDED_FONT_SIZE * 0.6));
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
