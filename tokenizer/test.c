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
  // make program exit by typing exit
  while(run){

    char *string = malloc(sizeof(100));

    write(1, "$ ", 2);
    read(0, string, 100);
    
    char ** token = mytoc(string , ' ');

   

    // free memory allocated
  }
  return 0;
}
