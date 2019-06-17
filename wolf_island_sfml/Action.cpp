#include"Action.h"

void Action:: do_action() {
		this->do_move();
		this->do_eat();
		this->do_birth();
		this->do_die();	
}

void Action:: do_die() {
	map.die();
}

void Action:: do_move() {
	map.moving();
}

void Action:: do_count() {
	map.counting();
}

void Action:: show_map() {
	map.show_count();
}

void Action:: show_all() {
	map.show_bunnies();
	map.show_wolvess();
	map.show_wolfs();
}

void Action:: do_birth() {
	map.bunny_birth();
	map.wolf_birth();
}
void Action:: do_eat() {
	map.eat();
}

bool Action::ending() {
	if (map.return_bunnies() == 0 or map.return_wolfes() == 0 or map.return_wolfess() == 0) {
		return true;
	}
	else
		return false;


}