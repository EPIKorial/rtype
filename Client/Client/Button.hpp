#pragma once

#ifndef BUTTON_HPP_
# define BUTTON_HPP_

# include <string>
# include <SFML/Graphics.hpp>
# include "IUIComponent.hpp"
# include "ScreenHelper.hpp"

class Button : public IUIComponent
{
	std::string text;
	float sizeX;
	float sizeY;
	float posX;
	float posY;
	sf::RectangleShape shape;
	sf::RenderWindow &win;
	ScreenHelper Dim;

public:
	Button(sf::RenderWindow &, const std::string &text,
		float sizeX, float sizeY, float posX = 0, float posY = 0);
	virtual ~Button() {}

	// Inherited via IUIComponent
	virtual bool isQuiet() const override;
	virtual bool isIn(float, float) const override;
	virtual void trigger() override;
	virtual void unTrigger() override;
	virtual void hover(float elapsed) override;
	virtual bool isActive() const override;
	virtual void setActive(bool) override;
	virtual void triggerKey(const sf::Event &, float elapsed) override;
	virtual void update(float elapsed) override;
	virtual void draw(float elapsed);
};

#endif /* !BUTTON_HPP_ */