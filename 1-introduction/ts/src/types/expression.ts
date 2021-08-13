import { Statement } from './statement';

export type ExpressionKind = 'IdExpression' | 'NumExpression' | 'OpExpression' | 'EseqExpression';
export interface Expression {
  kind: ExpressionKind;
}

export interface IdExpression extends Expression {
  kind: 'IdExpression'
  id: string;
}
export interface NumExpression extends Expression {
  kind: 'NumExpression'
  num: number;
}

export type BinOp = '+' | '-' | '*' | '/';

export interface OpExpression extends Expression {
  kind: 'OpExpression'
  left: Expression;
  op: BinOp;
  right: Expression;
};

export interface EseqExpression extends Expression {
  kind: 'EseqExpression',
  statement: Statement;
  expression: Expression;
}

export interface ExpressionList {
  kind: 'pair' | 'last';
}

export interface ExpressionPair extends ExpressionList {
  kind: 'pair',
  head: Expression;
  tail: ExpressionList;
}

export interface ExpressionLast extends ExpressionList {
  kind: 'last',
  last: Expression;
}

export function makeNum(num: number): NumExpression {
  return {
    kind: 'NumExpression',
    num
  };
}

export function makeId(id: string): IdExpression {
  return {
    kind: 'IdExpression',
    id
  };
}

export function makeOpExp(left: Expression, op: BinOp, right: Expression): OpExpression {
  return {
    kind: 'OpExpression',
    left,
    op,
    right
  };
}

export function makeExpPair(head: Expression, tail: ExpressionList): ExpressionPair {
  return {
    kind: 'pair',
    head,
    tail,
  }
}

export function makeExpLast(last: Expression): ExpressionLast {
  return {
    kind: 'last',
    last
  }
}

export function makeEseq(statement: Statement, expression: Expression): EseqExpression {
  return {
    kind: 'EseqExpression',
    statement,
    expression,
  }
}