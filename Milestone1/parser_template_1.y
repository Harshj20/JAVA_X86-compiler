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

program:
    class_declaration
    ;

class_declaration:
    KEYWORD IDENTIFIER '{' field_declaration* method_declaration* '}'
    {
        print_node("Class Declaration");
        print_token("Keyword", $1);
        print_token("Identifier", $2);
        for (int i = 3; i < $0 - 1; i++) {
            print_edge(node_count - 2, node_count);
            $$ = $i;
        }
    }
    ;

field_declaration:
    type_specifier variable_declarator (',' variable_declarator)* PUNCTUATION
    {
        print_node("Field Declaration");
        print_token("Type Specifier", $1);
        for (int i = 2; i < $0; i++) {
            print_edge(node_count - 2, node_count);
            $$ = $i;
        }
    }
    ;

variable_declarator:
    IDENTIFIER ('[' INTEGER_LITERAL ']')* ('=' expression)?
    {
        print_node("Variable Declarator");
        print_token("Identifier", $1);
        for (int i = 2; i < $0; i++) {
            print_edge(node_count - 2, node_count);
            print_node("Array Index");
            print_token("Integer Literal", $i);
            print_edge(node_count - 3, node_count);
        }
        if ($0 == 4) {
            print_edge(node_count - 2, node_count);
            print_node("Assignment Expression");
            print_token("Operator", "=");
            print_edge(node_count - 3, node_count);
            print_edge(node_count - 1, node_count);
            $$ = $4;
        }
    }
    ;

type_specifier:
    KEYWORD
    {
        print_node("Type Specifier");
        print_token("Keyword", $1);
    }
    ;

method_declaration:
    type_specifier IDENTIFIER '(' variable_declaration* ')' block_statement
    {
        print_node("Method Declaration");
        print_token("
