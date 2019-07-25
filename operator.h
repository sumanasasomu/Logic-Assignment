/**
 * @file operator.h
 * @author 2017A7PS0114H and 2017A7PS0262H
 * @brief This file has the functions to check if an operator is unary or binary
 * 
 */

#ifndef OPERATOR_H
#define OPERATOR_H
/**
 *  @brief A function to check is it is a unary operator.
 * 
 * @param Operator this is the operator to be found if is unary or not.
 * @return 1 if it is unary else 0.
 */
int isUnary(char Operator){
    if(Operator=='~')
        return 1;
    return 0;
}
/**
 * @brief A function to check is it is a binary operator.
 * 
 * @param Operator this is the operator to be found if is binary or not.
 * @return 1 if it is binary else 0.
 */
int isBinary(char Operator){
    if(Operator=='^'||Operator=='V'||Operator=='>')
        return 1;
    return 0;
}

#endif /* OPERATOR_H */
