#include "Map.h"

void Map:: counting() {
	this->making_it_zero();
	for (int i = 1; i < 21; i++) {
		for (int k = 1; k < 21; k++) {
			for (int t = 0; t < bunnies.size(); t++) {
				if (bunnies[t].show_pos_x() == i and bunnies[t].show_pos_y() == k) {
					this->an[i][k].buns++;
				}
			}
			for (int t = 0; t < wolfess.size(); t++) {
				if (wolfess[t].show_pos_x() == i and wolfess[t].show_pos_y() == k) {
					this->an[i][k].girl_wolfies++;
				}
			}
			for (int t = 0; t < wolfs.size(); t++) {
				if (wolfs[t].show_pos_x() == i and wolfs[t].show_pos_y() == k) {
					this->an[i][k].wolfies++;
				}
			}
		}
	}
}
void Map:: making_it_zero() {
	for (int i = 0; i < 22; i++) {
		for (int k = 0; k < 22; k++) {
			an[i][k].buns = 0;
			an[i][k].girl_wolfies = 0;
			an[i][k].wolfies = 0;
		}
	}
}
void Map:: add_bunny() {
	bunnies.push_back(Bunny());
}
void Map:: add_she_wolf() {
	wolfess.push_back(She_Wolf());
}
void Map:: add_wolf() {
	wolfs.push_back(Wolf());
}
void Map:: die() {
	for (int x = bunnies.size() - 1; x > -1; x--) {
		if (!bunnies[x].is_alive()) {
			bunnies.erase(bunnies.begin() + x);
		}
	}
	for (int x = wolfess.size() - 1; x > -1; x--) {
		if (!wolfess[x].is_alive() or wolfess[x].show_health() == 0) {
			wolfess.erase(wolfess.begin() + x);
		}
	}
	for (int x = wolfs.size() - 1; x > -1; x--) {
		if (!wolfs[x].is_alive() or wolfs[x].show_health() == 0) {
			wolfs.erase(wolfs.begin() + x);
		}
	}

}
void Map:: moving() {
	this->move_bunnies();
	this->move_wolfess();
	this->move_wolfs();
}
void Map:: move_bunnies() {
	for (auto&i : bunnies)
		if (i.is_alive()) {
			i.change_positions();
			i.aging();
		}
}
void Map:: move_wolfess() {

	for (auto&k : wolfess) {
		if (k.is_alive()) {
			if (!this->sence_bunnies(k.show_pos_x(), k.show_pos_y()) or k.show_health()>5)
				k.change_positions();
			else
				for (auto&i : bunnies) {
					if ((i.show_pos_x() == k.show_pos_x() or i.show_pos_x() == k.show_pos_x() + 1 or i.show_pos_x() == k.show_pos_x() - 1) and (i.show_pos_y() == k.show_pos_y() or i.show_pos_y() == k.show_pos_y() + 1 or i.show_pos_y() == k.show_pos_y() - 1))
						k.wolf_move(i.show_pos_x(), i.show_pos_y());
				}
			k.aging();
			k.minus_health();
		}
	}
}
void Map:: move_wolfs() {
	for (auto&t : wolfs) {
		if (t.is_alive()) {
			if (this->sence_bunnies(t.show_pos_x(), t.show_pos_y())and t.show_health()<=4) {
				for (auto&i : bunnies) {
					if ((i.show_pos_x() == t.show_pos_x() or i.show_pos_x() == t.show_pos_x() + 1 or i.show_pos_x() == t.show_pos_x() - 1) and (i.show_pos_y() == t.show_pos_y() or i.show_pos_y() == t.show_pos_y() + 1 or i.show_pos_y() == t.show_pos_y() - 1))
						t.wolf_move(i.show_pos_x(), i.show_pos_y());
				}
			}

			else if (this->sence_wolfess(t.show_pos_x(), t.show_pos_y()) and t.show_health()>4) {
				for (auto&i : wolfess) {
					if ((i.show_pos_x() == t.show_pos_x() or i.show_pos_x() == t.show_pos_x() + 1 or i.show_pos_x() == t.show_pos_x() - 1) and (i.show_pos_y() == t.show_pos_y() or i.show_pos_y() == t.show_pos_y() + 1 or i.show_pos_y() == t.show_pos_y() - 1))
						t.wolf_move(i.show_pos_x(), i.show_pos_y());
				}
			}
			else
				t.change_positions();
		}
		t.aging();
		t.minus_health();
	}
}
void Map:: show_count() {
	for (int i = 1; i < 21; i++) {
		for (int k = 1; k < 21; k++) {
			std::cout << an[i][k].buns << " ";
		}
		std::cout << endl;
	}
	cout << endl;
	for (int i = 1; i < 21; i++) {
		for (int k = 1; k < 21; k++) {
			std::cout << an[i][k].girl_wolfies << " ";
		}
		std::cout << endl;
	}
	cout << endl;
	for (int i = 1; i < 21; i++) {
		for (int k = 1; k < 21; k++) {
			std::cout << an[i][k].wolfies << " ";
		}
		std::cout << endl;
	}
}
int Map:: return_count_bunnies(int x, int y) {
	return an[x][y].buns;
}
int Map:: return_count_wolfess(int x, int y) {
	return an[x][y].girl_wolfies;
}
int Map::return_count_wolfs(int x, int y) {
	return an[x][y].wolfies;
}
bool Map:: sence_bunnies(int x, int y) {
	for (auto&k : bunnies) {
		if ((k.show_pos_x() == x or k.show_pos_x() == x + 1 or k.show_pos_x() == x - 1) and (k.show_pos_y() == y or k.show_pos_y() == y + 1 or k.show_pos_y() == y - 1)) {
			return true;
		}
	}
	return false;
}
bool Map:: sence_wolfess(int x, int y) {
	for (auto&k : wolfess) {
		if ((k.show_pos_x() == x or k.show_pos_x() == x + 1 or k.show_pos_x() == x - 1) and (k.show_pos_y() == y or k.show_pos_y() == y + 1 or k.show_pos_y() == y - 1)) {
			return true;
		}
	}
	return false;
}
void Map:: eat() {
	for (auto&i : wolfess) {
		if (i.is_alive()) {
			for (auto&k : bunnies) {
				if (k.show_pos_x() == i.show_pos_x() and k.show_pos_y() == i.show_pos_y()) {
					k.die();
					i.plus_health();
					break;
				}
			}
		}
	}
	for (auto&i : wolfs) {
		if (i.is_alive()) {
			for (auto&k : bunnies) {
				if (k.show_pos_x() == i.show_pos_x() and k.show_pos_y() == i.show_pos_y()) {
					k.die();
					i.plus_health();
					break;
				}
			}
		}
	}
}
void Map:: bunny_birth() {
	for (auto&i : bunnies) {
		if (i.is_alive() and bunnies.size() < 400 and i.show_age() >= 2) {
			int t = rand() % 10;
			if (t == 0 or t == 1)
				bunnies.push_back(Bunny(i.show_pos_x(), i.show_pos_y()));


		}
	}
}
void Map:: wolf_birth() {
	for (auto&i : wolfs) {
		if (i.show_age() >= 10) {
			for (auto&k : wolfess) {
				if (k.show_age() >= 10) {
					if (i.show_pos_x() == k.show_pos_x() and i.show_pos_y() == k.show_pos_y() and wolfess.size()<400 and wolfs.size()<400) {
						int t = rand() % 2;
						if (t == 0)
							wolfs.push_back(Wolf(i.show_pos_x(), i.show_pos_y()));
						else {
							wolfess.push_back(She_Wolf(i.show_pos_x(), i.show_pos_y()));
						}
						break;
					}
				}
			}
		}
	}
}
void Map:: show_bunnies() {
	cout << "Bunnies: " << this->bunnies.size() << endl;
}
void Map:: show_wolvess() {
	cout << "Wolvess: " << this->wolfess.size() << endl;
}
void Map:: show_wolfs() {
	cout << "Wolfs: " << this->wolfs.size() << endl;
}
int Map:: return_bunnies() {
	return bunnies.size();
}
int Map:: return_wolfes() {
	return wolfs.size();
}
int Map:: return_wolfess() {
	return wolfess.size();


}

bool Map:: bunny_here(int x, int y) {
	if (an[x][y].buns != 0)
		return true;
	else
		return false;
}
bool Map:: wolf_here(int x, int y) {
	if (an[x][y].wolfies != 0)
		return true;
	else
		return false;
}
bool Map:: wolfess_here(int x, int y) {
	if (an[x][y].girl_wolfies != 0)
		return true;
	else
		return false;
}