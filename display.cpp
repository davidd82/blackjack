/*
display.cpp
*/

#include "display.h"
#include <iostream>
#include <vector>

// Sets size data member to user input
Display::Display() {

}

//Destructor. releases resources
Display::~Display() {

}

// This function handles the printing of the current state of the board
void Display::print_hand(std::vector<int>& hand)
{
    for (int i = 0; i < hand.size(); i++) {

    }
}

/*
    0-12 HEARTS
    13-25 DIAMONDS
    26-38 SPADES
    39-51 CLUBS

    A = 12, 25, 38, 51
    K = 11, 24, 37, 50
    Q = 10, 23, 36, 49
    J =  9, 22, 35, 48
    





*/