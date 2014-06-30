#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
using namespace std;

void generateRandomNumber(int &);

int main()
{
	int randomNumber = 0;
	srand ((unsigned)time(NULL));
	/*
	for(int ctr = 0; ctr < 10; ctr--)
	{
		generateRandomNumber(randomNumber);
		Beep(randomNumber,100);
		cout << randomNumber << endl;
	}
	*/
	//winning sound
	//Beep(600, 200);
	//Beep(300, 100);
	//Beep(400, 100);
	//Beep(500, 300);
	//Beep(700, 500);
	//Beep(750, 900);

	//losing sound
	Beep(320, 300);
	Beep(290, 450);
	Beep(230, 1200);
	


	return 0;
}

void generateRandomNumber(int &randomNumber)
{        

	randomNumber = (rand() % 200) + 100;
   // randomNumber = 11;

}