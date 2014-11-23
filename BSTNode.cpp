
#include "BSTNode.h"
#include <iostream>
#include <string>

using namespace std;

//Constructors
BSTNode::BSTNode()
{
    personobj.setpname("0");
    personobj.setDOB("0");
    leftptr = nullptr;
    rightptr = nullptr;
}

BSTNode::BSTNode(People inputperson)
{
    personobj = inputperson;
    leftptr = nullptr;
    rightptr =  nullptr;
}

//Getter and setter functions
void BSTNode::setperson(People inputpobj)
{
    personobj = inputpobj;
}

People BSTNode::getperson()
{
    return personobj;
}

BSTNode* BSTNode::getrightptr()
{
    return rightptr;
}

BSTNode* BSTNode::getleftptr()
{
    return leftptr;
}

void BSTNode::setrightptr(Node* inputrptr)
{
    rightptr = inputrptr;
}

void BSTNode::setleftptr(Node* inputlptr)
{
    leftptr = inputlptr;
}

//Print method
string BSTNode::print() const
{
    string output = personobj.getpname() + ": " + personobj.getDOB();
    output += " left:" + ((leftptr != nullptr) ? leftptr->getperson().getpname() : "nullptr");
    output += " right:" + ((rightptr != nullptr) ? rightptr->getperson().getpname() : "nullptr");
    return output;
}
