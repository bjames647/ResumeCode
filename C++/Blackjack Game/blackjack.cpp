//Brian James
//Intro to programming logic
//12-16-13
//Blackjack final project

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
using namespace std;

void dealingAnimation(int &, bool &);
void generateRandomNumber(int &);
void playerTurn(int &,int &, int &, bool &, bool &);
void table(int &, int &, bool &);
void ifAce(int &);
void computerTurn(int &, int &);
void decideWinner(int &, int &, bool &);
void computerFirstNumber(int &);
void firstRound(int &, int &, int &);

//This game has sounds to make sure your speakers are at the proper volume

int main()
{
	int randomNumber = 0;
	int playerTotal = 0;
	int computerTotal = 0;
	int menuOption;
	int randomInt = 0;
	char yes;
	bool playAgain = false;
	bool firstDeal = true;
	bool blackjack = false;

	srand ((unsigned)time(NULL));
	
	system("cls");	
	cout << "**                                          **" << endl;
	cout << "      Welcome to the game of Blackjack!" << endl;
	cout << "**                                          **" << endl;
	cout << endl << endl;
	cout << "1. Play Game" << endl << endl;
	cout << "2. Quit Game" << endl << endl;
	cout << "Selection: ";
	cin >> menuOption;
	
	while(menuOption < 1 || menuOption > 2)
		{
		cout << "You entered an invalid option! Please enter in one of the options listed above!" << endl;
		cout << "Selection: ";		
		cin >> menuOption;
		}
	
	switch(menuOption)
	{
		case 1:
			do
			{
				firstRound(randomInt, computerTotal, playerTotal);
				
				playerTurn(randomNumber, computerTotal, playerTotal, firstDeal, blackjack);
				
				if(blackjack == true)
					decideWinner(computerTotal, playerTotal, blackjack);
					
				else if(blackjack == false)
					computerTurn(randomNumber, computerTotal);

				else if(playerTotal == 21)
					decideWinner(computerTotal, playerTotal, blackjack);

				else if(playerTotal > 21)
					decideWinner(computerTotal, playerTotal, blackjack);
					
				else
					decideWinner(computerTotal, playerTotal, blackjack);
				
				cout << "Would you like to play again?(y/n)" << endl;
				cout << "Selection: ";	
				cin >> yes;
		   
				if ( yes == 'y' || yes == 'Y')
					{
					playAgain = true;
					computerTotal = 0;
					playerTotal = 0;
					}
					
				else if ( yes != 'y' || yes != 'Y')
					{
					cout << "Thanks for playing Blackjack! Good bye!" << endl;
					playAgain = false;
					}
			}while(playAgain == true);
		case 2:
			cout << "Quitting!" << endl;
			break;
	}
	
	return 0;
}

void generateRandomNumber(int &randomNumber)
{        
	randomNumber = (rand() % 11) + 1;
}

void computerFirstNumber(int &randomInt)
{
	randomInt = (rand() % 11) + 1;
}

//This changes the random number to a one if the generated number was eleven and would cause the player
//or computer to go over 21
void ifAce(int &randomNumber)
{
	randomNumber = 1;	
}

void firstRound(int &randomInt, int &computerTotal, int &playerTotal)
{
	int compFirstCard = 0;
	
	system("CLS");
	cout << "**                                              **" << endl;
	cout << "      The computer will get two cards first!" << endl;
	cout << "**                                              **" << endl << endl;
	
	for(int i = 0; i < 2; i++)
		{
		computerFirstNumber(randomInt);
		if(i == 0)
			{
			cout << "Computer's first card is: " << randomInt << endl;
			Sleep(700);
			cout << "The other card is hidden!" << endl;
			compFirstCard = randomInt;
			}
		computerTotal = computerTotal + randomInt;	
		}
		
	Sleep(700);
	if(compFirstCard < 10)
	{
		cout << "   __ " << endl;
		cout << " _|" << compFirstCard <<" |" << endl;
		cout << "| |__|" << endl;
		cout << "|__|" << endl;
	}
	
	else if(compFirstCard >= 10)
	{
		cout << "   __ " << endl;
		cout << " _|" << compFirstCard <<"|" << endl;
		cout << "| |__|" << endl;
		cout << "|__|" << endl;
	}
	
	system("pause");

}

