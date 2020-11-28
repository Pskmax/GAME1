#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cmath>

//SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{

	// Render Window
	sf::RenderWindow window(sf::VideoMode(1080, 720), "REVERSE!");
	sf::Event event;
	window.setFramerateLimit(120);
	int STAGE = 0;

	// Sound
	sf::SoundBuffer epicBossFight;
	if (!epicBossFight.loadFromFile("sound/Orchestral_Battle_Theme_1.ogg"));
	sf::Sound epicBossFightBG;
	epicBossFightBG.setBuffer(epicBossFight);
	epicBossFightBG.setVolume(1);
	epicBossFightBG.play();
	epicBossFightBG.setLoop(true);

	// Font
	sf::Font font;

	// Score

	// Mouse
	sf::Mouse mouse;

	// Game Over
	// Win
	sf::Texture winTexture;
	if (!winTexture.loadFromFile("image/Victory.png"))
	{
		std::cout << "Victory Load failed" << std::endl;
	}
	sf::Sprite winSprite(winTexture);
	winSprite.setScale(0.6f, 0.6f);
	winSprite.setPosition(289.5f, 157.2f);

	// Lose
	sf::Texture gameOverTexture;
	if (!gameOverTexture.loadFromFile("image/GameOver.png"))
	{
		std::cout << "Game Over Load failed" << std::endl;
	}
	sf::Sprite gameOverSprite(gameOverTexture);
	gameOverSprite.setScale(0.6f, 0.6f);
	gameOverSprite.setPosition(289.5f, 157.2f);

	// Boss Map and Sprite
	sf::Texture bossmapTexture;
	if (!bossmapTexture.loadFromFile("image/Bossmap.jpeg"))
	{
		std::cout << "Boss map Load failed" << std::endl;
	}

	int bossmapSizeX = bossmapTexture.getSize().x;
	int bossmapSizeY = bossmapTexture.getSize().y;

	sf::IntRect rectBossmap(0, 0, bossmapSizeX, bossmapSizeY);
	sf::Sprite bossmapSprite(bossmapTexture, rectBossmap);
	bossmapSprite.setTexture(bossmapTexture);
	bossmapSprite.setScale(1.0843f, 1.030f);
	bossmapSprite.setPosition(0.f, 0.f);
	// 1
	sf::RectangleShape rectShape1;
	rectShape1.setSize(sf::Vector2f(1.f, 104.f));
	rectShape1.setPosition(424.f, 52.f);
	// 2
	sf::RectangleShape rectShape2;
	rectShape2.setSize(sf::Vector2f(265.f, 1.f));
	rectShape2.setPosition(159.f, 155.f);
	// 3
	sf::RectangleShape rectShape3;
	rectShape3.setSize(sf::Vector2f(1.f, 107.f));
	rectShape3.setPosition(159.f, 155.f);
	// 4
	sf::RectangleShape rectShape4;
	rectShape4.setSize(sf::Vector2f(106.f, 1.f));
	rectShape4.setPosition(159.f, 260.f);
	// 5
	sf::RectangleShape rectShape5;
	rectShape5.setSize(sf::Vector2f(1.f, 48.f));
	rectShape5.setPosition(265.f, 258.f);
	// 6
	sf::RectangleShape rectShape6;
	rectShape6.setSize(sf::Vector2f(1.f, 53.f));
	rectShape6.setPosition(265.f, 411.f);
	// 7
	sf::RectangleShape rectShape7;
	rectShape7.setSize(sf::Vector2f(108.f, 1.f));
	rectShape7.setPosition(157.f, 464.f);
	// 8
	sf::RectangleShape rectShape8;
	rectShape8.setSize(sf::Vector2f(1.f, 105.f));
	rectShape8.setPosition(157.f, 464.f);
	// 9
	sf::RectangleShape rectShape9;
	rectShape9.setSize(sf::Vector2f(267.f, 1.f));
	rectShape9.setPosition(157.f, 564.f);
	// 10
	sf::RectangleShape rectShape10;
	rectShape10.setSize(sf::Vector2f(1.f, 104.f));
	rectShape10.setPosition(424.f, 564.f);

	// STAGE 0
	sf::Texture stage0;
	if (!stage0.loadFromFile("image/dungeonMap.png"));
	int stage0SizeX = 800;
	int stage0SizeY = 600;
	sf::IntRect rectStage0(0, 0, stage0SizeX, stage0SizeY);
	sf::Sprite stage0Sprite(stage0, rectStage0);
	stage0Sprite.setScale(1.35f, 1.19f);
	stage0Sprite.setPosition(0.f, 0.f);
	// Player bar and Sprite
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

	// Monster Heart Sprite
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

	// Monster batHealth bar
	int batHealth = 3;
	int dragonHealth = 0; // MaxHP = 280
	
	sf::Clock batCollision;
	bool batBool = 0;
	bool dragonBool = 0;

	// Player Sprite
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

	sf::Vector2f playerSpawnPoint = { 100.f, 100.f };
	playerSprite.setPosition(playerSpawnPoint);

	// Player Animaton
	float playerMoveSpeedX = 1.5f;
	float playerMoveSpeedY = 1.5f;

	int playerAnimationFrame = 0;
	sf::Clock playerClock;

	// Sword Sprite
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

	sf::Vector2f swordSpawnPoint = { 150.f, 100.f };
	swordSprite.setPosition(swordSpawnPoint);

	// Sword animation
	int swordAnimationFrame = 0;
	sf::Clock swordClock;
	float keyPressed = 0;
	int dragonCount = 0;

	// Dragon Sprite (BOSS)
	sf::Texture dragonTexture;
	if (!dragonTexture.loadFromFile("image/Dragonboss.png"))
	{
		std::cout << "Dragon Boss Load failed" << std::endl;
	}

	int dragonSizeX = dragonTexture.getSize().x;
	int dragonSizeY = dragonTexture.getSize().y;

	sf::IntRect rectDragon(0, 0, dragonSizeX, dragonSizeY);
	sf::Sprite dragonSprite(dragonTexture, rectDragon);
	dragonSprite.setTexture(dragonTexture);
	dragonSprite.setScale(0.5f, 0.6f);

	sf::Vector2f dragonSpawnpoint = { 750.f,200.f };
	dragonSprite.setPosition(dragonSpawnpoint);
	float a = 200;
	sf::Clock dragonClock;
	float dragonPosY = 0.0;

	// Dragon Bossbar Texture and Sprite
	sf::Texture dragonBarTexture;
	if (!dragonBarTexture.loadFromFile("image/DragonBossbar.png"))
	{
		std::cout << "Dragon Bossbar Load Failed" << std::endl;
	}

	int dragonBarSizeX = dragonBarTexture.getSize().x;
	int dragonBarSizeY = dragonBarTexture.getSize().y;

	sf::IntRect rectDragonBar(0, 0, dragonBarSizeX, dragonBarSizeX);
	sf::Sprite dragonBarSprite(dragonBarTexture, rectDragonBar);
	dragonBarSprite.setTexture(dragonBarTexture);
	dragonBarSprite.setScale(0.5f, 0.5f); 
	dragonBarSprite.setPosition(700.f, 600.f);

	// Remove Dragon Healthbar
	sf::Texture dragonBarRTexture;
	if (!dragonBarRTexture.loadFromFile("image/remove.png"))
	{
		std::cout << "Dragon Remove Bar Load failed" << std::endl;
	}
	int dragonBarRSizeX = dragonBarRTexture.getSize().x;
	int dragonBarRSizeY = dragonBarRTexture.getSize().y;
	sf::IntRect rectDragonR(0, 0, dragonBarRSizeX, dragonBarRSizeY);
	sf::Sprite dragonBarRSprite(dragonBarRTexture, rectDragonR);
	dragonBarRSprite.setTexture(dragonBarRTexture);
	dragonBarRSprite.setScale(0.002f, 0.05f);

	// Dragon ChargeBeam and LaserBeam
	sf::Texture solarBeamTexture;
	if (!solarBeamTexture.loadFromFile("image/SolarBeam.png"))
	{
		std::cout << "Solar Beam Load failed" << std::endl;
	}
	int chargeBSizeX = 35;
	int chargeBSizeY = 30;
	int laserSizeX = 200;
	int laserSizeY = 27;

	sf::IntRect rectChargeB(250, 105, chargeBSizeX, chargeBSizeY);
	sf::IntRect rectLaser(7, 160, laserSizeX, laserSizeY);
	sf::Sprite chargeBeamSprite(solarBeamTexture, rectChargeB);
	sf::Sprite laserSprite(solarBeamTexture, rectLaser);
	chargeBeamSprite.setPosition(780.f, 250.f);
	chargeBeamSprite.setScale(1.5f, 1.5f);

	laserSprite.setScale(5.f, 1.5f);
	laserSprite.setPosition(835.f, 277.f);
	laserSprite.rotate(120);
	sf::Clock laserClock;

	bool laserPBool = 0;

	// Bat Sprite
	sf::Texture batTexture;
	if (!batTexture.loadFromFile("image/Monsters.png"))
	{
		std::cout << "Player Load failed" << std::endl;
	}

	int batSizeX = batTexture.getSize().x / 12;
	int batSizeY = batTexture.getSize().y / 8;

	sf::IntRect rectBat(batSizeX, 0, batSizeX, batSizeY);
	sf::Sprite batSprite(batTexture, rectBat);
	batSprite.setTexture(batTexture);
	batSprite.setScale(1.f, 1.f);

	sf::Vector2f batSpawnPoint = { 500.f, 500.f };
	batSprite.setPosition(batSpawnPoint);

	float batMoveSpeedX = .5f;
	float batMoveSpeedY = .5f;

	int batAnimationFrame = 0;
	sf::Clock batClock;

	// Items
	// Item Box Sprite
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

	sf::Vector2f itemBoxSpawnpoint = { 350.f, 600.f };
	itemBoxSprite.setPosition(itemBoxSpawnpoint);

	// Shield Sprite
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

	// Stopwatch Sprite
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

	// Random
	sf::Clock random;

	// While Game is Running
	while (window.isOpen())
	{
		//std::cout << mouse.getPosition(window).x;
		//std::cout << "\t" << mouse.getPosition(window).y << std::endl;
		// Random
		srand(time(NULL));
		int randomEffects = (rand() % 10) + 1;
		/*
			2 of 10 : Stopwatch
			4 of 10 : Shield
			4 of 10 : Potion
		*/
		/*if (random.getElapsedTime().asSeconds() > 1.f)
		{
			std::cout << "Random Number : " << randomEffects << std::endl;
			random.restart();
		}*/

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
				window.close();
		}
		window.clear();
		if (STAGE == 5)
		{
			window.draw(stage0Sprite);
			window.draw(playerSprite);
		}

		if (STAGE == 0)
		{
			window.draw(bossmapSprite);
			window.draw(dragonSprite);
			window.draw(itemBoxSprite);
			window.draw(playerSprite);
			window.draw(batSprite);
			window.draw(dragonBarSprite);
			window.draw(laserSprite);
			window.draw(chargeBeamSprite);
			window.draw(rectShape1);
			window.draw(rectShape2);
			window.draw(rectShape3);
			window.draw(rectShape4);
			window.draw(rectShape5);
			window.draw(rectShape6);
			window.draw(rectShape7);
			window.draw(rectShape8);
			window.draw(rectShape9);
			window.draw(rectShape10);

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
			if (stopwatch == 1)
			{
				window.draw(timeStopSprite);
				window.draw(stopwatchSprite);
			}

			// Health Bar
			// Player Health Bar
			for (int i = 0; i < healthStatus; i++)
			{
				if (i < 4)
				{
					sf::IntRect rectHealthBar1(healthBarSizeX1 * (2 * i), 0, healthBarSizeX1, healthBarSizeY1);
					sf::Sprite healthBarSprite1(healthBarTexture1, rectHealthBar1);
					healthBarSprite1.setTexture(healthBarTexture1);
					healthBarSprite1.setScale(0.2f, 0.2f);
					healthBarSprite1.setPosition(healthBarPosX - (2 * i), healthBarPosY);
					window.draw(healthBarSprite1);
				}
			}

			// Bat Health Bar
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

			// Dragon Health Bar
			for (float i = 0; i < dragonHealth; i++)
			{
				if (i <= 280)
				{
					dragonBarRSprite.setPosition(1042.5f - i, 668.f);
					window.draw(dragonBarRSprite);
				}
			}

			// Shield
			if (shield == 1)
			{
				shieldSprite.setPosition(playerSprite.getPosition().x - ((shieldSizeX * 0.15f) / 2) + (playerSizeX / 2), playerSprite.getPosition().y - ((shieldSizeY * 0.15f) / 2) + (playerSizeY / 2));
				window.draw(shieldSprite);
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
			
			// Dragon Update
			// Dragon Animation
			if (dragonClock.getElapsedTime().asSeconds() > 0.08f)
			{
				if (dragonCount < 20)
				{
					if (dragonCount < 10)
					{
						dragonPosY += 1.0;
						dragonSprite.setPosition(750.f, 200.f + dragonPosY);
					}
					if (dragonCount > 10)
					{
						dragonPosY -= 1.0;
						dragonSprite.setPosition(750.f, 200.f + dragonPosY);
					}
				}
				if (dragonCount == 20) dragonCount = 0;
				dragonCount++;
				dragonClock.restart();
			}
			// Dragon Laser
			if (laserClock.getElapsedTime().asSeconds() > 0.02f)
			{
				if (laserSprite.getRotation() < 180)
				{
					laserSprite.setRotation(laserSprite.getRotation() + 0.6);
					laserSprite.setPosition(laserSprite.getPosition().x + (-0.35f), laserSprite.getPosition().y + 0.21f);
				}
				if (laserSprite.getRotation() >= 180 && laserSprite.getRotation() < 210)
				{
					laserSprite.setRotation(laserSprite.getRotation() + 0.6);
					laserSprite.setPosition(laserSprite.getPosition().x, laserSprite.getPosition().y);
				}
				laserSprite.setPosition(laserSprite.getPosition().x, laserSprite.getPosition().y);
				laserSprite.setRotation(laserSprite.getRotation());
				laserClock.restart();
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

			// Alway Check Collision
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
					if (healthStatus <= 3) healthStatus++;
					else healthStatus = healthStatus;
				}
			}

			// Bat and Shield
			if (shieldSprite.getGlobalBounds().intersects(batSprite.getGlobalBounds()))
			{
				shieldSprite.setPosition(NULL - 1000, NULL - 1000);
				batSprite.setPosition(batSpawnPoint);
				if (batHealth == 1)
				{
					batSprite.setPosition(NULL - 1000, NULL - 1000);
				}
				else
				{
					batHealth--;
				}
				shield = 0;
			}

			// Bat and Laser
			if (laserSprite.getGlobalBounds().intersects(batSprite.getGlobalBounds()))
			{
				if (batHealth == 1)
				{
					batSprite.setPosition(NULL - 1000, NULL - 1000);
				}
				else
				{
					batHealth--;
				}
			}

			// Sword and Dragon (BOSS)
			if (!swordSprite.getGlobalBounds().intersects(dragonSprite.getGlobalBounds()))
			{
				dragonBool = 1;
			}
			if (swordSprite.getGlobalBounds().intersects(dragonSprite.getGlobalBounds()) && dragonBool == 1)
			{
				dragonHealth += 5;
				dragonBool = 0;
			}

			// Player and Laser
			if (!laserSprite.getGlobalBounds().intersects(playerSprite.getGlobalBounds()))
			{
				laserPBool = 1;
			}
			if (laserSprite.getGlobalBounds().intersects(playerSprite.getGlobalBounds()) && laserPBool == 1)
			{
				healthStatus-=2;
				laserPBool = 0;
			}
		}
		// ALWAY RUN
		// Player Update
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && playerSprite.getPosition().y > 20 && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && playerSprite.getPosition().y < (655 - playerSizeY) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W))
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && playerSprite.getPosition().x < (1020 - playerSizeX) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && playerSprite.getPosition().x > 40 && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
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

		// End Game
		// win
	
		// Lose
		if (healthStatus == 0) STAGE = 6;

		if (STAGE == 6)
		{
			window.clear();
			window.draw(gameOverSprite);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		window.display();
	}
	return 0;
}