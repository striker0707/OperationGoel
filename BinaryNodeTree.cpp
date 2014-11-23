/** @file BinaryNodeTree.cpp */
#include "BinaryNodeTree.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcep.h"
#include "NotFoundException.h"
#include <algorithm>

using std::max;

//--------------------------------------------------------------------
//          protected methods
//--------------------------------------------------------------------

// getHeightHelper
template < class ItemType > int BinaryNodeTree < ItemType >::getHeightHelper(BinaryNode < ItemType > *subTreePtr) const 
{
	if (subTreePtr == nullptr)
		return 0;
	else
		return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));

}  // end of getHeightHelper


// getNumberOfNodesHelper
template < class ItemType > int BinaryNodeTree < ItemType >::getNumberOfNodesHelper(BinaryNode < ItemType > *subTreePtr) const 
{
	if (subTreePtr == nullptr)
		return 0;
	else
		return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());

} // end of getNumberOfNodesHelper


// destroyTree
template < class ItemType > void BinaryNodeTree < ItemType >::destroyTree(BinaryNode < ItemType > *subTreePtr)
{
	if (subTreePtr != nullptr)
	{
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
		delete subTreePtr;
	}	// end if

}   // end destroyTree


//  balancedAdd
template < class ItemType > BinaryNode < ItemType > *BinaryNodeTree < ItemType >::balancedAdd(BinaryNode < ItemType > *subTreePtr,
	BinaryNode < ItemType > *newNodePtr)
{
	if (subTreePtr == nullptr)
		return newNodePtr;
	else
	{
		BinaryNode < ItemType > *leftPtr = subTreePtr->getLeftChildPtr();
		BinaryNode < ItemType > *rightPtr = subTreePtr->getRightChildPtr();
		if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
		{
			rightPtr = balancedAdd(rightPtr, newNodePtr);
			subTreePtr->setRightChildPtr(rightPtr);
		}
		else
		{
			leftPtr = balancedAdd(leftPtr, newNodePtr);
			subTreePtr->setLeftChildPtr(leftPtr);
		}	// end if
		return subTreePtr;
	}	// end if

}   // end balancedAdd


// removeValue
template < class ItemType > BinaryNode < ItemType > *BinaryNodeTree < ItemType >::removeValue(BinaryNode < ItemType > *subTreePtr, const ItemType target, bool & success)
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

// movesValuesUpTree
template < class ItemType > BinaryNode < ItemType > *BinaryNodeTree < ItemType >::moveValuesUpTree(BinaryNode < ItemType > *subTreePtr)
{
	if (subTreePtr->getLeftChildPtr() == nullptr && subTreePtr->getRightChildPtr() == nullptr)
	{
		delete subTreePtr;
		subTreePtr = nullptr;
		return subTreePtr;
	}
	else if (subTreePtr->getLeftChildPtr() == nullptr || subTreePtr->getRightChildPtr() == nullptr)
	{	
		//declare new BinaryNode
		BinaryNode < ItemType >* nodeToConnectPtr;
		
		if (subTreePtr->getRightChildPtr() == nullptr)
		{
			nodeToConnectPtr = subTreePtr->getLeftChildPtr();
		}
		else
		{
			nodeToConnectPtr = subTreePtr->getRightChildPtr();
		}

		delete subTreePtr;
		subTreePtr = nullptr;
		return nodeToConnectPtr;
	}
	else
	{	
		//declare temporary Binary Node
		BinaryNode< ItemType>* tempPtr;
		ItemType newNodeValue;

		tempPtr = removeLeftmostNode(subTreePtr->getRightChildPtr(), newNodeValue);
		subTreePtr->setRightChildPtr(tempPtr);
		subTreePtr->setItem(newNodeValue);
		return subTreePtr;
	}

}// end of movesValuesUpTree


