#ifndef __Lab3__Node__
#define __Lab3__Node__

#include <stdio.h>
#include "People.h"
#include <iostream>
#include <string>

using namespace std;

class Node
{
	//Declartion of variables
    private:
		People personobj;
		Node* leftptr;
		Node* rightptr;
    
    public:
		//Default constructor
		Node();
		Node(People inputperson);
		
		//Getter and setter functions
		void setperson(People inputpobj);
		People getperson();
    
		Node* getleftptr();
		Node* getrightptr();
    
		void setleftptr(Node* inputlptr);
		void setrightptr(Node* inputrptr);
		//Print node attributes method
		string print() const;
    
};
