#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace sf;
using namespace std;

class Game
{
private:

	Player player;
	
public:

	Game() {};
	Game(Player& _player);
	~Game();

	void setPlayer(Player _player);
	
	Player getPlayer();

	void mainWindow();
	void gameWindow(RenderWindow& _window);
	
};

