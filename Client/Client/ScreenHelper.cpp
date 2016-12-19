#include "ScreenHelper.hpp"

ScreenHelper::ScreenHelper(sf::RenderWindow &wi) : win(wi)
{
}

ScreenHelper::~ScreenHelper()
{
}

float ScreenHelper::getWidthRatio(int reqX) const
{
	if (win.getSize().x == 0.f)
		return 0;
	return ((float)reqX * 100.f) / (float)win.getSize().x;
}

float ScreenHelper::getHeightRatio(int reqY) const
{
	if (win.getSize().y == 0.f)
		return 0;
	return ((float)reqY * 100.f) / (float)win.getSize().y;
}

int ScreenHelper::getRealWidth(float rX) const
{
	return (rX * win.getSize().x) / 100;
}

int ScreenHelper::getRealHeight(float rY) const
{
	return (rY * win.getSize().y) / 100;
}
