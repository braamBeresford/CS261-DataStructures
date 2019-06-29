/* CS261- Assignment 1 - Q.1*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student * temp = malloc(10 * sizeof(struct student));
     
     /*Return the pointer*/
     return temp;
}

void generate(struct student* students){
     /*Generate random and unique IDs and random scores for ten students, 
IDs being between 1 and 10, scores between 0 and 100*/
	int ids[10] = {1,2,3,4,5,6,7,8,9,10};
	int i, j, temp;
	srand(time(0));

	//Use the Fisher-Yates shuffle
	for(i = 9; i > 0; i-= 1){
		j = rand()%(i+1);
		temp = ids[i];
		ids[i] = ids[j];
		ids[j] = temp;
	}
	
	for(i = 0; i < 9; i++){
		students[i].id = ids[i];
		students[i].score = rand()%101;
	}
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/


	int i;
	for(i = 0; i < 9; i+= 1){
		printf("ID%d Score%d \n", students[i].id, students[i].score);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the 
ten students*/
     
	int i, min=0, max=0, avg_temp=0;

	for(i = 0; i < 9; i += 1){
		min = min > students[i].score ? students[i].score : min;

		max = max < students[i].score ? students[i].score : max;

		avg_temp += students[i].score;
	}

	float avg = avg_temp/10;
	printf("Min: %d  Max: %d  Average:%f\n", min, max, avg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/

	if(stud != 0)
		free(stud);
	else
		printf("Error freeing memory!");
}

int main(){
    struct student* stud = NULL;
    
    /*Call allocate*/
    stud = allocate();
    
    /*Call generate*/
    generate(stud);

    /*Call output*/
    output(stud);
    
    /*Call summary*/
    summary(stud);
    
    /*Call deallocate*/
    deallocate(stud);

    return 0;
}

