#pragma once
#ifndef PLAYER_H_
#define PLAYER_H_
#include "Deck.h"

using namespace std;
#include <vector>
class Player: public Deck 
{
private:
	int powerCount;
	vector<PowerClass*> hand;
	bool turn;
	int play;
	int playedCard;
	
public:
	Player();
	int gethandSize();
	int getPowerCount();
	void addCard(PowerClass*, vector<PowerClass*> );
	void returnOne();
	PowerClass* returnCard(int);
	vector<PowerClass*> returnHand();
	bool getTurn();
	void setTurn(bool);
	int playCard(int);
	void removeCard(Player, int);
	char returnHandChar();
	Player returnPlayer(Player);
	int getPlay();
	void setPlay(int);
	int playedOnTurnCard();
	void setReturnCard(int);
	


};

#endif // !PLAYER_H_