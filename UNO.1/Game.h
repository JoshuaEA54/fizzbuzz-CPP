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
	
	Player getPlayer();
	Sprite getSprite();
	Texture getTexture();

	void drawPlayerDeck(RenderWindow& _game, Player& _player, int _size, Sprite*& spritesOfPlayer);
	void drawPlayerTwoDeck(RenderWindow& _game, Player& _player, int _size, Sprite*& spritesOfPlayer);
	void deckOfPlayer(Player& _player, int* rows, int* cols, int _size);

	void drawPillDeck(RenderWindow& _game, int _row, int _col, string urlOfCardAdded,int sizePill, bool firstCard);
	void printHideCard(RenderWindow& _game);
	Sprite spriteOfHideCard();
	Sprite* addSprite(Sprite*& spritesPill,Sprite& _sprite, int _size);
	

	void mainWindow();
	void gameWindow(RenderWindow& _window);

	void throwCardPlayer1(int sizePlayer1, Sprite* spritesOfPlayer1, Vector2f& mousePosition, int& sizePill, String& urlOfCardAdded, Player& player1, bool& firstCard, bool& turns);
	void throwCardPlayer2(int sizePlayer2, Sprite* spritesOfPlayer2, Vector2f& mousePosition, int& sizePill, String& urlOfCardAdded, Player& player2, bool& firstCard, bool& turns);

	void addCardOnPlayerOneDeck(Vector2f& mousePosition, int& sizePlayer1, int* rowP1, int* colP1,Player& _player1);
	void addCardOnPlayerTwoDeck(Vector2f& mousePosition, int& sizePlayer2, int* rowP2, int* colP2,Player& _player2);
	
};

