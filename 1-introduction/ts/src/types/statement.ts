import { Expression, ExpressionList } from "./expression";

export type StatementKind = 'CompoundStatement' | 'AssignStatement' | 'PrintStatement';

export interface Statement {
  kind: StatementKind;
  statement: CompoundStatement | AssignStatement | PrintStatement
}

export interface CompoundStatement {
  st1: Statement;
  st2: Statement;
}

export interface AssignStatement {
  id: string;
  expression: Expression;
}

export interface PrintStatement {
  exps: ExpressionList;
}

export function makeCompoundStatement(st1: Statement, st2: Statement): Statement {
  return <Statement>{
    kind: 'CompoundStatement',
    statement: <CompoundStatement> { st1, st2 }
  }
}
