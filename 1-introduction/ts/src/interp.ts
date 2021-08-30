import { Expression, ExpressionList, IdExpression, NumExpression, OpExpression, EseqExpression, ExpressionPair, ExpressionLast } from './types/expression';
import { Statement, AssignStatement, CompoundStatement, PrintStatement } from './types/statement';
type Table = Record<string, number>;

function newTable(id: string, val: number, tail: Table): Table {
  return {
    ...tail,
    [id]: val
  };
}

type ValAndTable = { val: number, table: Table };

export function interp(s: Statement, t: Table): Table {
  switch (s.kind) {
    case 'AssignStatement':
      const assign = s as AssignStatement;
      const result = interpExp(assign.expression, t);
      return newTable(assign.id, result.val, result.table);
    case 'CompoundStatement':
      const compound = s as CompoundStatement;
      const t1 = interp(compound.st1, t);
      const t2 = interp(compound.st2, t1);
      return t2;
    case 'PrintStatement':
      const print = s as PrintStatement;
      return interpExps(print.exps, t);
  }
}

function interpExp(exp: Expression, t: Table): ValAndTable {
  switch (exp.kind) {
    case 'IdExpression':
      const idExp = exp as IdExpression;
      return { val: t[idExp.id], table: t };
    case 'NumExpression':
      return { val: (exp as NumExpression).num, table: t };
    case 'OpExpression':
      return interpOpExp(exp as OpExpression, t);
    case 'EseqExpression':
      return interpEseqExp(exp as EseqExpression, t);

  }
}

function interpExps(exps: ExpressionList, t: Table): Table {
  switch (exps.kind) {
    case 'pair':
      const pair = exps as ExpressionPair;
      const res1 = interpExp(pair.head, t);
      return interpExps(pair.tail, res1.table);
    case 'last':
      const last = exps as ExpressionLast;
      const res2 = interpExp(last.last, t);
      return res2.table;
  }
}

function interpOpExp(opExp: OpExpression, t: Table): ValAndTable {
  const { val: left, table: t1 } = interpExp(opExp.left, t);
  const { val: right, table: t2 } = interpExp(opExp.right, t1);
  let val: number;
  switch (opExp.op) {
    case '*':
      val = left * right;
      break;
    case '+':
      val = left + right;
      break;
    case '-':
      val = left - right;
      break;
    case '/':
      val = left / right;
      break;
  }
  return { val, table: t2 };
}

function interpEseqExp(eseq: EseqExpression, t: Table): ValAndTable {
  t = interp(eseq.statement, t);
  return interpExp(eseq.expression, t);
}
