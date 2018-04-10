%{
//definitions
#include "y.tab.h"
#include <string.h>
#include <stdlib.h>


int comment = 0;
//add extra functions here

%}

%%

"/*"            { comment = 1; }
"*/"            { comment = 0; }

"int"           { if (!comment) return TYPEDEC; }
"float"         { if (!comment) return TYPEDEC; }
"char"          { if (!comment) return TYPEDEC; }

"else if"       { if (!comment) return ELSEIF; }
"if"            { if (!comment) return IF; }
"else"          { if (!comment) return ELSE; }
"while"         { if (!comment) return WHILE; }
"for"           { if (!comment) return FOR; }

[ \t\n]   {
    //throw away spaces and tabs and newline
}

-?[0-9]+ {
    if (!comment) {
        yylval.ival = atoi(yytext);
        return INTEGER;
    }
}

-?[0-9]+\.[0-9]* {
    if (!comment) {
        yylval.fval = atof(yytext);
        return FLOAT;
    }
}

\".*\"  {
    //anything between double quotes
    if (!comment) {
        yylval.strval = strdup(yytext);
        return STRING;
    }
}

\'.?\' {
    //any char between single quotes
    if (!comment) {
        yylval.charval = yytext[0];
        return CHAR;
    }
}

[a-zA-Z_][a-zA-Z0-9_]*  {
    //id found, look at sym table
    if (!comment) {
        yylval.strval = strdup(yytext);
        return VARIABLE;
    }
}

"+"     { if (!comment) return PLUS; }
"-"     { if (!comment) return MINUS; }
"+="    { if (!comment) return PLUSEQ; }
"-="    { if (!comment) return MINUSEQ; }
"++"    { if (!comment) return PLUSPLUS; }
"--"    { if (!comment) return MINUSMINUS; }

"*"     { if (!comment) return MULT; }
"/"     { if (!comment) return DIV; }
"%"     { if (!comment) return MOD; }
"*="    { if (!comment) return MULTEQ; }
"/="    { if (!comment) return DIVEQ; }
"%="    { if (!comment) return MODEQ; }

"&&"    { if (!comment) return ANDAND; }
"||"    { if (!comment) return OROR; }

"&"     { if (!comment) return AND; }
"|"     { if (!comment) return OR; }
"^"     { if (!comment) return XOR; }
"&="    { if (!comment) return ANDEQ; }
"|="    { if (!comment) return OREQ; }
"^="    { if (!comment) return XOREQ; }

"<"     { if (!comment) return LESS; }
">"     { if (!comment) return GREAT; }
"<="    { if (!comment) return LTEQ; }
">="    { if (!comment) return GTEQ; }
"="     { if (!comment) return ASGN; }
"=="    { if (!comment) return EQUAL; }

"<<"    { if (!comment) return LSHIFT; }
">>"    { if (!comment) return RSHIFT: }

"{"     { if (!comment) return LCURLY; }
"}"     { if (!comment) return RCURLY; }
"["     { if (!comment) return LBRAC; }
"]"     { if (!comment) return RBRAC; }
"~"     { if (!comment) return TILDE; }
";"     { if (!comment) return SEMICOL; }
","     { if (!comment) return COMMA: }
":"     { if (!comment) return COLON; }
"->"    { if (!comment) return ARROW; }
"#"     { if (!comment) return POUND; }

<<EOF>> { return END; }

.       { if (!comment) return yytext[0]; }

%%

