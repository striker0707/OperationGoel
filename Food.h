// Food
// By Elton Vinh

#ifndef _FOOD
#define _FOOD

#include <iostream>
#include <string>

using namespace std;

class Food
{
private:
	/* name is also unique key to be used in HT */
	string name;
	float calories;
	float gramsFat;
	float cholesterol;
    float sodium;
    float protein;
    /* sortKey is used by BST to sort BST based on one of the attributes above */
	float sortKey;
public:
	//Default Constructor
	Food();
	Food(string n);
	//Copy Constructor
	Food(const Food &obj);
	//Constructor to create new foodobj
	Food(string inputfname, float inputcal, float inputgFat, float inputcho, float inputsod, float inputpro);
	//Sortkey constructor
	Food(string inputskey, string inputfname, float inputcal, float inputgFat, float inputcho, float inputsod, float inputpro);
	
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
	bool operator == (const Food& rdr);
	bool operator > (const Food& rdr);
	bool operator < (const Food& rdr);
	Food operator + (const Food&);
	Food operator - (const Food&);
	friend ostream& operator << (ostream&, const Food&);
};

#endif;
