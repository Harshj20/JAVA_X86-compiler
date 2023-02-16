%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
%}

%union {
    char* string;
    int integer;
    double decimal;
    struct ASTNode* node;
}

%token <string> IDENTIFIER
%token <integer> INTEGER_LITERAL
%token <decimal> DECIMAL_LITERAL
%token <string> BOOLEAN_LITERAL
%token <string> STRING_LITERAL
%token <string> CLASS
%token <string> EXTENDS
%token <string> PUBLIC
%token <string> PRIVATE
%token <string> STATIC
%token <string> VOID
%token <string> INT
%token <string> LONG
%token <string> FLOAT
%token <string> DOUBLE
%token <string> BOOLEAN
%token <string> IF
%token <string> ELSE
%token <string> FOR
%token <string> WHILE
%token <string> RETURN
%token <string> PRINTLN

%left '+' '-'
%left '*' '/' '%'
%right '!' UNARYPLUS UNARYMINUS
%left '<' '>' LE GE EQ NE
%left '&' '^' '|'
%left AND OR

%%

program:
    class_declaration
    {
        $$ = create_node("Program", 1, $1);
    }
    ;

class_declaration:
    CLASS IDENTIFIER '{' class_body '}'
    {
        $$ = create_node("ClassDeclaration", 3, create_leaf("ClassName", $2), $4);
    }
    ;

class_body:
    /* empty */
    {
        $$ = create_node("ClassBody", 0);
    }
    | class_member_declaration
    {
        $$ = create_node("ClassBody", 1, $1);
    }
    | class_body class_member_declaration
    {
        $$ = create_node("ClassBody", 2, $1, $2);
    }
    ;

class_member_declaration:
    method_declaration
    {
        $$ = $1;
    }
    ;

method_declaration:
    method_header method_body
    {
        $$ = create_node("MethodDeclaration", 2, $1, $2);
    }
    ;

method_header:
    method_header_signature
    {
        $$ = create_node("MethodHeader", 1, $1);
    }
    ;

method_header_signature:
    method_header_signature_1
    {
        $$ = $1;
    }
    | method_header_signature_2
    {
        $$ = $1;
    }
    ;

method_header_signature_1:
    PUBLIC type IDENTIFIER '(' ')' 
    {
        $$ = create_node("MethodSignature", 3, create_leaf("Visibility", "Public"), create_leaf("ReturnType", $2), create_leaf("MethodName", $3));
    }
    ;

method_header_signature_2:
    PUBLIC STATIC type IDENTIFIER '(' ')' 
    {
        $$ = create_node("MethodSignature", 4, create_leaf("Visibility", "Public"), create_leaf("Static", "True"), create_leaf("ReturnType", $3), create_leaf("MethodName", $4));
    }
    ;

type:
    VOID
    {
        $$ = create_leaf("Type", "Void");
    }
    | primitive_type
    {
        $$ = $1;
    }
    ;

primitive_type:
    INT
    {
        $$ = create_leaf("Type", "Int");
    }
    | LONG
    {
        $$ = create_leaf("Type", "Long");
    }
    | FLOAT
    {
        $$ = create_leaf("Type
