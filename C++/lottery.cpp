//Brian James
//intro to programming 8:00
//11/18/2013
//lottery program

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void genRandNum(int[]);
void userNumbers(int[]);

const int RANDOM_NUMBERS = 5;

int main()
{    
	int randomNumbers[RANDOM_NUMBERS];
    int userNumbersArray[RANDOM_NUMBERS];
	int counter = 0;
	char yesNo;
	bool repeat = false;
	
	do
	{
	genRandNum(randomNumbers);
	
	userNumbers(userNumbersArray);
	
	//If states are checking for the random numbers and users numbers match
	if(randomNumbers[0] == userNumbersArray[0])
		counter++;
	if(randomNumbers[1] == userNumbersArray[1])
		counter++;
	if(randomNumbers[2] == userNumbersArray[2])
		counter++;
	if(randomNumbers[3] == userNumbersArray[3])
		counter++;
	if(randomNumbers[4] == userNumbersArray[4])
		counter++;
	if(counter == 5)
		cout << "Splendid job! All of your guesses matched the random numbers!" << endl;
	if(counter != 5)
		cout << "Your numbers matched " << counter << " times!" << endl;
		
	//This is all displaying what the numbers were
	cout << endl << "The random numbers were: " << randomNumbers[0];
	cout << ", " << randomNumbers[1];
	cout << ", " << randomNumbers[2];
	cout << ", " << randomNumbers[3];
	cout << ", " << randomNumbers[4] << endl;
	
	cout << endl << "Your numbers were: " << userNumbersArray[0];
	cout << ", " << userNumbersArray[1];
	cout << ", " << userNumbersArray[2];
	cout << ", " << userNumbersArray[3];
	cout << ", " << userNumbersArray[4] << endl;
	
	cout << endl << "Would you like to test your luck again?(y/n)";
	cin >> yesNo;
	
	//Play again code
	if(yesNo == 'y' || yesNo == 'Y')
		{
		repeat = true;
		counter = 0;
		system ("CLS");
		}
	else if(yesNo != 'y' || yesNo != 'Y')
		break;
	}while(repeat == true);
	
	return 0;
}
//Random number generator for array and make sure no random number is the same
void genRandNum(int randomNumbers[])
{
    srand ((unsigned)time(NULL));
    randomNumbers[0] = (rand() % 70) + 1;
	randomNumbers[1] = (rand() % 70) + 1;	
	
	while(randomNumbers[0] == randomNumbers[1])
		randomNumbers[1] = (rand() % 70) + 1;	
		
	randomNumbers[2] = (rand() % 70) + 1;
	while(randomNumbers[1] == randomNumbers[2])
		randomNumbers[2] = (rand() % 70) + 1;	
		
	randomNumbers[3] = (rand() % 70) + 1;
	while(randomNumbers[2] == randomNumbers[3])
		randomNumbers[3] = (rand() % 70) + 1;	
		
	randomNumbers[4] = (rand() % 70) + 1;
	while(randomNumbers[3] == randomNumbers[4])
		randomNumbers[4] = (rand() % 70) + 1;	
}

//User numbers for array. Not letting user input the same number
void userNumbers(int userNumbersArray[])
{
	cout << "Welcome to the lottery! You get five guesses!" << endl;
	cout << endl << "Enter five digits between 1 and 70!" << endl;
	cout << "Digit one: ";
	cin >> userNumbersArray[0];
	cout << "Digit two: ";
	cin >> userNumbersArray[1];
	while(userNumbersArray[0] == userNumbersArray[1])
		{
		cout << "You cannot have matching digits! Please re-enter digit two! " << endl;
		cout << "Digit two: ";
		cin >> userNumbersArray[1];
		}
	cout << "Digit three: ";
	cin >> userNumbersArray[2];
	while(userNumbersArray[1] == userNumbersArray[2])
		{
		cout << "You cannot have matching digits! Please re-enter digit three! " << endl;
		cout << "Digit three: ";
		cin >> userNumbersArray[2];
		}
	cout << "Digit four: ";
	cin >> userNumbersArray[3];
	while(userNumbersArray[2] == userNumbersArray[3])
		{
		cout << "You cannot have matching digits! Please re-enter digit four! " << endl;
		cout << "Digit four: ";
		cin >> userNumbersArray[3];
		}
	cout << "Digit five: ";
	cin >> userNumbersArray[4];
	while(userNumbersArray[3] == userNumbersArray[4])
		{
		cout << "You cannot have matching digits! Please re-enter digit five! " << endl;
		cout << "Digit five: ";
		cin >> userNumbersArray[4];
		}
	cout << endl;
}