#pragma once

#ifndef MENUSTATE_HPP_
# define MENUSTATE_HPP_

# include <SFML/Graphics.hpp>
# include "AState.hpp"
# include "ScrollingBack.hpp"

class MenuState : public AState
{
	sf::Texture texture;
	sf::Sprite sprite;
	bool loaded;
	ScrollingBack background;
	ScrollingBack upper;

	void start();

public:
	MenuState(App &);
	MenuState(App &, const ScrollingBack &, const ScrollingBack &, const std::string &s = "");

	virtual ~MenuState();



	// Inherited via AState
	virtual void update(float elapsed) override;

	virtual void draw(float elapsed) override;

};

#endif /* !MENUSTATE_HPP_ */