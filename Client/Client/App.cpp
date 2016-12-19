#include "App.hpp"
#include "FontLib.hpp"

void App::loop()
{
	if (currentState)
		currentState->update(gameClock.getElapsedTime().asMilliseconds() / 100);
	gameClock.restart();
	if (drawClock.getElapsedTime().asMilliseconds() > FPS)
	{
		win.clear();
		if (currentState)
			currentState->draw(drawClock.getElapsedTime().asMilliseconds() / 100);
		win.display();
		drawClock.restart();
	}
}

App::App() : win(sf::VideoMode(800, 600), "R-Type +6"), currentState(nullptr), active(false)
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

void App::setState(IState *ns)
{
	delete currentState;
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
