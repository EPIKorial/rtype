#include <iostream>
#include "ScrollingBack.hpp"

ScrollingBack::~ScrollingBack()
{
}

ScrollingBack::ScrollingBack(sf::RenderWindow &wi, const std::string &background, float _speed) :
	win(wi), speed(_speed), lastPosX(0), active(true)
{
	if (texture.loadFromFile(background))
	{
		picture.setTexture(texture);
		imgWidth = picture.getLocalBounds().width;
		imgHeight = picture.getLocalBounds().height;
	}
	else
	{
		std::cerr << "Could not load :" << background << std::endl;
		active = false;
	}
}

void ScrollingBack::draw(float elapsed)
{
	if (!active)
		return;

	lastPosX -= elapsed * speed;
	if (lastPosX <= 0 - imgWidth)
		lastPosX = 0;

	float progressX = lastPosX;
	while (progressX < win.getSize().x)
	{
		drawVertically(progressX);
		progressX += imgWidth;
	}
}

void ScrollingBack::drawVertically(float xPos)
{
	float progressY = 0;

	while (progressY < win.getSize().y)
	{
		picture.setPosition(xPos, progressY);
		win.draw(picture);
		progressY += imgHeight;
	}
}

void ScrollingBack::update(float elapsed)
{
}

void ScrollingBack::setSpeed(float ns)
{
	speed = ns;
	
}

float ScrollingBack::getSpeed(void) const
{
	return speed;
}
