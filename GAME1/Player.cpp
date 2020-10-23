#include "Player.h"

void Player::initVariables()
{
	this->movementSpeedX = 5.f;
	this->movementSpeedY = 4.f;
}

void Player::initPlayer()
{
	this->playerTexture.loadFromFile("image/Player.png");
	this->playerSprite.setTexture(playerTexture);
	this->spriteSizeX = playerTexture.getSize().x / 4;
	this->spriteSizeY = playerTexture.getSize().y / 4;

	playerSprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
	playerSprite.setScale(sf::Vector2f(1.5f, 1.5f));

	int animationFrame = 0;
}

void Player::time()
{
	sf::Time time;
}


Player::Player(float x, float y)
{
	this->playerSprite.setPosition(x, y);

	this->initVariables();
	this->initPlayer(); 
}

Player::~Player()
{
	
}

void Player::updateInput()
{
	//Keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->playerSprite.move(this->movementSpeedX, .0f);
		this->playerSprite.setTextureRect(sf::IntRect(this->spriteSizeX * this->animationFrame, this->spriteSizeY * 2, this->spriteSizeX, this->spriteSizeY));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->playerSprite.move(-this->movementSpeedX, .0f);
		this->playerSprite.setTextureRect(sf::IntRect(this->spriteSizeX * this->animationFrame, this->spriteSizeY * 1, this->spriteSizeX, this->spriteSizeY));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->playerSprite.move(.0f, -this->movementSpeedY);
		this->playerSprite.setTextureRect(sf::IntRect(this->spriteSizeX * this->animationFrame, this->spriteSizeY * 3, this->spriteSizeX, this->spriteSizeY));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->playerSprite.move(.0f, this->movementSpeedY);
		this->playerSprite.setTextureRect(sf::IntRect(this->spriteSizeX * this->animationFrame, this->spriteSizeY * 0, this->spriteSizeX, this->spriteSizeY));
	}
	this->animationFrame++;

	if (this->animationFrame >= 3)
	{
		this->animationFrame = 0;
	}
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{
	sf::FloatRect playerBounds = this->playerSprite.getGlobalBounds();
	//Left
	if (playerBounds.left <= 0.f)
		this->playerSprite.setPosition(0.f, playerBounds.top);

	//Right
	else if (playerBounds.left + playerBounds.width >= target->getSize().x)
		this->playerSprite.setPosition(target->getSize().x - playerBounds.width, playerBounds.top);

	//Top
	if (playerBounds.top <= 0.f)
		this->playerSprite.setPosition(playerBounds.left, 0.f);

	//Bottom
	else if (playerBounds.top + playerBounds.height >= target->getSize().y)
		this->playerSprite.setPosition(playerBounds.left, target->getSize().y - playerBounds.height);
}

void Player::update(const sf::RenderTarget* target)
{
	this->updateInput();

	//Window bounds collision
	this->updateWindowBoundsCollision(target);

	sf::Time time=this->clock.restart();
	printf(" %f\n", time.asSeconds());
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->playerSprite);
}
