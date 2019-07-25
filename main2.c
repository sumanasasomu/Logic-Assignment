/**
 * @file main2.c
 *
 * @brief This file has a program to check the validity of the proof
 * 
 * It asks for the no.of lines in the proof and asks the user to enter the 
 * proof lines in order and finally tells if the proof is valid or invalid
 * 
 * @author 2017A7PS0114H and 2017A7PS0262H
 * @note The symbols for operations are ~ NEGATION, ^ AND, V OR, > IMPLICATION
 * 
 */

#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "operator.h"
#include "rules.h"
#include<stdio.h>


int main()
{
    int noOfLines;
    char proofLine[100];
    int valid_lines;
    printf("no of lines : ");
    scanf("%d",&noOfLines);
    for(int i=0;i<noOfLines;i++)
    {
        printf("enter the line %d of proof : ",i+1);
        scanf("%s",proofLine);
        splitProofLine(proofLine);
        valid_lines = proofRuleCheck(); 
    }
        if(valid_lines==noOfLines) printf("Valid Proof\n");
        else printf("Invalid Proof\n");

        return 0;
        
}




