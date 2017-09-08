#include <stdlib.h>		/* for malloc */
#include <stdio.h>
#include "tokenizer.h"

int tracker = 0;
int atracker = 0;

void setIndex(int i){
  tracker = i;
}
 
char* stringcpy(char* tokenVec, char* str, char delim){
  
  int tvIndex = 0;
  int found = 0;

  while(str[atracker] != 0){

    if(str[atracker] == ' ' && found){
     
      tokenVec[tvIndex] = (char*)0;
      atracker++;
      printf("return 1 \n");
      return tokenVec;
    }
     
    if( (str[atracker] == '\n' || str[atracker] == '0') && found){
      tokenVec[tvIndex] = (char*)0;
       atracker ++;
       printf("return 2 \n");
	return tokenVec;
    }
    if(str[atracker] != ' ' || str[atracker] != '\n' || str[atracker] != '0'){
      tokenVec[tvIndex] = str[atracker];
      tvIndex++;
      found = 1;
    }
    atracker++;
  }
  tvIndex++;
  tokenVec[tvIndex] = (char*)0;
  printf("return 3 \n");
  return tokenVec;
}

int letterCount(char* str, char delim){
  printf("You are in letter count \n");


  int count = 0;
  printf("%s \n", str);
  int found = 0;
  

  
  while(str[tracker] != 0){
    printf("tracker:str[%d] = %c  \n", tracker, str[tracker]);
    if(str[tracker] == ' ' && found){
      printf("count: %d \n", count);
      tracker++;
      return count;
    }
    if( (str[tracker] == '\n' || str[tracker] == '0') && found){
       printf("count: %d \n", count);
       tracker++;
      return count;
    }
    if(str[tracker] != ' ' || str[tracker] == '\n' || str[tracker] == '0'){
      count ++;
      found = 1;
    }
    tracker++;
  }
  printf("count: %d \n", count);
  return count;
}

int count(char* str, char delim){
 
  int count = 0;
  int wordFound = 0;
  int previous = 1; // 1 for space

  for(int i = 0; str[i] != 0; i++){
    if( str[i] != ' ' && previous == 1){
	count ++;
      }
    if(str[i] == ' ' && previous == 0){ 
    }
    if(str[i] == ' '){
      previous = 1;
    }
    else{
      previous = 0;
    }
  }
   
   return count;
}
  char** mytoc(char* str, char delim){
    printf("in my toc \n");
    int wordCount = count(str, delim);
    printf(" Word Count: %d \n", wordCount);
    

    // allocate memory for 2D vector
     char**  tokenVec =(char**) calloc(wordCount + 1, sizeof(char*));
     for(int i = 0; i < wordCount + 1; i++){
        if(i != wordCount){
	  tokenVec[i] = (char*) malloc(sizeof(letterCount(str, delim) + 1));
       }
	else{
	 tokenVec[i] = (char *)0;
       }
     }
     
     for(int i = 0; i < wordCount + 1; i++){
       if(i != wordCount){
	 tokenVec[i] = stringcpy(tokenVec[i], str, delim);
	 printf("This is the token at index %d : %s \n", i, tokenVec[i]);
       }
       else{
	 tokenVec[i] = (char*)0;
	 printf("This is the token at index %d : %s \n", i, tokenVec[i]);
       }
     }

  }
