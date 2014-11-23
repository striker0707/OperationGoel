
#include <stdio.h>
#include <iostream>
#include <string>
#include "BSTNode.h"
#include "BinarySearchTree.h"
#include "Queue.h"

using namespace std;

//Default constructor
BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

//Search method
bool BinarySearchTree::search(Food fobj)
{
	//If located item is located in root, return root;
    if(((root->getfood()).getsortkey() == fobj.getsortkey()))
    {
        return root;
    }
       
    else
    {
		//If not located in root, recurse through the entire bst tree
        return searchHelper(root, fobj);
    }
}

//searchHelper method
bool BinarySearchTree::searchHelper(BSTNode* n, Food fobj)
{
	//If the located node is empty, return null
    if (n == nullptr)
    {
        return nullptr;
    }
    
	//If located node is on the n node, return n;
    if(fobj.getsortkey() == (n->getfood()).getsortkey())
    {
        return n;
    }
    
	//If node is on the left side of the bst tree, recurse until found
    else if(fobj.getsortkey() < (n->getfood()).getsortkey())
    {
        return searchHelper(n->getleftptr(), fobj);
    }
    else
    {
		//If node is on the right side of the bst tree, recurse until found.
        return searchHelper(n->getrightptr(), fobj);
    }
    
}

//Add method
bool BinarySearchTree::add(Food fobj)
{
	//If bst is empty, intialize node as root
    BSTNode* newnodeptr = new Node(fobj);
    if (root == nullptr)
    {
        root = newnodeptr;
        return true;
    }
    else
    {
		//Else, call addHelpher to find correct position
        return addHelper(root, newnodeptr);
    }
}

//AddHelpher method
bool BinarySearchTree::addHelper(BSTNode* n, BSTNode* newNode)
{
	//If new node is suppose to be added to the left
    if((newNode->getfood().getsortkey()) < (n->getfood().getsortkey()))
    {
		//If node is found on the root's left child
        if(n->getleftptr() == nullptr)
        {
			//Set root's left child as newnode
            n->setleftptr(newNode);
			
            return true;
        }
       
		//Otherwise, recurse until correct left side is found
        return addHelper(n->getleftptr(), newNode);
		
    }
    
	//Else if node is suppose to be added to the right
    else
    {
		//If root's right child is empty
        if(n->getrightptr() == nullptr)
        {
			//Set right child to newNode
            n->setrightptr(newNode);
			
            return true;
        }

		//else recurse until found
        return addHelper(n->getrightptr(), newNode);
    }
    
	
    return false;
    
}

//Postorder method
void BinarySearchTree::postorder(ostream& stream)
{
	//If nothing in BST, print message
    if(root == nullptr)
    {
        cout << "There is nothing within the tree." << endl;
    } 
	else
    {
		//Else print entire tree
        postorderHelper(root, stream);
    }
}

void BinarySearchTree::postorderHelper(BSTNode *n, ostream& stream)
{
	//As long as n is not a nullptr
    if (n != nullptr)
    {
		//Print left, right, then n
        postorderHelper(n->getleftptr(), stream);
        postorderHelper(n->getrightptr(), stream);
        stream << n->print() << endl;
    }
}

void BinarySearchTree::inorder(ostream& stream)
{
    if( root == nullptr)
    {
        cout << "There is nothing within the tree." << endl;
    }
    
    else
    {
        inorderHelper(root, stream);
    }
}

void BinarySearchTree::inorderHelper(BSTNode* n, ostream& stream)
{
    if(n != nullptr)
    {
        inorderHelper(n->getleftptr(), stream);
        stream << n->print() << endl;
        inorderHelper(n->getrightptr(), stream);
    }
}

//remove method
bool BinarySearchTree::remove(const Food& fobj)
{
	//If remove node is equal to root
    if(root->getfood().getsortkey() == fobj.getsortkey())
    {
		//Recieve replacement node and replace with root
        BSTNode* newRootNode = removeNode(root);
		
        root = newRootNode;
	
        return true;
		
    }
    else
    {
		//Else traverse the entire bst to find replacement node
        return removeHelper(root, fobj);
    }
}

