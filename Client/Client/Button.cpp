#include <iostream>
#include "FontLib.hpp"
#include "Button.hpp"
#include "Palette.hpp"

Button::Button(sf::RenderWindow &wi, const std::string & txte, const std::function<void()> fc, float sX, float sY, float pX, float pY, bool show) :
	win(wi), text(txte), sizeX(sX), sizeY(sY), posX(pX), posY(pY), Dim(wi), active(false), quiet(!show), callback(fc), hovered(false)
{
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color(Palette::DEEPSKYBLUE));
	shape.setOutlineThickness(-5);
	shape.setFillColor(sf::Color::Black);
	txt.setString(txte);
	txt.setFillColor(sf::Color(Palette::DEEPSKYBLUE));
	txt.setStyle(sf::Text::Bold);
	txt.setCharacterSize(30);
	if (FontLib::have("Nova"))
		txt.setFont(*FontLib::get("Nova"));
	txt.setFillColor(shape.getOutlineColor());

}

Button::~Button()
{
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
	callback();
	shape.setOutlineColor(sf::Color(Palette::DODGERBLUE));
	txt.setFillColor(shape.getOutlineColor());
}

void Button::unTrigger()
{
	std::cout << "Untriggered !" << std::endl;
	shape.setOutlineColor(sf::Color(Palette::DEEPSKYBLUE));
	txt.setFillColor(shape.getOutlineColor());
}

void Button::hover(float elapsed)
{
	hovered = true;
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
	txt.setFillColor(shape.getOutlineColor());

}

void Button::triggerKey(const sf::Event &e, float elapsed)
{
	if (active && e.key.code == sf::Keyboard::Return)
		trigger();
}

void Button::update(float elapsed)
{
	if (hovered)
	{
		shape.setOutlineColor(sf::Color(Palette::LIGHTBLUE));
		hovered = false;
	}
	else
		shape.setOutlineColor(sf::Color(Palette::DEEPSKYBLUE));
	txt.setFillColor(shape.getOutlineColor());
}

void Button::draw(float elapsed)
{
	
	shape.setPosition(Dim.getRealWidth(posX), Dim.getRealHeight(posY));
	if (Dim.getRealHeight(sizeY) <= RECOMMENDED_HEIGHT)
		shape.setSize(sf::Vector2f(Dim.getRealWidth(sizeX), Dim.getRealHeight(sizeY)));
	else
		shape.setSize(sf::Vector2f(Dim.getRealWidth(sizeX), RECOMMENDED_HEIGHT));
	txt.setPosition(Dim.getRealWidth(posX) + 15, Dim.getRealHeight(posY) + 10);
	win.draw(shape);
	win.draw(txt);
}

void Button::setQuiet(bool c)
{
	quiet = c;
	return;
}
