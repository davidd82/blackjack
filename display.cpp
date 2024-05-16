/*
display.cpp
*/

#include "display.h"
#include <iostream>
#include <vector>
#include <set>


// Sets size data member to user input
Display::Display() {
    aces.insert(12);
    aces.insert(25);
    aces.insert(38);
    aces.insert(51);

    kings.insert(11);
    kings.insert(24);
    kings.insert(37);
    kings.insert(50);

    queens.insert(10);
    queens.insert(23);
    queens.insert(36);
    queens.insert(49);

    jacks.insert(9);
    jacks.insert(22);
    jacks.insert(35);
    jacks.insert(48);
}

//Destructor. releases resources
Display::~Display() {

}

// This function handles the printing of the current hand
void Display::print_hand(std::vector<int>& hand)
{
    // Print the top of every card in the hand
    for (int i = 0; i < hand.size(); i++) {
        std::cout<<" ___  ";
    }

    std::cout << std::endl;

    // Print the section of the card that shows the type and suit
    for (int i = 0; i < hand.size(); i++) {
        std::cout<<"|";

        // Figure out which type to print (Face or number)
        if (aces.count(hand[i])) {
            std::cout << "A";
        } else if (kings.count(hand[i])) {
            std::cout << "K";
        } else if (queens.count(hand[i])) {
            std::cout << "Q";
        } else if (jacks.count(hand[i])) {
            std::cout << "J";
        } else {
            if (hand[i] < 9 && hand[i] >= 0) {
                std::cout << hand[i] + 1;
            } else if (hand[i] < 22 && hand[i] >= 13) {
                std::cout << hand[i] - 12;
            } else if (hand[i] < 35 && hand[i] >= 26) {
                std::cout << hand[i] - 25;
            } else if (hand[i] < 48 && hand[i] >= 39) {
                std::cout << hand[i] - 38;
            }
        }

        // Figure out which suit to print
        if (hand[i] < 13 && hand[i] >= 0) {
            std::cout << "H";
        } else if (hand[i] < 26 && hand[i] >= 13) {
            std::cout << "D";
        } else if (hand[i] < 39 && hand[i] >= 26) {
            std::cout << "S";
        } else if (hand[i] < 52 && hand[i] >= 39) {
            std::cout << "C";
        }

        std::cout << " | ";
    }

    std::cout << std::endl;

    // Print the bottom of every card
    for (int i = 0; i < hand.size(); i++) {
        std::cout<<"|___| ";
    }

    std::cout << std::endl;
}

// This function handles the printing of the dealer hand with one card
void Display::print_hand_dealer(std::vector<int>& hand)
{
    // Print the top of every card in the hand
    for (int i = 0; i < 1; i++) {
        std::cout<<" ___  ";
    }

    std::cout << " ___  ";

    std::cout << std::endl;

    // Print the section of the card that shows the type and suit
    for (int i = 0; i < 1; i++) {
        std::cout<<"|";

        // Figure out which type to print (Face or number)
        if (aces.count(hand[i])) {
            std::cout << "A";
        } else if (kings.count(hand[i])) {
            std::cout << "K";
        } else if (queens.count(hand[i])) {
            std::cout << "Q";
        } else if (jacks.count(hand[i])) {
            std::cout << "J";
        } else {
            if (hand[i] < 9 && hand[i] >= 0) {
                std::cout << hand[i] + 1;
            } else if (hand[i] < 22 && hand[i] >= 13) {
                std::cout << hand[i] - 12;
            } else if (hand[i] < 35 && hand[i] >= 26) {
                std::cout << hand[i] - 25;
            } else if (hand[i] < 48 && hand[i] >= 39) {
                std::cout << hand[i] - 38;
            }
        }

        // Figure out which suit to print
        if (hand[i] < 13 && hand[i] >= 0) {
            std::cout << "H";
        } else if (hand[i] < 26 && hand[i] >= 13) {
            std::cout << "D";
        } else if (hand[i] < 39 && hand[i] >= 26) {
            std::cout << "S";
        } else if (hand[i] < 52 && hand[i] >= 39) {
            std::cout << "C";
        }

        std::cout << " | ";
    }

    std::cout << "|   | ";

    std::cout << std::endl;

    // Print the bottom of every card
    for (int i = 0; i < 1; i++) {
        std::cout<<"|___| ";
    }

    std::cout << "|___| ";

    std::cout << std::endl;
}

int Display::find_score(std::vector<int>& hand)
{
    int low_aces = 0;
    int high_aces = 0;

    // Calculate score when aces are worth 1
    for(int i = 0; i < hand.size(); i++) {
        if (aces.count(hand[i])) {
            low_aces = low_aces + 1;
        } else if (kings.count(hand[i])) {
            low_aces = low_aces + 10;
        } else if (queens.count(hand[i])) {
            low_aces = low_aces + 10;
        } else if (jacks.count(hand[i])) {
            low_aces = low_aces + 10;
        } else {
            if (hand[i] < 9 && hand[i] >= 0) {
                low_aces = low_aces + (hand[i] + 1);
            } else if (hand[i] < 22 && hand[i] >= 13) {
                low_aces = low_aces + (hand[i] - 12);
            } else if (hand[i] < 35 && hand[i] >= 26) {
                low_aces = low_aces + (hand[i] - 25);
            } else if (hand[i] < 48 && hand[i] >= 39) {
                low_aces = low_aces + (hand[i] - 38);
            }
        }
    }

    // If blackjack hit then return 21
    if (low_aces == 21) {
        return 21;
    }

    // Calculate score when aces are worth 11
    for(int i = 0; i < hand.size(); i++) {
        if (aces.count(hand[i])) {
            high_aces = high_aces + 11;
        } else if (kings.count(hand[i])) {
            high_aces = high_aces + 10;
        } else if (queens.count(hand[i])) {
            high_aces = high_aces + 10;
        } else if (jacks.count(hand[i])) {
            high_aces = high_aces + 10;
        } else {
            if (hand[i] < 9 && hand[i] >= 0) {
                high_aces = high_aces + (hand[i] + 1);
            } else if (hand[i] < 22 && hand[i] >= 13) {
                high_aces = high_aces + (hand[i] - 12);
            } else if (hand[i] < 35 && hand[i] >= 26) {
                high_aces = high_aces + (hand[i] - 25);
            } else if (hand[i] < 48 && hand[i] >= 39) {
                high_aces = high_aces + (hand[i] - 38);
            }
        }
    }

    // If blackjack is hit then return 21
    if (high_aces == 21) {
        return 21;
    }

    // Return highest score below 21 else just return whichever
    if (high_aces < 21) {
        return high_aces;
    } else if (low_aces < 21) {
        return low_aces;
    } else {
        return high_aces;
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
     ___   ___ 
    |KS | |QS |
    |___| |___| 
    



*/