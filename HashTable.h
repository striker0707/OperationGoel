// HashedTable adt
// By Elton Vinh

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "SortedList.h"
#include "LinkedList.h"

using namespace std;

const int MAX = 100;

template<class ItemType>
class HashTable
{
private:
	SortedList<ItemType> table[MAX];
	float sizeofArray;
	int count;
	
	
public:
	HashTable()
	{
		count = 0;
		sizeofArray = 0;
	}
	bool insert( ItemType& newEntry,  string key)
	{
		//calls hashingfunction first to get index
		//then uses SortedList's insert function to insert in linkedlist
		table[hashingFunction(key)].insert(newEntry);
	}
	bool search(string entry)
	{
		bool success = false;
		int index;
		DataRecord drEntry(entry);
		DataRecord returnedEntry;
	
		index = hashingFunction(entry);
		if( table[index].getEntry(drEntry, returnedEntry) )
		{
			success = true;
			return success;
		}

		return success;
	}
	/** Outputs to screen entry count, probes, collisions, load factor */
	void displayStats()
	{
		int largestProbes = 0;
		int i = 0;
		float loadFactor = 0.0;
		int noProbes = 0;
		vector<int> indexofLargestProbes;	//holds the index values of the elements with largest number of probes
	
		for( i = 0; i < MAX; i++ )	//walking the hashedtable array
		{
			count += table[i].size();
			if(!table[i].isEmpty())
				sizeofArray++;
			if( (table[i].size()-1) > largestProbes )	//Determining the largest number of probes in the hashedtable
				largestProbes = table[i].size()-1;
		}

		cout << "There are "<<count<<" foods in this database." << endl;
		cout << "The size of the database is " << sizeofArray <<endl;
		loadFactor = (sizeofArray/MAX)*100;
		cout << "Load factor is "<< loadFactor << "%" << endl <<endl;
		cout << "Collisions: " << endl <<endl;
	
		for(i = 0; i < MAX; i++)
		{
			if( !table[i].isEmpty() && table[i].size() > 1 )	//If index is not empty and linked list inside index is larger than 1 key, than output probes
				cout << "Index:	"<< i <<" Probes:	"<< table[i].size() << endl;
			if( !table[i].isEmpty() && table[i].size() == 1)	//if index is not empty and size of linked list is 1, then increment noProbe count.
				noProbes++;
			if( (table[i].size() - 1) == largestProbes )	//if element's probes is equal to largest number of probes. Than store index in vector for later printing.
				indexofLargestProbes.push_back(i);
		}

		cout << endl <<"Max number of probes is " << largestProbes << ", at:" < <endl <<endl;
	
		for( i = 0; i<indexofLargestProbes.size(); i++ )
		{
			cout<<"index "<< indexofLargestProbes[i] <<": ";
			table[indexofLargestProbes[i]].display();
		}
		cout<<endl<<"No collisions: "<<noProbes<<endl;

	}
	int hashingFunction(string key)
	{
		unsigned index = 0;
		for(unsigned int i = 0; i < key.size(); i++)
		{
			index = 33 * index ^ key[i];
		}
		while(index>MAX-1)
			index = index % MAX;
		return index;
	}
};

//template<class ItemType>
//HashTable::HashTable()
//{
//
//}

//template<class ItemType>
//bool HashTable::insert( ItemType& newEntry, string key)
//{
//													
//	//calls hashingfunction first to get index
//	//then uses SortedList's insert function to insert in linkedlist
//	table[hashingFunction(key)].insert(newEntry);
//}

//template<class ItemType>
//bool HashTable::search(string entry)
//{
//	bool success = false;
//	int index;
//	DataRecord drEntry(entry);
//	DataRecord returnedEntry;
//	
//	index = hashingFunction(entry);
//	if( table[index].getEntry(drEntry, returnedEntry) )
//	{
//		success = true;
//		return success;
//	}
//
//	return success;
//}

//template<class ItemType>
//void HashTable::displayStats()
//{
//	int largestProbes = 0;
//	int i = 0;
//	float loadFactor = 0.0;
//	int noProbes = 0;
//	vector<int> indexofLargestProbes;	//holds the index values of the elements with largest number of probes
//	
//	for( i = 0; i < MAX; i++ )	//walking the hashedtable array
//	{
//		count += table[i].size();
//		if(!table[i].isEmpty())
//			sizeofArray++;
//		if( (table[i].size()-1) > largestProbes )	//Determining the largest number of probes in the hashedtable
//			largestProbes = table[i].size()-1;
//	}
//
//	cout << "There are "<<count<<" foods in this database." << endl;
//	cout << "The size of the database is " << sizeofArray <<endl;
//	loadFactor = (sizeofArray/MAX)*100;
//	cout << "Load factor is "<< loadFactor << "%" << endl <<endl;
//	cout << "Collisions: " << endl <<endl;
//	
//	for(i = 0; i < MAX; i++)
//	{
//		if( !table[i].isEmpty() && table[i].size() > 1 )	//If index is not empty and linked list inside index is larger than 1 key, than output probes
//			cout << "Index:	"<< i <<" Probes:	"<< table[i].size() << endl;
//		if( !table[i].isEmpty() && table[i].size() == 1)	//if index is not empty and size of linked list is 1, then increment noProbe count.
//			noProbes++;
//		if( (table[i].size() - 1) == largestProbes )	//if element's probes is equal to largest number of probes. Than store index in vector for later printing.
//			indexofLargestProbes.push_back(i);
//	}
//
//	cout << endl <<"Max number of probes is " << largestProbes << ", at:" < <endl <<endl;
//	
//	for( i = 0; i<indexofLargestProbes.size(); i++ )
//	{
//		cout<<"index "<< indexofLargestProbes[i] <<": ";
//		table[indexofLargestProbes[i]].display();
//	}
//	cout<<endl<<"No collisions: "<<noProbes<<endl;
//
//}
//
//template<class ItemType>
//int HashTable::hashingFunction(string key)
//{
//	unsigned index = 0;
//	for(unsigned int i = 0; i < key.size(); i++)
//	{
//		index = 33 * index ^ key[i];
//	}
//	while(index>MAX-1)
//		index = index % MAX;
//	return index;
//}

