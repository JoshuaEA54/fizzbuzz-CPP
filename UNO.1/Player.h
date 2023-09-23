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
	void setDeck(int* rows, int* cols, int _size);// metodo de inicio
	
    Deck getDeck();
	
	int* makeRandomVectorColumnsForPlayers(int _size);
	int* makeRandomVectorRowsForPlayers(int _size);

	int* addRowInVectorOfPlayer(int* _vector, int _size);// I need the size to increase 1 position
	int* addColumnInVectorOfPlayer(int* _vector, int _size);

	
};