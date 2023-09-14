#pragma once
#include "Game.h"

class Player {
private:

	 Deck deck;
	 Sprite sprite;
	 Texture texture;

public:

	Player() {}
	Player(Deck& _deck);
	~Player();

	void setDeck(Deck& _deck);
	void setSprite(Sprite& _sprite);
	void setTexture(Texture& _texture);

    Deck getDeck();
	Sprite getSprite();
	Texture getTexture();

	int* makeRandomVectorColumnsForPlayers();
	int* makeRandomVectorRowsForPlayers();

	void drawPlayerDeck(RenderWindow& _game, int* rows, int* cols);
	
	void firstCard(RenderWindow& _game, int _row, int _col);
	void printHideCard(RenderWindow& _game);
};