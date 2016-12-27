#pragma once

#ifndef READYSTATE_HPP_
# define READYSTATE_HPP_

# include <vector>
# include "AState.hpp"
# include "ScrollingBack.hpp"
# include "Label.hpp"

class ReadyState : public AState
{
	ScrollingBack upper;
	ScrollingBack back;

	std::vector<Label *> players;

public:
	ReadyState(App &, const ScrollingBack &, const ScrollingBack &);
	virtual ~ReadyState();


	// Inherited via AState
	virtual void update(float elapsed) override;

	virtual void draw(float elapsed) override;

};

#endif /* !READYSTATE_HPP_ */
