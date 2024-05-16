// a class that contains UI of blackjack game
#include <vector>
#include <set>


class Display {
public:
   
   // constructor. sets size of board to user input
   Display();
   
   // destructor
   ~Display();

   void print_hand(std::vector<int>& hand);
   void print_hand_dealer(std::vector<int>& hand);
   int find_score(std::vector<int>& hand);

   // member variables
private:
   std::set<int> aces;   // Set of aces
   std::set<int> kings;  // Set of kings
   std::set<int> queens; // Set of queens
   std::set<int> jacks;  // Set of jacks

};