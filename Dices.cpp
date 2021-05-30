#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Dices.h"


Dices::Dices(int size) {
	for (int i = 0; i < size; i++)
		Dices::dice.push_back(i);
	Dices::cant = 0;
	Dices::size = size;
}

int Dices::rollDices() {
	srand(time(NULL));
	cant += rand() % size + 1;
	cant += rand() % size + 1;
	return cant;
}