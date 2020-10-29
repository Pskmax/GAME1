#include"Player.h"

class Bat
{
private:
	sf::Texture batTexture;
	sf::Sprite batSprite;

	int spriteSizeX;
	int spriteSizeY;

	float movementSpeedX;
	float movementSpeedY;

	void initVariables();
	void initBat();

	void batFollow();

public:
	Bat(float x = 100.f, float y = 100.f);
	virtual ~Bat();

	//Functions
	void update();
	void render(sf::RenderTarget& target);
};

