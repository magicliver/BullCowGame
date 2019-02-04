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
void PrintGameSummary();
bool PlayAgain();
int32 GetHiddenWordLength();
FText GetValidGuess();


// declare global variables - can I get rid of this soon?
FText Guess = "";

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
    //    std::cout << "Welcome to Bulls and Cows\n";
    std::cout << "Welcome to Bulls and Cows" << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram word I am thinking of?\n";
}

void PlayGame() {
	BCGame.Reset();
	int32 MyMaxTries = BCGame.GetMaxTries();
	std::cout << "You have up to " << MyMaxTries << " tries. Good Luck!" << std::endl;
	
	//loop asking for guess while the game is NOT won and tries remain
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MyMaxTries) {
        //Get Guess function
		FText Guess = GetValidGuess(); //TODO: check guess valid
		// check if word is correct tb4 all the bull
		// submit vaild guess and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		// print number of bulls and cows
		std::cout << "Bulls: " << BullCowCount.Bulls;
		std::cout << "\nCows: " << BullCowCount.Cows << std::endl;
		
		//PrintBack(); Function now redundant

    }
	PrintGameSummary();
	return;
}

FText GetValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid;
	do {
		// get the players Guess
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		std::getline (std::cin,Guess);
		//check Guess is valid
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
			case EGuessStatus::Not_Isogram:
				std::cout << "Your guess is not an Isogram, all letters should be different";
				break;
			case EGuessStatus::Not_Enough_Letters:
				std::cout << "Guess too short! Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
				break;
			case EGuessStatus::Too_Many_Letters:
				std::cout << "Guess too long! Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
				break;
			case EGuessStatus::Non_Alphabetic_Characters:
				std::cout << "Guess contains non-Alphabetic characters!\n";
				break;
			case EGuessStatus::Not_Lower_Case:
				std::cout << "Guess should be all lower case characters. (Check Caps Lock is off?)\n";
				break;
			default:
				return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	return Guess;
}


void PrintGameSummary() {
	if (BCGame.IsGameWon()) {
		std::cout << "Congratulations. You are full of Bulls!! :) " << std::endl;
	}
	else
	{
		std::cout << "Unlucky, you are out of Tries!! :( " << std::endl;
	}
	return;
}


bool PlayAgain() {
	std::cout << "\nDo you want play again?";
	FText Response = "";
	getline(std::cin,Response);
	//std::cout << "Is it y/Y?" << (Response[0] == 'y'|| Response[0] == 'Y');
	//std::cout << std::endl;
	return (Response[0] == 'y'|| Response[0] == 'Y');
}

// end script ##BULLANDCOWGAME##
