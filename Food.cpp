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
    cout << "Name : " << fd.getName() << endl;
    cout << "Calories : " << fd.getCalories() << endl;
    cout << "Grams Fat : " << fd.getGramsFat() << endl;
    cout << "Cholesterol : " << fd.getCholesterol() << endl;
    cout << "Sodium : " << fd.getSodium() << endl;
    cout << "Protein : " << fd.getProtein() << endl;
}

//Food& operator= (const Food& other)
//{
//    if (this != &other)
//    {
//       cout << " not same names" << endl;
//    }
//    
//    return this;
//}
//bool operator< (const Food& rdr) //I don't know what does that mean rdr. So was little confused 
//{
//    if(Food < rdr.Food)
//    {
//        return true;
//    }
//    
//    if(Food == rdr.Food && Food < rdr.Food)
//    {
//        return true;
//    }
//         
//    return false;
//    
//}
//bool operator> (const Food& rdr);
//{
//    if(Food > rdr.Food)
//    {
//        return true;
//    }
//    
//    if(Food == rdr.Food && Food > rdr.Food)
//    {
//        return true;
//    }
//    
//    return false;
//    
//}
//    
