#pragma once

#ifndef SCREENHELPER_HPP_
# define SCREENHELPER_HPP_

# include <SFML/Graphics.hpp>

class ScreenHelper
{
protected:
	sf::RenderWindow &win;

public:
	ScreenHelper(sf::RenderWindow &);
	~ScreenHelper();

	float getWidthRatio(int) const;
	float getHeightRatio(int) const;

	int getRealWidth(float) const;
	int getRealHeight(float) const;
};

#endif /* !SCREENHELPER_HPP_ */