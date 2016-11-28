#pragma once
#ifndef SFWINDOW_HPP_
# define SFWINDOW_HPP_

# include <string>
# include <SFML/Graphics.hpp>
# include "IWindow.hpp"

class sfWindow : public IWindow
{
	sf::RenderWindow win;

public:
	sfWindow(sf::Vector2f, const std::string &);
	sf::RenderWindow &getNativeWindow()
	{
		return win;
	}

	// Inherited via IWindow
	virtual void draw(Sprite &) override;
	virtual void render(void) override;
};

#endif /* !SFWINDOW_HPP_ */
