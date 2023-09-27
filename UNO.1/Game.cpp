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
	RenderWindow windowGame;
	windowGame.create(VideoMode(1366, 768), "UNO", Style::Default);

	Event evnt2;

	Game game1; Player player1; Player player2;

	int sizePlayer1 = 7;
	Sprite* spritesOfPlayer1 = new Sprite[sizePlayer1];

	int sizePlayer2 = 7;
	Sprite* spritesOfPlayer2 = new Sprite[sizePlayer2];

	int sizePill = 1;

	srand(time(NULL));
	int row = rand() % 8;
	int col = rand() % 14;

	int* rowP1 = player1.makeRandomVectorRowsForPlayers(sizePlayer1);
	int* colP1 = player1.makeRandomVectorColumnsForPlayers(sizePlayer1);

	int* rowP2 = player2.makeRandomVectorRowsForPlayers(sizePlayer2);
	int* colP2 = player2.makeRandomVectorColumnsForPlayers(sizePlayer2);

	bool turns = true, firstCard = false;

	bool eliminate = false;
	bool eliminate2 = false;

	bool accessToPlayer1Deck = true;
	bool accessToPlayer2Deck = true;

	string urlOfCardAdded = "";
	int i_position = -1;
	int i_position2 = -1;

	//Defining out of the while
	while (windowGame.isOpen()) {

		while (windowGame.pollEvent(evnt2)) {

			if (evnt2.type == Event::Closed) {
				windowGame.close();
			}
			if (evnt2.type == Event::MouseButtonPressed && evnt2.mouseButton.button == Mouse::Left) {

				//transform coordenates of mouse to the window 	
				Vector2f mousePosition = windowGame.mapPixelToCoords(Mouse::getPosition(windowGame));

				if (turns == true) {
					addCardOnPlayerOneDeck(mousePosition, sizePlayer1, rowP1, colP1, player1);
					throwCardPlayer1(sizePlayer1, spritesOfPlayer1, mousePosition, sizePill, urlOfCardAdded, player1, firstCard, turns, i_position, eliminate);
				}
				else {//changes turn
					addCardOnPlayerTwoDeck(mousePosition, sizePlayer2, rowP2, colP2, player2);
					throwCardPlayer2(sizePlayer2, spritesOfPlayer2, mousePosition, sizePill, urlOfCardAdded, player2, firstCard, turns, i_position2, eliminate2);
				}
			}

		}

		windowGame.clear(Color::Red);

		game1.printHideCard(windowGame);
		game1.drawPillDeck(windowGame, row, col, urlOfCardAdded, sizePill, firstCard);

		if (accessToPlayer1Deck) {
			game1.deckOfPlayer(player1, rowP1, colP1, sizePlayer1);
			accessToPlayer1Deck = false;
		}
		//
		game1.drawPlayerDeck(windowGame, player1, sizePlayer1, spritesOfPlayer1, urlOfCardAdded, i_position, eliminate);
		//
		if (accessToPlayer2Deck) {
			game1.deckOfPlayer(player2, rowP2, colP2, sizePlayer2);
			accessToPlayer2Deck = false;
		}

		game1.drawPlayerTwoDeck(windowGame, player2, sizePlayer2, spritesOfPlayer2, urlOfCardAdded, i_position2, eliminate2);

		windowGame.display();
	}

	delete[] spritesOfPlayer1, spritesOfPlayer2, rowP1, rowP2, colP1, colP2;
}

void Game::throwCardPlayer1(int& sizePlayer1, Sprite* spritesOfPlayer1, Vector2f& mousePosition, int& sizePill,
	string& urlOfCardAdded, Player& player1, bool& firstCard, bool& turns, int& i_position, bool& eliminate)
{
	for (int i = 0; i < sizePlayer1; i++) {
		// this "if" takes into account that the cards are above each one of them

		if (spritesOfPlayer1[i].getGlobalBounds().contains(mousePosition) &&
			spritesOfPlayer1[i + 1].getGlobalBounds().contains(mousePosition) && (i != 0 || i != sizePlayer1 - 1)) {

			sizePill++;
			if (i == sizePlayer1 - 1) {
				urlOfCardAdded = player1.getDeck().getCards()[0][i].getUrl();
				i_position = i;
			}
			else {
				urlOfCardAdded = player1.getDeck().getCards()[0][i + 1].getUrl();
				i_position = i + 1;
			}

			firstCard = true;
			turns = false;
			eliminate = true;
			//cout << " if 1" << endl;

		}                                                                                     //i=sizeplayer-1                                                       
		else if ((i == 0 && spritesOfPlayer1[0].getGlobalBounds().contains(mousePosition)) || (i == sizePlayer1 - 2 && spritesOfPlayer1[sizePlayer1 - 1].getGlobalBounds().contains(mousePosition))) {

			sizePill++;
			if (i == sizePlayer1 - 2) {
				urlOfCardAdded = player1.getDeck().getCards()[0][i + 1].getUrl();// the last card
				i_position = i + 1;
			}
			else {
				urlOfCardAdded = player1.getDeck().getCards()[0][i].getUrl();//the first card
				i_position = i;
			}
			firstCard = true;
			turns = false;
			eliminate = true;
			//cout << "if 2" << endl;

		}
	}
}

