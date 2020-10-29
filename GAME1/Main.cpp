#include<iostream>
#include<vector>
#include<ctime>

//SFML
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

float playerMoveSpeedX = .15f;
float playerMoveSpeedY = .15f;

float batMoveSpeedX = .05f;
float batMoveSpeedY = .05f;

int main()
{
	// Render Window
	sf::RenderWindow window(sf::VideoMode(1080, 720), "REVERSE!");
	sf::Event event;

	// Smooth Animation
	sf::Clock clock;

	// Circle
	sf::CircleShape collision(100.f);
	collision.setPosition({ 200.f, 200.f });
	collision.setFillColor(sf::Color::Red);

	// Player Texture
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("image/Player.png"))
	{
		std::cout << "Player Load failed" << std::endl;
	}

	// Player Sprite
	int playerSizeX = playerTexture.getSize().x / 4;
	int playerSizeY = playerTexture.getSize().y / 4;

	sf::IntRect rectPlayer(0, 0, playerSizeX, playerSizeY);
	sf::Sprite playerSprite(playerTexture, rectPlayer);
	playerSprite.setTexture(playerTexture);
	playerSprite.setScale(1.2f, 1.2f);

	// Player Position
	sf::Vector2f playerSpawnPoint = { 0.f, 0.f };
	playerSprite.setPosition(playerSpawnPoint);

	// Player Animaton
	int playerAnimationFrame = 0;

	// Bat Player
	sf::Texture batTexture;
	if (!batTexture.loadFromFile("image/Monsters.png"))
	{
		std::cout << "Player Load failed" << std::endl;
	}

	// Bat Sprite
	int batSizeX = batTexture.getSize().x / 12;
	int batSizeY = batTexture.getSize().y / 8;

	sf::IntRect rectBat(batSizeX, 0, batSizeX, batSizeY);
	sf::Sprite batSprite(batTexture, rectBat);
	batSprite.setTexture(batTexture);
	batSprite.setScale(1.f, 1.f);
	
	// Bat Position
	sf::Vector2f batSpawnPoint = { 500.f, 500.f };
	batSprite.setPosition(batSpawnPoint);

	// Bat Animaton
	int batAnimationFrame = 0;


	// While Game is Running
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
				window.close();
		}
		window.clear();

		window.draw(collision);
		window.draw(playerSprite);
		window.draw(batSprite);

		// Player Update
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			rectPlayer.top = playerSizeY * 2;
			playerSprite.move(playerMoveSpeedX, 0.f);
			if (clock.getElapsedTime().asSeconds() > 0.3f)
			{
				if (rectPlayer.left == (playerSizeX * 3))
				{
					rectPlayer.left = 0;
				}
				else
				{
					rectPlayer.left += playerSizeX;
				}
				clock.restart();
			}
			playerSprite.setTextureRect(rectPlayer);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			rectPlayer.top = playerSizeY;
			playerSprite.move(-playerMoveSpeedX, 0.f);
			if (clock.getElapsedTime().asSeconds() > 0.3f)
			{
				if (rectPlayer.left == (playerSizeX * 3))
				{
					rectPlayer.left = 0;
				}
				else
				{
					rectPlayer.left += playerSizeX;
				}

				playerSprite.setTextureRect(rectPlayer);
				clock.restart();
			}
			playerSprite.setTextureRect(rectPlayer);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			rectPlayer.top = playerSizeY * 3;
			playerSprite.move(0.f, -playerMoveSpeedY);
			if (clock.getElapsedTime().asSeconds() > 0.3f)
			{
				if (rectPlayer.left == (playerSizeX * 3))
				{
					rectPlayer.left = 0;
				}
				else
				{
					rectPlayer.left += playerSizeX;
				}

				playerSprite.setTextureRect(rectPlayer);
				clock.restart();
			}
			playerSprite.setTextureRect(rectPlayer);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			rectPlayer.top = 0;
			playerSprite.move(0.f, playerMoveSpeedY);
			if (clock.getElapsedTime().asSeconds() > 0.3f)
			{
				if (rectPlayer.left == (playerSizeX * 3))
				{
					rectPlayer.left = 0;
				}
				else
				{
					rectPlayer.left += playerSizeX;
				}
				clock.restart();
			}
			playerSprite.setTextureRect(rectPlayer);
		}

		playerAnimationFrame++;

		if (playerAnimationFrame >= 4) 
		{
			playerAnimationFrame = 0;
		}

		// Bat Update

		if (batSprite.getPosition().y < playerSprite.getPosition().y)
		{
			batSprite.move(0.f, batMoveSpeedY);
			batSprite.setTextureRect(sf::IntRect(batSizeX * batAnimationFrame, 0, batSizeX, batSizeY));
		}
		else
		{
			batSprite.move(0.f, -batMoveSpeedY);
			batSprite.setTextureRect(sf::IntRect(batSizeX * batAnimationFrame, batSizeY * 3, batSizeX, batSizeY));
		}

		if (batSprite.getPosition().x < playerSprite.getPosition().x)
		{
			batSprite.move(batMoveSpeedX, 0.f);
			batSprite.setTextureRect(sf::IntRect(batSizeX * batAnimationFrame, batSizeY * 2, batSizeX, batSizeY));
		}
		else
		{
			batSprite.move(-batMoveSpeedX, 0.f);
			batSprite.setTextureRect(sf::IntRect(batSizeX * batAnimationFrame, batSizeY * 1, batSizeX, batSizeY));
		}

		// Collision
		if (collision.getGlobalBounds().intersects(playerSprite.getGlobalBounds())) 
		{
			playerSprite.setPosition(playerSpawnPoint);
		}

		batAnimationFrame++;

		if (batAnimationFrame >= 3)
		{
			batAnimationFrame = 0;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		window.display();
	}
	return 0;
}