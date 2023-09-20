#include "Deck.h"

Deck::Deck()
{
	this->cards = new Card*[8];

	for (int i = 0; i < 8; i++) {
		cards[i] = NULL;
	}

	this->amount = 0;
}

Deck::Deck(Card** _cards, int _amount)
{
	this->cards = _cards;
	this->amount = _amount;
}

Deck::~Deck()
{
}

void Deck::setCards(Card** _cards)
{
	this->cards = _cards;
}

void Deck::setAmount(int _amount)
{
	this->amount = _amount;
}

Card** Deck::getCards()
{
	return cards;
}

int Deck::getAmount()
{
	return amount;
}

Card** Deck::fulldeckk()
{
	int x = 0; Card aux;

	 cards = new Card * [8];
	for (int i = 0; i < 8; i++) {
		cards[i] = new Card[14];
	}
	//defining the matrix

	//Normal Cards
	for (int i = 0; i < 8; i++) {

		aux.defineColor(i, x, aux);

		for (int j = 0; j < 10; j++) {
			cards[i][j] = Card(j, "normal", x, "Deck/card_" + to_string(i) + "_" + to_string(j) + ".png");
			cout << cards[i][j].getUrl() << endl;
		}

	}
	//Wild Cards
	for (int i = 10; i < 14; i++) {

		for (int j = 0; j < 8; j++) {

			aux.defineColor(j, x, aux);// this method returns 'x' with the color number

			if (i == 10) {
				cards[j][i] = Card("LoseTurn", x, "Deck/card_" + to_string(j) + "_" + to_string(i) + ".png");
			}
			else if (i == 11) {
				cards[j][i] = Card("U - Turn", x, "Deck/card_" + to_string(j) + "_" + to_string(i) + ".png");
			}
			else if (i == 12) {
				cards[j][i] = Card("plus 2", x, "Deck/card_" + to_string(j) + "_" + to_string(i) + ".png");
			}
			else if (i == 13) {
				x = aux.allColor(); // 'x' equal to 5, it means the four colors

				if (j < 4) {
					cards[j][i] = Card("ChangeColor", x, "Deck/card_" + to_string(j) + "_" + to_string(i) + ".png");
				}
				else {
					cards[j][i] = Card("plus 4", x, "Deck/card_" + to_string(j) + "_" + to_string(i) + ".png");
				}

			}

		}

	}


	return cards;
}