void Game::throwCardPlayer2(int sizePlayer2, Sprite* spritesOfPlayer2, Vector2f& mousePosition, int& sizePill,
	string& urlOfCardAdded, Player& player2, bool& firstCard, bool& turns, int& i_position2, bool& eliminate2)
{
	for (int i = 0; i < sizePlayer2; i++) {
		// this "if" takes into account that the cards are above each one of them

		if (spritesOfPlayer2[i].getGlobalBounds().contains(mousePosition) &&
			spritesOfPlayer2[i + 1].getGlobalBounds().contains(mousePosition) && (i != 0 || i != sizePlayer2 - 1)) {

			sizePill++;
			if (i == sizePlayer2 - 1) {
				urlOfCardAdded = player2.getDeck().getCards()[0][i].getUrl();
				i_position2 = i;
			}
			else {
				urlOfCardAdded = player2.getDeck().getCards()[0][i + 1].getUrl();
				i_position2 = i + 1;
			}
			firstCard = true;
			turns = true;
			eliminate2 = true;

		}                                                                                     //i=sizeplayer-1                                                       
		else if ((i == 0 && spritesOfPlayer2[0].getGlobalBounds().contains(mousePosition)) || (i == sizePlayer2 - 2 && spritesOfPlayer2[sizePlayer2 - 1].getGlobalBounds().contains(mousePosition))) {

			sizePill++;
			if (i == sizePlayer2 - 2) {
				urlOfCardAdded = player2.getDeck().getCards()[0][i + 1].getUrl();// the last card
				i_position2 = i + 1;
			}
			else {
				urlOfCardAdded = player2.getDeck().getCards()[0][i].getUrl();//the first card
				i_position2 = i;
			}
			firstCard = true;
			turns = true;
			eliminate2 = true;

		}
	}
}

void Game::addCardOnPlayerOneDeck(Vector2f& mousePosition, int& sizePlayer1, int* rowP1, int* colP1, Player& _player1)
{
	if (spriteOfHideCard().getGlobalBounds().contains(mousePosition)) {

		if (sizePlayer1 < 20) {

			rowP1 = _player1.addRowInVectorOfPlayer(rowP1, sizePlayer1);
			colP1 = _player1.addColumnInVectorOfPlayer(colP1, sizePlayer1);// we add a new image

			sizePlayer1 += 1; // we increase the size of the vector of cards

			//agarar lo que el jugador tiene de baraja y añadirle una nueva

		}

	}
}

void Game::addCardOnPlayerTwoDeck(Vector2f& mousePosition, int& sizePlayer2, int* rowP2, int* colP2, Player& _player2)
{
	if (spriteOfHideCard().getGlobalBounds().contains(mousePosition)) {

		if (sizePlayer2 < 20) {

			rowP2 = _player2.addRowInVectorOfPlayer(rowP2, sizePlayer2);
			colP2 = _player2.addColumnInVectorOfPlayer(colP2, sizePlayer2);// we add a new image

			sizePlayer2 += 1; // we increase the size of the vector of cards
		}
	}
}

