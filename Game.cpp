#include "Game.h"


void GameBoard::PrintClearBoard()
{
    for (int i = 0; i < word.length(); i++)
    {
        cout << "_ ";
    }
    cout << endl;
}

void GameBoard::PrintLetter(string &guess, char letter, vector<int> id)
{
    int it = 0;
    for(int i = 0; i < word.length(); i++)
    {
        if (i == id[it])
        {
            it++;
            guess[i] = letter;
        }

    }
    for(int i = 0; i < word.length(); i++)
    {
        cout << guess[i] << " ";
    }
    cout <<endl;

}

void GameBoard::CheckLetter(string &guess, char letter, Player &p1)
{
    vector<int> id;
    int count = 0;
    for(int i = 0; i < word.length(); i++)
    {
        if(word[i] == letter)
        {
            count++;
            p1.points++;
            id.push_back(i);

            //cout << "debug points: " << p1.points <<endl;
        }
    }


    if(count == 0)
    {
        cout << "No letter " << letter << " in this word."<<endl;
        p1.lifes--;
        p1.PrintLifes();
    }
    else
    {
        PrintLetter(guess, letter, id);
    }
}

bool GameBoard::IsOver(Player p1)
{
    if (p1.points == word.length())
    {
        cout << "Congrats!" << endl;
        return true;
    }

    else if(p1.lifes == 0)
    {
        cout << "Seems you lost game, sorry! The word was '" << word << "' " << endl;
        return true;
    }

    else return false;

}
string GameBoard::RandomWord()
{
    string wordspool[10] = {"cat", "dog", "papi", "phone", "game", "plox", "good", "bad","help", "bugs"};
    srand(time(0));
    int number = rand()% 10;
    //cout << "debug rand: " << number <<endl;
   // cout << "debug rand word: " << wordspool[number] <<endl;
    word = wordspool[number];
    string guess = word;
    for(int i =0; i < wordspool[number].length(); i++)
    {
        guess[i] = '_';
    }
    return guess;

}

Player::Player()
{
    lifes = 4;
    points = 0;
}

char Player::GetLetter()
{
    cout << "Choose letter: ";
    char choice;
    cin >> choice;
    std::cin.ignore(256, '\n');
    return choice;
}

void Player::PrintLifes()
{
    cout << lifes <<" lifes left." <<endl;
}

void Gameplay()
{
    bool end = false;
    char qa;
    while(!end)

    {
        GameBoard b1;
        Player p1;
        string guess = b1.RandomWord();
        b1.PrintClearBoard();
        while (!b1.IsOver(p1))
        {
            char let = p1.GetLetter();
            b1.CheckLetter(guess, let, p1);
        }
        cout <<"Again? Y/N ";
        cin >> qa;
        std::cin.ignore(256, '\n');

        if (qa == 'Y' || qa == 'y')
        {
            end = false;
        }

        else if (qa == 'N' || qa == 'n')
        {
            end = true;
        }

        else
        {
            cout << "Wrong input" <<endl;
            end = true;
        }

    }
}