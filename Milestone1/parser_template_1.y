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


%type <string> type_specifier
%type <string> class_declaration
%type <string> field_declaration
%type <string> method_declaration
%type <string> block_statement
%type <string> statement
%type <string> Expression
%type <string> primary_Expression
%type <string> postfix_Expression
%type <string> argument_list
%type <string> variable_declaration
%type <string> variable_declarator

%%
// ------ Start ------- 
CompilationUnit : TopLevelClassOrInterfaceDeclarations {printf("Executed");};

TopLevelClassOrInterfaceDeclarations : 
TopLevelClassOrInterfaceDeclaration
| TopLevelClassOrInterfaceDeclaration TopLevelClassOrInterfaceDeclarations ;

TopLevelClassOrInterfaceDeclaration :
ClassDeclaration 


//  --------------------ignore--------------
VariableDeclaratorList : 
    VariableDeclarator 
    | VariableDeclarator s_comma VariableDeclaratorList 
    ;

VariableDeclarator : 
    VariableDeclaratorId
    | VariableDeclaratorId o_assign VariableInitializer
    ;

VariableDeclaratorId : 
    Identifier | Identifier Dims 
    ;

VariableInitializer : 
    Expression
    | ArrayInitializer
    ;
// --------------------ignore------------

// ------------production 3--------------

// ------production 4-------

Type : 
    PrimitiveType 
    | ReferenceType 
    ;

PrimitiveType : 
    NumericType 
    | k_boolean 
    ;

NumericType : 
    IntegralType 
    | FloatingPointType 
    ;

IntegralType : 
    k_byte 
    | k_short 
    | k_int 
    | k_long 
    | k_char
    ;

FloatingPointType : 
    k_float 
    | k_double
    ;

ReferenceType : 
    ClassType 
    | ArrayType 
    ;

// ClassType: ClassType /*| InterfaceType*/ ;

// ClassType: Identifier //
//             | ClassType s_dot Identifier //
//             | ClassType s_dot Identifier /**/ ;
//: | TypeArguments;

//InterfaceType: ClassType ;

ArrayType: 
    PrimitiveType Dims
    | ClassType Dims
    // | Identifier Dims
    ;

Dims: 
    s_open_square_bracket s_close_square_bracket 
    | s_open_square_bracket s_close_square_bracket Dims 
    ;

//  -------------------Production 6----------------

ClassType: 
    Identifier
    | ClassType s_dot Identifier
    ;

// --------------production 10-----------
ArrayInitializer:
    s_open_curly_bracket VariableInitializerList s_close_curly_bracket
    | s_open_curly_bracket VariableInitializerList s_comma s_close_curly_bracket
    | s_open_curly_bracket s_comma s_close_curly_bracket
    | s_open_curly_bracket s_close_curly_bracket
    ;

VariableInitializerList:
    VariableInitializer 
    | VariableInitializer s_comma VariableInitializerList
    ;


Expression: /*LambdaExpression |*/ AssignmentExpression ;


// -----------production 8 + production 14--------------
Block : 
    s_open_curly_bracket s_close_curly_bracket 
    | s_open_curly_bracket BlockStatements s_close_curly_bracket
    ;

BlockStatements : 
    BlockStatement 
    | BlockStatement BlockStatements 
    ; 

BlockStatement : 
    /*LocalClassDeclaration 
    |*/ LocalVariableDeclarationStatement 
    | Statement 
    ;

LocalVariableDeclarationStatement : 
    LocalVariableDeclaration s_semicolon
    ;

LocalVariableDeclaration : 
    // k_final LocalVariableType VariableDeclaratorList
    LocalVariableType VariableDeclaratorList 
    ;

LocalVariableType : 
    Type 
    | k_var
    ;

/* LocalClassDeclaration : 
    ClassDeclaration /*| NormalInterface Declaration
    ; */

ClassDeclaration : 
    NormalClassDeclaration 
    // | EnumDeclaration 
    //| RecordDeclaration 
    ;