void Game::eliminateCardOnPlayerDeck(Player& _player, int& _size, int& positionOfChanges)
{
	string temp = "";
	cout << " inicio " << endl << endl;
	cout << _player.getDeck().getCards()[0][positionOfChanges].getUrl() << endl;

	for (int i = positionOfChanges; i < _size - 1; i++) {

		/*cout << "--------------------------------------------------------------------------------" << endl;
		cout << " posicion '" << i << " ' : " << _player.getDeck().getCards()[0][i].getUrl() << endl;
		cout << " posicion '"<< i+1 << " ' : " << _player.getDeck().getCards()[0][i + 1].getUrl() << endl;
		cout << "--------------------------------------------------------------------------------" << endl;*/

		temp = _player.getDeck().getCards()[0][i].getUrl();
		_player.getDeck().getCards()[0][i].setUrl(_player.getDeck().getCards()[0][i + 1].getUrl());
		_player.getDeck().getCards()[0][i + 1].setUrl(temp);

	}
	cout << _player.getDeck().getCards()[0][_size - 1].getUrl() << endl;

	cout << " final " << endl << endl;
	_size = _size - 1;

	//_player.getDeck().setAmount(_size);

	//_player.setDeck(rowP, colP, _size);
}

void Game::drawPlayerDeck(RenderWindow& _game, Player& _player, int& _size, Sprite*& spritesOfPlayer, string& urlOfCardAdded, int i_position, bool& eliminate)
{

	for (int i = 0; i < _size; i++) {

		if (_player.getDeck().getCards()[0][i].getUrl() == urlOfCardAdded && i == i_position && eliminate == true) {

			eliminateCardOnPlayerDeck(_player, _size, i_position);
			eliminate = false;

			/*i_position = -1;
			temp = "";*/
		}

		texture.loadFromFile(_player.getDeck().getCards()[0][i].getUrl());
		cout << _player.getDeck().getCards()[0][_size - 1].getUrl() << endl << endl;
		//segunda vuelta muestra mal el numero

		sprite.setTexture(texture);

		sprite.setPosition(50.0f + i * 60.0f, 500.0f);
		sprite.setScale(0.24f, 0.24f);

		_game.draw(sprite);

		if (i < 7) {
			spritesOfPlayer[i] = sprite;
		}
		else {
			addSprite(spritesOfPlayer, sprite, _size);
		}
		//_game.draw(spritesOfPlayer[i]);
	   //aux++;
	}

}

void Game::drawPlayerTwoDeck(RenderWindow& _game, Player& _player, int& _size, Sprite*& spritesOfPlayer, string urlOfCardAdded, int i_position2, bool& eliminate2)
{


	for (int i = 0; i < _size; i++) {

		if (_player.getDeck().getCards()[0][i].getUrl() == urlOfCardAdded && i == i_position2 && eliminate2 == true) {

			eliminateCardOnPlayerDeck(_player, _size, i_position2);
			eliminate2 = false;
		}

		texture.loadFromFile(_player.getDeck().getCards()[0][i].getUrl());

		sprite.setTexture(texture);

		sprite.setPosition(50.0f + i * 60.0f, 30.0f);
		sprite.setScale(0.24f, 0.24f);

		_game.draw(sprite);

		if (i < 7) {
			spritesOfPlayer[i] = sprite;
		}
		else {
			addSprite(spritesOfPlayer, sprite, _size);
		}

		//_game.draw(spritesOfPlayer[i]);


	}

}

void Game::deckOfPlayer(Player& _player, int* rowP, int* colP, int _size)
{
	_player.setDeck(rowP, colP, _size);
}

void Game::drawPillDeck(RenderWindow& _game, int _row, int _col, string urlOfCardAdded, int sizePill, bool firstCard)
{
	for (int i = 0; i < sizePill; i++) {

		if (firstCard == false && i == 0) {
			texture.loadFromFile("Deck/card_" + to_string(_row) + "_" + to_string(_col) + ".png");

			sprite.setTexture(texture);// we get that position from the matrix
			sprite.setPosition(510, 260);// 510 260
			sprite.setScale(0.25f, 0.25f);

			_game.draw(sprite);

		}
		else if (i > 0) {

			texture.loadFromFile(urlOfCardAdded);

			sprite.setTexture(texture);// we get that position from the matrix
			sprite.setPosition(510, 260);// 510 260
			sprite.setScale(0.25f, 0.25f);

			_game.draw(sprite);
		}


	}

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

Sprite* Game::addSprite(Sprite*& spritesPill, Sprite& _sprite, int _size)
{
	Sprite* tempSprite = new Sprite[_size];//size+1
	for (int i = 0; i < _size - 1; i++) {//size 2, 0 
		tempSprite[i] = spritesPill[i];// el de firstcard
	}
	tempSprite[_size - 1] = _sprite;
	delete[] spritesPill;
	spritesPill = tempSprite;

	return spritesPill;
}

