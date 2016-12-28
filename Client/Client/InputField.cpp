#include "InputField.hpp"
#include "Palette.hpp"
#include "FontLib.hpp"

InputField::InputField(sf::RenderWindow &wi, const std::string & palceholder,
	float pX, float pY, int sX, bool show) :
	win(wi), placeholder(palceholder), posX(pX), posY(pY), sizeX(sX), quiet(!show), Dim(wi), active(false), hovered(false)
{
	shape.setFillColor(sf::Color::Black);
	shape.setOutlineColor(sf::Color(Palette::DARKMAGENTA));
	shape.setOutlineThickness(-2.5);
	shape.setSize(sf::Vector2f(Dim.getRealWidth(sizeX), RECOMMENDED_HEIGHT));
	in.setFillColor(sf::Color(Palette::DARKMAGENTA));
	in.setCharacterSize(RECOMMENDED_FONT_SIZE);
	in.setStyle(sf::Text::Bold);
	if (FontLib::have("Nova"))
		in.setFont(*FontLib::get("Nova"));
	fillField(palceholder);
}

InputField::~InputField()
{
}

const std::string & InputField::getText(void) const
{
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
	return (Dim.getRealWidth(x) >= Dim.getRealWidth(posX) && Dim.getRealWidth(x) <= Dim.getRealWidth(posX) + Dim.getRealWidth(sizeX))
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
		fillField(filled);
	}
	else
	{
		if (filled.size() == 0)
			fillField(placeholder);
		shape.setOutlineColor(sf::Color(Palette::DARKMAGENTA));
	}
	in.setFillColor(shape.getOutlineColor());
}

void InputField::fillField(const std::string &tofill) 
{
	in.setString(tofill);
	int offset = 0;

	if (tofill.size() > 0)
	{
		while (in.getLocalBounds().width + (RECOMMENDED_PADDING_HORIZ * 1.5) > shape.getLocalBounds().width
			&& offset < tofill.size())
		{
			in.setString(tofill.substr(offset, tofill.size() - offset));
			offset++;
		}
	}
}

void InputField::triggerKey(const sf::Event &e, float elapsed)
{
	if (e.type == sf::Event::TextEntered)
	{
		if (e.text.unicode == 8 && filled.size() > 0)
			filled.pop_back();
		else if (e.text.unicode >= ' ' && e.text.unicode < 128)
			filled += static_cast<char>(e.text.unicode);
		fillField(filled);
	}
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
	shape.setSize(sf::Vector2f(Dim.getRealWidth(sizeX), RECOMMENDED_HEIGHT));
	in.setPosition(Dim.getRealWidth(posX) + RECOMMENDED_PADDING_VERTI,
		Dim.getRealHeight(posY) + RECOMMENDED_PADDING_VERTI);
	win.draw(shape);
	win.draw(in);
}
