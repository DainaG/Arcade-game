#include <iostream>
#include <string>
#include "Hangman.h"
using namespace std;

Hangman::Hangman() {
    Hangman::head = 'O';
    Hangman::body = '|';
    Hangman::arm1 = '/';
    Hangman::arm2 = '\\';
    Hangman::leftLeg = '/';
    Hangman::rightLeg = '\\';
    Hangman::count = 0;
    Hangman::wrong = 0;
    Hangman::wordsForComputer[0] = "Stantler";
    Hangman::wordsForComputer[1] = "Pachirisu";
    Hangman::wordsForComputer[2] = "Forretress";
    Hangman::wordsForComputer[3] = "Baltoy";
    Hangman::wordsForComputer[4] = "Heatran";
    Hangman::wordsForComputer[5] = "Whimsicott";
    Hangman::wordsForComputer[6] = "Swoobat";
    Hangman::wordsForComputer[7] = "Reuniclus";
    Hangman::wordsForComputer[8] = "Farfetchd";
    Hangman::wordsForComputer[9] = "Meloetta";
}

void Hangman::setWord(const std::string& word) {
    word = word;
    size = word.size();
    for (int i = 0; i < size; i++)
        secretWord.push_back('*');
}

void Hangman::computerSelect() {
    int i = rand() % 9;
    word = wordsForComputer[i];
    size = word.size();
    for (int j = 0; j < size; j++)
        secretWord.push_back("*");
}

void Hangman::printHangman() {
    if (wrong == 0) {
        cout << "________" << endl;
        cout << "|" << "      " << "|" << endl;
        cout << "       " << "|" << endl;
        cout << "       " << "|" << endl;
        cout << "       " << "|" << endl;
        cout << "       " << "|" << endl;
        cout << "       " << "|" << endl;
        cout << "     " << "__" << "|" << "___" << endl;
        showSecretWord();
    }
    else if (wrong == 1) {
        //1 wrong guess made and letter not already guessed, print out the following
        cout << " ________" << endl;
        cout << " |" << "      " << "|" << endl;
        cout << " " << head;
        cout << "      " << "|" << endl;
        cout << "        " << "|" << endl;
        cout << "        " << "|" << endl;
        cout << "        " << "|" << endl;
        cout << "        " << "|" << endl;
        cout << "      " << "__" << "|" << "___" << endl;
        showSecretWord();
    }

    else if (wrong == 2) {
        //2 wrong guesses made, letter not previously guessed
        cout << " ________" << endl;
        cout << " |" << "      " << "|" << endl;
        cout << " " << head;
        cout << "      " << "|" << endl;
        cout << " " << body;
        cout << "      " << "|" << endl;
        cout << "        " << "|" << endl;
        cout << "        " << "|" << endl;
        cout << "        " << "|" << endl;
        cout << "      " << "__" << "|" << "___" << endl;
        showSecretWord();
    }

    else if (wrong == 3) {
        cout << " ________" << endl;
        cout << " |" << "      " << "|" << endl;
        cout << " " << head;
        cout << "      " << "|" << endl;
        cout << arm1;
        cout << bodyParts[1];
        cout << "      " << "|" << endl;
        cout << "        " << "|" << endl;
        cout << "        " << "|" << endl;
        cout << "        " << "|" << endl;
        cout << "      " << "__" << "|" << "___" << endl;
        showSecretWord();
    }

    else if (wrong == 4) {
        cout << " ________" << endl;
        cout << " |" << "      " << "|" << endl;
        cout << " " << head;
        cout << "      " << "|" << endl;
        cout << arm1;
        cout << body;
        cout << arm2;
        cout << "     " << "|" << endl;
        cout << "        " << "|" << endl;
        cout << "        " << "|" << endl;
        cout << "        " << "|" << endl;
        cout << "      " << "__" << "|" << "___" << endl;
        showSecretWord();
    }
    else if (wrong == 5) {
        cout << " ________" << endl;
        cout << " |" << "      " << "|" << endl;
        cout << " " << head;
        cout << "      " << "|" << endl;
        cout << arm1;
        cout << body;
        cout << arm2;
        cout << "     " << "|" << endl;
        cout << leftLeg;
        cout << "       " << "|" << endl;
        cout << "        " << "|" << endl;
        cout << "        " << "|" << endl;
        cout << "      " << "__" << "|" << "___" << endl;
        showSecretWord();
    }

    else if (wrong == 6) {
        //6 wrong guesses made (max)
        cout << " ________" << endl;
        cout << " |" << "      " << "|" << endl;
        cout << " " << head;
        cout << "      " << "|" << endl;
        cout << arm1;
        cout << body;
        cout << arm2;
        cout << "     " << "|" << endl;
        cout << leftLeg;
        cout << " " << rightLeg;
        cout << "     " << "|" << endl;
        cout << "        " << "|" << endl;
        cout << "        " << "|" << endl;
        cout << "      " << "__" << "|" << "___" << endl;
        showSecretWord();
        cout << "Better luck next time!";
    }
}

void Hangman::guessChar(char chr) {
    for (int i = 0; i < word.size(); i++) {
        if (word[i] == chr && hidden_word[i] == '*') {
            reveal_letter(i);
        }
        else {
            wrong++;
            printHangman();
        }
    }
}

void Hangman::revealLetter(int index) {
    if (index >= 0 && index < word.size())
        hidden_word[index] = word[index];
}

void Hangman::showSecretWord() {
    cout << "WORD: " << secretWord << endl;
}

bool Hangman::haveWon() const{
    return word == hidden_word;
}

int Hangman::getHelps() const {
    return count;
}

int Hangman::getWrong() const {
    return wrong;
}

int Hangman::getWordSize() const {
    return size;
}