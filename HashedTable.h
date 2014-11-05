#ifndef _HASHED_ENTRY
#define _HASHED_ENTRY

#include "TableInterface.h"
#include "HashedEntry.h"

template <class KeyType, class ItemType>
class HashedTable : public TableInterface < class KeyType, class ItemType >
{
private:
	static const int DEFAULT_SIZE = 101;
	HashedEntry<KeyType, ItemType>** hashTable;
	int itemCount;
	int hashTableSize;
	

public:
	//constructors
	HashedTable(); // default constructor

	//copy constructor
	HashedTable(const HashedTable<KeyType, ItemType>& table);
	
	//destructor
	virtual ~HashedTable();
	
	//methods
	bool isEmpty(); 
	int getNumberOfItems() const;
	bool add(const KeyType& searchKey, const ItemType& newItem);
	bool remove(const KeyType& searchKey);
	void clear();
	ItemType getItem(const KeyType& searchKey) const;
	bool contains(const KeyType& searchKey) const;
	void traverse(void visit(ItemType&)) const;

};
#endif