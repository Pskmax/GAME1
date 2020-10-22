#include "Game.h"

//Private functions
void Game::initVariable()
{
	this->window = nullptr;

	///Game logic
	this->points = 0;
	this->enemySpawnTimerMax = 1000.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 5;
}

void Game::initWindow()
{
	this->videoMode.height = 720;
	this->videoMode.width = 1080;

	this->window = new sf::RenderWindow(this->videoMode, "REVERSE!", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Green);
}

//Constructors /Destructors
Game::Game()
{
	this->initVariable();
	this->initWindow();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
}

//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}

//Functions
void Game::spawnEnemy()
{
	/*
		@ return void

		Spawns enemies and sets their colors and positions.
		- Sets a random position.
		- Sets a random colors.
		- Adds enemy to the vector.
	*/

	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
	);

	this->enemy.setFillColor(sf::Color::Green);

	//Spawn the enemy
	this->enemies.push_back(this->enemy);

	//Remove enemies at end of screen
}

void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch(this->ev.type)
		{
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				if (this->ev.key.code == sf::Keyboard::Escape)
				{
					this->window->close();
				}
				break;
		}
	}
}

void Game::updateMousePositions()
{
	/*
		@ return void

		Updates the mouse position:
		- Mouse position relative to window (Vector2i)
	*/

	this->mousePosWindow = sf::Mouse::getPosition(*this->window);

}

void Game::updateEnemies()
{
	/*
		@ return void

		Updates the enemy spawn timer and spawns enemies
		when the total amount of enemies is smaller than the maximum
		Moves the enemies downwards.
		Removes the enemies at the edge of the screen. //TODO
	*/

	//Updating the timer for enemy spawning
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			//Spawn the enemy and reset the timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 1.f;
	}

	//Move the enemies
	for (auto &e : this->enemies)
	{
		e.move(0.f, 1.f);
	}
}

void Game::update()
{
	this->pollEvents();

	this->updateMousePositions();

	this->updateEnemies();

	//Update mouse position
	//Relative to the screen
	//std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << "\n";
	//Relative to the window
	std::cout << "Mouse pos: " 
		<< sf::Mouse::getPosition(*this->window).x << " " 
		<< sf::Mouse::getPosition(*this->window).y << "\n";

}

void Game::renderEnemies()
{
	for (auto& e : this->enemies)
	{
		//Rendering all the enemies
		this->window->draw(e);
	}
}

void Game::reder()
{
	/*
		@return void

		- clear old frame
		- reder objects
		- diplay frame in window

		Renders the game objects.
	*/

	this->window->clear();

	//Draw game objects
	this->renderEnemies();

	this->window->display();
}