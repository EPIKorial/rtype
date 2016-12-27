#pragma once

#ifndef SELECTIONSTATE_HPP_
# define SELECTIONSTATE_HPP_

# include "AState.hpp"
# include "Button.hpp"
# include "ScrollingBack.hpp"

class SelectionState : public AState
{
	ScrollingBack back;
	ScrollingBack upper;
	Button *first;
	Button *second;
	Button *third;
	Button *fourth;

public:
	SelectionState(App &a, const ScrollingBack &, const ScrollingBack &);
	virtual ~SelectionState();

	// Inherited via AState
	virtual void update(float elapsed) override;

	virtual void draw(float elapsed) override;

};

#endif /* !SELECTIONSTATE_HPP_ */
