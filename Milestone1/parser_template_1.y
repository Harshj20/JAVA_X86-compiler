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

%token k_abstract k_assert k_boolean k_break k_byte k_case k_catch k_char k_class k_const k_continue k_default k_do k_double k_else k_enum k_extends k_final k_finally k_float k_for k_goto k_if k_implements k_import k_instanceof k_int k_interface k_long k_native k_new k_package k_private k_protected k_public k_return k_short k_static k_strictfp k_super k_switch k_synchronized k_this k_throw k_throws k_transient k_try k_void k_volatile k_while k_underscore
%token k_exports k_module k_non_sealed k_open k_opens k_permits k_provide k_record k_requires k_sealed k_to k_transitive k_uses k_var k_with k_yield

%token o_assign o_add_assign o_subtract_assign o_multiply_assign o_divide_assign o_modulo_assign o_bitwise_and_assign o_bitwise_or_assign o_bitwise_xor_assign o_left_shift_assign o_right_shift_assign o_unsigned_right_shift_assign o_bitwise_and o_bitwise_or o_bitwise_xor o_left_shift o_right_shift o_unsigned_right_shift o_add o_subtract o_multiply o_divide o_modulo o_less_than o_less_than_or_equal o_greater_than o_greater_than_or_equal o_equals o_not_equals o_logical_and o_logical_not o_logical_or o_increment o_decrement o_bitwise_complement o_question_mark o_colon

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

// program: /* empty */
//        | program statement s_semicolon
//        ;

// statement: declaration
//          | assignment_statement
//          | Expression_statement
//          ;
//  -------------------------Declaration --------------------
// declaration: PrimitiveType variable_declarator
//             ;

// variable_declarator: Identifier  op_o_assign_Expression 
//                     | Identifier array_initializer op_o_assign_d1_Expression
//                     | Identifier array_initializer array_initializer op_o_assign_d2_Expression
//                     | Identifier array_initializer array_initializer array_initializer op_o_assign_d3_Expression
//                     ;
// op_o_assign_Expression: | o_assign Expression ;
// op_o_assign_d1_Expression : | o_assign d1_Expression ;
// op_o_assign_d2_Expression: | o_assign d2_Expression ;
// op_o_assign_d3_Expression: | o_assign d3_Expression ;

// d1_Expression: s_open_curly_bracket op_Expression_list s_close_curly_bracket ;

// op_Expression_list: | Expression_list;
// Expression_list : Expression | Expression s_comma Expression ;

// d2_Expression: s_open_curly_bracket d1_Expression_list s_close_curly_bracket ; 
// d1_Expression_list: d1_Expression | d1_Expression s_comma d1_Expression_list ;


// d3_Expression: s_open_curly_bracket d2_Expression_list s_close_curly_bracket ;
// d2_Expression_list: d2_Expression | d2_Expression_list;

// array_initializer: s_open_square_bracket op_Expression s_close_square_bracket ;
op_Expression: | Expression;

// -------------------Declarations over -----------------

//  --------------------ignore--------------
// variable_initializer_list: variable_initializer (s_comma variable_initializer)*
//                           ;

VariableInitializer: Expression
                     | ArrayInitializer
                     ;
// --------------------ignore------------

// ------------production 3--------------
TypeIdentifier:
Identifier | k_exports | k_module | k_non_sealed | k_open | k_opens | k_provide | k_requires | k_to | k_transitive | k_uses | k_with ;

UnqualifiedMethodIdentifier:
Identifier | k_exports | k_module | k_non_sealed | k_open | k_opens | k_provide | k_requires | k_to | k_transitive | k_uses | k_with | k_permits | k_record | k_sealed | k_var ;

// ------production 4-------

Type: PrimitiveType | ReferenceType ;

PrimitiveType: NumericType | k_boolean ;

NumericType: IntegralType | FloatingPointType ;

IntegralType: k_byte | k_short | k_int | k_long |  k_char;

FloatingPointType: k_float | k_double;

ReferenceType: ClassOrInterfaceType | TypeVariable | ArrayType ;

ClassOrInterfaceType: ClassType | InterfaceType ;

