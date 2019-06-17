#pragma once
#include "Animal.h"

class Predator : public Animal {
	int health;
public:
	Predator() {}

	Predator(int x, int y) :Animal(x, y) {
		health = 10;
	}
	void wolf_move(int x, int y);
	void minus_health();
	int show_health();
	void plus_health();

	~Predator() {}

};
