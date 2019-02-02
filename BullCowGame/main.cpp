//
//  main.cpp
//  BullCowGame
//
//  Created by Dave Weatherill on 28/01/2019.
//  Copyright © 2019 Dave Weatherill. All rights reserved.
//  Modified: 30/01/19 Class created
//
/*
 This is the console executable that makes use of the BullCowGame class.
 This act as the view in a MVC (Model-View-Control) pattern and is
 and is respnsible for all user interaction.
 For game logic see the FBullCowGame class
 */
#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

//using namespace std;
//^^ bad parctice (?) so commenting out and qualifying namespaces

//substituting std::string with FText - Unreal standard for user output
using FText = std::string;
//substituting int with int32 - Unreal xplatform standard ensuring 32 bit int
using int32 = int;

// declare global function prototypes
void PrintIntro();
void PlayGame();
int32 GetHiddenWordLength();
FText GetGuess();
void PrintBack();
bool PlayAgain();


// declare global variables
FText Guess = "";
/* NoOfTries no longer needed, MaxTries in class now
int32 NoOfTries = 5;
*/

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
	int32 WORD_LENGTH = BCGame.GetHiddenWordLength();
    //    std::cout << "Welcome to Bulls and Cows\n";
    std::cout << "Welcome to Bulls and Cows" << std::endl;
    std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram word I am thinking of?\n";
}

void PlayGame() {
	BCGame.Reset();
	int32 MyMaxTries = BCGame.GetMaxTries();
	std::cout << MyMaxTries << std::endl;
	//loop for the number of turns for guesses
	// TODO: change to while look to test Max tries against current
    for (int32 i=1;i<=MyMaxTries;i++) {
        //Get Guess function
		FText Guess = GetGuess(); //TODO: check guess valid
		// check if word is correct tb4 all the bull

		// submit vaild guess and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// print number of bulls and cows
		std::cout << "Bulls: " << BullCowCount.Bulls;
		std::cout << "\nCows: " << BullCowCount.Cows << std::endl;
		
		//PrintBack(); Function now redundant

    }
	//TODO: summarize game
}

FText GetGuess() {
	int32 CurrentTry = BCGame.GetCurrentTry();
    // get the players Guess
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline (std::cin,Guess);
    return Guess;
}

/* Redundant function all now handled in PlayGame
void PrintBack() {
	std::cout << "Your guess was " << Guess << std::endl;
	std::cout << std::endl;
	return;
}
*/

bool PlayAgain() {
	std::cout << "Do you want play again?";
	FText Response = "";
	getline(std::cin,Response);
	//std::cout << "Is it y/Y?" << (Response[0] == 'y'|| Response[0] == 'Y');
	//std::cout << std::endl;
	return (Response[0] == 'y'|| Response[0] == 'Y');
}

// end script ##BULLANDCOWGAME##