// removeLeftmostNode
template < class ItemType > BinaryNode < ItemType > *BinaryNodeTree < ItemType >::removeLeftmostNode(BinaryNode < ItemType > *nodePtr, ItemType& inorderSuccessor)
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
template < class ItemType > BinaryNode < ItemType >  *BinaryNodeTree < ItemType >::findNode(BinaryNode < ItemType > *treePtr, const ItemType & target, bool & success) const
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



// copyTree
template < class ItemType > BinaryNode < ItemType > *BinaryNodeTree < ItemType >::copyTree(const BinaryNode < ItemType >
	*treePtr) const 
{
	BinaryNode < ItemType > *newTreePtr = nullptr;
	// Copy tree nodes during a preorder traversal
	if (treePtr != nullptr)
	{
		// Copy node
		newTreePtr = new BinaryNode < ItemType >(treePtr->getItem(), nullptr, nullptr);
		newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
		newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
	}	// end if
	// Else tree is empty (newTreePtr is nullptr)
	return newTreePtr;
}   // end copyTree


//--------------------------------------------------------------------
// Recursive traversal Helper Methods
//--------------------------------------------------------------------

//levelorder
template < class ItemType > void BinaryNodeTree < ItemType >::levelorder(void visit(ItemType &),
	BinaryNode < ItemType > *treePtr) const 
{
	int h = getHeight();
	int i;
	for(i = 1; i <=h; i++)
	{
		givenLevel(visit, treePtr, i);
	}

	
}   // end levelorder

template < class ItemType > void BinaryNodeTree < ItemType >::givenLevel(void visit(ItemType &),
	BinaryNode < ItemType > *treePtr, int level) const 
{
	if (treePtr == nullptr)
	{
		return;
	}
	if (level == 1)
	{
		ItemType theItem = treePtr->getItem();
		visit(theItem);
	}
	else if (level > 1)
	{
		givenLevel(visit, treePtr->getLeftChildPtr(), level-1);
		givenLevel(visit, treePtr->getRightChildPtr(), level-1);
	}
}


// preorder
template < class ItemType > void BinaryNodeTree < ItemType >::preorder(void visit(ItemType &),
	BinaryNode < ItemType > *treePtr) const 
{
	if (treePtr != nullptr)
	{
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		preorder(visit, treePtr->getLeftChildPtr());
		preorder(visit, treePtr->getRightChildPtr());

	}	// end if
}   // end preorder


