/*
blackjack.cpp
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include "blackjack.h"
#include "deck.h"
#include "display.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Hand of player
    vector<int> player;

    // Hand of dealer
    vector<int> dealer;

    // Create deck of cards
    Deck deck;

    // Create display instance
    Display display;

    // Deal 2 cards to the player
    int card = 0;
    card = deck.draw_from_deck();
    player.push_back(card);

    card = deck.draw_from_deck();
    player.push_back(card);

    // Deal 2 cards to the dealer
    
    
    return 0;
}