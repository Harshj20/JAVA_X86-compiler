%{
#include <bits/stdc++.h>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
extern int yylex();
extern int yylineno;
void yyerror(char* s){
    printf("Error123 %s in line %d\n",s,yylineno);
}

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

%token k_abstract k_assert k_boolean k_break k_byte k_case k_catch k_char k_class k_const k_continue k_default k_do k_double k_else k_enum k_extends k_final k_finally k_float k_for k_goto k_if k_implements k_import k_instanceof k_int k_interface k_long k_native k_new k_package k_private k_protected k_public k_return k_short k_static k_strictfp k_super k_switch k_synchronized k_this k_throw k_throws k_transient k_try k_void k_volatile k_while k_underscore
%token k_exports k_module k_non_sealed k_open k_opens k_permits k_provide k_record k_requires k_sealed k_to k_transitive k_uses k_var k_with k_yield 

%token o_assign o_add_assign o_subtract_assign o_multiply_assign o_divide_assign o_modulo_assign o_bitwise_and_assign o_bitwise_or_assign o_bitwise_xor_assign o_left_shift_assign o_right_shift_assign o_unsigned_right_shift_assign o_bitwise_and o_bitwise_or o_bitwise_xor o_left_shift o_right_shift o_unsigned_right_shift o_add o_subtract o_multiply o_divide o_modulo o_less_than o_less_than_or_equal o_greater_than o_greater_than_or_equal o_equals o_not_equals o_logical_and o_logical_not o_logical_or o_increment o_decrement o_bitwise_complement o_question_mark o_colon o_arrow

%token Identifier Literal 

%token s_open_paren s_close_paren s_open_curly_bracket s_close_curly_bracket s_open_square_bracket s_close_square_bracket s_semicolon s_comma s_dot s_varargs s_double_colon


%%
//19.2 Productions from §2.3: The Syntactic Grammar
Goal: CompilationUnit {printf("Executed\n");}



//19.4 Productions from §4: Types, Values, and Variables */

Type: PrimitiveType
    | ReferenceType

PrimitiveType: NumericType
            |k_boolean

NumericType:IntegralType
    |FloatingPointType

IntegralType: k_byte
            |k_short
            |k_int 
            |k_long 
            |k_char

FloatingPointType: k_float | k_double

ReferenceType:ClassOrInterfaceType
	         |ArrayType

ClassOrInterfaceType:Name

ClassType:ClassOrInterfaceType

InterfaceType:ClassOrInterfaceType

ArrayType: PrimitiveType s_open_square_bracket s_close_square_bracket
	| Name s_open_square_bracket s_close_square_bracket
	|ArrayType s_open_square_bracket s_close_square_bracket


//19.5 Productions from §6: Names

Name:SimpleName
	| QualifiedName

SimpleName: Identifier

QualifiedName: Name s_dot Identifier

//19.6 Productions from §7: Packages

CompilationUnit: PackageDeclaration ImportDeclarations TypeDeclarations
                | PackageDeclaration ImportDeclarations
                | PackageDeclaration TypeDeclarations
                | PackageDeclaration
                | ImportDeclarations TypeDeclarations
                | TypeDeclarations
                //|
                | ImportDeclarations

ImportDeclarations: ImportDeclaration | ImportDeclarations ImportDeclaration

TypeDeclarations:TypeDeclaration 
	            |TypeDeclarations TypeDeclaration

PackageDeclaration: k_package Name s_semicolon

ImportDeclaration: SingleTypeImportDeclaration
	              |TypeImportOnDemandDeclaration

SingleTypeImportDeclaration: k_import Name s_semicolon

TypeImportOnDemandDeclaration: k_import Name s_dot o_multiply s_semicolon

TypeDeclaration: ClassDeclaration
	            |InterfaceDeclaration
                | s_semicolon
//19.7 Productions Used Only in the LALR(1) Grammar

Modifiers:Modifier
         |Modifiers Modifier

Modifier: k_public 
        | k_protected 
        | k_private
	    | k_static
	    | k_abstract 
        | k_final 
        | k_native 
        | k_synchronized 
        | k_transient 
        | k_volatile

/* 19.8 Productions from §8: Classes
19.8.1 Productions from §8.1: Class Declaration */

ClassDeclaration:

	Modifiers k_class Identifier Super Interfaces ClassBody
    | Modifiers k_class Identifier Super ClassBody
    | Modifiers k_class Identifier Interfaces ClassBody
    | Modifiers k_class Identifier ClassBody
    | k_class Identifier Super Interfaces ClassBody
    | k_class Identifier Super ClassBody
    | k_class Identifier Interfaces ClassBody
    | k_class Identifier ClassBody


Super: k_extends ClassType

Interfaces: k_implements InterfaceTypeList

InterfaceTypeList:InterfaceType
	|InterfaceTypeList s_comma InterfaceType

ClassBody: s_open_curly_bracket ClassBodyDeclarations s_close_curly_bracket | s_open_curly_bracket s_close_curly_bracket

ClassBodyDeclarations:ClassBodyDeclaration
	|ClassBodyDeclarations ClassBodyDeclaration

ClassBodyDeclaration:ClassMemberDeclaration
                    |StaticInitializer
                    |ConstructorDeclaration

ClassMemberDeclaration:FieldDeclaration
                      |MethodDeclaration

//19.8.2 Productions from §8.3: Field Declarations

FieldDeclaration:

	Modifiers Type VariableDeclarators s_semicolon | Type VariableDeclarators s_semicolon

VariableDeclarators:VariableDeclarator
	               |VariableDeclarators s_comma VariableDeclarator

VariableDeclarator: VariableDeclaratorId
	               |VariableDeclaratorId o_assign VariableInitializer

VariableDeclaratorId: Identifier
	                 |VariableDeclaratorId s_open_square_bracket s_close_square_bracket

VariableInitializer:Expression
	               |ArrayInitializer

//19.8.3 Productions from §8.4: Method Declarations

MethodDeclaration: MethodHeader MethodBody

MethodHeader:
	Modifiers Type MethodDeclarator Throws
    | Modifiers Type MethodDeclarator
    |  Type MethodDeclarator Throws
    |  Type MethodDeclarator 
	| Modifiers k_void MethodDeclarator Throws
    | Modifiers k_void MethodDeclarator 
    |  k_void MethodDeclarator Throws
    |  k_void MethodDeclarator 

MethodDeclarator:
	Identifier s_open_paren FormalParameterList s_close_paren
    | Identifier s_open_paren s_close_paren
	| MethodDeclarator s_open_square_bracket s_close_square_bracket

FormalParameterList: FormalParameter
	                |FormalParameterList s_comma FormalParameter

FormalParameter: Type VariableDeclaratorId 
                | k_final Type VariableDeclaratorId 

Throws: k_throws ClassTypeList

ClassTypeList:ClassType
	        | ClassTypeList s_comma ClassType

MethodBody: Block 
	| s_semicolon

StaticInitializer:
	k_static Block
	;

ConstructorDeclaration:

	Modifiers ConstructorDeclarator Throws ConstructorBody
	| Modifiers ConstructorDeclarator ConstructorBody
	| ConstructorDeclarator Throws ConstructorBody
	| ConstructorDeclarator ConstructorBody
	;

ConstructorDeclarator:

	SimpleName s_open_paren FormalParameterList s_close_paren
	|SimpleName s_open_paren s_close_paren
	;

ConstructorBody:

	s_open_curly_bracket s_close_curly_bracket
	| s_open_curly_bracket BlockStatements s_close_curly_bracket
	| s_open_curly_bracket ExplicitConstructorInvocation s_close_curly_bracket
	| s_open_curly_bracket ExplicitConstructorInvocation BlockStatements s_close_curly_bracket
	;

ExplicitConstructorInvocation:

	k_this s_open_paren ArgumentList s_close_paren s_semicolon
	| k_this s_open_paren s_close_paren s_semicolon
	| k_super s_open_paren ArgumentList s_close_paren s_semicolon
	| k_super s_open_paren s_close_paren s_semicolon
	;

// -----------------Production 9
InterfaceDeclaration:

	Modifiers k_interface Identifier ExtendsInterfaces InterfaceBody
	| Modifiers k_interface Identifier InterfaceBody
	| k_interface Identifier ExtendsInterfaces InterfaceBody
	| k_interface Identifier InterfaceBody
	;

ExtendsInterfaces:

	k_extends InterfaceType
	| ExtendsInterfaces s_comma InterfaceType
	;

InterfaceBody:

	s_open_curly_bracket InterfaceMemberDeclarations s_close_curly_bracket
	|s_open_curly_bracket s_close_curly_bracket
	;

InterfaceMemberDeclarations:

	InterfaceMemberDeclaration
	| InterfaceMemberDeclarations InterfaceMemberDeclaration
	;

InterfaceMemberDeclaration:

	ConstantDeclaration
	| AbstractMethodDeclaration
	;

ConstantDeclaration:

	FieldDeclaration
	;

AbstractMethodDeclaration:

	MethodHeader s_semicolon
	;

	// --------------production 10
ArrayInitializer:

	s_open_curly_bracket VariableInitializers s_comma s_close_curly_bracket
	| s_open_curly_bracket VariableInitializers  s_close_curly_bracket
	| s_open_curly_bracket  s_comma s_close_curly_bracket
	| s_open_curly_bracket  s_close_curly_bracket
	;

VariableInitializers:

	VariableInitializer
	| VariableInitializers s_comma VariableInitializer
	;

// ---------Production 14

Block : 
    s_open_curly_bracket s_close_curly_bracket 
    | s_open_curly_bracket BlockStatements s_close_curly_bracket
    ;

BlockStatements : 
    BlockStatement 
    | BlockStatements BlockStatement 
    ; 

BlockStatement : 
    LocalVariableDeclarationStatement 
    | Statement 
    ;

LocalVariableDeclarationStatement : 
    LocalVariableDeclaration s_semicolon
    ;

LocalVariableDeclaration : 
    k_final LocalVariableType VariableDeclarators
    | LocalVariableType VariableDeclarators
    ;

LocalVariableType : Type | k_var

Statement : 
    StatementWithoutTrailingSubstatement 
    | LabeledStatement 
    | IfThenStatement 
    | IfThenElseStatement 
    | WhileStatement 
    | ForStatement 
    ; 

StatementNoShortIf : 
    StatementWithoutTrailingSubstatement
    | LabeledStatementNoShortIf 
    | IfThenElseStatementNoShortIf 
    | WhileStatementNoShortIf 
    | ForStatementNoShortIf 
    ; 

StatementWithoutTrailingSubstatement : 
    Block 
    | EmptyStatement 
    | ExpressionStatement 
    | BreakStatement 
    | ContinueStatement 
    | ReturnStatement  
    | SynchronizedStatement 
    | ThrowStatement 
    | TryStatement 
    ;

EmptyStatement:
	s_semicolon
	;

LabeledStatement:

	Identifier o_colon Statement
	;

LabeledStatementNoShortIf:

	Identifier o_colon StatementNoShortIf

ExpressionStatement:

	StatementExpression s_semicolon
	;

StatementExpression:

	Assignment
	| PreIncrementExpression
	| PreDecrementExpression
	| PostIncrementExpression
	| PostDecrementExpression
	| MethodInvocation
	| ClassInstanceCreationExpression
	;

IfThenStatement : 
    k_if s_open_paren Expression s_close_paren Statement 
    ;


IfThenElseStatement : 
    k_if s_open_paren Expression s_close_paren StatementNoShortIf k_else Statement 
    ;

IfThenElseStatementNoShortIf : 
    k_if s_open_paren Expression s_close_paren StatementNoShortIf k_else StatementNoShortIf 
    ;


WhileStatement : 
    k_while s_open_paren Expression s_close_paren Statement 
    ;

WhileStatementNoShortIf : 
    k_while s_open_paren Expression s_close_paren StatementNoShortIf 
    ;

ForStatement:

	k_for s_open_paren s_semicolon s_semicolon s_close_paren Statement 
    | k_for s_open_paren s_semicolon s_semicolon ForUpdate s_close_paren Statement 
    | k_for s_open_paren s_semicolon Expression s_semicolon s_close_paren Statement 
    | k_for s_open_paren s_semicolon Expression s_semicolon ForUpdate s_close_paren Statement 
    | k_for s_open_paren ForInit s_semicolon s_semicolon s_close_paren Statement 
    | k_for s_open_paren ForInit s_semicolon s_semicolon ForUpdate s_close_paren Statement 
    | k_for s_open_paren ForInit s_semicolon Expression s_semicolon s_close_paren Statement 
    | k_for s_open_paren ForInit s_semicolon Expression s_semicolon ForUpdate s_close_paren Statement 
    ;


ForStatementNoShortIf:

	k_for s_open_paren s_semicolon s_semicolon s_close_paren StatementNoShortIf
    | k_for s_open_paren s_semicolon s_semicolon ForUpdate s_close_paren StatementNoShortIf
    | k_for s_open_paren s_semicolon Expression s_semicolon s_close_paren StatementNoShortIf
    | k_for s_open_paren s_semicolon Expression s_semicolon ForUpdate s_close_paren StatementNoShortIf
    | k_for s_open_paren ForInit s_semicolon s_semicolon s_close_paren StatementNoShortIf
    | k_for s_open_paren ForInit s_semicolon s_semicolon ForUpdate s_close_paren StatementNoShortIf
    | k_for s_open_paren ForInit s_semicolon Expression s_semicolon s_close_paren StatementNoShortIf
    | k_for s_open_paren ForInit s_semicolon Expression s_semicolon ForUpdate s_close_paren StatementNoShortIf
    ;

ForInit : 
    StatementExpressionList 
    | LocalVariableDeclaration 
    ;

ForUpdate : 
	StatementExpressionList 
	;

StatementExpressionList:StatementExpression
                       |StatementExpressionList s_comma StatementExpression

BreakStatement: k_break s_semicolon | k_break Identifier s_semicolon

ContinueStatement: k_continue s_semicolon | k_continue Identifier s_semicolon

ReturnStatement: k_return s_semicolon | k_return Expression s_semicolon

ThrowStatement: k_throw s_semicolon | k_throw Expression s_semicolon

SynchronizedStatement:

	k_synchronized s_open_paren Expression s_close_paren Block

TryStatement: k_try Block Catches
	        | k_try Block Finally
            | k_try Block Catches Finally

Catches: CatchClause
        |Catches CatchClause

CatchClause: k_catch s_open_paren FormalParameter s_close_paren Block

Finally: k_finally Block


// ------------------ Production 15 -------------------

Primary:
    PrimaryNoNewArray
    | ArrayCreationExpression
    ;

PrimaryNoNewArray:
    Literal
    | k_this
    | s_open_paren Expression s_close_paren
    | ClassInstanceCreationExpression
    | FieldAccess
    | MethodInvocation
    | ArrayAccess
    ;

ClassInstanceCreationExpression:
    k_new ClassType s_open_paren s_close_paren
    | k_new ClassType s_open_paren ArgumentList s_close_paren
    ;

ArgumentList:
    Expression
    | ArgumentList s_comma Expression
    ;

ArrayCreationExpression:
    k_new PrimitiveType DimExprs 
    | k_new PrimitiveType Dims ArrayInitializer
    | k_new PrimitiveType DimExprs Dims
    | k_new Name DimExprs 
    | k_new Name DimExprs Dims
    | k_new Name Dims ArrayInitializer
    ;


DimExprs:
    DimExpr
    | DimExprs DimExpr
    ;

DimExpr:
    s_open_square_bracket Expression s_close_square_bracket;


Dims:
    s_open_square_bracket s_close_square_bracket
    | Dims s_open_square_bracket s_close_square_bracket
    ;

FieldAccess:
    Primary s_dot Identifier
    | k_super s_dot Identifier
    ;

MethodInvocation:
    Name s_open_paren s_close_paren
    | Name s_open_paren ArgumentList s_close_paren
    | Primary s_dot Identifier s_open_paren s_close_paren
    | Primary s_dot Identifier s_open_paren ArgumentList s_close_paren
    | k_super s_dot Identifier s_open_paren s_close_paren
    | k_super s_dot Identifier s_open_paren ArgumentList s_close_paren
    ;

ArrayAccess:
    Name s_open_square_bracket Expression s_close_square_bracket
    | PrimaryNoNewArray s_open_square_bracket Expression s_close_square_bracket
    ;

PostFixExpression:
    Primary
    | Name
    | PostIncrementExpression
    | PostDecrementExpression
    ;

PostIncrementExpression:
    PostFixExpression o_increment
    ;

PostDecrementExpression:
    PostFixExpression o_decrement
    ;

UnaryExpression:
    PreIncrementExpression
    | PreDecrementExpression
    | o_add UnaryExpression
    | o_subtract UnaryExpression
    | UnaryExpressionNotPlusMinus
    ;

PreIncrementExpression:
    o_increment UnaryExpression
    ;

PreDecrementExpression:
    o_decrement UnaryExpression
    ;

UnaryExpressionNotPlusMinus:
   PostFixExpression
    | o_bitwise_complement UnaryExpression
    | o_logical_not UnaryExpression
    | CastExpression
    ;

CastExpression:
    s_open_paren PrimitiveType s_close_paren UnaryExpression
    | s_open_paren PrimitiveType Dims s_close_paren UnaryExpression
    | s_open_paren Expression s_close_paren UnaryExpressionNotPlusMinus
    | s_open_paren Name  Dims s_close_paren UnaryExpressionNotPlusMinus
    ;

MultiplicativeExpression:
    UnaryExpression
    | MultiplicativeExpression o_multiply UnaryExpression
    | MultiplicativeExpression o_divide UnaryExpression
    | MultiplicativeExpression o_modulo UnaryExpression
    ;

AdditiveExpression:
    MultiplicativeExpression
    | AdditiveExpression o_add MultiplicativeExpression
    | AdditiveExpression o_subtract MultiplicativeExpression
    ;

ShiftExpression:   
    AdditiveExpression
    | ShiftExpression o_left_shift AdditiveExpression
    | ShiftExpression o_right_shift AdditiveExpression
    | ShiftExpression o_unsigned_right_shift AdditiveExpression
    ;

RelationalExpression:
    ShiftExpression
    | RelationalExpression o_less_than ShiftExpression
    | RelationalExpression o_greater_than ShiftExpression
    | RelationalExpression o_less_than_or_equal ShiftExpression
    | RelationalExpression o_greater_than_or_equal ShiftExpression
    | RelationalExpression k_instanceof ReferenceType
    ;

EqualityExpression:
    RelationalExpression
    | EqualityExpression o_equals RelationalExpression
    | EqualityExpression o_not_equals RelationalExpression
    ;

AndExpression:  
    EqualityExpression
    | AndExpression o_bitwise_and EqualityExpression
    ;

ExclusiveOrExpression:  
    AndExpression
    | ExclusiveOrExpression o_bitwise_xor AndExpression
    ;

InclusiveOrExpression:  
    ExclusiveOrExpression
    | InclusiveOrExpression o_bitwise_or ExclusiveOrExpression
    ;

ConditionalAndExpression:
    InclusiveOrExpression
    | ConditionalAndExpression o_logical_and InclusiveOrExpression
    ;

ConditionalOrExpression:
    ConditionalAndExpression
    | ConditionalOrExpression o_logical_or ConditionalAndExpression
    ;

ConditionalExpression:  
    ConditionalOrExpression
    | ConditionalOrExpression o_question_mark Expression o_colon ConditionalExpression
    ;

AssignmentExpression:
    ConditionalExpression
    | Assignment
    ;   

Assignment:
    LeftHandSide AssignmentOperator Expression
    ;

LeftHandSide:   
    Name
    | FieldAccess
    | ArrayAccess
    ;

AssignmentOperator:
    o_assign
    | o_add_assign
    | o_subtract_assign
    | o_multiply_assign
    | o_divide_assign
    | o_modulo_assign
    | o_left_shift_assign
    | o_right_shift_assign
    | o_unsigned_right_shift_assign
    | o_bitwise_and_assign
    | o_bitwise_or_assign
    | o_bitwise_xor_assign
    ;

Expression:
    AssignmentExpression
    ;

%%

int main(){
    yyparse();
    return 0;
}
