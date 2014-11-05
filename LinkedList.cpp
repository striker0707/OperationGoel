#include "LinkedList.h"

template<class ItemType>
LinkedList<ItemType>::LinkedList()
{
	headPtr = 0; 
	itemCount = 0; 
}

template<class ItemType>
virtual LinkedList<ItemType>::~LinkedList()	
{ 
	clear(); 
}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
{
	itemCount = aList.itemCount;
	Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original list

	if (origChainPtr == 0)
		headPtr = 0;  // Original list is empty
	else
	{
		headPtr = new Node<ItemType>();		// copy first node
		headPtr->setItem(origChainPtr->getItem());

		// Copy remaining nodes
		Node<ItemType>* newChainPtr = headPtr;
		origChainPtr = origChainPtr->getNext();
		while (origChainPtr != 0)
		{
			ItemType nextItem = origChainPtr->getItem();
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			newChainPtr->setNext(newNodePtr);
			newChainPtr = newChainPtr->getNext();
			origChainPtr = origChainPtr->getNext();
		}
		newChainPtr->setNext(0);              // Flag end of list
	}
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{ 
	return itemCount == 0; 
}

template<class ItemType>
void LinkedList<ItemType>::display() const
{
	Node<ItemType>* currPtr = headPtr;		// start at front of list
	while (currPtr != 0)					// walk until end of list
	{
		cout << currPtr->getItem() << " ";	// display data
		currPtr = currPtr->getNext();		// go to next node
	}
	cout << endl << endl;
}

template<class ItemType>
int LinkedList<ItemType>::size() const
{ 
	return itemCount; 
}

template<class ItemType>
void LinkedList<ItemType>::clear()
{
	Node<ItemType> * deletePtr;
	for (int i = 1; i < itemCount; i++) // walk each node
	{
		deletePtr = headPtr;			// remove each node
		headPtr = headPtr->getNext();
		delete deletePtr;
	}
	itemCount = 0;
}
