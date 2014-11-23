
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
bool BinarySearchTree::search(People pobj)
{
	//If located item is located in root, return root;
    if(((root->getperson()).getsortkey() == pobj.getsortkey()))
    {
        return root;
    }
       
    else
    {
		//If not located in root, recurse through the entire bst tree
        return searchHelper(root, pobj);
    }
}

//searchHelper method
bool BinarySearchTree::searchHelper(Node* n, People pobj)
{
	//If the located node is empty, return null
    if (n == nullptr)
    {
        return nullptr;
    }
    
	//If located node is on the n node, return n;
    if(pobj.getsortkey() == (n->getperson()).getsortkey())
    {
        return n;
    }
    
	//If node is on the left side of the bst tree, recurse until found
    else if(pobj.getsortkey() < (n->getperson()).getsortkey())
    {
        return searchHelper(n->getleftptr(), pobj);
    }
    else
    {
		//If node is on the right side of the bst tree, recurse until found.
        return searchHelper(n->getrightptr(), pobj);
    }
    
}

//Add method
bool BinarySearchTree::add(People pobj)
{
	//If bst is empty, intialize node as root
    Node* newnodeptr = new Node(pobj);
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
bool BinarySearchTree::addHelper(Node* n, Node* newNode)
{
	//If new node is suppose to be added to the left
    if((newNode->getperson().getsortkey()) < (n->getperson().getsortkey()))
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

void BinarySearchTree::postorderHelper(Node *n, ostream& stream)
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

void BinarySearchTree::inorderHelper(Node* n, ostream& stream)
{
    if(n != nullptr)
    {
        inorderHelper(n->getleftptr(), stream);
        stream << n->print() << endl;
        inorderHelper(n->getrightptr(), stream);
    }
}

//remove method
bool BinarySearchTree::remove(const People& pobj)
{
	//If remove node is equal to root
    if(root->getperson().getsortkey() == pobj.getsortkey())
    {
		//Recieve replacement node and replace with root
        Node* newRootNode = removeNode(root);
		
        root = newRootNode;
	
        return true;
		
    }
    else
    {
		//Else traverse the entire bst to find replacement node
        return removeHelper(root, pobj);
    }
}

//RemoveHelpher
bool BinarySearchTree::removeHelper(Node* n, const People& pobj)
{
	//If the remove node is located to the left
    if(pobj.getsortkey() < (n->getperson().getsortkey()))
    {
		//And if it equals to the n's left child
        if(n->getleftptr() == nullptr)
        {
			//Return false
            return false;
        }
        
		//If remove node is located to n's leftchild
        if(pobj.getsortkey() == n->getleftptr()->getperson().getsortkey())
        {
			//Get the correct node to replace it with and set it to n's left child
            Node* newLeftNode = removeNode(n->getleftptr());
			
            n->setleftptr(newLeftNode);
			
            return true;
        }
        
		
        else
        {
			//Else recurse until node is found
            return removeHelper(n->getleftptr(), pobj);
        }
    }
    
	//If node is on the right side
    else if (pobj.getsortkey() > (n->getperson().getsortkey()))
    {
		//And node's right child is null, return null
        if(n->getrightptr() == nullptr)
        {
			
            return false;
        }
        
		//If the nodes right child matches with remove obj
        if(pobj.getsortkey() == n->getrightptr()->getperson().getsortkey())
        {
			//Find the replacement node and set it to the node's right
            Node* newRightNode = removeNode(n->getrightptr());
			
            n->setrightptr(newRightNode);
			
            return true;
        }
        
        else
        {
			//Else recurse until found
            return removeHelper(n->getrightptr(), pobj);
        }
        
    }
    else
    {
        // this should never happen.
        return false;
    }
}
    
Node* BinarySearchTree::removeNode(Node* n)
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
        Node* tempnode = n->getrightptr();
        
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
        
        Node* returnnode = tempnode->getleftptr();
        
        
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
		Node* tempnode = n->getleftptr();
        delete n;
        return tempnode;
    }
    
    //In the case that the node is a single parent and has a left child
    if((n->getleftptr() == nullptr && n->getrightptr() != nullptr))
    {
		Node* tempnode = n->getrightptr();
        delete n;
        return tempnode;
    }
    
    //Should never happen.
    return nullptr;
    
}

//Modify method
void BinarySearchTree::modify(People pobj, People newpobj)
{
	//Calls on remove and add methods
    remove(pobj);
    add(newpobj);
    
    cout << "Item has been successfully removed and modified" << endl;
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

