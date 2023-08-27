

#include <iostream>
#include "CImg.h"
using namespace std;
using namespace cimg_library;



class Card {

private:
	    
    int number;
	string type;
	int color;
	
public:

	Card(int _number, string _type, int _color);
	Card(string _type, int _color);
	Card();
	
	int redColor();//1
	int yellowColor();//2
	int greenColor();//3
	int blueColor();//4
	int allColor();//5

	int cardNumber(int _number);
	   //void cardColor();
	  // string cardType();

	   
};

class Deck {

private:

	int rows;
	int col;
	Card** deck;

public:

	Deck(int _rows, int _col);
	Card& getDeck(int _row, int _col);
};



     
