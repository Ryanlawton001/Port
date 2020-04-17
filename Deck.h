#include "PowerClass.h"
#ifndef DECK_H_
#define DECK_H_
using namespace std;
#include <vector>
class Deck: public PowerClass
{
public:
	void createDeck();
	int deckSize();
	vector <PowerClass*> thing;
	void returnOne();
	PowerClass* returnCard(int);
	vector<PowerClass*> returnVector();
	void removeCard(int);


};

#endif // !DECK_H_