/* CS261- Assignment 1 - Q.2*/
/* Name:
 * Date:
 * Solution description:
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    /*Swap the addresses stored in the pointer variables a and b*/
	int * temp;
	temp = a;
	a = b;
	b = temp;
    
    /*Decrement the value of integer variable c*/
	c -= 1;

    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    
	int x, y ,z, ret_by_foo;
	srand(time(0));
	x = rand()%11;
	y = rand()%11;
	z = rand()%11;
     /*Print the values of x, y and z*/
	printf("X: %d, Y: %d, Z: %d\n", x, y, z);
   
    /*Call foo() appropriately, passing x,y,z as parameters*/
	ret_by_foo = foo(&x, &y, z);
    
    /*Print the values of x, y and z*/
	printf("X: %d, Y: %d, Z: %d\n", x, y, z);
    
    /*Print the value returned by foo*/
	printf("Value returned by foo(): %d\n", ret_by_foo);
 
    
    return 0;
}
    
    
// 4.a)
//The value returned by foo() is different from Z because 
//Z was copied (passed by value) when it was passed to foo. 
//This copy was then decremented inside of foo.  
//The return of foo copied the decremented integer 
//from the function back to main and assigned to the new variable,
//resulting in a decremented value being printed for the return value.

//4.b)
//The values of X and Y printed before and after the function
//call are the same. This is because the address of X and Y
//are passed by value into foo. Any changes to the addresses
//themselves will be discarded at the end of foo.
//These addreses can be used to do lasting changes to X and Y
//through dereferencing, although we don't do that here. 
