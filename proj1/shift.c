/*shift.c
 *
 *Author: Sam Essenburg
 *
 * function that returns ciphered character 
 */

#include <stdio.h>
#include <string.h>
#include "shift.h"

char shift(char ch, int k){
 
  int result;
  result = ch - k;

    if(ch == '\n')
      return '\n';

    if(result < 32){
      return result + 95;
    }
 
    if(result > 126){
      return result - 95;
    }
 
  }

