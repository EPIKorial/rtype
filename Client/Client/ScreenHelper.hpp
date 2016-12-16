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

	float getWidthRatio(int);
	float getHeightRatio(int);

	int getRealWidth(float);
	int getRealHeight(float);
};

#endif /* !SCREENHELPER_HPP_ */