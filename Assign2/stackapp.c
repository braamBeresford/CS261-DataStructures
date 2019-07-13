/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
			
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

int checkParity(DynArr* stk, char strVal){
	if(topDynArr(stk) != strVal) {
		return 0;
	}
	else {
		popDynArr(stk);
		return 1;
	}
}


/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: 
	post:	
*/
int isBalanced(char* s)
{
	DynArr* stk = newDynArr(10);
	assert(stk);

	char cur;
	while((cur=nextChar(s))){
		if(cur == '[') 
			pushDynArr(stk, ']');
		else if(cur== '{'){
			pushDynArr(stk, '}');
		}
		else if(cur== '('){
			pushDynArr(stk, ')');
		}
		else if(cur == ']' || cur == '}' || cur == ')' ){
			if(isEmptyDynArr(stk)) return 0;

			if(!checkParity(stk, cur)) return 0;
		} 
		
		// else if(cur == '}' && !isEmptyDynArr(stk)){
		// 	if(!checkParity(stk, '}')) return 0;
		// }
		// else if(cur == '}'  && !isEmptyDynArr(stk)){
		// 	if(!checkParity(stk, ')')) return 0;
		// }
		
	}
	if(isEmptyDynArr(stk)) return 1;
	return 0;
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");
	// printf("%s", s);
	if(s == NULL) res = 1;
	else res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

