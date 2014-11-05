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
	float calories;
	float gramsFat;
public:
	Food();
	string getName() const;
	float getCalories() const;
	float getGramsFat() const;
	void setCalories(float cal);
	void setGramsF(float gFat);
	friend ostream& operator<< (ostream& out, Food& dr);
	bool operator> (const Food& rdr);
	bool operator< (const Food& rdr);
};
#endif;
