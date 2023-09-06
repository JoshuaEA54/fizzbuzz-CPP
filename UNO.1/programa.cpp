#include "programa.h"


Card::Card(int _number, string _type, int _color)
{
	_number = number;
	_type = type;
	_color = color;
}

Card::Card(string _type, int _color)
{
	_type = type;
	_color = color;
}

Card::Card()
{
	number = 0;
	type = "";
	color = 0;
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

int Card::cardNumber(int _number)// I haven't used this method
{
	_number = number;

	return number;
}

int defineColor(int _variable, int& _x, Card& _aux)
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

Card** deck(){

	int x = 0;
	Card** deck = new Card* [8], aux;
	for (int i = 0; i < 8; i++) {
		deck[i] = new Card[14];
	}
	//defining the matrix


	//Normal Cards
	for (int i = 0; i < 8; i++) {

		defineColor(i, x, aux);

		for (int j = 0; j < 10; j++) {
			deck[i][j] = Card(j, "normal", x);
		}

	}
	//Wild Cards
	for (int i = 10; i < 14; i++) {


		for (int j = 0; j < 8; j++) {

			defineColor(j, x, aux);// this method returns 'x' with the color number

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

void mainWindow()
{

	RenderWindow window(VideoMode(1366, 768), "UNO");

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

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed) {
				window.close();
			}

			// Detectar clic en los botones
			if (event.type == Event::MouseButtonPressed) {
				Vector2i mousePosition = Mouse::getPosition(window);

				if (button1.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
					button1.setFillColor(Color::Cyan);
				}

				if (button2.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
					button2.setFillColor(Color::Blue);
				}
			}

			// Restaurar colores de los botones al soltar el botón del mouse
			if (event.type == Event::MouseButtonReleased) {
				button1.setFillColor(Color::Yellow);
				button2.setFillColor(Color::Yellow);
			}
		}

		window.clear(Color::White);

		// Dibujar elementos en la ventana
		window.draw(sprite);
		window.draw(button1);
		window.draw(buttonText1);
		window.draw(button2);
		window.draw(buttonText2);

		window.display();
	}
	
}
