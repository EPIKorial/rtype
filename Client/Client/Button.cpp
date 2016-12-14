#include "Button.hpp"

Button::Button(const std::string & text, float sizeX, float sizeY, float x, float y)
{
}

bool Button::isQuiet() const
{
	return false;
}

bool Button::isIn(float x, float y) const
{
	return false;
}

void Button::trigger()
{
}

void Button::unTrigger()
{
}

void Button::hover(float elapsed)
{
}

bool Button::isActive() const
{
	return false;
}

void Button::setActive(bool)
{
}

void Button::triggerKey(const sf::Event &e, float elapsed)
{
}

void Button::update(float elapsed)
{
}
