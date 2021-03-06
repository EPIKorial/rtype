#include <iostream>
#include "App.hpp"
#include "FontLib.hpp"
#include "Jukebox.hpp"

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
	win.setVerticalSyncEnabled(true);
	gameClock.restart();
	drawClock.restart();
	FontLib::add("Nova", "Assets/Fonts/NovaSquare.ttf");
}

void App::run(void)
{
	active = true;
	Jukebox::add("mood", "Assets/Audio/DST-Acceleron.ogg");
	Jukebox::add("button", "Assets/Audio/button.wav");
	Jukebox::add("keypress", "Assets/Audio/keypress.wav");
	Jukebox::add("error", "Assets/Audio/error.wav");

	if (Jukebox::have("mood"))
	{
		Jukebox::get("mood").setLoop(true);
		Jukebox::get("mood").play();
	}
	while (active)
		loop();
	if (Jukebox::have("mood"))
	{
		Jukebox::get("mood").stop();
	}
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