void computerTurn(int &randomNumber, int &computerTotal)
{
	bool first = true;
	
	system("CLS");
	cout << "**                         **" << endl;
	cout << "      Computer's turn!" << endl;
	cout << "**                         **" << endl;

	while(computerTotal < 17)
	{
		generateRandomNumber(randomNumber);
		
		if(randomNumber == 11 && computerTotal >= 11)
			ifAce(randomNumber);
			
		cout << "Computer's card is: " << randomNumber << endl;
		
		computerTotal = computerTotal + randomNumber;
		
		system("pause");

		first = false;
	}
	
	cout << "Computer's total is: " << computerTotal << endl;
	
	system("pause");
}



void playerTurn(int &randomNumber, int &computerTotal, int &playerTotal, bool &firstDeal, bool &blackjack)
{
	bool hit = false;
	char hitOrStay;
	firstDeal = true;
	
	do
	{
		hit = false;
		
		if(firstDeal == true)
			{
			for(int counter = 0; counter < 1; counter++)
				{
				generateRandomNumber(randomNumber);
				
				dealingAnimation(computerTotal, firstDeal);
				
				playerTotal = playerTotal + randomNumber;
				
				if(randomNumber == 11 && playerTotal >= 11)
					ifAce(randomNumber);

				table(computerTotal, playerTotal, firstDeal);
				
				system("pause");

				if(counter == 1)
					firstDeal = false;
				
				if(randomNumber == 10 && playerTotal == 11)
					{
					blackjack = true;
					}
				
				else if(randomNumber == 11 && playerTotal == 10)
					{
					blackjack = true;
					}
				}
			}
		
		generateRandomNumber(randomNumber);
		
		if(randomNumber == 11 && playerTotal >= 11)
			ifAce(randomNumber);
		
		playerTotal = playerTotal + randomNumber;
		
		dealingAnimation(computerTotal, firstDeal);
		
		table(computerTotal, playerTotal, firstDeal);
				
		cout << "Your card was " << randomNumber << "." << endl;
		cout << "Your total is " << playerTotal << "." << endl;
		cout << "Would you like to hit or stay?(h/s)" << endl;
		cout << "Selection: ";	
		cin >> hitOrStay;
		
		if(hitOrStay == 'h' || hitOrStay == 'H')
			{
			hit = true;
			firstDeal = false;
			}
		
		else
			break;
		
	}while(playerTotal < 21 && hit == true);
}

//This function decides if the player wins or if the computer wins
void decideWinner(int &computerTotal, int &playerTotal, bool &blackjack)
{
	if(computerTotal > playerTotal && computerTotal <= 21)
	{
		cout << "The computer was closer to 21 than you!" << endl;
		cout << "You lost!" << endl;
		//losing sound
		Beep(320, 300);
		Beep(290, 450);
		Beep(230, 1200);
	}
	
	else if (playerTotal > 21)
	{
		cout << "You went over 21!" << endl;
		//losing sound
		Beep(320, 300);
		Beep(290, 450);
		Beep(230, 1200);
	}
	
	else if(playerTotal == computerTotal)
	{
		cout << "**                                       **" << endl;
		cout << "     You tied the computer! You win!" << endl;
		cout << "**                                       **" << endl;	
		//winning sound
		Beep(600, 200);
		Beep(300, 100);
		Beep(400, 100);
		Beep(500, 300);
		Beep(700, 500);
		Beep(750, 900);
	}
	
	else if(blackjack == true)
		{
		cout << "**                        **" << endl;
		cout << "    You got blackjack!" << endl;
		cout << "          You win!" << endl;
		cout << "**                        **" << endl;
		
		//winning sound
		Beep(600, 200);
		Beep(300, 100);
		Beep(400, 100);
		Beep(500, 300);
		Beep(700, 500);
		Beep(750, 900);
	}
		
	else
	{
		cout << "**                                                        **" << endl;
		cout << "     You were closer to 21 than the computer! You win!" << endl;
		cout << "**                                                        **" << endl;
		
		//winning sound
		Beep(600, 200);
		Beep(300, 100);
		Beep(400, 100);
		Beep(500, 300);
		Beep(700, 500);
		Beep(750, 900);
	}
}

//This function is the static table
void table(int &computerTotal, int &playerTotal, bool &firstDeal)
{
	system("cls");
	if(firstDeal == true)
		{
		cout << "**                                              **" << endl;
		cout << "      Now you will get your first two cards!" << endl;
		cout << "**                                              **" << endl;
		}
	
	else
		{
		cout << "**                     **" << endl;
		cout << "      Your turn!" << endl;
		cout << "**                     **" << endl << endl;
		}
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << " \\            Computer Total    /" << endl;
	cout << "  \\    Your Total    |         /" << endl;
	cout << "   \\       |         |        /" << endl;
	cout << "    \\______" << playerTotal << "_______" << computerTotal << "________/" << endl;


}

