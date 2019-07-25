/**
 * @file task3.h
 * @author 2017A7PS0114H and 2017A7PS0262H
 * @brief This file has the functions required to perform task 3 which is for the in_order traversal of the parse tree
 * 
 */
#ifndef TASK3_H
#define TASK3_H
#include<string.h>
#include "operator.h"
#define N 1000

int inorderIndex=-1;/** The index of the output of in_order traversal. Initialized to -1 due to absence of any element*/
char inorderString[N];/** the string to store the output of in_order traversal of the tree*/

/**
 * @brief A function for traversing the parse tree .The in_order traversal gives infix form.
 * 
 * this function parse through the left subtree then the root and then the 
 * right subtree recursively to give the infix form by in_order traversal.
 * 
 * @param t which is the root node of the binary parse tree
 * @return inorderString 
 * @note It gives outermost brackets for every formula i.e When the postfix is ab^ it gives (a^b).
 */
char* traverseInorder(struct node* t) 
{
   if(t) 
    { 
       int flag = 1;
        if(isBinary(t->data))
        {
            inorderString[++inorderIndex]='(';
        }
        if(isUnary(t->data)){
            inorderString[++inorderIndex]='(';
            flag=0;
        }
        if(flag)
        traverseInorder(t->left);

        inorderString[++inorderIndex]=t->data;

        traverseInorder(t->right);
        if(isUnary(t->data))
        {
            inorderString[++inorderIndex]=')';            
        }
        if(isBinary(t->data))
        {
            inorderString[++inorderIndex]=')';
        }
        
   }
   return inorderString;

} 
#endif

