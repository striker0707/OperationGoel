/** Food Database Manager
  *	Created by Group 3: Elton Vinh, Gordon Wang, Joanne Trinh, Ethan Huang, Loc Giang, Shyanaka Ramachandra
  * Manish Goel
  * CIS 22C
  */

#ifndef _FOOD_PROGRAM
#define _FOOD_PROGRAM

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "HashTable.h"
#include "BinarySearchTree.h"


using namespace std;

class FoodProgram
{
private:
	/** Sorted Linked List */
	SortedList<Food*> fLL;
	/** Hash table that uses name of food as key and linked lists for buckets */
	HashTable<string, Food*> fHT;
	/** Binary Search Tree that uses name to insert */
	BinarySearchTree<Food*> fBST;
public:
	/** Parses food input file and inputs into fLL, fHT, and fBST */
	FoodProgram();
	/** Saves any changes made to fLL to file */
	~FoodProgram();
	void menu();
	/** Inserts new user defined entry into fLL, fHT, and fBST */
	bool insert();
	/** Removes user defined entry from fLL, fHT, and fBST */
	bool remove();
	/** Search for entry based on name and then prints entries attributes */
	bool search();
	/**  Calculates total meal nutrition facts */
	void nutritionCalc();
};

#endif;
