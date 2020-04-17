#include "PowerClass.h"
#include <vector>
#include <iostream>
using namespace std;

PowerClass::PowerClass(int power) {
	powerLevel = power;

}

int PowerClass::getPower() {

	return powerLevel;
}
void PowerClass::setPower(int power) {
	powerLevel = power;

	
}
void PowerClass::steal(vector<PowerClass*> stealer, vector<PowerClass*> victim, int index) {
	
	
	
}

