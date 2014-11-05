#ifndef BST_H
#define BST_H

// *********************************************************
// Header file BST.h for the ADT binary search tree.
// Assumption: A tree contains at most one item with a given
//             search key at any time.
// *********************************************************

#include "..."  // definition of itemClass
typedef type - of - item - in - tree treeItemType;
typedef type - of - key - field keyType;
typedef void(*functionType)(treeItemType& AnItem);
typedef treeNode* ptrType;  // pointer to node

struct treeNode
{
	treeItemType Item;
	ptrType      LChildPtr, RChildPtr;
	// constructor:
	treeNode(treeItemType& NodeItem, ptrType L, ptrType R);
};  // end struct