NormalClassDeclaration : 
    // Modifiers k_class Identifier ClassExtends /*classimplements*/ ClassPermits ClassBody
     Modifiers k_class Identifier  /*classimplements*/  ClassBody 
    | Modifiers k_class Identifier ClassExtends /*classimplements*/ ClassBody 
    // | Modifiers k_class Identifier  /*classimplements*/ ClassPermits ClassBody 
    // |  k_class Identifier ClassExtends /*classimplements*/ ClassPermits ClassBody 
    |  k_class Identifier ClassExtends /*classimplements*/ ClassBody 
    |  k_class Identifier  /*classimplements*/ ClassBody 
    // |  k_class Identifier  /*classimplements*/ ClassPermits ClassBody  
    ;

ClassExtends : 
    k_extends ClassType
    ;

// ClassPermits : 
//     k_permits ClassType
//     | ClassPermits s_comma ClassType
//     ; 

 
ClassBody: 
    s_open_curly_bracket ClassBodyDeclarations s_close_curly_bracket
    | s_open_curly_bracket s_close_curly_bracket 
    ;

ClassBodyDeclarations : 
    ClassBodyDeclaration 
    | ClassBodyDeclaration ClassBodyDeclarations
    ;

ClassBodyDeclaration : 
    ClassMemberDeclaration 
    //| Block 
    | StaticInitializer 
    | ConstructorDeclaration 
    ;

ClassMemberDeclaration : 
    FieldDeclaration 
    | MethodDeclaration 
    // | ClassDeclaration 
   // | /*InterfaceDeclaration |*/ s_semicolon 
    ;

FieldDeclaration: 
    Modifiers Type VariableDeclaratorList s_semicolon 
    | Type VariableDeclaratorList s_semicolon 
    ;

Modifiers : 
    Modifier 
    | Modifier Modifiers
    ;

Modifier : 
    k_public 
    | k_protected 
    | k_private 
    | k_static 
    | k_final 
    | k_transient 
    | k_volatile 
    | k_abstract
    | k_synchronized
    | k_sealed 
    | k_non_sealed 
    | k_strictfp 
    ;

MethodDeclaration : 
     MethodHeader MethodBody
    ;


MethodHeader: 
    Type MethodDeclarator Throws 
    | Type MethodDeclarator
    | k_void MethodDeclarator Throws 
    | k_void MethodDeclarator
    | Modifiers Type MethodDeclarator Throws 
    | Modifiers Type MethodDeclarator
    | Modifiers k_void MethodDeclarator Throws 
    | Modifiers k_void MethodDeclarator
    ;

MethodDeclarator : 
    // Identifier s_open_paren ReceiverParameter FormalParameterList s_close_paren Dims
    // | Identifier s_open_paren ReceiverParameter FormalParameterList s_close_paren 
    // | Identifier s_open_paren ReceiverParameter s_close_paren Dims
    // | Identifier s_open_paren ReceiverParameter s_close_paren 
     Identifier s_open_paren  FormalParameterList s_close_paren Dims
    | Identifier s_open_paren  FormalParameterList s_close_paren 
    | Identifier s_open_paren s_close_paren Dims
    | Identifier s_open_paren s_close_paren 
    
    ;  

// ReceiverParameter: 
//     Type  k_this | Type Identifier s_dot k_this
//     ;

FormalParameterList : 
    FormalParameter 
    | FormalParameter s_comma FormalParameterList 
    ;

FormalParameter: 
    // k_final Type VariableDeclaratorId
     Type VariableDeclaratorId  
    // | VariableArityParameter
    ;

// VariableArityParameter : 
//     VariableArityRecordComponent
//     |k_final Type s_varargs Identifier 
//     ;

Throws: 
    k_throws ExceptionTypeList
    ;

ExceptionTypeList: 
    ExceptionType 
    | ExceptionType s_comma ExceptionTypeList 
    ;

ExceptionType: 
    ClassType
    ;

MethodBody: 
    Block 
    | s_semicolon 
    ; 

StaticInitializer: 
    k_static Block 
    ;

ConstructorDeclaration: 
    Modifiers ConstructorDeclarator Throws ConstructorBody 
    | Modifiers ConstructorDeclarator ConstructorBody
    |  ConstructorDeclarator Throws ConstructorBody
    |  ConstructorDeclarator ConstructorBody
    ;

