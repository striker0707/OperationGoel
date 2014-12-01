// Binary tree abstract base class
 
#ifndef _BINARY_TREE
#define _BINARY_TREE

#include <queue>
#include "BinaryNode.h"
#include "Food.h"

using namespace std;

template<class ItemType>
class BinaryTree
{
protected:
	BinaryNode<ItemType>* rootPtr;		// ptr to root node
	int count;							// number of nodes in tree

public:
	// "admin" functions
 	BinaryTree();
	BinaryTree(const BinaryTree<ItemType> & tree);
	virtual ~BinaryTree();
	BinaryTree & operator=(const BinaryTree & sourceTree);
   
	// common functions for all binary trees
 	bool isEmpty() const;
	int size() const;
	void clear();
	void preOrder(void visit(ItemType &)) const;
	void inOrder(void visit(ItemType &)) const;
	void postOrder(void visit(ItemType &)) const;
	void breadthfirst(void visit(ItemType&)) const;
	void printToFile(ofstream& outFile, void visit(stringstream&, Food&)) const;

	// abstract functions to be implemented by derived class
	virtual bool insert(const ItemType & newEntry, BinaryNode<ItemType>* nodePtr) = 0; 
	virtual void remove( ItemType target) = 0;
	virtual bool getEntry(const ItemType & anEntry, ItemType & returnedItem) const = 0;

private:   
	// delete all nodes from the tree
	void destroyTree(BinaryNode<ItemType>* nodePtr);

	// copy from the tree rooted at nodePtr and returns a pointer to the copy
	BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* nodePtr);

	// internal traverse
	void _preorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
	void _inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
	void _postorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
	void _printToFile(ofstream& outFile, void visit(stringstream&, Food&),BinaryNode<ItemType>* nodePtr) const;
}; 

template<class ItemType>
BinaryTree<ItemType>::BinaryTree()						
{
	rootPtr = 0; 
	count = 0;
}

template<class ItemType>
BinaryTree<ItemType>::BinaryTree(const BinaryTree<ItemType> & tree)	
{ 
	rootPtr = copyTree(tree.rootPtr); 
	count = tree.count;
}

template<class ItemType>
BinaryTree<ItemType>::~BinaryTree()
{
	destroyTree(rootPtr);
}

template<class ItemType>
bool BinaryTree<ItemType>::isEmpty() const
{
	return count == 0;
}

template<class ItemType>
int BinaryTree<ItemType>::size() const					
{
	return count;
}

template<class ItemType>
void BinaryTree<ItemType>::clear()						
{
	destroyTree(rootPtr); 
	rootPtr = 0; 
	count = 0;
}

template<class ItemType>
void BinaryTree<ItemType>::preOrder(void visit(ItemType &)) const		
{
	_preorder(visit, rootPtr);
}

template<class ItemType>
void BinaryTree<ItemType>::inOrder(void visit(ItemType &)) const		
{
	_inorder(visit, rootPtr);
}

template<class ItemType>
void BinaryTree<ItemType>::postOrder(void visit(ItemType &)) const	
{
	_postorder(visit, rootPtr);
}

template<class ItemType>
BinaryTree<ItemType> & BinaryTree<ItemType>::operator=(const BinaryTree<ItemType> & sourceTree)
{
	rootPtr = copyTree(sourceTree.rootPtr);
	count = sourceTree.count;

	return *this;
}

template<class ItemType>
void BinaryTree<ItemType>::destroyTree(BinaryNode<ItemType>* nodePtr)
{
	if(nodePtr != 0)
	{
		destroyTree(nodePtr->getLeftPtr());
		destroyTree(nodePtr->getRightPtr());
		delete nodePtr;
	}
} 

template<class ItemType>
BinaryNode<ItemType>* BinaryTree<ItemType>::copyTree(const BinaryNode<ItemType>* nodePtr) 
{
	BinaryNode<ItemType>* newNodePtr = 0;

	if(nodePtr == 0)
		newNodePtr = 0;
	else
	{
		newNodePtr = new BinaryNode<ItemType>(nodePtr->getItem());
		newNodePtr->setLeftPtr(copyTree(nodePtr->getLeftPtr()));
		newNodePtr->setRightPtr(copyTree(nodePtr->getRightPtr()));
	}

	return newNodePtr;
}

template<class ItemType>
void BinaryTree<ItemType>::_preorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
	if (nodePtr != 0)
	{
		ItemType item = nodePtr->getItem();
		visit(item);
		_preorder(visit, nodePtr->getLeftPtr());
		_preorder(visit, nodePtr->getRightPtr());
	}
}  

template<class ItemType>
void BinaryTree<ItemType>::_inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
	if (nodePtr != 0)
	{
		_inorder(visit, nodePtr->getLeftPtr());
		ItemType item = nodePtr->getItem();
		if(*item != *rootPtr->getItem())
		{
			visit(item);
		}
		_inorder(visit, nodePtr->getRightPtr());
	}
}  

template<class ItemType>
void BinaryTree<ItemType>::_postorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
	if (nodePtr != 0)
	{
		_postorder(visit, nodePtr->getLeftPtr());
		_postorder(visit, nodePtr->getRightPtr());
		ItemType item = nodePtr->getItem();
		visit(item);
		
	}
}  
 
template<class ItemType>
void BinaryTree<ItemType>::breadthfirst(void visit(ItemType&)) const
{

	queue<BinaryNode<ItemType>*> q;

	if(rootPtr != 0)
		q.push(rootPtr);
	
	while (!q.empty())
	{
		ItemType item = q.front()->getItem();
		
		if(*item != *rootPtr->getItem())
		{
			visit(item);
		}

		if(q.front()->getLeftPtr() != 0)
			q.push(q.front()->getLeftPtr());
		if(q.front()->getRightPtr() != 0)
			q.push(q.front()->getRightPtr());
		q.pop();
	}
}

template<class ItemType>
void BinaryTree<ItemType>::printToFile(ofstream& outFile, void visit(stringstream&, Food&)) const
{
	_printToFile(outFile, visit, rootPtr);
} 

template<class ItemType>
void BinaryTree<ItemType>::_printToFile(ofstream& outFile, void visit(stringstream&, Food&),BinaryNode<ItemType>* nodePtr) const
{
	string buffer;

	if (nodePtr != 0)
	{
		ItemType item = nodePtr->getItem();
		if(*item != *rootPtr->getItem())
		{
			stringstream ss;
			visit(ss, *item);
			getline(ss,buffer);
			outFile << buffer << endl;
		}
		_printToFile(outFile, visit, nodePtr->getLeftPtr());
		_printToFile(outFile, visit, nodePtr->getRightPtr());
	}

} 

#endif

