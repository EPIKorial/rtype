#include "GameState.hpp"

GameState::GameState(App &a, const ScrollingBack &bk, const ScrollingBack &up) :
	AState(a), back(bk), upper(up), backTimer(0), player(4)
{
	app.win.setKeyRepeatEnabled(false);
	entities[0] = new Entity(a.win, "Assets/Images/player.png", 50, 50, 10, 10);
	player.setPlayer(entities[0]);
	// Implying my player's Id is 0
	myId = 0;
}

GameState::~GameState()
{
	for (std::map<int, Entity *>::iterator it = entities.begin(); it != entities.end(); it++)
	{
		delete (it->second);
	}
	app.win.setKeyRepeatEnabled(true);
}

void GameState::update(float elapsed)
{
	sf::Event e;
	while (app.win.pollEvent(e))
	{
		updateUI(e, elapsed);
		if (e.type == sf::Event::KeyPressed || e.type == sf::Event::KeyReleased)
			player.passEvent(e);
	}
	for (std::map<int, Entity *>::iterator it = entities.begin(); it != entities.end(); it++)
	{
		it->second->update(elapsed);
	}
}

void GameState::draw(float elapsed)
{
	player.compute(elapsed);
	drawBack(elapsed);
	for (std::map<int, Entity *>::iterator it = entities.begin(); it != entities.end(); it++)
	{
		it->second->draw(elapsed);
	}
	drawUI(elapsed);
}

void GameState::drawBack(float elapsed)
{
	if (backTimer < 14.f)
		backTimer += elapsed;
	if (backTimer > 3.f && backTimer < 14.f)
	{
		back.setSpeed(back.getSpeed() + backTimer / 12.f);
		if (back.getSpeed() > 50.f)
			back.setSpeed(50.f);
		upper.setSpeed(back.getSpeed() * 1.20);
	}
	back.draw(elapsed);
	upper.draw(elapsed);
}
