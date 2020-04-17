#pragma once
#ifndef POWERCLASS_H_
#define POWERCLASS_H_
#include <vector>

using namespace std;



class PowerClass
{
private:
	int powerLevel = 0;
public:
	PowerClass(int power);
	PowerClass() = default;
	void setPower(int power);
	int getPower();
	void steal(vector<PowerClass*>, vector<PowerClass*>, int);
	
	

};

#endif // !dd