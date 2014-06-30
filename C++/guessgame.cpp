#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//declare prototypes
void genRandNum(int &);
void gameIntro(int &);
bool gameReplay(bool , int &);
void takeGuess(int &, int &, int&, bool &);
void youWin(int &, bool &, int &);

 


int main()
{   
    int randomNum = 0;
    bool gameRepeat = true;
    int start = 0;
    int guessesTaken = 0;
    int guess = 0;
   
    genRandNum(randomNum);
   
    if(gameRepeat == true)
	{
    gameIntro(guessesTaken);
    takeGuess(guessesTaken, randomNum, guess, gameRepeat);
    gameReplay(gameRepeat, guessesTaken);
	bool checkTrue = gameReplay(gameRepeat, guessesTaken);
    }
   
    return 0;
}


void genRandNum(int &randomNum)
{
    srand ((unsigned)time(NULL));          // Sets the seed value for the random number generator
    randomNum = (rand() % 100) + 1;         // Generates a random number between 1 and 100
}

void gameIntro(int &guessesTaken)
{
    system ("CLS");
    cout << "Welcome to the number guessing game! You will have 10 tries to guess a number between 1 and 100. Good luck!" << endl;
	guessesTaken = 0;
 
} 

void takeGuess(int &guessesTaken, int &randomNum, int &guess, bool &gameRepeat)
{
    while(guessesTaken < 10)
    {
        guessesTaken = guessesTaken + 1;
        cout << "Take a guess!" << endl;
		//cout << "You have used " << guessesTaken << " guesses out of 10!" << endl;
        cin >> guess;
            if(guess > randomNum)
                cout << "Your guess is too high!" << endl;
             if(guess < randomNum)
                cout << "You guess is too low!" << endl;
            if(guess == randomNum)
            {
                cout << "You have guessed right!" << endl;
                youWin(randomNum, gameRepeat, guessesTaken);
				break;
            }
             if(guessesTaken == 10)
             {   
				cout << "You have used all of you're guesses! Good luck next time!" << endl;
			 }
			 cout << "You have used " << guessesTaken << " guesses out of 10!" << endl;
    }
}

void youWin(int &randomNum, bool &gameRepeat, int &guessesTaken)
 {
    cout << "You win the guessing game!" << endl;
    gameReplay(gameRepeat, guessesTaken);
}

bool gameReplay(bool gameRepeat, int &guessesTaken)
{  
	char yes;
    cout << "Would you like to play again? (Y/N)" << endl;
    cin >> yes;
    if ( yes == 'Y')
    {
        gameRepeat = true;
		guessesTaken = 0;
		return gameRepeat;
    }
    if ( yes != 'Y')
	{
		gameRepeat = false;
		guessesTaken = 10;
	}
}