//RemoveHelpher
bool BinarySearchTree::removeHelper(BSTNode* n, const Food& fobj)
{
	//If the remove node is located to the left
    if(fobj.getsortkey() < (n->getname().getsortkey()))
    {
		//And if it equals to the n's left child
        if(n->getleftptr() == nullptr)
        {
			//Return false
            return false;
        }
        
		//If remove node is located to n's leftchild
        if(fobj.getsortkey() == n->getleftptr()->getfood().getsortkey())
        {
			//Get the correct node to replace it with and set it to n's left child
            BSTNode* newLeftNode = removeNode(n->getleftptr());
			
            n->setleftptr(newLeftNode);
			
            return true;
        }
        
		
        else
        {
			//Else recurse until node is found
            return removeHelper(n->getleftptr(), fobj);
        }
    }
    
	//If node is on the right side
    else if (fobj.getsortkey() > (n->getfood().getsortkey()))
    {
		//And node's right child is null, return null
        if(n->getrightptr() == nullptr)
        {
			
            return false;
        }
        
		//If the nodes right child matches with remove obj
        if(fobj.getsortkey() == n->getrightptr()->getfood().getsortkey())
        {
			//Find the replacement node and set it to the node's right
            BSTNode* newRightNode = removeNode(n->getrightptr());
			
            n->setrightptr(newRightNode);
			
            return true;
        }
        
        else
        {
			//Else recurse until found
            return removeHelper(n->getrightptr(), fobj);
        }
        
    }
    else
    {
        // this should never happen.
        return false;
    }
}
    
BSTNode* BinarySearchTree::removeNode(BSTNode* n)
{
    //In the case of a leaf node
   if(n->getleftptr() == nullptr && n->getrightptr() == nullptr)
   {
       delete n;
       return nullptr;
   }
    //In the case of a node with 2 children
    if(n->getleftptr() != nullptr && n->getrightptr() != nullptr)
    {
        BSTNode* tempnode = n->getrightptr();
        
        //And in the case that the node's left child is null
        if (tempnode->getleftptr() == nullptr)
        {
            tempnode->setleftptr(n->getleftptr());
            delete n;
            return tempnode;
        }
        
        //traverse down to find the leftmost node using the parent node before the node we're given
        while(tempnode->getleftptr()->getleftptr() != nullptr)
        {
            tempnode = tempnode->getleftptr();
        }
        
        BSTNode* returnnode = tempnode->getleftptr();
        
        
        // After traversing, in the case that the node we want to replace with has a right child
        if(returnnode->getrightptr() != nullptr)
        {
            tempnode->setleftptr(returnnode->getrightptr());
        }
        
        delete n;
        
        returnnode->setleftptr(n->getleftptr());
        returnnode->setrightptr(n->getrightptr());
        
        tempnode->setleftptr(nullptr);
        
        return returnnode;
    }
    
    //In the case that the node is a single parent and has a right child
    if((n->getleftptr() != nullptr && n->getrightptr() == nullptr))
    {
	BSTNode* tempnode = n->getleftptr();
	
        delete n;
        return tempnode;
    }
    
    //In the case that the node is a single parent and has a left child
    if((n->getleftptr() == nullptr && n->getrightptr() != nullptr))
    {
	BSTNode* tempnode = n->getrightptr();
	
        delete n;
        return tempnode;
    }
    
    //Should never happen.
    return nullptr;
    
}

//Modify method
void BinarySearchTree::modify(Food fobj, Food newfobj)
{
	//Calls on remove and add methods
    remove(fobj);
    add(newfobj);
    
    cout << "Food has been successfully removed and modified" << endl;
}

//Breadth first method
void BinarySearchTree::breadthfirst(ostream &stream)
{
	//If bst is empty, then return nothing
    if (root == nullptr)
    {
        return;
    }

	//Otherwise, declare a queue and a root first
    Queue q;
    q.enqueue(root);

	//And while the queue is not empty
    while (!q.isEmpty())
    {
		//Want to take the root into a temp variable and pop it out
        Node* tempNode = q.peekfront();
        q.dequeue();
        
		//Print the front of the queue
        stream << tempNode->print() << endl;
        
		//Put the node's left items into the queue
        if(tempNode->getleftptr() != nullptr)
        {
            q.enqueue(tempNode->getleftptr());
        }
        
		//Put the node's right items into the queue
        if(tempNode->getrightptr() != nullptr)
        {
            q.enqueue(tempNode->getrightptr());
        }
    }
    
}

