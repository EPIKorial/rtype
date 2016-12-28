#pragma once

#ifndef ENTITY_HPP_
# define ENTITY_HPP_

# include <string>
# include <SFML/Graphics.hpp>
# include "IDrawable.hpp"
# include "ScreenHelper.hpp"

class Entity : public IDrawable
{
	std::string asset;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::RenderWindow &win;
	ScreenHelper Dim;
	float sX;
	float sY;
	float pX;
	float pY;
	bool loaded;

	float oldScreenX;
	float oldScreenY;

	void resize();

public:
	Entity(sf::RenderWindow &, const std::string &, float posX, float posY, float sizeX, float sizeY);
	virtual ~Entity();

	void setPos(float x, float y);
	float getPosX() const;
	float getPosY() const;


	// Inherited via IDrawable
	virtual void draw(float elapsed) override;

	virtual void update(float elapsed) override;

};

#endif /* !ENTITY_HPP_ */
