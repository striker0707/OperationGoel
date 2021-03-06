/*  Hashed Table
  *	Created by Group 3: Elton Vinh, Gordon Wang, Joanne Trinh, Ethan Huang, Loc Giang, Shyanaka Ramachandra
  * Manish Goel
  * CIS 22C
  */
#ifndef _HASH_TABLE
#define _HASH_TABLE

#include <vector>
#include <string>
#include "SortedList.h"
#include "Food.h"

using namespace std;

const int MAX = 33;

template<class KeyType, class ItemType>
class HashTable
{
private:
	SortedList<ItemType> table[MAX];
	int count;
public:
	HashTable();
	bool isEmpty();
	/** Insert 
	@param key to be used to generate a index location
	*/
	bool insert(const ItemType& newEntry, const KeyType& key);
	/** Remove 
	@param key used to locate index to remove
	*/
	bool remove(const KeyType& key);
	void clear();
	/** Gives you the item of your target
	@param item is provided by user and is the found item object
	*/
	bool contains(const KeyType& sKey,  ItemType& item);
	bool getItem(const KeyType& sKey, ItemType& foundItem);
	/** Displays efficient stats of Hash Table such as load factor,
	and collision info.
	*/
	bool displayStats();
	int hashingFunction(const KeyType key);
	bool print() const;
};
#endif;

template<class KeyType, class ItemType>
HashTable<KeyType,ItemType>::HashTable()
{
	count = 0;
}

template<class KeyType, class ItemType>
bool HashTable<KeyType,ItemType>::isEmpty()
{
	return (count == 0);
}

template<class KeyType, class ItemType>
bool HashTable<KeyType,ItemType>::insert(const ItemType& newEntry, const KeyType& key)
{
	int i;
	i = hashingFunction(key);
	table[i].insert(newEntry);
	count++;
	return true;
}

template<class KeyType, class ItemType>
bool HashTable<KeyType,ItemType>::remove(const KeyType& key)
{
	int i;
	Food fd = Food(key);
	ItemType targetKey = new Food();
	*targetKey = fd;
	ItemType foundItem = new Food();
	i = hashingFunction(key);
	if (table[i].getEntry(targetKey, foundItem))
	{
		table[i].remove(foundItem);
		count--;
		return true;
	}
	return false;
}

template<class KeyType, class ItemType>
void HashTable<KeyType,ItemType>::clear()
{
	for (int i = 0; i<MAX; i++)
		table[i].clear();
}

template<class KeyType, class ItemType>
bool HashTable<KeyType,ItemType>::contains(const KeyType& sKey,  ItemType& item)
{
	Food fd = Food(sKey);
	ItemType targetKey = new Food();
	*targetKey = fd;

	bool success = false;

	int i = this->hashingFunction(sKey);
	if (table[i].getEntry(targetKey, item))
	{
		success = true;
	}
	return success;
}

template<class KeyType, class ItemType>
bool HashTable<KeyType,ItemType>:: getItem(const KeyType& sKey, ItemType& foundItem)
{
	bool success = false;
	Food fd = Food(sKey);
	ItemType targetItem = new Food();
	*targetItem = fd;

	int i = hashingFunction(sKey);
	if (table[i].getEntry(targetItem, foundItem))
	{
		success = true;
	}
	return success;
}

template<class KeyType, class ItemType>
bool HashTable<KeyType,ItemType>::displayStats()
{
	int largestProbes = 0;
	int i = 0;
	float loadFactor = 0.0;
	int noProbes = 0;
	float averageProbes = -1;
	float occupiedIndexes = 0.0;
	vector<int> indexofLargestProbes; //holds the index values of the elements with largest number of probes
	vector<int> probeCountofEachIndex; //holds the number of probes in each index
		
	if (count == 0)
		return false;
	cout << "------------------------------------------" << endl;
	cout << "HashTable Statistics" << endl;
	cout << "------------------------------------------" << endl;
	cout << endl << "Collisions at: " << endl;
		
	/** Walking whole table and making stats*/
	for (i = 0; i < MAX; i++)
	{
		/** Prints to screen indexes which have collisions */
		/** Tracks probe count of each index */
		if (table[i].size() != 0 && table[i].size() > 1)
		{
			cout << "	Index: " << i << " Collisions: " << table[i].size() - 1 << endl;
			probeCountofEachIndex.push_back(table[i].size() - 1);
		}
		/** Determines how many indexes are occupied */
		if (table[i].size() != 0)
			occupiedIndexes++;
		/** Determines the largest amount of collisions found in HT */
		if ((table[i].size()) > largestProbes)
			largestProbes = table[i].size();
		/** Tracks all indexes with no collisions */
		if (table[i].size() != 0 && table[i].size() == 1)
			noProbes++;
	}
	///** Stores indexes equal to the greatest number of probes in vector for later printing */
	//for( i = 0; i < MAX; i++ )
	//{
	// if( (table[i].size()-1) == largestProbes )
	// indexofLargestProbes.push_back(i);
	//}
	/** Calculates average amount of probes */
	for (size_t s = 0; s < probeCountofEachIndex.size(); s++)
	{
		averageProbes =+ (float)probeCountofEachIndex[s];
		averageProbes /= occupiedIndexes;
	}
	cout << endl << "Size of table is " << MAX << endl;
	cout << "There are currently " << count << " items." << endl;
	cout << "Number of the occupied indexes: " << occupiedIndexes << endl;
	loadFactor = (occupiedIndexes / MAX) * 100;
	cout << "Load factor: " << loadFactor << "%";
	cout << endl << "Average amount of collisions: " << averageProbes;
	cout << endl << "Number of indexes with no collisions: " << noProbes;
	cout << endl << "Number of indexes with collisions: " << occupiedIndexes - noProbes;
	cout << endl << "Largest bucket size is " << largestProbes << endl << endl;
	//cout << endl <<"Max number of probes is " << largestProbes << ", at index locations:" < <endl <<endl;
	///** Prints indexes that have largest amount of Probes */
	//for( i = 0; i < indexofLargestProbes.size(); i++ )
	//{
	// cout<<"index "<< indexofLargestProbes[i] <<": ";
	// table[indexofLargestProbes[i]].display();
	//}
	return true;
}

template<class KeyType, class ItemType>
int HashTable<KeyType,ItemType>::hashingFunction(const KeyType key)
{
	unsigned index = 0;
	for (unsigned int i = 0; i < key.size(); i++)
	{
		index = 33 * index ^ key[i];
	}
	while (index>MAX - 1)
		index = index % MAX;
	return index;
}

template<class KeyType, class ItemType>
bool HashTable<KeyType,ItemType>::print() const
{
	if(count == 0)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < MAX; i++)
		{	
			cout << "Index #:";
			cout << i << endl;
			cout << "-----------------" << endl;
			if(!table[i].isEmpty())
			{
				table[i].display();
			}
			cout << endl;
		}
	}
	return true;
}