ClassType: TypeIdentifier op_TypeArguments
            | PackageName s_dot TypeIdentifier op_TypeArguments
            | ClassOrInterfaceType s_dot TypeIdentifier op_TypeArguments ;
op_TypeArguments: | TypeArguments;

InterfaceType: ClassType ;

TypeVariable: TypeIdentifier ;
ArrayType: PrimitiveType Dims
            | ClassOrInterfaceType Dims
            | TypeVariable Dims;

Dims: s_open_square_bracket s_close_square_bracket | s_open_square_bracket s_close_square_bracket Dims ;

TypeParameter: TypeIdentifier op_TypeBound ;
op_TypeBound: | TypeBound;

TypeBound: k_extends TypeVariable
            | k_extends ClassOrInterfaceType AdditionalBounds;

AdditionalBounds: | AdditionalBound AdditionalBounds;

AdditionalBound: o_bitwise_and InterfaceType ;

TypeArguments: o_less_than TypeArgumentList o_greater_than ;

TypeArgumentList: TypeArgument | TypeArgument s_comma TypeArgumentList;

TypeArgument: ReferenceType 
            | Wildcard ;
Wildcard: o_question_mark op_WildcardBounds
op_WildcardBounds: | WildcardBounds;
WildcardBounds: k_extends ReferenceType
            | k_super ReferenceType



//  -------------------Production 6----------------
PackageName: Identifier
            | PackageName s_dot Identifier ;
TypeName: TypeIdentifier
            | PackageName s_dot TypeIdentifier;


// --------------production 10-----------
ArrayInitializer:
s_open_curly_bracket op_VariableInitializerList op_s_dot s_close_curly_bracket;
op_s_dot : | s_dot;
op_VariableInitializerList : | VariableInitializerList ;
VariableInitializerList: VariableInitializer | VariableInitializer s_comma VariableInitializerList



assignment_statement: Expression o_assign Expression
                     | Expression o_assign ternary_Expression
                     | Expression o_add_assign Expression
                     | Expression o_multiply_assign Expression
                     | Expression o_subtract_assign Expression
                     | Expression o_divide_assign Expression
                     | Expression o_modulo_assign Expression
                     | Expression o_bitwise_and_assign Expression
                     | Expression o_bitwise_xor_assign Expression
                     | Expression o_bitwise_or_assign Expression
                     | Expression o_less_than_or_equal Expression
                     | Expression o_greater_than_or_equal Expression
                     | Expression o_unsigned_right_shift_assign Expression
                     ;

Expression_statement: Expression
                     ;

// Expression: ternary_Expression
//           ;
Expression: 
    Assignment_Expression
    | LambdaExpression
    ;

ternary_Expression: logical_or_Expression op_ternary_Expression ;
op_ternary_Expression : | o_question_mark ternary_Expression o_colon ternary_Expression ;

logical_or_Expression: logical_and_Expression op_logical_or_Expression ;
op_logical_or_Expression : | o_logical_or logical_and_Expression op_logical_or_Expression;

logical_and_Expression: bitwise_or_Expression op_logical_and_Expression
op_logical_and_Expression : | o_logical_and bitwise_or_Expression op_logical_and_Expression ; 

bitwise_or_Expression: bitwise_xor_Expression op_bitwise_or_Expression ;
op_bitwise_or_Expression: | o_bitwise_or bitwise_xor_Expression op_bitwise_or_Expression ;

bitwise_xor_Expression: bitwise_and_Expression op_bitwise_xor_Expression ;
op_bitwise_xor_Expression : | o_bitwise_or bitwise_and_Expression op_bitwise_xor_Expression ;

bitwise_and_Expression: equality_Expression op_bitwise_and_Expression ;
op_bitwise_and_Expression : | o_bitwise_and equality_Expression op_bitwise_and_Expression ;

equality_Expression: relational_Expression op_equality_Expression ;
op_equality_Expression : | o_equals relational_Expression op_equality_Expression | o_not_equals relational_Expression op_equality_Expression;

