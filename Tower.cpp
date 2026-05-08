#include<iostream>
#include"Tower.h"
#include<cmath>
using namespace std;

float getDistance(sf::Vector2f a, sf::Vector2f b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}
void Tower::spawnBullet(sf::Vector2f target) {
	if (bulletCount < 30) {
		bullets[bulletCount++] = new Bullet(position, target);
	}
}
Tower::Tower(int d, float r, sf::Vector2f p) {
	damage = d;
	range = r;
	position = p;
	cooldown = 0;
	fireRate = 60;
	for(int i=0;i<30;i++){
		bullets[i] = nullptr;
	}
}
int Tower::getDamage()const {
	return damage;
}
float Tower::getRange()const {
	return range;
}
float Tower::getCooldown()const {
	return cooldown;
}
float Tower::getFireRate()const {
	return fireRate;
}
sf::Vector2f Tower::getPosition()const {
	return position;
}
void Tower::setDamage(int d) {
	if (d >= 0) {
		damage = d;
	}
}
void Tower::setRange(float r) {
	if (r > 0) {
		range = r;
	}
}
void Tower::setFireRate(float f) {
	if (f > 0) {
		fireRate = f;
	}
}
void Tower::updateBullets() {
	for (int i = 0; i < bulletCount; i++) {
		if (bullets[i] == nullptr) {
			continue;
		}
		bullets[i]->update();
		if (!bullets[i]->isActive()) {
			delete bullets[i];
			bullets[i] = nullptr;
			for (int j = i; j < bulletCount - 1; j++) {
				bullets[j] = bullets[j + 1];
			}
			bulletCount--;
			i--;
		}
	}
}
void Tower::renderBullets(sf::RenderWindow& window) {
	for (int i = 0; i < bulletCount; i++) {
		bullets[i]->render(window);
	}
}

CannonTower::CannonTower(sf::Vector2f p) :Tower(20, 100.0, p), texture("assets/cannon_tower.png"), sprite(texture) {
	sf::Vector2u texSize = texture.getSize();
	sprite.setScale(sf::Vector2f(100.0f / texSize.x, 100.0f / texSize.y));
	sprite.setOrigin(sf::Vector2f(150, 150));
	sprite.setPosition(position);
}
void CannonTower::attack(Enemy* enemy[], int enemyCount) {
	if (cooldown > 0) {
		return;
	}
	Enemy* target = nullptr;
	for (int i = 0; i < enemyCount; i++) {
		if (enemy[i]->isDead()) {
			continue;
		}
		float dist = getDistance(position, enemy[i]->getPosition());
		if (dist <= range) {
			if (target == nullptr || *enemy[i] > *target) {
				target = enemy[i];
			}
		}
	}
	if (target != nullptr) {
		spawnBullet(target->getPosition());
		target->takeDamage(damage);
		cooldown = fireRate;
		cout << "Cannon Hit! HP: " << target->getHP() << endl;
	}
}
void CannonTower::update() {
	if (cooldown > 0) {
		cooldown--;
	}
}
void CannonTower::render(sf::RenderWindow& window) {
	sprite.setPosition(position);
	window.draw(sprite);
}

SniperTower::SniperTower(sf::Vector2f p) :Tower(60, 300.0, p), texture("assets/sniper.png"), sprite(texture) {
	sf::Vector2u texSize = texture.getSize();
	sprite.setScale(sf::Vector2f(80.0f / texSize.x, 80.0f / texSize.y));
	sprite.setOrigin(sf::Vector2f(150, 150));
	sprite.setPosition(position);
}
void SniperTower::attack(Enemy* enemy[], int enemyCount) {
	if (cooldown > 0) {
		return;
	}
	Enemy* target = nullptr;
	float maxDist = range;
	for (int i = 0; i < enemyCount; i++) {
		if (enemy[i]->isDead()) {
			continue;
		}
		float dist = getDistance(position, enemy[i]->getPosition());
		if (dist <= maxDist) {
			maxDist = dist;
			target = enemy[i];
		}
	}
	if (target) {
		spawnBullet(target->getPosition());
		target->takeDamage(damage);
		cooldown = fireRate * 2;
		cout << "Sniper Hit! HP: " << target->getHP() << endl;
	}

}
void SniperTower::update() {
	if (cooldown > 0) {
		cooldown--;
	}
}
void SniperTower::render(sf::RenderWindow& window) {
	sprite.setPosition(position);
	window.draw(sprite);
}

