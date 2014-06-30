//Brian James
//c++
//random number program
//This game generates random numbers as the stats for the characters.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void generateStats(int &, int &);
void generateEnemy(int &, int &, int&);
void genRandNum(int &);
void battleSystem(int &, int &, int &, int &, int &, int &);

int main() {
    
    bool play = true;
    bool playAgain = true;
    bool charSelectScreen = true;
    bool warrior = false;
    bool mage = false;
    
    char playAgainChoice;
    string name;
    int charSelect = 0;
    
    int playerHealth = 100;
    int playerAttack = 0;
    int playerIntellect = 0;
    
    int enemyHealth = 0;
    int enemyAttack = 0;
    int enemyIntellect = 0;
    
    int ranNum = 0;
    
    srand ((unsigned)time(NULL)); //generate random number seed
        
    do //Main game loop
    {
        while(charSelectScreen == true){
            cout << "Choose your class." << endl;
            cout << "1. Warrior" << endl;
            cout << "2. Mage" << endl;
            cin >> charSelect;
            if(charSelect == 1){
                warrior = true;  
                charSelectScreen = false;
            }
            else if(charSelect == 2){
                mage = true;
                charSelectScreen = false;
            }
        }
        
        while(warrior == true && playAgain == true){
            cout << "You selected the warrior class." << endl;
            cout << "What is your name, warrior? : ";
            cin >> name;
            
            generateStats(playerAttack, playerIntellect);
            
            cout << name << " Stats: " << endl;
            cout << "Attack: " << playerAttack << endl;
            cout << "Intellect: " << playerIntellect << endl;
            
            cout << "You have been called to the arena. Time to fight!" << endl;
            
            genRandNum(ranNum);
            
            if(ranNum == 1){
                cout << "Your opponent is a goblin!" << endl;
            }
            else if(ranNum == 2){
                cout << "Your opponent is a orc!" << endl;
            }
            else if(ranNum == 3){
                cout << "Your opponent is a nazi!" << endl;
            }
            
            generateEnemy(enemyHealth, enemyAttack, enemyIntellect);
            
            while(playerHealth > 0 && enemyHealth > 0){
                
                battleSystem(playerHealth, playerAttack, playerIntellect, enemyHealth, enemyAttack, enemyIntellect);
            }
            
            cout << "Would you like to play again?(y/n): " << endl;
            cin >> playAgainChoice;
            
            if(playAgainChoice == 'y' || playAgainChoice == 'Y'){
                playAgain = true;
            }
            else
                playAgain = false;
            
            
        }
        
        while(mage == true && playAgain == true){
            cout << "You selected the mage class." << endl;
            cout << "What is your name, mage? : ";
            cin >> name;
            
            generateStats(playerAttack, playerIntellect);
            
            cout << name << " Stats: " << endl;
            cout << "Attack: " << playerAttack << endl;
            cout << "Intellect: " << playerIntellect << endl;
            
            
            cout << "You have been called to the arena. Time to fight!" << endl;
            
            genRandNum(ranNum);
            
            if(ranNum == 1){
                cout << "Your opponent is a goblin!" << endl;
            }
            else if(ranNum == 2){
                cout << "Your opponent is a orc!" << endl;
            }
            else if(ranNum == 3){
                cout << "Your opponent is a nazi!" << endl;
            }
            
            generateEnemy(enemyHealth, enemyAttack, enemyIntellect);
            
            while(playerHealth > 0 && enemyHealth > 0){
                
                battleSystem(playerHealth, playerAttack, playerIntellect, enemyHealth, enemyAttack, enemyIntellect);
            }
            
            cout << "Would you like to play again?(y/n): " << endl;
            cin >> playAgainChoice;
            
            if(playAgainChoice == 'y' || playAgainChoice == 'Y'){
                playAgain = true;
            }
            else
				system("pause");
                playAgain = false;
				play = false;
        }
		
    }while(play == true);
}

//This generates the stats for the player
void generateStats(int &playerAttack, int &playerIntellect){
    playerAttack = (rand() % 10) + 5;
    playerIntellect = (rand() % 5) + 1;
}

//This generates the stats for the enemy
void generateEnemy(int &enemyHealth, int &enemyAttack, int&enemyIntellect){
    enemyHealth = (rand() % 50) + 30;
    enemyAttack = (rand() % 6) + 1;
    enemyIntellect = (rand() % 3) + 1;
}

//This generates the random number deciding what enemy is chosen
void genRandNum(int &ranNum){
    ranNum = (rand() % 3) + 1;
}

//This runs the battle system for the game
void battleSystem(int &playerHealth, int &playerAttack, int &playerIntellect, int &enemyHealth, int &enemyAttack, int &enemyIntellect){
    
    int attackDif = 0;
    int intellectDif = 0;
    int aOrM = 0;
    
    cout << "Would you like to attack or use magic?" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Magic" << endl;
    cin >> aOrM;
    
    if(aOrM == 1){
        cout << endl;
        cout << "You chose attack!" << endl;
        
        attackDif = playerAttack - enemyAttack;
        enemyHealth = enemyHealth - playerAttack;
        playerHealth = playerHealth - attackDif;
        
        cout << "Enemy health: " << enemyHealth << endl;
        cout << "Player health: " << playerHealth << endl;
    }
    
    else if(aOrM == 2){
        cout << endl;
        cout << "You chose magic!" << endl;
        
        intellectDif = playerIntellect - enemyIntellect;
        enemyHealth = enemyHealth - playerIntellect;
        playerHealth = playerHealth - intellectDif;
        
        cout << "Enemy health: " << enemyHealth << endl;
        cout << "Player health: " << playerHealth << endl;
    }
}