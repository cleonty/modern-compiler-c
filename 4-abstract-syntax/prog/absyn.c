/*
 * absyn.c - Abstract Syntax Functions. Most functions create an instance of an
 *           abstract syntax rule.
 */

#include "util.h"
#include "symbol.h" /* symbol table data structures */
#include "absyn.h"  /* abstract syntax data structures */

A_var A_SimpleVar( S_symbol sym)
{A_var p = checked_malloc(sizeof(*p));
 p->kind=A_simpleVar;
 
 p->u.simple=sym;
 return p;
}

A_var A_FieldVar( A_var var, S_symbol sym)
{A_var p = checked_malloc(sizeof(*p));
 p->kind=A_fieldVar;
 
 p->u.field.var=var;
 p->u.field.sym=sym;
 return p;
}

A_var A_SubscriptVar( A_var var, A_exp exp)
{A_var p = checked_malloc(sizeof(*p));
 p->kind=A_subscriptVar;
 
 p->u.subscript.var=var;
 p->u.subscript.exp=exp;
 return p;
}


A_exp A_VarExp( A_var var)
{A_exp p = checked_malloc(sizeof(*p));
 p->kind=A_varExp;
 
 p->u.var=var;
 return p;
}

A_exp A_NilExp()
{A_exp p = checked_malloc(sizeof(*p));
 p->kind=A_nilExp;
 
 return p;
}

A_exp A_IntExp( int i)
{A_exp p = checked_malloc(sizeof(*p));
 p->kind=A_intExp;
 
 p->u.intt=i;
 return p;
}

A_exp A_StringExp( string s)
{A_exp p = checked_malloc(sizeof(*p));
 p->kind=A_stringExp;
 
 p->u.stringg=s;
 return p;
}

A_exp A_CallExp( S_symbol func, A_expList args)
{A_exp p = checked_malloc(sizeof(*p));
 p->kind=A_callExp;
 
 p->u.call.func=func;
 p->u.call.args=args;
 return p;
}

A_exp A_OpExp( A_oper oper, A_exp left, A_exp right)
{A_exp p = checked_malloc(sizeof(*p));
 p->kind=A_opExp;
 
 p->u.op.oper=oper;
 p->u.op.left=left;
 p->u.op.right=right;
 return p;
}

A_exp A_RecordExp( S_symbol typ, A_efieldList fields)
{A_exp p = checked_malloc(sizeof(*p));
 p->kind=A_recordExp;
 
 p->u.record.typ=typ;
 p->u.record.fields=fields;
 return p;
}

A_exp A_SeqExp( A_expList seq)
{A_exp p = checked_malloc(sizeof(*p));
 p->kind=A_seqExp;
 
 p->u.seq=seq;
 return p;
}

A_exp A_AssignExp( A_var var, A_exp exp)
{A_exp p = checked_malloc(sizeof(*p));
 p->kind=A_assignExp;
 
 p->u.assign.var=var;
 p->u.assign.exp=exp;
 return p;
}

A_exp A_IfExp( A_exp test, A_exp then, A_exp elsee)
{A_exp p = checked_malloc(sizeof(*p));
 p->kind=A_ifExp;
 
 p->u.iff.test=test;
 p->u.iff.then=then;
 p->u.iff.elsee=elsee;
 return p;
}

A_exp A_WhileExp( A_exp test, A_exp body)
{A_exp p = checked_malloc(sizeof(*p));
 p->kind=A_whileExp;
 
 p->u.whilee.test=test;
 p->u.whilee.body=body;
 return p;
}

A_exp A_ForExp( S_symbol var, A_exp lo, A_exp hi, A_exp body)
{A_exp p = checked_malloc(sizeof(*p));
 p->kind=A_forExp;
 
 p->u.forr.var=var;
 p->u.forr.lo=lo;
 p->u.forr.hi=hi;
 p->u.forr.body=body;
 p->u.forr.escape=TRUE;
 return p;
}

