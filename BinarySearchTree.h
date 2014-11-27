// Binary Search Tree ADT

#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include <string>
#include "BinaryTree.h"

using namespace std;

template<class ItemType>
class BinarySearchTree : public BinaryTree<ItemType>
{   
private:
	// internal insert node: insert newNode in nodePtr subtree
	BinaryNode<ItemType>* _insert(BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>* newNode);
   
	// internal remove node: locate and delete target node under nodePtr subtree
	BinaryNode<ItemType>* _remove(BinaryNode<ItemType>* nodePtr, const ItemType target, bool & success);
   
	// delete target node from tree, called by internal remove node
	BinaryNode<ItemType>* deleteNode(BinaryNode<ItemType>* targetNodePtr);
   
	// remove the leftmost node in the left subtree of nodePtr
	BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* nodePtr, ItemType & successor);
   
	// search for target node
	BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType & target) const;

	// internal print indentend tree
	BinaryNode<ItemType>* _indentedTree(BinaryNode<ItemType>* nodePtr, string indent);
   
public:  
	// insert a node at the correct location
    bool insert(const ItemType & newEntry);
	// remove a node if found
	void remove( ItemType target);
	// find a target node
	bool getEntry(const ItemType & target, ItemType & returnedItem) const;
	// update data
	bool update(bool updatedName, ItemType& target, ItemType& newData);
	// prints indented tree
	bool indentedTree(BinaryNode<ItemType>* nodePtr);
	bool indentedTree();
 
};

#endif

/////////////////////////// public function definitions ///////////////////////////

template<class ItemType>
bool BinarySearchTree<ItemType>::insert(const ItemType & newEntry)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
	rootPtr = _insert(rootPtr, newNodePtr); 
	count++;
	return true;
}  

template<class ItemType>
void BinarySearchTree<ItemType>::remove( ItemType target )
{
	//bool isSuccessful = false;
	//rootPtr = _remove(rootPtr, target, isSuccessful);
	//count--;
	//return isSuccessful; 
	/* Pre: a name
	Post: node with the given name is removed from the tree and pointers are rebound
	Return: none */
	BinaryNode<ItemType>* current;
	current = rootPtr;
	BinaryNode<ItemType>* parent = 0;
	while (*current->getItem() != *target) //traverse tree and search for name
	{
		parent = current;
		if (*target > *current->getItem())
		{
			current = current->getRightPtr();
		}
		else
		{
			current = current->getLeftPtr();
		}
		if (current == 0)//if we never find the name
		{
			cout << "No entry by that name exists." << endl;
			return;
		}
	}
	//removing leaf node
	if (current->getLeftPtr() == 0 && current->getRightPtr() == 0)
	{
		if (parent->getLeftPtr() == current)
		{
			parent->setLeftPtr(0);
		}
		else
		{
			parent->setRightPtr(0);
		}
		delete current;
		cout << "Entry deleted (by Name). (Leaf)" << endl;
		return;
	}
	//case: has left child but no right child
	if ((current->getLeftPtr() != 0) && (current->getRightPtr() == 0))
	{
		if (parent->getLeftPtr() == current)
		{
			parent->setLeftPtr(current->getLeftPtr());
			delete current;
		}
		else
		{
			parent->setRightPtr(current->getLeftPtr());
			delete current;
		}
		cout << "Entry deleted (by Name). (Left Child)" << endl;
		return;
	}
	//case: has right child but no left child
	if ((current->getLeftPtr() == 0) && (current->getRightPtr() != 0))
	{
		if (parent->getLeftPtr() == current)
		{
			parent->setLeftPtr(current->getRightPtr());
			delete current;
		}
		else
		{
			parent->setRightPtr(current->getRightPtr());
			delete current;
		}
		cout << "Entry deleted (by Name). (Right Child)" << endl;
		return;
	}
	//case: has 2 children
	//logic: when we delete a node, replace it with the smallest value in
	// the right subtree of the node we are deleting then delete
	// that node
	if ((current->getLeftPtr() != 0) && (current->getRightPtr() != 0))
	{
		BinaryNode<ItemType>* check;
		check = current->getRightPtr();
		//if right node is a leaf, replace current node with it and set right node to 0
		if ((check->getLeftPtr() == 0) && (check->getRightPtr() == 0))
		{
			current->setItem(check->getItem());
			delete check;
			current->setRightPtr(0);
		}
		else //traverse right side to find smallest element if right node has left child
		{
			if (current->getRightPtr()->getLeftPtr() != 0)
			{
				//new reference pointers not to be confused with initial parent/current pointers,
				//which will allow us to travers the tree further
				BinaryNode<ItemType>* parent2 = current->getRightPtr();
				BinaryNode<ItemType>* current2 = current->getRightPtr()->getLeftPtr();
				while (current2->getLeftPtr() != 0)//find smallest element in the subtree
				{
					parent2 = current2;
					current2 = current2->getLeftPtr();
				}
				current->setItem(current2->getItem()); //replacing node (see logic above)
				delete current2;
				parent2->setLeftPtr(0); //delete node we used to replace the node we wanted to deleted
			}
			else //if nothing on the left of subtree
			{
				BinaryNode<ItemType>* temp = current->getRightPtr();
				current->setItem(temp->getItem());
				current->setRightPtr(temp->getRightPtr());
				delete temp;
			}
		}
		cout << "Entry deleted (by Name). (2 Children)" << endl;
		return;
	}
}  

