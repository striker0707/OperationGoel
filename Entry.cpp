/** @file Entry.cpp */
#include "Entry.h"


//--------------------------------------------------------------------
//          protected methods
//--------------------------------------------------------------------

template <class KeyType, class ItemType>
void Entry<KeyType, ItemType>::setKey(const KeyType& newKey)
{
	searchKey = newKey;
}

//--------------------------------------------------------------------
//          public methods
//--------------------------------------------------------------------

//--------------------------------------------------------------------
//Constructor and Destructor Section.
//--------------------------------------------------------------------


template <class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry()
{
	
}// end of default constructor

template <class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry(ItemType newEntry, KeyType newKey)
{
	item = newEntry;
	setKey(newKey);
}


//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------


template <class KeyType, class ItemType>
ItemType Entry<KeyType, ItemType>::getItem() const
{
	return item;
}// end of getItem


template <class KeyType, class ItemType>
KeyType Entry<KeyType, ItemType>::getKey() const
{
	return searchKey;
}// end of getKey


template <class KeyType, class ItemType>
void Entry<KeyType, ItemType>::setItem(const ItemType& newEntry)
{
	item = newEntry;
}// end of setItem

//------------------------------------------------------------
// Operator overload section
//------------------------------------------------------------

template <class KeyType, class ItemType> 
bool Entry <KeyType, ItemType>::operator==(const Entry<KeyType, ItemType>& rightHandItem) const
{
	if (item == rightHandItem.getItem() || searchKey = rightHandItem.getSearchKey)
	{
		return true;
	}
	else
		return false;
	
} //end of operator==

template <class KeyType, class ItemType> 
bool Entry <KeyType, ItemType>::operator>(const Entry<KeyType, ItemType>& rightHandItem) const
{
	if (item > rightHandItem.getItem())
	{
		return true;
	}
	else
		return false;
	
} //end of operator==