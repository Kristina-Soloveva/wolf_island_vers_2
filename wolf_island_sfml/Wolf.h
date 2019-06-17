#pragma once
#include "Predator.h"

using namespace std;

class Wolf :public Predator {
public:	
	Wolf() {};
	Wolf(int x, int y):Predator(x,y) {}
	~Wolf() {}

};
