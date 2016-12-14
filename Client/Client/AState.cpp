#include "AState.hpp"

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

void AState::mouseEventUI(const sf::Event &, float elapsed)
{
	for (std::vector<IUIComponent *>::iterator it = uiComponents.begin(); it != uiComponents.end(); it++)
	{
		//TODO
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
	}
}
