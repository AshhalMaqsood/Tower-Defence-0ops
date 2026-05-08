#include"Screens.h"
#include"Enemy.h"
#include"Tower.h"
#include"Bullet.h"
#include<SFML/Audio.hpp>
#include<cstdlib>
#include<iostream>

using namespace std;

const int gridSize = 64;
sf::Vector2f snapToGrid(sf::Vector2f pos) {
	int x = (int(pos.x) / gridSize) * gridSize;
	int y = (int(pos.y) / gridSize) * gridSize;
	return sf::Vector2f(static_cast<float>(x), static_cast<float>(y));
}

int mainMenu(sf::RenderWindow& window) {

	menuMusic.play();
	sf::Texture bgTexture;
	if (!bgTexture.loadFromFile("assets/start_screen.png")) {
		cout << "Background not loaded" << endl;
	}
	sf::Sprite bg(bgTexture);
	bg.setScale(sf::Vector2f(1280.0f / bgTexture.getSize().x, 680.0f / bgTexture.getSize().y));

	sf::RectangleShape b1(sf::Vector2f(240, 60));
	b1.setPosition(sf::Vector2f(520, 315));
	b1.setFillColor(sf::Color(200, 200, 0));
	sf::RectangleShape b2(sf::Vector2f(240, 50));
	b2.setPosition(sf::Vector2f(520, 410));
	b2.setFillColor(sf::Color(200, 200, 0));
	sf::RectangleShape b3(sf::Vector2f(240, 50));
	b3.setPosition(sf::Vector2f(520, 490));
	b3.setFillColor(sf::Color(200, 200, 0));

	while (window.isOpen()) {
		while (auto event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
			if (event->is<sf::Event::MouseButtonPressed>()) {
				auto mouseEvent = event->getIf<sf::Event::MouseButtonPressed>();
				if (!mouseEvent) {
					continue;
				}
				if (mouseEvent && mouseEvent->button == sf::Mouse::Button::Left) {
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

					if (b1.getGlobalBounds().contains(worldPos)) {
						clickSound.play();
						return 1;
					}
					else if (b2.getGlobalBounds().contains(worldPos)) {
						clickSound.play();
						return 2;
					}
					else if (b3.getGlobalBounds().contains(worldPos)) {
						clickSound.play();
						return 0;
					}
				}
			}
		}
		window.draw(bg);
		window.display();
	}
	return 0;
}
int gameOverScreen(sf::RenderWindow& window) {
	sf::Texture bgTexture;
	if (!bgTexture.loadFromFile("assets/game_over_screen.png")) {
		cout << "Background not loaded" << endl;
	}
	sf::Sprite bg(bgTexture);
	bg.setScale(sf::Vector2f(1280.0f / bgTexture.getSize().x, 680.0f / bgTexture.getSize().y));


	sf::RectangleShape b1(sf::Vector2f(240, 60));
	b1.setPosition(sf::Vector2f(520, 315));
	b1.setFillColor(sf::Color(200, 200, 0));
	sf::RectangleShape b2(sf::Vector2f(240, 50));
	b2.setPosition(sf::Vector2f(520, 410));
	b2.setFillColor(sf::Color(200, 200, 0));
	sf::RectangleShape b3(sf::Vector2f(240, 50));
	b3.setPosition(sf::Vector2f(520, 490));
	b3.setFillColor(sf::Color(200, 200, 0));

	while (window.isOpen()) {
		while (auto event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
				return 0;
			}
			if (event->is<sf::Event::MouseButtonPressed>()) {
				auto mouseEvent = event->getIf<sf::Event::MouseButtonPressed>();
				if (mouseEvent && mouseEvent->button == sf::Mouse::Button::Left) {
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

					if (b1.getGlobalBounds().contains(worldPos)) {
						clickSound.play();
						return 1;  // retry
					}
					else if (b2.getGlobalBounds().contains(worldPos)) {
						clickSound.play();
						return 2;  // main menu
					}
					else if (b3.getGlobalBounds().contains(worldPos)) {
						clickSound.play();
						return 0;  // quit
					}
				}
			}
		}
		window.draw(bg);
		window.display();
	}
	return 0;
}
int winScreen(sf::RenderWindow& window) {
	sf::Texture bgTexture;
	if (!bgTexture.loadFromFile("assets/win_screen.png")) {
		cout << "Background not loaded" << endl;
	}
	sf::Sprite bg(bgTexture);
	bg.setScale(sf::Vector2f(1280.0f / bgTexture.getSize().x, 680.0f / bgTexture.getSize().y));

	sf::RectangleShape b1(sf::Vector2f(240, 60));
	b1.setPosition(sf::Vector2f(520, 315));
	b1.setFillColor(sf::Color(200, 200, 0));
	sf::RectangleShape b2(sf::Vector2f(240, 50));
	b2.setPosition(sf::Vector2f(520, 410));
	b2.setFillColor(sf::Color(200, 200, 0));

	while (window.isOpen()) {
		while (auto event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
				return 0;
			}
			if (event->is<sf::Event::MouseButtonPressed>()) {
				auto mouseEvent = event->getIf<sf::Event::MouseButtonPressed>();
				if (mouseEvent && mouseEvent->button == sf::Mouse::Button::Left) {
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

					if (b1.getGlobalBounds().contains(worldPos)) {
						clickSound.play();
						return 1;  // retry
					}
					else if (b2.getGlobalBounds().contains(worldPos)) {
						clickSound.play();
						return 0;  // quit
					}
				}
			}
		}
		window.clear();
		window.draw(bg);
		window.display();
	}
	return 0;
}
int pauseMenu(sf::RenderWindow& window) {
	sf::Texture bgTexture;
	if (!bgTexture.loadFromFile("assets/pause_screen.png")) {
		cout << "Background not loaded" << endl;
	}
	sf::Sprite bg(bgTexture);
	bg.setScale(sf::Vector2f(1280.0f / bgTexture.getSize().x, 680.0f / bgTexture.getSize().y));


	sf::RectangleShape b1(sf::Vector2f(240, 60));
	b1.setPosition(sf::Vector2f(520, 315));
	b1.setFillColor(sf::Color(200, 200, 0));
	sf::RectangleShape b2(sf::Vector2f(240, 50));
	b2.setPosition(sf::Vector2f(520, 410));
	b2.setFillColor(sf::Color(200, 200, 0));
	sf::RectangleShape b3(sf::Vector2f(240, 50));
	b3.setPosition(sf::Vector2f(520, 490));
	b3.setFillColor(sf::Color(200, 200, 0));

	while (window.isOpen()) {
		while (auto event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
				return 0;
			}
			if (event->is<sf::Event::KeyPressed>()) {
				auto key = event->getIf<sf::Event::KeyPressed>();
				if (key && key->code == sf::Keyboard::Key::Escape) {
					return 1;
				}
			}
			if (event->is<sf::Event::MouseButtonPressed>()) {
				auto mouseEvent = event->getIf<sf::Event::MouseButtonPressed>();
				if (mouseEvent && mouseEvent->button == sf::Mouse::Button::Left) {
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

					if (b1.getGlobalBounds().contains(worldPos)) {
						clickSound.play();
						return 1;  // resume
					}
					else if (b2.getGlobalBounds().contains(worldPos)) {
						clickSound.play();
						return 2;  // main menu
					}
					else if (b3.getGlobalBounds().contains(worldPos)) {
						clickSound.play();
						return 0;  // quit
					}
				}
			}
		}
		window.draw(bg);
		window.display();
	}
	return 0;
}
int guideScreen(sf::RenderWindow& window) {
	sf::Texture bgTexture;
	if (!bgTexture.loadFromFile("assets/guide_screen.png")) {
		cout << "Background not loaded" << endl;
	}
	sf::Sprite bg(bgTexture);
	bg.setScale(sf::Vector2f(1280.0f / bgTexture.getSize().x, 680.0f / bgTexture.getSize().y));

	sf::RectangleShape b1(sf::Vector2f(150, 40));
	b1.setPosition(sf::Vector2f(565, 600));
	b1.setFillColor(sf::Color(200, 200, 0));

	while (window.isOpen()) {
		while (auto event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
				return 0;
			}

			if (event->is<sf::Event::MouseButtonPressed>()) {
				auto mouseEvent = event->getIf<sf::Event::MouseButtonPressed>();
				if (mouseEvent && mouseEvent->button == sf::Mouse::Button::Left) {
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

					if (b1.getGlobalBounds().contains(worldPos)) {
						clickSound.play();
						return 2;
					}
				}
			}
		}
		window.draw(bg);
		window.display();
	}
	return 0;
}
int runGame(sf::RenderWindow& window) {
	int gameState = 0;
	sf::Font font;
	if (!font.openFromFile("fonts/arial.ttf")) {
		cout << "Font not loaded" << endl;
		return 0;
	}
	gameState = 1;

	sf::RectangleShape b1(sf::Vector2f(240, 80));
	b1.setPosition(sf::Vector2f(1020, 45));
	b1.setFillColor(sf::Color(200, 200, 0));
	sf::RectangleShape b2(sf::Vector2f(240, 80));
	b2.setPosition(sf::Vector2f(1020, 140));
	b2.setFillColor(sf::Color(200, 200, 0));
	sf::RectangleShape b3(sf::Vector2f(240, 80));
	b3.setPosition(sf::Vector2f(1020, 240));
	b3.setFillColor(sf::Color(200, 200, 0));
	sf::RectangleShape b4(sf::Vector2f(240, 80));
	b4.setPosition(sf::Vector2f(1020, 335));
	b4.setFillColor(sf::Color(200, 200, 0));
	sf::RectangleShape b5(sf::Vector2f(240, 80));
	b5.setPosition(sf::Vector2f(1020, 430));
	b5.setFillColor(sf::Color(200, 200, 0));

	//path of enemy
	sf::Vector2f path[6];
	path[0] = { 120,160 };
	path[1] = { 710,160 };
	path[2] = { 710,330 };
	path[3] = { 160,330 };
	path[4] = { 160,530 };
	path[5] = { 880,530 };

	sf::Texture bgTexture;
	if (!bgTexture.loadFromFile("assets/backgroundmap.png")) {
		cout << "Background not loaded" << endl;
	}
	sf::Sprite bg(bgTexture);
	bg.setScale(sf::Vector2f(1280.0f / bgTexture.getSize().x, 680.0f / bgTexture.getSize().y));

	sf::Texture panelTexture;
	if (!panelTexture.loadFromFile("assets/panel.png")) {
		cout << "Panel not loaded" << endl;
	}
	sf::Sprite panel(panelTexture);
	panel.setScale(sf::Vector2f(280.0f / panelTexture.getSize().x, 680.0f / panelTexture.getSize().y));
	panel.setPosition(sf::Vector2f(1000, 0));

	// Enemies
	Enemy* enemies[50];
	int enemyCount = 0;

	int wave = 1;
	int enemiesToSpawn = 5;
	int spawnTimer = 0;
	int spawnDelay = 120;
	int lives = 10;
	int money = 300;

	// Towers
	Tower* towers[100];
	int towerCount = 0;

	int selectedTower = 0;
	bool canPlace = true;
	int cannon_cost = 100;
	int sniper_cost = 150;
	int machinegun_cost = 120;
	int slowtower_cost = 130;
	int explosive_cost = 180;

	sf::Text uiText(font, "Loading..", 20);
	uiText.setFillColor(sf::Color::White);

	sf::Music bgMusic;
	sf::SoundBuffer killBuffer;
	sf::SoundBuffer placeBuffer;
	sf::SoundBuffer gameoverBuffer;

	if (!bgMusic.openFromFile("assets/background.mp3")) {
		cout << "BackGround Music not loaded" << endl;
	}
	bgMusic.setLooping(true);
	bgMusic.setVolume(70);

	if (!killBuffer.loadFromFile("assets/kill.mp3")) {
		cout << "Kill Music not loaded" << endl;
	}
	if (!placeBuffer.loadFromFile("assets/tower_place.mp3")) {
		cout << "Tower Place Music not loaded" << endl;
	}
	if (!gameoverBuffer.loadFromFile("assets/gameover.mp3")) {
		cout << "Gameover Music not loaded" << endl;
	}
	sf::Sound killSound(killBuffer);
	sf::Sound placeSound(placeBuffer);
	sf::Sound gameOverSound(gameoverBuffer);


	menuMusic.stop();
	bgMusic.play();
	// game loop
	while (window.isOpen()) {
		while (auto event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
				cout << "Window Closed" << endl;
				bgMusic.stop();
				for (int i = 0; i < enemyCount; i++) {
					delete enemies[i];
					enemies[i] = nullptr;
				}
				enemyCount = 0;

				for (int i = 0; i < towerCount; i++) {
					delete towers[i];
					towers[i] = nullptr;
				}
				towerCount = 0;
				return 0;
			}
			if (event->is<sf::Event::KeyPressed>()) {
				auto key = event->getIf<sf::Event::KeyPressed>();
				if (key && key->code == sf::Keyboard::Key::Escape) {
					int r = pauseMenu(window);

					if (r == 1) {
						clickSound.play();
						// resume;
					}
					else if (r == 2) {
						clickSound.play();
						bgMusic.stop();
						for (int i = 0; i < enemyCount; i++) {
							delete enemies[i];
							enemies[i] = nullptr;
						}
						enemyCount = 0;

						for (int i = 0; i < towerCount; i++) {
							delete towers[i];
							towers[i] = nullptr;
						}
						towerCount = 0;
						return 2;
					}
					else {
						clickSound.play();
						bgMusic.stop();
						for (int i = 0; i < enemyCount; i++) {
							delete enemies[i];
							enemies[i] = nullptr;
						}
						enemyCount = 0;

						for (int i = 0; i < towerCount; i++) {
							delete towers[i];
							towers[i] = nullptr;
						}
						towerCount = 0;
						return 0;
					}
				}
			}

			if (event->is<sf::Event::MouseButtonPressed>()) {
				auto mouseEvent = event->getIf<sf::Event::MouseButtonPressed>();
				if (mouseEvent && mouseEvent->button == sf::Mouse::Button::Left && canPlace) {
					canPlace = false;
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

					if (b1.getGlobalBounds().contains(worldPos)) {
						clickSound.play();
						selectedTower = 1;
						cout << "Cannon Selected" << endl;
					}
					else if (b2.getGlobalBounds().contains(worldPos)) {
						clickSound.play();
						selectedTower = 2;
						cout << "Sniper Selected" << endl;
					}
					else if (b3.getGlobalBounds().contains(worldPos)) {
						clickSound.play();
						selectedTower = 3;
						cout << "Machine Gun Selected" << endl;
					}
					else if (b4.getGlobalBounds().contains(worldPos)) {
						clickSound.play();
						selectedTower = 4;
						cout << "SlowTower Selected" << endl;
					}
					else if (b5.getGlobalBounds().contains(worldPos)) {
						clickSound.play();
						selectedTower = 5;
						cout << "Explosive Tower Selected" << endl;
					}
					else if (worldPos.x < 1000) {
						sf::Vector2f snappedPos = snapToGrid(worldPos);
						if (towerCount < 100) {
							if (selectedTower == 1 && money >= cannon_cost) {
								towers[towerCount++] = new CannonTower(snappedPos);
								money -= cannon_cost;
								placeSound.play();
								cout << "Tower Placed - Money: " << money << endl;
							}
							else if (selectedTower == 2 && money >= sniper_cost) {
								towers[towerCount++] = new SniperTower(snappedPos);
								money -= sniper_cost;
								placeSound.play();
								cout << "Tower Placed - Money: " << money << endl;
							}
							else if (selectedTower == 3 && money >= machinegun_cost) {
								towers[towerCount++] = new MachineGunTower(snappedPos);
								money -= machinegun_cost;
								placeSound.play();
								cout << "Tower Placed - Money: " << money << endl;
							}
							else if (selectedTower == 4 && money >= slowtower_cost) {
								towers[towerCount++] = new SlowTower(snappedPos);
								money -= slowtower_cost;
								placeSound.play();
								cout << "Tower Placed - Money: " << money << endl;
							}
							else if (selectedTower == 5 && money >= explosive_cost) {
								towers[towerCount++] = new ExplosiveTower(snappedPos);
								money -= explosive_cost;
								placeSound.play();
								cout << "Tower Placed - Money: " << money << endl;
							}
							else {
								cout << "Not enough Money" << endl;
							}

						}

					}

				}
			}
		}
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			canPlace = true;
		}
		window.clear(sf::Color::Blue); // backgrond
		window.draw(bg);
		window.draw(panel);

		spawnTimer++;
		if (spawnTimer >= spawnDelay) {
			spawnTimer = 0;
			if (enemiesToSpawn > 0 && enemyCount < 50) {
				Enemy* e = nullptr;
				int enemyType = rand() % 5;
				if (enemyType == 0) {
					e = new BasicEnemy({ 120,160 });
				}
				else if (enemyType == 1) {
					e = new FastEnemy({ 120,160 });
				}
				else if (enemyType == 2) {
					e = new TankEnemy({ 120,160 });
				}
				else if (enemyType == 3) {
					e = new FlyingEnemy({ 120,160 });
				}
				else {
					e = new ShieldEnemy({ 120,160 });
				}

				e->setPath(path, 6);
				enemies[enemyCount++] = e;
				enemiesToSpawn--;
			}
		}
		for (int i = 0; i < enemyCount; i++) {
			enemies[i]->resetSpeed();
		}
		for (int i = 0; i < towerCount; i++) {
			towers[i]->update();
			towers[i]->attack(enemies, enemyCount);
			towers[i]->updateBullets();
		}
		//Enemies
		for (int i = 0; i < enemyCount; i++) {
			if (!enemies[i]->isDead()) {
				enemies[i]->update();
			}
			if (enemies[i]->isDead() || enemies[i]->reachedEnd()) {
				if (enemies[i]->isDead()) {
					money += 25;
					killSound.play();
					cout << "Enemy Killed- 25 Money Added- Money: " << money << endl;
				}
				if (enemies[i]->reachedEnd()) {
					lives--;
					cout << "Lives: " << lives << endl;
				}
				if (lives <= 0) {
					gameState = 2;
					cout << "Game Over" << endl;
				}
				delete enemies[i];

				for (int j = i; j < enemyCount - 1; j++) {
					enemies[j] = enemies[j + 1];
				}
				enemyCount--;
				i--;
				continue;
			}
			enemies[i]->render(window);
		}
		if (enemyCount == 0 && enemiesToSpawn == 0) {
			if (wave >= 10) {
				gameState = 3;
			}
			else {
				wave++;
				enemiesToSpawn = 5 + wave * 2;
				spawnDelay -= 10;
				if (spawnDelay < 40) {
					spawnDelay = 40;
				}
				cout << "Wave: " << wave << endl;
			}
		}
		if (gameState == 2) {
			gameOverSound.play();
			bgMusic.stop();
			int r = gameOverScreen(window);
			for (int i = 0; i < enemyCount; i++) {
				delete enemies[i];
				enemies[i] = nullptr;
			}
			enemyCount = 0;

			for (int i = 0; i < towerCount; i++) {
				delete towers[i];
				towers[i] = nullptr;
			}
			towerCount = 0;

			if (r == 1) {
				return 1;
			}
			if (r == 2) {
				return 2;
			}
			else {
				return 0;
			}
		}
		if (gameState == 3) {
			gameOverSound.play();
			bgMusic.stop();
			int r = winScreen(window);
			for (int i = 0; i < enemyCount; i++) {
				delete enemies[i];
				enemies[i] = nullptr;
			}
			enemyCount = 0;

			for (int i = 0; i < towerCount; i++) {
				delete towers[i];
				towers[i] = nullptr;
			}
			towerCount = 0;
			if (r == 1) {
				return 2;  // mainmenu
			}
			else {
				return 0;  // quit
			}
		}
		// Tower
		for (int i = 0; i < towerCount; i++) {
			towers[i]->render(window);
			towers[i]->renderBullets(window);
		}
		uiText.setString(to_string(cannon_cost));
		uiText.setPosition(sf::Vector2f(1135, 105));
		uiText.setCharacterSize(15);
		window.draw(uiText);
		uiText.setString(to_string(sniper_cost));
		uiText.setPosition(sf::Vector2f(1135, 205));
		uiText.setCharacterSize(15);
		window.draw(uiText);
		uiText.setString(to_string(machinegun_cost));
		uiText.setPosition(sf::Vector2f(1135, 302));
		uiText.setCharacterSize(15);
		window.draw(uiText);
		uiText.setString(to_string(slowtower_cost));
		uiText.setPosition(sf::Vector2f(1135, 400));
		uiText.setCharacterSize(15);
		window.draw(uiText);
		uiText.setString(to_string(explosive_cost));
		uiText.setPosition(sf::Vector2f(1135, 497));
		uiText.setCharacterSize(15);
		window.draw(uiText);

		uiText.setString(to_string(lives));
		uiText.setPosition(sf::Vector2f(1135, 635));
		uiText.setCharacterSize(20);
		window.draw(uiText);
		uiText.setString(to_string(money));
		uiText.setPosition(sf::Vector2f(1040, 635));
		uiText.setCharacterSize(20);
		window.draw(uiText);
		uiText.setString("WAVE: " + to_string(wave));
		uiText.setPosition(sf::Vector2f(1100, 560));
		uiText.setCharacterSize(20);
		window.draw(uiText);
		window.display();
	}
	cout << "Game Ended" << endl;
	for (int i = 0; i < enemyCount; i++) {
		delete enemies[i];
		enemies[i] = nullptr;
	}
	enemyCount = 0;

	for (int i = 0; i < towerCount; i++) {
		delete towers[i];
		towers[i] = nullptr;
	}
	towerCount = 0;
	return 0;
}