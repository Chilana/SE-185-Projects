/*----------------------------------------------------------------------------
-     SE 185: Lab 03 - Introduction to the DS4 and Functions       -
- Name:
 -
-  Section:
 -
- NetID:
     -
- Date:
 -
-----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
- Includes
 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
/*----------------------------------------------------------------------------
-                             Prototypes                                   -
-----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
-                                 Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab03-2.c -o lab03-2
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -b | ./lab03-2
/*----------------------------------------------------------------------------
- Implementation
 -
-----------------------------------------------------------------------------*/
int butcounter(int number1, int number2, int number3, int number4);
int main(int argc, char *argv[])
{
	int controlbut1;
	int controlbut2;
	int controlbut3;
	int controlbut4;
	
    while (1)
    {
		scanf("%d, %d, %d, %d", &controlbut1, & controlbut2, &controlbut3, &controlbut4);
		printf("The number of buttons presseed is %d \n", butcounter(controlbut1, controlbut2, controlbut3, controlbut4));
        fflush(stdout);
	}
	
    return 0;
}
/* Put your functions here, and be sure to put prototypes above. */

int butcounter(int number1, int number2, int number3, int number4){
	
	return number1 + number2 + number3 + number4;
	
}