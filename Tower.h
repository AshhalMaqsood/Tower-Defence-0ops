#pragma once
#include"Entity.h"
#include"Enemy.h"
#include"Bullet.h"
#include<SFML/Graphics.hpp>

float getDistance(sf::Vector2f a, sf::Vector2f b);

class Tower :public Entity {
protected:
	int damage;
	float range;
	float cooldown;
	float fireRate;
	sf::Vector2f position;
	Bullet* bullets[30];
	int bulletCount=0;

	void spawnBullet(sf::Vector2f target);
public:
	Tower(int d, float r, sf::Vector2f p);
	int getDamage()const;
	float getRange()const;
	float getCooldown()const;
	float getFireRate()const;
	sf::Vector2f getPosition()const;
	void setDamage(int d);
	void setRange(float r);
	void setFireRate(float f);
	void updateBullets();
	void renderBullets(sf::RenderWindow& window);
	virtual void attack(Enemy* enemy[], int enemyCount) = 0;
	virtual void update()override = 0;
	virtual void render(sf::RenderWindow& window)override = 0;
	virtual~Tower() {
		for (int i = 0; i < bulletCount; i++) {
			delete bullets[i];
			bullets[i] = nullptr;
		}
	}
};
class CannonTower :public Tower {
	sf::Texture texture;
	sf::Sprite sprite;
public:
	CannonTower(sf::Vector2f p);
	void attack(Enemy* enemy[], int enemyCount)override;
	void update()override;
	void render(sf::RenderWindow& window)override;
};
class SniperTower :public Tower {
	sf::Texture texture;
	sf::Sprite sprite;
public:
	SniperTower(sf::Vector2f p);
	void attack(Enemy* enemy[], int enemyCount)override;
	void update()override;
	void render(sf::RenderWindow& window)override;
};
class MachineGunTower :public Tower {
	sf::Texture texture;
	sf::Sprite sprite;
public:
	MachineGunTower(sf::Vector2f p);
	void attack(Enemy* enemy[], int enemyCount)override;
	void update()override;
	void render(sf::RenderWindow& window)override;
};
class SlowTower :public Tower {
	sf::Texture texture;
	sf::Sprite sprite;
public:
	SlowTower(sf::Vector2f p);
	void attack(Enemy* enemy[], int enemyCount)override;
	void update()override;
	void render(sf::RenderWindow& window)override;
};
class ExplosiveTower :public Tower {
	sf::Texture texture;
	sf::Sprite sprite;
public:
	ExplosiveTower(sf::Vector2f p);
	void attack(Enemy* enemy[], int enemyCount)override;
	void update()override;
	void render(sf::RenderWindow& window)override;
};