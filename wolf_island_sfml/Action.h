#pragma once
#include"Map.h"
#include <SFML/Graphics.hpp>


class Action {
public:
	Map map;
	Action(){
		Map map;
	}
	void do_action();
	void do_die();
	void do_move();
	void do_count();
	void show_map();
	void show_all();
	void do_birth();
	void do_eat();
	bool ending();
	bool bunny_here_2(int x, int y) {
		return this->map.bunny_here(x,y);
	}
	bool wolf_here_2(int x, int y) {
		return map.wolf_here(x, y);
	}
	bool wolfess_here_2(int x, int y) {
		return map.wolfess_here(x, y);
	}


	




};
