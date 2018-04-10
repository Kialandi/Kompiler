%token  ELSEIF IF ELSE WHILE FOR

%token  PLUS MINUS
%token  MULT DIV MOD

%token  ANDAND OROR
%token  AND OR XOR
%token  VARIABLE ASGN END

%token  PLUSPLUS MINUSMINUS
%token  LESS GREAT LTEQ GTEQ EQUAL
%token  LSHIFT RSHIFT
%token  LCURLY RCURLY LBRAC RBRAC
%token  TILDE SEMICOL COMMA COLON ARROW POUND

%token <assignment> PLUSEQ MINUSEQ MULTEQ DIVEQ MODEQ ANDEQ OREQ XOREQ
%token <ival>       INTEGER
%token <fval>       FLOAT
%token <strval>     STRING TYPEDEC
%token <charval>    CHAR

%left PLUS MINUS
%left MULT DIV
%left LPAREN RPAREN
%left LBRAC RBRAC
%left LCURLY RCURLY

%type expr stmt

%union {
    char *  strval;
    int     ival;
    float   fval;
    char    charval;
    int     token;
    int     assignment;
}

%{//definitions and extra code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSYMTAB 150

struct sym_ent {
    char * name;
    int occurs;
} symtab[MAXSYMTAB];

%}

%start parser

%%

parser: stmts
    ;

stmts:  stmt SEMICOL
    ;
    
stmt:   TYPEDEC VARIABLE ASGN expr
    |   IF
    |   FOR
    |   WHILE
    |   


