#include "ScreenHelper.hpp"

ScreenHelper::ScreenHelper(sf::RenderWindow &wi) : win(wi)
{
}

ScreenHelper::~ScreenHelper()
{
}

float ScreenHelper::getWidthRatio(int reqX)
{
	if (win.getSize().x == 0)
		return 0;
	return (reqX * 100) / win.getSize().x;
}

float ScreenHelper::getHeightRatio(int reqY)
{
	if (win.getSize().y == 0)
		return 0;
	return (reqY * 100) / win.getSize().y;
}

int ScreenHelper::getRealWidth(float rX)
{
	return (rX * win.getSize().x) / 100;
}

int ScreenHelper::getRealHeight(float rY)
{
	return (rY * win.getSize().y) / 100;
}
