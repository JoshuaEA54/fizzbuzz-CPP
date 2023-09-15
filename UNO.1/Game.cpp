#include "Game.h"

Game::Game(Player& _player)
{
	player = _player;
	
}

Game::~Game()
{
}

void Game::setPlayer(Player _player)
{
	player = _player;
}

void Game::setSprite(Sprite& _sprite)
{
	sprite = _sprite;
}

void Game::setTexture(Texture& _texture)
{
	texture = _texture;
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

	/*Card** oneCard; 
	oneCard = new Card * [1];
	oneCard[0] = new Card[1];
    oneCard[0][0].setUrl("Deck/card_" + to_string(0) + "_" + to_string(0) + ".png");

	Deck deckkk; 
	deckkk.setCards(oneCard);

	Player jugador; 
	jugador.setDeck(deckkk);
*/
	Game game1; 
	//game1.setPlayer(jugador);

	srand(time(NULL));
	int row = rand() % 8; int col = rand() % 14;

	int* roW = player.makeRandomVectorRowsForPlayers();
	int* coL = player.makeRandomVectorColumnsForPlayers();


	//Defining out of the while
	while (game.isOpen()) {

		while (game.pollEvent(evnt2)) {

			if (evnt2.type == Event::Closed) {
				game.close();
			}

		}

		game.clear(Color::Red);

		game1.printHideCard(game);
		game1.firstCard(game, row, col);
		game1.drawPlayerDeck(game, roW, coL);

		game.display();
	}

}

void Game::drawPlayerDeck(RenderWindow& _game, int* rows, int* cols)
{
	/*texture.loadFromFile("Deck/card_" + to_string(0) +
		"_" + to_string(0) + ".png");
	sprite.setTexture(texture);

	sprite.setPosition(50, 500);
	sprite.setScale(0.24f, 0.24f);

	_game.draw(sprite);*/
	for (int i = 0; i < 7; i++) {

		texture.loadFromFile("Deck/card_" + to_string(rows[i]) +
			"_" + to_string(cols[i]) + ".png");

		sprite.setTexture(texture);

		sprite.setPosition(50 + i * 75, 500);
		sprite.setScale(0.24f, 0.24f);

		_game.draw(sprite);
	}

}


void Game::firstCard(RenderWindow& _game, int _row, int _col)
{
	//deck.setCards(_deck);

	texture.loadFromFile("Deck/card_" + to_string(_row) + "_" + to_string(_col) + ".png");
	sprite.setTexture(texture);// we get that position from the matrix

	sprite.setPosition(510, 260);
	sprite.setScale(0.25f, 0.25f);

	_game.draw(sprite);
}

void Game::printHideCard(RenderWindow& _game)
{
	texture.loadFromFile("Deck/hideCard.png");

	sprite.setTexture(texture);
	sprite.setPosition(660, 260);
	sprite.setScale(0.26f, 0.26f);

	_game.draw(sprite);
}