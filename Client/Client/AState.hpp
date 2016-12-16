#pragma once

#ifndef ASTATE_HPP_
# define ASTATE_HPP_

# include <vector>
# include "App.hpp"
# include "IUIComponent.hpp"
# include "IState.hpp"
# include "ScreenHelper.hpp"

class AState : public IState
{
protected:
	std::vector<IUIComponent *> uiComponents;
	App &app;
	ScreenHelper Dim;

	virtual void keyboardEventUI(const sf::Event &, float elapsed);
	virtual void mouseEventUI(const sf::Event &, float elapsed);

public:
	AState(App &);
	virtual ~AState();

	// Inherited via IState
	virtual void update(float elapsed) override = 0;
	virtual void draw(float elapsed) override = 0;

	virtual void drawUI(float elapsed);
	virtual void updateUI(const sf::Event &, float elapsed);
};

#endif /* !ASTATE_HPP_ */
