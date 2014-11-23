//#include "BinarySearchTree.h"
/////////////////////////// public function definitions ///////////////////////////
//
//template<class ItemType>
//bool BinarySearchTree<ItemType>::insert(const ItemType & newEntry)
//{
//	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
//	rootPtr = _insert(rootPtr, newNodePtr); 
//	count++;
//	return true;
//}  
//
//template<class ItemType>
//bool BinarySearchTree<ItemType>::insertbyBirth(const ItemType & newEntry)
//{
//	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
//	rootPtr = _insertbyBirth(rootPtr, newNodePtr); 
//	count++;
//	return true;
//}  
//
//
//
//template<class ItemType>
//bool BinarySearchTree<ItemType>::remove(const ItemType & target)
//{
//	bool isSuccessful = false;
//	rootPtr = _remove(rootPtr, target, isSuccessful);
//	count--;
//	return isSuccessful; 
//}  
//
//template<class ItemType>
//bool BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry, ItemType & returnedItem) const
//{
//	BinaryNode<ItemType>* nodePtr;
//	if(nodePtr = findNode(rootPtr, anEntry))
//	{
//		returnedItem = nodePtr->getItem();
//		return true;
//	}
//	else
//		return false;
//}  
//
//template<class ItemType>
//bool BinarySearchTree<ItemType>::update(bool updatedName, ItemType& target, ItemType& newData)
//{
//	BinaryNode<ItemType>* nodePtr;
//	if( nodePtr = findNode(rootPtr, target) )
//	{
//		if(updatedName)
//		{
//			this->remove(target);
//			this->insert(newData);
//		}
//		else
//			nodePtr->setItem(newData);
//		
//		return true;
//	}
//	else
//		return false;
//} 
//
////////////////////////////// private functions ////////////////////////////////////////////
//
//template<class ItemType>
//BinaryNode<ItemType>* BinarySearchTree<ItemType>::_insert(BinaryNode<ItemType>* nodePtr,
//                                                          BinaryNode<ItemType>* newNodePtr)
//{
//	if ( nodePtr == 0 )
//		return newNodePtr;
//	else
//	{
//		if( newNodePtr->getItem() < nodePtr->getItem() )
//			nodePtr->setLeftPtr(_insert( nodePtr->getLeftPtr(), newNodePtr ));
//		else
//			nodePtr->setRightPtr(_insert( nodePtr->getRightPtr(), newNodePtr ));
//		return nodePtr;
//	}
//
//
//}  
//
//template<class ItemType>
//BinaryNode<ItemType>* BinarySearchTree<ItemType>::_insertbyBirth(BinaryNode<ItemType>* nodePtr,
//                                                          BinaryNode<ItemType>* newNodePtr)
//{
//	if ( nodePtr == 0 )
//		return newNodePtr;
//	else
//	{
//		if( newNodePtr->getItem().getBirthday() < nodePtr->getItem().getBirthday() ) //compares both birthday strings
//			nodePtr->setLeftPtr(_insert( nodePtr->getLeftPtr(), newNodePtr ));
//		else
//			nodePtr->setRightPtr(_insert( nodePtr->getRightPtr(), newNodePtr ));
//		return nodePtr;
//	}
//
//
//}  
//
//template<class ItemType>
//BinaryNode<ItemType>* BinarySearchTree<ItemType>::_remove(BinaryNode<ItemType>* nodePtr,
//                                                          const ItemType target, bool & success)
//
//{
//	if (nodePtr == 0)                   
//	{
//		success = false;
//		return 0;
//	}
//	if (nodePtr->getItem() > target)		 
//		nodePtr->setLeftPtr(_remove(nodePtr->getLeftPtr(), target, success));
//	else if (nodePtr->getItem() < target)	 
//		nodePtr->setRightPtr(_remove(nodePtr->getRightPtr(), target, success));
//	else		
//	{
//		nodePtr = deleteNode(nodePtr);
//		success = true;
//	}      
//	return nodePtr;   
//}  
//
//template<class ItemType>
//BinaryNode<ItemType>* BinarySearchTree<ItemType>::deleteNode(BinaryNode<ItemType>* nodePtr)
//{
//	if (nodePtr->isLeaf())		// no child nodes		
//	{
//		delete nodePtr;
//		nodePtr = 0;
//		return nodePtr;
//	}
//	else if (nodePtr->getLeftPtr() == 0)	// no left child, only right child
//	{
//		BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getRightPtr();
//		delete nodePtr;
//		nodePtr = 0;
//		return nodeToConnectPtr;
//	}
//	else if (nodePtr->getRightPtr() == 0)	// no right child, only left child
//	{
//		BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getLeftPtr();
//		delete nodePtr;
//		nodePtr = 0;
//		return nodeToConnectPtr;      
//	}
//	else	// both child nodes are present                                 
//	{
//		ItemType newNodeValue;
//		nodePtr->setRightPtr(removeLeftmostNode(nodePtr->getRightPtr(), newNodeValue));
//		nodePtr->setItem(newNodeValue);
//		return nodePtr;
//	}  
//}  
//
//template<class ItemType> 
//BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* nodePtr,
//                                                                     ItemType & successor)
//{
//	if (nodePtr->getLeftPtr() == 0)	//if left null
//	{
//		successor = nodePtr->getItem();
//		return deleteNode(nodePtr);
//	}
//	else 
//	{
//		nodePtr->setLeftPtr(removeLeftmostNode(nodePtr->getLeftPtr(), successor));
//		return nodePtr;
//	}       
//}
//
//
//template<class ItemType>
//BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* nodePtr,
//                                                           const ItemType & target) const 
//{
//	if (nodePtr == 0)                   
//	{
//		return 0;
//	}
//	if (nodePtr->getItem() > target)		 
//		findNode(nodePtr->getLeftPtr(), target);
//	else if (nodePtr->getItem() < target)	 
//		findNode(nodePtr->getRightPtr(), target);
//	else if (nodePtr->getItem() == target)
//	{
//			return nodePtr;
//	}      
//		
//}  