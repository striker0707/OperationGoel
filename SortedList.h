/** Sorted Linked list ADT
  *	Created by Group 3: Elton Vinh, Gordon Wang, Joanne Trinh, Ethan Huang, Loc Giang, Shyanaka Ramachandra
  * Manish Goel
  * CIS 22C
  */

#ifndef _SORTED_LIST
#define _SORTED_LIST

#include "LinkedList.h"

template<class ItemType>
class SortedList : public LinkedList<ItemType>
{
public:
	// Inserts an entry in the correct sorted order, position is ignored
	bool insert(const ItemType& newEntry, int newPosition = 1);
	// Removes an entry
	bool remove(const ItemType& anEntry);
	// Returns true for found, false for not found anEntry
	bool getEntry( ItemType & target, ItemType & returnedEntry) const;
}; 

template<class ItemType>
bool SortedList<ItemType>::insert(const ItemType& newEntry, int newPosition)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
	Node<ItemType>* currentPtr = headPtr;
	Node<ItemType>* prev = 0;

	if(itemCount == 0 || headPtr == 0 || isEmpty()) 
	//inserts if empty list
	{
		newNodePtr->setNext(headPtr);
		headPtr = newNodePtr;
		itemCount++;
		return true;
	}

	while(currentPtr != 0 && *currentPtr->getItem() < *newNodePtr->getItem()) 
	//walks through list till the end or where data needs to be added, pointers get set to prepare for data insertion
	{
		prev = currentPtr;
		currentPtr = currentPtr->getNext();
	}
		
	if(currentPtr != 0 )
	//if not inserting at the end of the list insert accordingly
	{
		newNodePtr->setNext(currentPtr);
		if( prev != 0)
		//if not at the beginning of the list
			prev->setNext(newNodePtr);
		else
		//else the new data is the head
			headPtr = newNodePtr;


	}
	else
	{
	//if inserting at the end of the list
		prev->setNext(newNodePtr);
		newNodePtr->setNext(0);
	}

	itemCount++;
	return true;
}

template<class ItemType>
bool SortedList<ItemType>::remove(const ItemType& anEntry)
{
	bool found = false;

	Node<ItemType>* currentPtr = headPtr;
	Node<ItemType>* prev = 0;
	Node<ItemType>* ptrToDelete = 0;

	while( currentPtr != 0 )
	{

		const ItemType item = currentPtr->getItem();
		if( *item == *anEntry)
		{
			ptrToDelete = currentPtr;
			if( prev != 0 )
				prev->setNext(currentPtr->getNext());
			else
				headPtr = currentPtr->getNext();
			found = true;
			itemCount--;

			delete ptrToDelete;
			return found;
		}
		prev = currentPtr;	
		currentPtr = currentPtr->getNext();
	}
	return found;
}  

template<class ItemType>
bool SortedList<ItemType>::getEntry( ItemType& target, ItemType& returnedEntry) const
{
	bool found = false;

	Node<ItemType>* currentPtr = headPtr;
	while(currentPtr != 0 && found == false)
	// walk list
	{
		if( *currentPtr->getItem() == *target )
		//need to overload "==" operator
		{
			*returnedEntry = *currentPtr->getItem();
			found = true;
		}
		currentPtr = currentPtr->getNext();
	}
	return found;
}

#endif 
