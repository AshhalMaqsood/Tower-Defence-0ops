#include<iostream>
#include<cmath>
#include"Enemy.h"
using namespace std;

Enemy::Enemy(int h, float s, sf::Vector2f p) {
	hp = h;
	maxHP = h;
	speed = s;
	orgspeed = speed;
	position = p;
}
void Enemy::setPath(sf::Vector2f p[], int size) {
	for (int i = 0; i < size; i++) {
		path[i] = p[i];
	}
	pathsize = size;
	currenttarget = 0;
}
void Enemy::takeDamage(int d) {
	hp = hp - d;
}
bool Enemy::isDead() {
	return (hp <= 0);
}
int Enemy::getHP()const {
	return hp;
}
sf::Vector2f Enemy::getPosition()const {
	return position;
}
bool Enemy::reachedEnd() {
	return (currenttarget >= pathsize);
}
void Enemy::resetSpeed() {
	speed = orgspeed;
}
void Enemy::slow(float f) {
	speed = orgspeed * f;
}
bool Enemy::operator>(const Enemy& rhs)const {
	if (hp != rhs.hp) {
		return hp > rhs.hp;
	}
	return speed < rhs.speed;
}
int Enemy::getCurrentTarget()const {
	return currenttarget;
}
void Enemy::hpbar(sf::RenderWindow& window) {
	float maxHpF = (float)this->maxHP;
	sf::Vector2f barPos = position;
	barPos.y -= 10;
	float width = 40;
	float height = 5.0f;

	float hpPercent = (float)hp / maxHP;
	if (hpPercent < 0) {
		hpPercent = 0;
	}

	sf::RectangleShape hpBar(sf::Vector2f(width, height));
	hpBar.setFillColor(sf::Color::Red);
	hpBar.setPosition(barPos);

	sf::RectangleShape Bar(sf::Vector2f(width * hpPercent, height));
	Bar.setFillColor(sf::Color::Green);
	Bar.setPosition(barPos);

	window.draw(hpBar);
	window.draw(Bar);

}
BasicEnemy::BasicEnemy(sf::Vector2f p) :Enemy(100, 2.0, p), texture("assets/basic_enemy.png"), sprite(texture) {
	sf::Vector2u texSize = texture.getSize();
	sprite.setScale(sf::Vector2f(70.0f / texSize.x, 70.0f / texSize.y));
	sprite.setOrigin(sf::Vector2f(200, 200));
	sprite.setPosition(position);
}
void BasicEnemy::takeDamage(int d){
	Enemy::takeDamage(d);
}
void BasicEnemy::move(){
	if (currenttarget >= pathsize) {
		return;
	}
	sf::Vector2f target = path[currenttarget];
	sf::Vector2f direction;
	direction.x = target.x - position.x;
	direction.y = target.y - position.y;

	float len = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (len < speed) {
		position = target;
		currenttarget++;
		return;
	}
	direction.x = direction.x / len;
	direction.y = direction.y / len;

	position.x += direction.x * speed;
	position.y += direction.y * speed;

}
void BasicEnemy::update(){
	move();
}
void BasicEnemy::render(sf::RenderWindow& window){
	sprite.setPosition(position);
	window.draw(sprite);
	hpbar(window);
}

FastEnemy::FastEnemy(sf::Vector2f p) :Enemy(50, 4.0f, p), texture("assets/fast_enemy.png"), sprite(texture) {
	sf::Vector2u texSize = texture.getSize();
	sprite.setScale(sf::Vector2f(70.0f / texSize.x, 70.0f / texSize.y));
	sprite.setOrigin(sf::Vector2f(150, 150));
	sprite.setPosition(position);
}
void FastEnemy::takeDamage(int d) {
	Enemy::takeDamage(d);
}
void FastEnemy::move() {
	if (currenttarget >= pathsize) {
		return;
	}
	sf::Vector2f target = path[currenttarget];
	sf::Vector2f direction;
	direction.x = target.x - position.x;
	direction.y = target.y - position.y;

	float len = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (len < speed) {
		position = target;
		currenttarget++;
		return;
	}
	direction.x = direction.x / len;
	direction.y = direction.y / len;

	position.x += direction.x * speed;
	position.y += direction.y * speed;

}
void FastEnemy::update() {
	move();
}
void FastEnemy::render(sf::RenderWindow& window) {
	sprite.setPosition(position);
	window.draw(sprite);
	hpbar(window);
}


