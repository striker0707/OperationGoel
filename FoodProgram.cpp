/** Food Database Manager
  *	Created by Group 3: Elton Vinh, Gordon Wang, Joanne Trinh, Ethan Huang, Loc Giang, Shyanaka Ramachandra
  * Manish Goel
  * CIS 22C
  */

#include "FoodProgram.h"

/** Prints contents of food objects. To be passed to a traversal function */
template<class ItemType>
void bstPrint(ItemType& item)
{
	cout << *item << endl;
}

/** Prints food objects to file, each food object gets its own line, attributes seperated by commas. To be passed
to a traversal function */
void prnToFile(stringstream& foodPrint, Food& item)
{
	foodPrint << item.getName() << ", ";
	foodPrint << item.getCalories() << ", ";
	foodPrint << item.getGramsFat() << ", ";
	foodPrint << item.getCholesterol() << ", ";
	foodPrint << item.getSodium() << ", ";
	foodPrint << item.getProtein();
}

/** Prints name of food object only. Used for indented tree printing */
void prnName(int indent, Food& item)
{
	cout << setw(indent) << ' ';
	cout<<item.getName()<< endl;
}

FoodProgram::FoodProgram()
{
	ifstream inputFile;
	string fname;
	string name;
	string buffer;
	string ssbuffer;
	float cal, gfat, chole, sodi, prot;

	inputFile.open("Archive.txt");
	if (inputFile.fail())
	{
		cout << "Unable to open input file" << endl;
		cout << "Ending Program" << endl;
		return;   // Ends Program if the if statement is true
	}
	else 
	{
		cout << "Files opened successfully, open output file to see results when program ends." << endl;
	}


	//Setting a dummy head pointer for BST, to aid in removing head node from BST
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

			Food* newFood = new Food(name,name,cal,gfat,chole,sodi,prot); 
			

			fLL.insert(newFood);
			fHT.insert(newFood, newFood->getName());
			fBST.insert(newFood);
		}
	}

}

FoodProgram::~FoodProgram()
{
	ofstream outFile;
	outFile.open("Archive.txt");
	cout << endl << "Saving changes..." << endl;
	system("pause");
	fBST.printToFile(outFile, prnToFile);
	outFile.close();
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
		cout << "1) Add new food data" << endl;
		cout << "2) Delete new food data" << endl;
		cout << "3) Look up nutritional information of food" << endl;
		cout << "4) List data in hash table sequence" << endl;
		cout << "5) List food data (sorted by name)" << endl;
		cout << "6) Print indented tree" << endl;
		cout << "7) Print Hash Table Statistics" << endl;
		cout << "8) Food Calculator" << endl;
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
				cout << endl << "-------------------------------------------------------------------" << endl;
				cout << "Food listed in Hash Sequence";
				cout << endl << "-------------------------------------------------------------------" << endl;
				cout << left << setw(19) << "Name";
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
				cout << endl << "-------------------------------------------------------------------" << endl;
				cout << "Food listed in Alphabetical Order";
				cout << endl << "-------------------------------------------------------------------" << endl;
				cout << left << setw(19) << "Name";
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
				fBST.indentedTree(prnName);
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
				cout << endl << "-------------------------------------------------------------------" << endl;
				cout << "Food Calculator";
				cout << endl << "-------------------------------------------------------------------" << endl;
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

	Food* insertFood = new Food(iName,iName,iCal,igFat,iChol,iSod,iPro);
	
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
	while(!(cin >> targetcal))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}

	cout << "Enter the number of food items in your meal: ";
	while(!(cin >> targetnum))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}

	for (int i = 0; i < targetnum; i++)
	{
		bool found;
		cout << "Enter the name of a food item (enter QUIT to exit): ";
		cin >> foodname;
		targetFood->setName(foodname);
		found = fHT.contains(foodname,targetFood);

		if(!found)
			cout << "Entry not found." << endl;
		else
		{
			cout << "Enter the amount of " << foodname << ": ";
			while(!(cin >> number))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Try again: ";
			}
			*targetFood = *targetFood * number;
		}

		foodsum = foodsum + *targetFood;
		if(!found && i >= 0)
		{
			i--;
		}
		if(foodname == "QUIT")
			break;
	}
	if(foodname == "QUIT")
			return;

	cout << "The total nutrition facts for your meal is: " << endl;
	cout << setw(19) << left << " ";
	cout << setw(9) << left << "Calories";
	cout << setw(11) << left << "Fat";
	cout << setw(12) << left << "Cholesterol";
	cout << setw(9) << left << "Sodium";
	cout << setw(7) << left << "Protein" << endl;
	cout << foodsum << endl << endl;
	if (targetcal - foodsum.getCalories() >= 0)
	{
		cout << "You are " << targetcal - foodsum.getCalories() << " calories short of your maximum." << endl << endl;
	}
	else
	{
		cout << "You are " << (targetcal - foodsum.getCalories()) * -1 << " calories over your maximum!" << endl << endl;
	}
}