ConstructorDeclarator: 
    // Identifier s_open_paren ReceiverParameter FormalParameterList s_close_paren 
    // | Identifier s_open_paren ReceiverParameter s_close_paren
     Identifier s_open_paren  FormalParameterList s_close_paren 
    | Identifier s_open_paren s_close_paren 
    ;

ConstructorBody: 
    s_open_curly_bracket s_close_curly_bracket 
    | s_open_curly_bracket BlockStatements s_close_curly_bracket
    | s_open_curly_bracket ExplicitConstructorInvocation s_close_curly_bracket 
    | s_open_curly_bracket ExplicitConstructorInvocation BlockStatements s_close_curly_bracket
    ;

ExplicitConstructorInvocation: 
    k_this s_open_paren ArgumentList s_close_paren s_semicolon 
    | k_super s_open_paren  ArgumentList s_close_paren s_semicolon 
    // | ClassType s_dot k_super s_open_paren  ArgumentList s_close_paren s_semicolon 
    // | Primary s_dot k_super s_open_paren  ArgumentList s_close_paren s_semicolon
    | k_this s_open_paren s_close_paren s_semicolon 
    | k_super s_open_paren  s_close_paren s_semicolon 
    // | ClassType s_dot k_super s_open_paren  s_close_paren s_semicolon 
    // | Primary s_dot k_super s_open_paren  s_close_paren s_semicolon
    ; 

ArgumentList : 
    Expression 
    | Expression s_comma ArgumentList 
    ;

// EnumDeclaration : 
//     Modifiers k_enum Identifier EnumBody 
//     | k_enum Identifier EnumBody
//     ; 

// EnumBody: 
//     s_open_curly_bracket EnumConstantList s_comma EnumBodyDeclarations s_close_curly_bracket
//     | s_open_curly_bracket EnumConstantList s_comma s_close_curly_bracket
//     | s_open_curly_bracket EnumConstantList EnumBodyDeclarations s_close_curly_bracket
//     | s_open_curly_bracket EnumConstantList  s_close_curly_bracket
//     | s_open_curly_bracket s_comma EnumBodyDeclarations s_close_curly_bracket
//     | s_open_curly_bracket s_comma  s_close_curly_bracket
//     | s_open_curly_bracket EnumBodyDeclarations s_close_curly_bracket
//     | s_open_curly_bracket  s_close_curly_bracket 
//     ;

// EnumConstantList: 
//     EnumConstant 
//     | EnumConstant s_comma EnumConstantList 
//     ;

// EnumConstant: 
//     Identifier 
//     | Identifier op_enum_constant ClassBody
//     | Identifier ClassBody
//     | Identifier op_enum_constant
//     ;


// op_enum_constant : s_open_paren s_close_paren | s_open_paren ArgumentList s_close_paren ;

// EnumBodyDeclarations: 
//     s_semicolon ClassBodyDeclarations
//     | s_semicolon 
//     ;

/* RecordDeclaration: 
    ClassModifiers k_record Identifier RecordHeader RecordBody 
    | k_record Identifier RecordHeader RecordBody 
    ;

RecordBody : 
    s_open_curly_bracket RecordBodyDeclarations s_close_curly_bracket 
    | s_open_curly_bracket  s_close_curly_bracket 
    
    ;
RecordBodyDeclarations:
    RecordBodyDeclaration
    | RecordBodyDeclaration RecordBodyDeclarations
    ;

RecordBodyDeclaration :
    ClassBodyDeclaration 
    | CompactConstructorDeclaration 
    ;

CompactConstructorDeclaration : 
    ConstructorModifiers SimpleClassType ConstructorBody 
    | SimpleClassType ConstructorBody 
    ;

RecordHeader : 
    s_open_paren RecordComponentList s_close_paren | s_open_paren  s_close_paren 
    ;

RecordComponentList : 
    RecordComponent 
    | RecordComponent s_comma RecordComponentList 
    ;

RecordComponent : 
    Type Identifier 
    | VariableArityRecordComponent 
    ;*/

