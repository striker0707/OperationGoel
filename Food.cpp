#include "Food.h"

Food::Food()
{
    name = "";
    calories = 0;
    gramsFat = 0;
    cholesterol = 0;
    sodium = 0;
    protein = 0;
}

Food::Food(string n)
{
	name = n;
	sortKey = n;
}

Food::Food(const Food &fobj)
{
    name = fobj.getName();
    calories = fobj.getCalories();
    gramsFat = fobj.getGramsFat();
    cholesterol = fobj.getCholesterol();
    sodium = fobj.getSodium();
    protein = fobj.getProtein();
    
}

Food::Food(string inputfname, float inputcal, float inputgFat, float inputcho, float inputsod, float inputpro)
{
    name = inputfname;
    calories = inputcal;
    gramsFat = inputgFat;
    cholesterol = inputcho;
    sodium = inputsod;
    protein = inputpro;
}
Food::Food(string inputskey, string inputfname, float inputcal, float inputgFat, float inputcho, float inputsod, float inputpro)
{
	sortKey = inputskey;
    name = inputfname;
    calories = inputcal;
    gramsFat = inputgFat;
    cholesterol = inputcho;
    sodium = inputsod;
    protein = inputpro;
}

string Food::getName() const
{
    return name;
}

float Food::getCalories() const
{
    return calories;
}

float Food::getGramsFat() const
{
    return gramsFat;
}

float Food::getCholesterol() const
{
    return cholesterol;
}

float Food::getSodium() const
{
    return sodium;
}

float Food::getProtein() const
{
    return protein;
}

void Food::setName(string inputname)
{
    name = inputname;
}

void Food::setCalories(float cal)
{
    calories = cal;
}

void Food::setGramsF(float gFat)
{
    gramsFat = gFat;
}

void Food::setCholesterol(float cholest)
{
    cholesterol = cholest;
}

void Food::setSodium(float inputsod)
{
    sodium = inputsod;
}

void Food::setProtein(float inputpro)
{
    protein = inputpro;
}

void Food::print(Food& fd)
{
	cout << endl << fd.getName() << endl;
	cout << "=======================" << endl;
    cout << "Calories : " << fd.getCalories() << endl;
    cout << "Grams Fat : " << fd.getGramsFat() << endl;
    cout << "Cholesterol : " << fd.getCholesterol() << endl;
    cout << "Sodium : " << fd.getSodium() << endl;
    cout << "Protein : " << fd.getProtein() << endl;
}



bool Food::operator < (const Food& rdr)
{
	return (sortKey < rdr.sortKey);
}
bool Food::operator > (const Food& rdr)
{
	return (sortKey > rdr.sortKey);
}
    
Food Food::operator + (const Food& aFood)
{
	Food food;
	food.name = " ";
	food.calories = this->calories + aFood.calories;
	food.gramsFat = this->gramsFat + aFood.gramsFat;
	food.cholesterol = this->cholesterol + aFood.cholesterol;
    food.sodium = this->sodium + aFood.sodium;
    food.protein = this->protein + aFood.protein;

	return food;
}

Food Food::operator - (const Food& aFood)
{
	Food food;
	food.name = " ";
	food.calories = this->calories - aFood.calories;
	food.gramsFat = this->gramsFat - aFood.gramsFat;
	food.cholesterol = this->cholesterol - aFood.cholesterol;
    food.sodium = this->sodium - aFood.sodium;
    food.protein = this->protein - aFood.protein;

	return food;
}

ostream& operator << (ostream& foodPrint, const Food& aFood)
{
	//foodPrint << "Your total nutrition facts are:" << endl;
	foodPrint /*<< "Name: "*/ << aFood.getName();
	foodPrint <<"\t"<< aFood.getCalories();
	foodPrint <<"\t"<< aFood.getGramsFat();
	foodPrint <<"\t"<< aFood.getCholesterol();
	foodPrint <<"\t"<< aFood.getSodium();
	foodPrint <<"\t"<< aFood.getProtein();

	return foodPrint;
}
bool operator == (const Food& ldr, const Food& rdr)
{
	return (ldr.name == rdr.name);
}
bool operator != (const Food& ldr, const Food& rdr)
{
	return (ldr.name != rdr.name);
}