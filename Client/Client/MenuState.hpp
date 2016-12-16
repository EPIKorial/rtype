#pragma once

#ifndef MENUSTATE_HPP_
# define MENUSTATE_HPP_

# include "AState.hpp"

class MenuState : public AState
{
public:
	MenuState(App &);
	virtual ~MenuState();



	// Inherited via AState
	virtual void update(float elapsed) override;

	virtual void draw(float elapsed) override;

};

#endif /* !MENUSTATE_HPP_ */