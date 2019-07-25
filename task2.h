/**
 * @file task2.h
 * @author 2017A7PS0114H and 2017A7PS0262H
 * @brief This file has the functions required to perform task 2 which is to build a parse tree for given postfix form
 * 
 */
#ifndef TASK2_H
#define TASK2_H
#include<string.h>
#include<stdlib.h>
#include "operator.h"
#define N 1000 /**< @def N is defined to be 1000*/ 
/** @brief A variable declaration with structure declaration called node */
struct node
{
    struct node* right; /**< this is a structure node pointer pointing to the left child*/
    char data; /**< character that stores the data to be inside the node*/
    struct node* left; /**< this is a structure node pointer pointing to the right child*/
};

struct node* stack2[N]; /**< an array for implementing stack operation*/
struct node* parentNode;/**< a pointer pointing to the parent node*/
int ios2=-1;/** The index of stack2. Initialized to -1 due to absence of any element*/


/**
 *  @brief A function to create a node and return a pointer pointing it
 * 
 * Creates node and assigns each element of it to NULL
 * @param value This is the value to be stored in the data part of the node
 * @return pointer to the node created
 */
struct node* createNode(char value){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->right =NULL;
    ptr->left = NULL;
    ptr->data = value;
    return ptr;
}
/**
 *  @brief A function to push the pointer to node onto the stack2 array.
 * 
 * Pushes the pointer to node by increasing the index.
 * @param address The pointer to be pushed onto stack
 * @return void
 */
void push2(struct node* address){
    stack2[++ios2]=address;
}
/**
 * @brief A function to pop the topmost pointer out of the stack2 array.
 * 
 * Pops out the top element and decreases the index.
 * 
 * @param void
 * @return returns the pointer at the top 
 */
struct node* pop2(){
    return(stack2[ios2--]);
}
/**
 * @brief A function to construct a parse tree
 * 
 * This function parse through the postfix form string till the end 
 * It prints the brackets accordingly when it encounters unary or binary operator 
 * If the element is an alphabet other than V then it creates a node for that
 * the function uses array implementation of stack to push and pop elements which are children of the parent node
 * 
 * @param inp_postfix a postfix form of the formula
 * @return parentNode
 * @note the letter V is used for OR operation. Do not use it as a propositional atom  
 */
struct node* buildBinaryTree(char* inp_postfix){
    char form[N];
    int i=0;
     if(inp_postfix==NULL) return 0;
    strcpy(form,inp_postfix);

    while(form[i]!=0){
        
        if(isalpha(form[i]) && form[i]!='V'){
	    parentNode = createNode(form[i]);
            push2(parentNode);
        }
       else if(isUnary(form[i])){
            parentNode = createNode(form[i]);
            parentNode->right =pop2();
            push2(parentNode);
        }
        else if(isBinary(form[i]))
        {
            parentNode = createNode(form[i]);
            parentNode->right=pop2();
            parentNode->left= pop2();
            push2(parentNode);
        }
        i++;
    }
    return parentNode;
} 
#endif
