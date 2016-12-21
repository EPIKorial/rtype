#pragma once

#ifndef EMPTYSTATE_HPP_
# define EMPTYSTATE_HPP_

# include "AState.hpp"

class EmptyState : public AState
{
public:
	EmptyState(App &a) : AState(a) {}
	virtual ~EmptyState() {}
	// Inherited via AState
	virtual void update(float elapsed) override;
	virtual void draw(float elapsed) override;
};

#endif /* !EMPTYSTATE_HPP_ */