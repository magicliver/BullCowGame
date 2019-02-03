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
    bGameIsWon = false;
    return;
}

bool FBullCowGame::IsGameWon() const {
    return bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
    if (false) { // if the guess is Not_Isogram
        return EGuessStatus::Not_Isogram;
        }
// if the guess Not_Enough_Letters
    else if (Guess.length() < GetHiddenWordLength()) {
        return EGuessStatus::Not_Enough_Letters;
    }
// if the guess Too_Many_Letters
    else if (Guess.length() > GetHiddenWordLength()) {
        return EGuessStatus::Too_Many_Letters;
    }
// if the guess Not_Alpha_Numeric
    else if (false) {
        return EGuessStatus::Non_Alphabetic_Characters;
    }
// if the guess Not_Lower_Case
    else if (false) {
        return EGuessStatus::Not_Lower_Case;
    }
// otherwise
        else {
            return EGuessStatus::OK;
    }
}

//Receive VALID guess, increment turn and return count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess){
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
    if (BullCowCount.Bulls == GetHiddenWordLength()) {
        bGameIsWon = true;
    }
    else {
        bGameIsWon = false;
    }
    return BullCowCount;
}