relational_Expression: shift_Expression op_relational_Expression ;
op_relational_Expression : | op_relational shift_Expression op_relational_Expression ;
op_relational : o_less_than | o_less_than_or_equal | o_greater_than | o_greater_than_or_equal ;

shift_Expression: additive_Expression | additive_Expression operators_shift_Expression shift_Expression;
                 ;
operators_shift_Expression: o_left_shift | o_right_shift | o_unsigned_right_shift;


additive_Expression: multiplicative_Expression | multiplicative_Expression operators_additive_Expression additive_Expression ;
operators_additive_Expression: o_add | o_subtract ;

multiplicative_Expression: unary_Expression | unary_Expression operators_multiplicative_Expression multiplicative_Expression;
                          ;
operators_multiplicative_Expression: o_multiply | o_divide | o_modulo ;

unary_Expression: primary_Expression
                 | o_logical_not unary_Expression
                 | o_add primary_Expression
                 | o_subtract primary_Expression
                 | o_increment unary_Expression
                 | o_decrement unary_Expression
                 ;

primary_Expression: Identifier
                   | integer_literal
                   | s_open_paren Expression s_close_paren
                   | k_this
                   ;

integer_literal: Literal
               ;


// -----------production 14--------------
Block : s_open_curly_bracket op_BlockStatements s_close_curly_bracket ;

op_BlockStatements : | BlockStatements
BlockStatements : BlockStatement | BlockStatement BlockStatements ;

BlockStatement : /*LocalClassDeclaration | LocalVariableDeclaration |*/ Statement ;

LocalClassDeclaration : NormalClassDeclaration | EnumDeclaration | RecordDeclaration ;

NormalClassDeclaration : op_classmodifier k_class TypeIdentifier op_classextends op_classpermits ClassBody ;
op_classmodifier : | ClassModifier op_classmodifier
op_classextends : | ClassExtends
op_classpermits : | ClassPermits
ClassExtends : k_extends ClassType

ClassPermits : k_permits TypeName op_typename ; 
op_typename : | s_comma TypeName op_typename ;

ClassModifier : public | protected | private | abstract | static | final | sealed | non-sealed | strictfp ; 

ClassBody: s_open_curly_bracket op_classbody s_close_curly_bracket
op_classbody : | ClassBodyDeclaration op_classbody
ClassBodyDeclaration : ClassMemberDeclaration | InstanceInitializer | StaticInitializer | ConstructorDeclaration ;

ClassMemberDeclaration : FieldDeclaration | MethodDeclaration | ClassDeclaration | InterfaceDeclaration | s_semicolon ;

FieldDeclaration: op_field_modifier Type VariableDeclaratorList s_semicolon ;
op_field_modifier : | FieldModifier op_field_modifier ;
FieldModifier : public | protected | private | static | final | transient | volatile ;

MethodDeclaration : op_method_modifier MethodHeader MethodBody
op_method_modifier : | MethodModifier op_method_modifier ;
MethodModifier: public | protected | private | abstract | static | final | synchronized | native | strictfp
MethodHeader: Result MethodDeclarator op_throws | Result MethodDeclarator op_throws
op_throws : | Throws ;
Result: Type | void
MethodDeclarator : Identifier s_open_paren op_receiver_parameter op_formal_parameter_list s_close_paren op_dims;
op_dims : | Dims;
op_formal_parameter_list : | FormalParameterList

op_receiver_parameter : | ReceiverParameter s_comma
ReceiverParameter: Type op_identifier_dot k_this ;
op_identifier_dot : | Identifier s_dot
FormalParameterList : FormalParameter op_formal_parameter
op_formal_parameter : | s_comma FormalParameter op_formal_parameter ;
FormalParameter: op_variable_modifier Type VariableDeclaratorId | VariableArityParameter
op_variable_modifier: | k_final ;
Throws: k_throws ExceptionTypeList

ExceptionTypeList: ExceptionType | ExceptionType s_comma ExceptionTypeList ;
ExceptionType: ClassType TypeVariable
MethodBody: Block | s_semicolon ;
InstanceInitializer: Block ;
StaticInitializer: k_static Block ;

