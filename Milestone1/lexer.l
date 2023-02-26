%{
#include <stdio.h>
#include <stdlib.h>
%}

/* Enumeration of Java token types */

%option yylineno
%x string
%x textBlock

RESERVED_WORD "abstract"|"assert"|"boolean"|"break"|"byte"|"case"|"catch"|"char"|"class"|"const"|"_"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"if"|"goto"|"implements"|"import"|"instanceof"|"int"|"interface"|"long"|"naive"|"new"|"package"|"private"|"protected"|"public"|"return"|"short"|"static"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"void"|"volatile"|"while"
CONTEXTUAL_WORD "exports"|"module"|"non-sealed"|"open"|"opens"|"permits"|"provides"|"record"|"requires"|"sealed"|"to"|"transitive"|"uses"|"var"|"with"|"yield"

%%
//  Keywords
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

// Literals
"true" { return l_true; }
"false" { return l_false; }
"null" { return l_null; }

}
// Assignment Operators
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

// Arithmetic Operators
"+" { return o_add; }
"-" { return o_subtract; }
"*" { return o_multiply; }
"/" { return o_divide; }
"%" { return o_modulo; }

// Relational Operators
"<" { return o_less_than; }
"<=" { return o_less_than_or_equal_to; }
">" { return o_greater_than; }
">=" { return o_greater_than_or_equal_to; }
"instanceof" { return o_instance_of; }
"==" { return o_equals; }
"!=" { return o_not_equals; }

// Logical Operators
"&" { return o_bitwise_and; }
"|" { return o_bitwise_or; }
"^" { return o_bitwise_xor; }
"!" { return o_logical_not; }
"&&" { return o_logical_and; }
"||" { return o_logical_or; }

// Unary Operators
"++" { return o_increment; }
"--" { return o_decrement; }
"+" { return o_unary_plus; }
"-" { return o_unary_minus; }
"~" { return o_bitwise_complement; }

// Ternary Operator
"?" { return o_question_mark; }
":" { return o_colon; }

// Other Operators
"." { return o_dot; }
"," { return o_comma; }
";" { return o_semicolon; }
"(" { return o_open_paren; }
")" { return o_close_paren; }
"[" { return o_open_square_bracket; }
"]" { return o_close_square_bracket; }
"{" { return o_open_curly_bracket; }
"}" { return o_close_curly_bracket; }
"@" { return o_annotation; }
"..." { return o_varargs; }


";" { return s_semicolon; }
"," { return s_comma; }
"." { return s_dot; }
"(" { return s_open_paren; }
")" { return s_close_paren; }
"[" { return s_open_square_bracket; }
"]" { return s_close_square_bracket; }
"{" { return s_open_curly_bracket; }
"}" { return s_close_curly_bracket; }
"@" { return s_annotation; }
"::" { return s_double_colon; }
"..." { return s_varargs; }
  
[0-9]+                  { return l_int; }

[0-9]+\.[0-9]+[fF]?          { return l_float; }
[0-9]+[eE][+-]?[0-9]+[fF]?   { return l_float; }


"'"[^"'"\\]"'" {return l_char; }
"\"\"\"" yymore(); BEGIN(textBlock);
<textBlock>"\"\"\"" {
    BEGIN(INITIAL);
    return l_text_box;
}
<textBlock>[^\\]+ yymore();
<textBlock>\\(["\"""'"\\nstrbf]|[0-7]{1,2}|[0-3][0-7]{2}) yymore();

"\"" yymore(); BEGIN(string);
<string>[^"\""\\\n\r]+ yymore();
<string>\\(["\"""'"\\ntrbsf]|[0-7]{1,2}|[0-3][0-7]{2}) yymore();
<string>"\"" {
    BEGIN(INITIAL);
    return l_string;
}
[a-zA-Z$_][a-zA-Z0-9$_]* { return identifier;}


"//"(.)*               /* single-line comments */
"/*"([^*]|\*[^/])*"*/" /* multi-line comments */
[ \t\r\n]+             /* white space */

<INITIAL,string,textBlock>.|\n  printf("Error at line no. %d, text is %s\n", yylineno, yytext); return 0;
%%

int yywrap(){
    return 1;
}