// inorder
template < class ItemType > void BinaryNodeTree < ItemType >::inorder(void visit(ItemType &),
	BinaryNode < ItemType > *treePtr) const 
{
	if (treePtr != nullptr)
	{
		inorder(visit, treePtr->getLeftChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		inorder(visit, treePtr->getRightChildPtr());

	}	// end if
}   // end inorder

// postorder
template < class ItemType > void BinaryNodeTree < ItemType >::postorder(void visit(ItemType &),
	BinaryNode < ItemType > *treePtr) const 
{
	if (treePtr != nullptr)
	{
		
		postorder(visit, treePtr->getLeftChildPtr());
		postorder(visit, treePtr->getRightChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		
		
	}	// end if
}   // end preorder


//--------------------------------------------------------------------
//          public methods
//--------------------------------------------------------------------

//--------------------------------------------------------------------
//Constructor and Destructor Section.
//--------------------------------------------------------------------

template < class ItemType > BinaryNodeTree < ItemType >::BinaryNodeTree() :rootPtr(nullptr)
{
}   // end default constructor

template < class ItemType > BinaryNodeTree < ItemType >::BinaryNodeTree(const ItemType & rootItem)
{
	rootPtr = new BinaryNode < ItemType >(rootItem, nullptr, nullptr);

}   // end constructor

template < class ItemType > BinaryNodeTree < ItemType >::BinaryNodeTree(const ItemType & rootItem,
	const BinaryNodeTree < ItemType > *leftTreePtr,
	const BinaryNodeTree < ItemType > *rightTreePtr)
{
	rootPtr = new BinaryNode < ItemType >(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr));

}   // end constructor

// Copy Constructor
template < class ItemType > BinaryNodeTree < ItemType >::BinaryNodeTree(const BinaryNodeTree < ItemType > &treePtr)
{
	rootPtr = copyTree(treePtr.rootPtr);

}   // end copy constructor


template < class ItemType > BinaryNodeTree < ItemType >::~BinaryNodeTree()
{
	destroyTree(rootPtr);

} // end of destructor


//--------------------------------------------------------------------
//   Public BinaryTreeInterface Methods Section.
//--------------------------------------------------------------------

// isEmpty
template < class ItemType > bool BinaryNodeTree < ItemType >::isEmpty() const
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
template < class ItemType > int BinaryNodeTree < ItemType >::getHeight() const 
{
	return getHeightHelper(rootPtr);

} // end of getHeight


// getNumberOfNodes
template < class ItemType > int BinaryNodeTree < ItemType >::getNumberOfNodes() const
{
	return getNumberOfNodesHelper(rootPtr);

} // end of getHeight

// getRootData
template < class ItemType > ItemType BinaryNodeTree < ItemType >::getRootData() const throw (PrecondViolatedExcep)
{
	if (rootPtr == nullptr)
	{
		throw PrecondViolatedExcep("Root Data not found");
	}
	else
		return rootPtr->getItem();
}


// setRootData
template < class ItemType > void BinaryNodeTree < ItemType >::setRootData(const ItemType& newData)
{
	*rootPtr = newData;

} // end of setRootData


//add
template < class ItemType > bool BinaryNodeTree < ItemType >::add(const ItemType& newData)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
	rootPtr = balancedAdd(rootPtr, newNodePtr);

	return true;

} // end of add


//remove
template < class ItemType > bool BinaryNodeTree < ItemType >::remove(const ItemType& data)
{
	bool success;
	success = false;
	rootPtr = removeValue(rootPtr, data, success);
	return success;

} // end of remove


//clear
template < class ItemType > void BinaryNodeTree < ItemType >::clear()
{
	destroyTree(rootPtr);

} // end of clear


//getEntry
template < class ItemType > ItemType BinaryNodeTree < ItemType >::getEntry(const ItemType & anEntry) const throw (NotFoundException)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>();
	bool success;

	newNodePtr = findNode(rootPtr,anEntry, success);
	
	if (newNodePtr == nullptr)
	{
		throw NotFoundException("The entry not found on the Tree");
	}
	else
		return newNodePtr->getItem();

}


//contains
template < class ItemType > bool BinaryNodeTree < ItemType >::contains(const ItemType & anEntry) const
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>();
	bool success;

	newNodePtr = findNode(rootPtr, anEntry, success);

	return success;
}


//------------------------------------------------------------
//   Public Traversals Section.
//------------------------------------------------------------

// preorderTraverse
template < class ItemType > void BinaryNodeTree < ItemType >::preorderTraverse(void visit(ItemType &)) const
{
	preorder(visit, rootPtr);
	
}  //end of preorderTraverse


// inorderTraverse
template < class ItemType > void BinaryNodeTree < ItemType >::inorderTraverse(void visit(ItemType &)) const
{
	inorder(visit, rootPtr);

}  //end of inorderTraverse


// postorderTraverse
template < class ItemType > void BinaryNodeTree < ItemType >::postorderTraverse(void visit(ItemType &)) const
{
	postorder(visit, rootPtr);

}  //end of postorderTraverse


//------------------------------------------------------------
//   Overloaded Operator Section.
//------------------------------------------------------------

template < class ItemType > BinaryNodeTree<ItemType> & BinaryNodeTree < ItemType >::operator=(const BinaryNodeTree & rightHandSide)
{
	/*
	if (this != &rightHandSide)
	{
		this->clear(); 
		rootPtr = copyTree(treePtr->rootPtr);
	}
	*/
	return *this;
	
} //end of operator=
