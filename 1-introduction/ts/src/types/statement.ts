import { Expression, ExpressionList } from "./expression";

export type StatementKind = 'CompoundStatement' | 'AssignStatement' | 'PrintStatement';

export interface Statement {
  kind: StatementKind;
}

export interface CompoundStatement extends Statement {
  kind: 'CompoundStatement';
  st1: Statement;
  st2: Statement;
}

export interface AssignStatement extends Statement {
  kind: 'AssignStatement';
  id: string;
  expression: Expression;
}

export interface PrintStatement extends Statement {
  kind: 'PrintStatement';
  exps: ExpressionList;
}

export function makeCompoundStatement(st1: Statement, st2: Statement): CompoundStatement {
  return {
    kind: 'CompoundStatement',
    st1,
    st2
  }
}

export function makeAssignStatement(id: string, expression: Expression): AssignStatement {
  return {
    kind: 'AssignStatement',
    id,
    expression
  };
}

export function makePrint(exps: ExpressionList): PrintStatement {
  return {
    kind: 'PrintStatement',
    exps
  }
}
