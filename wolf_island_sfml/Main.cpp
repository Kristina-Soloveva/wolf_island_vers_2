#include <SFML/Graphics.hpp>
#include <conio.h>
#include "Game.h"
#include <ctime>


int main() {
	srand(time(NULL));
	Game game;
	game.run();
	_getch();
}










