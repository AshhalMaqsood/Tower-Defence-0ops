#include"Bullet.h"
#include<iostream>
using namespace std;

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f tgt) : texture("assets/bullet.png"),sprite(texture){
	position = pos;
	target = tgt;
	speed = 8.0f;
	active = true;
	sf::Vector2f textureSize(texture.getSize());
	sprite.setScale(sf::Vector2f(30.0f / textureSize.x, 30.0f / textureSize.y));
	sprite.setOrigin(sf::Vector2f(textureSize.x / 2.0f, textureSize.y / 2.0f));
	sprite.setPosition(position);

	float dx = target.x - position.x;
	float dy = target.y - position.y;
	float angle = atan2(dy, dx) * 180 / 3.14159f;
	sprite.setRotation(sf::degrees(angle));
}
void Bullet::update() {
	if (!active) {
		return;
	}
	sf::Vector2f direction;
	direction.x = target.x - position.x;
	direction.y = target.y - position.y;
	float length = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length < speed) {
		active = false;
		return;
	}
	direction.x /= length;
	direction.y /= length;
	position.x += direction.x * speed;
	position.y += direction.y * speed;
	sprite.setPosition(position);
}
void Bullet::render(sf::RenderWindow& window) {
	if (!active) {
		return;
	}
	window.draw(sprite);
}
bool Bullet::isActive() const {
	return active;
}