// VariableArityRecordComponent : 
//     Type s_varargs Identifier 
//     ; 


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

EmptyStatement : 
    s_semicolon 
    ; 

LabeledStatement : 
    Identifier o_colon Statement 
    ;

LabeledStatementNoShortIf : 
    Identifier o_colon StatementNoShortIf 
    ;

ExpressionStatement : 
    StatementExpression s_semicolon 
    ;

StatementExpression : 
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

ForStatement : 
    BasicForStatement 
    // | EnhancedForStatement 
    ; 
ForStatementNoShortIf : 
    BasicForStatementNoShortIf 
    // | EnhancedForStatementNoShortIf 
    ;

BasicForStatement : 
    k_for s_open_paren s_semicolon s_semicolon s_close_paren Statement 
    | k_for s_open_paren s_semicolon s_semicolon ForUpdate s_close_paren Statement 
    | k_for s_open_paren s_semicolon Expression s_semicolon s_close_paren Statement 
    | k_for s_open_paren s_semicolon Expression s_semicolon ForUpdate s_close_paren Statement 
    | k_for s_open_paren ForInit s_semicolon s_semicolon s_close_paren Statement 
    | k_for s_open_paren ForInit s_semicolon s_semicolon ForUpdate s_close_paren Statement 
    | k_for s_open_paren ForInit s_semicolon Expression s_semicolon s_close_paren Statement 
    | k_for s_open_paren ForInit s_semicolon Expression s_semicolon ForUpdate s_close_paren Statement 
    ;
// k_FOR: k_for {printf("Printing for\n");};
BasicForStatementNoShortIf: 
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
    StatementExpressionList {printf("Forinti statement\n");}
    | LocalVariableDeclaration 
    ;
ForUpdate : StatementExpressionList ;
StatementExpressionList : 
StatementExpression
| StatementExpression s_comma StatementExpressionList

// EnhancedForStatement : k_for s_open_paren LocalVariableDeclaration o_colon Expression s_close_paren Statement
// EnhancedForStatementNoShortIf : k_for s_open_paren LocalVariableDeclaration o_colon Expression s_close_paren StatementNoShortIf
BreakStatement : k_break | k_break Identifier;
/*YieldStatement : k_yield Expression ;*/
ContinueStatement : k_continue | k_continue Identifier ;
ReturnStatement : k_return | k_return Expression ;


ThrowStatement: 
    k_throw Expression 
    ;

SynchronizedStatement: 
    k_synchronized s_open_paren Expression s_close_paren Block 
    ;

TryStatement: 
    k_try Block Catches 
    | k_try Block Finally 
    | k_try Block Catches Finally 
    //| TryWithResourcesStatement 
    ;

Catches: 
    CatchClause 
    | CatchClause Catches 
    ;

CatchClause: 
    k_catch s_open_paren FormalParameter s_open_paren Block 
    ;

// CatchFormalParameter: 
//     CatchType VariableDeclaratorId 
//     ;
// CatchType:  
//     ClassType 
//     | ClassType o_bitwise_or CatchType 
//     ;
Finally: 
    k_finally Block 
    ;

/* TryWithResourcesStatement: 
    k_try ResourceSpecification Block Catches Finally
    | k_try ResourceSpecification Block Finally
    | k_try ResourceSpecification Block Catches 
    | k_try ResourceSpecification Block 
    ;

ResourceSpecification:
    s_open_paren ResourceList o_colon s_close_paren
    | s_open_paren ResourceList s_close_paren
    ; 
ResourceList: 
    Resource 
    | Resource o_colon ResourceList 
    ;
Resource: 
    LocalVariableDeclaration 
    | VariableAccess 
    ;
VariableAccess : 
    ClassType 
    | FieldAccess
     ;*/
// Pattern: 
//     TypePattern 
//     ;
// TypePattern: 
//     LocalVariableDeclaration 
//     ;

Primary:
    PrimaryNoNewArray
    | ArrayCreationExpression {printf("Primary\n");}
    ;

