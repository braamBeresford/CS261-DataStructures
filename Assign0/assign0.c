/***********************************************************
 * Author:                      Braam Beresford
 * Date Created:                06/24/2019
 * Last Modification Date:      06/27/2019
 * Filename:                    main.c
 *
 * Overview:
 *      This program will read in hard coded variables and use them to calculate the area
 *      are of a triangle using Heron's Formula. The result is then stored to a local 
 *      variavle and then printed to the terminal. 
 * Input:
 * 	No inputs.
 * Output:
 * 	The calculated area of the triangle is printed to the screen. 
 ************************************************************/

#include <stdio.h>
#include <math.h>

int main(){

	// Base vairables for triangle dimension. 
	double a, b, c;

	//Variables used during area calculation.
	double s, temp;

	//Total area;
	double area;

	//Pre-defined triangle dimensions
	a = 3;
	b = 4;
	c = 5;
	
	//Heron's formula sqrt(s(s-a)(s-b)(s-c))
	s = (a+b+c)/2;
	temp = (s)*(s-a)*(s-b)*(s-c);
	area = sqrt(temp);
	
	//Print resulting area.
	printf("The area is: %g\n", area);
	
	return 0;
}
