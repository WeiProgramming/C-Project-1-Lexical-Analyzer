/*
*Name: Wei Leung
*Prof Name: Carroll
*Class: CS570
*1/26/2017
*/
#include "getword.h"

int getword(char *w){
	int charCounter = 0; //counts number of letters
	int iochar; //variable for the char of stdin
	char* ogw; //char point variable
	ogw = w; //pointer to the original pointer *w to reference later
	
	while((iochar = getchar()) !=EOF){
		if(iochar == 32 || iochar == 10){ //checks if newline or space
			if(charCounter != 0){ //checks if counter is not zero
				if(strcmp(ogw,"logout")==0){  //compares the string referencing the beginning of the passed in char array with the string "logout" 
					*w = '\0';
					return -1; //returns -1 if it works
				}
				if(iochar == '\n'){ //puts back newline into stdin
					ungetc('\n',stdin); 
					*w = '\0'; //finishes up the current string
					return charCounter;
				}
				else{ //prints standard string 
					*w = '\0';
					return charCounter;
				}
			}
			else if(iochar == 10 && charCounter == 0){ //handles a space followed by a newline, from input1
				*w = '\0';
				return 0;
			}
		}
		else{ //places into the array
			*w = iochar;
			charCounter++;
			*w++;
		}
	}
	*w = '\0'; // handles premature EOF
	if(charCounter == 0){
		*w = '\0';
		return -1;
	}
	return charCounter;
}
