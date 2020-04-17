#include "Match.h"
#include"Singleton.h"
using namespace std;
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
Player john;
Player comp;
Deck deck;

Singleton* instance = Singleton::getInstance();



void Match::startMatch() {
    
	srand(time(NULL));
	int pick = 0;
	int newPick = 0;
	cout << "The match is Loading..." << endl;
	
	
	vector<int> repeat;
	deck.createDeck();
	
	for (int i = 0; i < 5; i++) {
		int index = rand() % deck.deckSize();
		comp.addCard(deck.returnCard(index), deck.returnVector());
		deck.removeCard(index);
		cout << "The Computer Selected Number:  " << index << endl;
		
	}
	cout << " There are : " << deck.deckSize() -1 << " cards left to choose from." << endl;

	for (int i = 5; i < 10; i++) {
		cout << " Enter pick number " << i << "  : " << endl;
		cin >> pick;
		while(pick < 0 || pick > deck.deckSize() || pick == deck.deckSize()) {
			cout << "Choose Again: " << endl;
			cin >> pick;
		}
			john.addCard(deck.returnCard(pick), deck.returnVector());
			deck.removeCard(pick);

	}
		cout << "This is your hand: " << endl;
		john.returnOne();

	}


void Match::takeTurn() {
	
	while (isGameFinished() == false) {
		
		john.setTurn(false);
		comp.setTurn(true);
		cout << "The Computer will choose first " << endl;
		int compNumber = compRandom();
		int stealRandom = compRandom();
		
		if (comp.getTurn() == true) {
			comp.setPlay(1);
			john.setPlay(0);
			Singleton::getInstance()->updateFile(john, comp);
			
			if (comp.gethandSize() != 0) {

				if (comp.returnCard(compNumber)->getPower() == 0) {
					if (john.gethandSize() == 0) {
						comp.setPower(comp.getPower() + 1);
						cout << "The Computer has used a steal card but you have no cards left... +1 was added to their power!" << endl;
						cout << "Their New Power Is: " << comp.getPower() << endl;
						comp.setReturnCard(comp.returnCard(compNumber)->getPower());
						comp.removeCard(comp, compNumber);
						comp.setTurn(false);
						john.setTurn(true);
						
						
						

					}
					else {
						comp.addCard(john.returnCard(humanStealRandom()), john.returnHand());
						comp.setReturnCard(comp.returnCard(compNumber)->getPower());
						john.removeCard(john, humanStealRandom());
						comp.removeCard(comp, stealRandom);
						cout << "The Computer has used the steal card: " << endl;
						comp.setTurn(false);
						john.setTurn(true);
						
					
					}

				}
				else if (comp.returnCard(compNumber)->getPower() < 0) {
					john.setPower(john.getPower() + comp.playCard(compNumber));
					comp.setReturnCard(comp.returnCard(compNumber)->getPower());
					comp.removeCard(comp, compNumber);
					cout << "The Computer choose a minus power card... " << endl;
					cout << "Your new Power Level is:  " << john.getPower() << endl;
					comp.setTurn(false);
					john.setTurn(true);
					
					

				}
				else {
					cout << "The computer used a power bonus on themselves!!..." << endl;
					comp.setPower(comp.getPower() + comp.playCard(compNumber));
					comp.setReturnCard(comp.returnCard(compNumber)->getPower());
					comp.removeCard(comp, compNumber);
					cout << "Their power is now: " << comp.getPower() << endl;
					comp.setTurn(false);
					john.setTurn(true);
					
					
				}
			}
			else {
				comp.setTurn(false);
				john.setTurn(true);
				
			}
			
			


			}
		
		if (john.getTurn() == true) {
			john.setPlay(1);
			comp.setPlay(0);
			Singleton::getInstance()->updateFile(john, comp);
			john.returnOne();
			int pick = 0;
			if (john.gethandSize() != 0) {
				cout << "Enter the card you want to play: " << endl;
				cin >> pick;
				while (pick < 0 || pick > john.gethandSize() || pick == john.gethandSize()) {
					cout << "Enter a different number: " << endl;
					cin >> pick;
				}

				if (john.returnCard(pick)->getPower() == 0) {
					if (comp.gethandSize() == 0) {
						john.setPower(john.getPower() + 1);
						cout << "The computer has no more cards left to play.. + 1 was added to your power" << endl;
						cout << "Your New Power Is: " << john.getPower() << endl;
						john.setReturnCard(john.returnCard(pick)->getPower());
						john.removeCard(john, pick);
						john.setTurn(false);
						comp.setTurn(true);
					
						
					}
					else {
						john.addCard(comp.returnCard(pick), comp.returnHand());
						john.setReturnCard(john.returnCard(pick)->getPower());
						john.removeCard(john, pick);
						comp.removeCard(comp, compRandom());
						
						cout << "You used a steal Card..." << endl;
						cout << "Your new hand is this.." << endl;
						john.returnOne();
						john.setTurn(false);
						comp.setTurn(true);
						
						
					}

				}
				else if (john.returnCard(pick)->getPower() < 0) {
					comp.setPower(comp.getPower() + john.playCard(pick));
					john.setReturnCard(john.returnCard(pick)->getPower());
					john.removeCard(john, pick);
					cout << " You used a minus power card..." << endl;
					cout << "The computers new power level is: " << comp.getPower() << endl;
					john.setTurn(false);
					comp.setTurn(true);
					
					

				}
				else
				{
					john.setPower(john.getPower() + john.playCard(pick));
					john.setReturnCard(john.returnCard(pick)->getPower());
					john.removeCard(john, pick);
					cout << "You selected a power plus Card!..." << endl;
					cout << "Your new Power is: " << john.getPower() << endl;
					john.setTurn(false);
					comp.setTurn(true);
					
					

				}
			}
			else {
				john.setTurn(false);
				comp.setTurn(true);
			}
			
		}
		

	}
	
}

int Match::compRandom() {
	int random = 0;
	if (comp.gethandSize() != 0) {
		random = rand() % comp.gethandSize();
		return random;

	}
}
int Match::humanStealRandom() {
	int random = 0;
	if (john.gethandSize() != 0) {
		random = rand() % john.gethandSize();
		return random;

	}
}
bool Match::isGameFinished() {

	if (comp.gethandSize() == 0 && john.gethandSize() == 0) {
		cout << "The game has Ended..." << endl;
		cout << "The Final Power Levels... " << endl;
		cout << "    You: " << john.getPower() << "    Computer: " << comp.getPower() << endl;
		if (john.getPower() < comp.getPower()) {
			cout << "The Computer Has WON!!!...." << endl;
		
		}
		else if (john.getPower() == comp.getPower()) {
			cout << "It's a draw!!!" << endl;
		}
		else {
			cout << "You Are The Winner!! Congratulations!" << endl;
		}
		

		return true;
	}

	else {
		return false;
		
	}
	
}

bool Match::isRepeatNumber(int compNumber, vector<int> repeat) {
	if (count(repeat.begin(), repeat.end(), compNumber)) {
		return true;

	}
	else {
		return false;
	}
}







