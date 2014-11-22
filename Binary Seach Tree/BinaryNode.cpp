/** @file BinaryNode.cpp */
#include "BinaryNode.h"

//--------------------------------------------------------------------
//          constructors
//--------------------------------------------------------------------

//default constructor
template<class ItemType>
BinaryNode<ItemType>::BinaryNode()
{
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;

}//end of default constructor

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType & anItem)
{
	item = anItem;
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;

}// end of constructor

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType & anItem, BinaryNode < ItemType > *leftPtr, BinaryNode < ItemType > *rightPtr)
{
	item = anItem;
	leftChildPtr = leftPtr;
	rightChildPtr = rightPtr;
}// end of constructor

//--------------------------------------------------------------------
//          member functions
//--------------------------------------------------------------------

//setItem
template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType & anItem)
{
	item = anItem;

} // end of setItem


//getItem
template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
	return item;

} // end of getItem


//isLeaf
template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
	if (leftChildPtr == nullptr && rightChildPtr == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}

}//end of isLeaf


//getLeftChildPtr
template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const
{
	return leftChildPtr;

}//end of getLeftChildPtr


//getRightChildPtr
template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const
{
	return rightChildPtr;

}//end of getrightChildPtr



//setLeftChildPtr
template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType> *leftPtr)
{
	leftChildPtr = leftPtr;

}//end of setLeftChildPtr


//setRightChildPtr
template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType> *rightPtr)
{
	rightChildPtr = rightPtr;

}//end of setRightChildPtr
