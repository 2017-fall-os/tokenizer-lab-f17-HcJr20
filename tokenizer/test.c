#include <sys/types.h>		/* for lseek, read */
#include <unistd.h>		/* for lseek, read */
#include <sys/stat.h>		/* for read */
#include <fcntl.h>		/* for read */
#include <stdlib.h>		/* for malloc */
#include <stdio.h>
#include "tokenizer.h"

 

int main(){
  int run = 1;
  char* exit = "exit";
  char* string[100];
  // make program exit by typing exit
  while(run){

    
    write(1, "$ ", 2);
    read(0, string, sizeof string);

    for(int i = 0; string[i] != 0; i++){
      if(string[i] == '\n'){
	string[i] = '\0';
	}
    } 

       char ** token = mytoc(string , ' ');
       

       for(int i = 0; i < getVectorSize(); i++){
	  free(token[i]);
       }

       free(token);

       

       setTrackers(0);
  }
    return 0;
}

   
  
