#include <stdio.h>
#include "util.h"
#include "slp.h"
#include "prog1.h"
#include "maxargs.h"
#include "interp.h"

int main(int argc, char *argv[]) {
   printf ("maxargs is %d\n", maxargs(prog()));
   Table_ res = interpStm(prog(), NULL);
   printf ("result table:\n");
   print(res);
   return 0;
}