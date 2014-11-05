// Food
// By Elton Vinh

#ifndef _FOOD
#define _FOOD

#include <iostream>

using namespace std;

class Food
{
private:
	string name;
	int calories;
	int gramsFat;
public:
	Food();
	string getName() const;
	int getCalories() const;
	friend ostream& operator<< (ostream& out, Food& dr);
	bool operator> (const Food& rdr);
	bool operator< (const Food& rdr);
};
#endif;
