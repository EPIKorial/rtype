#include <iostream>
#include "Entity.hpp"


Entity::Entity(sf::RenderWindow &wi, const std::string &as,
	float posX, float posY, float sizeX, float sizeY) :
	win(wi), Dim(wi), asset(as), pX(posX), pY(posY), sX(sizeX), sY(sizeY), loaded(true)
{
	if (texture.loadFromFile(asset))
	{
		sprite.setTexture(texture);
		resize();
	}
	else
	{
		std::cerr << "Could not load :" << asset << std::endl;
		loaded = false;
	}
}

Entity::~Entity()
{
}

void Entity::setPos(float x, float y)
{
	pX = x;
	pY = y;
}

float Entity::getPosX() const
{
	return pX;
}

float Entity::getPosY() const
{
	return pY;
}


void Entity::draw(float elapsed)
{
	if (loaded)
	{
		if (oldScreenX != win.getSize().x || oldScreenY != win.getSize().y)
			resize();
		sprite.setPosition(Dim.getRealWidth(pX), Dim.getRealHeight(pY));
		win.draw(sprite);
	}
}

void Entity::update(float elapsed)
{
}

void Entity::resize()
{
	oldScreenX = win.getSize().x;
	oldScreenY = win.getSize().y;
	sprite.setScale((float)Dim.getRealWidth(sX) / texture.getSize().x,
		(float)Dim.getRealHeight(sY) / texture.getSize().y);
	sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
}
