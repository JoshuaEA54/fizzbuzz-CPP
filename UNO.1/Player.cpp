#include "Player.h"

Player::Player(Deck& _deck)
{
	this->deck = _deck;
}

Player::~Player()
{
}

void Player::setDeck(Deck& _deck)
{
	this->deck = _deck;
}

void Player::setDeck(int* rows, int* cols,int _size)
{
	Card** deckOfPlayer;

	deckOfPlayer = new Card * [1];
	deckOfPlayer[0] = new Card[_size];

	for (int i = 0; i < _size; i++) {

		deckOfPlayer[0][i].setUrl(deck.fulldeckk()[rows[i]][cols[i]].getUrl());
		//agarra los strings del mazo ya definido de cartas
		
	}

	 this->deck = Deck(deckOfPlayer, _size);

}

Deck Player::getDeck()
{
	return deck;
}


int* Player::makeRandomVectorColumnsForPlayers(int _size)
{
	int* colVector = new int[_size];
	int random = 0;

	for (int i = 0; i < _size; i++) {
		random = rand() % 14;
		colVector[i] = random;
	}
	return colVector;
}

int* Player::makeRandomVectorRowsForPlayers(int _size)
{
	int* rowVector = new int[_size];
	int random = 0;

	for (int i = 0; i < _size; i++) {
		random = rand() % 8;
		rowVector[i] = random;
		

	}
	
	return rowVector;
}

int* Player::addRowInVectorOfPlayer(int* _vector, int _size)
{
	int* temporalVector = new int[_size + 1];
	for (int i = 0; i < _size; i++) {
		temporalVector = _vector;// last position empty
	}
	int random = rand() % 8;
	temporalVector[_size] = random;

	
	return temporalVector;
}

int* Player::addColumnInVectorOfPlayer(int* _vector, int _size)
{
	int* temporalVector = new int[_size + 1];
	for (int i = 0; i < _size; i++) {
		temporalVector = _vector;// last position empty
	}
	int random = rand() % 14;
	temporalVector[_size] = random; // last position filled

	return temporalVector;
}
