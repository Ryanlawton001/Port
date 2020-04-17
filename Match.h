#pragma once
#ifndef MATCH_H_
#define MATCH_H_
#include "Player.h"
#include "Singleton.h"


class Match
{
public:
	void startMatch();
	
	void takeTurn();

	int compRandom();
	int humanStealRandom();
	bool isGameFinished();
	bool isRepeatNumber(int, vector<int>);
	


};

#endif // !MATCH_H_