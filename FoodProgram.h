#include <string>
#include "SortedList.h"
#include "Food.h"
#include "HashTable.h"

using namespace std;


class FoodProgram
{
private:
	SortedList<Food> fDB;
	HashTable<string, Food*> fHT;
public:
	FoodProgram();
	/** Parses food file and inputs into fDB */
	FoodProgram(string filename);
	/** Saves any changes made to fDB to file */
	~FoodProgram();
	bool fileIO(string filename);
	void menu() const;
	bool buildBST(int option);
	/** Inserts new entries into fDB */
	bool insert(string newEntry);
	/** Removes entries from fDB */
	bool remove(string targetEntry);

};

/* Remember that all food data needs to be stored as dynamic memory in both the BST and HT */