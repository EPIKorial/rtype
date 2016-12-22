#pragma once

#ifndef IUICOMPONENT_HPP_
# define IUICOMPONENT_HPP_

# include <SFML/Window/Event.hpp>	
# include <SFML/Graphics/RenderWindow.hpp>

class IUIComponent
{
public:
	enum AlignType
	{
		RIGHT,
		LEFT,
		CENTERED
	};

	virtual ~IUIComponent() {}

	/**
	* @return true if has to be drawn
	*/
	virtual bool isQuiet() const = 0;
	virtual void setQuiet(bool) = 0;

	/**
	* @return true if mouse is in hot zone
	*/
	virtual bool isIn(float x, float y) const = 0;


	virtual void trigger() = 0;
	virtual void unTrigger() = 0;
	virtual void hover(float elapsed) = 0;
	virtual bool isActive() const = 0;
	virtual void setActive(bool) = 0;
	virtual void triggerKey(const sf::Event &, float elapsed) = 0;
	virtual void update(float elapsed) = 0;
	virtual void draw(float elapsed) = 0;

	static const int RECOMMENDED_HEIGHT;
	static const int RECOMMENDED_PADDING_HORIZ;
	static const int RECOMMENDED_PADDING_VERTI;
	static const int RECOMMENDED_FONT_SIZE;
};

#endif /* !IUICOMPONENT_HPP_ */