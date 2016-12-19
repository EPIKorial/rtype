#include <iostream>
#include "FontLib.hpp"
#include "Button.hpp"
#include "Palette.hpp"

Button::Button(sf::RenderWindow &wi, const std::string & txte, float sX, float sY, float pX, float pY, bool show) :
	win(wi), text(txte), sizeX(sX), sizeY(sY), posX(pX), posY(pY), Dim(wi), active(false), quiet(!show)
{
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color(Palette::DEEPSKYBLUE));
	shape.setOutlineThickness(-5);
	txt.setString(txte);
	txt.setFillColor(sf::Color(Palette::DEEPSKYBLUE));
	txt.setStyle(sf::Text::Bold);
	if (FontLib::have("Nova"))
		txt.setFont(*FontLib::get("Nova"));

}

bool Button::isQuiet() const
{
	return quiet;
}

bool Button::isIn(float x, float y) const
{
	return (Dim.getRealWidth(x) >= Dim.getRealWidth(posX) && Dim.getRealWidth(x) <= Dim.getRealWidth(posX) + Dim.getRealWidth(sizeX))
		&& (Dim.getRealHeight(y) >= Dim.getRealHeight(posY) && Dim.getRealHeight(y) <= Dim.getRealHeight(posY) + Dim.getRealHeight(sizeY));
}

void Button::trigger()
{
	std::cout << "Clicked !" << std::endl;
	shape.setOutlineColor(sf::Color(Palette::DODGERBLUE));
}

void Button::unTrigger()
{
	std::cout << "Untriggered !" << std::endl;
	shape.setOutlineColor(sf::Color(Palette::DEEPSKYBLUE));
}

void Button::hover(float elapsed)
{
}

bool Button::isActive() const
{
	return active;
}

void Button::setActive(bool a)
{
	active = a;
	if (a)
		shape.setOutlineColor(sf::Color(Palette::DODGERBLUE));
	else
		shape.setOutlineColor(sf::Color(Palette::DEEPSKYBLUE));

}

void Button::triggerKey(const sf::Event &e, float elapsed)
{
	if (active && e.key.code == sf::Keyboard::Return)
		trigger();
}

void Button::update(float elapsed)
{
}

void Button::draw(float elapsed)
{
	
	shape.setPosition(Dim.getRealWidth(posX), Dim.getRealHeight(posY));
	shape.setSize(sf::Vector2f(Dim.getRealWidth(sizeX), Dim.getRealHeight(sizeY)));
	txt.setFillColor(shape.getOutlineColor());
	txt.setCharacterSize(30);
	txt.setPosition(Dim.getRealWidth(posX) + 15, Dim.getRealHeight(posY) + 15);
	win.draw(shape);
	win.draw(txt);
}

void Button::setQuiet(bool c)
{
	quiet = c;
	return;
}
