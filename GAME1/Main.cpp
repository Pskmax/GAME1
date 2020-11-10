#include<iostream>
#include<vector>
#include<ctime>

//SFML
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:

	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
	{
		// load the tileset texture
		if (!m_tileset.loadFromFile(tileset))
			return false;

		// resize the vertex array to fit the level size
		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(width * height * 4);

		// populate the vertex array, with one quad per tile
		for (unsigned int i = 0; i < width; ++i)
			for (unsigned int j = 0; j < height; ++j)
			{
				// get the current tile number
				int tileNumber = tiles[i + j * width];

				// find its position in the tileset texture
				int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
				int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

				// get a pointer to the current tile's quad
				sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

				// define its 4 corners
				quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
				quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
				quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
				quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

				// define its 4 texture coordinates
				quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
				quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
				quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
				quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
			}

		return true;
	}

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// apply the transform
		states.transform *= getTransform();

		// apply the tileset texture
		states.texture = &m_tileset;

		// draw the vertex array
		target.draw(m_vertices, states);
	}

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};

int main()
{
	// Random
	srand(time(NULL));
	int randomEffects = (rand() % 10) + 1;
		/*
			2 of 10 : Stopwatch
			4 of 10 : Shield
			4 of 10 : Potion
		*/
	std::cout << randomEffects;

	// Render Window
	sf::RenderWindow window(sf::VideoMode(1080, 720), "REVERSE!");
	sf::Event event;
	window.setFramerateLimit(120);

	// Game Over
	sf::Texture gameOverTexture;
	if (!gameOverTexture.loadFromFile("image/GameOver.png"))
	{
		std::cout << "Game Over Load failed" << std::endl;
	}
	sf::Sprite gameOverSprite(gameOverTexture);
	gameOverSprite.setScale(0.6f, 0.6f);

	// Game Over Position
	gameOverSprite.setPosition(289.5f, 157.2f);

	//Tile Map
	const int level[] =
	{
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
	};

	// create the tilemap from the level definition
	TileMap map;
	if (!map.load("image/tileset.png", sf::Vector2u(32, 32), level, 34, 23))
		return -1;

	// Player batHealth bar and Sprite
	// 1
	sf::Texture healthBarTexture1;
	if (!healthBarTexture1.loadFromFile("image/PlayerHealthBar1.png"))
	{
		std::cout << "healthBar Load failed" << std::endl;
	}

	int healthBarSizeX1 = healthBarTexture1.getSize().x / 8;
	int healthBarSizeY1 = healthBarTexture1.getSize().y;

	// Player batHealth bar Position
	float healthBarPosX = 20.f;
	float healthBarPosY = 20.f;

	// Player batHealth bar
	int healthStatus = 4;

	// Monster Heart and Sprite
	sf::Texture heartTexture;
	if (!heartTexture.loadFromFile("image/MonsterHealthBar.png"))
	{
		std::cout << "Heart Load failed" << std::endl;
	}

	int heartSizeX = heartTexture.getSize().x / 3;
	int heartSizeY = heartTexture.getSize().y;

	// Monster Heart
	sf::Sprite heartSprite(heartTexture);
	heartSprite.setTexture(heartTexture);
	heartSprite.setScale(0.1f, 0.1f);

	// Monster Heart Position
	float heartPosX;
	float heartPosY;

	// Monster batHealth bar
	int batHealth = 3;
	
	//Bat batHealth
	sf::Clock batCollision;
	bool batBool = 0;

	// Player Texture and Sprite
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("image/Player.png"))
	{
		std::cout << "Player Load failed" << std::endl;
	}

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
	float playerMoveSpeedX = 1.5f;
	float playerMoveSpeedY = 1.5f;

	int playerAnimationFrame = 0;
	sf::Clock playerClock;

	// Sword Texture and Sprite
	sf::Texture swordTexture;
	if (!swordTexture.loadFromFile("image/SwordSlash.png"))
	{
		std::cout << "Player Load failed" << std::endl;
	}
	// Animation 1 -> x = 109 y = 80
	// Animation 2 -> x = 179 y = 80
	// Animation 3 -> x = 249 y = 80
	// Size x = 69 y = 40
	sf::IntRect rectSword(109, 80, 69, 40);
	sf::Sprite swordSprite(swordTexture, rectSword);
	swordSprite.setTexture(swordTexture);
	swordSprite.setScale(0.8f, 1.2f);

	// Sword Position
	sf::Vector2f swordSpawnPoint = { 150.f, 100.f };
	swordSprite.setPosition(swordSpawnPoint);

	// Sword animation
	int swordAnimationFrame = 0;
	sf::Clock swordClock;
	float keyPressed = 0;

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
	float batMoveSpeedX = .5f;
	float batMoveSpeedY = .5f;

	int batAnimationFrame = 0;
	sf::Clock batClock;

	// Items
	// Item Box Texture
	sf::Texture itemBoxTexture;
	if (!itemBoxTexture.loadFromFile("image/ItemBoxR.png"))
	{
		std::cout << "Item Box Load failed" << std::endl;
	}
	int itemBoxSizeX = itemBoxTexture.getSize().x;
	int itemBoxSizeY = itemBoxTexture.getSize().y;

	sf::IntRect rectItemBox(0, 0, itemBoxSizeX, itemBoxSizeY);
	sf::Sprite itemBoxSprite(itemBoxTexture, rectItemBox);
	itemBoxSprite.setTexture(itemBoxTexture);
	itemBoxSprite.setScale(0.1f, 0.1f);

	//Item Box Spawnpoint
	sf::Vector2f itemBoxSpawnpoint = { 1000.f, 600.f };
	itemBoxSprite.setPosition(itemBoxSpawnpoint);

	// Shield Box Texture
	sf::Texture shieldTexture;
	if (!shieldTexture.loadFromFile("image/Shield.png"))
	{
		std::cout << "Shield Load failed" << std::endl;
	}
	int shieldSizeX = shieldTexture.getSize().x;
	int shieldSizeY = shieldTexture.getSize().y;

	sf::IntRect rectShield(0, 0, shieldSizeX, shieldSizeY);
	sf::Sprite shieldSprite(shieldTexture, rectShield);
	shieldSprite.setTexture(shieldTexture);
	shieldSprite.setScale(0.15f, 0.15f);

	//Shield status
	bool shield = 0;

	// Stopwatch
	sf::Texture stopwatchTexture;
	if (!stopwatchTexture.loadFromFile("image/Stopwatch.png"))
	{
		std::cout << "Shield Load failed" << std::endl;
	}
	int stopwatchSizeX = stopwatchTexture.getSize().x;
	int stopwatchSizeY = stopwatchTexture.getSize().y;

	sf::IntRect rectStopwatch(0, 0, stopwatchSizeX, stopwatchSizeY);
	sf::Sprite stopwatchSprite(stopwatchTexture);
	stopwatchSprite.setScale(0.2f, 0.2f);

	// Stopwatch Position
	stopwatchSprite.setPosition(970.f, 10.f);

	// Stopwatch status
	bool stopwatch = 0;

	// Time Stop BG
	sf::Texture timeStopBGTexture;
	if (!timeStopBGTexture.loadFromFile("image/TimeStopBG.png"))
	{
		std::cout << "Time Stop BG Load failed" << std::endl;
	}

	sf::IntRect rectTimeStopBG(0, 0, 1080, 720);
	sf::Sprite timeStopSprite(timeStopBGTexture);

	// While Game is Running
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
				window.close();
		}
		window.clear();

		if (healthStatus > 0)
		{
			window.draw(map);
			window.draw(itemBoxSprite);
			window.draw(playerSprite);
			window.draw(batSprite);

			// Player Update
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && playerSprite.getPosition().y > 0 && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && playerSprite.getPosition().y < (705 - playerSizeY) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W))
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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && playerSprite.getPosition().x < (1080 - playerSizeX) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && playerSprite.getPosition().x > 0 && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
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

			playerAnimationFrame++;

			if (playerAnimationFrame >= 4)
			{
				playerAnimationFrame = 0;
			}

			// Player Health Bar
			for (int i = 0; i < healthStatus; i++)
			{
				sf::IntRect rectHealthBar1(healthBarSizeX1 * (2 * i), 0, healthBarSizeX1, healthBarSizeY1);
				sf::Sprite healthBarSprite1(healthBarTexture1, rectHealthBar1);
				healthBarSprite1.setTexture(healthBarTexture1);
				healthBarSprite1.setScale(0.2f, 0.2f);
				healthBarSprite1.setPosition(healthBarPosX - (2 * i), healthBarPosY);
				window.draw(healthBarSprite1);
			}

			// Sword Update
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				keyPressed = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && keyPressed == 1)
			{
				swordAnimationFrame = 20;
				keyPressed = 0;
			}
			if (swordAnimationFrame > 0)
			{
				if (rectPlayer.left <= (playerSizeX * 3))
				{
					// Right
					if (rectPlayer.top == (playerSizeY * 2))
					{
						swordSprite.setPosition(playerSprite.getPosition().x + 30.f, playerSprite.getPosition().y);
						swordSprite.setTextureRect(rectSword);
						window.draw(swordSprite);
						swordSprite.setPosition(playerSprite.getPosition().x + 50.f, playerSprite.getPosition().y);
					}
					// Left
					if (rectPlayer.top == (playerSizeY))
					{
						swordSprite.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y);
						swordSprite.setScale(-0.8f, 1.2f);
						swordSprite.setTextureRect(rectSword);
						window.draw(swordSprite);
						swordSprite.setPosition(playerSprite.getPosition().x - 50.f, playerSprite.getPosition().y);
					}
					// Top
					if (rectPlayer.top == (playerSizeY * 3))
					{
						swordSprite.setPosition(playerSprite.getPosition().x - 5.f, playerSprite.getPosition().y);
						swordSprite.rotate(-90.f);
						swordSprite.setTextureRect(rectSword);
						window.draw(swordSprite);
						swordSprite.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y - 50.f);
					}
					// Bottom
					if (rectPlayer.top == 0)
					{
						swordSprite.setPosition(playerSprite.getPosition().x - 5.f, playerSprite.getPosition().y + 40.f);
						swordSprite.rotate(-90.f);
						swordSprite.setScale(-0.8f, 1.2f);
						swordSprite.setTextureRect(rectSword);
						window.draw(swordSprite);
						swordSprite.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y + 50.f);
					}

				}
				swordSprite.setRotation(0.f);
				swordSprite.setScale(0.8f, 1.2f);
				swordAnimationFrame--;
			}
			else
			{
				swordSprite.setPosition(NULL - 1000, NULL - 1000);
			}

			// Bat Update
			if (stopwatch == 0)
			{
				if (batSprite.getPosition().y < playerSprite.getPosition().y)
				{
					rectBat.top = 0;
					batSprite.move(0.f, batMoveSpeedY);
					if (batClock.getElapsedTime().asSeconds() > 0.3f)
					{
						if (rectBat.left == (batSizeX * 2))
						{
							rectBat.left = 0;
						}
						else
						{
							rectBat.left += batSizeX;
						}
						batClock.restart();
					}
					batSprite.setTextureRect(rectBat);
				}
				else
				{
					rectBat.top = batSizeY * 3;
					batSprite.move(0.f, -batMoveSpeedY);
					if (batClock.getElapsedTime().asSeconds() > 0.3f)
					{
						if (rectBat.left == (batSizeX * 2))
						{
							rectBat.left = 0;
						}
						else
						{
							rectBat.left += batSizeX;
						}
						batClock.restart();
					}
					batSprite.setTextureRect(rectBat);
				}

				if (batSprite.getPosition().x < playerSprite.getPosition().x)
				{
					rectBat.top = batSizeY * 2;
					batSprite.move(batMoveSpeedX, 0.f);
					if (batClock.getElapsedTime().asSeconds() > 0.3f)
					{
						if (rectBat.left == (batSizeX * 2))
						{
							rectBat.left = 0;
						}
						else
						{
							rectBat.left += batSizeX;
						}
						batClock.restart();
					}
					batSprite.setTextureRect(rectBat);
				}
				else
				{
					rectBat.top = batSizeY;
					batSprite.move(-batMoveSpeedX, 0.f);
					if (batClock.getElapsedTime().asSeconds() > 0.3f)
					{
						if (rectBat.left == (batSizeX * 2))
						{
							rectBat.left = 0;
						}
						else
						{
							rectBat.left += batSizeX;
						}
						batClock.restart();
					}
					batSprite.setTextureRect(rectBat);
				}

				batAnimationFrame++;

				if (batAnimationFrame >= 3)
				{
					batAnimationFrame = 0;
				}

				//Collision
				// Player and Bat
				if (batSprite.getGlobalBounds().intersects(playerSprite.getGlobalBounds()))
				{
					playerSprite.setPosition(playerSpawnPoint);
					batSprite.setPosition(batSpawnPoint);
					healthStatus--;
				}
			}

			if (stopwatch == 1)
			{
				window.draw(timeStopSprite);
				window.draw(stopwatchSprite);
				if (batSprite.getPosition().y < playerSprite.getPosition().y)
				{
					rectBat.top = 0;
					batSprite.move(0.f, 0.f);
					if (batClock.getElapsedTime().asSeconds() > 0.3f)
					{
						if (rectBat.left == (batSizeX * 2))
						{
							rectBat.left = 0;
						}
						else
						{
							rectBat.left += batSizeX;
						}
						batClock.restart();
					}
					batSprite.setTextureRect(rectBat);
				}
				else
				{
					rectBat.top = batSizeY * 3;
					batSprite.move(0.f, 0.f);
					if (batClock.getElapsedTime().asSeconds() > 0.3f)
					{
						if (rectBat.left == (batSizeX * 2))
						{
							rectBat.left = 0;
						}
						else
						{
							rectBat.left += batSizeX;
						}
						batClock.restart();
					}
					batSprite.setTextureRect(rectBat);
				}

				if (batSprite.getPosition().x < playerSprite.getPosition().x)
				{
					rectBat.top = batSizeY * 2;
					batSprite.move(0.f, 0.f);
					if (batClock.getElapsedTime().asSeconds() > 0.3f)
					{
						if (rectBat.left == (batSizeX * 2))
						{
							rectBat.left = 0;
						}
						else
						{
							rectBat.left += batSizeX;
						}
						batClock.restart();
					}
					batSprite.setTextureRect(rectBat);
				}
				else
				{
					rectBat.top = batSizeY;
					batSprite.move(0.f, 0.f);
					if (batClock.getElapsedTime().asSeconds() > 0.3f)
					{
						if (rectBat.left == (batSizeX * 2))
						{
							rectBat.left = 0;
						}
						else
						{
							rectBat.left += batSizeX;
						}
						batClock.restart();
					}
					batSprite.setTextureRect(rectBat);
				}

				batAnimationFrame++;

				if (batAnimationFrame >= 3)
				{
					batAnimationFrame = 0;
				}
			}

			// Bat batHealth Bar
			for (int i = 0; i < 3; i++)
			{
				sf::IntRect rectHeart(heartSizeX * 2, 0, heartSizeX, heartSizeY);
				heartSprite.setPosition(batSprite.getPosition().x + (20.f * i), batSprite.getPosition().y - 20.f);
				heartSprite.setTextureRect(rectHeart);
				window.draw(heartSprite);
			}
			for (int i = 0; i < batHealth; i++)
			{
				sf::IntRect rectHeart(0, 0, heartSizeX, heartSizeY);
				heartSprite.setPosition(batSprite.getPosition().x + (20.f * i), batSprite.getPosition().y - 20.f);
				heartSprite.setTextureRect(rectHeart);
				window.draw(heartSprite);
			}

			//Shield
			if (shield == 1)
			{
				shieldSprite.setPosition(playerSprite.getPosition().x - ((shieldSizeX * 0.15f) / 2) + (playerSizeX / 2), playerSprite.getPosition().y - ((shieldSizeY * 0.15f) / 2) + (playerSizeY / 2));
				window.draw(shieldSprite);
			}

			// Collision
			// Sword and Bat
			if (!swordSprite.getGlobalBounds().intersects(batSprite.getGlobalBounds()))
				batBool = 1;
			if (swordSprite.getGlobalBounds().intersects(batSprite.getGlobalBounds()) && batBool == 1)
			{
				if (batHealth == 1)
				{
					batSprite.setPosition(NULL - 1000, NULL - 1000);
				}
				else
				{
					batHealth--;
				}
				batBool = 0;
				stopwatch = 0;
			}

			if (batSprite.getPosition().x == (NULL - 1000) && batSprite.getPosition().y == (NULL - 1000))
			{
				batMoveSpeedX = 0.f;
				batMoveSpeedY = 0.f;
			}

			// Collect Item collision
			if (playerSprite.getGlobalBounds().intersects(itemBoxSprite.getGlobalBounds()))
			{
				itemBoxSprite.setPosition(NULL - 1000, NULL - 1000);
				if (randomEffects == 1 || randomEffects == 2)
				{
					stopwatch = 1;
				}
				else if (randomEffects == 3 || randomEffects == 4 || randomEffects == 5 || randomEffects == 6)
				{
					shield = 1;
				}
				else if (randomEffects == 7 || randomEffects == 8 || randomEffects == 9 || randomEffects == 10)
				{
					healthStatus++;
				}
			}

			// Bat and Shield
			if (shieldSprite.getGlobalBounds().intersects(batSprite.getGlobalBounds()))
			{
				shieldSprite.setPosition(NULL - 1000, NULL - 1000);
				batSprite.setPosition(batSpawnPoint);
				shield = 0;
			}
		}

		if (healthStatus == 0)
		{
			window.clear();
			window.draw(gameOverSprite);
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