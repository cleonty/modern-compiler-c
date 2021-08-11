import { Statement } from './statement';

export type ExpressionKind = 'IdExpression' | 'NumExpression' | 'OpExpression' | 'EseqExpression';
export interface Expression {
  kind: ExpressionKind;
  expression: IdExpression | NumExpression | OpExpression | EseqExpression;
}

export type IdExpression = string;
export type NumExpression = number;
export type BinOp = '+' | '-' | '*' | '/';
export interface OpExpression {
  left: Expression;
  op: BinOp;
  right: Expression;
};

export interface EseqExpression {
  statement: Statement;
  expression: Expression;
}

export interface ExpressionList {
  kind: 'pair' | 'last';
  list: ExpressionPair | Expression; 
}

export interface ExpressionPair {
  head: Expression;
  tail: ExpressionList;
}