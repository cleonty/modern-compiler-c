#include <stdio.h>
#include <stdlib.h>

int inc(int x) {
  return x + 1;
}

int main(int argc, char *argv[]) {
  int val = 3;
  int newVal = inc(val);
  printf ("val = %d newVal = %d\n", val, newVal);
}
