#ifndef IWINDOW_HPP_
# define IWINDOW_HPP_

# include "Sprite.hpp"

/**
* Interface for GUI Library layer of abstraction
*/
class IWindow
{
public:
	virtual ~IWindow() {}

	/**
	* draw sprite on screen
	*/
	virtual void draw(Sprite &) = 0;

	/**
	* calls the render function
	*/
	virtual void render(void) = 0;
};

#endif /* !IWINDOW_HPP_ */