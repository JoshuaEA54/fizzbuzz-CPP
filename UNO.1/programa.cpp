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

	CImg<unsigned char> image("UNOPrueba3.bmp");
	CImg<unsigned char> newSize = image.resize(1366, 680);//1366 768 is the normal resolution of this pc 
	CImgDisplay window(newSize, "UNO - Joshua Elizondo Abarca");

	// Keeps window open until it closes
	while (!window.is_closed()) {
		window.wait();
	}
	
}
