/** Nutrition database
    Created by Group 3: Elton Vinh, Gordon , Joanne Trinh, Ethan Huang, Loc, */

#define _CRTDBG_MAP_ALLOC

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "FoodProgram.h"
#include <crtdbg.h>

#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

using namespace std;

int main()
{
	FoodProgram NutritionDictionary;
	NutritionDictionary.menu();
  
    system("pause");//close database
	_CrtDumpMemoryLeaks();
	return 0;
}
