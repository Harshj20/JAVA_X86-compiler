%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
%}

/* Enumeration of Java token types */

%option yylineno
%x string
%x textBlock

Integer [1-9][lL]?|[1-9][0-9_]*[0-9]+[lL]?

deci_floats [0-9]*"."[0-9]+[fFdD]?|[0-9]+"."[0-9]*[fFdD]?|[0-9][0-9_]*[0-9]+"."[0-9]*[fFdD]?|[0-9]*"."[0-9][0-9_]*[0-9]+[fFdD]|[+-][0-9][0-9_]*[0-9]+"."[0-9][0-9_]*[0-9]+[fFdD]?

hex_floats 0[xX][0-9a-fA-F]*"."[0-9a-fA-F]+|0[xX][0-9a-fA-F]+"."[0-9a-fA-F]*|0[xX][0-9a-fA-F][0-9a-fA-F_]*[0-9a-fA-F]+"."[0-9a-fA-F]*|0[xX][0-9a-fA-F]*"."[0-9a-fA-F][0-9a-fA-F_]*[0-9a-fA-F]+|0[xX][0-9a-fA-F][0-9a-fA-F_]*[0-9a-fA-F]+"."[0-9a-fA-F][0-9a-fA-F_]*[0-9a-fA-F]+

RESERVED_WORD "abstract"|"assert"|"boolean"|"break"|"byte"|"case"|"catch"|"char"|"class"|"const"|"_"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"if"|"goto"|"implements"|"import"|"instanceof"|"int"|"interface"|"long"|"naive"|"new"|"package"|"private"|"protected"|"public"|"return"|"short"|"static"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"void"|"volatile"|"while"
CONTEXTUAL_WORD "exports"|"module"|"non-sealed"|"open"|"opens"|"permits"|"provides"|"record"|"requires"|"sealed"|"to"|"transitive"|"uses"|"var"|"with"|"yield"

%%
"exports" {return k_exports;}
"module"  { return k_module;}
"non-sealed" {return k_non_sealed;}
"open" {return k_open;}
"opens"  {return k_opens;}
"permits" {return k_permits;}
"provides" {return k_provide;}
"record" {return k_record;}
"requires" {return k_requires;}
"sealed" {return k_sealed;}
"to" {return k_to;}
"transitive" {return k_transitive;}
"uses" {return k_uses;}
"var" {return k_var;}
"with" {return k_with;}
"yield" {return k_yield;}

"abstract" { return k_abstract; }
"assert" { return k_assert; }
"boolean" { return k_boolean; }
"break" { return k_break; }
"byte" { return k_byte; }
"case" { return k_case; }
"catch" { return k_catch; }
"char" { return k_char; }
"class" { return k_class; }
"const" { return k_const; }
"continue" { return k_continue; }
"default" { return k_default; }
"do" { return k_do; }
"double" { return k_double; }
"else" { return k_else; }
"enum" { return k_enum; }
"extends" { return k_extends; }
"final" { return k_final; }
"finally" { return k_finally; }
"float" { return k_float; }
"for" { return k_for; }
"if" { return k_if; }
"goto" { return k_goto; }
"implements" { return k_implements; }
"import" { return k_import; }
"instanceof" { return k_instanceof; }
"int" { return k_int; }
"interface" { return k_interface; }
"long" { return k_long; }
"native" { return k_native; }
"new" { return k_new; }
"package" { return k_package; }
"private" { return k_private; }
"protected" { return k_protected; }
"public" { return k_public; }
"return" { return k_return; }
"short" { return k_short; }
"static" { return k_static; }
"strictfp" { return k_strictfp; }
"super" { return k_super; }
"switch" { return k_switch; }
"synchronized" { return k_synchronized; }
"this" { return k_this; }
"throw" { return k_throw; }
"throws" { return k_throws; }
"transient" { return k_transient; }
"try" { return k_try; }
"void" { return k_void; }
"volatile" { return k_volatile; }
"while" { return k_while; }
"_" {return k_underscore; }

