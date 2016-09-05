/*encrypt.c
 *
 *Created on: Jun, 28
 *Authort: Sam Essenburg
 *
 *CIS 361: Project 1
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shift.h"

char shift(char, int);

int main(int argc, char* argv[]){

  int  key;
  char ch, fname[50];
  FILE *fin, *fout;

  if(argc != 3){
    printf("Invalid number of arguments\n");
    exit(1);
  }
  
  strcpy(fname, argv[1]);
  strcat(fname, ".enc");  

  key = atoi(argv[2]);
  //key = -key;

  fin = fopen(argv[1], "r");
  fout = fopen(fname, "w");

    if(fin == NULL || fout == NULL){
      printf("File not found\n");
      exit(1);
    }
  
  while(fscanf(fin, "%c", &ch) != EOF){
    fprintf(fout, "%c", shift(ch, key));
  }

  fclose(fin);
  fclose(fout);
  
  return 0;
}
