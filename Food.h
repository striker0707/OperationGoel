// Food
// By Elton Vinh

#ifndef _FOOD
#define _FOOD

#include <iostream>
#include <string>

using namespace std;
//test
class Food
{
private:
	string name;
	float calories;
	float gramsFat;
	float cholesterol;
    float sodium;
    float protein;
public:
	//Default Constructor
	Food();
	//Copy Constructor
	Food(const Food &obj);
	//Constructor to create new foodobj
	Food(string inputfname, float inputcal, float inputgFat, float inputcho, float inputsod, float inputpro);
	
	//Accessor functions
	string getName() const;
    float getCalories() const;
	float getGramsFat() const;
	float getCholesterol() const;
	float getSodium() const;
	float getProtein() const;
    	
    //Mutator functions
	void setName(string inputname);
	void setCalories(float cal);
	void setGramsF(float gFat);
	void setCholesterol(float cholest);
	void setSodium(float inputsodium);
	void setProtein(float inputpro);
	
	//Prints attributes of food class
	void print(Food& fd);
	
	//Overloaded functions
	Food& operator= (const Food& other);
	friend ostream& operator<< (ostream& out, Food& dr);
	bool operator> (const Food& rdr);
	bool operator< (const Food& rdr);
};

#endif;
