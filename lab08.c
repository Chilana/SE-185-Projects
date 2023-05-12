/*-----------------------------------------------------------------------------
-    SE 185 Lab 08
-             Developed for 185-Rursch by T.Tran and K.Wang
- Name:
-  Section:
- NetID:
- Date:
-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
- Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<ncurses.h>
/*-----------------------------------------------------------------------------
- Defines
-----------------------------------------------------------------------------*/
#define MAXPOINTS 10000
/*-----------------------------------------------------------------------------
- Prototypes
-----------------------------------------------------------------------------*/
/* Updates the buffer with the new_item and returns the computed
moving average of the updated buffer */
double m_avg(double buffer[], int avg_size, double new_item);
void draw_character(int x, int y, char use);
double roll(double xMag);
/*-----------------------------------------------------------------------------
- Implementation
-----------------------------------------------------------------------------*/
int main(int argc, char* argv[]) {
    /* DO NOT CHANGE THIS PART OF THE CODE */
    double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
    double new_x, new_y, new_z;
    double avg_x, avg_y, avg_z;
    int lengthofavg = 0;
	int i;
	int time, bT, bC, bX, bS;
	double Xg, Yg, Zg;
    if (argc > 1) {
        sscanf(argv[1], "%d", &lengthofavg );
        printf("You entered a buffer length of %d\n", lengthofavg);
    }
    else {
        printf("Enter a length on the command line\n");
        return -1;
    }
    if (lengthofavg < 1 || lengthofavg > MAXPOINTS) {
        printf("Invalid length\n");
        return -1;
    }
    for(i = 0; i < lengthofavg; i++)
    {
        scanf("%lf, %lf, %lf", &new_x, &new_y, &new_z);
        x[i] = new_x;
        y[i] = new_y;
        z[i] = new_z;
    }
    do{
	
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &time, &Xg, &Yg, &Zg, &bT, &bC, &bX, &bS);
	
		avg_x = m_avg(x, lengthofavg, new_x);
        avg_y = m_avg(y, lengthofavg, new_y);
        avg_z = m_avg(z, lengthofavg, new_z);
		//printf(" X %lf, Y %lf, Z %lf Ave X %lf, min_X: %lf, max_X: %lf y_Avg: %lf, min_Y: %lf, max_Y: %lf z_Avg: %lf, min_Z: %lf, max_Z: %lf\n", Xg, Yg, Zg, x_Avg, x_Min, x_Max, y_Avg, y_Min, y_Max, z_Avg, z_Min, z_Max);
		draw_character((int) avg_x,(int) avg_y, 'A');
        draw_character(avg_x, avg_y - 1,' ');
        if (roll(Xg) == 1){
			avg_x = avg_x + 1;
		}
		if(roll(Xg) == -1){
			avg_x = avg_x - 1;
		}
		fflush(stdout);
	}
	while (bS == 0);
	/*while(1)
    {
        scanf("%lf, %lf, %lf", &new_x, &new_y, &new_z);
        avg_x = m_avg(x, lengthofavg, new_x);
        avg_y = m_avg(y, lengthofavg, new_y);
        avg_z = m_avg(z, lengthofavg, new_z);
        printf("RAW, %lf, %lf, %lf, AVG ,%lf, %lf, %lf\n", new_x, new_y, new_z, 
avg_x, avg_y, avg_z);
        fflush(stdout);
    }*/
}
double m_avg(double buffer[], int avg_size, double new_item)
{
    int i;
	int sum;
	int counter = 0;
	for(i = 0; i < avg_size; i++){
		buffer[i + 1] = buffer[i];
	}
	buffer[0] = new_item;
	for(i = 0; i < avg_size; i++){
		sum += buffer[1];
		counter ++;
	}
	return sum / counter;
}
void draw_character(int x, int y, char use)
{
    x = abs(x);
	y = abs(y);
	mvaddch(y,x,use);
    refresh();
}
double roll(double xMag){
	if(xMag >= 1.0){
		xMag = 1.0;
	}else if(xMag <= -1.0){
		xMag = -1.0;
	}
	
	return xMag;
}