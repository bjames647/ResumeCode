//Brian James
//number guessing program 
//intro to programming logic
//10-24-13


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//declare prototypes
void genRandNum(int &);



int main()
{   
	int randomNum = 0;
	int guessesTaken = 0;
	int guess = 0;
	char yes = 'y';
	bool replay = true;
	genRandNum(randomNum);
	
	//This is the main game loop
	do
	{
		if(guessesTaken == 0)
			cout << "Welcome to the number guessing game! The goal is to guess a number between 1 and 100! Good luck!" << endl;
		cout << "Take a guess!" << endl;
		cin >> guess;
		guessesTaken = guessesTaken + 1;
		cout << "You have taken " << guessesTaken << " out of 10 guesses!" << endl;
		if(guess > randomNum)
			cout << "Your guess!" << endl;
		if(guess < randomNum)
			cout << "Your guess!" << endl;
		if(guess == randomNum)
		{
			cout << "You have guessed correct! Congratz!" << endl;
			cout << "Would you like to play again!? (y/n)" << endl;
			cin >> yes;
			if(yes == 'y')
			{
				guessesTaken = 0;
				system ("CLS");
			}
			if(yes != 'y')
				break;
		}
		if(guessesTaken == 10)
		{
			cout << "You did not guess the number in 10 guesses or less! The number was " << randomNum << endl;
			cout << "Would you like to play again!? (y/n)" << endl;
			cin >> yes;
			if(yes == 'y')
			{
				guessesTaken = 0;
				system ("CLS");
			}
			if(yes != 'y')
			{
				break;
			}	
		}
	
	}while(replay = true);
	
    return 0;
}

//module generates random number
void genRandNum(int &randomNum)
{
    srand ((unsigned)time(NULL));          // Sets the seed value for the random number generator
    randomNum = (rand() % 100) + 1;         // Generates a random number between 1 and 100
}