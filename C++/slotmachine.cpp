#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void genRandNum(int &, int &, int &);
void inputBet(int &);
void playAgain(bool &, int &, int &);

	
const int cherries = 1;
const int oranges = 2;
const int plums = 3;
const int bells = 4;
const int melons = 5;
const int bars = 6;

int main()
{    
	int betInput;
	int totalBet = 0;
	int randomNum1;
	int randomNum2;
	int randomNum3;
	int totalWinnings = 0;
	int matches = 0;
	char yes;
	bool repeat = false;
	

	
	do
	{
	inputBet(betInput);
	
	genRandNum(randomNum1, randomNum2, randomNum3);
	
	matches = 0;
	
	totalBet = totalBet + betInput;
	
	if(randomNum1 == cherries)
		cout << "Cherries ";
	elif(randomNum1 == oranges)
		cout << "Oranges ";
	elif(randomNum1 == plums)
		cout << "Plums ";
	elif(randomNum1 == bells)
		cout << "Bells ";
	elif(randomNum1 == melons)
		cout << "Melons ";
	elif(randomNum1 == bars)
		cout << "Bars ";
	elif(randomNum2 == cherries)
		cout << "Cherries ";
	elif(randomNum2 == oranges)
		cout << "Oranges ";
	elif(randomNum2 == plums)
		cout << "Plums ";
	elif(randomNum2 == bells)
		cout << "Bells ";
	elif(randomNum2 == melons)
		cout << "Melons ";
	elif(randomNum2 == bars)
		cout << "Bars ";
	elif(randomNum3 == cherries)
		cout << "Cherries " << endl;
	elif(randomNum3 == oranges)
		cout << "Oranges " << endl;
	elif(randomNum3 == plums)
		cout << "Plums " << endl;
	elif(randomNum3 == bells)
		cout << "Bells " << endl;
	elif(randomNum3 == melons)
		cout << "Melons " << endl;
	elif(randomNum3 == bars)
		cout << "Bars " << endl;
		
	if(randomNum1 == randomNum2)
		matches = 1;
	if(randomNum2 == randomNum3)
		matches = 1;
	if(randomNum1 == randomNum3)
		matches = 1;
	if(randomNum1 == randomNum2 && randomNum2 == randomNum3)
		matches = 2;

		//display what matches
	if(matches == 0)
		{
		cout << endl << "Sorry you have won $0!" << endl;	
		}
	elif(matches == 1)
		{
		cout << endl << "Two of the words match! You have won twice the amount you bet!" << endl;
		totalWinnings = totalBet * 2;
		}
	elif(matches == 2)
		{
		cout << endl << "Three of the words match! You have won three times the amount you bet!" << endl;
		totalWinnings = totalBet * 3;
		}
	
	//cout << totalWinnings << endl;
	

	
	playAgain(repeat, totalWinnings, totalBet);
	
	}while(repeat == true);
    return 0;
}


void genRandNum(int &randomNum1, int &randomNum2, int &randomNum3)
{
    srand ((unsigned)time(NULL));
    randomNum1 = (rand() % 6) + 1;
	randomNum2 = (rand() % 6) + 1;
	randomNum3 = (rand() % 6) + 1;
	
}


void inputBet(int &betInput)
{
	cout <<  "How much would you like to bet?: $";
	cin >> betInput;
	cout << endl;

}


void playAgain(bool &repeat, int &totalWinnings, int &totalBet)
{	char yes;
	cout << endl << "Would you like to play again?: (y/n)" << endl;
	cin >> yes;
	if(yes == 'y')
		repeat = true;
	if(yes != 'y')
		{
		cout << "The total amount of money you bet was $" << totalBet << endl;
		cout << "The total amount of money you won was $" << totalWinnings;
		repeat = false;
		}
}