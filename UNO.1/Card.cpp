#include "Card.h"

Card::Card(int _number, string _type, int _color, string _url)
{
	this->number = _number;
	this->type = _type;
	this->color = _color;
	this->url = _url;
}

Card::Card(string _type, int _color, string _url)
{
	this->type = _type;
	this->color = _color;
	this->url = _url;
}

Card::Card()
{
	this->number = 0;
	this->type = "";
	this->color = 0;
	this->url = "";

}

Card::~Card()
{
}

void Card::setNumber(int _number)
{
	this->number = _number;
}

void Card::setType(string _type)
{
	this->type = _type;
}

void Card::setColor(int _color)
{
	this->color = _color;
}

void Card::setUrl(string _url)
{
	this->url = _url;
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

string Card::getUrl()
{
	return url;
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










