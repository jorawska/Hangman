#ifndef HANGMAN_GAME_H
#define HANGMAN_GAME_H
#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>

using namespace std;


class Player{
public:

    int lifes;
    int points;
    Player();
    char GetLetter();
    void PrintLifes();
};

class GameBoard{

public:
    string word;
    void PrintClearBoard();
    void PrintLetter(string &guess, char letter, vector<int> id);
    void CheckLetter(string &guess, char letter, Player &p1);
    bool IsOver(Player p1);
    string RandomWord();
};

void Gameplay();
#endif //HANGMAN_GAME_H
