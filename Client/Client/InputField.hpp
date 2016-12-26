#pragma once

#ifndef INPUTFIELD_HPP_
# define INPUTFIELD_HPP_

# include <string>
# include <SFML/Graphics.hpp>
# include "IUIComponent.hpp"
# include "ScreenHelper.hpp"

class InputField : public IUIComponent
{
	std::string placeholder;
	std::string filled;
	float posX;
	float posY;
	//int charSize;
	sf::Text in;
	sf::RenderWindow &win;
	bool quiet;
	bool active;
	ScreenHelper Dim;
	sf::RectangleShape shape;
	bool hovered;
	int sizeX;

	void fillField(void);

public:
	InputField(sf::RenderWindow &, const std::string &placeholder, float pX = 0, float pY = 0, int sizeX = 10, bool show = true);
	virtual ~InputField();

	const std::string &getText(void) const;



	// Inherited via IUIComponent
	virtual bool isQuiet() const override;

	virtual void setQuiet(bool) override;

	virtual bool isIn(float x, float y) const override;

	virtual void trigger() override;

	virtual void unTrigger() override;

	virtual void hover(float elapsed) override;

	virtual bool isActive() const override;

	virtual void setActive(bool) override;

	virtual void triggerKey(const sf::Event &, float elapsed) override;

	virtual void update(float elapsed) override;

	virtual void draw(float elapsed) override;

};

#endif /* !INPUTFIELD_HPP_ */