#pragma once
#include <SFML/Graphics.hpp>

class Unit {
private:

public:
	sf::Vector2i pos{};
	int health{};
	int attackDamage{};

	virtual void draw(sf::RenderWindow) = 0;
};

class Warrior : public Unit {
private:

public:
	void draw(sf::RenderWindow window) override {
		
	}

};