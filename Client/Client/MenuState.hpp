#pragma once

#ifndef MENUSTATE_HPP_
# define MENUSTATE_HPP_

# include "IState.hpp"
# include "App.hpp"

class MenuState : public IState
{
	App &app;

public:
	MenuState(App &);
	virtual ~MenuState();

	// Inherited via IState
	virtual void update(float elapsed) override;
	virtual void draw(float elapsed) override;
};

#endif /* !MENUSTATE_HPP_ */