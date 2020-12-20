#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUMBER_OF_ITEMS 8
#define MAX2 2
#define MAX3 3

#include <ctime>
#include <math.h>
#include<stdio.h>
#include<utility>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>

using namespace std;
//SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
	const float PI = 3.14159265;
	int music = 0;
	int played = 0;
	float click = 0;
	bool collect = 0;
	bool swordBool = 0;
	bool shield = 0;
	bool stopwatch = 0;
	bool keyPressed = 0;
	bool bossBullet = 0;
	bool swordStatus = 0;
	bool weaponStatus = 0;
	int waveInt = 3;
	int beam = 0;
	int laserStatus = 3;
	int SWCD = 5;
	float immune = 0;
	float immuneBlink = 0;
	float batImmune = 0;
	float slimeImmune = 0;
	float dragonImmune = 0;
	float weaponSwap = 0;
	float sword0 = 0;
	int weaponsType = 0;

	int bulletNow = 0;

	int arrowNow = 0;

	int pBulletNow = 0;
	int pBulletStatus = 0;

	float timeC = 0;
	bool pause = 0;
	bool check1 = 0;
	bool check2 = 0;

	int gun = 0;
	int pBulletInt = 0;

	float scoreCalculateA = 0;
	float scoreCalculateB = 0;
	float scoreCalculateC = 0;
	float totalScore = 0;
	bool scoreCheck = 0;
	bool slimeS = 0;
	bool batS = 0;

	/* 
		STAGE0 = map1
		STAGE1 = map2
		STAGE2 = map3
		STAGE3 = Main Menu
		STAGE4 = Win
		STAGE5 = Lose
		STAGE6 = How To Play
		STAGE7 = High Score
	*/

	int STAGE = 3;

	// Render Window
	sf::RenderWindow window(sf::VideoMode(1080, 720), "REVERSE!");
	sf::Event event;
	window.setFramerateLimit(120);

	// Sound
	sf::SoundBuffer epicBossFight;
	sf::SoundBuffer victoryMusic;
	if (!epicBossFight.loadFromFile("sound/Orchestral_Battle_Theme_1.ogg"));
	if (!victoryMusic.loadFromFile("sound/Airship.ogg"));
	sf::Sound epicBossFightBG;
	sf::Sound victoryMusicBG;
	epicBossFightBG.setBuffer(epicBossFight);
	victoryMusicBG.setBuffer(victoryMusic);
	victoryMusicBG.setVolume(20);
	epicBossFightBG.setVolume(20);

	// Font
	sf::Font font;
	if (!font.loadFromFile("font/Roboto.ttf"));
	sf::Text timeCount;
	timeCount.setCharacterSize(35.f);
	timeCount.setFont(font);
	timeCount.setPosition(100.f, 670.f);
	timeCount.setFillColor(sf::Color::Green);
	sf::Clock timeClock;
	sf::Clock SWCDClock;

	sf::Text how[MAX_NUMBER_OF_ITEMS];
	sf::Text scoreNow[MAX3];

	// Time
	sf::Texture timeTexture;
	if (!timeTexture.loadFromFile("image/time.png"));
	sf::IntRect rectTime(0, 0, 360, 360);
	sf::Sprite timeSprite(timeTexture, rectTime);
	timeSprite.setTexture(timeTexture);
	timeSprite.setScale(0.13f, 0.13f);
	timeSprite.setPosition(40.f, 668.f);
	sf::Time deltaTime1;

	// Mouse
	sf::Mouse mouse;

	// Score
	float SCOREA = 0;
	float SCOREB = 0;
	float SCOREC = 0;
	bool scoreStatus = 0;
	bool scoreboardupdate = 0;
	bool cantype = 0;
	int playernamenow = 0;
	char playername[20];
	bool canbackspace = 0;
	float backspacetime = 0;
	sf::Text ClearTime;
	ClearTime.setCharacterSize(45);
	ClearTime.setFont(font);
	ClearTime.setPosition(300, 200);
	ClearTime.setString("Time : ");
	ClearTime.setFillColor(sf::Color::Blue);
	sf::Text CTime;
	CTime.setCharacterSize(45);
	CTime.setFont(font);
	CTime.setPosition(500, 200);
	CTime.setString("12345");
	CTime.setFillColor(sf::Color::Red);
	sf::Text EnterScore;
	EnterScore.setCharacterSize(45);
	EnterScore.setFont(font);
	EnterScore.setPosition(300, 275);
	EnterScore.setString("Score : ");
	EnterScore.setFillColor(sf::Color::Blue);
	sf::Text SCORENow;
	SCORENow.setCharacterSize(45);
	SCORENow.setFont(font);
	SCORENow.setFillColor(sf::Color::Red);
	SCORENow.setString("12345");
	SCORENow.setPosition(500, 275);
	sf::Text EnterName;
	EnterName.setCharacterSize(45);
	EnterName.setFont(font);
	EnterName.setPosition(300, 350);
	EnterName.setString("Name : ");
	EnterName.setFillColor(sf::Color::Blue);
	sf::Text name;
	name.setCharacterSize(45);
	name.setFont(font);
	name.setPosition(500, 350);
	name.setString("12345");
	name.setFillColor(sf::Color::Blue);
	sf::Text player1;
	player1.setCharacterSize(50);
	player1.setFont(font);
	player1.setFillColor(sf::Color::Black);
	player1.setString("Player");
	player1.setPosition(200, 130);
	sf::Text player2;
	player2.setCharacterSize(50);
	player2.setFont(font);
	player2.setFillColor(sf::Color::Black);
	player2.setString("Player");
	player2.setPosition(200, 250);
	sf::Text player3;
	player3.setCharacterSize(50);
	player3.setFont(font);
	player3.setFillColor(sf::Color::Black);
	player3.setString("Player");
	player3.setPosition(200, 370);
	sf::Text player4;
	player4.setCharacterSize(50);
	player4.setFont(font);
	player4.setFillColor(sf::Color::Black);
	player4.setString("Player");
	player4.setPosition(200, 490);
	sf::Text player5;
	player5.setCharacterSize(50);
	player5.setFont(font);
	player5.setFillColor(sf::Color::Black);
	player5.setString("Player");
	player5.setPosition(200, 610);
	sf::Text score1;
	score1.setCharacterSize(50);
	score1.setFont(font);
	score1.setFillColor(sf::Color::Red);
	score1.setString("12345");
	score1.setPosition(800, 130);
	sf::Text score2;
	score2.setCharacterSize(50);
	score2.setFont(font);
	score2.setFillColor(sf::Color::Red);
	score2.setString("12345");
	score2.setPosition(800, 250);
	sf::Text score3;
	score3.setCharacterSize(50);
	score3.setFont(font);
	score3.setFillColor(sf::Color::Red);
	score3.setString("12345");
	score3.setPosition(800, 370);
	sf::Text score4;
	score4.setCharacterSize(50);
	score4.setFont(font);
	score4.setFillColor(sf::Color::Red);
	score4.setString("12345");
	score4.setPosition(800, 490);
	sf::Text score5;
	score5.setCharacterSize(50);
	score5.setFont(font);
	score5.setFillColor(sf::Color::Red);
	score5.setString("12345");
	score5.setPosition(800, 610);
	//scoreboard
	sf::Text scoreboardText;
	scoreboardText.setCharacterSize(60);
	scoreboardText.setFont(font);
	scoreboardText.setFillColor(sf::Color::Blue);
	scoreboardText.setString("Leader Board");
	scoreboardText.setPosition(400, 10);
	sf::Text no1;
	no1.setCharacterSize(50);
	no1.setFont(font);
	no1.setFillColor(sf::Color::Black);
	no1.setString("1.");
	no1.setPosition(150, 130);
	sf::Text no2;
	no2.setCharacterSize(50);
	no2.setFont(font);
	no2.setFillColor(sf::Color::Black);
	no2.setString("2.");
	no2.setPosition(150, 250);
	sf::Text no3;
	no3.setCharacterSize(50);
	no3.setFont(font);
	no3.setFillColor(sf::Color::Black);
	no3.setString("3.");
	no3.setPosition(150, 370);
	sf::Text no4;
	no4.setCharacterSize(50);
	no4.setFont(font);
	no4.setFillColor(sf::Color::Black);
	no4.setString("4.");
	no4.setPosition(150, 490);
	sf::Text no5;
	no5.setCharacterSize(50);
	no5.setFont(font);
	no5.setFillColor(sf::Color::Black);
	no5.setString("5.");
	no5.setPosition(150, 610);

	sf::Text credit;
	credit.setCharacterSize(20);
	credit.setFont(font);
	credit.setFillColor(sf::Color::Blue);
	credit.setString("Passakorn Kongboonkiat 63010750");
	credit.setPosition(15.f, 695.f);

	// Start Menu
	sf::Texture menuTexture;
	if (!menuTexture.loadFromFile("image/pauseGame.jpg"));
	sf::IntRect rectMenu(0, 0, 866, 677);
	sf::Sprite menu(menuTexture,rectMenu);
	menu.setScale(2.1f, 1.9f);
	menu.setPosition(0.f, 0.f);

	sf::Texture REVERSETex;
	if(!REVERSETex.loadFromFile("image/REVERSE!.png"));
	sf::Sprite REVERSE0(REVERSETex);

	sf::Texture playTexture;
	if (!playTexture.loadFromFile("image/PLAY.png"));
	sf::Sprite play0(playTexture);

	sf::Texture highScoreTexture;
	if (!highScoreTexture.loadFromFile("image/HIGH_SCORE.png"));
	sf::Sprite highScore0(highScoreTexture);

	sf::Texture howToPlayTexture;
	if (!howToPlayTexture.loadFromFile("image/HOW_TO_PLAY.png"));
	sf::Sprite howToPlay0(howToPlayTexture);

	sf::Texture exitTexture;
	if(!exitTexture.loadFromFile("image/EXIT.png"));
	sf::Sprite exit0(exitTexture);

	// Backward
	sf::Texture backwardTexture;
	if (!backwardTexture.loadFromFile("image/backward.png"));
	sf::Sprite backward(backwardTexture);

	// Pause Menu
	sf::Texture pauseTexture;
	if (!pauseTexture.loadFromFile("image/pauseGame.jpg"));
	sf::Sprite pauseMenu(pauseTexture);
	pauseMenu.setScale(1.3f, 1.3f);
	pauseMenu.setPosition(210.f, 110.f);

	sf::Texture REVERSETexture;
	if (!REVERSETexture.loadFromFile("image/REVERSE!.png"));
	sf::Sprite REVERSE(REVERSETexture);
	REVERSE.setScale(0.5f, 0.5f);
	REVERSE.setPosition(210.f + ((pauseTexture.getSize().x * pauseMenu.getScale().x) / 2) - ((REVERSETexture.getSize().x / 2) * REVERSE.getScale().x)
		, 110.f + ((((pauseTexture.getSize().y * 2) / 6) * pauseMenu.getScale().y) / 2) - ((REVERSETexture.getSize().y / 2) * REVERSE.getScale().y));

	sf::Texture RESUMETexture;
	if (!RESUMETexture.loadFromFile("image/RESUME.png"));
	sf::Sprite RESUME(RESUMETexture);

	sf::Texture RESTARTTexture;
	if (!RESTARTTexture.loadFromFile("image/RESTART.png"));
	sf::Sprite RESTART(RESTARTTexture);
	
	sf::Texture MAINMENUTexture;
	if (!MAINMENUTexture.loadFromFile("image/MAIN_MENU.png"));
	sf::Sprite MAINMENU(MAINMENUTexture);
	sf::Sprite MAINMENU1(MAINMENUTexture);

	sf::Texture SUBMITTexture;
	if (!SUBMITTexture.loadFromFile("image/Submit.png"));
	sf::Sprite SUBMIT(SUBMITTexture);
	
	// Game Over
	// Win
	sf::Texture winTexture;
	if (!winTexture.loadFromFile("image/Victory.png"));
	sf::Sprite winSprite(winTexture);
	winSprite.setScale(0.8f, 0.8f);
	winSprite.setPosition((window.getSize().x / 2) - (winSprite.getScale().x * (winTexture.getSize().x / 2))
		, (window.getSize().y / 8) - (winSprite.getScale().y * (winTexture.getSize().y / 2)));

	// Lose
	sf::Texture gameOverTexture;
	if (!gameOverTexture.loadFromFile("image/GameOver.png"));
	sf::Sprite gameOverSprite(gameOverTexture);
	gameOverSprite.setScale(0.6f, 0.6f);
	gameOverSprite.setPosition(289.5f, 157.2f);

	// STAGE 2 --> Boss Map and Sprite
	sf::Texture bossmapTexture;
	if (!bossmapTexture.loadFromFile("image/Bossmap.jpeg"));

	int bossmapSizeX = bossmapTexture.getSize().x;
	int bossmapSizeY = bossmapTexture.getSize().y;

	sf::IntRect rectBossmap(0, 0, bossmapSizeX, bossmapSizeY);
	sf::Sprite bossmapSprite(bossmapTexture, rectBossmap);
	bossmapSprite.setTexture(bossmapTexture);
	bossmapSprite.setScale(1.0843f, 1.030f);
	bossmapSprite.setPosition(0.f, 0.f);

	sf::RectangleShape gateTo5;
	gateTo5.setSize(sf::Vector2f(5.f, 140.f));
	gateTo5.setFillColor(sf::Color::Blue);

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
	if (!healthBarTexture1.loadFromFile("image/PlayerHealthBar1.png"));

	int healthBarSizeX1 = healthBarTexture1.getSize().x / 8;
	int healthBarSizeY1 = healthBarTexture1.getSize().y;

	// Player batHealth bar Position
	float healthBarPosX = 20.f;
	float healthBarPosY = 20.f;

	// Player batHealth bar
	int playerHealthStatus = 4;

	// Monster Heart Sprite
	sf::Texture heartTexture;
	if (!heartTexture.loadFromFile("image/MonsterHealthBar.png"));

	int heartSizeX = heartTexture.getSize().x / 3;
	int heartSizeY = heartTexture.getSize().y;

	// Monster Heart
	sf::Sprite batHeartSprite(heartTexture);
	batHeartSprite.setTexture(heartTexture);
	batHeartSprite.setScale(0.1f, 0.1f);

	sf::Sprite slimeHeartSprite(heartTexture);
	slimeHeartSprite.setTexture(heartTexture);
	slimeHeartSprite.setScale(0.1f, 0.1f);

	// Monster batHealth bar
	int batHealth = 3;
	int slimeHealth = 3;
	int skeletonHealth = 3;
	float dragonHealth = 0; // MaxHP = 280

	sf::Clock batCollision;

	// Player Sprite
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("image/Player.png"));

	int playerSizeX = playerTexture.getSize().x / 4;
	int playerSizeY = playerTexture.getSize().y / 4;

	sf::IntRect rectPlayer(0, 0, playerSizeX, playerSizeY);
	sf::Sprite playerSprite(playerTexture, rectPlayer);
	playerSprite.setTexture(playerTexture);
	playerSprite.setScale(1.2f, 1.2f);

	sf::IntRect rectPlayer0(0, 0, playerSizeX, playerSizeY);
	sf::Sprite player0(playerTexture, rectPlayer);
	player0.setScale(4.5f, 4.5f);
	player0.setPosition(200.f, 150.f);

	sf::Vector2f playerSpawnPoint = { 70.f, 300.f };
	playerSprite.setPosition(playerSpawnPoint);
	
	// Player Hitbox
	sf::RectangleShape hitBox;
	hitBox.setFillColor(sf::Color::Green);
	hitBox.setSize(sf::Vector2f(10.f, 15.f));

	float playerMoveSpeedX = 1.7f;
	float playerMoveSpeedY = 1.7f;

	int playerAnimationFrame = 0;
	sf::Clock playerClock;

	// Sword Sprite
	sf::Texture swordTexture1;
	if (!swordTexture1.loadFromFile("image/sword.png"));
	sf::IntRect rectSword1(0, 0, 103, 300);
	sf::Sprite sword(swordTexture1, rectSword1);
	sword.setScale(0.2f, 0.25f);
	sf::Clock swordClock;
	sf::Int32 attackTimerMax;

	// Sword Wave
	sf::Texture swordWave;
	if (!swordWave.loadFromFile("image/Swordwave.png"));
	sf::IntRect rectWave(0, 0, 314, 306);
	sf::Sprite swordWaveSprite(swordWave, rectWave);
	swordWaveSprite.setScale(0.2f, 0.25f);
	sf::Clock swordWaveClock;
	float waveX = 5.f;

	// Gun Sprite
	sf::Texture gunTexture;
	if(!gunTexture.loadFromFile("image/gun.png"));
	sf::IntRect rectGun(57, 85, 346, 405);
	sf::Sprite gunSprite(gunTexture, rectGun);
	
	// Gun Item
	sf::Sprite gunItem(gunTexture, rectGun);
	gunItem.setScale(0.12f, 0.12f);

	sf::Texture gunTexture0;
	if (!gunTexture0.loadFromFile("image/gun.png"));
	sf::IntRect rectGun0(57, 85, 346, 405);
	sf::Sprite gunSprite0(gunTexture0, rectGun0);
	gunSprite0.setScale(0.15f, 0.15f);
	gunSprite0.setPosition(50.f, 525.f);
	gunSprite0.setRotation(-90.f);

	// Player Bullet Gun
	sf::Texture pBulletTexture;
	if (!pBulletTexture.loadFromFile("image/playerBullet.png"));
	sf::IntRect rectPBullet(0, 0, 1281, 282);
	sf::Sprite pBullet(pBulletTexture, rectPBullet);

	pBullet.setScale(0.02f, 0.02f);
	pBullet.setPosition(NULL - 1000, NULL - 1000);
	float pBulletX[110] = { NULL - 1000 };
	float pBulletY[110] = { NULL - 1000 };
	float cdpb = 0;
	float pBulletDeg[110] = { 0 };

	// Dragon Sprite (BOSS)
	sf::Texture dragonTexture;
	if (!dragonTexture.loadFromFile("image/Dragonboss.png"));

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
	int dragonCount = 0;

	// Dragon Bossbar Texture and Sprite
	sf::Texture dragonBarTexture;
	if (!dragonBarTexture.loadFromFile("image/DragonBossbar.png"));

	int dragonBarSizeX = dragonBarTexture.getSize().x;
	int dragonBarSizeY = dragonBarTexture.getSize().y;

	sf::IntRect rectDragonBar(0, 0, dragonBarSizeX, dragonBarSizeX);
	sf::Sprite dragonBarSprite(dragonBarTexture, rectDragonBar);
	dragonBarSprite.setTexture(dragonBarTexture);
	dragonBarSprite.setScale(0.5f, 0.5f);
	dragonBarSprite.setPosition(700.f, 600.f);

	// Remove Dragon Healthbar
	sf::Texture dragonBarRTexture;
	if (!dragonBarRTexture.loadFromFile("image/remove.png"));
	int dragonBarRSizeX = dragonBarRTexture.getSize().x;
	int dragonBarRSizeY = dragonBarRTexture.getSize().y;
	sf::IntRect rectDragonR(0, 0, dragonBarRSizeX, dragonBarRSizeY);
	sf::Sprite dragonBarRSprite(dragonBarRTexture, rectDragonR);
	dragonBarRSprite.setTexture(dragonBarRTexture);
	dragonBarRSprite.setScale(0.002f, 0.05f);

	// Dragon ChargeBeam and LaserBeam
	sf::Texture solarBeamTexture;
	if (!solarBeamTexture.loadFromFile("image/SolarBeam.png"));
	int chargeBSizeX = 35;
	int chargeBSizeY = 30;
	int laserSizeX = 200;
	int laserSizeY = 27;

	sf::IntRect rectChargeB(250, 105, chargeBSizeX, chargeBSizeY);
	sf::IntRect rectLaser(7, 160, laserSizeX, laserSizeY);
	sf::Sprite chargeBeamSprite(solarBeamTexture, rectChargeB);
	sf::Sprite laserSprite1(solarBeamTexture, rectLaser);
	sf::Sprite laserSprite2(solarBeamTexture, rectLaser);
	sf::Sprite laserSprite3(solarBeamTexture, rectLaser);
	chargeBeamSprite.setPosition(780.f, 250.f);
	chargeBeamSprite.setScale(1.5f, 1.5f);
	laserSprite1.setRotation(180);
	laserSprite1.setScale(5.f, 1.5f);
	laserSprite2.setRotation(180);
	laserSprite2.setScale(5.f, 1.5f);
	laserSprite3.setRotation(180);
	laserSprite3.setScale(5.f, 1.5f);
	sf::Clock laserClock;
	sf::Clock beamClock1;
	sf::Clock beamClock2;

	// Dragon Bullet
	sf::Texture bulletTex;
	if (!bulletTex.loadFromFile("image/plasmaBullet.png"));
	sf::IntRect rectBullet(251, 324, 19, 19);
	sf::Sprite bullet(bulletTex,rectBullet);
	bullet.setScale(1.3f, 1.3f);
	sf::CircleShape bulletCircle;
	bulletCircle.setFillColor(sf::Color::Green);
	bulletCircle.setRadius(9.5);
	bulletCircle.setScale(1.3f, 1.3f);

	float bulletX[1100] = { NULL - 1000 };
	float bulletY[1100] = { NULL - 1000 };
	float bulletDeg[1100] = { 0 };
	float cdr = 0;
	float degChange = 0;

	// Skeleton Sprite
	sf::Texture skeletonTexture;
	if (!skeletonTexture.loadFromFile("image/skeleton.png"));
	int skeletonSizeX = 100;
	int skeletonSizeY = 100;
	sf::IntRect rectSkeleton1(560, 400, skeletonSizeX, skeletonSizeY);
	sf::Sprite skeletonSprite1(skeletonTexture, rectSkeleton1);
	skeletonSprite1.setTexture(skeletonTexture);
	skeletonSprite1.setScale(0.8f, 0.8f);
	skeletonSprite1.setPosition(920.f, 150.f);
	sf::Clock skeletonClock1;

	sf::IntRect rectSkeleton2(560, 400, skeletonSizeX, skeletonSizeY);
	sf::Sprite skeletonSprite2(skeletonTexture, rectSkeleton2);
	skeletonSprite2.setTexture(skeletonTexture);
	skeletonSprite2.setScale(0.8f, 0.8f);
	skeletonSprite2.setPosition(920.f, 520.f);
	sf::Clock skeletonClock2;

	// Arrow 
	sf::Texture fireArrowTexture;
	if (!fireArrowTexture.loadFromFile("image/arrow2.png"));
	sf::IntRect rectFireArrow(0,0,793,151);
	sf::Sprite fireArrowSprite(fireArrowTexture, rectFireArrow);
	fireArrowSprite.setTexture(fireArrowTexture);
	fireArrowSprite.setScale(0.08f, 0.08f);

	float arrowX[10] = { NULL - 1000 };
	float arrowY[10] = { NULL - 1000 };
	float cda = 0;

	// Bat Sprite
	sf::Texture batTexture;
	if (!batTexture.loadFromFile("image/Monsters.png"));

	int batSizeX = batTexture.getSize().x / 12;
	int batSizeY = batTexture.getSize().y / 8;

	sf::IntRect rectBat(batSizeX, 0, batSizeX, batSizeY);
	sf::Sprite batSprite(batTexture, rectBat);
	batSprite.setTexture(batTexture);
	batSprite.setScale(1.f, 1.f);

	sf::Vector2f batSpawnPoint = { 800.f, 500.f };
	batSprite.setPosition(batSpawnPoint);

	float batMoveSpeedX = .5f;
	float batMoveSpeedY = .5f;

	int batAnimationFrame = 0;
	sf::Clock batClock;

	// Slime Sprite
	sf::Texture slimeTexture;
	if (!slimeTexture.loadFromFile("image/Monsters.png"));

	int slimeSizeX = slimeTexture.getSize().x / 12;
	int slimeSizeY = slimeTexture.getSize().y / 16;

	sf::IntRect rectSlime(slimeSizeX * 3, 0, slimeSizeX, slimeSizeY);
	sf::Sprite slimeSprite(slimeTexture, rectSlime);
	slimeSprite.setTexture(slimeTexture);
	slimeSprite.setScale(1.2f, 1.2f);

	sf::Vector2f slimeSpawnPoint = { 800.f, 50.f };
	slimeSprite.setPosition(slimeSpawnPoint);

	float slimeMoveSpeedX = .25f;
	float slimeMoveSpeedY = .25f;

	int slimeAnimationFrame = 0;
	sf::Clock slimeClock;

	// Items
	// Item Box Sprite
	sf::Texture itemBoxTexture;
	if (!itemBoxTexture.loadFromFile("image/ItemBoxR.png"));
	int itemBoxSizeX = itemBoxTexture.getSize().x;
	int itemBoxSizeY = itemBoxTexture.getSize().y;

	sf::IntRect rectItemBox(0, 0, itemBoxSizeX, itemBoxSizeY);
	sf::Sprite itemBoxSprite(itemBoxTexture, rectItemBox);
	itemBoxSprite.setScale(0.1f, 0.1f);

	sf::Vector2f itemBoxSpawnpoint = { 350.f, 600.f };
	itemBoxSprite.setPosition(itemBoxSpawnpoint);

	// Shield Sprite
	sf::Texture shieldTexture;
	if (!shieldTexture.loadFromFile("image/Shield.png"));
	int shieldSizeX = shieldTexture.getSize().x;
	int shieldSizeY = shieldTexture.getSize().y;

	sf::IntRect rectShield(0, 0, shieldSizeX, shieldSizeY);
	sf::Sprite shieldSprite(shieldTexture, rectShield);
	shieldSprite.setTexture(shieldTexture);
	shieldSprite.setScale(0.15f, 0.15f);

	// Stopwatch Sprite
	sf::Texture stopwatchTexture;
	if (!stopwatchTexture.loadFromFile("image/Stopwatch.png"));
	int stopwatchSizeX = stopwatchTexture.getSize().x;
	int stopwatchSizeY = stopwatchTexture.getSize().y;

	sf::IntRect rectStopwatch(0, 0, stopwatchSizeX, stopwatchSizeY);
	sf::Sprite stopwatchSprite(stopwatchTexture);
	stopwatchSprite.setScale(0.2f, 0.2f);
	stopwatchSprite.setPosition(970.f, 10.f);
	sf::Clock stopwatchClock;

	// Time Stop BG
	sf::Texture timeStopBGTexture;
	if (!timeStopBGTexture.loadFromFile("image/TimeStopBG.png"));

	sf::IntRect rectTimeStopBG(0, 0, 1080, 720);
	sf::Sprite timeStopSprite(timeStopBGTexture);

	// Item Drop Potion
	sf::Texture potionTexture;
	if(!potionTexture.loadFromFile("image/Potion.png"));
	sf::IntRect rectPotion(0, 0, 864, 1022);
	sf::Sprite potion(potionTexture, rectPotion);
	potion.setScale(0.035f, 0.035f);

	// 0
	sf::Texture potionTexture0;
	if (!potionTexture0.loadFromFile("image/Potion.png"));
	sf::IntRect rectPotion0(0, 0, 864, 1022);
	sf::Sprite potion0(potionTexture0, rectPotion0);
	potion0.setScale(0.04f, 0.04f);
	potion0.setPosition(530.f, 485.f);

	sf::Sprite shield0(shieldTexture, rectShield);
	shield0.setScale(0.1f, 0.1f);
	shield0.setPosition(50.f, 570.f);

	sf::Sprite itemBox0(itemBoxTexture, rectItemBox);
	itemBox0.setScale(0.1f, 0.1f);
	itemBox0.setPosition(530.f, 590.f);

	// Random
	sf::Clock random;

	// While Game is Running
	while (window.isOpen())
	{
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

		if (STAGE == 0)
		{
			gateTo5.setPosition(1025, 286);
			if (playerSprite.getGlobalBounds().intersects(gateTo5.getGlobalBounds()))
			{
				playerSprite.setPosition(playerSpawnPoint);
				STAGE = 2;
			}
			window.draw(hitBox);
			window.draw(stage0Sprite);
			if(batHealth > 0) window.draw(batSprite);
			if(slimeHealth > 0) window.draw(slimeSprite);
			window.draw(playerSprite);
			window.draw(timeSprite);
			window.draw(skeletonSprite1);
			window.draw(skeletonSprite2);
			if (pause == 0)
			{
				// Potion Drop
				
				for (int i = 0; i < collect; i++)
				{
					window.draw(potion);
				}
				if (collect == 1)
				{
					if (playerSprite.getGlobalBounds().intersects(potion.getGlobalBounds()))
					{
						if (playerHealthStatus >= 4) playerHealthStatus = 4;
						else playerHealthStatus++;
						collect = 0;
					}
				}
				if (batHealth == 0)
				{
					potion.setPosition(batSprite.getPosition());
					if (randomEffects == 1 || randomEffects == 3 || randomEffects == 5 || randomEffects == 7 || randomEffects == 9)
					{
						collect = 1;
					}
					batHealth = -1;
				}
				if (slimeHealth == 0)
				{
					potion.setPosition(slimeSprite.getPosition());
					if (randomEffects == 1 || randomEffects == 3 || randomEffects == 5 || randomEffects == 7 || randomEffects == 9)
					{
						collect = 1;
					}
					slimeHealth = -1;
				}
				// Bat Health Bar
				if (batHealth > 0)
				{
					for (int i = 0; i < 3; i++)
					{
						sf::IntRect rectBatHeart(heartSizeX * 2, 0, heartSizeX, heartSizeY);
						batHeartSprite.setPosition(batSprite.getPosition().x + (20.f * i), batSprite.getPosition().y - 20.f);
						batHeartSprite.setTextureRect(rectBatHeart);
						window.draw(batHeartSprite);
					}
				}
				for (int i = 0; i < batHealth; i++)
				{
					sf::IntRect rectBatHeart(0, 0, heartSizeX, heartSizeY);
					batHeartSprite.setPosition(batSprite.getPosition().x + (20.f * i), batSprite.getPosition().y - 20.f);
					batHeartSprite.setTextureRect(rectBatHeart);
					window.draw(batHeartSprite);
				}
				// Slime Health Bar
				if (slimeHealth > 0)
				{
					for (int i = 0; i < 3; i++)
					{
						sf::IntRect rectSlimeHeart(heartSizeX * 2, 0, heartSizeX, heartSizeY);
						slimeHeartSprite.setPosition(slimeSprite.getPosition().x + (20.f * i), slimeSprite.getPosition().y - 20.f);
						slimeHeartSprite.setTextureRect(rectSlimeHeart);
						window.draw(slimeHeartSprite);
					}
				}
				for (int i = 0; i < slimeHealth; i++)
				{
					sf::IntRect rectSlimeHeart(0, 0, heartSizeX, heartSizeY);
					slimeHeartSprite.setPosition(slimeSprite.getPosition().x + (20.f * i), slimeSprite.getPosition().y - 20.f);
					slimeHeartSprite.setTextureRect(rectSlimeHeart);
					window.draw(slimeHeartSprite);
				}

				// Slime Update
				if (stopwatch == 0)
				{
					if (slimeSprite.getPosition().y < playerSprite.getPosition().y)
					{
						rectSlime.top = slimeSizeX;
						slimeSprite.move(0.f, slimeMoveSpeedY * deltaTime1.asSeconds() * 100);
						if (slimeClock.getElapsedTime().asSeconds() > 0.3f)
						{
							if (rectSlime.left == (slimeSizeX * 5))
							{
								rectSlime.left = slimeSizeX * 3;
							}
							else
							{
								rectSlime.left += slimeSizeX;
							}
							slimeClock.restart();
						}
						slimeSprite.setTextureRect(rectSlime);
					}
					else
					{
						rectSlime.top = slimeSizeY * 7;
						slimeSprite.move(0.f, -slimeMoveSpeedY * deltaTime1.asSeconds() * 100);
						if (slimeClock.getElapsedTime().asSeconds() > 0.3f)
						{
							if (rectSlime.left == (slimeSizeX * 5))
							{
								rectSlime.left = slimeSizeX * 3;
							}
							else
							{
								rectSlime.left += slimeSizeX;
							}
							slimeClock.restart();
						}
						slimeSprite.setTextureRect(rectSlime);
					}

					if (slimeSprite.getPosition().x < playerSprite.getPosition().x)
					{
						rectSlime.top = slimeSizeY * 5;
						slimeSprite.move(slimeMoveSpeedX * deltaTime1.asSeconds() * 100, 0.f);
						if (slimeClock.getElapsedTime().asSeconds() > 0.3f)
						{
							if (rectSlime.left == (slimeSizeX * 5))
							{
								rectSlime.left = slimeSizeX * 3;
							}
							else
							{
								rectSlime.left += slimeSizeX;
							}
							slimeClock.restart();
						}
						slimeSprite.setTextureRect(rectSlime);
					}
					else
					{
						rectSlime.top = slimeSizeY * 3;
						slimeSprite.move(-slimeMoveSpeedX * deltaTime1.asSeconds() * 100, 0.f);
						if (slimeClock.getElapsedTime().asSeconds() > 0.3f)
						{
							if (rectSlime.left == (slimeSizeX * 5))
							{
								rectSlime.left = slimeSizeX * 3;
							}
							else
							{
								rectSlime.left += slimeSizeX;
							}
							slimeClock.restart();
						}
						slimeSprite.setTextureRect(rectSlime);
					}

					slimeAnimationFrame++;

					if (slimeAnimationFrame >= 3)
					{
						slimeAnimationFrame = 0;
					}

					// Collision
					// Player and Slime
					if (slimeHealth > 0)
					{
						if (slimeSprite.getGlobalBounds().intersects(hitBox.getGlobalBounds()) && immune < 0)
						{
							playerHealthStatus--;
							immune = 3;
						}
					}
				}
				// Skeleton Update
				if (stopwatch == 0)
				{
					if (skeletonClock1.getElapsedTime().asSeconds() > 1)
					{
						if (rectSkeleton1.left == 760)
						{
							rectSkeleton1.left = 560;
						}
						else
						{
							rectSkeleton1.left += 100;
						}
						skeletonClock1.restart();
					}
					skeletonSprite1.setTextureRect(rectSkeleton1);
					if (skeletonClock2.getElapsedTime().asSeconds() > 1)
					{
						if (rectSkeleton2.left == 760)
						{
							rectSkeleton2.left = 560;
						}
						else
						{
							rectSkeleton2.left += 100;
						}
						skeletonClock2.restart();
					}
					skeletonSprite2.setTextureRect(rectSkeleton2);
				}
					if (arrowNow > 8)
						arrowNow = 0;
					for (int i = 0; i < 10; i++)
					{
						if (stopwatch == 0)
						{
							if (arrowX[i] == NULL - 1000 && arrowY[i] == NULL - 1000)
								continue;
							if (arrowX[i] < 0)
							{
								arrowX[i] = (NULL - 1000);
								arrowY[i] = (NULL - 1000);
							}
							arrowX[i] -= 240.f * deltaTime1.asSeconds();
							fireArrowSprite.setPosition(arrowX[i], arrowY[i]);
						}
						window.draw(fireArrowSprite);
						// Player and Arrow
						if (playerSprite.getGlobalBounds().intersects(fireArrowSprite.getGlobalBounds()) && immune < 0)
						{
							if (shield == 0) playerHealthStatus--;
							if (shield == 1) shield = 0;
							arrowX[i] = (NULL - 1000);
							arrowY[i] = (NULL - 1000);
							immune = 3;
						}
					}
					if (cda <= 0)
					{
						arrowX[arrowNow] = 910.f;
						arrowY[arrowNow] = 170.f;
						arrowNow++;
						arrowX[arrowNow] = 910.f;
						arrowY[arrowNow] = 540.f;
						arrowNow++;
						cda = 3;
					}
					else cda -= deltaTime1.asSeconds();

				// Bat Update
				if (stopwatch == 0)
				{
					if (batHealth > 0)
					{
						if (batSprite.getPosition().y < playerSprite.getPosition().y)
						{
							rectBat.top = 0;
							batSprite.move(0.f, batMoveSpeedY * deltaTime1.asSeconds() * 100);
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
							batSprite.move(0.f, -batMoveSpeedY * deltaTime1.asSeconds() * 100);
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
							batSprite.move(batMoveSpeedX * deltaTime1.asSeconds() * 100, 0.f);
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
							batSprite.move(-batMoveSpeedX * deltaTime1.asSeconds() * 100, 0.f);
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

						// Collision
						// Player and Bat
						if (batSprite.getGlobalBounds().intersects(hitBox.getGlobalBounds()) && immune < 0)
						{
							playerHealthStatus--;
							immune = 3;
						}
					}
				}

				// Collision
				// Sword and Bat
				if (swordStatus == 1)
				{
					if (sword.getGlobalBounds().intersects(batSprite.getGlobalBounds()) && batImmune < 0)
					{
						if (batHealth == 1) batS++;
						batHealth--;
						batImmune = 1;
					}
				}

				// Sword and Slime
				if (swordStatus == 1)
				{
					if (sword.getGlobalBounds().intersects(slimeSprite.getGlobalBounds()) && slimeImmune < 0)
					{
						if (slimeHealth == 1) slimeS++;
						slimeHealth--;
						slimeImmune = 1;
					}
				}

				// Sword Wave and Bat
				if (swordWaveSprite.getGlobalBounds().intersects(batSprite.getGlobalBounds()) && batImmune < 0)
				{
					if (batHealth == 1) batS++;
					swordWaveSprite.setPosition(NULL - 1000, NULL - 1000);
					batHealth--;
					batImmune = 1;
				}

				// Sword Wave and Slime
				if (swordWaveSprite.getGlobalBounds().intersects(slimeSprite.getGlobalBounds()) && slimeImmune < 0)
				{
					if (slimeHealth == 1) slimeS++;
					swordWaveSprite.setPosition(NULL - 1000, NULL - 1000);
					slimeHealth--;
					slimeImmune = 1;
				}

				// Bat and Shield
				if (shieldSprite.getGlobalBounds().intersects(batSprite.getGlobalBounds()))
				{
					if (batHealth == 1) batS++;
					shieldSprite.setPosition(NULL - 1000, NULL - 1000);
					if (batSprite.getPosition().y < playerSprite.getPosition().y) batSprite.setPosition(batSprite.getPosition().x, batSprite.getPosition().y - 20);
					if (batSprite.getPosition().y > playerSprite.getPosition().y) batSprite.setPosition(batSprite.getPosition().x, batSprite.getPosition().y + 20);
					if (batSprite.getPosition().x < playerSprite.getPosition().x) batSprite.setPosition(batSprite.getPosition().x - 20, batSprite.getPosition().y);
					if (batSprite.getPosition().x > playerSprite.getPosition().x) batSprite.setPosition(batSprite.getPosition().x + 20, batSprite.getPosition().y);
					batHealth--;
					if (batHealth > 0) shield = 0;
				}

				// Slime and Shield
				if (shieldSprite.getGlobalBounds().intersects(slimeSprite.getGlobalBounds()))
				{
					if (slimeHealth == 1) slimeS++;
					shieldSprite.setPosition(NULL - 1000, NULL - 1000);
					if (slimeSprite.getPosition().y < playerSprite.getPosition().y) slimeSprite.setPosition(slimeSprite.getPosition().x, slimeSprite.getPosition().y - 20);
					if (slimeSprite.getPosition().y > playerSprite.getPosition().y) slimeSprite.setPosition(slimeSprite.getPosition().x, slimeSprite.getPosition().y + 20);
					if (slimeSprite.getPosition().x < playerSprite.getPosition().x) slimeSprite.setPosition(slimeSprite.getPosition().x - 20, slimeSprite.getPosition().y);
					if (slimeSprite.getPosition().x > playerSprite.getPosition().x) slimeSprite.setPosition(slimeSprite.getPosition().x + 20, slimeSprite.getPosition().y);
					slimeHealth--;
					if(slimeHealth > 0) shield = 0;
				}
			}
		}

		if (STAGE == 2) // BOSS STAGE
		{
			window.draw(hitBox);
			window.draw(bossmapSprite);
			window.draw(timeSprite);
			window.draw(itemBoxSprite);
			window.draw(playerSprite);
			window.draw(dragonSprite);
			window.draw(dragonBarSprite);
			window.draw(gunItem);

			// Dragon Health Bar
			for (float i = 0; i < dragonHealth; i++)
			{
				if (i <= 280)
				{
					dragonBarRSprite.setPosition(1042.5f - i, 668.f);
					window.draw(dragonBarRSprite);
				}
			}

			if (pause == 0)
			{

				// Boss Bullet
				if (dragonHealth <= 280)
				{
					if (bulletNow > 1000)
						bulletNow = 0;
					for (int i = 0; i < 1100; i++)
					{
						if (bulletX[i] == NULL - 1000 && bulletY[i] == NULL - 1000)
							continue;
						if (stopwatch == 0)
						{
							bulletX[i] = bulletX[i] + (deltaTime1.asSeconds() * 150) * cos(bulletDeg[i]);
							bulletY[i] = bulletY[i] + (deltaTime1.asSeconds() * 150) * sin(bulletDeg[i]);
						}
						if (bulletX[i] >= 1080 || bulletX[i] <= 0 || bulletY[i] <= 0 || bulletY[i] >= 720)
						{
							bulletX[i] = (NULL - 1000);
							bulletY[i] = (NULL - 1000);
						}
						bullet.setPosition(bulletX[i], bulletY[i]);
						bulletCircle.setPosition(bulletX[i] + 1.5, bulletY[i] + 1.5);

						window.draw(bullet);

						// Player and Bullet
						if (hitBox.getGlobalBounds().intersects(bulletCircle.getGlobalBounds()) && immune < 0)
						{
							if (shield == 0) playerHealthStatus--;
							if (shield == 1) shield = 0;
							bossBullet = 0;
							bulletX[i] = (NULL - 1000);
							bulletY[i] = (NULL - 1000);
							immune = 3;
						}
					}
					if (stopwatch == 0)
					{
						if (cdr <= 0)
						{
							bulletX[bulletNow] = 780;
							bulletY[bulletNow] = 250;
							bulletDeg[bulletNow] = (0) + degChange;
							bulletNow++;
							bulletX[bulletNow] = 780;
							bulletY[bulletNow] = 250;
							bulletDeg[bulletNow] = (PI / 4) + degChange;
							bulletNow++;
							bulletX[bulletNow] = 780;
							bulletY[bulletNow] = 250;
							bulletDeg[bulletNow] = (2 * PI / 4) + degChange;
							bulletNow++;
							bulletX[bulletNow] = 780;
							bulletY[bulletNow] = 250;
							bulletDeg[bulletNow] = (3 * PI / 4) + degChange;
							bulletNow++;
							bulletX[bulletNow] = 780;
							bulletY[bulletNow] = 250;
							bulletDeg[bulletNow] = (4 * PI / 4) + degChange;
							bulletNow++;
							bulletX[bulletNow] = 780;
							bulletY[bulletNow] = 250;
							bulletDeg[bulletNow] = (5 * PI / 4) + degChange;
							bulletNow++;
							bulletX[bulletNow] = 780;
							bulletY[bulletNow] = 250;
							bulletDeg[bulletNow] = (6 * PI / 4) + degChange;
							bulletNow++;
							bulletX[bulletNow] = 780;
							bulletY[bulletNow] = 250;
							bulletDeg[bulletNow] = (7 * PI / 4) + degChange;
							degChange = degChange + 0.3f;
							bulletNow++;
							cdr = 0.3;

							if (dragonHealth > 70)
							{
								bulletNow++;
								bulletX[bulletNow] = 780;
								bulletY[bulletNow] = 250;
								bulletDeg[bulletNow] = (PI / 8) + degChange;
								bulletNow++;
								bulletX[bulletNow] = 780;
								bulletY[bulletNow] = 250;
								bulletDeg[bulletNow] = (3 * PI / 8) + degChange;
								bulletNow++;
								bulletX[bulletNow] = 780;
								bulletY[bulletNow] = 250;
								bulletDeg[bulletNow] = (5 * PI / 8) + degChange;
								bulletNow++;
								bulletX[bulletNow] = 780;
								bulletY[bulletNow] = 250;
								bulletDeg[bulletNow] = (7 * PI / 8) + degChange;
								bulletNow++;
								bulletX[bulletNow] = 780;
								bulletY[bulletNow] = 250;
								bulletDeg[bulletNow] = (9 * PI / 8) + degChange;
								bulletNow++;
								bulletX[bulletNow] = 780;
								bulletY[bulletNow] = 250;
								bulletDeg[bulletNow] = (11 * PI / 8) + degChange;
								bulletNow++;
								bulletX[bulletNow] = 780;
								bulletY[bulletNow] = 250;
								bulletDeg[bulletNow] = (13 * PI / 8) + degChange;
								bulletNow++;
								bulletX[bulletNow] = 780;
								bulletY[bulletNow] = 250;
								bulletDeg[bulletNow] = (15 * PI / 8) + degChange;
								bulletNow++;
							}
						}
						else cdr -= deltaTime1.asSeconds();
					}
				}
				// Dragon Laser
				if (dragonHealth < 140)
				{
					beamClock1.restart().Zero;
					beamClock2.restart().Zero;
					laserClock.restart().Zero;
				}
				if (dragonHealth >= 140)
				{
					if (beamClock1.getElapsedTime().asSeconds() > 7.6f)
					{
						laserStatus = 0;
						beamClock1.restart();
					}
					if (beamClock2.getElapsedTime().asSeconds() > 1.f)
					{
						beam++;
						beamClock2.restart();
					}

					if (laserClock.getElapsedTime().asSeconds() > 4.f)
					{
						if (laserClock.getElapsedTime().asSeconds() > 7.5f)
						{
							for (int i = 0; i < laserStatus; i++)
							{
								laserSprite1.setPosition(NULL - 1000, NULL - 1000);
								laserSprite2.setPosition(NULL - 1000, NULL - 1000);
								laserSprite3.setPosition(NULL - 1000, NULL - 1000);
							}
						}
						else
						{
							for (int i = 0; i < laserStatus; i++)
							{
								laserSprite1.setPosition(820.f, 95.f);
								laserSprite2.setPosition(820.f, 295.f);
								laserSprite3.setPosition(820.f, 495.f);
								window.draw(laserSprite1);
								window.draw(laserSprite2);
								window.draw(laserSprite3);
							}
						}
					}
					for (int i = 0; i < laserStatus; i++)
					{
						if (i == 0)
						{
							if (beam == 1 || beam == 3)chargeBeamSprite.setPosition(NULL - 1000, NULL - 1000);
							else chargeBeamSprite.setPosition(780.f, 50.f);
						}
						if (i == 1)
						{
							if (beam == 1 || beam == 3)chargeBeamSprite.setPosition(NULL - 1000, NULL - 1000);
							else chargeBeamSprite.setPosition(780.f, 250.f);
						}
						if (i == 2)
						{
							if (beam == 1 || beam == 3)chargeBeamSprite.setPosition(NULL - 1000, NULL - 1000);
							else chargeBeamSprite.setPosition(780.f, 450.f);
						}
						window.draw(chargeBeamSprite);
					}
				}

				// Sword Wave and Dragon (BOSS)
				if (swordWaveSprite.getGlobalBounds().intersects(dragonSprite.getGlobalBounds()) && dragonImmune < 0)
				{
					dragonHealth += 5;
					dragonImmune = 1;
				}

				// Player and Laser
				if (hitBox.getGlobalBounds().intersects(laserSprite1.getGlobalBounds()) && immune < 0)
				{
					if (shield == 0) playerHealthStatus -= 2;
					if (shield == 1) shield = 0;
					immune = 3;
				}
				if (hitBox.getGlobalBounds().intersects(laserSprite2.getGlobalBounds()) && immune < 0)
				{
					if (shield == 0) playerHealthStatus -= 2;
					if (shield == 1) shield = 0;
					immune = 3;
				}
				if (hitBox.getGlobalBounds().intersects(laserSprite3.getGlobalBounds()) && immune < 0)
				{
					if (shield == 0) playerHealthStatus -= 2;
					if (shield == 1) shield = 0;
					immune = 3;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// ALWAY RUN
		// Player Update
		if (STAGE == 0 || STAGE == 1 || STAGE == 2)
		{
			// Player Health Bar
			for (int i = 0; i < playerHealthStatus; i++)
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

			if (pause == 0)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && playerSprite.getPosition().y > 20 && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					rectPlayer.top = playerSizeY * 3;
					playerSprite.move(0.f, -playerMoveSpeedY * deltaTime1.asSeconds() * 100);
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
					playerSprite.move(0.f, playerMoveSpeedY * deltaTime1.asSeconds() * 100);
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
					playerSprite.move(playerMoveSpeedX * deltaTime1.asSeconds() * 100, 0.f);
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
					playerSprite.move(-playerMoveSpeedX * deltaTime1.asSeconds() * 100, 0.f);
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

				if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A)
					&& !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					rectPlayer.left = 0;
					playerSprite.setTextureRect(rectPlayer);
				}

				playerAnimationFrame++;

				if (playerAnimationFrame >= 4)
				{
					playerAnimationFrame = 0;
				}

				// Player Hit Box
				hitBox.setPosition(playerSprite.getPosition().x + 14.2, playerSprite.getPosition().y + 26);

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

				// Collect Item
				if (STAGE == 2)
				{
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
						// Potion
						else if (randomEffects == 7 || randomEffects == 8 || randomEffects == 9 || randomEffects == 10)
						{
							if (playerHealthStatus <= 3) playerHealthStatus++;
							else playerHealthStatus = playerHealthStatus;
						}
					}
				}

				// Stopwatch
				if (stopwatch == 0) stopwatchClock.restart().Zero;
				if (stopwatch == 1)
				{
					window.draw(timeStopSprite);
					window.draw(stopwatchSprite);
					if (stopwatchClock.getElapsedTime().asSeconds() > 3)
					{
						stopwatch = 0;
						stopwatchClock.restart();
					}
				}

				// Shield
				if (shield == 1)
				{
					shieldSprite.setPosition(playerSprite.getPosition().x - ((shieldSizeX * 0.15f) / 2) + (playerSizeX / 2), playerSprite.getPosition().y - ((shieldSizeY * 0.15f) / 2) + (playerSizeY / 2));
					window.draw(shieldSprite);
				}

				// Sword update
				if (gun == 0)
				{
					// Edit
					float dX = mouse.getPosition(window).x - playerSprite.getPosition().x - playerTexture.getSize().x / 8;
					if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						swordStatus = 0;
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sword0 < 0)
					{
						swordStatus = 1;
						sword0 = 1;
					}
					if (dX >= 0)
					{
						sword.setRotation(-90);
						sword.setPosition(playerSprite.getPosition().x + ((playerSizeX / 2) * playerSprite.getScale().x)
							, playerSprite.getPosition().y + ((playerSizeY / 2) * playerSprite.getScale().y)
							+ ((sword.getScale().x / 2) * swordTexture1.getSize().x));
					}
					if (dX < 0)
					{
						sword.setRotation(90);
						sword.setPosition(playerSprite.getPosition().x + ((playerSizeX / 2) * playerSprite.getScale().x)
							, playerSprite.getPosition().y + ((playerSizeY / 2) * playerSprite.getScale().y)
							- ((sword.getScale().x / 2) * swordTexture1.getSize().x));
					}

					// Sword Wave Skill
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && waveInt == 0)
					{
						swordWaveSprite.setPosition(playerSprite.getPosition().x + 5.f, playerSprite.getPosition().y);
						if (mouse.getPosition(window).x - playerSprite.getPosition().x >= 0) waveInt = 1;
						if (mouse.getPosition(window).x - playerSprite.getPosition().x < 0) waveInt = 2;
					}
					if (waveInt == 1)
					{
						swordWaveSprite.setScale(0.2f, 0.25f);
						swordWaveSprite.move(waveX, 0.f);
						window.draw(swordWaveSprite);
					}
					if (waveInt == 2)
					{
						swordWaveSprite.setScale(-0.2f, 0.25f);
						swordWaveSprite.move(-waveX, 0.f);
						window.draw(swordWaveSprite);
					}
					if (swordWaveClock.getElapsedTime().asSeconds() > 5)
					{
						waveInt = 0;
						swordWaveClock.restart();
					}
				}

				// Gun update
				if (gun == 1)
				{
					float dX = mouse.getPosition(window).x - playerSprite.getPosition().x - playerTexture.getSize().x / 8;
					float dY = mouse.getPosition(window).y - playerSprite.getPosition().y - playerTexture.getSize().y / 8;

					float deg = atan2(dX, dY) * 180 / PI;
					if ((mouse.getPosition(window).x - playerSprite.getPosition().x - playerTexture.getSize().x / 8) > 0)
					{
						gunSprite.setScale(0.12f, 0.12f);
						gunSprite.setRotation(35.f - deg);
					}
					if ((mouse.getPosition(window).x - playerSprite.getPosition().x - playerTexture.getSize().x / 8) <= 0)
					{
						gunSprite.setScale(-0.12f, 0.12f);
						gunSprite.setRotation(-35.f - deg);
					}
					gunSprite.setPosition(playerSprite.getPosition().x + playerTexture.getSize().x / 8, playerSprite.getPosition().y + playerTexture.getSize().y / 6);
					// Player Bullet Gun
					float slope = atan(dY / dX);
					if (pBulletNow > 100)
						pBulletNow = 0;
					for (int i = 0; i < 110; i++)
					{
						if (pBulletX[i] == NULL - 1000 && pBulletY[i] == NULL - 1000)
							continue;
						pBulletX[i] = pBulletX[i] + (deltaTime1.asSeconds() * 1000) * cos(pBulletDeg[i]);
						pBulletY[i] = pBulletY[i] + (deltaTime1.asSeconds() * 1000) * sin(pBulletDeg[i]);
						pBullet.setPosition(pBulletX[i], pBulletY[i]);
						pBullet.setRotation(pBulletDeg[i] * 180 / PI);
						window.draw(pBullet);
						if (pBulletX[i] > 1080 || pBulletX[i] < 0 || pBulletY[i] < 0 || pBulletY[i] > 720)
						{
							pBulletX[i] = (NULL - 1000);
							pBulletY[i] = (NULL - 1000);
						}
						if (STAGE == 2)
						{
							if (pBullet.getGlobalBounds().intersects(dragonSprite.getGlobalBounds())
								|| pBullet.getGlobalBounds().intersects(batSprite.getGlobalBounds())
								|| pBullet.getGlobalBounds().intersects(slimeSprite.getGlobalBounds()))
							{
								dragonHealth += 0.4;
								pBulletX[i] = (NULL - 1000);
								pBulletY[i] = (NULL - 1000);
							}
						}
					}
					if (cdpb <= 0)
					{
						pBulletX[pBulletNow] = playerSprite.getPosition().x + ((playerSizeX / 2) * playerSprite.getScale().x);
						pBulletY[pBulletNow] = playerSprite.getPosition().y + ((playerSizeY / 2) * playerSprite.getScale().y);
						if (dX > 0)
							pBulletDeg[pBulletNow] = slope;
						else
							pBulletDeg[pBulletNow] = PI + slope;
						pBulletNow++;
						cdpb = 0.1;
					}
					else cdpb -= deltaTime1.asSeconds();
				}
			}

			// Weapons
			if (pause == 0)
			{
				if (gun == 0)
				{
					if (swordStatus == 1 || sword0 > 0.85) window.draw(sword);
				}
				if (gun == 1) window.draw(gunSprite);
			}
			// Gun
			if (STAGE == 2)
			{
				if (weaponStatus == 0)
				{
					gunItem.setPosition(350.f, 80.f);
					gun = 0;
				}
				if (weaponStatus == 1)
				{
					gunItem.setPosition(NULL - 1000, NULL - 1000);
					gun = 1;
				}
				if (hitBox.getGlobalBounds().intersects(gunItem.getGlobalBounds()))
				{
					weaponStatus = 1;
				}
			}

			// Player immune time
			immune -= deltaTime1.asSeconds();
			immuneBlink -= deltaTime1.asSeconds();
			if (immune < 0)
			{
				playerSprite.setColor(sf::Color(255, 255, 255, 255));
			}
			else if (immuneBlink <= 0)
			{
				immuneBlink = 0.2;
			}
			else if (immuneBlink <= 0.1)
			{
				playerSprite.setColor(sf::Color(255, 255, 255, 255));
			}
			else if (immuneBlink <= 0.2)
			{
				playerSprite.setColor(sf::Color(255, 255, 255, 0));
			}

			// Monster immune time
			batImmune -= deltaTime1.asSeconds();
			slimeImmune -= deltaTime1.asSeconds();
			dragonImmune -= deltaTime1.asSeconds();
			sword0 -= deltaTime1.asSeconds();

			// Time
			if (pause == 1 || STAGE == 4)
			{
				deltaTime1 = timeClock.restart().Zero;
			}
			if (pause == 0)
			{
				deltaTime1 = timeClock.restart();
				timeCount.setString(std::to_string(timeC));
				CTime.setString(std::to_string(timeC));
				timeC = timeC + deltaTime1.asSeconds();
			}
			window.draw(timeCount);

			// Pause Menu
			if (pause == 1)
			{
				// RESUME
				if (mouse.getPosition(window).x > 475 && mouse.getPosition(window).x < 615
					&& mouse.getPosition(window).y > 300 && mouse.getPosition(window).y < 335)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						pause = 0;
					}
					RESUME.setScale(0.35f, 0.35f);
					RESUME.setColor(sf::Color(255, 255, 255, 255));
				}
				else
				{
					RESUME.setScale(0.28f, 0.28f);
					RESUME.setColor(sf::Color(255, 255, 255, 200));
				}

				RESUME.setPosition(210.f + ((pauseTexture.getSize().x * pauseMenu.getScale().x) / 2)
					- ((RESUMETexture.getSize().x / 2) * RESUME.getScale().x)
					, 150.f + ((((pauseTexture.getSize().y * 4) / 6) * pauseMenu.getScale().y) / 2)
					- ((RESUMETexture.getSize().y / 2) * RESUME.getScale().y));

				// RESTART
				if (mouse.getPosition(window).x > 475 && mouse.getPosition(window).x < 615
					&& mouse.getPosition(window).y > 375 && mouse.getPosition(window).y < 415)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						STAGE = 0;

						SCOREA = 0;
						SCOREB = 0;
						SCOREC = 0;

						cantype = 0;
						playernamenow = 0;
						playername[20];
						canbackspace = 0;
						totalScore = 0;
						scoreCheck = 0;
						slimeS = 0;
						batS = 0;
						scoreStatus = 0;
						scoreboardupdate = 0;
						cantype = 0;
						playernamenow = 0;
						playername[20];
						canbackspace = 0;
						backspacetime = 0;

						sword0 = 0;
						shield = 0;
						stopwatch = 0;
						keyPressed = 0;
						bossBullet = 0;
						swordStatus = 0;
						weaponStatus = 0;
						beam = 0;
						laserStatus = 3;
						SWCD = 5;
						immune = 0;
						immuneBlink = 0;
						batImmune = 0;
						slimeImmune = 0;
						dragonImmune = 0;
						weaponSwap = 0;
						sword0 = 0;
						weaponsType = 0;
						bulletNow = 0;
						arrowNow = 0;
						pBulletNow = 0;
						pBulletStatus = 0;
						timeC = 0;
						pause = 0;
						check1 = 0;
						check2 = 0;
						gun = 0;
						pBulletInt = 0;
						playerHealthStatus = 4;
						batHealth = 3;
						slimeHealth = 3;
						skeletonHealth = 3;
						dragonHealth = 0;
						playerAnimationFrame = 0;
						for (int i = 0; i < 110; i++)
						{
							if (i == 110) i = 0;
							pBulletX[i] = { NULL - 1000 };
							pBulletY[i] = { NULL - 1000 };
							pBulletDeg[i] = { 0 };
						}
						cdpb = 0;
						a = 200;
						dragonPosY = 0.0;
						dragonCount = 0;
						for (int i = 0; i < 1100; i++)
						{
							if (i == 1100) i = 0;
							bulletX[i] = { NULL - 1000 };
							bulletY[i] = { NULL - 1000 };
							bulletDeg[i] = { 0 };
						}
						cdr = 0;
						degChange = 0;
						for (int i = 0; i < 10; i++)
						{
							if (i == 10) i = 0;
							arrowX[i] = { NULL - 1000 };
							arrowY[i] = { NULL - 1000 };
						}
						cda = 0;
						batAnimationFrame = 0;
						playerSprite.setPosition(playerSpawnPoint);
						pBullet.setPosition(NULL - 1000, NULL - 1000);
						dragonSprite.setPosition(dragonSpawnpoint);
						chargeBeamSprite.setPosition(780.f, 250.f);
						batSprite.setPosition(batSpawnPoint);
						slimeSprite.setPosition(slimeSpawnPoint);
						itemBoxSprite.setPosition(itemBoxSpawnpoint);
					}
					RESTART.setScale(0.35f, 0.35f);
					RESTART.setColor(sf::Color(255, 255, 255, 255));
				}
				else
				{
					RESTART.setScale(0.28f, 0.28f);
					RESTART.setColor(sf::Color(255, 255, 255, 200));
				}

				RESTART.setPosition(210.f + ((pauseTexture.getSize().x * pauseMenu.getScale().x) / 2)
					- ((RESTARTTexture.getSize().x / 2) * RESTART.getScale().x)
					, 230.f + ((((pauseTexture.getSize().y * 4) / 6) * pauseMenu.getScale().y) / 2)
					- ((RESTARTTexture.getSize().y / 2) * RESTART.getScale().y));

				// MAIN MENU
				if (mouse.getPosition(window).x > 475 && mouse.getPosition(window).x < 615
					&& mouse.getPosition(window).y > 455 && mouse.getPosition(window).y < 495)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						pause = 0;
						STAGE = 3;

						SCOREA = 0;
						SCOREB = 0;
						SCOREC = 0;

						cantype = 0;
						playernamenow = 0;
						playername[20];
						canbackspace = 0;
						totalScore = 0;
						scoreCheck = 0;
						slimeS = 0;
						batS = 0;
						scoreStatus = 0;
						scoreboardupdate = 0;
						cantype = 0;
						playernamenow = 0;
						playername[20];
						canbackspace = 0;
						backspacetime = 0;

						sword0 = 0;
						shield = 0;
						stopwatch = 0;
						keyPressed = 0;
						bossBullet = 0;
						swordStatus = 0;
						weaponStatus = 0;
						beam = 0;
						laserStatus = 3;
						SWCD = 5;
						immune = 0;
						immuneBlink = 0;
						batImmune = 0;
						slimeImmune = 0;
						dragonImmune = 0;
						weaponSwap = 0;
						sword0 = 0;
						weaponsType = 0;
						bulletNow = 0;
						arrowNow = 0;
						pBulletNow = 0;
						pBulletStatus = 0;
						timeC = 0;
						pause = 0;
						check1 = 0;
						check2 = 0;
						gun = 0;
						pBulletInt = 0;
						playerHealthStatus = 4;
						batHealth = 3;
						slimeHealth = 3;
						skeletonHealth = 3;
						dragonHealth = 0;
						playerAnimationFrame = 0;
						for (int i = 0; i < 110; i++)
						{
							if (i == 110) i = 0;
							pBulletX[i] = { NULL - 1000 };
							pBulletY[i] = { NULL - 1000 };
							pBulletDeg[i] = { 0 };
						}
						cdpb = 0;
						a = 200;
						dragonPosY = 0.0;
						dragonCount = 0;
						for (int i = 0; i < 1100; i++)
						{
							if (i == 1100) i = 0;
							bulletX[i] = { NULL - 1000 };
							bulletY[i] = { NULL - 1000 };
							bulletDeg[i] = { 0 };
						}
						cdr = 0;
						degChange = 0;
						for (int i = 0; i < 10; i++)
						{
							if (i == 10) i = 0;
							arrowX[i] = { NULL - 1000 };
							arrowY[i] = { NULL - 1000 };
						}
						cda = 0;
						batAnimationFrame = 0;
						playerSprite.setPosition(playerSpawnPoint);
						pBullet.setPosition(NULL - 1000, NULL - 1000);
						dragonSprite.setPosition(dragonSpawnpoint);
						chargeBeamSprite.setPosition(780.f, 250.f);
						batSprite.setPosition(batSpawnPoint);
						slimeSprite.setPosition(slimeSpawnPoint);
						itemBoxSprite.setPosition(itemBoxSpawnpoint);
					}
					MAINMENU.setScale(0.35f, 0.35f);
					MAINMENU.setColor(sf::Color(255, 255, 255, 255));
				}
				else
				{
					MAINMENU.setScale(0.28f, 0.28f);
					MAINMENU.setColor(sf::Color(255, 255, 255, 200));
				}

				MAINMENU.setPosition(210.f + ((pauseTexture.getSize().x * pauseMenu.getScale().x) / 2)
					- ((MAINMENUTexture.getSize().x / 2) * MAINMENU.getScale().x)
					, 310.f + ((((pauseTexture.getSize().y * 4) / 6) * pauseMenu.getScale().y) / 2)
					- ((MAINMENUTexture.getSize().y / 2) * MAINMENU.getScale().y));

				window.draw(pauseMenu);
				window.draw(REVERSE);
				window.draw(RESUME);
				window.draw(RESTART);
				window.draw(MAINMENU);
			}
		}
		// Start Menu
		if (STAGE == 3)
		{
			deltaTime1 = timeClock.restart().Zero;
			
			// REVERSE!
			REVERSE0.setScale(0.65f, 0.65f);
			REVERSE0.setPosition((window.getSize().x / 2) - ((REVERSETex.getSize().x / 2) * REVERSE0.getScale().x)
				, (window.getSize().y / 6) - ((REVERSETex.getSize().y / 2) * REVERSE0.getScale().y));

			// PLAY
			if (mouse.getPosition(window).x > 460 && mouse.getPosition(window).x < 625
				&& mouse.getPosition(window).y > 246 && mouse.getPosition(window).y < 311)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					STAGE = 0;
				}
				play0.setScale(0.7f, 0.7f);
			}
			else
			{
				play0.setScale(0.55f,0.55f);
			}
			
			play0.setPosition((window.getSize().x / 2) - ((playTexture.getSize().x / 2) * play0.getScale().x)
				, ((window.getSize().y * 2.4)/ 6) - ((playTexture.getSize().y / 2) * play0.getScale().y));

			// HOW TO PLAY
			if (mouse.getPosition(window).x > 340 && mouse.getPosition(window).x < 745
				&& mouse.getPosition(window).y > 356 && mouse.getPosition(window).y < 420)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					STAGE = 6;
				}
				howToPlay0.setScale(0.7f, 0.7f);
			}
			else
			{
				howToPlay0.setScale(0.55f, 0.55f);
			}

			howToPlay0.setPosition((window.getSize().x / 2) - ((howToPlayTexture.getSize().x / 2) * howToPlay0.getScale().x)
				, ((window.getSize().y * 3.3) / 6) - ((howToPlayTexture.getSize().y / 2) * howToPlay0.getScale().y));
			
			// HIGH SCORE
			if (mouse.getPosition(window).x > 365 && mouse.getPosition(window).x < 715
				&& mouse.getPosition(window).y > 497 && mouse.getPosition(window).y < 542)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					STAGE = 7;
				}
				highScore0.setScale(0.7f, 0.7f);
			}
			else
			{
				highScore0.setScale(0.55f, 0.55f);
			}

			highScore0.setPosition((window.getSize().x / 2) - ((highScoreTexture.getSize().x / 2) * highScore0.getScale().x)
				, ((window.getSize().y * 4.3) / 6) - ((highScoreTexture.getSize().y / 2) * highScore0.getScale().y));

			// EXIT
			if (mouse.getPosition(window).x > 475 && mouse.getPosition(window).x < 610
				&& mouse.getPosition(window).y > 600 && mouse.getPosition(window).y < 660)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					window.close();
				}
				exit0.setScale(0.7f, 0.7f);
			}
			else
			{
				exit0.setScale(0.55f, 0.55f);
			}

			exit0.setPosition((window.getSize().x / 2) - ((exitTexture.getSize().x / 2) * exit0.getScale().x)
				, ((window.getSize().y * 5.3) / 6) - ((exitTexture.getSize().y / 2) * exit0.getScale().y));

			window.draw(menu);
			window.draw(REVERSE0);
			window.draw(play0);
			window.draw(howToPlay0);
			window.draw(highScore0);
			window.draw(exit0);
			window.draw(credit);
		}
		// How To Play
		if (STAGE == 6)
		{
			window.draw(menu);
			window.draw(gunSprite0);
			window.draw(potion0);
			window.draw(shield0);
			window.draw(itemBox0);
			window.draw(player0);

			if (mouse.getPosition(window).x > 35 && mouse.getPosition(window).x < 110
				&& mouse.getPosition(window).y > 15 && mouse.getPosition(window).y < 80)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					STAGE = 3;
				}
				backward.setScale(0.16f, 0.16f);
			}
			else
			{
				backward.setScale(0.12f, 0.12f);	
			}
			backward.setPosition((window.getPosition().x / 10) - ((backwardTexture.getSize().x / 10) * backward.getScale().x)
				, (window.getPosition().y / 10) - ((backwardTexture.getSize().y / 10) * backward.getScale().y));
			window.draw(backward);

			for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
			{
				how[0].setCharacterSize(35.f);
				how[0].setFont(font);
				how[0].setFillColor(sf::Color::Black);
				how[0].setString("W/A/S/D to control your player");
				how[0].setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / (MAX_NUMBER_OF_ITEMS + 1) * 1.2));

				how[1].setCharacterSize(35.f);
				how[1].setFont(font);
				how[1].setFillColor(sf::Color::Black);
				how[1].setString("LEFT MOUSE = attack (only sword)");
				how[1].setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / (MAX_NUMBER_OF_ITEMS + 1) * 2.4));

				how[2].setCharacterSize(35.f);
				how[2].setFont(font);
				how[2].setFillColor(sf::Color::Black);
				how[2].setString("SPACE = skill (only sword)");
				how[2].setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / (MAX_NUMBER_OF_ITEMS + 1) * 3.6));

				how[3].setCharacterSize(35.f);
				how[3].setFont(font);
				how[3].setFillColor(sf::Color::Black);
				how[3].setString("ESC = Pause");
				how[3].setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / (MAX_NUMBER_OF_ITEMS + 1) * 4.8));

				how[4].setCharacterSize(35.f);
				how[4].setFont(font);
				how[4].setFillColor(sf::Color::Blue);
				how[4].setString("Change sword to gun");
				how[4].setPosition(sf::Vector2f(window.getSize().x / 8, window.getSize().y / (MAX_NUMBER_OF_ITEMS + 1) * 6));

				how[5].setCharacterSize(35.f);
				how[5].setFont(font);
				how[5].setFillColor(sf::Color::Blue);
				how[5].setString("Healing potion");
				how[5].setPosition(sf::Vector2f((window.getSize().x * 4.5) / 8, window.getSize().y / (MAX_NUMBER_OF_ITEMS + 1) * 6));

				how[6].setCharacterSize(35.f);
				how[6].setFont(font);
				how[6].setFillColor(sf::Color::Blue);
				how[6].setString("Shield (protect 1 times)");
				how[6].setPosition(sf::Vector2f(window.getSize().x / 8, window.getSize().y / (MAX_NUMBER_OF_ITEMS + 1) * 7.2));

				how[7].setCharacterSize(35.f);
				how[7].setFont(font);
				how[7].setFillColor(sf::Color::Blue);
				how[7].setString("Random Item Box\n(Potion / Shield / Stopwatch)");
				how[7].setPosition(sf::Vector2f((window.getSize().x * 4.5) / 8, window.getSize().y / (MAX_NUMBER_OF_ITEMS + 1) * 7.2));

				window.draw(how[i]);
			}
		}

		// HIGH SCORE
		if (STAGE == 7)
		{
			window.draw(menu);

			if (mouse.getPosition(window).x > 35 && mouse.getPosition(window).x < 110
				&& mouse.getPosition(window).y > 15 && mouse.getPosition(window).y < 80)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					STAGE = 3;
				}
				backward.setScale(0.16f, 0.16f);
			}
			else
			{
				backward.setScale(0.12f, 0.12f);
			}
			backward.setPosition((window.getPosition().x / 10) - ((backwardTexture.getSize().x / 10) * backward.getScale().x)
				, (window.getPosition().y / 10) - ((backwardTexture.getSize().y / 10) * backward.getScale().y));
			window.draw(backward);

			//update
			if (scoreboardupdate == 0)
			{
				char temp[256];
				FILE* fp;
				string leaderboardname[5];
				int leaderboardscore[5];
				fp = fopen("./score.txt", "r");
				for (int i = 0; i < 5; i++)
				{
					fscanf(fp, "%s", &temp);
					leaderboardname[i] = temp;
					fscanf(fp, "%d", &leaderboardscore[i]);
				}
				player1.setString(leaderboardname[0]);
				player2.setString(leaderboardname[1]);
				player3.setString(leaderboardname[2]);
				player4.setString(leaderboardname[3]);
				player5.setString(leaderboardname[4]);
				score1.setString(to_string(leaderboardscore[0]));
				score2.setString(to_string(leaderboardscore[1]));
				score3.setString(to_string(leaderboardscore[2]));
				score4.setString(to_string(leaderboardscore[3]));
				score5.setString(to_string(leaderboardscore[4]));
				scoreboardupdate = 1;
			}
			window.draw(scoreboardText);
			window.draw(no1);
			window.draw(no2);
			window.draw(no3);
			window.draw(no4);
			window.draw(no5);
			window.draw(player1);
			window.draw(player2);
			window.draw(player3);
			window.draw(player4);
			window.draw(player5);
			window.draw(score1);
			window.draw(score2);
			window.draw(score3);
			window.draw(score4);
			window.draw(score5);
		}

		// Calculate Score
		if (STAGE == 4 && scoreCheck == 0)
		{
			if (batS == 1) SCOREA = 100; // bat
			if (slimeS == 1) SCOREB = 100; // slime
			SCOREC = 5000; // dragon
			scoreCalculateA = SCOREA * 150; // total bat score
			scoreCalculateB = SCOREB * 100; // total slime score
			scoreCalculateC = SCOREC * 200; // total dragon score
			totalScore = (100 * (SCOREA + SCOREB + SCOREC)) / timeC; // total score
			scoreCheck = 1;
		}
		// End Game
		// win
		if (dragonHealth > 280) STAGE = 4;
		if (STAGE == 4)
		{
			SCORENow.setString(to_string(int(totalScore)));
			window.draw(menu);
			window.draw(winSprite);
			window.draw(EnterScore);
			window.draw(ClearTime);
			window.draw(CTime);
			window.draw(SCORENow);
			window.draw(EnterName);
			window.draw(name);

			//name input
			if (event.type != sf::Event::TextEntered) cantype = 1;
			if (event.type == sf::Event::TextEntered && cantype == 1)
			{
				if (event.text.unicode < 128)
				{
					if (!sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && playernamenow < 14) {
						playername[playernamenow] = static_cast<char>(event.text.unicode);
						playernamenow++;
					}
				}
				cantype = 0;
			}
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) canbackspace = 1;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && canbackspace == 1)
			{
				if (playernamenow > 0) {
					playernamenow--;
					playername[playernamenow] = '\0';
					canbackspace = 0;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
			{
				backspacetime += deltaTime1.asSeconds();
			}
			else backspacetime = 0;
			if (backspacetime > 0.5)
			{
				for (int i = 0; i < 15; i++)
				{
					playername[i] = '\0';
				}
				playernamenow = 0;
			}
			name.setString(playername);
			printf("%s %d\n", playername, playernamenow);
			sf::Vector2i position = sf::Mouse::getPosition(window);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
				&& mouse.getPosition(window).x > 50 && mouse.getPosition(window).x < 218
				&& mouse.getPosition(window).y > 613 && mouse.getPosition(window).y < 663)
			{
				char temp[256];
				FILE* fp;
				string leaderboardname[6];
				int leaderboardscore[6];
				vector <pair<int, string>> sorting;
				fp = fopen("./score.txt", "r");
				for (int i = 0; i < 5; i++)
				{
					fscanf(fp, "%s", &temp);
					leaderboardname[i] = temp;
					fscanf(fp, "%d", &leaderboardscore[i]);
					sorting.push_back(make_pair(leaderboardscore[i], leaderboardname[i]));
				}
				leaderboardname[5] = playername;
				leaderboardscore[5] = totalScore;
				sorting.push_back(make_pair(leaderboardscore[5], leaderboardname[5]));
				sort(sorting.begin(), sorting.end());
				for (int i = 0; i < 6; i++)
				{
					cout << sorting[i].second << " " << sorting[i].first << endl;
				}
				fclose(fp);
				fp = fopen("./score.txt", "w");
				for (int i = 5; i > 0; i--)
				{
					strcpy(temp, sorting[i].second.c_str());
					fprintf(fp, "%s %d\n", temp, sorting[i].first);
				}
				fclose(fp);
				STAGE = 3;
				scoreboardupdate = 0;
				for (int i = 0; i < 15; i++)
					playername[i] = { NULL };
			}
			
			// SUBMIT
			if (mouse.getPosition(window).x > 50 && mouse.getPosition(window).x < 218
				&& mouse.getPosition(window).y > 613 && mouse.getPosition(window).y < 663)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					STAGE = 3;

					SCOREA = 0;
					SCOREB = 0;
					SCOREC = 0;

					cantype = 0;
					playernamenow = 0;
					playername[20];
					canbackspace = 0;
					totalScore = 0;
					scoreCheck = 0;
					slimeS = 0;
					batS = 0;
					scoreStatus = 0;
					scoreboardupdate = 0;
					cantype = 0;
					playernamenow = 0;
					playername[20];
					canbackspace = 0;
					backspacetime = 0;

					sword0 = 0;
					shield = 0;
					stopwatch = 0;
					keyPressed = 0;
					bossBullet = 0;
					swordStatus = 0;
					weaponStatus = 0;
					beam = 0;
					laserStatus = 3;
					SWCD = 5;
					immune = 0;
					immuneBlink = 0;
					batImmune = 0;
					slimeImmune = 0;
					dragonImmune = 0;
					weaponSwap = 0;
					sword0 = 0;
					weaponsType = 0;
					bulletNow = 0;
					arrowNow = 0;
					pBulletNow = 0;
					pBulletStatus = 0;
					timeC = 0;
					pause = 0;
					check1 = 0;
					check2 = 0;
					gun = 0;
					pBulletInt = 0;
					playerHealthStatus = 4;
					batHealth = 3;
					slimeHealth = 3;
					skeletonHealth = 3;
					dragonHealth = 0;
					playerAnimationFrame = 0;
					for (int i = 0; i < 110; i++)
					{
						if (i == 110) i = 0;
						pBulletX[i] = { NULL - 1000 };
						pBulletY[i] = { NULL - 1000 };
						pBulletDeg[i] = { 0 };
					}
					cdpb = 0;
					a = 200;
					dragonPosY = 0.0;
					dragonCount = 0;
					for (int i = 0; i < 1100; i++)
					{
						if (i == 1100) i = 0;
						bulletX[i] = { NULL - 1000 };
						bulletY[i] = { NULL - 1000 };
						bulletDeg[i] = { 0 };
					}
					cdr = 0;
					degChange = 0;
					for (int i = 0; i < 10; i++)
					{
						if (i == 10) i = 0;
						arrowX[i] = { NULL - 1000 };
						arrowY[i] = { NULL - 1000 };
					}
					cda = 0;
					batAnimationFrame = 0;
					playerSprite.setPosition(playerSpawnPoint);
					pBullet.setPosition(NULL - 1000, NULL - 1000);
					dragonSprite.setPosition(dragonSpawnpoint);
					chargeBeamSprite.setPosition(780.f, 250.f);
					batSprite.setPosition(batSpawnPoint);
					slimeSprite.setPosition(slimeSpawnPoint);
					itemBoxSprite.setPosition(itemBoxSpawnpoint);

					CTime.setString("12345");
					CTime.setString("12345");
					SCORENow.setString("12345");
					name.setString("12345");
					player1.setString("Player");
					player2.setString("Player");
					player3.setString("Player");
					player4.setString("Player");
					player5.setString("Player");
					score1.setString("12345");
					score2.setString("12345");
					score3.setString("12345");
					score4.setString("12345");
					score5.setString("12345");

				}
				SUBMIT.setScale(0.72f, 0.72f);
				SUBMIT.setColor(sf::Color(255, 255, 255, 255));
			}
			else
			{
				SUBMIT.setScale(0.63f, 0.63f);
				SUBMIT.setColor(sf::Color(255, 255, 255, 200));
			}
			SUBMIT.setPosition(-200.f + ((pauseTexture.getSize().x * pauseMenu.getScale().x) / 2)
				- ((SUBMITTexture.getSize().x / 2) * SUBMIT.getScale().x)
				, 470.f + ((((pauseTexture.getSize().y * 4) / 6) * pauseMenu.getScale().y) / 2)
				- ((SUBMITTexture.getSize().y / 2) * SUBMIT.getScale().y));
			window.draw(SUBMIT);
		}

		// Lose
		if (playerHealthStatus <= 0) STAGE = 5;
		if (STAGE == 5)
		{
			window.draw(menu);
			window.draw(gameOverSprite);

			// SUBMIT
			if (mouse.getPosition(window).x > 830 && mouse.getPosition(window).x < 1034
				&& mouse.getPosition(window).y > 618 && mouse.getPosition(window).y < 651)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					STAGE = 3;

					SCOREA = 0;
					SCOREB = 0;
					SCOREC = 0;

					cantype = 0;
					playernamenow = 0;
					playername[20];
					canbackspace = 0;
					totalScore = 0;
					scoreCheck = 0;
					slimeS = 0;
					batS = 0;
					scoreStatus = 0;
					scoreboardupdate = 0;
					cantype = 0;
					playernamenow = 0;
					playername[20];
					canbackspace = 0;
					backspacetime = 0;

					sword0 = 0;
					shield = 0;
					stopwatch = 0;
					keyPressed = 0;
					bossBullet = 0;
					swordStatus = 0;
					weaponStatus = 0;
					beam = 0;
					laserStatus = 3;
					SWCD = 5;
					immune = 0;
					immuneBlink = 0;
					batImmune = 0;
					slimeImmune = 0;
					dragonImmune = 0;
					weaponSwap = 0;
					sword0 = 0;
					weaponsType = 0;
					bulletNow = 0;
					arrowNow = 0;
					pBulletNow = 0;
					pBulletStatus = 0;
					timeC = 0;
					pause = 0;
					check1 = 0;
					check2 = 0;
					gun = 0;
					pBulletInt = 0;
					playerHealthStatus = 4;
					batHealth = 3;
					slimeHealth = 3;
					skeletonHealth = 3;
					dragonHealth = 0;
					playerAnimationFrame = 0;
					for (int i = 0; i < 110; i++)
					{
						if (i == 110) i = 0;
						pBulletX[i] = { NULL - 1000 };
						pBulletY[i] = { NULL - 1000 };
						pBulletDeg[i] = { 0 };
					}
					cdpb = 0;
					a = 200;
					dragonPosY = 0.0;
					dragonCount = 0;
					for (int i = 0; i < 1100; i++)
					{
						if (i == 1100) i = 0;
						bulletX[i] = { NULL - 1000 };
						bulletY[i] = { NULL - 1000 };
						bulletDeg[i] = { 0 };
					}
					cdr = 0;
					degChange = 0;
					for (int i = 0; i < 10; i++)
					{
						if (i == 10) i = 0;
						arrowX[i] = { NULL - 1000 };
						arrowY[i] = { NULL - 1000 };
					}
					cda = 0;
					batAnimationFrame = 0;
					playerSprite.setPosition(playerSpawnPoint);
					pBullet.setPosition(NULL - 1000, NULL - 1000);
					dragonSprite.setPosition(dragonSpawnpoint);
					chargeBeamSprite.setPosition(780.f, 250.f);
					batSprite.setPosition(batSpawnPoint);
					slimeSprite.setPosition(slimeSpawnPoint);
					itemBoxSprite.setPosition(itemBoxSpawnpoint);

					CTime.setString("12345");
					CTime.setString("12345");
					SCORENow.setString("12345");
					name.setString("12345");
					player1.setString("Player");
					player2.setString("Player");
					player3.setString("Player");
					player4.setString("Player");
					player5.setString("Player");
					score1.setString("12345");
					score2.setString("12345");
					score3.setString("12345");
					score4.setString("12345");
					score5.setString("12345");

				}
				MAINMENU1.setScale(0.35f, 0.35f);
				MAINMENU1.setColor(sf::Color(255, 255, 255, 255));
			}
			else
			{
				MAINMENU1.setScale(0.28f, 0.28f);
				MAINMENU1.setColor(sf::Color(255, 255, 255, 200));
			}
			MAINMENU1.setPosition(600.f + ((pauseTexture.getSize().x * pauseMenu.getScale().x) / 2)
				- ((MAINMENUTexture.getSize().x / 2) * MAINMENU1.getScale().x)
				, 470.f + ((((pauseTexture.getSize().y * 4) / 6) * pauseMenu.getScale().y) / 2)
				- ((MAINMENUTexture.getSize().y / 2) * MAINMENU1.getScale().y));
			window.draw(MAINMENU1);
		}

		// Music
		if ((STAGE == 4 || STAGE == 3) && music == 0)
		{
			epicBossFightBG.stop();
			victoryMusicBG.play();
			music = 1;
		}
		if (STAGE == 0 && mouse.getPosition(window).x > 460 && mouse.getPosition(window).x < 625
			&& mouse.getPosition(window).y > 245 && mouse.getPosition(window).y < 310 && music == 1)
		{
			victoryMusicBG.stop();
			epicBossFightBG.play();
			music = 0;
		}		

		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			check1 = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && check1 == 1)
		{
			if (check2 == 0)
			{
				pause = 1;
				check2 = 1;
			}
			else if (check2 == 1)
			{
				pause = 0;
				check2 = 0;
			}
			check1 = 0;
		}
		std::cout << "X = " << mouse.getPosition(window).x << " Y = " << mouse.getPosition(window).y << std::endl;
		window.display();
	}
	return 0;
}