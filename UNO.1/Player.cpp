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

void Player::setDeck(int* rows, int* cols)
{
	Card** card;

	card = new Card * [1];
	card[0] = new Card[7];

	for (int i = 0; i < 7; i++) {

		card[0][i].setUrl("Deck/card_" + to_string(rows[i]) +
			"_" + to_string(cols[i]) + ".png");

	}

	 this->deck = Deck(card, 7);

	
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