template<class ItemType>
bool BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry, ItemType & returnedItem) const
{
	BinaryNode<ItemType>* nodePtr;
	if(nodePtr = findNode(rootPtr, anEntry))
	{
		returnedItem = nodePtr->getItem();
		return true;
	}
	else
		return false;
}  

template<class ItemType>
bool BinarySearchTree<ItemType>::update(bool updatedName, ItemType& target, ItemType& newData)
{
	BinaryNode<ItemType>* nodePtr;
	if( nodePtr = findNode(rootPtr, target) )
	{
		if(updatedName)
		{
			this->remove(target);
			this->insert(newData);
		}
		else
			nodePtr->setItem(newData);
		
		return true;
	}
	else
		return false;
} 

template<class ItemType>
bool BinarySearchTree<ItemType>::indentedTree()
{
	BinaryNode<ItemType>* nodePtr;
	cout<<endl;
	nodePtr = _indentedTree(rootPtr,"");
	if(nodePtr == 0)
		return false;
	return true;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::indentedTree(BinaryNode<ItemType>* nodePtr)
{
	BinaryNode<ItemType>* nodePtr;
	cout<<endl;
	nodePtr = _indentedTree(nodePtr,"");
	if(nodePtr == 0)
		return false;
	return true;
}

//////////////////////////// private functions ////////////////////////////////////////////

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_insert(BinaryNode<ItemType>* nodePtr,
                                                          BinaryNode<ItemType>* newNodePtr)
{
	if ( nodePtr == 0 )
		return newNodePtr;
	else
	{
		if( *newNodePtr->getItem() < *nodePtr->getItem() )
			nodePtr->setLeftPtr(_insert( nodePtr->getLeftPtr(), newNodePtr ));
		else
			nodePtr->setRightPtr(_insert( nodePtr->getRightPtr(), newNodePtr ));
		return nodePtr;
	}


}  


template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_remove(BinaryNode<ItemType>* nodePtr,
                                                          const ItemType target, bool & success)
{
	//BinaryNode<ItemType> prev = new BinaryNode<Item>()
	//prev = 0;
	//if (nodePtr == 0)                   
	//{
	//	success = false;
	//	return 0;
	//}

	//else if (*nodePtr->getItem() == *target)
	//{
	//	nodePtr = deleteNode(nodePtr);
	//	prev->set
	//	success = true;


	//	return 0;
	//}

	//else
	//{
	//	prev = nodePtr;
	//	if (*nodePtr->getItem() > *target)		 
	//		nodePtr->setLeftPtr(_remove(nodePtr->getLeftPtr(), target, success));
	//	else if (*nodePtr->getItem() < *target)	 
	//		nodePtr->setRightPtr(_remove(nodePtr->getRightPtr(), target, success));   
	//}


	return nodePtr;   
}  

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::deleteNode(BinaryNode<ItemType>* nodePtr)
{
	if (nodePtr->isLeaf())		// no child nodes		
	{
		delete nodePtr;
		nodePtr = 0;
		return nodePtr;
	}
	else if (nodePtr->getLeftPtr() == 0)	// no left child, only right child
	{
		BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getRightPtr();
		delete nodePtr;
		nodePtr = 0;
		return nodeToConnectPtr;
	}
	else if (nodePtr->getRightPtr() == 0)	// no right child, only left child
	{
		BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getLeftPtr();
		delete nodePtr;
		nodePtr = 0;
		return nodeToConnectPtr;      
	}
	else	// both child nodes are present                                 
	{
		ItemType newNodeValue;
		nodePtr->setRightPtr(removeLeftmostNode(nodePtr->getRightPtr(), newNodeValue));
		nodePtr->setItem(newNodeValue);
		return nodePtr;
	}  
}  

template<class ItemType> 
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* nodePtr,
                                                                     ItemType & successor)
{
	if (nodePtr->getLeftPtr() == 0)	//if left null
	{
		successor = nodePtr->getItem();
		return deleteNode(nodePtr);
	}
	else 
	{
		nodePtr->setLeftPtr(removeLeftmostNode(nodePtr->getLeftPtr(), successor));
		return nodePtr;
	}       
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* nodePtr,
                                                           const ItemType & target) const 
{
	if (nodePtr == 0)                   
	{
		return 0;
	}
	if (nodePtr->getItem() > target)		 
		findNode(nodePtr->getLeftPtr(), target);
	else if (nodePtr->getItem() < target)	 
		findNode(nodePtr->getRightPtr(), target);
	else if (nodePtr->getItem() == target)
	{
			return nodePtr;
	}      
		
} 
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_indentedTree(BinaryNode<ItemType>* nodePtr, string indent)
{
	if(nodePtr == 0)
		return nodePtr;
	else
	{
		_indentedTree(nodePtr->getRightPtr(), indent + "	");
		cout << indent <<"|"<< *nodePtr->getItem() <<"|"<< endl;
		_indentedTree(nodePtr->getLeftPtr(), indent + "	");
		return nodePtr;
	}
}