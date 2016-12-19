#pragma once

#ifndef MENUSTATE_HPP_
# define MENUSTATE_HPP_

# include <SFML/Graphics.hpp>
# include "AState.hpp"

class MenuState : public AState
{
	sf::Texture texture;
	sf::Sprite sprite;
	bool loaded;

public:
	MenuState(App &);
	virtual ~MenuState();



	// Inherited via AState
	virtual void update(float elapsed) override;

	virtual void draw(float elapsed) override;

};

#endif /* !MENUSTATE_HPP_ */