"true" { return Literal; }
"false" { return Literal; }
"null" { return Literal; }

"=" { return o_assign; }
"+=" { return o_add_assign; }
"-=" { return o_subtract_assign; }
"*=" { return o_multiply_assign; }
"/=" { return o_divide_assign; }
"%=" { return o_modulo_assign; }
"&=" { return o_bitwise_and_assign; }
"|=" { return o_bitwise_or_assign; }
"^=" { return o_bitwise_xor_assign; }
"<<=" { return o_left_shift_assign; }
">>=" { return o_right_shift_assign; }
">>>=" { return o_unsigned_right_shift_assign; }

"&" { return o_bitwise_and; }
"|" { return o_bitwise_or; }
"^" { return o_bitwise_xor; }
"<<" { return o_left_shift; }
">>" { return o_right_shift; }
">>>" { return o_unsigned_right_shift; }

"+" { return o_add; }
"-" { return o_subtract; }
"*" { return o_multiply; }
"/" { return o_divide; }
"%" { return o_modulo; }

"<" { return o_less_than; }
"<=" { return o_less_than_or_equal; }
">" { return o_greater_than; }
">=" { return o_greater_than_or_equal; }
"==" { return o_equals; }
"!=" { return o_not_equals; }

"!" { return o_logical_not; }
"&&" { return o_logical_and; }
"||" { return o_logical_or; }

"++" { return o_increment; }
"--" { return o_decrement; }
"~" { return o_bitwise_complement; }

"?" { return o_question_mark; }
":" { return o_colon; }
"->" {return o_arrow;}


";" { return s_semicolon; }
"," { return s_comma; }
"." { return s_dot; }
"(" { return s_open_paren; }
")" { return s_close_paren; }
"[" { return s_open_square_bracket; }
"]" { return s_close_square_bracket; }
"{" { return s_open_curly_bracket; }
"}" { return s_close_curly_bracket; }
"::" { return s_double_colon; }
"..." { return s_varargs; }
  
{Integer}                  { return Literal; }

{deci_floats}        { return Literal; }
{hex_floats}        {return Literal;}

{deci_floats}|{deci_floats}[eE]{deci_floats}|{Integer}[eE]{deci_floats}|{deci_floats}[eE]{Integer}|{Integer}[eE]{Integer} {return Literal;}

0[xX][0-9a-fA-F]|0[xX][0-9a-fA-F][0-9a-fA-F_]*[0-9a-fA-F]   {   return Literal; }

{hex_floats}|{hex_floats}[pP]{Integer}      {   return Literal; }


0[bB][01]|0[bB][01][01_]*[01]+  {   return Literal; }

0|0[0-9_]*[0-9]+  {   return Literal; }


"'"[^"'"\\]"'" {return Literal; }
"\"\"\"" yymore(); BEGIN(textBlock);
<textBlock>"\"\"\"" {
    BEGIN(INITIAL);
    return Literal;
}
<textBlock>[^\\]+ yymore();
<textBlock>\\(["\"""'"\\nstrbf]|[0-7]{1,2}|[0-3][0-7]{2}) yymore();

"\"" yymore(); BEGIN(string);
<string>[^"\""\\\n\r]+ yymore();
<string>\\(["\"""'"\\ntrbsf]|[0-7]{1,2}|[0-3][0-7]{2}) yymore();
<string>"\"" {
    BEGIN(INITIAL);
    return Literal;
}
[a-zA-Z$_][a-zA-Z0-9$_]* { return Identifier;}

"//"(.)*               /* single-line comments */
"/*"[^*/]*"*/"  /* multi-line comments */
[ \t\r\n]+             /* white space */

<INITIAL,string,textBlock>.|\n  printf("Error at line no. %d, text is %s\n", yylineno, yytext); return 0;
%%

int yywrap(){
    return 1;
}
