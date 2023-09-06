

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;


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
	   

	   
};

int defineColor(int _variable,int& _x, Card& _aux);
Card** deck();
void mainWindow();


     
