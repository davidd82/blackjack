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

    // String to store player choice and int to store calculated score
    string move;
    int score = 0; 

    // Deal 2 cards to the player
    int card = 0;
    card = deck.draw_from_deck();
    player.push_back(card);

    card = deck.draw_from_deck();
    player.push_back(card);

    // Print hand of player
    cout << "PLAYER: " << endl;
    display.print_hand(player);

    // Print score of the player
    cout << endl;
    score = display.find_score(player);
    cout << "SCORE: " << score << endl;

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
        cout << "PLAYER WINS BY BLACKJACK" << endl;
        return 0;
    }

    // While the player hasn't gone over 21
    while (display.find_score(player) <= 21) {
        // Ask the player if they want to hit or stay
        cout << endl;
        cout << "HIT(H) or STAY(S)?" << endl;
        cin >> move;

        // If the player decides to hit
        if (move == "H") {
            // Draw a card from the deck and add it to player's hand
            card = deck.draw_from_deck();
            player.push_back(card);

            // Print hand of the player
            cout << "PLAYER: " << endl;
            display.print_hand(player);

            // Print score of the player
            cout << endl;
            score = display.find_score(player);
            cout << "SCORE: " << score << endl;

            //print hand of dealer
            cout << endl;
            cout << "DEALER:" << endl;
            display.print_hand_dealer(dealer);

            // Check if player wins by blackjack
            if (score == 21) {
                cout << "PLAYER WINS BY BLACKJACK" << endl;
                return 0;
            }
        } else if (move == "S") { // Else break from loop if player decided to stay
            break;
        }
    }

    // If the player's score is above 21 then dealer wins
    if (score > 21) {
        cout << "DEALER WINS BY PLAYER BUST" << endl;
        return 0;
    }

    // If the score of the dealer is 16 or less then keep drawing cards
    while(display.find_score(dealer) <= 16) {
        card = deck.draw_from_deck();
        dealer.push_back(card);
    }

    // Print hand of the player
    cout << "PLAYER: " << endl;
    display.print_hand(player);

    // Print score of the player
    cout << endl;
    score = display.find_score(player);
    cout << "SCORE: " << score << endl;

    //print hand of dealer
    cout << endl;
    cout << "DEALER:" << endl;
    display.print_hand(dealer);
    
    // Print score of the dealer
    cout << endl;
    score = display.find_score(dealer);
    cout << "SCORE: " << score << endl;

    // If the dealer busts then the player wins
    if (score > 21) {
        cout << endl;
        cout << "PLAYER WINS BY DEALER BUST" << endl;
    }

    // Figure out wether there is a draw or which player has the higher score
    if (display.find_score(dealer) > display.find_score(player)) {
        cout << endl;
        cout << "DEALER WINS" << endl;
        return 0;
    } else if (display.find_score(dealer) < display.find_score(player)) {
        cout << endl;
        cout << "PLAYER WINS" << endl;
    } else {
        cout << endl;
        cout << "DRAW" << endl;
    }

    return 0;
}

