#include <iostream>

using namespace std;

int main()
{
    int secretNum = 7;
    int guess;
    int guessCount = 0;
    int guessLimit = 3;
    bool outOfGuesses = false;

    while(secretNum != guess && !outOfGuesses)
    {
        if(guessCount < guessLimit)
        {
            cout << "Enter guess: " << endl;
            cin >> guess;
            guessCount++;
        }
        else
        {
            outOfGuesses = true;
        }


    }
    if(outOfGuesses == true)
    {
        cout << "You lose!" << endl;
    }
    else
    {
        cout << "You win!" << endl;
    }

    return 0;
}
