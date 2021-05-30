#ifndef PLAYER_H
#define PLAYER_h


#pragma once
#include <string>
using std::string;

class Player {
public:
	Player(string name, char mark);
	void displayWins();
	char getMark() const;
	string getName() const;
	void Winner();
	int getWins() const;
private:
	string name;
	int wins;
	char mark;
};

#endif PLAYER_H