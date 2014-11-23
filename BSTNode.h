#ifndef __Lab3__Node__
#define __Lab3__Node__

#include <stdio.h>
#include "Food.h"
#include <iostream>
#include <string>

using namespace std;

class BSTNode
{
	//Declartion of variables
    private:
		Food foodobj;
		BSTNode* leftptr;
		BSTNode* rightptr;
    
    public:
		//Default constructor
		BSTNode();
		BSTNode(People inputperson);
		
		//Getter and setter functions
		void setfood(Food inputfobj);
		Food getperson();
    
		BSTNode* getleftptr();
		BSTNode* getrightptr();
    
		void setleftptr(BSTNode* inputlptr);
		void setrightptr(BSTNode* inputrptr);
		//Print node attributes method
		string print() const;
    
};
