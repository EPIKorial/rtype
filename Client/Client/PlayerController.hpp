#pragma once
#ifndef PLAYERCONTROLLER_HPP_
# define PLAYERCONTROLLER_HPP_

# include <SFML/Graphics.hpp>
# include "Entity.hpp"

class PlayerController
{
	Entity *player;
	float speed;
	
	bool up;
	bool down;
	bool right;
	bool left;

	static const float ANGLE_MOVEMENT;

	void toFalse();
public:
	PlayerController(float speed = 10, Entity *e = nullptr);
	~PlayerController();

	void setPlayer(Entity *);

	void passEvent(sf::Event &e);
	void compute(float elapsed);

	void setSpeed(float s);
	float getSpeed() const;
};

#endif /* !PLAYERCONTROLLER_HPP_ */