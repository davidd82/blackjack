// a class for a deck of 52 cards
#include <vector>
#include <set>

class Deck {
public:
   // constructor. creats deck of 52 cards using set
   Deck();
   
   // destructor
   ~Deck();

   int draw_from_deck();

// member variables
private:
   std::set<int> cards; // Size of tic tac toe board
};