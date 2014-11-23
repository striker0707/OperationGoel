#ifndef __Lab3__Node__
#define __Lab3__Node__

#include <stdio.h>
#include "People.h"
#include <iostream>
#include <string>

using namespace std;

class BSTNode
{
	//Declartion of variables
    private:
		People personobj;
		BSTNode* leftptr;
		BSTNode* rightptr;
    
    public:
		//Default constructor
		BSTNode();
		BSTNode(People inputperson);
		
		//Getter and setter functions
		void setperson(People inputpobj);
		People getperson();
    
		BSTNode* getleftptr();
		BSTNode* getrightptr();
    
		void setleftptr(BSTNode* inputlptr);
		void setrightptr(BSTNode* inputrptr);
		//Print node attributes method
		string print() const;
    
};
