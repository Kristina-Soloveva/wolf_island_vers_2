#include "Predator.h"


void Predator:: wolf_move(int x, int y) {
	this->change_x(x);
	this->change_y(y);
}

void Predator:: minus_health() {
	health--;
}

int Predator:: show_health() {
	return health;
}

void Predator:: plus_health() {
	health = 10;
}