MachineGunTower::MachineGunTower(sf::Vector2f p) :Tower(5, 120.0f, p), texture("assets/machine_gun.png"), sprite(texture) {
	sf::Vector2u texSize = texture.getSize();
	sprite.setScale(sf::Vector2f(100.0f / texSize.x, 100.0f / texSize.y));
	sprite.setOrigin(sf::Vector2f(150, 150));
	sprite.setPosition(position);
	fireRate = 10;
}
void MachineGunTower::attack(Enemy* enemy[], int enemyCount) {
	if (cooldown > 0) {
		return;
	}
	bool shot = false;
	for (int i = 0; i < enemyCount; i++) {
		if (enemy[i]->isDead()) {
			continue;
		}
		float dist = getDistance(position, enemy[i]->getPosition());
		if (dist <= range) {
			spawnBullet(enemy[i]->getPosition());
			enemy[i]->takeDamage(damage);
			shot = true;
		}
	}
	if (shot) {
		cooldown = fireRate;
	}
}
void MachineGunTower::update() {
	if (cooldown > 0) {
		cooldown--;
	}
}
void MachineGunTower::render(sf::RenderWindow& window) {
	sprite.setPosition(position);
	window.draw(sprite);
}

SlowTower::SlowTower(sf::Vector2f p) :Tower(0, 140.0, p), texture("assets/slow_tower.png"), sprite(texture) {
	sf::Vector2u texSize = texture.getSize();
	sprite.setScale(sf::Vector2f(100.0f / texSize.x, 100.0f / texSize.y));
	sprite.setOrigin(sf::Vector2f(150, 150));
	sprite.setPosition(position);
	fireRate = 30;
}
void SlowTower::attack(Enemy* enemy[], int enemyCount) {
	for (int i = 0; i < enemyCount; i++) {
		if (enemy[i]->isDead()) {
			continue;
		}
		float dist = getDistance(position, enemy[i]->getPosition());
		if (dist <= range) {
			spawnBullet(enemy[i]->getPosition());
			enemy[i]->slow(0.5f);
			cout << "Slow tower   Hit! HP: " << enemy[i]->getHP() << endl;
		}
	}
}
void SlowTower::update() {
	if (cooldown > 0) {
		cooldown--;
	}
}
void SlowTower::render(sf::RenderWindow& window) {
	sprite.setPosition(position);
	window.draw(sprite);
}

ExplosiveTower::ExplosiveTower(sf::Vector2f p) :Tower(40, 110.0, p), texture("assets/explosive.png"), sprite(texture) {
	sf::Vector2u texSize = texture.getSize();
	sprite.setScale(sf::Vector2f(100.0f / texSize.x, 100.0f / texSize.y));
	sprite.setOrigin(sf::Vector2f(150, 150));
	sprite.setPosition(position);
	fireRate = 90;
}
void ExplosiveTower::attack(Enemy* enemy[], int enemyCount) {
	if (cooldown > 0) {
		return;
	}
	bool hit = false;
	for (int i = 0; i < enemyCount; i++) {
		if (enemy[i]->isDead()) {
			continue;
		}
		float dist = getDistance(position, enemy[i]->getPosition());
		if (dist <= range) {
			spawnBullet(enemy[i]->getPosition());
			enemy[i]->takeDamage(damage);
			hit = true;
		}
	}
	if (hit) {
		cooldown = fireRate;
	}
}
void ExplosiveTower::update() {
	if (cooldown > 0) {
		cooldown--;
	}
}
void ExplosiveTower::render(sf::RenderWindow& window) {
	sprite.setPosition(position);
	window.draw(sprite);
}