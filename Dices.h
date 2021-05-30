#ifndef DICES_H
#define DICES_h

#pragma once
#include <vector>

class Dices {
public:
	Dices(int size);
	int rollDices();
private:
	std::vector<int> dice;
	int cant;
	int size;
};

#endif DICES_H