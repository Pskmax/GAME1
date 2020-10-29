#include "IncludeEverything.h"
#include "Game.h"

//Private functions
void Game::initVariable()
{
	this->window = nullptr;

	///Game logic
	this->points = 0;
	this->spawnTimerMax = 1000.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxBats = 10;
}

void Game::initWindow()
{
	this->videoMode.height = 720;
	this->videoMode.width = 1080;

	this->window = new sf::RenderWindow(this->videoMode, "REVERSE!", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

//Constructors /Destructors
Game::Game()
{
	this->initVariable();
	this->initWindow();
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
void Game::spawnBat()
{
	if (this->spawnTimer < this->spawnTimerMax)
		this->spawnTimer += 1.f;
	else
	{
		if (this->bats.size() < this->maxBats)
		{
			this->bats.push_back(Bat());

			this->spawnTimer = 0.f;
		}
	}
		
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
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::update()
{
	this->pollEvents();

	//this->spawnBat();
	this->bat.update();
	this->player.update(this->window);

	this->updateMousePositions();

}

void Game::render()
{
	this->window->clear();

	//Draw game objects
	this->bat.render(*this->window);
	this->player.render(this->window);

	this->window->display();
}