//Your random number animation thing made me want to do animation in a game. 
//I thought an animated blackjack table would be a perfect opportunity to do this.
void dealingAnimation(int &computerTotal, bool &firstDeal)
{

	system("CLS");
	cout << "**                  	     **" << endl;
	cout << "      Dealing your card!" << endl;
	cout << "**                 	     **" << endl << endl;
		
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << " \\                              /" << endl;
	cout << "  \\                            /" << endl;
	cout << "   \\                          /" << endl;
	cout << "    \\_______________" << computerTotal << "_______/" << endl;

	Sleep(100);
	system("cls");
	
	cout << "**                           **" << endl;
	cout << "      Dealing your card!" << endl;
	cout << "**                           **" << endl << endl;	
	cout << "|              __               |" << endl;
	cout << "|             |  |              |" << endl;
	cout << "|             |__|              |" << endl;
	cout << "|                               |" << endl;
	cout << " \\                              /" << endl;
	cout << "  \\                            /" << endl;
	cout << "   \\                          /" << endl;
	cout << "    \\_______________" << computerTotal << "_______/" << endl;

	Sleep(100);
	system("cls");
	
	
	cout << "**                           **" << endl;
	cout << "      Dealing your card!" << endl;
	cout << "**                           **" << endl << endl;
	
	cout << "|                               |" << endl;
	cout << "|              __               |" << endl;
	cout << "|             |  |              |" << endl;
	cout << "|             |__|              |" << endl;
	cout << " \\                              /" << endl;
	cout << "  \\                            /" << endl;
	cout << "   \\                          /" << endl;
	cout << "    \\_______________" << computerTotal << "_______/" << endl;

	Sleep(100);
	system("cls");
	
	
	cout << "**                           **" << endl;
	cout << "      Dealing your card!" << endl;
	cout << "**                           **" << endl << endl;
	
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << "|              __               |" << endl;
	cout << "|             |  |              |" << endl;
	cout << " \\           |__|               /" << endl;
	cout << "  \\                            /" << endl;
	cout << "   \\                          /" << endl;
	cout << "    \\_______________" << computerTotal << "_______/" << endl;

	Sleep(100);
	system("cls");
	
	
	cout << "**                           **" << endl;
	cout << "      Dealing your card!" << endl;
	cout << "**                           **" << endl << endl;
	
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << "|              __               |" << endl;
	cout << " \\           |  |               /" << endl;
	cout << "  \\          |__|              /" << endl;
	cout << "   \\                          /" << endl;
	cout << "    \\_______________" << computerTotal << "_______/" << endl;

	Sleep(100);
	system("cls");
	
	
	cout << "**                           **" << endl;
	cout << "      Dealing your card!" << endl;
	cout << "**                           **" << endl << endl;
	
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << " \\            __                /" << endl;
	cout << "  \\          |  |              /" << endl;
	cout << "   \\         |__|             /" << endl;
	cout << "    \\_______________" << computerTotal << "_______/" << endl;

	Sleep(100);
	system("cls");
	
	
	cout << "**                           **" << endl;
	cout << "      Dealing your card!" << endl;
	cout << "**                           **" << endl << endl;
	
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << " \\                              /" << endl;
	cout << "  \\           __               /" << endl;
	cout << "   \\         |  |             /" << endl;
	cout << "    \\________|__|___" << computerTotal << "_______/" << endl;

	Sleep(100);
	system("cls");
	
	
	cout << "**                           **" << endl;
	cout << "      Dealing your card!" << endl;
	cout << "**                           **" << endl << endl;
	
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << " \\                              /" << endl;
	cout << "  \\                            /" << endl;
	cout << "   \\          __              /" << endl;
	cout << "    \\________|__|___"<< computerTotal << "_______/" << endl;

	Sleep(100);
	system("cls");
	
	
	cout << "**                           **" << endl;
	cout << "      Dealing your card!" << endl;
	cout << "**                           **" << endl << endl;
	
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << "|                               |" << endl;
	cout << " \\                              /" << endl;
	cout << "  \\                            /" << endl;
	cout << "   \\                          /" << endl;
	cout << "    \\_______________" << computerTotal << "_______/" << endl;
	
	Sleep(100);
}