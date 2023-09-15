#pragma once
#include "Card.h"

class Deck
{
private:
	
	Card** cards;// they have an string with the url
	int amount;
	
public:

	Deck();
	//Deck(int _amount);
	~Deck();

	void setCards(Card** _cards);
	void setAmount(int _amount);
	
	Card** getCards();
	int getAmount();
	
	Card** fulldeckk();

};

