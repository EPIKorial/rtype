#include "Label.hpp"
#include "FontLib.hpp"

Label::Label(sf::RenderWindow &wi, const std::string & txt, AlignType al, const sf::Color &col, const std::string &font, float pX, float pY,
	float sze, bool show) : win(wi), text(txt), posX(pX), posY(pY), size(sze), quiet(!show), align(al), Dim(wi)
{
	sftxt.setString(txt);
	sftxt.setFillColor(col);
	sftxt.setStyle(sf::Text::Bold);
	sftxt.setCharacterSize(size);
	if (FontLib::have(font))
		sftxt.setFont(*FontLib::get(font));
}

Label::~Label()
{
}

bool Label::isQuiet() const
{
	return quiet;
}

void Label::setQuiet(bool b)
{
	quiet = b;
}

bool Label::isIn(float x, float y) const
{
	return false;
}

void Label::trigger()
{
}

void Label::unTrigger()
{
}

void Label::hover(float elapsed)
{
}

bool Label::isActive() const
{
	return false;
}

void Label::setActive(bool)
{
}

void Label::triggerKey(const sf::Event &, float elapsed)
{
}

void Label::update(float elapsed)
{
}

void Label::draw(float elapsed)
{
	switch (align)
	{
	case LEFT:
		sftxt.setPosition(Dim.getRealWidth(posX), Dim.getRealHeight(posY));
		break;
	case CENTERED:
		sftxt.setPosition(Dim.getRealWidth(posX) - (sftxt.getLocalBounds().width / 2.f),
			Dim.getRealHeight(posY) - (sftxt.getLocalBounds().height / 2.f));
		break;
	case RIGHT:
		sftxt.setPosition(Dim.getRealWidth(posX) - sftxt.getLocalBounds().width,
			Dim.getRealHeight(posY) - sftxt.getLocalBounds().height);
	}
	win.draw(sftxt);
}
