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
    bool searchHelper(BSTNode* n, People pobj);
    bool modifyHelper(BSTNode* n, People pobj);
    
    public:
	//Default constructor
    BinarySearchTree();
	//Search, modify, add, and remove methods
    bool search(People pobj);
    bool add(People peopleobj);
    bool remove(const People& pobj);
    bool removeHelper(BSTNode* n, const People& pobj);
    Node* removeNode(BSTNode* n);
    
    void modify(People pobj, People newpobj);
    
	//Ordering methods
    void inorder(ostream& stream);
    void inorderHelper(BSTNode* n, ostream& stream);
    void postorder(ostream& stream);
    void postorderHelper(BSTNode* n, ostream& stream);
    void breadthfirst(ostream& stream);
    
    void print();
    
};


#endif
