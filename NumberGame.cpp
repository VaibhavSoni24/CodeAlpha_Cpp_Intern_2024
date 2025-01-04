#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    // Generate a random number between 1 and 100
    int targetNumber = rand() % 100 + 1;
    
    int playerGuess;
    int attempts = 0;

    cout<<"Welcome to the Number Guessing Game!"<<endl;
    cout<<"I have selected a number between 1 and 100. Try to guess it!"<<endl;
    
    // Keep asking the player for guesses until they guess correctly
    do
    {
        cout<<"Enter your guess: ";
        cin>>playerGuess;
        attempts++;
        
        if(playerGuess > targetNumber)
        {
            cout<<"Too high! Try again."<<endl;
        }
        else if(playerGuess < targetNumber)
        {
            cout<<"Too low! Try again."<<endl;
        }
        else
        {
            cout<<"Correct! The number was "<<targetNumber<<"."<<endl;
            cout<<"You guessed it in "<<attempts<<" attempts."<<endl;
        }
    }

    // Repeat until the guess is correct
    while(playerGuess != targetNumber);
    return 0;
}