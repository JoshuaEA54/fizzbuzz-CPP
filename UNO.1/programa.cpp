#include "programa.h"

Card::Card(int _number, string _type, int _color)
{
	number = _number;
	type = _type;
	color = _color;
}

Card::Card(string _type, int _color)
{
	type = _type;
	color = _color;
}

Card::Card()
{
	number = 0;
	type = "";
	color = 0;

}

Card::~Card()
{
}

void Card::setNumber(int _number)
{
	number = _number;
}

void Card::setType(string _type)
{
	type = _type;
}

void Card::setColor(int _color)
{
	color = _color;
}

void Card::setSprite(Texture& _texture)
{
	spriteOfCard.setTexture(_texture);
}


int Card::getNumber()
{
	return number;
}

string Card::getType()
{
	return type;
}

int Card::getColor()
{
	return color;
}

Sprite Card::getSprite()
{
	return spriteOfCard;
}

int Card::redColor()
{
	color = 1;
	return color;
}

int Card::yellowColor()
{
	color = 2;
	return color;
}

int Card::greenColor()
{
	color = 3;
	return color;
}

int Card::blueColor()
{
	color = 4;
	return color;
}

int Card::allColor()
{
	color = 5;
	return color;
}


int Card::defineColor(int _variable, int& _x, Card& _aux)
{

	if (_variable == 0 || _variable == 4) {
		_x = _aux.redColor();
	}
	else if (_variable == 1 || _variable == 5) {
		_x = _aux.yellowColor();
	}
	else if (_variable == 2 || _variable == 6) {
		_x = _aux.greenColor();
	}
	else {
		_x = _aux.blueColor();
	}

	return _x;
}

Card** deckk() {

	int x = 0;
	Card** deck = new Card * [8], aux;
	for (int i = 0; i < 8; i++) {
		deck[i] = new Card[14];
	}
	//defining the matrix

	//Normal Cards
	for (int i = 0; i < 8; i++) {

		aux.defineColor(i, x, aux);

		for (int j = 0; j < 10; j++) {
			deck[i][j] = Card(j, "normal", x);
			cout << x;
		}

	}
	//Wild Cards
	for (int i = 10; i < 14; i++) {

		for (int j = 0; j < 8; j++) {

			aux.defineColor(j, x, aux);// this method returns 'x' with the color number

			if (i == 10) {
				deck[j][i] = Card("LoseTurn", x);
			}
			else if (i == 11) {
				deck[j][i] = Card("U - Turn", x);
			}
			else if (i == 12) {
				deck[j][i] = Card("plus 2", x);
			}
			else if (i == 13) {
				x = aux.allColor(); // 'x' equal to 5, it means the four colors

				if (j < 4) {
					deck[j][i] = Card("ChangeColor", x);
				}
				else {
					deck[j][i] = Card("plus 4", x);
				}

			}
			
		}

	}
	return deck;
}



void drawSprites(RenderWindow& _game, Card** _deck)
{
	/*Card** carta = new Card * [8];
	for (int i = 0; i < 8; i++) {
		carta[i] = new Card[14];
	}*/
	Texture textura;
	Sprite sprite;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 14; j++) {

			textura.loadFromFile("Deck/card_" + to_string(i) + "_" + to_string(j) + ".png");
			_deck[i][j].setSprite(textura);

			sprite = _deck[i][j].getSprite();
			sprite.setPosition(630, 280);
			sprite.setScale(0.25f, 0.25f);

			_game.draw(sprite);
		}
	}

}

void firstCard(RenderWindow& _game,Card** _deck, int _row, int _col)
{
	Texture textura;
	Sprite sprite;

	textura.loadFromFile("Deck/card_" + to_string(_row) + "_" + to_string(_col) + ".png");
	_deck[_row][_col].setSprite(textura);// we get that position from the matrix

	sprite = _deck[_row][_col].getSprite();
	sprite.setPosition(480, 280);
	sprite.setScale(0.25f, 0.25f);

	_game.draw(sprite);
		
}

void mainWindow()
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
					button2.setFillColor(Color::Blue);
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

void gameWindow(RenderWindow& _window)
{
	_window.close();// close the last window

	//second window
	RenderWindow game;
	game.create(VideoMode(1366, 768), "UNO", Style::Default);

	Event evnt2;

    Card** deck = deckk();

	srand(time(NULL));
	int row = rand()%8; int col = rand() % 14;
	

	//Defining out of the while
	while (game.isOpen()) {

		while (game.pollEvent(evnt2)) {

			if (evnt2.type == Event::Closed) {
				game.close();
			}

		}

		game.clear(Color::Red);

		drawSprites(game, deck);
		
		firstCard(game, deck,row,col);
		
		game.display();
	}

}
