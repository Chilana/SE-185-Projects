// Lab 09 DS4Talker Skeleton Code      
// Lab09 

// Question 1. Describe how you keep track of the word selected on the screen and how this interfaces with the DualShock 4. Is the interface reasonable?
// I keep track of the word selected on the screen by tracking the cursur implented by calling draw character.In addition I am using the previous value of the position pos defined in the start of the code as the birthplace of the cursur and then I increment the value of the previous position by 1(pseudo code: previous_Value++). I then calculate the length of the pre-populated word in the text file and then increment the previous positon by that length. (pseudo code: previous_Value += (mycalculatedlength(wordlist[k]))). This interfaces with dualshock 4 via mvprintw function from the ncurses library. The interface is not reasonable because it depends on how the user opens up the cgwin console and it also tends to unsynchronize when the user resizes the window or changes the window attributes. 

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#define WORDLENGTH 11
#define MAXWORDS 100
#define DEBUGM 1   // Set this to 0 to disable debug output

// Reads words from the file into WL and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int read_words(char* WL[MAXWORDS], char* file_name);

// modifies str to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* str);

void draw_character(int x, int y, char use);
int mycalculatedlength(char numchars[80]);


// --------------------------------------------------------------------------------------------- \\

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordcount;
	wordcount = read_words(wordlist, argv[1]);
    initscr();
    refresh();
    int val = 0, cursur = 7, previous_Value = 0, k = 0, b[1000], quitter = 0, pos = 30;
    int xButton, mycircle, mytriangle, i, myleftJoyX, myleftJoyY ,mytimewatcher, mysquare, myrightJoyX, myrightJoyY;
    mvprintw(28,0, "Your sentence:");
    while(quitter == 0)
    {
        scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
        for (i = 0; i < 19; i++){
			//The initial birth place of the blinking cursur 
            mvprintw(pos,previous_Value, "_");
            mvprintw(i,0, "%s", wordlist[i]);
            refresh();
            }
        for (i = 19; i < 38; i++){
            mvprintw((i-19),15, "%s", wordlist[i]);
            refresh();
            }
        for (i = 38; i < 57; i++){
            mvprintw((i-38),30, "%s", wordlist[i]);
            refresh();
            }
        for (i = 57; i < 76; i++){
            mvprintw((i-57),45, "%s", wordlist[i]);
            refresh();
            }
			// I keep track of the word selected on the screen by tracking the cursur implented in the next line on draw character
            draw_character(cursur, k, '<');
        if (myleftJoyY > 125){
            k++;
            draw_character(cursur, (k-1), ' ');
            if ((k == 19) && (myleftJoyY > 125)) {
                cursur += 15;
                k = 0;
                }
            if (cursur > 52) {
                cursur = 7;
            }
            while (myleftJoyY > 10) {
                    scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
            }
            }
        if (myleftJoyY < -125){
                k--;
                draw_character(cursur, (k+1), ' ');
            if ((k < 0) && (cursur == 7) && (myleftJoyY < -125)) {
                cursur = 52;
                k = 18;
                }
            if ((k < 0) && (cursur != 7) && (myleftJoyY < -125)) {
                cursur -= 15;
                k = 18;
                }
            while (myleftJoyY < -10) {
                    scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
            }
        }
        if (myleftJoyX > 120) {
            cursur += 15;
            draw_character((cursur-15), k, ' ');
            if (cursur > 52) {
                cursur = 7;
            }
            while (myleftJoyX > 10) {
                    scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
            }
        }
        if (myleftJoyX < -120) {
            cursur -= 15;
            draw_character((cursur+15), k, ' ');
            if (cursur < 7) {
                cursur = 52;
            }
            while (myleftJoyX < -10) {
                    scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
            }
        }
		
		if (mycircle == 1) {
            if (cursur == 7) {
                mvprintw(pos,previous_Value, "%s", wordlist[k]);
                previous_Value += (mycalculatedlength(wordlist[k]));
                b[val] = (mycalculatedlength(wordlist[k]));
                val++;
                while (mycircle == 1) {
                    scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
            }
            }
            if (cursur == 22) {
                mvprintw(pos,previous_Value, "%s", wordlist[(k+19)]);
                previous_Value += (mycalculatedlength(wordlist[k+19]));
                b[val] = (mycalculatedlength(wordlist[k+19]));
                val++;
                while (mycircle == 1) {
                    scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
            }
            }
            if (cursur == 37) {
                mvprintw(pos,previous_Value, "%s", wordlist[(k+38)]);
                previous_Value += (mycalculatedlength(wordlist[k+38]));
                b[val] = (mycalculatedlength(wordlist[k+38]));
                val++;
                while (mycircle == 1) {
                    scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
            }
            }
            if (cursur == 52) {
                mvprintw(pos,previous_Value, "%s", wordlist[(k+57)]);
                previous_Value += (mycalculatedlength(wordlist[k+57]));
                b[val] = (mycalculatedlength(wordlist[k+57]));
                val++;
                while (mycircle == 1) {
                    scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
            }
            }
        }

        if (mysquare == 1) {
            if (cursur == 7) {
                mvprintw(pos,previous_Value, "%s", wordlist[k]);
                previous_Value += (mycalculatedlength(wordlist[k]));
                b[val] = (mycalculatedlength(wordlist[k]));
                val++;
                while (mysquare == 1) {
                    scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
            }
            }
            if (cursur == 22) {
                mvprintw(pos,previous_Value, "%s", wordlist[(k+19)]);
                previous_Value += (mycalculatedlength(wordlist[k+19]));
                b[val] = (mycalculatedlength(wordlist[k+19]));
                val++;
                while (mysquare == 1) {
                    scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
            }
            }
            if (cursur == 37) {
                mvprintw(pos,previous_Value, "%s", wordlist[(k+38)]);
                previous_Value += (mycalculatedlength(wordlist[k+38]));
                b[val] = (mycalculatedlength(wordlist[k+38]));
                val++;
                while (mysquare == 1) {
                    scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
            }
            }
            if (cursur == 52) {
                mvprintw(pos,previous_Value, "%s", wordlist[(k+57)]);
                previous_Value += (mycalculatedlength(wordlist[k+57]));
                b[val] = (mycalculatedlength(wordlist[k+57]));
                val++;
                while (mysquare == 1) {
                    scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
            }
            }
        }
		
		
		if (mytriangle == 1) {
			
            if (cursur == 7) {
                mvprintw(pos,previous_Value, " ");
                previous_Value++;
                mvprintw(pos,previous_Value, "%s", wordlist[k]);
                previous_Value += (mycalculatedlength(wordlist[k]));
                b[val] = (mycalculatedlength(wordlist[k]));
                val++;
                while (mytriangle == 1) {
                    scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
            }
            }
            if (cursur == 22) {
                mvprintw(pos,previous_Value, " ");
                previous_Value++;
                mvprintw(pos,previous_Value, "%s", wordlist[(k+19)]);
                previous_Value += (mycalculatedlength(wordlist[k+19]));
                b[val] = (mycalculatedlength(wordlist[k+19]));
                val++;
                while (mytriangle == 1) {
                    scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
            }
            }
            if (cursur == 37) {
                mvprintw(pos,previous_Value, " ");
                previous_Value++;
                mvprintw(pos,previous_Value, "%s", wordlist[(k+38)]);
                previous_Value += (mycalculatedlength(wordlist[k+38]));
                b[val] = (mycalculatedlength(wordlist[k+38]));
                val++;
                while (mytriangle == 1) {
                    scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
            }
            }
            if (cursur == 52) {
                mvprintw(pos,previous_Value, " ");
                previous_Value++;
                mvprintw(pos,previous_Value, "%s", wordlist[(k+57)]);
                previous_Value += (mycalculatedlength(wordlist[k+57]));
                b[val] = (mycalculatedlength(wordlist[k+57]));
                val++;
                while (mytriangle == 1) {
                    scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
            }
            }
        }
		
		

        if (previous_Value > 80) {
            pos++;
            previous_Value = 0;
        }
        if (previous_Value < 0) {
            previous_Value = 0;
        }
        if (xButton == 1) {
            val--;
            if (b[val] == 1) {
                    mvprintw(pos,previous_Value, " ");
                    previous_Value--;
                    while (xButton == 1) {
                        scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
                }
            }
            if (b[val] != 1) {
                for (i = 0; i < (b[val] + 1); i++) {
                    mvprintw(pos,previous_Value, " ");
                    previous_Value--;
                    while (xButton == 1) {
                        scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d", &mytimewatcher, &mytriangle, &mycircle, &xButton, &mysquare, &myleftJoyX, &myleftJoyY, &myrightJoyX, &myrightJoyY);
                    }
                }
            }
    }
        
    }
	// most of your code goes here. Do not forget to include the ncurses library 
	endwin();
	return 0;
}



// DO NOT MODIFY THIS FUNCTION!
int read_words(char* WL[MAXWORDS], char* file_name)
{
	int numread = 0;
	char line[WORDLENGTH];
	char *p;
	FILE* fp = fopen(file_name, "r");
	while (!feof(fp)) {
		p = fgets(line, WORDLENGTH, fp);
		if (p != NULL) 
		{
			trimws(line);
			WL[numread] = (char *)malloc(strlen(line) + 1);
			strcpy(WL[numread], line);
			numread++;
		}
	}
	fclose(fp);
	return numread;
}



// DO NOT MODIFY THIS FUNCTION!
void trimws(char* str) {
	int length = strlen(str);
	int x;
	if (length == 0) return;
	x = length - 1;
	while (isspace(str[x]) && (x >= 0)) {
		str[x] = '\0';
		x -= 1;
	}
}

void draw_character(int x, int y, char use) {
	mvprintw(y, x, "%c", use);
	refresh();
	return;
}

int mycalculatedlength(char numchars[80]) {
	int val = strlen(numchars);
	return val;
}
