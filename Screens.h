#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

inline sf::Music menuMusic;
inline sf::SoundBuffer clickBuffer;
inline sf::Sound clickSound(clickBuffer);

int mainMenu(sf::RenderWindow& window);
int gameOverScreen(sf::RenderWindow& window);
int winScreen(sf::RenderWindow& window);
int pauseMenu(sf::RenderWindow& window);
int guideScreen(sf::RenderWindow& window);
int runGame(sf::RenderWindow& window);

