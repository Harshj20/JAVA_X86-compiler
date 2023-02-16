%{
#include <stdio.h>
#include <stdlib.h>
%}

/* Enumeration of Java token types */
%{
enum {
    T_KEYWORD = 1,
    T_IDENTIFIER,
    T_INTEGER_LITERAL,
    T_FLOATING_POINT_LITERAL,
    T_OPERATOR,
    T_PUNCTUATION
};
%}

%%
// Keywords
abstract|continue|for|new|switch
assert|default|if|package|synchronized
boolean|do|goto|private|this
break|double|implements|protected|throw
byte|else|import|public|throws
case|enum|instanceof|return|transient
catch|extends|int|short|try
char|final|interface|static|void
class|finally|long|strictfp|volatile
const|float|native|super|while
{keyword}           { return T_KEYWORD; }

// Identifiers
[a-zA-Z_$][a-zA-Z0-9_$]*   { return T_IDENTIFIER; }

// Integer literals
[0-9]+                  { return T_INTEGER_LITERAL; }

// Floating point literals
[0-9]+\.[0-9]+          { return T_FLOATING_POINT_LITERAL; }
[0-9]+[eE][+-]?[0-9]+   { return T_FLOATING_POINT_LITERAL; }

// Operators and punctuations
"++"                    { return T_OPERATOR; }
"--"                    { return T_OPERATOR; }
"=="                    { return T_OPERATOR; }
"!="                    { return T_OPERATOR; }
"<="                    { return T_OPERATOR; }
">="                    { return T_OPERATOR; }
"&&"                    { return T_OPERATOR; }
"||"                    { return T_OPERATOR; }
"!"                     { return T_OPERATOR; }
"&"                     { return T_OPERATOR; }
"|"                     { return T_OPERATOR; }
"^"                     { return T_OPERATOR; }
"~"                     { return T_OPERATOR; }
"<<"                    { return T_OPERATOR; }
">>"                    { return T_OPERATOR; }
">>>"                   { return T_OPERATOR; }
"="                     { return T_OPERATOR; }
"+"                     { return T_OPERATOR; }
"-"                     { return T_OPERATOR; }
"*"                     { return T_OPERATOR; }
"/"                     { return T_OPERATOR; }
"%"                     { return T_OPERATOR; }
"?"                     { return T_OPERATOR; }
":"                     { return T_OPERATOR; }
";"                     { return T_PUNCTUATION; }
","                     { return T_PUNCTUATION; }
"."                     { return T_PUNCTUATION; }
"("                     { return T_PUNCTUATION; }
")"                     { return T_PUNCTUATION; }
"{"                     { return T_PUNCTUATION; }
"}"                     { return T_PUNCTUATION; }
"["                     { return T_PUNCTUATION; }
"]"                     { return T_PUNCTUATION; }

// Comments and white space
"//"(.)*               /* single-line comments */
"/*"([^*]|\*[^/])*"*/" /* multi-line comments */
[ \t\r\n]+             /* white space */

%%

int yywrap(){
    return 1;
}