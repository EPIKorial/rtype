#include "AState.hpp"
#include <iostream>

void AState::keyboardEventUI(const sf::Event &ev, float elapsed)
{
	for (std::vector<IUIComponent *>::iterator it = uiComponents.begin(); it != uiComponents.end(); it++)
	{
		if ((*it)->isActive() && ev.key.code == sf::Keyboard::Tab)
		{
			if ((it + 1) != uiComponents.end())
			{
				(*it)->unTrigger();
				(*(it + 1))->trigger();
			}
			else
			{
				(*it)->unTrigger();
				(*uiComponents.begin())->trigger();
			}
		}
		if ((*it)->isActive())
		{
			(*it)->triggerKey(ev, elapsed);
		}
	}
}

void AState::mouseEventUI(const sf::Event &e, float elapsed)
{
	float xRatio = 0;
	float yRatio = 0;

	if (e.type == sf::Event::MouseButtonPressed)
	{
		xRatio = Dim.getWidthRatio(e.mouseButton.x);
		yRatio = Dim.getHeightRatio(e.mouseButton.y);
	}
	else if (e.type == sf::Event::MouseMoved)
	{
		xRatio = Dim.getWidthRatio(e.mouseMove.x);
		yRatio = Dim.getHeightRatio(e.mouseMove.y);
	}

	for (std::vector<IUIComponent *>::iterator it = uiComponents.begin(); it != uiComponents.end(); it++)
	{
		if (!(*it)->isQuiet())
		{
			if ((*it)->isIn(xRatio, yRatio))
			{
				if (e.type == sf::Event::MouseButtonPressed)
				{
					(*it)->trigger();
					std::cout << xRatio << ":" << yRatio << std::endl;
				}
				else
					(*it)->hover(elapsed);
			}
			else if (e.type == sf::Event::MouseButtonPressed)
				(*it)->unTrigger();
			(*it)->update(elapsed);
		}
	}
}

AState::AState(App &a) : app(a), Dim(a.win)
{
}

AState::~AState()
{
	for (std::vector<IUIComponent *>::iterator it = uiComponents.begin(); it != uiComponents.end(); it++)
	{
		delete (*it);
	}
}

void AState::drawUI(float elapsed)
{
	for (std::vector<IUIComponent *>::iterator it = uiComponents.begin(); it != uiComponents.end(); it++)
	{
		if (!(*it)->isQuiet())
		{
			(*it)->draw(elapsed);
		}
	}
}

void AState::updateUI(const sf::Event &ev, float elapsed)
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		keyboardEventUI(ev, elapsed);
		break;
	case sf::Event::TextEntered:
		keyboardEventUI(ev, elapsed);
		break;

	case sf::Event::MouseButtonPressed:
		mouseEventUI(ev, elapsed);
		break;
	case sf::Event::MouseMoved:
		mouseEventUI(ev, elapsed);
		break;

	case sf::Event::Closed:
		app.quit();
		break;

	case sf::Event::Resized:
		app.win.setView(sf::View(sf::FloatRect(0, 0, ev.size.width, ev.size.height)));
		break;
	}
}