PrimaryNoNewArray:
    Literal
    //| ClassLiteral
    | k_this
    // | ClassType s_dot k_this
    | s_open_paren Expression s_close_paren
    | ClassInstanceCreationExpression
    | FieldAccess
    | ArrayAccess
    | MethodInvocation
    // MethodReference
    ;

/* ClassLiteral: 
    ClassType s_dot k_class
    | NumericType s_dot k_class
    | k_boolean s_dot k_class
    | ClassType Dims s_dot k_class
    | NumericType Dims s_dot k_class
    | k_boolean Dims s_dot k_class
    | k_void s_dot k_class
    ; */
    
ClassInstanceCreationExpression:
    UnqualifiedClassInstanceCreationExpression
    // | ClassType s_dot UnqualifiedClassInstanceCreationExpression
    // | Primary s_dot UnqualifiedClassInstanceCreationExpression
    ;

UnqualifiedClassInstanceCreationExpression:
    k_new  ClassType s_open_paren s_close_paren 
    // | k_new  ClassType s_open_paren s_close_paren ClassBody 
    | k_new  ClassType s_open_paren ArgumentList s_close_paren 
    // | k_new  ClassType s_open_paren ArgumentList s_close_paren ClassBody
    ;

// ClassTypeToInstantiate:
//     Identifier  
//     | Identifier s_dot ClassTypeToInstantiate
//     ;

FieldAccess:
    Primary s_dot Identifier
    | k_super s_dot Identifier
    // | ClassType s_dot k_super s_dot Identifier
    ;

ArrayAccess:
    ClassType s_open_square_bracket Expression s_close_square_bracket
    | PrimaryNoNewArray s_open_square_bracket Expression s_close_square_bracket
    ;

MethodInvocation:
    ClassType s_open_paren s_close_paren
    | ClassType s_open_paren ArgumentList s_close_paren
    // | ClassType s_dot  Identifier s_open_paren s_close_paren
    | Primary s_dot  Identifier s_open_paren s_close_paren
    | Primary s_dot  Identifier s_open_paren ArgumentList s_close_paren
    | k_super s_dot  Identifier s_open_paren s_close_paren
    | k_super s_dot  Identifier s_open_paren ArgumentList s_close_paren
    // | ClassType s_dot k_super s_dot Identifier s_open_paren s_close_paren
    // | ClassType s_dot  Identifier s_open_paren ArgumentList s_close_paren
    // | ClassType s_dot k_super s_dot  Identifier s_open_paren ArgumentList s_close_paren
    ;

/* MethodReference:
    ClassType s_double_colon  Identifier
    | Primary s_double_colon  Identifier
    | ReferenceType s_double_colon  Identifier
    | k_super s_double_colon  Identifier
    | ClassType s_dot k_super s_double_colon  Identifier
    | ClassType s_double_colon  k_new
    | ArrayType s_double_colon k_new
    ; */

ArrayCreationExpression:
    k_new PrimitiveType DimExprs 
    | k_new PrimitiveType Dims ArrayInitializer
    | k_new PrimitiveType DimExprs Dims
    | k_new ClassType DimExprs 
    | k_new ClassType DimExprs Dims
    // | k_new ClassType Dims ArrayInitializer
    ;

DimExprs: 
    DimExpr
    | DimExpr DimExprs
    ;

DimExpr:
    s_open_square_bracket Expression s_close_square_bracket
    ;

/* LambdaExpression:
    LambdaParameters o_arrow LambdaBody */
// -- variable:
// --     ID
// --     ;

// -- constant:
// --     INT_LITERAL
// --     | DOUBLE_LITERAL
// --     | BOOL_LITERAL
// --     ;
//s_LambdaParameter: | s_comma LambdaParameter s_LambdaParameter;

// s_Identifier: | s_comma Identifier s_Identifier;


/* LambdaParameters:
    s_open_paren s_close_paren
    | s_open_paren LambdaParameterList s_close_paren
    | Identifier
    ;
LambdaParameterList:
     LambdaParameter s_LambdaParameter
    | Identifier s_Identifier
    ;
LambdaParameter:
    s_VariableModifier LambdaParameterType VariableDeclaratorId
    | VariableArityParameter
LambdaParameterType:
    Type
    | k_var
    ;
LambdaBody:
    Expression
    | Block
    ; */

