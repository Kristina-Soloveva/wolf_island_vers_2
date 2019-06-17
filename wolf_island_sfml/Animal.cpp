#include"Animal.h"


void Animal:: aging() {
	this->age++;
	if (this->age == 20)
		alive = false;
}

int Animal:: show_age() {
	return this->age;
}

void Animal:: change_positions() {
	int x;
	int y;
	if (this->show_pos_x() == 1) {
		if (this->show_pos_y() == 1) {
			y = rand() % 2;
		}
		else if (this->show_pos_y() == 20) {
			y = rand() % 2 - 1;
		}
		else {
			y = rand() % 3 - 1;
		}
		x = rand() % 2;
	}
	else if (this->show_pos_x() == 20) {
		x = rand() % 2 - 1;
		if (this->show_pos_y() == 1) {
			y = rand() % 2;
		}
		else if (this->show_pos_y() == 20) {
			y = rand() % 2 - 1;
		}
		else {
			y = rand() % 3 - 1;
		}
	}
	else if (this->show_pos_x() != 1 and this->show_pos_x() != 20 and this->show_pos_y() == 1 or this->show_pos_y() == 20) {
		x = rand() % 3 - 1;
		if (this->show_pos_y() == 1) {
			y = rand() % 2;
		}
		else {
			y = rand() % 2 - 1;
		}
	}
	else {
		x = rand() % 3 - 1;
		y = rand() % 3 - 1;
	}
	this->change_pos_x(x);
	this->change_pos_y(y);

}

void Animal:: change_pos_x(int x) {
	this->pos_x += x;
}

void Animal:: change_pos_y(int y) {
	this->pos_y += y;
}

void Animal:: change_x(int x) { this->pos_x = x; }
void Animal:: change_y(int y) { this->pos_y = y; }

int Animal:: show_pos_x() {
	return this->pos_x;
}

int Animal:: show_pos_y() {
	return this->pos_y;
}

bool Animal:: is_alive() {
	if (this->age == 20)
		alive = false;
	return alive;
}

void Animal:: die() {
	alive = false;
}