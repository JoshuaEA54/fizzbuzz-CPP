#include "Player.h"

Player::Player(Deck& _deck)
{
	deck = _deck;
}

Player::~Player()
{
}

void Player::setDeck(Deck& _deck)
{
	deck = _deck;
}

Deck Player::getDeck()
{
	return deck;
}


int* Player::makeRandomVectorColumnsForPlayers()
{
	int* colVector = new int[7];
	int col = 0;

	for (int i = 0; i < 7; i++) {
		col = rand() % 14;
		colVector[i] = col;
	}
	return colVector;
}

int* Player::makeRandomVectorRowsForPlayers()
{
	int* rowVector = new int[7];
	int row = 0;

	for (int i = 0; i < 7; i++) {
		row = rand() % 8;
		rowVector[i] = row;

	}
	return rowVector;
}

