%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int node_count = 0;

void print_node(char* label) {
    printf("node%d[label=\"%s\"];\n", node_count++, label);
}

void print_edge(int from, int to) {
    printf("node%d -> node%d;\n", from, to);
}

void print_token(char* token_type, char* token_value) {
    print_node(token_value);
    print_edge(node_count - 1, node_count);
    print_node(token_type);
    print_edge(node_count - 1, node_count);
}
%}

%union {
    char* string;
    int integer;
    double floating_point;
    bool boolean;
}

%token <string> IDENTIFIER
%token <integer> INTEGER_LITERAL
%token <floating_point> FLOATING_POINT_LITERAL
%token <string> KEYWORD
%token <string> OPERATOR
%token <string> PUNCTUATION
%token <string> STRING_LITERAL
%token <boolean> BOOLEAN_LITERAL

%type <string> type_specifier
%type <string> class_declaration
%type <string> field_declaration
%type <string> method_declaration
%type <string> block_statement
%type <string> statement
%type <string> expression
%type <string> primary_expression
%type <string> postfix_expression
%type <string> argument_list
%type <string> variable_declaration
%type <string> variable_declarator

%%

program: /* empty */
       | program statement SEMICOLON
       ;

statement: declaration
         | assignment_statement
         | expression_statement
         ;

declaration: primitive_type variable_declarator
            ;

-- type: primitive_type array_type?
--     ;

primitive_type: k_int | k_float | k_bool | k_double | k_long ;

array_type: LBRACKET RBRACKET array_type?
          ;

variable_declarator: IDENTIFIER (array_initializer)? (ASSIGN expression)?
                    ;

array_initializer: o_open_square_bracket variable_initializer_list? o_close_square_bracket
                  ;

variable_initializer_list: variable_initializer (o_comma variable_initializer)*
                          ;

variable_initializer: expression
                     | array_initializer
                     ;

assignment_statement: expression ASSIGN expression
                     | expression ASSIGN ternary_expression
                     | expression PLUS_ASSIGN expression
                     | expression MINUS_ASSIGN expression
                     | expression MULT_ASSIGN expression
                     | expression DIV_ASSIGN expression
                     | expression MOD_ASSIGN expression
                     | expression BITWISE_AND_ASSIGN expression
                     | expression BITWISE_XOR_ASSIGN expression
                     | expression BITWISE_OR_ASSIGN expression
                     | expression SHIFT_LEFT_ASSIGN expression
                     | expression SHIFT_RIGHT_ASSIGN expression
                     | expression UNSIGNED_SHIFT_RIGHT_ASSIGN expression
                     ;

expression_statement: expression
                     ;

expression: ternary_expression
          ;

ternary_expression: logical_or_expression (QUESTION_MARK ternary_expression COLON ternary_expression)?
                  ;

logical_or_expression: logical_and_expression (OR logical_and_expression)*
                      ;

logical_and_expression: bitwise_or_expression (AND bitwise_or_expression)*
                       ;

bitwise_or_expression: bitwise_xor_expression (BITWISE_OR bitwise_xor_expression)*
                      ;

bitwise_xor_expression: bitwise_and_expression (BITWISE_XOR bitwise_and_expression)*
                       ;

bitwise_and_expression: equality_expression (BITWISE_AND equality_expression)*
                       ;

equality_expression: relational_expression ((EQ | NEQ) relational_expression)*
                     ;

relational_expression: shift_expression ((LT | LTE | GT | GTE) shift_expression)*
                      ;

shift_expression: additive_expression ((SHIFT_LEFT | SHIFT_RIGHT | UNSIGNED_SHIFT_RIGHT) additive_expression)*
                 ;

additive_expression: multiplicative_expression ((PLUS | MINUS) multiplicative_expression)*
                    ;

multiplicative_expression: unary_expression ((MULT | DIV | MOD) unary_expression)*
                          ;

unary_expression: primary_expression
                 | NOT unary_expression
                 | PLUS primary_expression
                 | MINUS primary_expression
                 | INC unary_expression
                 | DEC unary_expression
                 ;

primary_expression: IDENTIFIER
                   | integer_literal
                   | LPAREN expression RPAREN
                   | THIS
                   ;

integer_literal: LITERAL
               ;


statement_list:
    /* empty */
    | statement_list statement
    ;

statement:
    expression_statement
    | compound_statement
    | selection_statement
    | iteration_statement
    ;

expression_statement:
    expression SEMICOLON
    ;

compound_statement:
    L_BRACE statement_list R_BRACE
    ;

selection_statement:
    IF L_PAREN expression R_PAREN statement
    | IF L_PAREN expression R_PAREN statement ELSE statement
    ;

iteration_statement:
    WHILE L_PAREN expression R_PAREN statement
    | FOR L_PAREN for_expression SEMICOLON for_expression SEMICOLON for_expression R_PAREN statement
    ;

for_expression:
    expression | /* empty */
    ;

expression:
    equality_expression
    ;

equality_expression:
    relational_expression
    | equality_expression EQ relational_expression
    | equality_expression NEQ relational_expression
    ;

relational_expression:
    additive_expression
    | relational_expression LT additive_expression
    | relational_expression GT additive_expression
    | relational_expression LTE additive_expression
    | relational_expression GTE additive_expression
    ;

additive_expression:
    multiplicative_expression
    | additive_expression PLUS multiplicative_expression
    | additive_expression MINUS multiplicative_expression
    ;

multiplicative_expression:
    unary_expression
    | multiplicative_expression MULT unary_expression
    | multiplicative_expression DIV unary_expression
    | multiplicative_expression MOD unary_expression
    ;

unary_expression:
    postfix_expression
    | PLUS unary_expression %prec UNARY
    | MINUS unary_expression %prec UNARY
    | NOT unary_expression %prec UNARY
    | INCREMENT unary_expression %prec UNARY
    | DECREMENT unary_expression %prec UNARY
    ;

postfix_expression:
    primary_expression
    | postfix_expression INCREMENT
    | postfix_expression DECREMENT
    ;

primary_expression:
    variable
    | constant
    | L_PAREN expression R_PAREN
    ;

variable:
    ID
    ;

constant:
    INT_LITERAL
    | DOUBLE_LITERAL
    | BOOL_LITERAL
    ;

%%
