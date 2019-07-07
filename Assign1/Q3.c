/* CS261- Assignment 1 - Q.3*/
/* Name: 
 * Date: 
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>


int isUpper(char ch){
	if('A' <= ch || 'Z' >= ch)
		return 1;
	return 0;
}


int isLower(char ch){
	if('a' <= ch || 'z' >= ch)
		return 1;
	return 0;
}

int isLetter(char ch){
	if(isLower(ch) || isUpper(ch)) return 1;
	return 0;
}

void formatString(char* str){	
	char temp[100];

	int insideWord = 0;
	int firstWord = 1;
	int firstAlpha = 1;
	int j =0;
	for(int i =0; str[i] != '\0'; i++){
		if(isLetter(str[i])){
			if(firstWord){
				if(isUpper(str[i])) temp[j++] = toLowerCase(str[i]);
				else temp[j++] = str[i];
				firstWord = 0;
				firstAlpha = 0;
			}
			else if(firstAlpha){
				firstAlpha = 0;
				if(isLower(str[i])) temp[j++] = toUpperCase(str[i]);
				else temp[j++] = str[i];
			}
			else{
				if(isUpper(str[i])) temp[j++] = toLowerCase(str[i]);
				else temp[j++] = str[i];
			}
		}
	}
}

int isValid(char* str){
	int firstAlpha = 0;
	int spacing = 0;
	for(int i =0; str[i] != '\0'; i++){
		if(isLetter(str[i])){
			if(firstAlpha == 0) 
				firstAlpha = 1;
			else if(firstAlpha == 1 && spacing == 1)
				return 1; //Valid string of two letter groups
		}
		if(firstAlpha)
			spacing = 1;
	}
	return 0;
}

char toUpperCase(char ch){
  /*Convert ch to upper case, assuming it is in lower case currently*/

}

char toLowerCase(char ch){
  /*Convert ch to lower case, assuming it is in upper case currently*/                          

}

int stringLength(char s[]) {
   /*Return the length of the string*/
}


void camelCase(char* word){
	/*Convert to camelCase*/
	
	
}

int main(){
	char input[100];
	/*Read the string from the keyboard*/
	
	
	/*Call camelCase*/
	
	
	/*Print the new string*/
	
	
	return 0;
}

