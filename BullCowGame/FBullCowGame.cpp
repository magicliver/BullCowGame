//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by David Weatherill on 30/01/2019.
//  Copyright © 2019 Dave Weatherill. All rights reserved.
//

#include "FBullCowGame.hpp"
#include <string>

//constructor
FBullCowGame::FBullCowGame() {
    Reset();
}

int FBullCowGame::GetMaxTries() const {
    return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const {
    return MyCurrentTry;
}

void FBullCowGame::Reset() {
    constexpr int MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;
    
    MyCurrentTry = 1;
    return;
}

bool FBullCowGame::IsGameWon() const {
    return false;
}

bool FBullCowGame::CheckGuessValidity(std::string) const {
    return false;
}

