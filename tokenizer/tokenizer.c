#include <sys/types.h>		/* for lseek, read */
#include <unistd.h>		/* for lseek, read */
#include <sys/stat.h>		/* for read */
#include <fcntl.h>
#include <stdlib.h>		/* for malloc */
#include <stdio.h>
#include "tokenizer.h"

int tracker = 0;
int atracker = 0;
int wordCount = 0;

void setTrackers(int i){
 tracker = i;
 atracker = i;
}
int getVectorSize(){
  return wordCount + 1;
}
 
char* stringcpy(char* tokenVec, char* str, char delim){
  
  int tvIndex = 0;
  int found = 0;
  int previous = 0;

  while(str[atracker] != 0){

    if(str[atracker] == ' ' && found){
     
      tokenVec[tvIndex] = (char*)0;
      atracker++;
      
      return tokenVec;
    }
     
    if( (str[atracker] == '0') && found){
      tokenVec[tvIndex] = (char*)0;
       atracker ++;
       
	return tokenVec;
    }
    if(str[tracker] == ' ' && !found){
      continue;
    }
    if(str[atracker] != ' '){
      tokenVec[tvIndex] = str[atracker];
      tvIndex++;
      found = 1;
    }
    atracker++;
  }
  tvIndex++;
  tokenVec[tvIndex] = (char*)0;
  
  return tokenVec;
}

int letterCount(char* str, char delim){


  int count = 0;
  int found = 0;
  

  
  while(str[tracker] != 0){
    if(str[tracker] == ' ' && found){
      printf("count: %d \n", count);
      tracker++;
      return count;
    }
    if( (str[tracker] == '0') && found){
       printf("count: %d \n", count);
       tracker++;
      return count;
    }
    if(str[tracker] != ' '){
      count ++;
      found = 1;
    }
    tracker++;
  }
  
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
 
     wordCount = count(str, delim);
   
    // allocate memory for 2D vector
  
     char**  tokenVec =(char**) calloc(wordCount + 1, sizeof(char*));

     int word[wordCount];
     
     for(int i = 0; i < wordCount + 1; i++){
        if(i != wordCount){
	  word[i] = letterCount(str, delim) +1;
	  tokenVec[i] = (char*) malloc(sizeof(word[i]));
	  }
	else{
	 tokenVec[i] = (char *)0;
       }
     }
  
     for(int i = 0; i < wordCount + 1; i++){
       if(i != wordCount){
	 tokenVec[i] = stringcpy(tokenVec[i], str, delim);
	 write(1, tokenVec[i], word[i]);
	 write(1, "\n", 1);
       }
       else{
	 tokenVec[i] = (char*)0;
       }
     }
     return tokenVec;
}
