import { AssignStatement, OpExpression, Statement, PrintStatement, ExpressionPair, Expression, EseqExpression, CompoundStatement, makeCompoundStatement } from './../types';

const assignA = <Statement>{
  kind: 'AssignStatement',
  statement: <AssignStatement>{
    id: 'a',
    expression: {
      kind: 'OpExpression',
      expression: <OpExpression>{
        left: { kind: 'NumExpression', expression: 5 },
        op: '+',
        right: { kind: 'NumExpression', expression: 3 }
      }
    }
  }
};

const printA = <Statement>{
  kind: 'PrintStatement',
  statement: <PrintStatement>{
    exps: {
      kind: 'pair',
      list: <ExpressionPair>{
        head: {
          kind: 'IdExpression',
          expression: 'a'
        },
        tail: {
          kind: 'last',
          list: <Expression>{
            kind: 'OpExpression',
            expression: <OpExpression>{
              left: {
                kind: 'IdExpression',
                expression: 'a'
              },
              op: '-',
              right: {
                kind: 'NumExpression',
                expression: 1
              }
            }
          }
        }
      }
    }
  }
};

const tenTimesA = <Expression>{
  kind: 'OpExpression',
  expression: <OpExpression>{
    left: {
      kind: 'NumExpression',
      expression: 10
    },
    op: '-',
    right: {
      kind: 'IdExpression',
      expression: 'a'
    }
  }
};

const assignB = <Statement>{
  kind: 'AssignStatement',
  statement: <AssignStatement>{
    id: 'b',
    expression: {
      kind: 'EseqExpression',
      expression: <EseqExpression> {
        statement: printA,
        expression: tenTimesA
      }
    }
  }
};

const printB = <Statement>{
  kind: 'PrintStatement',
  statement: <PrintStatement> {
    exps: {
      kind: 'last',
      list: <Expression>{
        kind: 'IdExpression',
        expression: 'b'
      }
    }
  }
};

export const prog1 = makeCompoundStatement(assignA, makeCompoundStatement(assignB, printB));
