import { ExpressionPair, EseqExpression } from './types/expression';
import { CompoundStatement, PrintStatement, AssignStatement } from './types/statement';
import { ExpressionList, Statement, Expression } from './types';

export function maxargs(st: Statement): number {
  switch (st.kind) {
    case 'AssignStatement':
      const assign = st as AssignStatement;
      return maxargs_exp(assign.expression);
    case 'CompoundStatement':
      const compound = st as CompoundStatement;
      return Math.max(maxargs(compound.st1), maxargs(compound.st2));
    case 'PrintStatement':
      const print = st as PrintStatement;
      return maxargs_exps(print.exps);
  }
}

function maxargs_exps(exps: ExpressionList): number {
  if (exps.kind === 'pair') {
    return 1 + maxargs_exps((exps as ExpressionPair).tail);
  } else {
    return 1;
  }
}

function maxargs_exp(exp: Expression): number {
  switch (exp.kind) {
    case 'IdExpression':
    case 'NumExpression':
      return 1;
    case 'OpExpression':
      return 0;
    case 'EseqExpression':
      const eseq = exp as EseqExpression;
      return Math.max(maxargs(eseq.statement), maxargs_exp(eseq.expression));
  }
}
