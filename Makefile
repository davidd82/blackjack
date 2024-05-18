all: hash

hash: blackjack.cpp blackjack.h display.cpp display.h deck.cpp deck.h
	g++ -g -Wall -std=c++17 blackjack.cpp display.cpp deck.cpp -o blackjack

.PHONY: clean

clean:
	rm -f blackjack