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

	// Heart1
	sf::Texture heartTexture;
	if (!heartTexture.loadFromFile("image/HealthBar.png"))
	{
		std::cout << "Heart Load failed" << std::endl;
	}

	// Heart Sprite
	int heartSizeX = heartTexture.getSize().x / 3;
	int heartSizeY = heartTexture.getSize().y;

	// Heart1
	sf::IntRect rectHeart1(0, 0, heartSizeX, heartSizeY);
	sf::Sprite heartSprite1(heartTexture, rectHeart1);
	heartSprite1.setTexture(heartTexture);
	heartSprite1.setScale(0.1f, 0.1f);

	// Heart1 Position
	sf::Vector2f heartPos1 = { 20.f, 20.f };
	heartSprite1.setPosition(heartPos1);

	// Heart2
	sf::IntRect rectHeart2(0, 0, heartSizeX, heartSizeY);
	sf::Sprite heartSprite2(heartTexture, rectHeart2);
	heartSprite2.setTexture(heartTexture);
	heartSprite2.setScale(0.1f, 0.1f);

	// Heart2 Position
	sf::Vector2f heartPos2 = { 40.f, 20.f };
	heartSprite2.setPosition(heartPos2);

	// Heart3
	sf::IntRect rectHeart3(0, 0, heartSizeX, heartSizeY);
	sf::Sprite heartSprite3(heartTexture, rectHeart3);
	heartSprite3.setTexture(heartTexture);
	heartSprite3.setScale(0.1f, 0.1f);

	// Heart3 Position
	sf::Vector2f heartPos3 = { 60.f, 20.f };
	heartSprite3.setPosition(heartPos3);

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
	sf::Vector2f playerSpawnPoint = { 100.f, 100.f };
	playerSprite.setPosition(playerSpawnPoint);

	// Player Animaton
	int playerAnimationFrame = 0;
	sf::Clock playerClock;

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

		window.draw(playerSprite);
		window.draw(batSprite);
		window.draw(heartSprite1);
		window.draw(heartSprite2);
		window.draw(heartSprite3);

		// Player Update
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			rectPlayer.top = playerSizeY * 2;
			playerSprite.move(playerMoveSpeedX, 0.f);
			if (playerClock.getElapsedTime().asSeconds() > 0.3f)
			{
				if (rectPlayer.left == (playerSizeX * 3))
				{
					rectPlayer.left = 0;
				}
				else
				{
					rectPlayer.left += playerSizeX;
				}
				playerClock.restart();
			}
			playerSprite.setTextureRect(rectPlayer);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			rectPlayer.top = playerSizeY;
			playerSprite.move(-playerMoveSpeedX, 0.f);
			if (playerClock.getElapsedTime().asSeconds() > 0.3f)
			{
				if (rectPlayer.left == (playerSizeX * 3))
				{
					rectPlayer.left = 0;
				}
				else
				{
					rectPlayer.left += playerSizeX;
				}
				playerClock.restart();
			}
			playerSprite.setTextureRect(rectPlayer);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			rectPlayer.top = playerSizeY * 3;
			playerSprite.move(0.f, -playerMoveSpeedY);
			if (playerClock.getElapsedTime().asSeconds() > 0.3f)
			{
				if (rectPlayer.left == (playerSizeX * 3))
				{
					rectPlayer.left = 0;
				}
				else
				{
					rectPlayer.left += playerSizeX;
				}
				playerClock.restart();
			}
			playerSprite.setTextureRect(rectPlayer);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			rectPlayer.top = 0;
			playerSprite.move(0.f, playerMoveSpeedY);
			if (playerClock.getElapsedTime().asSeconds() > 0.3f)
			{
				if (rectPlayer.left == (playerSizeX * 3))
				{
					rectPlayer.left = 0;
				}
				else
				{
					rectPlayer.left += playerSizeX;
				}
				playerClock.restart();
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

		batAnimationFrame++;

		if (batAnimationFrame >= 3)
		{
			batAnimationFrame = 0;
		}

		// Collision
		if (batSprite.getGlobalBounds().intersects(playerSprite.getGlobalBounds()))
		{
			if (rectHeart3.left == 0)
			{
				rectHeart3.left = (heartSizeX * 2);
				heartSprite3.setTextureRect(rectHeart3);
			}
			else
			{
				if (rectHeart2.left == 0)
				{
					rectHeart2.left = (heartSizeX * 2);
					heartSprite2.setTextureRect(rectHeart2);
				}
				else
				{
					if (rectHeart1.left == 0)
					{
						rectHeart1.left = (heartSizeX * 2);
						heartSprite1.setTextureRect(rectHeart1);
					}
					if (rectHeart1.left != 0)
					{
						window.close();
					}
				}
			}
		}

		// End Program
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		window.display();
	}
	return 0;
}