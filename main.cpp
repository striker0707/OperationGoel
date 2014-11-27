/** Nutrition database
    Created by Group 3: Elton Vinh, Gordon , Joanne Trinh, Ethan Huang, Loc, */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "FoodProgram.h"
#define _CRTDBG_MAP_ALLOC
#include <iostream>
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

	///* BST TEST///////////////////////////*/
	//BinarySearchTree<char> bst;
	//bst.insert('j');
	//bst.insert('f');
	//bst.insert('k');
	//bst.insert('z');
	//bst.insert('a');
	//bst.insert('h');
	//bst.insert('d');
	//cout << bst.size() << endl;
	//bst.indentedTree();
	//bst.breadthfirst(print); cout << endl;
	//bst.inOrder(print); cout << endl;
	//bst.preOrder(print); cout << endl;
	//bst.postOrder(print); cout << endl;
	//bst.clear();
	//cout << bst.indentedTree() << endl;
	//cout << bst.isEmpty() << endl;
	//cout << bst.size() << endl;
	///*///////////////////////////////////*/


	//HashTable<string,string> ht;
	//ht.insert("Elton", "Elton");
	//ht.insert("Gordon", "Gorfon");
	//ht.insert("Joanne", "Joanne");
	//ht.insert("Ethan", "Ethan");
	//ht.insert("Rama", "Rama");
	//ht.insert("Loc", "Loc");
	//ht.displayStats();
  
    system("pause");//close database
	_CrtDumpMemoryLeaks();
	return 0;
	
}
