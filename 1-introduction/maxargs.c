#include <stdio.h>
#include "util.h"
#include "slp.h"
#include "maxargs.h"

int maxargs_exp(A_exp exp) {
  switch (exp->kind) {
    case A_idExp:
    case A_numExp:
      return 1;
    case A_opExp:
      return 0;
    case A_eseqExp:
      return max(maxargs(exp->u.eseq.stm), maxargs_exp(exp->u.eseq.exp));
  }
}

int maxargs_list(A_expList list) {
  switch (list->kind) {
    case A_pairExpList:
      return 1 + maxargs_list(list->u.pair.tail);
    case A_lastExpList:
      return 1;
  }
}
  
int maxargs(A_stm stm) {
  switch (stm->kind) {
      case A_compoundStm:
        {
          int n1 = maxargs(stm->u.compound.stm1);
          int n2 = maxargs(stm->u.compound.stm2);
          printf ("n1 %d n2 %d\n", n1, n2);
          return max(n1, n2);
        }
      case A_assignStm:
        return maxargs_exp(stm->u.assign.exp);
      case A_printStm:
        return maxargs_list(stm->u.print.exps);
      default:
        printf ("unknown stm kind %d\n", stm->kind);
   }   
}