ConstructorDeclaration: op_ConstructorModifiers ConstructorDeclarator op_Throws ConstructorBody ;
op_Throws:  | Throws; 
op_ConstructorModifiers : | ConstructorModifiers;
ConstructorModifiers: ConstructorModifier | ConstructorModifier ConstructorModifiers ;

ConstructorModifier: k_public | k_protected | k_private ; 
ConstructorDeclarator: SimpleTypeName s_open_paren op_reciever_parameter op_formal_parameter_list s_close_paren ;
SimpleTypeName: TypeIdentifier ;
ConstructorBody: s_open_curly_bracket op_ExplicitConstructorInvocation op_BlockStatements s_close_curly_bracket;
op_ExplicitConstructorInvocation : | ExplicitConstructorInvocation;
ExplicitConstructorInvocation: k_this s_open_paren op_ArgumentList s_close_paren s_semicolon | super s_open_paren  op_ArgumentList s_close_paren s_semicolon | ExpressionName s_dot k_super s_open_paren  op_ArgumentList s_close_paren s_semicolon | Primary s_dot k_super s_open_paren  op_ArgumentList s_close_paren s_semicolon

ArgumentList : Expression | Expression s_comma ArgumentList ;
op_ArgumentList : | ArgumentList
EnumDeclaration : op_classmodifier k_enum TypeIdentifier EnumBody ; 

EnumBody: s_open_curly_bracket op_enum_constant_list op_comma op_enum_body_declarations s_close_curly_bracket ;
op_enum_constant_list : | EnumConstantList ;
op_comma : | s_comma ;
op_enum_body_declarations : | EnumBodyDeclarations 
EnumConstantList: EnumConstant | EnumConstant s_comma EnumConstantList ;
EnumConstant: Identifier op_enum_constant op_classbody
op_enum_constant : | s_open_paren /*ArgumentList?*/ s_close_paren
EnumBodyDeclarations: s_semicolon {ClassBodyDeclaration}


RecordDeclaration: op_classmodifier k_record TypeIdentifier RecordHeader RecordBody ;

RecordHeader : s_open_paren op_RecordComponentList s_close_paren ;
op_RecordComponentList : | RecordComponentList ;

RecordComponentList : RecordComponent | RecordComponent s_comma RecordComponentList ;
RecordComponent : Type identifier | VariableArityRecordComponent ;

VariableArityRecordComponent : Type s_varargs Identifier ; 


Statement : StatementWithoutTrailingSubstatement | LabeledStatement | IfThenStatement | IfThenElseStatement | WhileStatement | ForStatement ; 
 
StatementNoShortIf : StatementWithoutTrailingSubstatement | LabeledStatementNoShortIf | IfThenElseStatementNoShortIf | WhileStatementNoShortIf | ForStatementNoShortIf ; 

StatementWithoutTrailingSubstatement : Block | EmptyStatement | ExpressionStatement | BreakStatement | ContinueStatement | ReturnStatement ;

EmptyStatement : s_semicolon ; 

LabeledStatement : Identifier o_colon Statement ;

LabeledStatementNoShortIf : Identifier o_colon StatementNoShortIf ;

ExpressionStatement : StatementExpression s_semicolon ;

StatementExpression : Assignment /*| PreIncrementExpression | PreDecrementExpression | PostIncrementExpression | PostDecrementExpression | MethodInvocation | ClassInstanceCreationExpression*/ ;
Assignment : o_assign | o_add_assign | o_subtract_assign | o_multiply_assign | o_divide_assign | o_bitwise_and_assign
IfThenStatement : k_if s_open_paren Expression s_close_paren Statement ;

IfThenElseStatement : k_if s_open_paren Expression s_close_paren StatementNoShortIf k_else Statement ;

IfThenElseStatementNoShortIf : k_if s_open_paren Expression s_close_paren StatementNoShortIf k_else StatementNoShortIf ;

WhileStatement : k_while s_open_paren Expression s_close_paren Statement ;

WhileStatementNoShortIf : k_while s_open_paren Expression s_close_paren StatementNoShortIf ;

