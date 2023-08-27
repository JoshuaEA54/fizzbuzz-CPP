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

int Card::cardNumber(int _number)
{
	_number = number;

	return number;
}



//string Card::cardType()
//{
//	for (int i = 0; i < 8; i++) {
//
//		for (int j = 0; j < 10; j++) {
//			if (cardDeck[i][j] == j) {
//				return ("Normal");
//			}
//		}
//	}
//
//	for (int j = 0; j < 4; j++) {
//
//		for (int i = 0; i < 8; i++) {
//
//			if (jokerDeck[i][j] == "LoseTurn") {
//				return ("Especial");
//			}
//			else if (jokerDeck[i][j] == "U-Turn") {
//				return ("Especial");
//			}
//			else if (jokerDeck[i][j] == "plus 2") {
//				return ("Especial");
//			}
//			else if (jokerDeck[i][j] == "ChangeColor") {
//				return ("Especial");
//			}
//			else if (jokerDeck[i][j] == "plus 4") {
//				return ("Especial");
//			}
//
//		}
//
//	}
//}


//void Card::defineCD()
//{
//	
//
//	// there should be just one 0 of each color but for now I won´t do it
//	
//	for (int i = 0; i < 8; i++) {
//
//		for (int j = 0; j < 10; j++) {
//			cardDeck[i][j] = j;
//		}
//	}
//
//	/*for (int i = 0; i < 8; i++) {
//
//		for (int j = 0; j < 10; j++) {
//			cout << " " << cardDeck[i][j];
//		}
//		cout << endl;
//	}*/
//}

//void Card::defineJD()
//{
//
//		for (int j = 0; j < 4; j++) {
//			
//			for (int i = 0; i < 8; i++) {
//
//				if (j == 0) {
//					jokerDeck[i][j] = "LoseTurn";
//				}
//				  else if (j == 1) {
//					   jokerDeck[i][j] = "U-Turn";
//				  }
//				    else if (j == 2) {
//					     jokerDeck[i][j] = "plus 2";
//				    }
//
//				if (j == 3) {
//					if (i < 4) {
//						jokerDeck[i][j] = "ChangeColor";
//					}
//					  else {
//						jokerDeck[i][j] = "plus 4";
//					  }
//				}
//			}
//			
//		}
//
//}

Deck::Deck(int _rows, int _col)
{
	deck = new Card* [_rows];

	for (int i = 0; i < _rows; ++i) {
		deck[i] = new Card[_col];
	}



}

Card& Deck::getDeck(int _row, int _col)//devuelve referencia de "Card"
{
		return deck[_row][_col];
}


