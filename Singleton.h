#pragma once
#ifndef _SINGLETON
#define _SINGLETON



#include "Player.h"
#include <string>
#include <fstream>
using namespace std;
class Singleton
{
private:
	static Singleton* instance;
	Singleton() {};

public:
	static Singleton* getInstance();
	Singleton(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton& operator=(Singleton&&) = delete;
	void endOfProgram();
	void updateFile(Player, Player);
};

#endif // !_SINGLETON