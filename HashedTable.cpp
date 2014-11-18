/** @file HashedTable.cpp */

#include "TableInterface.h"
#include "HashedEntry.h"
#include "HashedEntry.cpp"
#include "HashedTable.h"

//--------------------------------------------------------------------
//          public methods
//--------------------------------------------------------------------

//--------------------------------------------------------------------
//Constructor and Destructor Section.
//--------------------------------------------------------------------


template < class KeyType, class ItemType > 
HashedTable< KeyType, ItemType>::HashedTable()
{
	itemCount = 0;
	hashTableSize = 0;
	hashTable = nullptr;

}// end of default constructor

template <class KeyType, class ItemType>
HashedTable<KeyType, ItemType>::~HashedTable()
{
	
}



//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------

template <class KeyType, class ItemType>
bool HashedTable<KeyType, ItemType>::isEmpty() const
{
	return true;
	
}// end of isEmpty


template <class KeyType, class ItemType>
int HashedTable<KeyType, ItemType>::getNumberOfItems() const
{
	return itemCount;

}// end of getNumberOfItems


template <class KeyType, class ItemType>
bool HashedTable<KeyType, ItemType>::add(const KeyType& searchKey, const ItemType& newItem)
{
	//create entry to add to dictionary
	HashedEntry<KeyType, ItemType>* entryToAddPtr = 
		new HashedEntry<KeyType, ItemType>(newItem, searchKey);

	return true;
	
}// end of add


template <class KeyType, class ItemType>
bool HashedTable<KeyType, ItemType>::remove(const KeyType& searchKey)
{
	return true;
	
}// end of remove


template <class KeyType, class ItemType>
void HashedTable<KeyType, ItemType>::clear()
{
	
	
}// end of clear

template <class KeyType, class ItemType>
ItemType HashedTable<KeyType, ItemType>::getItem(const KeyType& searchKey) const
{
	return searchKey;

}// end of getItem

template <class KeyType, class ItemType>
bool HashedTable<KeyType, ItemType>::contains(const KeyType& searchKey) const
{
	return true;
	
}// end of contains

template <class KeyType, class ItemType>
void HashedTable<KeyType, ItemType>::traverse(void visit(ItemType&)) const
{
	
	
}// end of traverse