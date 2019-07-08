/* CS261- Assignment 1 - Q. 0*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr){
  
     /*Print the value and address of the integer pointed to by iptr*/
    printf("The value of iptr is: %d  The address that iptr points to is: %p\n", *iptr, iptr);

     /*Increment the value of the integer pointed to by iptr by 5*/
    (*iptr) += 5;

     /*Print the address of iptr itself*/
     printf("The address of iptr itself is: %p\n", &iptr);

    /*Dummy variable, ignore the warning*/
   int c=5;  
}


void fooB(int* jptr){
  
     /*Print the value and address of the integer pointed to by jptr*/
    printf("The value of jptr is: %d  The address that jptr points to is: %p\n", *jptr, jptr);


     /*Decrement the address by 1 pointed to by jptr using jptr */
     jptr -= 1;
      
     /*Print the address of jptr itself*/
    printf("The address of jptr itself is: %p\n", &jptr);

}


int main(){   
    /*Declare an integer x and initialize it randomly to a value in [0,10] 
*/
    //Seed the random
    srand(time(0)); 

    int x = rand()%10;
    
    /*Print the value and address of x*/
    printf("The value of X is %d\n", x);
    printf("The address of X is %p\n", &x);
    
    /*Call fooA() with the address of x*/
    fooA(&x);

    /*Print the value of x*/
    printf("The value of X after fooA is: %d\n", x);
    //The value of X is different as we passed the address (pointer)
    //of the variable. FooA then could access the data that is pointed to.
    //This means that FooA recieves a copy of the address but actually acesses
    //the value of X in memory. 
    
    /*Call fooB() with the address of x*/
    fooB(&x);

    /*Print the value and address of x*/
    printf("The value of X after fooB is: %d ", x);
    printf("The address of X is: %p \n", &x);
    //The value of X is the same as before as we did no attempt to manipulate it
    //in the function. The address remains the same as well as we only manipulated
    //a copy of the pointer in fooB which is discarded when the function collapses.  

    
    return 0;
}


