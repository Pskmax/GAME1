#pragma once

#include<iostream>
#include<vector>
#include<ctime>

#include "Player.h"
#include "Bat.h"

/*
	Class that acts as the game engine.
	Wrapper class.
*/

class Game
{
private:
	//Variable
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Mouse positions
	sf::Vector2i mousePosWindow;

	//Game logic
	int points;
	float spawnTimer;
	float spawnTimerMax;
	int maxBats;

	//Game objects
	std::vector<Bat> bats;

	Player player;

	Bat bat;

	//Private Functions
	void initVariable();
	void initWindow();

public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	//Functions
	void spawnBat();
	void pollEvents();

	void updateMousePositions();
	void update();

	void render();
};

