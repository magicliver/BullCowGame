//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by David Weatherill on 30/01/2019.
//  Copyright © 2019 Dave Weatherill. All rights reserved.
//

#include "FBullCowGame.hpp"
#include <map>
#define TMap std::map
// remove? #include <string>

//substituting std::string with FString - Unreal standard for non-user output
using FString = std::string;
//substituting int with int32 - Unreal xplatform standard ensuring 32 bit int
using int32 = int;

//constructor
FBullCowGame::FBullCowGame() {Reset();}

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}
int32 FBullCowGame::GetHiddenWordLength() const {return int(MyHiddenWord.length());}
bool FBullCowGame::IsGameWon() const {return bGameIsWon;}

void FBullCowGame::Reset() {
    const FString HIDDEN_WORD = "hornets";
    constexpr int32 MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    bGameIsWon = false;
    return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
    if (!IsIsogram(Guess)) { // if the guess is Not_Isogram
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
    else if (!IsLowercase(Guess)) {
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
    //note variable for hidden word length changing, the validation ensures guesss the same
    int32 WordLength = int(MyHiddenWord.length());
    for(int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
        //compare MHWChar MyHiddenWord Character vs GChar Guess Character
        for(int32 GChar = 0; GChar < WordLength; GChar++) {
            //if match then
            if (Guess[GChar] == MyHiddenWord[MHWChar]){
                //check position the same
                if (MHWChar == GChar) {
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

bool FBullCowGame::IsIsogram(FString Word) const {
    //treat 0 or 1 word as isograms cos they must be (ok but why not reorder switch cases?)
    if (Word.length() <= 1) { return true; }
    
    TMap<char, bool> LetterSeen; // set up our map
    
    for (auto Letter : Word) {//for all letters of the word
        Letter = tolower(Letter); //handle mix case
        if (LetterSeen[Letter]){
            return false; // NOT isogram
        }
        else {
            LetterSeen [Letter] = true; // add the letter to the map as seen
        }
    }
    return true; //for example in caes where /0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const {
    //loop though each letter checking if lowercase
    for (auto Letter : Word) {
        if (Letter != tolower(Letter)) {return false;}
    }
    return true;
}
