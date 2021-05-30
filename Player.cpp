#include <iostream>

#include "Player.h"

using namespace std;

Player::Player(string name, char mark) {
	Player::name = name;
	Player::mark = mark;
	Player::wins = 0;
}

int Player::displayWins() {
	cout << name << " has " << wins << "!" << endl;
}

char Player::getMark() const{
	return mark;
}

string Player::getName() const{
	return name;
}

void Player::Winner() {
	wins++;
}

int Player::getWins() const {
	return wins;
}