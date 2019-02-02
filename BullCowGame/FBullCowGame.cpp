//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by David Weatherill on 30/01/2019.
//  Copyright © 2019 Dave Weatherill. All rights reserved.
//

#include "FBullCowGame.hpp"
#include <string>

//substituting std::string with FString - Unreal standard for non-user output
using FString = std::string;
//substituting int with int32 - Unreal xplatform standard ensuring 32 bit int
using int32 = int;

//constructor
FBullCowGame::FBullCowGame() {
    Reset();
}

int32 FBullCowGame::GetMaxTries() const {
    return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const {
    return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const {
    return int(MyHiddenWord.length());
}

void FBullCowGame::Reset() {
    constexpr int32 MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;
    const FString HIDDEN_WORD = "hornets";
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    return;
}

bool FBullCowGame::IsGameWon() const {
    return false;
}

bool FBullCowGame::CheckGuessValidity(FString) const {
    return false;
}

//Receive VALID guess, increment turn and return count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess){
    //increment turn number if valid
    MyCurrentTry++;
    //debug code: std::cout << "Test we got the uses Guess: " << Guess;
    //set up a return variable
    FBullCowCount BullCowCount;
    //loop through all letters in the guess
    int32 HiddenWordLength = int(MyHiddenWord.length());
    for(int32 i=0; i<HiddenWordLength; i++) {
        //compare letter against the hidden word
        for(int32 j=0; j<HiddenWordLength; j++) {
            //if match then
            if (Guess[j] == MyHiddenWord[i]){
                //check position the same
                if (i == j) {
                   //increment bulls
                    BullCowCount.Bulls++;
                }
                else {
                //if position not same
                    //increment cows
                    BullCowCount.Cows++;
                }
            }
        }
    }
    
    return BullCowCount;
}
