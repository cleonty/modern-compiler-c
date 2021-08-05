#include <stdio.h>
#include "util.h"
#include "slp.h"
#include "prog1.h"
#include "maxargs.h"

int main(int argc, char *argv[]) {
   printf ("maxargs is %d\n", maxargs(prog()));
   return 0;
}