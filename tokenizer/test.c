#include <sys/types.h>		/* for lseek, read */
#include <unistd.h>		/* for lseek, read */
#include <sys/stat.h>		/* for read */
#include <fcntl.h>		/* for read */
#include <stdlib.h>		/* for malloc */
#include <stdio.h>
#include "tokenizer.h"

// compare to check for exit
int checkExit(char* str, char* exit){
  int exitEnabled = 1;
  for(int i = 0; str[i] != 0; i++){
    if(str[i] != exit[i]){
      exitEnabled = 0;
    }
  }

  return exitEnabled;
}

int main(){
  int run = 1;
  char* exit = "exit";
  char* string[100];
  // make program exit by typing exit
  while(run){

    // take user input
    write(1, "$ ", 2);
    read(0, string, sizeof string);

    // add 0 char in the end
    for(int i = 0; string[i] != 0; i++){
      if(string[i] == '\n'){
	string[i] = '\0';
	}
    }
    // check if exit entered
     if(checkExit(string, exit)){
      break;
    }   
     // build tokenizer
     char ** token = mytoc(string , ' ');
       
     // free up the space
       for(int i = 0; i < getVectorSize(); i++){
	  free(token[i]);
       }

       free(token);

       // reset globals in tokenizer.c
       setTrackers(0);
  }
    return 0;
}

   
  