ForStatement : BasicForStatement | EnhancedForStatement ; 
ForStatementNoShortIf : BasicForStatementNoShortIf | EnhancedForStatementNoShortIf ;

BasicForStatement : k_for s_open_paren op_ForInit s_semicolon op_Expression s_semicolon op_ForUpdate s_close_paren Statement ;
op_ForInit : | ForInit ;
op_ForUpdate : | ForUpdate
BasicForStatementNoShortIf: k_for s_open_paren op_ForInit s_semicolon op_Expression s_semicolon op_ForUpdate s_close_paren StatementNoShortIf ;
ForInit : StatementExpressionList | LocalVariableDeclaration;
ForUpdate : StatementExpressionList ;
StatementExpressionList : StatementExpression op_StatementExpression
op_StatementExpression : | s_comma StatementExpression op_StatementExpression
EnhancedForStatement : k_for s_open_paren LocalVariableDeclaration o_colon Expression s_close_paren Statement
EnhancedForStatementNoShortIf : k_for s_open_paren LocalVariableDeclaration : Expression s_close_paren StatementNoShortIf
BreakStatement : k_break op_Identifier ;
op_Identifier : | Identifier op_Identifier
/*YieldStatement : k_yield Expression ;*/
ContinueStatement : k_continue op_Identifier ;
ReturnStatement : k_return op_Expression ;


ThrowStatement: k_throw Expression ;
SynchronizedStatement: k_synchronized s_open_paren Expression s_close_paren Block ;
TryStatement: k_try Block Catches | k_try Block op_Catches Finally | TryWithResourcesStatement ;
op_Catches: | Catches;
Catches: CatchClause | CatchClause Catches ;
CatchClause: k_catch s_open_paren CatchFormalParameter s_open_paren Block ;
CatchFormalParameter: CatchType VariableDeclaratorId ;
CatchType:  ClassType | ClassType o_bitwise_or CatchType ;
Finally: k_finally Block ;
TryWithResourcesStatement: k_try ResourceSpecification Block op_Catches op_Finally
op_Finally: | Finally;
ResourceSpecification:s_open_paren ResourceList op_s_colon s_close_paren; 
op_s_colon: | s_colon;
ResourceList: Resource | Resource s_colon ResourceList ;
Resource: LocalVariableDeclaration | VariableAccess ;
Pattern: TypePattern ;
TypePattern: LocalVariableDeclaration ;
// -- statement_list:
// --     | statement_list statement
// --     ;

// -- statement:
// --     Expression_statement
// --     | compound_statement
// --     | selection_statement
// --     | iteration_statement
// --     ;

// -- Expression_statement:
// --     Expression SEMICOLON
// --     ;

// -- compound_statement:
// --     L_BRACE statement_list R_BRACE
// --     ;

// -- selection_statement:
// --     IF L_PAREN Expression R_PAREN statement
// --     | IF L_PAREN Expression R_PAREN statement ELSE statement
// --     ;

// -- iteration_statement:
// --     WHILE L_PAREN Expression R_PAREN statement
// --     | FOR L_PAREN for_Expression SEMICOLON for_Expression SEMICOLON for_Expression R_PAREN statement
// --     ;

// -- for_Expression:
// --     Expression | /* empty */
// --     ;

// -- Expression:
// --     equality_Expression
// --     ;

// -- equality_Expression:
// --     relational_Expression
// --     | equality_Expression EQ relational_Expression
// --     | equality_Expression NEQ relational_Expression
// --     ;

// -- relational_Expression:
// --     additive_Expression
// --     | relational_Expression LT additive_Expression
// --     | relational_Expression GT additive_Expression
// --     | relational_Expression LTE additive_Expression
// --     | relational_Expression GTE additive_Expression
// --     ;

// -- additive_Expression:
// --     multiplicative_Expression
// --     | additive_Expression PLUS multiplicative_Expression
// --     | additive_Expression MINUS multiplicative_Expression
// --     ;

// -- multiplicative_Expression:
// --     unary_Expression
// --     | multiplicative_Expression MULT unary_Expression
// --     | multiplicative_Expression DIV unary_Expression
// --     | multiplicative_Expression MOD unary_Expression
// --     ;

