/** \mainpage PROPOSITIONAL LOGIC
 *  \subpage This program is designed as a Proof checking engine for rules of Natural Deduction
 * The first part of the program is to convert Infix 
 * to Postfix form , construction of Parse tree and its inorder 
 * traversal.
 *
 * The second part of the program is a tool to verify 
 * whether a certain proof of a given sequent is valid or not
 *
 * The proof rules allowed are AND introduction/elimination,
 * OR introduction,Implication elimination and Modus Tollens
 *
 * Definitions : <statement> : : = p | ~p | ~(<statement>) | (<statement>^<statement>) | (<statement> V <statement>) | (<statement> > <statement>)
 *
 * <rule> :: = ^i | ^e1 | ^e2 | Vi1 | Vi2 | >e | MT | p
 *
 * <b>EVERY FORMULA MUST BE PERFECTLY PARENTHESIZED</b>
 *
 * Example : (a^b) , ((a^b)^c) , (~a) are valid but not (a) , (a^b^c) , ~a
 *
 * NOTE : Do not use "V" as a propositional atom as we used it for OR operation
 * 
 * \page page1 Report for PART 1
 *
 * Input:a       	 		Output_1: a		   Output_2: a				  Time: 0.00012
 *
 * Input:a^~b    	 		Output_1: ab~^		   Output_2: (a^(~b))			  Time: 0.00013
 *
 * Input:a>(cVd) 	 		Output_1: acdV>		   Output_2: (a>(aVd))			  Time: 0.00017
 *
 * Input:(a^(~(cV(d>e)))) 		Output_1: acde>V~^	   Output_2: (a^(~(cV(d>e))))		  Time: 0.00024
 *
 * Input:(a^(~(cV(d>e))))>(s^(g>h))   	Output_1: acde>V~^sgh>^>   Output_2: ((a^(~(cV(d>e))))>(s^(g>h))) Time: 0.00032
 *
 * \page page2 Report for PART 2
 *
 * <b>AND INTRODUCTION</b>
 *
 * (a^b)/p
 *
 * (~c)/p
 *
 * ((a^b)^(~c))/^i/1/2
 *
 * OUTPUT : valid , TIME : 0.000029
 *
 * <b>AND ELIMINATION</b>
 * 
 * 1.
 *
 * ((a^b)^(~(c>d)))/p
 *
 * (a^b)/^e1/1
 *
 * OUTPUT : valid , TIME : 0.000031
 *
 * 2.
 *
 * ((a^b)^(~(c>d)))/p
 *
 * (~(c^d))/^e2/1
 *
 * OUTPUT : valid , TIME : 0.000030
 *
 * <b>OR INTRODUCTION</b>
 *
 * 1.
 *
 * ((a^b)>(~c))/p
 * 
 * (~d)/p
 *
 * (((a^b)>(~c))V(~(eVf)))/Vi1/1
 *
 * OUTPUT : valid , TIME : 0.000031
 *
 * 2.
 *
 * ((a^b)>(~c))/p
 * 
 * (~d)/p
 *
 * ((~(s>t))V((a^b)>(~c)))/Vi2/1
 *
 * OUTPUT : valid , TIME : 0.000031
 *
 * <b>IMPLICATION ELIMINATION</b>
 *
 * ((a>b)>(~(c^d)))/p
 *
 * (~(c^d))/p
 *
 * (a>b)/>e/1/2
 *
 * OUTPUT : valid , TIME : 0.000029
 *
 * <b>MODUS TOLLENS</b>
 *
 * ((~(a^b))>(c>d))/p
 *
 * (~(c>d))/p
 *
 * (~(~(a^b)))/MT/1/2
 *
 * OUTPUT : valid , TIME : 0.000030
 * 
 * @file main1.c
 * 
 * @brief This file has a program to perform 3 tasks
 * 
 * Task 1: Converts infix form to postfix form
 *
 * Task 2: Builds a parse tree for given postfix form
 *
 * Task 3: Gives back the infix form by in_order traversal
 *
 * @author 2017A7PS0114H and 2017A7PS0262H
 * @note The symbols for operations are ~ NEGATION, ^ AND, V OR, > IMPLICATION
 * 
 */

#include<stdio.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "operator.h"

char inorderString[1000];
int main()
{
    char infix[100];
    printf("enter the infix form\n");
    scanf("%s",infix);

    char * v1 = inToPostfix(infix);
    char * use = traverseInorder(buildBinaryTree(v1));

    printf("the postfix form is : %s",v1);
    printf("\nthe in_order traversal gives :");
    printf("%s\n",use);

    return 0;
} 
