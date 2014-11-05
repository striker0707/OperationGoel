#ifndef _HASHED_ENTRY
#define _HASHED_ENTRY

#include "TableInterface.h"
#include "HashedEntry.h"

template <class KeyType, class ItemType>
class HashedEntry : public TableInterface < class KeyType, class ItemType >
{
private:

public:
	//constructors
	HashedEntry(); // default constructor
	

	//destructor
	virtual ~HashedEntry();
	
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