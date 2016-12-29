#pragma once

#ifndef LABEL_HPP_
# define LABEL_HPP_

# include <string>
# include <SFML/Graphics.hpp>
# include "IUIComponent.hpp"
# include "ScreenHelper.hpp"

class Label : public IUIComponent
{
	std::string text;
	float posX;
	float posY;
	float size;
	sf::Text sftxt;
	sf::RenderWindow &win;
	bool quiet;
	AlignType align;
	ScreenHelper Dim;

public:

	Label(sf::RenderWindow &, const std::string &text, AlignType, const sf::Color &, const std::string &font, float posX = 0, float posY = 0, float size = RECOMMENDED_FONT_SIZE, bool show = true);
	virtual ~Label();

	void setText(const std::string &);
	const std::string &getText(void) const;

	void setColor(const sf::Color &);

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

#endif /* !LABEL_HPP_ */