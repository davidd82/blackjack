/*
deck.cpp
*/

#include "deck.h"
#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>

using namespace std;

// Sets size data member to user input
Deck::Deck() {
    for (int i = 0; i < 52; i++) {
        cards.insert(i);
    }
}

int Deck::draw_from_deck()
{
    // Providing a seed value
	srand((unsigned) time(NULL));

	// Get a random number for card to draw
	int card = rand() % 53;
}

//Destructor. releases resources
Deck::~Deck() {

}