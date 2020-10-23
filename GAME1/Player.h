#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class Player
{
private:
	sf::Texture playerTexture;
	sf::Sprite  playerSprite;

	sf::Clock clock;

	int spriteSizeX;
	int spriteSizeY;
	int animationFrame = 0;

	float movementSpeedX;
	float movementSpeedY;

	void initVariables();
	void initPlayer();
	void time();

public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	void updateInput();
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

