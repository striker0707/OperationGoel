/** ADT binary tree: Link-based implementation.
@file BinaryNodeTree.h */
#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
template < class ItemType>

class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
private :
	BinaryNode<ItemType>* rootPtr;
protected :
//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------
	int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const ;
	int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const ;
// Recursively deletes all nodes from the tree.
	void destroyTree(BinaryNode<ItemType>* subTreePtr);
// Recursively adds a new node to the tree in a left/right fashion to
// keep the tree balanced.
	BinaryNode<ItemType>* balancedAdd(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);
// Removes the target value from the tree by calling moveValuesUpTree
// to overwrite value with value from child.
	BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr,const ItemType target, bool& success);
// Copies values up the tree to overwrite value in current node until
// a leaf is reached; the leaf is then removed, since its value is
// stored in the parent.
	BinaryNode<ItemType>* moveValuesUpTree(BinaryNode<ItemType>* subTreePtr);
// Recursively searches for target value in the tree by using a
// preorder traversal.
	BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType& target, bool& success) const ;
// Copies the tree rooted at treePtr and returns a pointer to
// the copy.
	BinaryNode<ItemType>*
	copyTree( const BinaryNode<ItemType>* treePtr) const ;
// Recursive traversal helper methods:
	void preorder( void visit(ItemType&),
	BinaryNode<ItemType>* treePtr) const ;
	void inorder( void visit(ItemType&),
	BinaryNode<ItemType>* treePtr) const ;
	void postorder( void visit(ItemType&),
	BinaryNode<ItemType>* treePtr) const ;
public :
//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------
	BinaryNodeTree();
	BinaryNodeTree( const ItemType& rootItem);
	BinaryNodeTree( const ItemType& rootItem, const BinaryNodeTree<ItemType>* leftTreePtr, const BinaryNodeTree<ItemType>* rightTreePtr);
	BinaryNodeTree( const BinaryNodeTree<ItemType>& tree);
	virtual ~BinaryNodeTree();
//------------------------------------------------------------
// Public BinaryTreeInterface Methods Section.
//------------------------------------------------------------
	bool isEmpty() const ;
	int getHeight() const ;
	int getNumberOfNodes() const ;
	ItemType getRootData() const throw (PrecondViolatedExcep);
	void setRootData( const ItemType& newData);
	bool add( const ItemType& newData); // Adds a node
	bool remove( const ItemType& data); // Removes a node
	void clear();
	ItemType getEntry( const ItemType& anEntry) const
	throw (NotFoundException);
	bool contains( const ItemType& anEntry) const ;
//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
	void preorderTraverse( void visit(ItemType&)) const ;
	void inorderTraverse( void visit(ItemType&)) const ;
	void postorderTraverse( void visit(ItemType&)) const ;
//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
	BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);
}; // end BinaryNodeTree
#include "BinaryNodeTree.cpp"
#endif


template < class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr( nullptr )
{
} // end default constructor
template < class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree( const ItemType& rootItem)
{
	rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr );
} // end constructor
template < class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree( const ItemType& rootItem,
											const BinaryNodeTree<ItemType>* leftTreePtr,
													const BinaryNodeTree<ItemType>* rightTreePtr)
{
	rootPtr = new BinaryNode<ItemType>(rootItem,
	copyTree(leftTreePtr->rootPtr),
	copyTree(rightTreePtr->rootPtr));
} // end constructor


template < class ItemType> 
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const
{
	BinaryNode<ItemType>* newTreePtr = nullptr ;
	// Copy tree nodes during a preorder traversal
	if (treePtr != nullptr )
	{
		// Copy node
		newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(),nullptr, nullptr );
		{
			newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
			newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
		}
	} // end if
	// Else tree is empty (newTreePtr is nullptr)
	return newTreePtr;
} // end copyTree

//copy Constructor
template < class ItemType>BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr)
{
	rootPtr = copyTree(treePtr.rootPtr);
} // end copy constructor
//destroyTree
template < class ItemType>
void BinaryNodeTree<ItemType>::
destroyTree(BinaryNode<ItemType>* subTreePtr)
{
	if (subTreePtr != nullptr )
	{
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
		delete subTreePtr;
	} // end if
} // end destroyTree

//getHeightHelper
template < class ItemType>
int BinaryNodeTree<ItemType>::
getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
{
	if (subTreePtr == nullptr )
		return 0;
	else
		return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
	getHeightHelper(subTreePtr->getRightChildPtr()));
} // end getHeightHelper


//add
template < class ItemType>bool BinaryNodeTree<ItemType>::add( const ItemType& newData)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
	rootPtr = balancedAdd(rootPtr, newNodePtr);
return true ;
} // end add

//ballanceAdd
template < class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType> :: balancedAdd(BinaryNode<ItemType>* subTreePtr,BinaryNode<ItemType>* newNodePtr)
{
	if (subTreePtr == nullptr )
	{
		return newNodePtr;
	}
	else
	{
		BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
		BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();
		if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
		{
			rightPtr = balancedAdd(rightPtr, newNodePtr);
			subTreePtr->setRightChildPtr(rightPtr);
		}
		else
		{
			leftPtr = balancedAdd(leftPtr, newNodePtr);
			subTreePtr->setLeftChildPtr(leftPtr);
		} // end if
		return subTreePtr;
		
	} // end if
} // end balancedAdd

//inorder
template < class ItemType>void BinaryNodeTree<ItemType>::inorder( void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr )
	{
		inorder(visit, treePtr->getLeftChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		inorder(visit, treePtr->getRightChildPtr());
	} // end if
} // end inorder
