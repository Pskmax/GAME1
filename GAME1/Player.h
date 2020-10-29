#pragma once

class Player
{
private:
	sf::Texture playerTexture;
	sf::Sprite  playerSprite;

	int spriteSizeX;
	int spriteSizeY;
	int animationFrame = 0;

	float movementSpeedX;
	float movementSpeedY;

	void initVariables();
	void initPlayer();

public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	float playerPosX();
	float playerPosY();

	void updateInput();
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

