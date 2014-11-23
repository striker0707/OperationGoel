#ifndef Lab3_BinarySearchTree_h
#define Lab3_BinarySearchTree_h
#include "BSTNode.h"
#include "Queue.h"

class BinarySearchTree
{
    private:
	//Declaration of variables
    BSTNode* root;
	//Private add, search, amd modify methods
    bool addHelper(BSTNode* n, BSTNode* newNode);
    bool searchHelper(BSTNode* n, Food fobj);
    bool modifyHelper(BSTNode* n, Food fobj);
    
    public:
	//Default constructor
    BinarySearchTree();
	//Search, modify, add, and remove methods
    bool search(Food fobj);
    bool add(Food foodobj);
    bool remove(const Food& fobj);
    bool removeHelper(BSTNode* n, const Food& fobj);
    Node* removeNode(BSTNode* n);
    
    void modify(Food fobj, Food newfobj);
    
	//Ordering methods
    void inorder(ostream& stream);
    void inorderHelper(BSTNode* n, ostream& stream);
    void postorder(ostream& stream);
    void postorderHelper(BSTNode* n, ostream& stream);
    void breadthfirst(ostream& stream);
    
    void print();
    
};


#endif
