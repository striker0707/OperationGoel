/** @file Entry.cpp */

#include "Entry.h"
#include "Entry.cpp"
#include "HashedEntry.h"

//--------------------------------------------------------------------
//          public methods
//--------------------------------------------------------------------

//--------------------------------------------------------------------
//Constructor and Destructor Section.
//--------------------------------------------------------------------

template <class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry()
{
	nextPtr = nullptr;

}// end of default constructor

template <class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(ItemType newEntry, KeyType newKey)
{
	item = newEntry;
	setKey(newKey);
	nextPtr = nullptr;

}// end of constructor

template <class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(ItemType newEntry, KeyType newKey, HashedEntry<KeyType, ItemType>* nextEntryPtr)
{
	item = newEntry;
	setKey(newKey);
	nextPtr = nextEntryPtr;

}// end of constructor



//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
template <class KeyType, class ItemType>
void HashedEntry<KeyType, ItemType>::setNext(HashedEntry<KeyType, ItemType>* nextEntryPtr)
{
	nextPtr = nextEntryPtr;
}// end of setNext

template <class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>* HashedEntry<KeyType, ItemType>::getNext() const
{
	return nextPtr;
}// end of setNext