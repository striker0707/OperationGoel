// Linked List abstract base class

#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "Node.h"

template<class ItemType>
class LinkedList 
{
protected:
   Node<ItemType>* headPtr; // Pointer to first node in the list
   int itemCount;           // Current count of list items 
   
public:
	// constructor
	LinkedList();
	// copy constructor
	LinkedList(const LinkedList<ItemType>& aList);
	// destructor
	virtual ~LinkedList();
	// check for empty list
	bool isEmpty() const;
	// get number of entries in the list
	int size() const;
	// remove all entries from list
	void clear();
	// display list from front to end
	void display() const;
	// abstract insert function
	virtual bool insert(const ItemType& newEntry, int newPosition = 1) = 0;
}; 

#endif 
