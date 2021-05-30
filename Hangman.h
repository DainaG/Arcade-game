#ifndef HANGMAN_H
#define HANGMAN_H
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

class Hangman{
public:
    Hangman();                                          //default constructor
    void setWord(const std::string& word);              //Player select word
    void computerSelect();                              //Gets word for computer
    void printHangman();                                //Prints out body part each time guessed letter not in word
    void guessChar(char chr);                           //Guess a letter
    void revealLetter(int index);                       //Show a letter selected by index
    void showSecretWord();                              //Show's progress
    bool haveWon() const;                               //Return true/1 if won
    int getHelps() const;                               //Returns amount of time help was used
    int getWrong() const;                               //Return amount of errors
    int getWordSize() const;                            //Return word size
private:
    char head;                      //Drawing of head
    char body;                      //Drawing of body
    char arm1;                      //Drawing of left arm
    char arm2;                      //Drawing of right arm
    char leftLeg;                   //Drawing of left leg
    char rightLeg;                  //Drawing of right leg
    string words;                   //Word
    string* wordsForComputer;       //List of words for computer to choose from
    int size;                       //Size of word
    int count;                      //Amount of helps utilized
    int wrong;                      //wrong guesses
    string secretWord;              //Secret word (*******)
};



#endif  HANGMAN_H