/*decrypt.c
 *
 *Created on: June 28
 *Authort: Sam Essenburg
 *
 * CIS361: Project 1
 *
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shift.h"

char shift(char, int);

int main(int argc, char* argv[]){

  int key, total, winner, temp, len;
  char ch, word[50], fname[50] ,fline[1024], stuff[50];
  FILE *fin, *fout, *dict;

  if(argc == 3){
  
  strcpy(fname, argv[1]);
  strcat(fname, ".dec");  

  key = atoi(argv[2]);
  key = -key;

  fin = fopen(argv[1], "r");
  fout = fopen(fname, "w");

    if(fin == NULL || fout == NULL){
      printf("No open\n");
      exit(1);
    }
 
  while(fscanf(fin, "%c", &ch) != EOF){
    fprintf(fout, "%c", shift(ch, key));
  }

  fclose(fin);
  fclose(fout);

  }
  //If no shift value is given compares the contents of the decryption to a 
  //set of words in a dictionary file
  //Compiles but takes an insane amount of time to run
  else if(argc == 2){

    strcpy(fname, argv[1]);
    strcat(fname, ".dec");
    fin = fopen(argv[1], "r");
    fout = fopen(fname, "w");
    dict = fopen("/usr/share/dict/words", "r");

    if(fin == NULL || fout == NULL){
      printf("No open\n");
      exit(1);
    }

    for(int i = 1; i < 95; i++){
      temp = 0;
      while(fscanf(fin, "%c", &ch) != EOF){
        fprintf(fout, "%c", shift(ch, i));
      }
    
      while(!feof(dict)){
        fgets(word, 1024, dict);
        //strtok(word, "\n");
	while(!feof(fout)){
	  fgets(fline, 1024, fout);
	  len = strlen(word);
	  strncpy(stuff, fline, len);
	  if(strcmp(word, stuff) == 0){
	    temp = temp + 1;
	  }
        }
      }
      if(temp > total){
	total = temp;
       	winner = i;
    }
    }
    while(fscanf(fin, "%c", &ch) != EOF){
      fprintf(fout, "%c", shift(ch, winner));
    }

    fclose(fin);
    fclose(fout);
    fclose(dict);
     
  }
  else{
    printf("Invalid number of arguments");
    exit(1);
  }
  return 0;
}
