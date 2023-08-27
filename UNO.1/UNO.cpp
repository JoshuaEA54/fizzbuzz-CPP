
#include "programa.h"


int main()
{
	int x = 0;
	Card deck[8][14], aux;

	for (int i = 0; i < 8; i++) {

		if (i == 0 || i == 4) {
			x = aux.redColor();
		}
		else if (i == 1 || i == 5) {
			x = aux.yellowColor();
		}
		else if (i == 2 || i == 6) {
			x = aux.greenColor();
		}
		else {
			x = aux.blueColor();
		}

		for (int j = 0; j < 10; j++) {
			deck[i][j] = Card(j, "normal", x);
		}
	}
}






return 0;
}


//int cardDeck[8][10];//8 lines , 10 columns
//string jokerDeck[8][4];
//void defineCD();
//void defineJD();