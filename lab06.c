
/*----------------------------------------------------------------------------
-                     SE 185: Lab 06 - Bop-It!                   -
- Name: cHILANA aMARATUNGA
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
#include <stdlib.h>
#include <time.h>
/*----------------------------------------------------------------------------
-                             Prototypes                                   -
-----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
-                             Notes                                        -
-----------------------------------------------------------------------------*/
// Compile with gcc lab06.c -o lab06
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b | ./lab06
/*----------------------------------------------------------------------------
- Implementation
 -
-----------------------------------------------------------------------------*/
int playgame();
int main(int argc, char *argv[])
{
	int t;
	int triangle, circle, cross, square =  0;
    srand(time(NULL)); /* This will ensure a random game each time. */
	printf("This is a Bop-it Game!\n");
	printf("Press Circle to being");
    while(1){
	fflush(stdout);
		scanf("%d, %d, %d, %d, %d", &t, &triangle, &circle, &cross, &square);
		int start = circle;
		if(circle == 1){
			playgame();
		}
		}
		printf("You got %d point", playgame());


    return 0;
}
/* Put your functions here, and be sure to put prototypes above. */
int playgame(){
	
	int t, guess, counter;
	int timer = 2500;
	int triangle, circle, cross, square =  0;
	while(1){
		scanf("%d, %d, %d, %d, %d", &t, &triangle, &circle, &cross, &square);
		guess = rand() % 4 + 1;
		if(guess = 1){
			printf("Enter Triangle and you have %d seconds", timer);
			if(triangle = 1){
				counter++;
				timer -= timer - (t % 1000);
			}else if(cross = 1 || square = 1 || circle = 1)
			{
				break;
			}
		}
		if(guess = 2){
			printf("Enter Circle and you have %d seconds", timer);
			if(circle = 1){
				counter++;
				timer -= timer - (t % 1000);
			}else if(cross = 1 || triangle = 1 || square = 1)
			{
				break;
			}
		}
		if(guess = 3){
			printf("Enter X and you have %d seconds", timer);
			if(cross = 1){
				counter++;
				timer -= timer - (t % 1000);
			}else if(square = 1 || triangle = 1 || circle = 1)
			{
				break;
			}
		}			
		if(guess = 4){
			printf("Enter square and you have %d seconds", timer);
			if(square = 1){
				counter++;
				timer -= timer - (t % 1000);
			}else if(cross = 1 || triangle = 1 || circle = 1)
			{
				break;
			}
		}
		if(timer < 0){
			break;
		}
	}
	printf("%d", counter);
	return counter;
}	
			