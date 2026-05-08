#pragma once
#include<SFML/Graphics.hpp>
#include<cmath>

class Bullet {
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2f position;
	sf::Vector2f target;
	float speed;
	bool active;

public:
	Bullet(sf::Vector2f pos, sf::Vector2f tgt);
	void update();
	void render(sf::RenderWindow& window);
	bool isActive() const;
};