// -- unary_Expression:
// --     postfix_Expression
// --     | PLUS unary_Expression %prec UNARY
// --     | MINUS unary_Expression %prec UNARY
// --     | NOT unary_Expression %prec UNARY
// --     | INCREMENT unary_Expression %prec UNARY
// --     | DECREMENT unary_Expression %prec UNARY
// --     ;

// -- postfix_Expression:
// --     primary_Expression
// --     | postfix_Expression INCREMENT
// --     | postfix_Expression DECREMENT
// --     ;

// ------------ Production 15 ------------

Primary:
    PrimaryNoNewArray
    | ArrrayCreationExpression
    ;

PrimaryNoNewArray:
    Literal
    | ClassLiteral
    | k_this
    | Typename s_dot k_this
    | s_open_paren Expression s_close_paren
    | ClassInstanceCreationExpression
    | FieldAccess
    | ArrayAccess
    | MethodInvocation
    | MethodReference
    ;

ClassLiteral: 
    TypeName op_dims s_dot k_class
    | NumericType op_dims s_dot k_class
    | k_boolean op_dims s_dot k_class
    | k_void s_dot k_class
    ;
    
ClassInstanceCreationExpression:
    UnqualifiedClassInstanceCreationExpression
    | ExpressionName s_dot UnqualifiedClassInstanceCreationExpression
    | Primary s_dot UnqualifiedClassInstanceCreationExpression
    ;

UnqualifiedClassInstanceCreationExpression:
    k_new op_TypeArguments ClassOrInterfaceTypeToInstantiate s_open_paren op_ArgumentList s_close_paren op_classbody
    ;

ClassOrInterfaceTypeToInstantiate:
    Identifier op_TypeArguments 
    | Identifier s_dot ClassOrInterfaceTypeToInstantiate
    ;

FieldAccess:
    Primary s_dot Identifier
    | k_super s_dot Identifier
    | TypeName s_dot k_super s_dot Identifier
    ;

ArrayAccess:
    ExpressionName s_open_square_bracket Expression s_close_square_bracket
    | PrimaryNoNewArray s_open_square_bracket Expression s_close_square_bracket
    ;

MethodInvocation:
    MethodName s_open_paren op_ArgumentList s_close_paren
    | TypeName s_dot op_TypeArguments Identifier s_open_paren op_ArgumentList s_close_paren
    | ExpressionName s_dot op_TypeArguments Identifier s_open_paren op_ArgumentList s_close_paren
    | Primary s_dot op_TypeArguments Identifier s_open_paren op_ArgumentList s_close_paren
    | k_super s_dot op_TypeArguments Identifier s_open_paren op_ArgumentList s_close_paren
    | TypeName s_dot k_super s_dot op_TypeArguments Identifier s_open_paren op_ArgumentList s_close_paren
    ;

MethodRefere:
    ExpressionName s_double_colon op_TypeArguments Identifier
    | Primary s_double_colon op_TypeArguments Identifier
    | ReferenceType s_double_colon op_TypeArguments Identifier
    | k_super s_double_colon op_TypeArguments Identifier
    | TypeName s_dot k_super s_double_colon op_TypeArguments Identifier
    | ClassType s_double_colon op_TypeArguments k_new
    | ArrayType s_double_colon k_new
    ;

ArrayCreationExpression:
    k_new PrimitiveType DimExprs op_Dims
    | k_new ClassOrInterfaceType DimExprs op_Dims
    | k_new PrimitiveType Dims ArrayInitializer
    | k_new ClassOrInterfaceType Dims ArrayInitializer
    ;

DimExprs: 
    DimExpr
    | DimExpr DimExprs
    ;

DimExpr:
    s_open_square_bracket Expression s_close_square_bracket
    ;

LambdaExpression:
    LambdaParemeter 
// -- variable:
// --     ID
// --     ;

// -- constant:
// --     INT_LITERAL
// --     | DOUBLE_LITERAL
// --     | BOOL_LITERAL
// --     ;

%%
