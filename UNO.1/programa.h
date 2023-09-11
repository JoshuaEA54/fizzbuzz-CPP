

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

using namespace sf;
using namespace std;


class Card {

private:
	    
    int number;
	string type;
	int color;
	Texture textureCard;
	
public:

	Card(int _number, string _type, int _color);
	Card(string _type, int _color);
	Card();
	
	void setTexture(int _row, int _col);
	void setTexture(Texture _texture);

	Texture getTexture();
	string getType();

	int redColor();//1
	int yellowColor();//2
	int greenColor();//3
	int blueColor();//4
	int allColor();//5

	int cardNumber(int _number);
	   

	   
};

int defineColor(int _variable,int& _x, Card& _aux);

Card** deckk();

void spritesVector(RenderWindow& _game);

void mainWindow();
void gameWindow(RenderWindow& _window);


     
