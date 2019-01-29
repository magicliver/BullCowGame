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

/*
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
*/

// declare global variables
string Guess = "";
// declare global functions
void PrintIntro();
string GetGuess();

int main(){
    
// declare variables in main
    int NoOfTries = 5;
    
// introduce the game
    PrintIntro();
    

    for (int x=1;x<=NoOfTries;x++) {
//Get Guess function
    GetGuess();
// Return the players Guess
        cout << "Your guess was " << Guess << endl;
    }
    
    return 0;
}

// functions
void PrintIntro() {
    constexpr int WORD_LENGTH = 5;
    //    cout << "Welcome to Bulls and Cows\n";
    cout << "Welcome to Bulls and Cows" << endl;
    cout << "Can you guess the " << WORD_LENGTH << " letter isogram word I am thinking of?\n";
}

string GetGuess() {
    // get the players Guess
    getline (cin,Guess);
    return Guess;
}