A_exp A_BreakExp()
{A_exp p = checked_malloc(sizeof(*p));
 p->kind=A_breakExp;
 
 return p;
}

A_exp A_LetExp( A_decList decs, A_exp body)
{A_exp p = checked_malloc(sizeof(*p));
 p->kind=A_letExp;
 
 p->u.let.decs=decs;
 p->u.let.body=body;
 return p;
}

A_exp A_ArrayExp( S_symbol typ, A_exp size, A_exp init)
{A_exp p = checked_malloc(sizeof(*p));
 p->kind=A_arrayExp;
 
 p->u.array.typ=typ;
 p->u.array.size=size;
 p->u.array.init=init;
 return p;
}

A_dec A_FunctionDec( A_fundecList function)
{A_dec p = checked_malloc(sizeof(*p));
 p->kind=A_functionDec;
 
 p->u.function=function;
 return p;
}

A_dec A_VarDec( S_symbol var, S_symbol typ, A_exp init)
{A_dec p = checked_malloc(sizeof(*p));
 p->kind=A_varDec;
 
 p->u.var.var=var;
 p->u.var.typ=typ;
 p->u.var.init=init;
 p->u.var.escape=TRUE;
 return p;
}

A_dec A_TypeDec( A_nametyList type)
{A_dec p = checked_malloc(sizeof(*p));
 p->kind=A_typeDec;
 
 p->u.type=type;
 return p;
}

A_ty A_NameTy( S_symbol name)
{A_ty p = checked_malloc(sizeof(*p));
 p->kind=A_nameTy;
 
 p->u.name=name;
 return p;
}

A_ty A_RecordTy( A_fieldList record)
{A_ty p = checked_malloc(sizeof(*p));
 p->kind=A_recordTy;
 
 p->u.record=record;
 return p;
}

A_ty A_ArrayTy( S_symbol array)
{A_ty p = checked_malloc(sizeof(*p));
 p->kind=A_arrayTy;
 
 p->u.array=array;
 return p;
}

A_field A_Field( S_symbol name, S_symbol typ)
{A_field p = checked_malloc(sizeof(*p));
 
 p->name=name;
 p->typ=typ;
 p->escape=TRUE;
 return p;
}

A_fieldList A_FieldList(A_field head, A_fieldList tail)
{A_fieldList p = checked_malloc(sizeof(*p));
 p->head=head;
 p->tail=tail;
 return p;
}

A_expList A_ExpList(A_exp head, A_expList tail)
{A_expList p = checked_malloc(sizeof(*p));
 p->head=head;
 p->tail=tail;
 return p;
}

A_fundec A_Fundec( S_symbol name, A_fieldList params, S_symbol result,
		  A_exp body)
{A_fundec p = checked_malloc(sizeof(*p));
 
 p->name=name;
 p->params=params;
 p->result=result;
 p->body=body;
 return p;
}

A_fundecList A_FundecList(A_fundec head, A_fundecList tail)
{A_fundecList p = checked_malloc(sizeof(*p));
 p->head=head;
 p->tail=tail;
 return p;
}

A_decList A_DecList(A_dec head, A_decList tail)
{A_decList p = checked_malloc(sizeof(*p));
 p->head=head;
 p->tail=tail;
 return p;
}

A_namety A_Namety(S_symbol name, A_ty ty)
{A_namety p = checked_malloc(sizeof(*p));
 p->name=name;
 p->ty=ty;
 return p;
}

A_nametyList A_NametyList(A_namety head, A_nametyList tail)
{A_nametyList p = checked_malloc(sizeof(*p));
 p->head=head;
 p->tail=tail;
 return p;
}

A_efield A_Efield(S_symbol name, A_exp exp)
{A_efield p = checked_malloc(sizeof(*p));
 p->name=name;
 p->exp=exp;
 return p;
}

A_efieldList A_EfieldList(A_efield head, A_efieldList tail)
{A_efieldList p = checked_malloc(sizeof(*p));
 p->head=head;
 p->tail=tail;
 return p;
}

