
#include "BSTNode.h"
#include <iostream>
#include <string>

using namespace std;

//Constructors
BSTNode::BSTNode()
{
    foodobj.setName(" ");
    foodobj.setCalories(0);
    foodobj.setGramsFat(0);
    foodobj.setCholesterol(0);
    foodobj.setSodium(0);
    foodobj.setProtein(0);
    leftptr = nullptr;
    rightptr = nullptr;
}

BSTNode::BSTNode(People inputfoodobj)
{
    foodobj = inputfoodobj;
    leftptr = nullptr;
    rightptr =  nullptr;
}

//Getter and setter functions
void BSTNode::setperson(Food inputfobj)
{
    foodobj = inputfobj;
}

Food BSTNode::getfood()
{
    return foodobj;
}

BSTNode* BSTNode::getrightptr()
{
    return rightptr;
}

BSTNode* BSTNode::getleftptr()
{
    return leftptr;
}

void BSTNode::setrightptr(BSTNode* inputrptr)
{
    rightptr = inputrptr;
}

void BSTNode::setleftptr(BSTNode* inputlptr)
{
    leftptr = inputlptr;
}

//Print method
string BSTNode::print() const
{
    string output = foodobj.getName();
    output += " left:" + ((leftptr != nullptr) ? leftptr->getfood().getName() : "nullptr");
    output += " right:" + ((rightptr != nullptr) ? rightptr->getfood().getName() : "nullptr");
    return output;
}
