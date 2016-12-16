#include "Button.hpp"

Button::Button(const std::string & txt, float sX, float sY, float pX, float pY) :
	text(txt), sizeX(sX), sizeY(sY), posX(pX), posY(pY)
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

void Button::draw(sf::RenderWindow &win, float elapsed)
{
}
