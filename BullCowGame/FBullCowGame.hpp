//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by David Weatherill on 30/01/2019.
//  Copyright © 2019 Dave Weatherill. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

#pragma once

//substituting std::string with FString - Unreal standard for non-user output
using FString = std::string;
//substituting int with int32 - Unreal xplatform standard ensuring 32 bit int
using int32 = int;

// all values initialised to zero
struct FBullCowCount {
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus {
    Invalid,
    OK,
    Not_Isogram,
    Not_Enough_Letters,
    Too_Many_Letters,
    Non_Alphabetic_Characters,
    Not_Lower_Case
};

class FBullCowGame {
public:
    FBullCowGame();
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool IsGameWon() const;
    void Reset(); //TODO: richer returned value later
    EGuessStatus CheckGuessValidity(FString) const;
    FBullCowCount SubmitValidGuess(FString);
/* Other possibilities:
    int32  IsogramLength();
    bool ReuseIsogram();
    bool Clue();
    bool TimeTrial();
    int32 MaxTimeMin();
 */
private:
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
    bool bGameIsWon;
    bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};


#endif /* FBullCowGame_hpp */
