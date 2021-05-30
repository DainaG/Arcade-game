#ifndef TATETI_H
#define TATETI_h

#pragma once
#include <string>
using std::string;

class TaTeTi {
public:
	TaTeTi(int size);
	void printOptions();
	int playTaTeTi();
	bool getTurn() const;
private:
	string* options;
	int size;
	bool chooseRight;
	bool playerTurn;				//True = player, False = computer
};

#endif TATETI_H