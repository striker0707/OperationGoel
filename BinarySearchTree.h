#ifndef Lab3_BinarySearchTree_h
#define Lab3_BinarySearchTree_h
#include "Node.h"
#include "Queue.h"

class BinarySearchTree
{
    private:
	//Declaration of variables
    Node* root;
	//Private add, search, amd modify methods
    bool addHelper(Node* n, Node* newNode);
    bool searchHelper(Node* n, People pobj);
    bool modifyHelper(Node* n, People pobj);
    
    public:
	//Default constructor
    BinarySearchTree();
	//Search, modify, add, and remove methods
    bool search(People pobj);
    bool add(People peopleobj);
    bool remove(const People& pobj);
    bool removeHelper(Node* n, const People& pobj);
    Node* removeNode(Node* n);
    
    void modify(People pobj, People newpobj);
    
	//Ordering methods
    void inorder(ostream& stream);
    void inorderHelper(Node* n, ostream& stream);
    void postorder(ostream& stream);
    void postorderHelper(Node* n, ostream& stream);
    void breadthfirst(ostream& stream);
    
    void print();
    
};


#endif
