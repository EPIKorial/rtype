#pragma once

#ifndef SCROLLINGBACK_HPP_
# define SCROLLINGBACK_HPP_

# include <string>
# include <SFML/Graphics.hpp>
# include "IDrawable.hpp"

class ScrollingBack : public IDrawable
{
protected:
	std::string background;
	sf::RenderWindow &win;
	sf::Sprite picture;
	sf::Texture texture;
	float speed;
	float lastPosX;
	bool active;

	float imgWidth;
	float imgHeight;
	
	void drawVertically(float xPos);
	void start(void);

public:
	virtual ~ScrollingBack();

	/**
	* @param background URL to the image
	* @param speed pixel/sec
	*/
	ScrollingBack(sf::RenderWindow &, const std::string &background, float speed = 10);
	ScrollingBack(const ScrollingBack &);

	// Inherited via IDrawable
	virtual void draw(float elapsed) override;

	virtual void update(float elapsed) override;

	void setSpeed(float);
	float getSpeed(void) const;

};

#endif /* !SCROLLINGBACK_HPP_ */
