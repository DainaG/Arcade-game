#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "TicTacToe.h"
#include "Dices.h"
#include "TaTeTi.h"
#include "Hangman.h"


using namespace std;


int main(){
    TicTacToe Ttt;
    Hangman hM;
    TaTeTi tateti(10);
    string playerName, word;
    char letter;
    int i, choice;
    bool play = true;
    char ch;

    cout << "Hello! Please enter your name: ";      //prompt for player name
    cin >> playerName;                              //read in player name
    Player player(playerName, 'X');                 //create Player object using player's name
    Player computer("Computer", 'O');               //create Player object for the computer

    /* Welcome message and choice */
    cout << "It's nive to have you here today " << playerName << ", now, as you may know \nthis is a mini arcade, completed with some of my favourite games\n";
    cout << "You'll be competing against the computer, so don't worry and select one of the\noptions!\n";
    do {
        cout << "1. Tic-Tac-Toe\n2. Hangman\n3. Dices\n4. TaTeti" << endl;
        cin >> choice;

        /* TicTacToe */
        if (choice == 1) {
            cout << "Tic-Tac-Toe is always a good option!" << endl;
            i = -1;
            Ttt.board();
            do {
                Ttt.Turn(player);
                Ttt.board();
                i = Ttt.checkWin();
                Ttt.Turn(computer);
                Ttt.board();
                i = Ttt.checkWin();
            } while (i == -1);
            if (i == 1) {
                if (Ttt.WinnerT() == false) {
                    player.Winner();
                    cout << "Congratulations!" << endl;
                }
                else {
                    computer.Winner();
                    cout << "Better luck next game!" << endl;
                }
            }
        }
        /* Shows amount of wins by player */
        player.displayWins();
        computer.displayWins();
        /* Hangman */
        if (choice == 2) {
            cout << "I hope you know some difficult words!" << endl;
            srand(time(NULL));
            i = rand() % 2 + 1;
            if (i == 1) {
                cout << computer.getName() << " will choose the word! Good luck" << endl;
                hM.computerSelect();
                do {
                    hM.printHangman();
                    cout << "1. Guess Letter" << endl << "2. Reveal letter (by index)" << endl << "3. Reveal letter (random)" << endl;
                    cin >> choice;
                    switch (choice) {
                    case 1:
                        cout << "Please insert letter: " << endl;
                        cin >> letter;
                        hM.guessChar(letter);
                        break;
                    case 2:
                        if (hM.getHelps() < 3) {
                            cout << "Please insert index: " << endl;
                            cin >> choice;
                            hM.revealLetter(choice);
                            break;
                        }
                        else {
                            cout << "Sorry, you can't use help anymore!" << endl;
                            break;
                        }
                    case 3:
                        if (hM.getHelps() < 3) {
                            choice = rand() % hM.getWordSize();
                            hM.revealLetter(choice);
                            break;
                        }
                        else {
                            cout << "Sorry, you can't use help anymore!" << endl;
                            break;
                        }
                    }
                } while (hM.haveWon() != 1 && hM.getWrong() <= 6);
                if (hM.haveWon() == 1) {
                    hM.printHangman();
                    cout << "Congratulations!" << endl;
                    player.Winner();
                }
                else 
                    hM.showSecretWord();
            }
            else {
                cout << playerName << " will choose the word! Good luck" << endl;
                cout << "Choose a word!" << endl;
                cin >> word;
                hM.setWord(word);
                do {
                    hM.printHangman();
                    cout << "1. Guess Letter" << endl << "2. Reveal letter (by index)" << endl << "3. Reveal letter (random)" << endl;
                    choice = rand() % 3 + 1;
                    switch (choice) {
                    case 1:
                        letter = 'a' + rand() % 26;
                        cout << "letter: " << letter << endl;
                        hM.guessChar(letter);
                        break;
                    case 2:
                        if (hM.getHelps() < 3) {
                            choice = rand() % hm.getWordSize();
                            cout << "Showing letter in " << choice << "index: " << endl;
                            hM.revealLetter(choice);
                            break;
                        }
                    case 3:
                        if (hM.getHelps() < 3) {
                            choice = rand() % hM.getWordSize();
                            hM.revealLetter(choice);
                            break;
                        }
                    }
                } while (hM.haveWon() != 1 && hM.getWrong() <= 6);
                if (hM.haveWon() == 1) {
                    hM.printHangman();
                    cout << "Better luck next time!" << endl;
                    computer.Winner();
                }
                else
                    hM.showSecretWord();
            }
        }
        /* Shows amount of wins by player */
        player.displayWins();
        computer.displayWins();
        /* Dices */
        if (choice == 3) {
            cout << "Are we feeling lucky today?" << endl;
            cout << "Which size you want the dices to be?" << endl;
            cin >> i;
            Dices d(i);
            int playerPoint, computerPoint;
            cout << "Good luck!" << endl;
            playerPoint = d.rollDices();
            computerPoint = d.rollDices();
            if (playerPoint > computerPoint) {
                cout << "Congrats! You've won with: " << playerPoint << endl;
                player.Winner();
            }
            if (playerPoint < computerPoint) {
                cout << "The computer won with: " << computerPoint << endl;
                computer.Winner();
            }
        }
        /* Shows amount of wins by player */
        player.displayWins();
        computer.displayWins();
        /* TaTeTi */
        if (choice == 4) {
            cout << "I hope you can choose the correct option!" << endl;
            do {
                cout << "Good luck!" << endl;
                tateti.printOptions();
                i = tateti.playTaTeTi();
            } while (i != 1 && i != 0);
            if (tateti.getTurn() == false) {
                cout << "Congratulation for guessing right!" << endl;
                player.Winner();
            }
            if (tateti.getTurn() == true) {
                cout << "Better luck next time!" << endl;
                computer.Winner();
            }
        }
        /* Shows amount of wins by player */
        player.displayWins();
        computer.displayWins();
        /* If player wants to continue */
        cout << "You want to continue playing? (y/n)" << endl;
        cin >> ch;
        if (ch == 'n')
            break;
    } while (play == true);
    /* See who's the winner */
    if (player.getWins() < computer.getWins())
        cout << "Better luck next time!" << endl;
    else if (player.getWins() > computer.getWins())
        cout << "Congratulations!" << endl;
    else
        cout << "It's a tie!" << endl;
    return 0;
}