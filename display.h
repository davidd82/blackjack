// a class that contains UI of blackjack game
#include <vector>

class Display {
public:
   
   // constructor. sets size of board to user input
   Display();
   
   // destructor
   ~Display();

   void print_hand(std::vector<int>& hand);
   
};