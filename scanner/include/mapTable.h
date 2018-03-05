#ifndef MAPTAB_H
#define MAPTAB_H

#define JUNK        0
#define WHITESPACE  1
#define NUMBERS     2
#define CHARS       3
#define NEWLINE     4

#define SQUOTE      5
#define DQUOTE      6

#define PLUS        7
#define MINUS       8
#define STAR        9
#define SLASH       10
#define MOD         11

#define NOT         12
#define AND         13
#define OR          14
#define LESS        15
#define GREAT       16
#define EQUAL       17
#define TILDE       18

#define LPARAN      19
#define RPARAN      20
#define LBRAC       21
#define RBRAC       22
#define LCURLY      23
#define RCURLY      24

#define COMMA       25
#define PERIOD      26
#define QUESTION    27

#define COLON       28
#define SEMICOL     29

#define CARET       30
#define UNDER       31

#define ESCAPE      32
#define POUND       33

extern int mapTable[ASCIIMAX + 1];
#endif