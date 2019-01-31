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


class FBullCowGame {
public:
    FBullCowGame();
    void Reset();
    int  GetMaxTries() const;
    int  GetCurrentTry() const;
    bool IsGameWon() const;
    bool CheckGuessValidity(std::string) const;
/* Other possibilities:
    int  IsogramLength();
    bool ReuseIsogram();
    bool Clue();
    bool TimeTrial();
    int MaxTimeMin();
 */
private:
    int MyCurrentTry;
    int MyMaxTries;
};


#endif /* FBullCowGame_hpp */
