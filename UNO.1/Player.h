#pragma once

#include "Deck.h"

class Player {
private:

	 Deck deck;
	

public:

	Player() {}
	Player(Deck& _deck);
	~Player();

	void setDeck(Deck& _deck);
	void setDeck(int* rows, int* cols);// metodo de inicio
	
    Deck getDeck();
	
	int* makeRandomVectorColumnsForPlayers();
	int* makeRandomVectorRowsForPlayers();

	
};