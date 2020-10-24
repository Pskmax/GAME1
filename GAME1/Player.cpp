#include "Player.h"

void Player::initVariables()
{
	this->movementSpeedX = 8.f;
	this->movementSpeedY = 7.5f;
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
	//Left
	if (this->playerSprite.getGlobalBounds().left <= 0.f)
		this->playerSprite.setPosition(0.f, this->playerSprite.getGlobalBounds().top);
	
	//Right
	if (this->playerSprite.getGlobalBounds().left + this->playerSprite.getGlobalBounds().width >= target->getSize().x)
		this->playerSprite.setPosition(target->getSize().x - this->playerSprite.getGlobalBounds().width, this->playerSprite.getGlobalBounds().top);

	//Top
	if (this->playerSprite.getGlobalBounds().top <= 0.f)
		this->playerSprite.setPosition(this->playerSprite.getGlobalBounds().left, 0.f);

	//Bottom
	if (this->playerSprite.getGlobalBounds().top + this->playerSprite.getGlobalBounds().height >= target->getSize().y)
		this->playerSprite.setPosition(this->playerSprite.getGlobalBounds().left, target->getSize().y - this->playerSprite.getGlobalBounds().height);
}

void Player::update(const sf::RenderTarget* target)
{
	this->updateInput();

	//Window bounds collision
	this->updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->playerSprite);
}
