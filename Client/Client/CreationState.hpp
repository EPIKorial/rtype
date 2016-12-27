#pragma once

#ifndef CREATIONSTATE_HPP_
# define CREATIONSTATE_HPP_

# include "AState.hpp"
# include "ScrollingBack.hpp"

class CreationState : public AState
{
	ScrollingBack upper;
	ScrollingBack back;

public:
	CreationState(App &, const ScrollingBack &, const ScrollingBack &);
	virtual ~CreationState();



	// Inherited via AState
	virtual void update(float elapsed) override;

	virtual void draw(float elapsed) override;

};

#endif /* !CREATIONSTATE_HPP_ */