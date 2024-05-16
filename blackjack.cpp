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

    string move;
    int score; 

    // Deal 2 cards to the player
    int card = 0;
    card = deck.draw_from_deck();
    player.push_back(card);

    card = deck.draw_from_deck();
    player.push_back(card);

    // Print hand of player
    cout << "PLAYER: " << endl;
    display.print_hand(player);

    // Deal 2 cards to the dealer
    card = deck.draw_from_deck();
    dealer.push_back(card);

    card = deck.draw_from_deck();
    dealer.push_back(card);

    //print hand of dealer
    cout << endl;
    cout << "DEALER:" << endl;
    display.print_hand_dealer(dealer);

    // Check if player wins by blackjack
    score = display.find_score(player);

    if (score == 21) {
        
    }
    cout << endl;
    cout << "HIT(H) or STAY(S)?" << endl;
    cin >> move;
    
    return 0;
}

