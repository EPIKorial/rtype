#include "InputField.hpp"
#include "Palette.hpp"
#include "FontLib.hpp"
#include <iostream>

InputField::InputField(sf::RenderWindow &wi, const std::string & palceholder,
	float pX, float pY, int max, bool show) :
	win(wi), placeholder(palceholder), posX(pX), posY(pY), charSize(max), quiet(!show), Dim(wi), active(false), hovered(false)
{
	shape.setFillColor(sf::Color::Black);
	shape.setOutlineColor(sf::Color(Palette::DARKMAGENTA));
	shape.setOutlineThickness(-2.5);
	in.setFillColor(sf::Color(Palette::DARKMAGENTA));
	in.setCharacterSize(RECOMMENDED_FONT_SIZE);
	in.setStyle(sf::Text::Bold);
	in.setString(palceholder);
	if (FontLib::have("Nova"))
		in.setFont(*FontLib::get("Nova"));
	sizeX = charSize * RECOMMENDED_FONT_SIZE + RECOMMENDED_PADDING_HORIZ * 2;
}

InputField::~InputField()
{
}

const std::string & InputField::getText(void) const
{
	std::cout << placeholder << std::endl;
	return filled;
}

bool InputField::isQuiet() const
{
	return quiet;
}

void InputField::setQuiet(bool q)
{
	quiet = q;
}

bool InputField::isIn(float x, float y) const
{
	return (Dim.getRealWidth(x) >= Dim.getRealWidth(posX) && Dim.getRealWidth(x) <= Dim.getRealWidth(posX) + sizeX)
		&& (Dim.getRealHeight(y) >= Dim.getRealHeight(posY) && Dim.getRealHeight(y) <= Dim.getRealHeight(posY) + RECOMMENDED_HEIGHT);
}

void InputField::trigger()
{
	setActive(true);
}

void InputField::unTrigger()
{
	setActive(false);
}

void InputField::hover(float elapsed)
{
	hovered = true;
}

bool InputField::isActive() const
{
	return active;
}

void InputField::setActive(bool a)
{
	active = a;
	if (a)
	{
		shape.setOutlineColor(sf::Color(Palette::BLUEVIOLET));
		in.setString(filled);
	}
	else
	{
		if (filled.size() == 0)
			in.setString(placeholder);
		shape.setOutlineColor(sf::Color(Palette::DARKMAGENTA));
	}
	in.setFillColor(shape.getOutlineColor());
}

void InputField::triggerKey(const sf::Event &e, float elapsed)
{
}

void InputField::update(float elapsed)
{
	if (!active)
	{
		if (hovered)
			shape.setOutlineColor(sf::Color(Palette::ORCHID));
		else
			shape.setOutlineColor(sf::Color(Palette::DARKMAGENTA));
	}
	hovered = false;
	in.setFillColor(shape.getOutlineColor());
}

void InputField::draw(float elapsed)
{
	shape.setPosition(Dim.getRealWidth(posX), Dim.getRealHeight(posY));
	shape.setSize(sf::Vector2f(sizeX, RECOMMENDED_HEIGHT));
	in.setPosition(Dim.getRealWidth(posX) + RECOMMENDED_PADDING_VERTI,
		Dim.getRealHeight(posY) + RECOMMENDED_PADDING_VERTI);
	win.draw(shape);
	win.draw(in);
}