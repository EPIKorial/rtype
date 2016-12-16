#include <iostream>
#include "Button.hpp"

Button::Button(sf::RenderWindow &wi, const std::string & txt, float sX, float sY, float pX, float pY) :
	win(wi), text(txt), sizeX(sX), sizeY(sY), posX(pX), posY(pY), Dim(wi)
{
	shape.setFillColor(sf::Color::White);
}

bool Button::isQuiet() const
{
	return false;
}

bool Button::isIn(float x, float y) const
{
	return (x >= posX && x <= posX + sizeX)
		&& (y >= posY && y <= posY + sizeY);
}

void Button::trigger()
{
	std::cout << "Clicked !" << std::endl;
	shape.setFillColor(sf::Color::Red);
}

void Button::unTrigger()
{
	shape.setFillColor(sf::Color::White);
	std::cout << "Untriggered !" << std::endl;
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

void Button::draw(float elapsed)
{
	shape.setPosition(Dim.getRealWidth(posX), Dim.getRealHeight(posY));
	shape.setSize(sf::Vector2f(Dim.getRealWidth(sizeX), Dim.getRealHeight(sizeY)));
	win.draw(shape);
}
