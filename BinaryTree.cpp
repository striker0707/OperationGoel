//#include "BinaryTree.h"

//template<class ItemType>
//BinaryTree<ItemType>::BinaryTree()						
//{
//	rootPtr = 0; 
//	count = 0;
//}
//
//template<class ItemType>
//BinaryTree<ItemType>::BinaryTree(const BinaryTree<ItemType> & tree)	
//{ 
//	rootPtr = copyTree(tree.rootPtr); 
//	count = tree.count;
//}
//
//template<class ItemType>
//BinaryTree<ItemType>::~BinaryTree()
//{
//	destroyTree(rootPtr);
//}
//
//template<class ItemType>
//bool BinaryTree<ItemType>::isEmpty() const
//{
//	return count == 0;
//}
//
//template<class ItemType>
//int BinaryTree<ItemType>::size() const					
//{
//	return count;
//}
//
//template<class ItemType>
//void BinaryTree<ItemType>::clear()						
//{
//	destroyTree(rootPtr); 
//	rootPtr = 0; 
//	count = 0;
//}
//
//template<class ItemType>
//void BinaryTree<ItemType>::preOrder(void visit(ItemType &)) const		
//{
//	_preorder(visit, rootPtr);
//}
//
//template<class ItemType>
//void BinaryTree<ItemType>::inOrder(void visit(ItemType &)) const		
//{
//	_inorder(visit, rootPtr);
//}
//
//template<class ItemType>
//void BinaryTree<ItemType>::postOrder(void visit(ItemType &)) const	
//{
//	_postorder(visit, rootPtr);
//}
//
//
//
//template<class ItemType>
//BinaryTree<ItemType> & BinaryTree<ItemType>::operator=(const BinaryTree<ItemType> & sourceTree)
//{
//	rootPtr = copyTree(sourceTree.rootPtr);
//	count = sourceTree.count;
//
//	return *this;
//}
//
//template<class ItemType>
//void BinaryTree<ItemType>::destroyTree(BinaryNode<ItemType>* nodePtr)
//{
//	if(nodePtr != 0)
//	{
//		destroyTree(nodePtr->getLeftPtr());
//		destroyTree(nodePtr->getRightPtr());
//		delete nodePtr;
//	}
//} 
//
//template<class ItemType>
//BinaryNode<ItemType>* BinaryTree<ItemType>::copyTree(const BinaryNode<ItemType>* nodePtr) 
//{
//	BinaryNode<ItemType>* newNodePtr = 0;
//
//	if(nodePtr == 0)
//		newNodePtr = 0;
//	else
//	{
//		newNodePtr = new BinaryNode<ItemType>(nodePtr->getItem());
//		newNodePtr->setLeftPtr(copyTree(nodePtr->getLeftPtr()));
//		newNodePtr->setRightPtr(copyTree(nodePtr->getRightPtr()));
//	}
//
//	return newNodePtr;
//}
//
//template<class ItemType>
//void BinaryTree<ItemType>::_preorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
//{
//	if (nodePtr != 0)
//	{
//		ItemType item = nodePtr->getItem();
//		visit(item);
//		_preorder(visit, nodePtr->getLeftPtr());
//		_preorder(visit, nodePtr->getRightPtr());
//	}
//}  
//
//template<class ItemType>
//void BinaryTree<ItemType>::_inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
//{
//	if (nodePtr != 0)
//	{
//		_inorder(visit, nodePtr->getLeftPtr());
//		ItemType item = nodePtr->getItem();
//		visit(item);
//		_inorder(visit, nodePtr->getRightPtr());
//	}
//}  
//
//template<class ItemType>
//void BinaryTree<ItemType>::_postorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
//{
//	if (nodePtr != 0)
//	{
//		_postorder(visit, nodePtr->getLeftPtr());
//		_postorder(visit, nodePtr->getRightPtr());
//		ItemType item = nodePtr->getItem();
//		visit(item);
//		
//	}
//}  
// 
//template<class ItemType>
//void BinaryTree<ItemType>::breadthfirst() const
//{
//	queue<BinaryNode<ItemType>*> q;
//	ofstream fout("BreadthFirstContacts.txt");
//
//	if(rootPtr != 0)
//		q.push(rootPtr);
//	
//	while (!q.empty())
//	{
//		cout << q.front()->getItem() << endl;
//		fout << q.front()->getItem() << endl;
//		if(q.front()->getLeftPtr() != 0)
//			q.push(q.front()->getLeftPtr());
//		if(q.front()->getRightPtr() != 0)
//			q.push(q.front()->getRightPtr());
//		q.pop();
//	}
//	fout.close();
//}
