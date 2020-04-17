#include "Singleton.h"
#include"Player.h"
#include "Match.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
Singleton* Singleton::instance = 0;
fstream logfile;
Player playerTurn;

Singleton* Singleton::getInstance() {
	if (!instance){
		static Singleton instance;
	}
	return instance;
}
void Singleton::endOfProgram() {
	logfile.close();

	delete instance;
	instance = 0;
}
void Singleton::updateFile(Player human, Player comp) {
	Player playerTurn;
	logfile.open("Testing1234567891234.txt", fstream::app);

	if (logfile.is_open()) {
		if (comp.getPlay() == 1){
			playerTurn = comp;
			logfile << "It is the Computers turn." << endl;

		}
		else if (human.getPlay() == 1){
			playerTurn = human;
			logfile << "It is the Humans turn" << endl;
			
		}

		logfile << "The Players Power level is: " << playerTurn.getPower() << endl;
		if (playerTurn.playedOnTurnCard() == NULL) {
			logfile << "They Didn't Select A Card" << endl;
		}
		else {
			logfile << "They used this card: " << playerTurn.playedOnTurnCard() << endl;
		}
		for (int i = 0; i < playerTurn.gethandSize(); i++) {
			if (playerTurn.gethandSize() == 1) {
				logfile << "No Cards Left" << endl;
			}
			else {
				logfile << "Card:  " << playerTurn.returnCard(i)->getPower() << endl;
			}
		}
		logfile << "-----End of Turn-----" << endl;
		logfile.close();
		

	}


}