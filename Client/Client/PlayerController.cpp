#include <cmath>
#include "PlayerController.hpp"

const float PlayerController::ANGLE_MOVEMENT = 0.707;

void PlayerController::toFalse()
{
	up = false;
	down = false;
	right = false;
	left = false;
}

PlayerController::PlayerController(float _speed, Entity *e) : player(e), speed(_speed),
	up(false), down(false), left(false), right(false)
{
}

PlayerController::~PlayerController()
{
}

void PlayerController::setPlayer(Entity *e)
{
	player = e;
}

void PlayerController::passEvent(sf::Event & e)
{
	if (e.type == sf::Event::KeyPressed)
	{
		switch (e.key.code)
		{
		case sf::Keyboard::Up:
			up = true;
			break;
		case sf::Keyboard::Down:
			down = true;
			break;
		case sf::Keyboard::Right:
			right = true;
			break;
		case sf::Keyboard::Left:
			left = true;
			break;
		}
	}
	else if (e.type == sf::Event::KeyReleased)
	{
		switch (e.key.code)
		{
		case sf::Keyboard::Up:
			up = false;
			break;
		case sf::Keyboard::Down:
			down = false;
			break;
		case sf::Keyboard::Right:
			right = false;
			break;
		case sf::Keyboard::Left:
			left = false;
			break;
		}
	}
}

void PlayerController::compute(float elapsed)
{
	if (up || down || left || right)
	{
		float movHoriz = 0;
		float movVert = 0;
		if (up)
		{
			if (left || right)
			{
				movVert = -ANGLE_MOVEMENT;
				if (left)
					movHoriz -= ANGLE_MOVEMENT;
				else if (right)
					movHoriz += ANGLE_MOVEMENT;
			}
			else
				movVert = -1.f;
		}
		if (down)
		{
			if (left || right)
			{
				movVert += ANGLE_MOVEMENT;
				if (left)
					movHoriz -= ANGLE_MOVEMENT;
				if (right)
					movHoriz += ANGLE_MOVEMENT;
			}
			else
				movVert += 1.f;
		}
		if (left)
			movHoriz = -1.f;
		else if (right)
			movHoriz = 1.f;
		if (left && right)
			movHoriz = 0;

		player->setPos(player->getPosX() + (speed * elapsed * movHoriz),
			player->getPosY() + (speed * elapsed * movVert));
	}
}

void PlayerController::setSpeed(float s)
{
	speed = s;
}

float PlayerController::getSpeed() const
{
	return speed;
}
