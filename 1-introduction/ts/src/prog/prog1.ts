import { makeAssignStatement, makeCompoundStatement, makeEseq, makeExpLast, makeExpPair, makeId, makeNum, makeOpExp, makePrint } from './../types';

const assignA = makeAssignStatement('a', makeOpExp(makeNum(5), '+', makeNum(3)));
const printA = makePrint(makeExpPair(makeId('a'), makeExpLast(makeOpExp(makeId('a'), '-', makeNum(1)))));
const tenTimesA = makeOpExp(makeNum(10), '-', makeId('a'));
const assignB = makeAssignStatement('b', makeEseq(printA, tenTimesA));
const printB = makePrint(makeExpLast(makeId('b')));
export const prog1 = makeCompoundStatement(assignA, makeCompoundStatement(assignB, printB));
