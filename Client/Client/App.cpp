#include "App.hpp"
#include <iostream>
#include "FontLib.hpp"

const int App::FPS = 16; // 1000 / 60

void App::loop()
{
	if (toDelete)
	{
		delete oldState;
		toDelete = false;
	}
	if (currentState)
		currentState->update(gameClock.getElapsedTime().asMilliseconds() / 100.f);
	gameClock.restart();
	if (drawClock.getElapsedTime().asMilliseconds() > FPS)
	{
		win.clear();
		if (currentState)
			currentState->draw(drawClock.getElapsedTime().asMilliseconds() / 100.f);
		win.display();
		drawClock.restart();
	}
}

App::App() : win(sf::VideoMode(800, 600), "R-Type +6"), currentState(nullptr), active(false), toDelete(false), oldState(nullptr)
{
	gameClock.restart();
	drawClock.restart();
	FontLib::add("Nova", "Assets/Fonts/NovaSquare.ttf");
}

void App::run(void)
{
	active = true;
	while (active)
		loop();
	return;
}

void App::setState(IState *ns, bool deleteIt)
{
	toDelete = deleteIt;
	oldState = currentState;
	currentState = ns;
}

void App::quit()
{
	active = false;
	win.close();
	return;
}

bool App::getActive(void) const
{
	return active;
}
