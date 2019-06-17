#pragma once
#include <iostream>
#include <ctime>

using namespace std;


class Animal {
	int pos_x;
	int pos_y;
	int age;
	bool alive;
public:
	Animal() {
		pos_x = rand()%20+1;
		pos_y = rand()%20+1;
		age = 0;
		alive = true;
	}
	Animal(int x , int y ) {
		age = 0;
     	pos_x = x;
		pos_y = y;
		alive = true;
	}

	void aging();
	int show_age();
	void change_positions();
	void change_pos_x(int x);
	void change_pos_y(int y);
	void change_x(int x);
	void change_y(int y);
	int show_pos_x();
	int show_pos_y();
	bool is_alive();
	void die();

	~Animal() {}
};

