#include <stdio.h>
#include "util.h"
#include "slp.h"
#include "table.h"
#include "interp.h"

typedef struct IntAndTable {
  int i;
  Table_ t;
} IntAndTable;

IntAndTable interpExp(A_exp e, Table_ t);

Table_ interpExpList(A_expList expList, Table_ t) {
  switch (expList->kind) {
    case A_pairExpList:
    {
      A_exp head = expList->u.pair.head;
      IntAndTable headResult = interpExp(head, t);
      t = headResult.t;
      A_expList tail = expList->u.pair.tail;
      t = interpExpList(tail, t);
      return t;
    }
    case A_lastExpList:
    {
      A_exp last = expList->u.last;
      IntAndTable lastResult = interpExp(last, t);
      return lastResult.t;
    }
  }
}

Table_ interpStm(A_stm s, Table_ t) {
  switch (s->kind) {
    case A_compoundStm:
      {
        t = interpStm(s->u.compound.stm1, t);
        t = interpStm(s->u.compound.stm2, t);
        return t;
      }
    case A_assignStm:
      {
        string key = s->u.assign.id;
        IntAndTable intAndTable = interpExp(s->u.assign.exp, t);
        return update(intAndTable.t, key, intAndTable.i);
      }
    case A_printStm:
      {
        A_expList expList= s->u.print.exps;
        return interpExpList(expList, t);
      }
    default:
      printf ("unknown stm kind %d\n", s->kind);
   }
}

IntAndTable interpExp(A_exp e, Table_ t) {
  IntAndTable intAndTable = {0, t};
  switch (e->kind) {
    case A_idExp:
      {
        IntAndTable result = {lookup(t, e->u.id), t};
        return result;
      }
    case A_numExp:
      {
        IntAndTable result = {e->u.num, t};
        return result;
      }
    case A_opExp:
      {
        A_exp left = e->u.op.left;
        A_binop oper = e->u.op.oper;
        A_exp right = e->u.op.right;
        IntAndTable leftResult = interpExp(left, t);
        int leftNum = leftResult.i;
        t = leftResult.t;
        IntAndTable rightResult = interpExp(right, t);
        int rightNum = rightResult.i;
        t = rightResult.t;
        int num = 0;
        switch (oper) {
          case A_plus:
            num = leftNum + rightNum;
            break;
          case A_minus:
            num = leftNum - rightNum;
            break;
          case A_times:
            num = leftNum * rightNum;
            break;
          case A_div:
            num = leftNum / rightNum;
            break;
        }
        IntAndTable result = {num, t};
        return result;
      }
    case A_eseqExp:
      {
        A_stm stm = e->u.eseq.stm;
        A_exp exp = e->u.eseq.exp;
        t = interpStm(stm, t);
        IntAndTable expResult = interpExp(exp, t);
        return expResult;
      }
  default:
    printf ("unknown exp kind %d\n", e->kind);
    exit(1);
    break;
  }
  return intAndTable;
}
