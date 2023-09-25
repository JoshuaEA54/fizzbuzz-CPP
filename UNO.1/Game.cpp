#include "Game.h"

Game::Game(Player& _player)
{
	this->player = _player;
	
}

Game::~Game()
{
}

void Game::setPlayer(Player& _player)
{
	this->player = _player;
}

void Game::setSprite(Sprite& _sprite)
{
	this->sprite = _sprite;
}

void Game::setTexture(Texture& _texture)
{
	this->texture = _texture;
}

Player Game::getPlayer()
{
	return player;
}

Sprite Game::getSprite()
{
	return sprite;
}

Texture Game::getTexture()
{
	return texture;
}

void Game::mainWindow()
{
	//creation of the window
	RenderWindow window;
	window.create(VideoMode(1366, 768), "UNO", Style::Default);

	/*Music music;
	music.openFromFile("UNO 2K17 Full Music Album.ogg");
	music.play();*/

	// Cargar una imagen desde un archivo
	Texture texture;
	texture.loadFromFile("WhatsApp Image 2023-08-29 at 7.20.14 PM.jpeg");

	// Crear un sprite para mostrar la imagen
	Sprite sprite(texture);

	Font font;
	font.loadFromFile("blocking.ttf");

	// Botón 1
	RectangleShape button1(Vector2f(350, 150));
	button1.setPosition(520, 300);
	button1.setFillColor(Color::Yellow);

	Text buttonText1("Player VS Computer", font, 40);
	buttonText1.setPosition(550, 350);
	buttonText1.setFillColor(Color::Black);

	// Botón 2
	RectangleShape button2(Vector2f(350, 150));
	button2.setPosition(520, 520);
	button2.setFillColor(Color::Yellow);

	Text buttonText2("Player VS Player", font, 40);
	buttonText2.setPosition(570, 570);
	buttonText2.setFillColor(Color::Black);

	Event evnt;

	while (window.isOpen()) {

		Vector2i mousePosition = Mouse::getPosition(window);
		while (window.pollEvent(evnt)) {

			if (evnt.type == Event::Closed) {
				window.close();
			}

			// Detectar clic en los botones
			if (evnt.type == Event::MouseButtonPressed) {


				if (button1.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
					gameWindow(window);


				}

				if (button2.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
					gameWindow(window);
				}
			}


		}


		// Dibujar elementos en la ventana

		window.clear();

		//aqui en medio de clear y display dibujar los elementos
		window.draw(sprite);
		window.draw(button1);
		window.draw(buttonText1);
		window.draw(button2);
		window.draw(buttonText2);

		window.display();
	}

}

void Game::gameWindow(RenderWindow& _window)
{
	_window.close();// close the last window

	//second window
	RenderWindow game;
	game.create(VideoMode(1366, 768), "UNO", Style::Default);

	Event evnt2;

	Game game1; Player player1; Player player2;

	int sizePlayer1 = 7;
	int sizePlayer2 = 7;

	srand(time(NULL));
	int row = rand() % 8;
	int col = rand() % 14;

	int* rowP1 = player.makeRandomVectorRowsForPlayers(sizePlayer1);
	int* colP1 = player.makeRandomVectorColumnsForPlayers(sizePlayer1);
	int* rowP2 = player.makeRandomVectorRowsForPlayers(sizePlayer2);
	int* colP2 = player.makeRandomVectorColumnsForPlayers(sizePlayer2);

	bool turns = true;

	//Defining out of the while
	while (game.isOpen()) {

		while (game.pollEvent(evnt2)) {

			if (evnt2.type == Event::Closed) {
				game.close();
			}
			if (evnt2.type == Event::MouseButtonReleased && evnt2.mouseButton.button == Mouse::Left) {
				//transform coordenates of mouse to the window 	
				Vector2f mousePosition = game.mapPixelToCoords(Mouse::getPosition(game));
					
				addCardOnPlayerDeck(mousePosition, turns, sizePlayer1, rowP1, colP1, sizePlayer2, rowP2, player2, colP2);
				
			}

			game.clear(Color::Red);

			game1.printHideCard(game);
			game1.firstCard(game, row, col);

			game1.deckOfPlayer(player1, rowP1, colP1, sizePlayer1);
			game1.drawPlayerDeck(game, rowP1, colP1, player1,sizePlayer1);

			game1.deckOfPlayer(player2, rowP2, colP2, sizePlayer2);
			game1.drawPlayerTwoDeck(game, rowP2, colP2, player2, sizePlayer2);


			game.display();
		}

	}
}

void Game::addCardOnPlayerDeck(Vector2f& mousePosition, bool& turns, int& sizePlayer1, int* rowP1, int* colP1, int& sizePlayer2, int* rowP2, Player& player2, int* colP2)
{
	if (spriteOfHideCard().getGlobalBounds().contains(mousePosition)) {

		if (turns) {

			turns = false;

			if (sizePlayer1 < 20) {

				rowP1 = player.addRowInVectorOfPlayer(rowP1, sizePlayer1);
				colP1 = player.addColumnInVectorOfPlayer(colP1, sizePlayer1);// we add a new image

				sizePlayer1 += 1; // we increase the size of the vector of cards
			}
		}
		else {
			turns = true;

			if (sizePlayer2 < 20) {

				rowP2 = player2.addRowInVectorOfPlayer(rowP2, sizePlayer2);

				colP2 = player2.addColumnInVectorOfPlayer(colP2, sizePlayer2);// we add a new image

				sizePlayer2 += 1; // we increase the size of the vector of cards
			}
		}
	}
}

void Game::drawPlayerDeck(RenderWindow& _game, int* rows, int* cols ,Player& _player,int _size)
{	
	_player.setDeck(rows, cols,_size);

	for (int i = 0; i < _size; i++) {

		texture.loadFromFile(_player.getDeck().getCards()[0][i].getUrl());

		sprite.setTexture(texture);

		sprite.setPosition(50.0f + i * 60.0f, 500.0f);
		sprite.setScale(0.24f, 0.24f);

		_game.draw(sprite);

	}

}

void Game::drawPlayerTwoDeck(RenderWindow& _game, int* rows, int* cols, Player& _player, int _size)
{
	_player.setDeck(rows, cols,_size);

	for (int i = 0; i < _size; i++) {

		texture.loadFromFile(_player.getDeck().getCards()[0][i].getUrl());

		sprite.setTexture(texture);

		sprite.setPosition(50.0f + i * 60.0f, 30.0f);
		sprite.setScale(0.24f, 0.24f);

		_game.draw(sprite);

	}
}

void Game::deckOfPlayer(Player& _player, int* rowP, int* colP, int _size)
{
	_player.setDeck(rowP, colP, _size);
}

void Game::firstCard(RenderWindow& _game, int _row, int _col)
{
	//Sprite sprite2;

	texture.loadFromFile("Deck/card_" + to_string(_row) + "_" + to_string(_col) + ".png");
	
	sprite.setTexture(texture);// we get that position from the matrix
	sprite.setPosition(510, 260);// 510 260
	sprite.setScale(0.25f, 0.25f);

	_game.draw(sprite);
}

void Game::printHideCard(RenderWindow& _game)
{
	_game.draw(spriteOfHideCard());
}

Sprite Game::spriteOfHideCard()
{
	texture.loadFromFile("Deck/hideCard.png");

	sprite.setTexture(texture);
	//                  x    y
	sprite.setPosition(660, 260);
	sprite.setScale(0.26f, 0.26f);

	return sprite;
}
