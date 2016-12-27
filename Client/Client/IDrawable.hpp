#pragma once

#ifndef IDRAWABLE_HPP_
# define IDRAWABLE_HPP_

class IDrawable
{
public:
	virtual ~IDrawable() {}

	virtual void draw(float elapsed) = 0;
	virtual void update(float elapsed) = 0;
};

#endif /* !IDRAWABLE_HPP_ */