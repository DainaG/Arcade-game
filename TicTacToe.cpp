#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stdbool.h>
#include "TicTacToe.h"
#include "Player.h"

using namespace std;


TicTacToe::TicTacToe() {
    TicTacToe::square[0] = '0';
    TicTacToe::square[1] = '1';
    TicTacToe::square[2] = '2';
    TicTacToe::square[3] = '3';
    TicTacToe::square[4] = '4';
    TicTacToe::square[5] = '5';
    TicTacToe::square[6] = '6';
    TicTacToe::square[7] = '7';
    TicTacToe::square[8] = '8';
    TicTacToe::square[9] = '9';
    TicTacToe::playerWin = false;
    TicTacToe::playerTurn = true;

}

void TicTacToe::board() {
    system("cls");
    cout << "\n\n\tTic-Tac-Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}

void TicTacToe::Turn(Player p) {
    srand(time(NULL));
    int choice;
    char mark = p.getMark();

    cout << p.getName() << "'s turn!" << endl;
    if (playerTurn)
        cin >> choice;
    else
        choice = rand() % 9 + 1;

    if (choice == 1 && square[1] == '1')
        square[1] = mark;
    else if (choice == 2 && square[2] == '2')
        square[2] = mark;
    else if (choice == 3 && square[3] == '3')
        square[3] = mark;
    else if (choice == 4 && square[4] == '4')
        square[4] = mark;
    else if (choice == 5 && square[5] == '5')
        square[5] = mark;
    else if (choice == 6 && square[6] == '6')
        square[6] = mark;
    else if (choice == 7 && square[7] == '7')
        square[7] = mark;
    else if (choice == 8 && square[8] == '8')
        square[8] = mark;
    else if (choice == 9 && square[9] == '9')
        square[9] = mark;
    else
        cout << "Invalid move, try again";
    playerTurn = !playerTurn;
}

int TicTacToe::checkWin() {
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
        && square[4] != '4' && square[5] != '5' && square[6] != '6'
        && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}

bool TicTacToe::WinnerT() {
    return playerWin;
}