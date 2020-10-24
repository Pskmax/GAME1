
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class Bat
{
private:
	sf::Texture batTexture;
	sf::Sprite batSprite;

	int spriteSizeX;
	int spriteSizeY;

	void initBat();

public:
	Bat(float x = 100.f, float y = 100.f);
	virtual ~Bat();

	//Functions
	void update();
	void render(sf::RenderTarget& target);
};

