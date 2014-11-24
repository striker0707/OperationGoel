#ifndef _FOOD_PROGRAM
#define _FOOD_PROGRAM

#include <iostream>
#include <string>
#include "SortedList.h"
#include "Food.h"
#include "HashTable.h"
#include "BinarySearchTree.h"

using namespace std;

/** Change what you need to get it to work. Need to have all menu functions implemented */
class FoodProgram
{
private:
	SortedList<Food> fDB;
	HashTable<string, Food*> fHT;
	string fileName;
public:
	/** Intializes fDB and fHT */
	FoodProgram();
	/** Parses food file and inputs into fDB */
	FoodProgram(string filename);
	/** Saves any changes made to fDB to file */
	~FoodProgram();
	bool fileIO();
	void menu() const;
	/** Accepts option and builds BST from fDB sorted by said option */
	bool buildBST(int option);
	/** Inserts new entries into fDB */
	bool insert(string newEntry);
	/** Removes entries from fDB */
	bool remove(string targetEntry);

};

#endif;

/* Remember that all food data needs to be stored as dynamic memory in both the BST and HT */
/* "As the records are read, they are placed in dynamic memory and the memory location (address) is then inserted" */

void FoodProgram::menu() const
{
	char choice = -1;
 
	while(choice != 9)
	{
		//menu text is taken directly from the project req
		//recommend we change or lsightly modify some of the names so more "user friendly"ish
		cout << "     MENU" << endl;
		cout << "1) Add new data" << endl;
		cout << "2) Delete data" << endl;
		cout << "3) Find and display one data record using the primary key" << endl; 
		cout << "4) List data in hash table sequence" << endl;
		cout << "5) List data in key sequence (sorted)" << endl;
		cout << "6) Print indented tree" << endl;
		cout << "7) Effeciency" << endl;
		cout << "8) SECRET MENU OPTION" << endl;
		cout << "9) Quit" << endl;
    
		cin >> choice;
    
		//ENTER FUNCTION CALLS FOR EACH MODULE AS WE COMPLETE IT,
		//PLEASE COMMENT OUT YOUR FUNCTION CALL IF YOU COMMIT A CHANGE THAT IS NOT COMPILABLE
		//switch(choice)
		//case 1:	
		//	break;
		//case 2:
		//  break;
		//case 3:
		//  break;
		//case 4:
		//  break;
		//case 5:
		//  break;
		//case 6:
		//  break;
		//case 7:
		//  break;
		//case 8:
		//  break;
		//case 9: //user quit case
		//  return 0;
		//  break;
		//default:
		//cout << "Invalid Option, please enter a valid option (1-9)." << endl;
		//system("pause");
		//break;
	}
}
