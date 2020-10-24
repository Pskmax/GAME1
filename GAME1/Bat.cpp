#include "Bat.h"

void Bat::initBat()
{
	this->batTexture.loadFromFile("image/Monsters.png");
	this->batSprite.setTexture(batTexture);
	this->spriteSizeX = batTexture.getSize().x / 12;
	this->spriteSizeY = batTexture.getSize().y / 8;

	batSprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
}

Bat::Bat(float x, float y)
{
	this->batSprite.setPosition(x, y);

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
