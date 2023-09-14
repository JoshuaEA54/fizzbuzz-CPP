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

void Player::setSprite(Sprite& _sprite)
{
	sprite = _sprite;
}

void Player::setTexture(Texture& _texture)
{
	texture = _texture;
}

Deck Player::getDeck()
{
	return deck;
}

Sprite Player::getSprite()
{
	return sprite;
}

Texture Player::getTexture()
{
	return texture;
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


void Player::drawPlayerDeck(RenderWindow& _game, int* rows, int* cols)
{

	for (int i = 0; i < 7; i++) {

		texture.loadFromFile("Deck/card_" + to_string(rows[i]) +
			"_" + to_string(cols[i]) + ".png");

		sprite.setTexture(texture);

		sprite.setPosition(50 + i * 75, 500);
		sprite.setScale(0.24f, 0.24f);

		_game.draw(sprite);
	}

}


void Player::firstCard(RenderWindow& _game, int _row, int _col)
{
	//deck.setCards(_deck);

	texture.loadFromFile("Deck/card_" + to_string(_row) + "_" + to_string(_col) + ".png");
	sprite.setTexture(texture);// we get that position from the matrix

	sprite.setPosition(510, 260);
	sprite.setScale(0.25f, 0.25f);

	_game.draw(sprite);
}

void Player::printHideCard(RenderWindow& _game)
{
	texture.loadFromFile("Deck/hideCard.png");

	sprite.setTexture(texture);
	sprite.setPosition(660, 260);
	sprite.setScale(0.26f, 0.26f);

	_game.draw(sprite);
}
