#ifndef _FOOD_PROGRAM
#define _FOOD_PROGRAM

#include <iostream>
#include <string>
#include <fstream>
#include "SortedList.h"
#include "Food.h"
#include "HashTable.h"
#include "BinarySearchTree.h"
#include <sstream>

using namespace std;

template<class ItemType>
void bstPrint(ItemType& item)
{
	cout << *item << endl;
}

void prnToFile(stringstream& foodPrint, Food& item)
{
	foodPrint << item.getName() << ", ";
	foodPrint << item.getCalories() << ", ";
	foodPrint << item.getGramsFat() << ", ";
	foodPrint << item.getCholesterol() << ", ";
	foodPrint << item.getSodium() << ", ";
	foodPrint << item.getProtein();
}

template<class ItemType>
void prnName(ItemType&)
{
	cout << indent <<"|"<< *nodePtr->getItem() <<"|"<< endl;
}

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

FoodProgram::FoodProgram()
{
	ifstream inputFile;
	string fname;
	string name;
	string buffer;
	string ssbuffer;
	float cal, gfat, chole, sodi, prot;

	inputFile.open("Archive.txt");
	if (inputFile.fail())       // Checks if both output and input are false
	{
		cout << "Unable to open input file" << endl;                      // If false, prints an error message
		cout << "Ending Program" << endl;
		return;   // Ends Program if the if statement is true
	}      // End if
	else    // When successful opening, program will print sucession
	{
		cout << "Files opened successfully, open output file to see results when program ends" << endl;
	} // end if else


	//Setting a dummy head pointer for BST
	Food* dummy = new Food();
	fBST.insert(dummy);
	
	if(inputFile.is_open())
	{
		while( getline(inputFile, buffer) )
		{
			stringstream ss(buffer);
  
			getline(ss,ssbuffer, ',');
			name = ssbuffer;
			getline(ss,ssbuffer, ',');
			cal = stof(ssbuffer);
			getline(ss,ssbuffer, ',');
			gfat = stof(ssbuffer);
			getline(ss,ssbuffer, ',');
			chole = stof(ssbuffer);
			getline(ss,ssbuffer, ',');
			sodi = stof(ssbuffer);
			getline(ss,ssbuffer, ',');
			prot = stof(ssbuffer);

			Food* newFood = new Food(name,name,cal,gfat,chole,sodi,prot); //needs to be delete
			

			fLL.insert(newFood);
			fHT.insert(newFood, newFood->getName());
			fBST.insert(newFood);
		}
	}

}

FoodProgram::~FoodProgram()
{
	cout << endl << "Saving changes..." << endl;
	system("pause");
	fLL.printToFile("Archive.txt", prnToFile);
	fBST.clear();
	fHT.clear();
	fLL.clear();
}

void FoodProgram::menu()
{
	int choice = -1;

	while (choice != 9)
	{
		cout << endl << "///////////////////////////////////////////////" << endl;
		cout << "     MENU" << endl;
		cout << "1) Add new data" << endl;
		cout << "2) Delete data" << endl;
		cout << "3) Look up nutritional information of food" << endl;
		cout << "4) List data in hash table sequence" << endl;
		cout << "5) List data in key sequence (sorted)" << endl;
		cout << "6) Print indented tree" << endl;
		cout << "7) Effeciency" << endl;
		cout << "8) SECRET MENU OPTION" << endl;
		cout << "9) Quit" << endl;
		cout << "///////////////////////////////////////////////" << endl;
		cout << ": ";

		cin >> choice;

		switch (choice)
		{
			case 1:
			{
				this->insert();
				system("pause");
				break;
			}
			case 2:
			{
				this->remove();
				system("pause");
				break;
			}
			case 3:
			{
				this->search();
				system("pause");
				break;
			}
			 
			case 4:
			{
				cout << endl << "-----------------------------------------------------------------" << endl;
				cout << "Food listed in Hash Sequence";
				cout << endl << "-----------------------------------------------------------------" << endl;
				cout << left << setw(17) << "Name";
				cout << left << setw(9) << "Calories";
				cout << left << setw(11) << "Grams Fat";
				cout << left << setw(12) << "Cholesterol";
				cout << left << setw(9) << "Sodium";
				cout << left << setw(7) << "Protein" << endl << endl;
				fHT.print();
				cout << endl;
				system("pause");
				break;
			}
			case 5:
			{
				cout << endl << "-----------------------------------------------------------------" << endl;
				cout << "Food listed in Alphabetical Order";
				cout << endl << "-----------------------------------------------------------------" << endl;
				cout << left << setw(17) << "Name";
				cout << left << setw(9) << "Calories";
				cout << left << setw(11) << "Grams Fat";
				cout << left << setw(12) << "Cholesterol";
				cout << left << setw(9) << "Sodium";
				cout << left << setw(7) << "Protein" << endl;
				fBST.inOrder(bstPrint);
				cout << endl;
				system("pause");
				break;
			}
			case 6:
			{
				fBST.indentedTree();
				system("pause");
				break;
			}
			case 7:
			{
				fHT.displayStats();
				system("pause");
				break;
			}
			case 8:
			{
				this->nutritionCalc();
				break;
			}
			case 9: //user quit case
			{
				return;
			}
			default:
			{
				cout << "Invalid Option, please enter a valid option (1-9)." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				break;
			}
		}
	}

}

