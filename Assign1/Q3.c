/* CS261- Assignment 1 - Q.3*/
/* Name: 
 * Date: 
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

// Non skeleton code prototypes
int isUpper(char ch);
int isLower(char ch);
void formatString(char* str);


// Previously Provided function definitions
char toUpperCase(char ch){
  /*Convert ch to upper case, assuming it is in lower case currently*/
	return ch-32;

}

char toLowerCase(char ch){
  /*Convert ch to lower case, assuming it is in upper case currently*/                          
	return ch+32;

}

int stringLength(char s[]) {
   /*Return the length of the string*/
	int i = 0;
	for(; s[i] != '\0'; i++)
		;
	return i;
}


// Function created for better readability
void camelCase(char* word){
	/*Convert to camelCase*/

	formatString(word);
	char temp[100];
	int j =0;
	int inWord = 1;
	
	for(int i =0; i < stringLength(word); i++){
		if(word[i] == '_'){
			inWord = 0;
		}
		else if(inWord){
			temp[j++] = isLower(word[i])? word[i]: toLowerCase(word[i]);
		}
		else{
			temp[j++] = isUpper(word[i])? word[i]: toUpperCase(word[i]);
			inWord = 1;
		}
	}

	temp[j]= '\0';
	for(int i =0; i <= stringLength(temp); i++)
		word[i] = temp[i];
	
}


int isUpper(char ch){
	if('A' <= ch && 'Z' >= ch)
		return 1;
	return 0;
}


int isLower(char ch){
	if('a' <= ch && 'z' >= ch)
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
	int j =0;
	for(int i =0; i<stringLength(str) ; i++){
		if(isLetter(str[i])){
			temp[j++] = isLower(str[i]) ? str[i]: toLowerCase(str[i]);
			//temp[j++] = str[i];
			insideWord = 1;
		}

		else if(insideWord ){
			temp[j++] = '_';
			insideWord = 0;
		}
	}

	temp[j] = '\0';
	for(int i = 0; i <= j; i++)
		str[i] = temp[i];
	printf("Temp: %s\n", str);
}

int isValid(char* str){
	int firstAlpha = 0;
	int spacing = 0;
	for(int i =0; i < stringLength(str); i++){
		if(isLetter(str[i])){
			if(firstAlpha == 0) 
				firstAlpha = 1;
			else if(firstAlpha == 1 && spacing == 1)
				return 1; //Valid string of two letter groups
		}	
			else if(firstAlpha)
				spacing = 1;
	}
	return 0;
}


int main(){
	char input[100];
	/*Read the string from the keyboard*/
	printf("Please enter your words, 100 char limit\n");
	scanf("%[^\n]", input);
	printf("Here: %s\n", input);
	/*Call camelCase*/
	if(isValid(input)){
		camelCase(input);
		
		/*Print the new string*/
		printf("Camel: %s\n", input);
	}
	else{
		printf("invalid input string\n");
	}

	
	
	return 0;
}

