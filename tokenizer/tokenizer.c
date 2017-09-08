#include <stdlib.h>		/* for malloc */
#include <stdio.h>
#include "tokenizer.h"

int tracker = 0;

void setIndex(int i){
  tracker = i;
}
char* stringcpy(char* str, char delim){
  printf("You are in stringcpy \n");
}

int letterCount(char* str, char delim){
  printf("You are in letter count \n");
  while(str[tracker] == ' '){
    tracker++;
  }
  int letterCount = 0;
  while(str[tracker] != ' '){
    letterCount++;
    tracker++;
  }
   printf("letter count: %d \n", letterCount);

   return letterCount;
}

int count(char* str, char delim){
 
  int count = 0;
  int wordFound = 0;
  for(int i = 0; str[i] != NULL; i++){
    if( (str[i] == ' ' || str[i] == '\n') && wordFound){
	printf(" Found white space \n");
	count ++;
	wordFound = 0;
      }
    else if(str[i] != ' '){
      printf("found character \n");
      wordFound = 1;
    }
  }
   printf("Number of words: %d \n", count);
   return count;
}
  char** mytoc(char* str, char delim){
    printf("You are in mytovc \n");   
    int wordCount = count(str, delim);
    
    // allocate memory for 2D vector
    /*  char**  tokenVec =(char**) calloc(wordCount + 1, sizeof(char*));
    for(int i = 0; i < wordCount + 1; i++){
     tokenVec[i] = (char*) malloc(letterCount(str, delim));  
    }

    //copy strings into vector
    for(int i = 0; i < wordCount + 1; i++){

    }
*/
  }
