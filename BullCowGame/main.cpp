//
//  main.cpp
//  BullCowGame
//
//  Created by David Weatherill on 28/01/2019.
//  Copyright © 2019 Dave Weatherill. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

// declare global function prototypes
void PrintIntro();
void PlayGame();
string GetGuess();
void PrintBack();
// declare global variables
string Guess = "";
int NoOfTries = 5;

int main() {
    
// declare variables in main
//none
    
// introduce the game
	PrintIntro();
    
// play game
    PlayGame ();
    
    return 0;
}

// functions
void PrintIntro() {
    constexpr int WORD_LENGTH = 5;
    //    cout << "Welcome to Bulls and Cows\n";
    cout << "Welcome to Bulls and Cows" << endl;
    cout << "Can you guess the " << WORD_LENGTH << " letter isogram word I am thinking of?\n";
}

void PlayGame() {
    for (int x=1;x<=NoOfTries;x++) {
		
        //Get Guess function
        GetGuess();
		
        // Return the players Guess
		PrintBack();
    }
}

string GetGuess() {
    // get the players Guess
    getline (cin,Guess);
    return Guess;
}

void PrintBack() {
	cout << "Your guess was " << Guess << endl;
	cout << endl;
	return;
}

// end script ##BULLANDCOWGAME##
