#ifndef _HASHED_ENTRY
#define _HASHED_ENTRY

#include "Entry.h"

template<class KeyType, class ItemType>
class HashedEntry : public Entry < KeyType, ItemType >
{
private:
	//data
	HashedEntry<KeyType, ItemType>* nextPtr;

public:
		
	//constructors
	HashedEntry();
	HashedEntry(ItemType newEntry, KeyType searchKey);
	HashedEntry(ItemType newEntry, KeyType searchKey, HashedEntry<KeyType, ItemType>* nextEntryPtr);

	//methods
	void setNext(HashedEntry<KeyType, ItemType>* nextEntryPtr);
	HashedEntry<KeyType, ItemType>* getNext() const;
};

#endif