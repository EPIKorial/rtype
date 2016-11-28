#pragma once

#ifndef ISTATE_HPP_
# define ISTATE_HPP_

# include <SFML/Graphics.hpp>

class IState
{
public:
	virtual ~IState() {}

	/**
	* called each loop time
	*/
	virtual void update(float elapsed) = 0;

	/**
	* called often to draw
	*/
	virtual void draw(float elapsed) = 0;
};

#endif /* !ISTATE_HPP_ */