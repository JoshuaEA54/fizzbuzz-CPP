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






//Deck::Deck(int _rows, int _col)
//{
//	deck = new Card* [_rows];
//
//	for (int i = 0; i < _rows; ++i) {
//		deck[i] = new Card[_col];
//	}
//
//
//
//}
//
//Card& Deck::getDeck(int _row, int _col)//devuelve referencia de "Card"
//{
//		return deck[_row][_col];
//}

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

Card deck(){

	int x = 0;
	Card deck[8][14], aux;

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
	return Card (deck[0][0]);
}
