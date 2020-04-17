#include "Player.h"
using namespace std;
#include <iostream>
#include <vector>


Player::Player(){
	powerCount = 0;
	vector <PowerClass*> hand;
	play = 0;
	turn = false;
	int playedCard = 0;
	
}

int Player::getPowerCount() {
	return powerCount;
}
int Player::gethandSize() {
	return hand.size();

}
void Player::addCard(PowerClass* card, vector<PowerClass*> stack ) {
		this->hand.push_back(card);
		vector<PowerClass*>::iterator it = find(stack.begin(), stack.end(), card);
		int index = distance(stack.begin(), it);
		stack.erase(it);
}
vector<PowerClass*> Player::returnHand() {
	return hand;
}
void Player::returnOne() {
	for (int i = 0; i < hand.size(); i++) {
		cout << "[" << i << "]" << hand[i]->getPower() << endl;

	}
}
PowerClass* Player::returnCard(int i) {
	return hand[i];
}
void Player::setTurn(bool set) {
	turn = set;

}

bool Player::getTurn() {
	return turn;

}
void Player::removeCard(Player steve, int index) {
	
	this->hand.erase(this->hand.begin() + index);
	

}
int Player::playCard(int index) {
	return hand[index]->getPower();
	
	
}
char Player::returnHandChar() {
	for (int i = 0; i < hand.size(); i++) {
		return hand[i]->getPower();

	}
	

}
Player Player::returnPlayer(Player name) {
	
	return name;
}
int Player::getPlay() {
	return play;
}
void Player::setPlay(int set) {
	play = set;
}
int Player::playedOnTurnCard() {
	return playedCard;



}
void Player::setReturnCard(int played) {
	playedCard = played;

}


