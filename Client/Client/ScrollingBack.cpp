#include <iostream>
#include "ScrollingBack.hpp"

ScrollingBack::~ScrollingBack()
{
}

void ScrollingBack::start(void)
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

ScrollingBack::ScrollingBack(sf::RenderWindow &wi, const std::string &_background, float _speed) :
	win(wi), speed(_speed), lastPosX(0), active(true), background(_background)
{
	start();
}

ScrollingBack::ScrollingBack(const ScrollingBack &o) :
	win(o.win), speed(o.speed), lastPosX(o.lastPosX), active(o.active), background(o.background)
{
	start();
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
	if (speed < 0.f)
		speed = 0;
	else if (speed > 100.f)
		speed = 100.f;
}

float ScrollingBack::getSpeed(void) const
{
	return speed;
}
