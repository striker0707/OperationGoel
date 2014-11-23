/** @file BinarySearchTree.cpp */
#include "BinarySearchTree.h"
#include "BinaryTreeInterface.h"
#include "BinaryNodeTree.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcep.h"
#include "NotFoundException.h"
#include <algorithm>

//--------------------------------------------------------------------
//          protected methods
//--------------------------------------------------------------------

template < class ItemType > BinaryNode <ItemType > * BinarySearchTree < ItemType >::insertInorder(BinaryNode < ItemType > *subTreePtr, BinaryNode < ItemType > *newNode)
{
	if (subTreePtr == nullptr)
	{
		return newNode;
	}
	else if (subTreePtr->getItem() > newNode->getItem())
	{
		BinaryNode< ItemType> *tempPtr;
		tempPtr = insertInorder(subTreePtr->getLeftChildPtr(), newNode);
		subTreePtr->setLeftChildPtr(tempPtr);
	}
	else
	{
		BinaryNode< ItemType> *tempPtr;
		tempPtr = insertInorder(subTreePtr->getRightChildPtr(), newNode);
		subTreePtr->setRightChildPtr(tempPtr);
	}

	return subTreePtr;
}


// removeValue
template < class ItemType > BinaryNode < ItemType > * BinarySearchTree < ItemType >::removeValue(BinaryNode < ItemType > *subTreePtr, const ItemType target, bool & success)
{
	if (subTreePtr == nullptr)
	{
		success = false;
		return nullptr;
	}
	else if (subTreePtr->getItem() == target)
	{
		subTreePtr = moveValuesUpTree(subTreePtr);
		success = true;
		return subTreePtr;
	}
	else if (subTreePtr->getItem() > target)
	{
		BinaryNode< ItemType>* tempPtr;
		tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
		subTreePtr->setLeftChildPtr(tempPtr);
		return subTreePtr;
	}
	else
	{
		BinaryNode< ItemType>* tempPtr;
		tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
		subTreePtr->setRightChildPtr(tempPtr);
		return subTreePtr;
	}
}


// removeNode
template < class ItemType > BinaryNode < ItemType > * BinarySearchTree < ItemType >::removeNode(BinaryNode < ItemType > *nodePtr)
{
	if (nodePtr->lefChildPtr == nullptr && nodePtr->rightChildPtr == nullptr)
	{
		delete nodePtr;
		nodePtr = nullptr;
		return nodePtr;
	}
	else if (nodePtr->leftChildPtr == nullptr || nodePtr->rightChildPtr == nullptr)
	{
		//declare new BinaryNode
		BinaryNode < ItemType > nodeToConnectPtr();

		if (nodePtr->rightChildPtr == nullptr)
		{
			nodeToConnectPtr = nodePtr->getLeftChildPtr();
		}
		else
		{
			nodeToConnectPtr = nodeePtr->getRightChildPtr();
		}

		delete nodePtr;
		nodePtr = nullptr;
		return nodeToConnectPtr;
	}
	else
	{
		//declare temporary Binary Node
		BinaryNode< ItemType> tempPtr();
		ItemType newNodeValue;

		tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue);
		nodePtr->setRightChildPtr(tempPtr);
		nodePtr->setItem(newNodeValue);
		return nodePtr;
	}
}


// removeLeftmostNode
template < class ItemType > BinaryNode < ItemType > * BinarySearchTree < ItemType >::removeLeftmostNode(BinaryNode < ItemType > *nodePtr, ItemType& inorderSuccessor)
{
	if (nodePtr->getLeftChildPtr() == nullptr)
	{
		inorderSuccessor = nodePtr->getItem();
		return moveValuesUpTree(nodePtr);
	}
	else
	{
		return removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor);
	}

}// end of removeLeftmostNode



// findNode
template < class ItemType > BinaryNode < ItemType >  *BinarySearchTree < ItemType >::findNode(BinaryNode < ItemType > *treePtr, const ItemType & target, bool & success) const
{
	if (treePtr == nullptr)
	{
		success = false;
		return nullptr;
	}
	else if (treePtr->getItem() == target)
	{
		success = true;
		return treePtr;
	}
	else if (treePtr->getItem() > target)
	{
		return findNode(treePtr->getLeftChildPtr(), target, success);
	}
	else
	{
		return findNode(treePtr->getRightChildPtr(), target, success);
	}

}// end of findNode

//--------------------------------------------------------------------
//          public methods
//--------------------------------------------------------------------

