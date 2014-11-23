/** ADT binary tree: Link-based implementation.
@file BinaryNodeTree.h */
#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcep.h"
#include "NotFoundException.h"
template < class ItemType > 
class BinaryNodeTree : public BinaryTreeInterface <ItemType>
{
private:
	BinaryNode < ItemType > *rootPtr;
protected:
	//------------------------------------------------------------
	// Protected Utility Methods Section:
	// Recursive helper methods for the public methods.
	//------------------------------------------------------------
	int getHeightHelper(BinaryNode < ItemType > *subTreePtr) const;
	int getNumberOfNodesHelper(BinaryNode < ItemType > *subTreePtr) const;

	// Recursively deletes all nodes from the tree.
	void destroyTree(BinaryNode < ItemType > *subTreePtr);

	// Recursively adds a new node to the tree in a left/right fashion to
	// keep the tree balanced.
	BinaryNode < ItemType > *balancedAdd(BinaryNode < ItemType > *subTreePtr, BinaryNode < ItemType > *newNodePtr);

	// Removes the target value from the tree by calling moveValuesUpTree
	// to overwrite value with value from child.
	BinaryNode < ItemType > *removeValue(BinaryNode < ItemType > *subTreePtr, const ItemType target, bool & success);

	// Copies values up the tree to overwrite value in current node until
	// a leaf is reached; the leaf is then removed, since its value is
	// stored in the parent.
	BinaryNode < ItemType > *moveValuesUpTree(BinaryNode < ItemType > *subTreePtr);

	// Finds the leftmost node
	// 
	BinaryNode < ItemType > *removeLeftmostNode(BinaryNode < ItemType > *nodePtr, ItemType& inorderSuccessor);

	// Recursively searches for target value in the tree by using a
	// preorder traversal.
	BinaryNode < ItemType > *findNode(BinaryNode < ItemType > *treePtr, const ItemType & target, bool & success) const;

	// Copies the tree rooted at treePtr and returns a pointer to
	// the copy.
	BinaryNode < ItemType > *copyTree(const BinaryNode < ItemType > *treePtr) const;

	// Recursive traversal helper methods:
	void levelorder(void visit(ItemType &), BinaryNode < ItemType > *treePtr) const;
	void givenLevel(void visit(ItemType &), BinaryNode < ItemType > *treePtr, int level) const;
	void preorder(void visit(ItemType &), BinaryNode < ItemType > *treePtr) const;
	void inorder(void visit(ItemType &), BinaryNode < ItemType > *treePtr) const;
	void postorder(void visit(ItemType &), BinaryNode < ItemType > *treePtr) const;

public:
	//------------------------------------------------------------
	// Constructor and Destructor Section.
	//------------------------------------------------------------
	BinaryNodeTree();
	BinaryNodeTree(const ItemType & rootItem);
	BinaryNodeTree(const ItemType & rootItem, const BinaryNodeTree < ItemType > *leftTreePtr,
		const BinaryNodeTree < ItemType > *rightTreePtr);
	BinaryNodeTree(const BinaryNodeTree < ItemType > &tree);
	virtual ~BinaryNodeTree();
	//------------------------------------------------------------
	// Public BinaryTreeInterface Methods Section.
	//------------------------------------------------------------
	virtual bool isEmpty() const;
	virtual int getHeight() const;
	virtual int getNumberOfNodes() const;
	virtual ItemType getRootData() const throw (PrecondViolatedExcep);
	virtual void setRootData(const ItemType & newData);
	virtual bool add(const ItemType & newData);	// Adds a node
	virtual bool remove(const ItemType & data);	// Removes a node
	virtual void clear();
	virtual ItemType getEntry(const ItemType & anEntry) const throw (NotFoundException);
	virtual bool contains(const ItemType & anEntry) const;
	//------------------------------------------------------------
	// Public Traversals Section.
	//------------------------------------------------------------
	virtual void preorderTraverse(void visit(ItemType &)) const;
	virtual void inorderTraverse(void visit(ItemType &)) const;
	virtual void postorderTraverse(void visit(ItemType &)) const;
	//------------------------------------------------------------
	// Overloaded Operator Section.
	//------------------------------------------------------------
	virtual BinaryNodeTree & operator= (const BinaryNodeTree & rightHandSide);
};  // end BinaryNodeTree

#endif
