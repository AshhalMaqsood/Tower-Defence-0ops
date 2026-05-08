#include"Screens.h"
#include<cstdlib>
#include<ctime>
#include<SFML/Audio.hpp>
#include<iostream>
using namespace std;

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));

	static sf::RenderWindow window(sf::VideoMode({ 1280,680 }), "Tower Defence");
	window.setPosition(sf::Vector2i(50, 10));
	window.setFramerateLimit(60);

	if (!menuMusic.openFromFile("assets/menu.mp3")) {
		cout << "Menu Music not loaded" << endl;
	}
	menuMusic.setLooping(true);
	menuMusic.setVolume(70);
	menuMusic.play();

	if (!clickBuffer.loadFromFile("assets/click.mp3")) {
		cout << "Click Music not loaded" << endl;
	}
	clickSound.setBuffer(clickBuffer);

	// game loop
	while (window.isOpen()) {
		int choice = mainMenu(window);
		if (choice == 0) {      // quit
			return 0;
		}
		if (choice == 1) {      // start game 
			while (window.isOpen()) {
				int result = runGame(window);
				if (result == 1) {
					continue;  // retry
				}
				else if (result == 2) {
					break;  // main menu
				}
				else {
					return 0; //quit
				}
			}

		}
		if (choice == 2) {       // guide
			guideScreen(window);
			continue;
		}
	}
	return 0;
}