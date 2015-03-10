#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>
#include <ostream>

using namespace std;

const int MAX_CARDS = 52;

struct card {
	string suit;
	string value;	
};

void initDeck(std::vector<card> & deck)
{
	card c;

	string suit[] = { "D", "H", "C", "S"};
	string value[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

	for (int i=0; i<4; i++) {
		for (int j=0; j<13;j++) {
			c.suit = suit[i];
			c.value = value[j];
			deck.push_back(c);
		}
	}
}

int getRand(int val)
{
	return (rand() % MAX_CARDS);
}

void shuffleDeck(std::vector<card> &deck) 
{
	card c;
	int index;
	for (int i=0; i<deck.size();i++) {
		index = getRand(i);
		c = deck[i];
		deck[i] = deck[index];
		deck[index] = c;
	}
}

void printDeck(const std::vector<card> deck, ostream &os)
{
	for (int i=0; i<deck.size(); i++) {
		os << deck[i].value << "" << deck[i].suit << ",";
		//if (i != deck.size()-1) os << ",";
	}
	os << endl;
}

int main()
{
	vector<card> deck;
	filebuf fb;
	fb.open("shuffle_cards.csv", std::ios::out);
	ostream os(&fb);

	initDeck(deck);
	printDeck(deck, os);

	for (int i=0; i<3000;i++) {
		shuffleDeck(deck);
		printDeck(deck, os);
	}

	fb.close();

	return 0;
}
