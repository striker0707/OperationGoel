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
	//Default Constructor
	Food();
	//Copy Constructor
	Food(const Food &obj);
	
	string getName() const;
	float getCalories() const;
	float getGramsFat() const;
	void setCalories(float cal);
	void setGramsF(float gFat);
	
	Food& operator= (const Food& other);
	friend ostream& operator<< (ostream& out, Food& dr);
	bool operator> (const Food& rdr);
	bool operator< (const Food& rdr);
};
#endif;
