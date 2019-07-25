/**
 * @file task1.h
 * @author 2017A7PS0114H and 2017A7PS0262H
 * @brief This file has the functions to perform task 1 to change infix to postfix form
 * 
 */

#ifndef TASK1_H
#define TASK1_H
#include<string.h>
#include<ctype.h>
#define N 1000/**< @def N is defined to be 1000*/


int ios1=-1;/**< The index of stack1. Initialized to -1 due to absence of any element*/
char stack1[N];/**< a character array for stack implementation*/
char postfix[N];/**< an array of characters to store the postfix form*/
/**
 *  @brief A function to push an element onto the stack1 array.
 * 
 * pushes the element by increasing the index.
 * @param inpt the char to be pushed to stack1.
 * @return void
 */
void push1(char inpt){
    stack1[++ios1]=inpt;
}
/**
 * @brief A function to pop the topmost element out of the stack1 array.
 * 
 * pops out the top element and decreases the index.
 * 
 * @param void
 * @return returns the character at the top 
 */
char pop1(){
    return(stack1[ios1--]);
}
/**
 * @brief A function to find the preference.
 * 
 * gives the weight of individual operators
 * 
 * @param inputOp the operator for which the weight is to be found
 * @return the integer weight
 * @note the operators are ~ , ^ , V , > for NEGATION,AND,OR and implication respectively
 */
int weightOf(char inputOp){
    int weight;
    switch(inputOp)
	{
                case '(': weight=1;break;        
                case '>': weight=2;break;		
                case 'V': weight=3;break;
                case '^': weight=4;break;
                case '~': weight=5;break;

	}
    return weight;
}
/**
 * @brief A function to convert infix to postfix form
 * 
 * this function parse through the infix form string till the end 
 * It pushes the element if it is alphabet other than V 
 * If it is an operator it pops out the operators in the stack with higher precedence 
 * and then pushes this element to stack recursively. And finally flushes the stack 
 * 
 * @param infix the formula in infix form
 * @return postfix which is the formula in postfix form
 * @note the letter V is used for OR operation. Do not use it as a propositional atom
 */
char* inToPostfix(char* infix){
  
  int i=0,k=0;
  while(infix[i]!='\0')
    {
        if(infix[i]=='(')
        {
            push1(infix[i]);
        }
        else if(infix[i]==')')
        {
                while(stack1[ios1]!='('){
                    postfix[k]=pop1();
                    k++;
                }

                pop1();
 
        }
        
        else if(isalpha(infix[i]) && infix[i]!='V')
            {
            postfix[k++]=infix[i];
            }
        
        else {

            while(weightOf(infix[i])<weightOf(stack1[ios1]))
                    postfix[k++]=pop1();
                    push1(infix[i]);
            }
        i++;
    }
    
    while(ios1!=-1)
    {
        postfix[k++]=pop1();
    }
    
   postfix[k]='\0';

   return postfix;
}

#endif