//
//  main.cpp
//  BullCowGame
//
//  Created by Dave Weatherill on 28/01/2019.
//  Copyright © 2019 Dave Weatherill. All rights reserved.
//  Modified: 30/01/19 Class created
//

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

//using namespace std;
//^^ bad parctice (?) so commenting out and qualifying namespaces

// declare global function prototypes
void PrintIntro();
void PlayGame();
std::string GetGuess();
void PrintBack();
bool PlayAgain();

// declare global variables
std::string Guess = "";
int NoOfTries = 5;

// Instantiate classes
FBullCowGame BCGame;  //instantiate a new game

int main() {
	
// play game
	do {
		PrintIntro();
		PlayGame ();
	}
	// Ask if want to play again
	while (PlayAgain());

    return 0;
}

// functions
void PrintIntro() {
    constexpr int WORD_LENGTH = 5;
    //    std::cout << "Welcome to Bulls and Cows\n";
    std::cout << "Welcome to Bulls and Cows" << std::endl;
    std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram word I am thinking of?\n";
}

void PlayGame() {
	BCGame.Reset();
	int MyMaxTries = BCGame.GetMaxTries();
	std::cout << MyMaxTries << std::endl;
	//loop for the number of turns for guesses
	// TODO: change to while look to test Max tries against current
    for (int x=1;x<=MyMaxTries;x++) {
        //Get Guess function
		GetGuess(); //TODO: check guess valid
		// submit vaild guess
		// print number of bulls and cows
        // Return the players Guess
		PrintBack();
    }
	//TODO: summarize game
}

std::string GetGuess() {
	int CurrentTry = BCGame.GetCurrentTry();
    // get the players Guess
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline (std::cin,Guess);
    return Guess;
}

void PrintBack() {
	std::cout << "Your guess was " << Guess << std::endl;
	std::cout << std::endl;
	return;
}

bool PlayAgain() {
	std::cout << "Do you want play again?";
	std::string Response = "";
	getline(std::cin,Response);
	//std::cout << "Is it y/Y?" << (Response[0] == 'y'|| Response[0] == 'Y');
	//std::cout << std::endl;
	return (Response[0] == 'y'|| Response[0] == 'Y');
}

// end script ##BULLANDCOWGAME##
