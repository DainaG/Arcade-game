#ifndef TICTACTOE_H
#define TICTACTOE_h

#pragma once

#include <stdbool.h>
#include "Player.h"

class TicTacToe {
public:
	TicTacToe();							//Initializes all variables within the TicTacToe game
	void board();							//Creates the board for the game
	void Turn(Player p);					//Plays a turn
	int checkWin();							//Returns 1 if game is going on, 0 if finished (tie) and -1 if finished (winner)
	bool WinnerT();							//Returns bool playerWin;

private:
	char square[10];						//Board
	bool playerWin;							//If there's a winner
	bool playerTurn;						//True if player, False if computer
};

#endif TICTACTOE_H