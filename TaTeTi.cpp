#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TaTeTi.h"

using namespace std;

TaTeTi::TaTeTi(int size) {
	string op;
	TaTeTi::size = size;
	for (int i = 0; i < size; i++) {
		cout << "Enter word: " << endl;
		cin >> op;
		TaTeTi::options[i] = op;
	}
	TaTeTi::chooseRight = false;
	TaTeTi::playerTurn = true;
}

void TaTeTi::printOptions() {
	cout << "\n\n\tOptions:\n\n";
	for (int i = 0; i < size; i++)
		cout << i << ". " << options[i] << "\n";
}

int TaTeTi::playTaTeTi() {
	int i = rand() % size;
	int choice;
	do {
		if (playerTurn) {
			printOptions();
			cout << "Enter choice: " << endl;
			cin >> choice;
			cout << options[choice] << endl;
			if (choice == i)
				chooseRight = true;
			playerTurn != playerTurn;
		}
		if (playerTurn == false) {
			printOptions();
			choice = rand() % size;
			cout << options[choice] << endl;
			if (choice == 1)
				choice = true;
			playerTurn = !playerTurn;
		}

	} while (chooseRight == false);
	if (playerTurn)
		return 1;
	if (!playerTurn)
		return 0;
}

bool TaTeTi::getTurn() const {
	return playerTurn;
}