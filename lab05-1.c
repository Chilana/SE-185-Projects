/*----------------------------------------------------------------------------
-          SE 185: Lab 05 - Conditionals (What's up?)               -
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
 
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include<stdbool.h>
/*----------------------------------------------------------------------------
-                             Prototypes                                   -
-----------------------------------------------------------------------------*/
double magnitude(double ax, double ay, double az);
int close_to(double tolerance, double point, double value);
double side(double gx, double gy, double gz);
/*----------------------------------------------------------------------------
-                                 Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab05.c -o lab05
// Run with ./ds4rd.exe -d 054c:09cc(05c4) -D DS4_BT -a -g -b | ./lab05
/*----------------------------------------------------------------------------
- Implementation
 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int triangle, circle, x_button, square;
    double ax, ay, az, gx, gy, gz;
	double compMagnitude;
    while (triangle != 1)
    {
        scanf("%lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d",
              &ax, &ay, &az, &gx, &gy, &gz, &triangle, &circle, &x_button, &square);
        /* printf for observing values scanned in from ds4rd.exe,
         * be sure to comment or remove in final program */
        //printf("Echoing output: %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n",
          //     ax, ay, az, gx, gy, gz, triangle, circle, x_button, square);
        /* It would be wise (mainly save time) if you copy your code to calculate
         * the magnitude from lab03-1.c. You will also need to copy your
         * prototypes and functions to the appropriate sections in this program. */
        //printf("The acceleration's current magnitude is: %lf\n", magnitude(ax, ay, az));
		if (close_to(.009, compMagnitude, magnitude(ax, ay, az))){
			side(gx, gy, gz);
		}
		compMagnitude = magnitude(ax, ay, az);
    }
    		

	return 0;
	
}
/* Put your functions here, and be sure to put prototypes above. */
double magnitude(double ax, double ay, double az){
    // Step 8, uncomment and modify the next line
     return sqrt(pow(ax,2) + pow(ay,2) + pow(az,2));

}
int close_to(double tolerance, double point, double value){
	int bothPlus = tolerance + point;
    int bothMinus = point - tolerance;
    if (value >= bothMinus && value <= bothPlus){
        return true;
	}
    else{
        return false;
	}
}	
double side(double gx, double gy, double gz){
	if(close_to(.1, 1, gy)){
		printf("Top\n");
	}else if (close_to(.15, -1, gy)){
		printf("Bottom\n");
	}else if(close_to(.3, -1, gx)){
		printf("Left\n");
	}else if(close_to(.3, 1, gx)){
		printf("Right\n");
	}else if(close_to(.3, -1, gz)){
		printf("Front\n");
	}else if(close_to(.3, 1, gz)){
		printf("Back\n");
	}
}