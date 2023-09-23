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

	void drawPlayerDeck(RenderWindow& _game, int* rows, int* cols, Player& _player, int _size);
	void drawPlayerTwoDeck(RenderWindow& _game, int* rows, int* cols, Player& _player, int _size);
	void firstCard(RenderWindow& _game, int _row, int _col);
	void printHideCard(RenderWindow& _game);
	Sprite spriteOfHideCard();
	

	void mainWindow();
	void gameWindow(RenderWindow& _window);
	
};

