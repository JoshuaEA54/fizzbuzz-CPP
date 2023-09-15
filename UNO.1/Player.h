#pragma once
//#include "Card.h"
#include "Deck.h"

class Player {
private:

	 Deck deck;
	 Deck deckOfPlayer;

public:

	Player() {}
	Player(Deck& _deck);
	~Player();

	void setDeck(Deck& _deck);
	
    Deck getDeck();
	
	int* makeRandomVectorColumnsForPlayers();
	int* makeRandomVectorRowsForPlayers();

	
};