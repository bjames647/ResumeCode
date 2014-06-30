// Brian James
// compass program
// 2/6/14

#include <iostream>
#include <string>
using namespace std;

void quadrant(int &, int &); //function to keep the program organized and easy to program with

int main()
{
	char selection;
	
	//these will hold the coordinates
	int x = 0;
	int y = 0;
	
	do
	{
		cout << "Enter a direction of N, S, E, W or Q to quit." << endl;
		cout << "Selection: ";
		cin >> selection;
		
		if(selection == 'n' || selection == 'N'){
			cout << "You chose North." << endl << endl;
			y = y + 1; //this equation will help hold the numbers for when we loop the program
			}
		
		//else if statements will help the program run faster instead of doing all if states
		else if(selection == 's' || selection == 'S'){
			cout << "You chose South." << endl << endl;
			y = y - 1;
			}
			
		else if(selection == 'e' || selection == 'E'){
			cout << "You chose East." << endl << endl;
			x = x + 1;
			}
			
		else if(selection == 'w' || selection == 'W'){
			cout << "You chose West." << endl << endl;
			x = x - 1;
			}
		
		else if(selection == 'q' || selection == 'Q'){
			cout << "You chose to quit." << endl << endl;
			system("pause");
			return 0; //this ends the program after the user presses a button
			}
			
		quadrant(x, y);
		cout << x << "," << y << endl << endl;
		
	}while(selection != 'q' || selection !='Q');
	
	//This displays the coordinates on the screen in a good fashion 
	cout << x << "," << y << endl;
	system("pause");

	return 0;
}

void quadrant(int &x, int &y)
{
	//NORTH
	if(x == 0 && y > 0){
		cout << "You are North." << endl;
		}
		
	else if(x > 0 && y > 0){
		cout << "You are North-east." << endl;
		}
		
	else if(x < 0 && y > 0){
		cout << "You are North-west." << endl;
		}
		
	//SOUTH	
	else if(x == 0 && y < 0){
		cout << "You are South." << endl;
		}
		
	else if(x < 0 && y < 0){
		cout << "You are South-west." << endl;
		}
		
	else if(x > 0 && y < 0){
		cout << "You are South-east." << endl;
		}
	
	//EAST
	else if(x > 0 && y == 0){
		cout << "You are East." << endl;
		}
	
	//WEST
	else if(x < 0 && y == 0){
		cout << "You are West." << endl;
		}
}