AssignmentExpression:
    ConditionalExpression
    | Assignment 
    ;

Assignment:
    LeftHandSide AssignmentOperator AssignmentExpression
    ;

LeftHandSide:
    ClassType
    | FieldAccess
    | ArrayAccess
    ;

AssignmentOperator:
    o_equals
    | o_multiply_assign
    | o_divide_assign
    | o_modulo_assign
    | o_add_assign
    | o_subtract_assign
    | o_left_shift_assign
    | o_right_shift_assign
    | o_unsigned_right_shift_assign
    | o_bitwise_and_assign
    | o_bitwise_xor_assign
    | o_bitwise_or_assign
    ;

ConditionalExpression:
    ConditionalOrExpression
    | ConditionalOrExpression o_question_mark Expression o_colon ConditionalExpression
    // ConditionalOrExpression o_question_mark Expression o_colon //LambdaExpression
    ;

ConditionalOrExpression:
    ConditionalAndExpression
    | ConditionalOrExpression o_logical_or ConditionalAndExpression
    ;

ConditionalAndExpression:
    InclusiveOrExpression
    | ConditionalAndExpression o_logical_and InclusiveOrExpression
    ;

InclusiveOrExpression:
    ExclusiveOrExpression
    | InclusiveOrExpression o_bitwise_or ExclusiveOrExpression
    ;

ExclusiveOrExpression:
    AndExpression
    | ExclusiveOrExpression o_bitwise_xor AndExpression
    ;

AndExpression:
    EqualityExpression
    | AndExpression o_bitwise_and EqualityExpression
    ;

EqualityExpression:
    RelationalExpression
    | EqualityExpression o_equals RelationalExpression
    | EqualityExpression o_not_equals RelationalExpression
    ;

RelationalExpression:
    ShiftExpression
    | RelationalExpression o_less_than ShiftExpression
    | RelationalExpression o_greater_than ShiftExpression
    | RelationalExpression o_less_than_or_equal ShiftExpression
    | RelationalExpression o_greater_than_or_equal ShiftExpression
    | RelationalExpression k_instanceof ReferenceType
    ;

// InstanceOfExpression:
//     RelationalExpression k_instanceof ReferenceType
//     | RelationalExpression k_instanceof Pattern
//     ;

ShiftExpression:
    AdditiveExpression
    | ShiftExpression o_left_shift AdditiveExpression
    | ShiftExpression o_right_shift AdditiveExpression
    | ShiftExpression o_unsigned_right_shift AdditiveExpression
    ;

AdditiveExpression:
    MultiplicativeExpression
    | AdditiveExpression o_add MultiplicativeExpression
    | AdditiveExpression o_subtract MultiplicativeExpression
    ;

MultiplicativeExpression:
    UnaryExpression
    | MultiplicativeExpression o_multiply UnaryExpression
    | MultiplicativeExpression o_divide UnaryExpression
    | MultiplicativeExpression o_modulo UnaryExpression
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
    PostfixExpression
    | o_logical_not UnaryExpression
    | o_bitwise_complement UnaryExpression
    | CastExpression
    ;

PostfixExpression:
    Primary {printf("Primary printing literal at line %d\n", yylineno);}
    | PostIncrementExpression
    | PostDecrementExpression
    | ClassType
    ;

PostIncrementExpression:    
    PostfixExpression o_increment
    ;

PostDecrementExpression:
    PostfixExpression o_decrement
    ;

CastExpression:
    s_open_paren PrimitiveType s_close_paren UnaryExpression
    | s_open_paren PrimitiveType Dims s_close_paren UnaryExpression
    | s_open_paren Expression s_close_paren UnaryExpressionNotPlusMinus
    | s_open_paren ClassType Dims s_close_paren UnaryExpressionNotPlusMinus
    /* | s_open_paren ReferenceType AdditionalBounds s_close_paren UnaryExpressionNotPlusMinus
    | s_open_paren ReferenceType AdditionalBounds s_close_paren LambdaExpression */
    ;
    
%%

int main(){
    yyparse();
    return 0;
}