TankEnemy::TankEnemy(sf::Vector2f p) :Enemy(300, 1.2f, p), texture("assets/tank_enemy.png"), sprite(texture) {
	sf::Vector2u texSize = texture.getSize();
	sprite.setScale(sf::Vector2f(70.0f / texSize.x, 70.0f / texSize.y));
	sprite.setOrigin(sf::Vector2f(150, 150));
	sprite.setPosition(position);
}
void TankEnemy:: takeDamage(int d) {
	Enemy::takeDamage(d);
}
void TankEnemy::move() {
	if (currenttarget >= pathsize) {
		return;
	}
	sf::Vector2f target = path[currenttarget];
	sf::Vector2f direction;
	direction.x = target.x - position.x;
	direction.y = target.y - position.y;

	float len = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (len < speed) {
		position = target;
		currenttarget++;
		return;
	}
	direction.x = direction.x / len;
	direction.y = direction.y / len;

	position.x += direction.x * speed;
	position.y += direction.y * speed;

}
void TankEnemy::update() {
	move();
}
void TankEnemy::render(sf::RenderWindow& window) {
	sprite.setPosition(position);
	window.draw(sprite);
	hpbar(window);
}

FlyingEnemy::FlyingEnemy(sf::Vector2f p) :Enemy(70, 3.0f, p), texture("assets/flying_enemy.png"), sprite(texture) {
	sf::Vector2u texSize = texture.getSize();
	sprite.setScale(sf::Vector2f(70.0f / texSize.x, 70.0f / texSize.y));
	sprite.setOrigin(sf::Vector2f(300, 140));
	sprite.setPosition(position);
}
void FlyingEnemy::takeDamage(int d) {
	Enemy::takeDamage(d);
}
void FlyingEnemy::move() {
	if (/*pathsize == 0 || */currenttarget >= pathsize) { // uncomment pathsize==0 for enemy to g straight to end
		return;
	}
	sf::Vector2f target = path[currenttarget];
	// sf::Vector2f target = path[pathsize - 1]; // go straight to end
	sf::Vector2f direction;
	direction.x = target.x - position.x;
	direction.y = target.y - position.y;

	float len = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (len < speed) {
		position = target;
		// currenttarget = pathsize;  // go straight to end
		currenttarget++;
		return;
	}
	direction.x = direction.x / len;
	direction.y = direction.y / len;

	position.x += direction.x * speed;
	position.y += direction.y * speed;

}
void FlyingEnemy::update() {
	move();
}
void FlyingEnemy::render(sf::RenderWindow& window) {
	sprite.setPosition(position);
	window.draw(sprite);
	hpbar(window);
}

ShieldEnemy::ShieldEnemy(sf::Vector2f p) :Enemy(150, 2.0, p), texture("assets/shield_enemy.png"), sprite(texture) {
	sf::Vector2u texSize = texture.getSize();
	sprite.setScale(sf::Vector2f(70.0f / texSize.x, 70.0f / texSize.y));
	sprite.setOrigin(sf::Vector2f(100, 100));
	sprite.setPosition(position);
}
void ShieldEnemy::move() {
	if (currenttarget >= pathsize) {
		return;
	}
	sf::Vector2f target = path[currenttarget];
	sf::Vector2f direction;
	direction.x = target.x - position.x;
	direction.y = target.y - position.y;

	float len = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (len < speed) {
		position = target;
		currenttarget++;
		return;
	}
	direction.x = direction.x / len;
	direction.y = direction.y / len;

	position.x += direction.x * speed;
	position.y += direction.y * speed;

}
void ShieldEnemy::takeDamage(int d) {
	hp -= (d / 2);
}
void ShieldEnemy::update() {
	move();
}
void ShieldEnemy::render(sf::RenderWindow& window) {
	sprite.setPosition(position);
	window.draw(sprite);
	hpbar(window);
}