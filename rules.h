/**
 * @file rules.h
 * @author 2017A7PS0114H and 2017A7PS0262H
 * @brief This file has the functions required to check the validity of the proof
 * 
 */

#include "task1.h"
#include "task2.h"
#include "task3.h"
#include<string.h>
#include<ctype.h>
#define N 1000

char formulas[N][N];/** the array to store all the formulas encountered in the proof lines*/
char elemProofLines[4][N];/** the array to store the formula,proof rule and the reference numbers if any*/
char negationString[N];/** the string to store the negation of a formula*/
char inorderString[N];/** the string which stores the output of the traverseInorder function*/
int countValidLines=0;/** An integer variable to store the no.of valid lines of proof till then,initialized to zero*/
int formRow=0;/** The index for the rows of formulas array to access formulas of reference lines*/

char inorderString[N];

/**
 * @brief A function to reinitialize the InorderString array
 * 
 * This function reinitializes every element to '\0'
 * 
 * @param void
 * @return void
 */
void clearInorderString(){
    for(int i=0;i<N;i++)
    {
    inorderString[i]='\0';
    }
    inorderIndex=-1;
}
/**
 * @brief A function to get the negation of a formula 
 * 
 * This function appends '~' at the beginning of the formula and also <b>encloses it with brackets</b>
 * 
 * @param req which is the name of array that has the formula  
 * @return string with the negation and enclosed with brackets 
 */

char* negOf(char req[])
{
    int length=strlen(req);
    int w=2;
    for(int i=0;i<N;i++)
    {
        negationString[i]='\0';
    }
    negationString[0]='(';negationString[1]='~';
    for(int i=0;i<length;i++)
    {
        negationString[w++]=req[i];
    }
    negationString[w]=')';
    return negationString;
}
/**
 * @brief A function to separate formula,rule notation,reference number(s) of the proof line
 * 
 * This function breaks the input at every encounter of '/' and stores them in elemOfProofLine array
 * 
 * @param s which is the input proof line
 * @return void 
 */
void splitProofLine(char* s){
    int k=0,l=0;
    
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<N;j++)
            {
                elemProofLines[i][j]=' ';
            }
        }
        for(int j=0;j<N;j++)
        {
            if(s[j]=='/')
            {
                elemProofLines[k][l]='\0';
                if(k==0){ strcpy(formulas[formRow],elemProofLines[0]); formRow++;}
                k++;
                l=0;
            }
            else
                elemProofLines[k][l++]=s[j];
                       
        }
        elemProofLines[k][l]='\0';
}

/**
 * @brief A function to check the given proof line with the proof rule
 * 
 * This function identifies the rule mentioned and checks the correctness 
 * with respect to the reference numbers entered.
 * As soon as we enter the corresponding if block is executed which compares
 * the left and/or the right subtree with the formulas at the reference numbers
 * and increases the count variable if it is valid.
 * The sub_formulas are obtained by giving the right or left nodes of the parent 
 * node which we get from bulidBinaryTree function to the traverseInorder function 
 * 
 * @param void  
 * @return an integer countValidLines which is the no.of valid lines
 * @note give the inputs in perfectly parenthesized infix form.
 * 
 */
int proofRuleCheck()
{ 
    int a=0,b=0;
    char premise[]="p";
    char ANDi[]="^i";
    char ANDe1[]="^e1";
    char ANDe2[]="^e2";
    char ORi1[]="Vi1";
    char ORi2[]="Vi2";
    char IMPe[]=">e";
    char MT[]="MT";

    int first=atoi(elemProofLines[2])-1;
    int second=atoi(elemProofLines[3])-1;
  
    if(!strcmp(elemProofLines[1],premise))
    {
            countValidLines++;
    }
    
    else if(!strcmp(elemProofLines[1],ANDi))
    {
        struct node* par = buildBinaryTree(inToPostfix(elemProofLines[0]));
        clearInorderString();
        traverseInorder(par->left);
        b=strcmp(formulas[first],inorderString); 
        clearInorderString();
        traverseInorder(par->right);
        b=strcmp(formulas[second],inorderString); 
        if(a==0&&b==0) countValidLines++;
        
    }
    
    else if(!strcmp(elemProofLines[1],ANDe1))
    {
            struct node* par = buildBinaryTree(inToPostfix(formulas[first]));
            clearInorderString();
            traverseInorder(par->left);
            a=strcmp(elemProofLines[0],inorderString);
            if(a==0) countValidLines++;
   
    }
    
    else if(!strcmp(elemProofLines[1],ANDe2))
    {
        
            struct node* par = buildBinaryTree(inToPostfix(formulas[first]));
            clearInorderString();
            traverseInorder(par->right);
            b=strcmp(elemProofLines[0],inorderString);
            if(b==0) countValidLines++;
        
        
    }
    
    else if(!strcmp(elemProofLines[1],ORi1))
    {
       
        struct node* par=buildBinaryTree(inToPostfix(elemProofLines[0]));
        clearInorderString();
        traverseInorder(par->left);
        a=strcmp(formulas[first],inorderString);
        if(a==0) countValidLines++;
       
        
    }
    
    else if(!strcmp(elemProofLines[1],ORi2))
    {
       
        struct node* par=buildBinaryTree(inToPostfix(elemProofLines[0]));
        clearInorderString();
        traverseInorder(par->right);
        b=strcmp(formulas[first],inorderString);
        if(b==0) countValidLines++;
       
        
    }
    
    else if(!strcmp(elemProofLines[1],IMPe))
    {
        
        struct node* par = buildBinaryTree(inToPostfix(formulas[first]));
        clearInorderString();
        traverseInorder(par->right);
        a=strcmp(elemProofLines[0],inorderString);
        clearInorderString();
        traverseInorder(par->left);
        b=strcmp(formulas[second],inorderString);
        if(a==0&&b==0) countValidLines++;
    
    }
    
    else if(!strcmp(elemProofLines[1],MT))
    {
        struct node* par = buildBinaryTree(inToPostfix(formulas[first]));
        clearInorderString();
        traverseInorder(par->left);
        a=strcmp(elemProofLines[0],negOf(inorderString));
        clearInorderString();
        traverseInorder(par->right);
        b=strcmp(formulas[second],negOf(inorderString));
        if(a==0&&b==0) countValidLines++;
    }
    return countValidLines;
}
