#pragma once
#include"Entity.h"
#include<SFML/Graphics.hpp>
#include <cmath>

class Enemy :public Entity {
protected:
	int hp;
	int maxHP;
	float orgspeed;
	float speed;
	sf::Vector2f position;
	sf::Vector2f path[10];
	int pathsize = 0;
	int currenttarget = 0;
public:
	Enemy(int h, float s, sf::Vector2f p);
	void setPath(sf::Vector2f p[], int size);
	virtual void move() = 0;
	virtual void takeDamage(int d);
	bool isDead();
	int getHP()const;
	sf::Vector2f getPosition()const;
	bool reachedEnd();
	void resetSpeed();
	void slow(float f);
	bool operator>(const Enemy& rhs)const;
	int getCurrentTarget()const;
	void hpbar(sf::RenderWindow& window);
	virtual~Enemy() {}
};
class BasicEnemy :public Enemy {
	sf::Texture texture;
	sf::Sprite sprite;
public:
	BasicEnemy(sf::Vector2f p);
	void takeDamage(int d)override;
	void move()override;
	void update()override;
	void render(sf::RenderWindow& window)override;
};
class FastEnemy :public Enemy {
	sf::Texture texture;
	sf::Sprite sprite;
public:
	FastEnemy(sf::Vector2f p);
	void takeDamage(int d)override;
	void move()override;
	void update()override;
	void render(sf::RenderWindow& window)override;
};
class TankEnemy :public Enemy {
	sf::Texture texture;
	sf::Sprite sprite;
public:
	TankEnemy(sf::Vector2f p);
	void takeDamage(int d)override;
	void move()override;
	void update()override;
	void render(sf::RenderWindow& window)override;
};
class FlyingEnemy :public Enemy {
	sf::Texture texture;
	sf::Sprite sprite;
public:
	FlyingEnemy(sf::Vector2f p);
	void takeDamage(int d)override;
	void move()override;
	void update()override;
	void render(sf::RenderWindow& window)override;
};
class ShieldEnemy :public Enemy {
	sf::Texture texture;
	sf::Sprite sprite;
public:
	ShieldEnemy(sf::Vector2f p);
	void move()override;
	void takeDamage(int d)override;
	void update()override;
	void render(sf::RenderWindow& window)override;
};

