/** A class of nodes for a link-based binary tree.
@file BinaryNode.h */
#ifndef _BINARY_NODE
#define _BINARY_NODE


template<class ItemType> 
class BinaryNode
{
private:
	//data members
	ItemType item;	// Data portion
	BinaryNode<ItemType> *leftChildPtr;	// Pointer to left child
	BinaryNode<ItemType> *rightChildPtr;	// Pointer to right child
public:
	//constructors
	BinaryNode();
	BinaryNode(const ItemType & anItem);
	BinaryNode(const ItemType & anItem, BinaryNode < ItemType > *leftPtr, BinaryNode < ItemType > *rightPtr);

	//member functions
	void setItem(const ItemType & anItem);
	ItemType getItem() const;
	bool isLeaf() const;
	BinaryNode<ItemType> *getLeftChildPtr()const;
	BinaryNode<ItemType> *getRightChildPtr()const;
	void setLeftChildPtr(BinaryNode<ItemType> *leftPtr);
	void setRightChildPtr(BinaryNode<ItemType> *rightPtr);

};  

#endif
