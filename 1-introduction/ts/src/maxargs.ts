import { CompoundStatement } from './types/statement';
import { Statement } from './types';
export function maxargs(st: Statement): number {
  switch (st.kind) {
    case 'AssignStatement':
      
    case 'CompoundStatement':
      const compound = st.statement as CompoundStatement;
      return Math.max(maxargs(compound.st1), maxargs(compound.st2));
    case 'PrintStatement':
  }
}