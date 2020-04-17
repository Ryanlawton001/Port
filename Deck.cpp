#include "Deck.h"
using namespace std;
#include <iostream>

void Deck::createDeck() {
	int i;
	thing.reserve(20);
	for (i = 0; i < 20; i++) {
		thing.push_back(new PowerClass((rand() % 10) - 5));	
	
	}
}
int Deck::deckSize() {
	int total = 0;
	for (int i = 0; i < thing.size(); i++, total++){
		
		
		}
	return total;
}
void Deck::returnOne() {
	for (int i = 0; i < thing.size(); i++) {
		cout << "[" << i << "]" << thing[i]->getPower() << endl;

	}
	

}
vector<PowerClass*> Deck::returnVector() {
	return thing;

}
PowerClass* Deck::returnCard(int i) {
	return thing[i];
}

void Deck::removeCard(int index) {	
		thing.erase(thing.begin() + index);

}
