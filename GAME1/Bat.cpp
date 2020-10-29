#include "IncludeEverything.h"
#include "Player.h"
#include "Bat.h"

Player player;

void Bat::initVariables()
{
	this->movementSpeedX = 1.f;
	this->movementSpeedY = 1.25f;
}

void Bat::initBat()
{
	this->batTexture.loadFromFile("image/Monsters.png");
	this->batSprite.setTexture(batTexture);
	this->spriteSizeX = batTexture.getSize().x / 12;
	this->spriteSizeY = batTexture.getSize().y / 8;

	batSprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
}

void Bat::batFollow()
{
}

Bat::Bat(float x, float y)
{
	this->batSprite.setPosition(x, y);
	if (this->batSprite.getPosition().x <= player.playerPosX())
	{
		this->batSprite.move(this->movementSpeedX, 0.f);
	}
	this->initBat();
}

Bat::~Bat()
{

}

void Bat::update()
{
	
}

void Bat::render(sf::RenderTarget& target)
{
	target.draw(this->batSprite);
}
