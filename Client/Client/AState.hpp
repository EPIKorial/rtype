#pragma once

#ifndef ASTATE_HPP_
# define ASTATE_HPP_

# include <vector>
# include "IUIComponent.hpp"
# include "IState.hpp"

class AState : public IState
{
	std::vector<IUIComponent *> uiComponents;

	virtual void keyboardEventUI(const sf::Event &, float elapsed);
	virtual void mouseEventUI(const sf::Event &, float elapsed);

public:
	virtual ~AState() {}

	// Inherited via IState
	virtual void update(float elapsed) override = 0;
	virtual void draw(float elapsed) override = 0;

	virtual void updateUI(const sf::Event &, float elapsed);
};

#endif /* !ASTATE_HPP_ */
