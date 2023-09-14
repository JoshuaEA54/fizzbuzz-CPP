#pragma once
#include "Game.h"

class Card {

private:

	int number;
	string type;
	int color;
	string url;

public:

	Card(int _number, string _type, int _color, string _url);
	Card(string _type, int _color, string _url);
	Card();
	~Card();

	void setNumber(int _number);
	void setType(string _type);
	void setColor(int _color);
	void setUrl(string _url);
	
	int getNumber();
	string getType();
	int getColor();
	string getUrl();
	
	int redColor();//1
	int yellowColor();//2
	int greenColor();//3
	int blueColor();//4
	int allColor();//5

	int defineColor(int _variable, int& _x, Card& _aux);

};




