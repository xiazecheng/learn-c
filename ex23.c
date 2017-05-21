#include <stdio.h>
#include <string.h>
#include "dbg.h"

int normal_copy(char *from, char *to, int count){
  int i = 0;

  for (i = 0; i < count; i++) {
    to[i] = from[i];
  }

  return i;
}

int duffs_device(char *from, char *to, int count){
  {
    int n = (count + 7)/8；

    switch (count % 8) {
      case 0: do{
        
      }while (n > 0);
    }
  }
}