bool FoodProgram::insert()
{
	string iName = "Elton";
	float iCal, igFat, iChol, iSod, iPro;
	
	cout << endl << "Please enter information about new food." << endl;
	
	cout << "Name: ";
	cin.ignore(); //ignore newline
	getline(cin, iName);
	
	cout << "Calories: ";
	while(!(cin >> iCal))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}

	cout << "Grams Fat: ";
	while(!(cin >> igFat))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}
	
	cout << "Cholesterol: ";
	while(!(cin >> iChol))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}
	
	cout << "Sodium: ";
	while(!(cin >> iSod))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}
	
	cout << "Protein: ";
	while(!(cin >> iPro))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}
	
	if(iCal < 0 || igFat < 0 || iChol < 0 || iSod < 0 || iPro < 0)
	{
		cout << "Negative values are invalid." << endl;
		return false;
	}

	Food* insertFood = new Food(iName,iName,iCal,igFat,iChol,iSod,iPro); //needs to be delete
	
	fBST.insert(insertFood);
	fLL.insert(insertFood);
	fHT.insert(insertFood, insertFood->getName());

	return true;
}

bool FoodProgram::remove()
{
	string iName;

	cout << "Name of food to remove: ";
	cin.ignore(); //ignore newline
	getline(cin, iName);

	Food removeFood(iName);

	
	fBST.remove(&removeFood);
	fHT.remove(iName);
	fLL.remove(&removeFood);

	return true;
}

bool FoodProgram::search()
{
	Food* fd = new Food();
	string item;
	
	cout << endl << "What food would you like to look up?: ";
	cin.ignore(); //ignore newline
	getline(cin, item);
	
	if (fHT.contains(item, fd))
	{
		fd->print(*fd);
		return true;
	}
	else
	{
		cout << "No food with that name found." << endl;
	}
	return false;
}

void FoodProgram::nutritionCalc()
{
	int number;
	float targetcal;
	int targetnum;
	string foodname;
	Food foodsum = Food();
	Food* targetFood = new Food();

	cout << "Enter a maximum calorie amount: ";
		cin >> targetcal;
	cout << "Enter the number of food items in your meal: ";
		cin >> targetnum;

	for (int i = 0; i < targetnum; i++)
	{
		cout << "Enter the name of a food item (enter QUIT to exit): ";
			cin >> foodname;
			targetFood->setName(foodname);
			fHT.contains(foodname,targetFood);
			//targetFood = fLL.getFood(foodname);

		if(*targetFood != Food())
		{
			cout << "Enter the amount of " << foodname << ": ";
				cin >> number;
				*targetFood = *targetFood * number;
		}

		foodsum = foodsum + *targetFood;
		if(*targetFood == Food())
		{
			i--;
		}
		if(foodname == "QUIT")
			break;
	}
	if(foodname == "QUIT")
			return;
	//is someone using the overloaded ostream operator for food for soemthing or cna i change it?
	cout << "The total nutrition facts for your meal is: " << endl;
	cout << setw(17) << left << " ";
	cout << setw(9) << left << "Calories";
	cout << setw(11) << left << "Fat";
	cout << setw(12) << left << "Cholesterol";
	cout << setw(9) << left << "Sodium";
	cout << setw(7) << left << "Protein" << endl;
	cout << foodsum << endl << endl;
	if (targetcal - foodsum.getCalories() >= 0)
	{
		cout << "You are " << targetcal - foodsum.getCalories() << " calories short of your maximum." << endl << endl;
		cout << "Possible items to add are: " << endl;
		//IMPLEMENT:print out all items that have < targetcal - foodsum.getCalories() calories from bst sorted by calories
	}
	else
	{
		cout << "You are " << (targetcal - foodsum.getCalories()) * -1 << " calories over your maximum!" << endl << endl;
	}
}
