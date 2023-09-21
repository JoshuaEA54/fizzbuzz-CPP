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

	Music music;
	music.openFromFile("UNO 2K17 Full Music Album.ogg");
	music.play();

	// Cargar una imagen desde un archivo
	Texture texture;
	texture.loadFromFile("WhatsApp Image 2023-08-29 at 7.20.14 PM.jpeg");

	// Crear un sprite para mostrar la imagen
	Sprite sprite(texture);

	Font font;
	font.loadFromFile("blocking.ttf");

	// Bot�n 1
	RectangleShape button1(Vector2f(350, 150));
	button1.setPosition(520, 300);
	button1.setFillColor(Color::Yellow);

	Text buttonText1("Player VS Computer", font, 40);
	buttonText1.setPosition(550, 350);
	buttonText1.setFillColor(Color::Black);

	// Bot�n 2
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


	srand(time(NULL));
	int row = rand() % 8;
	int col = rand() % 14;

	int* row2 = player.makeRandomVectorRowsForPlayers();
	int* col2 = player.makeRandomVectorColumnsForPlayers();
	int* row3 = player.makeRandomVectorRowsForPlayers();
	int* col3 = player.makeRandomVectorColumnsForPlayers();


	//Defining out of the while
	while (game.isOpen()) {

		while (game.pollEvent(evnt2)) {

			if (evnt2.type == Event::Closed) {
				game.close();
			}
			if (evnt2.type == Event::MouseButtonPressed && evnt2.mouseButton.button == Mouse::Left) {
				//transform coordenates of mouse to the window 	
				Vector2f mousePosition = game.mapPixelToCoords(Mouse::getPosition(game));
					
				if (spriteOfHideCard().getGlobalBounds().contains(mousePosition)) {
					cout << " sprite of hide card";
					// //agregar una carta random de la matriz de cartas a la baraja 
					// 		
					// game1.addCard(player1); 		
					// //el deck del player aumenta 	}
				}
				
			}

			game.clear(Color::Red);

			game1.printHideCard(game);
			game1.firstCard(game, row, col);
			game1.drawPlayerDeck(game, row2, col2, player1);
			game1.drawPlayerTwoDeck(game, row3, col3, player2);

			game.display();
		}

	}
}

void Game::drawPlayerDeck(RenderWindow& _game, int* rows, int* cols ,Player& _player)
{	

	_player.setDeck(rows, cols);

	for (int i = 0; i < 7; i++) {

		texture.loadFromFile(_player.getDeck().getCards()[0][i].getUrl());

		sprite.setTexture(texture);

		sprite.setPosition(50 + i * 75, 500);
		sprite.setScale(0.24f, 0.24f);

		_game.draw(sprite);

	}

}

void Game::drawPlayerTwoDeck(RenderWindow& _game, int* rows, int* cols, Player& _player)
{
	_player.setDeck(rows, cols);

	for (int i = 0; i < 7; i++) {

		texture.loadFromFile(_player.getDeck().getCards()[0][i].getUrl());

		sprite.setTexture(texture);

		sprite.setPosition(50 + i * 75, 30);
		sprite.setScale(0.24f, 0.24f);

		_game.draw(sprite);

	}
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
	texture.loadFromFile("Deck/hideCard.png");

	sprite.setTexture(texture);
	//                  x    y
	sprite.setPosition(660, 260);
	sprite.setScale(0.26f, 0.26f);

	//Vector2f spritePosition = sprite.getPosition();// gets the position of the image
	//
	//Vector2f windowCoords = _game.mapPixelToCoords(Vector2i(spritePosition.x, spritePosition.y));

	//cout << "Coordenadas de ventana: (" << windowCoords.x << ", " << windowCoords.y << ")" << endl;

	_game.draw(sprite);
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
