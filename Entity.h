#pragma once
#include<SFML/Graphics.hpp>
class Entity {
public:
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual~Entity() {}
};
