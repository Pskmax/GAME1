#pragma once

#include<iostream>
#include<vector>
#include<ctime>

#include "Player.h"

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
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

	//Game objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;

	Player player;

	//Private Functions
	void initVariable();
	void initWindow();
	void initEnemies();	

public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	//Functions
	void spawnEnemy();

	void pollEvents();
	void updateMousePositions();
	void updateEnemies();
	void update();

	void renderEnemies();
	void reder();
};

