#pragma once
#ifndef APP_HPP_
# define APP_HPP_

# include <SFML/Graphics.hpp>
# include "IState.hpp"

class App
{
protected:
	IState *currentState;
	IState *oldState;
	sf::Clock gameClock;
	sf::Clock drawClock;
	bool active;
	bool toDelete;

	void loop();

	static const int FPS;
public:
	sf::RenderWindow win;

	App();

	/**
	* Launch the graphic client
	*/
	void run(void);
	
	/**
	* Change current state of the app
	*/
	void setState(IState *, bool deleteIt = true);

	/**
	* Close the window and terminates the program
	*/
	void quit();

	bool getActive(void) const;
};

#endif /* !APP_HPP_ */