//--------------------------------------------------------------------
//Constructor and Destructor Section.
//--------------------------------------------------------------------

template < class ItemType > BinarySearchTree < ItemType >::BinarySearchTree()
{
	rootPtr = nullptr;

}   // end default constructor

template < class ItemType > BinarySearchTree < ItemType >::BinarySearchTree(const ItemType & rootItem)
{
	rootPtr = new BinaryNode < ItemType >(rootItem, nullptr, nullptr);

}   // end constructor


// Copy Constructor
template < class ItemType > BinarySearchTree < ItemType >::BinarySearchTree(const BinarySearchTree < ItemType > &treePtr)
{
	rootPtr = copyTree(treePtr.rootPtr);

}   // end copy constructor


template < class ItemType > BinarySearchTree < ItemType >::~BinarySearchTree()
{
	destroyTree(rootPtr);

} // end of destructor

//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------

// isEmpty
template < class ItemType > bool BinarySearchTree < ItemType >::isEmpty() const
{
	if (rootPtr == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}

} // end pf isEmpty

// getHeight
template < class ItemType > int BinarySearchTree < ItemType >::getHeight() const
{
	return getHeightHelper(rootPtr);

} // end of getHeight


// getNumberOfNodes
template < class ItemType > int BinarySearchTree < ItemType >::getNumberOfNodes() const
{
	return getNumberOfNodesHelper(rootPtr);

} // end of getHeight

// getRootData
template < class ItemType > ItemType BinarySearchTree < ItemType >::getRootData() const throw (PrecondViolatedExcep)
{
	if (rootPtr == nullptr)
	{
		throw PrecondViolatedExcep("Root Data not found");
	}
	else
		return rootPtr->getItem();
}


// setRootData
template < class ItemType > void BinarySearchTree < ItemType >::setRootData(const ItemType& newData) const throw (PrecondViolatedExcep)
{
	rootData = newData;

} // end of setRootData


//add
template < class ItemType > bool BinarySearchTree < ItemType >::add(const ItemType& newData)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
	rootPtr = insertInorder(rootPtr, newNodePtr);

	return true;

} // end of add


//remove
template < class ItemType > bool BinarySearchTree < ItemType >::remove(const ItemType& data)
{
	bool success;
	success = false;
	rootPtr = removeValue(rootPtr, data, success);
	return success;

} // end of remove


//clear
template < class ItemType > void BinarySearchTree < ItemType >::clear()
{
	destroyTree(rootPtr);

} // end of clear


//getEntry
template < class ItemType > ItemType BinarySearchTree < ItemType >::getEntry(const ItemType & anEntry) const throw (NotFoundException)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>();
	bool success;

	newNodePtr = findNode(rootPtr, anEntry, success);

	if (newNodePtr == nullptr)
	{
		throw NotFoundException("The entry not found on the Tree");
	}
	else
		return newNodePtr->getItem();

}


//contains
template < class ItemType > bool BinarySearchTree < ItemType >::contains(const ItemType & anEntry) const
{
	//BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);

	//rootPtr = insertInorder(rootPtr, newNodePtr);

	return true;
}



//------------------------------------------------------------
//   Public Traversals Section.
//------------------------------------------------------------


// preorderTraverse
template < class ItemType > void BinarySearchTree < ItemType >::preorderTraverse(void visit(ItemType &)) const
{
	preorder(visit, rootPtr);

}  //end of preorderTraverse


// inorderTraverse
template < class ItemType > void BinarySearchTree < ItemType >::inorderTraverse(void visit(ItemType &)) const
{
	inorder(visit, rootPtr);

}  //end of inorderTraverse


// postorderTraverse
template < class ItemType > void BinarySearchTree < ItemType >::postorderTraverse(void visit(ItemType &)) const
{
	postorder(visit, rootPtr);

}  //end of postorderTraverse

// postorderTraverse
template < class ItemType > void BinarySearchTree < ItemType >::levelorderTraverse(void visit(ItemType &)) const
{
	levelorder(visit, rootPtr);

}  //end of postorderTraverse


//------------------------------------------------------------
//   Overloaded Operator Section.
//------------------------------------------------------------

template < class ItemType > BinarySearchTree<ItemType> & BinarySearchTree < ItemType >::operator=(const BinarySearchTree & rightHandSide)
{
	if (this != &rightHandSide)
	{
		this->clear();
		rootPtr = copyTree(treePtr.rootPtr);
	}

	return *this;

} //end of operator=
