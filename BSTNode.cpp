
#include "BSTNode.h"
#include <iostream>
#include <string>

using namespace std;

//Constructors
Node::Node()
{
    personobj.setpname("0");
    personobj.setDOB("0");
    leftptr = nullptr;
    rightptr = nullptr;
}

Node::Node(People inputperson)
{
    personobj = inputperson;
    leftptr = nullptr;
    rightptr =  nullptr;
}

//Getter and setter functions
void Node::setperson(People inputpobj)
{
    personobj = inputpobj;
}

People Node::getperson()
{
    return personobj;
}

Node* Node::getrightptr()
{
    return rightptr;
}

Node* Node::getleftptr()
{
    return leftptr;
}

void Node::setrightptr(Node* inputrptr)
{
    rightptr = inputrptr;
}

void Node::setleftptr(Node* inputlptr)
{
    leftptr = inputlptr;
}

//Print method
string Node::print() const
{
    string output = personobj.getpname() + ": " + personobj.getDOB();
    output += " left:" + ((leftptr != nullptr) ? leftptr->getperson().getpname() : "nullptr");
    output += " right:" + ((rightptr != nullptr) ? rightptr->getperson().getpname() : "nullptr");
    return output;
}
