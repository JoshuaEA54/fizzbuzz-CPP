#pragma once

#include "Player.h"

class Game
{
private:

	Player player;
	Sprite sprite;
	Texture texture;

public:

	Game() {};
	Game(Player& _player);
	~Game();

	void setPlayer(Player& _player);
	void setSprite(Sprite& _sprite);
	void setTexture(Texture& _texture);
	void deckOfPlayer(Player& _player, int* rows, int* cols, int _size);

	Player getPlayer();
	Sprite getSprite();
	Texture getTexture();

	//decks
	void drawPlayerDeck(RenderWindow& _game, Player& _player, int& _size, Sprite*& spritesOfPlayer, string& urlOfCardAdded, int i_position, bool& eliminate);
	void drawPlayerTwoDeck(RenderWindow& _game, Player& _player, int& _size, Sprite*& spritesOfPlayer, string urlOfCardAdded, int i_position2, bool& eliminate2);
	void drawPillDeck(RenderWindow& _game, int _row, int _col, string urlOfCardAdded,int sizePill, bool firstCard);
	void printHideCard(RenderWindow& _game);

	Sprite spriteOfHideCard();
	Sprite* addSprite(Sprite*& spritesPill,Sprite& _sprite, int _size);
	
	void mainWindow();
	void gameWindow(RenderWindow& _window);

	void throwCardPlayer1(int& sizePlayer1, Sprite* spritesOfPlayer1, Vector2f& mousePosition, int& sizePill, string& urlOfCardAdded, Player& player1, bool& firstCard, bool& turns, int& i_position, bool& eliminate);
	void throwCardPlayer2(int sizePlayer2, Sprite* spritesOfPlayer2, Vector2f& mousePosition, int& sizePill, string& urlOfCardAdded, Player& player2, bool& firstCard, bool& turns, int& i_position, bool& eliminate2);

	void addCardOnPlayerOneDeck(Vector2f& mousePosition, int& sizePlayer1, int*& rowP1, int*& colP1,Player& _player1, bool& accessToPlayer1Deck);
	
	void addCardOnPlayerTwoDeck(Vector2f& mousePosition, int& sizePlayer2, int*& rowP2, int*& colP2,Player& _player2, bool& accessToPlayer2Deck);

	void eliminateCardOnPlayerDeck(Player& _player, int& _size, int& positionOfChanges);
	
};

