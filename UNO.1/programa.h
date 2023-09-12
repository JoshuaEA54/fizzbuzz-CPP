

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
	Sprite spriteOfCard;


public:

	Card(int _number, string _type, int _color);
	Card(string _type, int _color);
	Card();
	~Card();

	void setNumber(int _number);
	void setType(string _type);
	void setColor(int _color);
	void setSprite(Texture& _texture);

	int getNumber();
	string getType();
	int getColor();
	Sprite getSprite();

	int redColor();//1
	int yellowColor();//2
	int greenColor();//3
	int blueColor();//4
	int allColor();//5

	int defineColor(int _variable, int& _x, Card& _aux);


};

Card** deckk();


//draws all the cards in order
void drawSprites(RenderWindow& _game, Card** _deck);
//trying to do it in desorder
void firstCard(RenderWindow& _game, Card** _deck,int _row, int _col);

//windows
void mainWindow();
void gameWindow(RenderWindow& _window);


     
