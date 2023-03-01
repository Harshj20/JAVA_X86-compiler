%{
#include <bits/stdc++.h>
#include "Node.h"
using namespace std;
extern int yylex();
extern int yylineno;
void yyerror(char* s){
    printf("Error123 %s in line %d\n",s,yylineno);
}
Node* root=NULL;
%}

%code requires{
    #include "Node.h"
}

%union {
    char* str;
    Node* node;
}

%token k_abstract k_assert k_boolean k_break k_byte k_case k_catch k_char k_class k_const k_continue k_default k_do k_double k_else k_enum k_extends k_final k_finally k_float k_for k_goto k_if k_implements k_import k_instanceof k_int k_interface k_long k_native k_new k_package k_private k_protected k_public k_return k_short k_static k_strictfp k_super k_switch k_synchronized k_this k_throw k_throws k_transient k_try k_void k_volatile k_while k_underscore
%token k_exports k_module k_non_sealed k_open k_opens k_permits k_provide k_record k_requires k_sealed k_to k_transitive k_uses k_var k_with k_yield 

%token<str> o_assign o_add_assign o_subtract_assign o_multiply_assign o_divide_assign o_modulo_assign o_bitwise_and_assign o_bitwise_or_assign o_bitwise_xor_assign o_left_shift_assign o_right_shift_assign o_unsigned_right_shift_assign o_bitwise_and o_bitwise_or o_bitwise_xor o_left_shift o_right_shift o_unsigned_right_shift o_add o_subtract o_multiply o_divide o_modulo o_less_than o_less_than_or_equal o_greater_than o_greater_than_or_equal o_equals o_not_equals o_logical_and o_logical_not o_logical_or o_increment o_decrement o_bitwise_complement o_question_mark o_colon o_arrow

%token<str> Identifier Literal 

%token<str> s_open_paren s_close_paren s_open_curly_bracket s_close_curly_bracket s_open_square_bracket s_close_square_bracket s_semicolon s_comma s_dot s_varargs s_double_colon

%start Program

%type<node> Program CompilationUnit ImportDeclarations ImportDeclaration TypeDeclarations TypeDeclaration ClassDeclaration NormalClassDeclaration ClassBody PackageDeclaration

%%
// ------------------ Start -----------------------

Program : {root=new Node("Program");root->children.push_back(new Node("EOF","EOF"));}| CompilationUnit {root=new Node("Program"); root->children.push_back($1);root->children.push_back(new Node("EOF","EOF"));} 


// -------------------------------- Production 4 -----------------------

Type: PrimitiveType
    | ReferenceType

PrimitiveType: NumericType 
             | k_boolean

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


// ------------------------------- Production 6 --------------------------

Name:SimpleName
	| QualifiedName

SimpleName: Identifier

QualifiedName: Name s_dot Identifier

// --------------------------- Production 7 --------------------------

CompilationUnit: PackageDeclaration ImportDeclarations TypeDeclarations  
                {
                    $$=new Node("CompilationUnit"); 
                    $$->children.push_back($1);
                    $$->children.push_back($2);
                    $$->children.push_back($3);
                }
                | PackageDeclaration ImportDeclarations 
                {
                    $$=new Node("CompilationUnit"); 
                    $$->children.push_back($1);
                    $$->children.push_back($2);
                }
                | PackageDeclaration TypeDeclarations
                {
                    $$=new Node("CompilationUnit"); 
                    $$->children.push_back($1);
                    $$->children.push_back($2);
                }
                | PackageDeclaration
                {
                    $$=$1;
                }
                | ImportDeclarations TypeDeclarations
                {
                    $$=new Node("CompilationUnit"); 
                    $$->children.push_back($1);
                    $$->children.push_back($2);
                }
                | TypeDeclarations
                {
                    $$=$1;
                }
                //|
                | ImportDeclarations
                {
                    $$=$1;
                }

ImportDeclarations: ImportDeclaration 
                {
                    $$=$1;
                }
                | ImportDeclarations ImportDeclaration
                {
                    $$=new Node("ImportDeclarations"); 
                    $$->children.push_back($1);
                    $$->children.push_back($2);
                }

TypeDeclarations:TypeDeclaration 
                {
                    $$=$1;
                }
	            |TypeDeclarations TypeDeclaration 
                {
                    $$=new Node("ImportDeclarations"); 
                    $$->children.push_back($1);
                    $$->children.push_back($2);
                }

PackageDeclaration: k_package Name s_semicolon

ImportDeclaration: SingleTypeImportDeclaration
	              |TypeImportOnDemandDeclaration

SingleTypeImportDeclaration: k_import Name s_semicolon

TypeImportOnDemandDeclaration: k_import Name s_dot o_multiply s_semicolon

TypeDeclaration: ClassDeclaration 
                {
                    $$=$1;
                }
	            |InterfaceDeclaration
                | s_semicolon
// ---------------------------- Production 8 -----------------------

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

ClassDeclaration : NormalClassDeclaration 
                   {
                    $$=$1;
                   }
                  |EnumDeclaration

NormalClassDeclaration:
	Modifiers k_class Identifier Super Interfaces ClassBody
    | Modifiers k_class Identifier Super ClassBody
    | Modifiers k_class Identifier Interfaces ClassBody
    | Modifiers k_class Identifier ClassBody
    | k_class Identifier Super Interfaces ClassBody
    | k_class Identifier Super ClassBody
    | k_class Identifier Interfaces ClassBody
    | k_class Identifier ClassBody 
    {
        $$=new Node("TypeDeclarations"); 
        $$->children.push_back(new Node("class","Keyword"));
        $$->children.push_back(new Node($2,"Identifier"));
        $$->children.push_back($3);
    }



Super: k_extends ClassType

Interfaces: k_implements InterfaceTypeList

InterfaceTypeList:InterfaceType
	|InterfaceTypeList s_comma InterfaceType

ClassBody: s_open_curly_bracket ClassBodyDeclarations s_close_curly_bracket 
| s_open_curly_bracket s_close_curly_bracket 
{
    $$=new Node("ClassBody");
    $$->children.push_back(new Node("{","Separator"));
    $$->children.push_back(new Node("}","Separator"));
}

ClassBodyDeclarations:ClassBodyDeclaration
	|ClassBodyDeclarations ClassBodyDeclaration

ClassBodyDeclaration:ClassMemberDeclaration
                    |StaticInitializer
                    |ConstructorDeclaration

ClassMemberDeclaration:FieldDeclaration
                      |MethodDeclaration

FieldDeclaration:

	Modifiers Type VariableDeclaratorList s_semicolon | Type VariableDeclaratorList s_semicolon

VariableDeclaratorList:VariableDeclarator
	               |VariableDeclaratorList s_comma VariableDeclarator

VariableDeclarator: VariableDeclaratorId
	               |VariableDeclaratorId o_assign VariableInitializer

VariableDeclaratorId: Identifier
	                 |VariableDeclaratorId s_open_square_bracket s_close_square_bracket

VariableInitializer:Expression
	               |ArrayInitializer

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

EnumDeclaration : Modifiers k_enum Identifier ClassImplements EnumBody
                 |Modifiers k_enum Identifier EnumBody
                 |k_enum Identifier ClassImplements EnumBody
                 |k_enum Identifier EnumBody

ClassImplements : k_implements InterfaceTypeList

EnumBody : s_open_curly_bracket EnumConstantList s_comma EnumBodyDeclarations s_close_curly_bracket
          |s_open_curly_bracket EnumConstantList s_comma s_close_curly_bracket
          |s_open_curly_bracket EnumConstantList EnumBodyDeclarations s_close_curly_bracket
          |s_open_curly_bracket EnumConstantList s_close_curly_bracket
          |s_open_curly_bracket s_comma EnumBodyDeclarations s_close_curly_bracket
          |s_open_curly_bracket s_comma s_close_curly_bracket
          |s_open_curly_bracket EnumBodyDeclarations s_close_curly_bracket
          |s_open_curly_bracket s_close_curly_bracket

EnumBodyDeclarations : s_semicolon | s_semicolon ClassBodyDeclaration

EnumConstantList : Identifier s_open_paren ArgumentList s_close_paren ClassBody
                  |Identifier s_open_paren s_close_paren ClassBody
                  |Identifier s_open_paren ArgumentList s_close_paren
                  |Identifier s_open_paren s_close_paren
                  |Identifier ClassBody
                  |Identifier
// ---------------------------- Production 9 -----------------------

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

InterfaceMemberDeclarations: InterfaceMemberDeclaration
	| InterfaceMemberDeclarations InterfaceMemberDeclaration
	;

InterfaceMemberDeclaration: ConstantDeclaration
	| AbstractMethodDeclaration
	;

ConstantDeclaration: FieldDeclaration
	;

AbstractMethodDeclaration: MethodHeader s_semicolon 
	;


// ------------------------------- Production 10 ---------------------

ArrayInitializer:

	s_open_curly_bracket VariableInitializerList s_comma s_close_curly_bracket
	| s_open_curly_bracket VariableInitializerList  s_close_curly_bracket
	| s_open_curly_bracket  s_comma s_close_curly_bracket
	| s_open_curly_bracket  s_close_curly_bracket
	;

VariableInitializerList: VariableInitializer
	| VariableInitializerList s_comma VariableInitializer
	;


// ------------------------ Production 14 -------------------------------------

Block : s_open_curly_bracket s_close_curly_bracket 
    {
        $$=new Node("Block");
        $$->children.push_back(new Node("{","Separator"));
        $$->children.push_back(new Node("}","Separator"));
    }
    | s_open_curly_bracket BlockStatements s_close_curly_bracket
    {
        $$=new Node("Block");
        $$->children.push_back(new Node("{","Separator"));
        $$->children.push_back($2);
        $$->children.push_back(new Node("}","Separator"));
    }
    ;

BlockStatements : 
    BlockStatement 
    {
        $$ = $1;
    }
    | BlockStatements BlockStatement 
    {
        $$=new Node("BlockStatements");
        $$->children.push_back($1);
        $$->children.push_back($2);
    }
    ; 

BlockStatement : 
    LocalVariableDeclarationStatement 
    {
        $$ = $1;
    }
    | Statement 
    {
        $$ = $1
    }
    ;

LocalVariableDeclarationStatement : LocalVariableDeclaration s_semicolon
    {
        $$ = new Node("LocalVariableDeclarationStatement");
        $$->children.push_back($1);
        $$->children.push_back(new Node(";", "Seperator"));
    }
    ;

LocalVariableDeclaration : 
    k_final LocalVariableType VariableDeclaratorList
    {
        $$=new Node("LocalVariableDeclaration");
        $$->children.push_back(new Node("final","Keyword"));
        $$->children.push_back($2);
        $$->children.push_back($3);
    }
    | LocalVariableType VariableDeclaratorList
    {
        $$=new Node("LocalVariableDeclaration");
        $$->children.push_back($1);
        $$->children.push_back($2);
    }
    ;

LocalVariableType : 
    Type
    {
        $$ = $1;
    }
    | k_var
    {
        $$ = new Node("var", "Keyword");
    }

Statement : 
    StatementWithoutTrailingSubstatement 
    {$$ = $1;}
    | LabeledStatement
    {$$ = $1;} 
    | IfThenStatement
    {$$ = $1;} 
    | IfThenElseStatement
    {$$ = $1;} 
    | WhileStatement
    {$$ = $1;} 
    | ForStatement
    {$$ = $1;} 
    ; 

StatementNoShortIf : 
    StatementWithoutTrailingSubstatement
    {$$ = $1;}
    | LabeledStatementNoShortIf 
    {$$ = $1;}
    | IfThenElseStatementNoShortIf 
    {$$ = $1;}
    | WhileStatementNoShortIf 
    {$$ = $1;}
    | ForStatementNoShortIf 
    {$$ = $1;}
    ; 

StatementWithoutTrailingSubstatement : 
    Block 
    {$$ = $1;}
    | EmptyStatement 
    {$$ = $1;}
    | ExpressionStatement 
    {$$ = $1;}
    | BreakStatement 
    {$$ = $1;}
    | ContinueStatement 
    {$$ = $1;}
    | ReturnStatement  
    {$$ = $1;}
    | SynchronizedStatement 
    {$$ = $1;}
    | ThrowStatement 
    {$$ = $1;}
    | TryStatement 
    {$$ = $1;}
    ;

EmptyStatement:
	s_semicolon
    {$$ = new Node(";", "Separator");}
	;

LabeledStatement:

	Identifier o_colon Statement
    {
        $$ = new Node("LabeledStatement");
        $$->children.push_back($1, "Identifier");
        $$->children.push_back(new Node(":", "Operator"));
        $$->children.push_back($3);
    }
	;

LabeledStatementNoShortIf:

	Identifier o_colon StatementNoShortIf
    {
        $$ = new Node("LabeledStatementNoShortIf");
        $$->children.push_back($1, "Identifier");
        $$->children.push_back(new Node(":", "Operator"));
        $$->children.push_back($3);
    }

ExpressionStatement:

	StatementExpression s_semicolon
    {
        $$ = new Node("ExpressionStatement");
        $$->children.push_back($1);
        $$->children.push_back(new Node(";", "Separator"));
    }
	;

StatementExpression:

	Assignment
    { $$ = $1; }
	| PreIncrementExpression
    { $$ = $1; }
	| PreDecrementExpression
    { $$ = $1; }
	| PostIncrementExpression
    { $$ = $1; }
	| PostDecrementExpression
    { $$ = $1; }
	| MethodInvocation
    { $$ = $1; }
	| ClassInstanceCreationExpression
    { $$ = $1; }
	;

IfThenStatement : 
    k_if s_open_paren Expression s_close_paren Statement 
    {
        $$ = new Node("IfThenStatement");
        $$->children.push_back(new Node("if", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back($3);
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($5);
    }
    ;


IfThenElseStatement : 
    k_if s_open_paren Expression s_close_paren StatementNoShortIf k_else Statement 
    {
        $$ = new Node("IfThenElseStatement");
        $$->children.push_back(new Node("if", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back($3);
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($5);
        $$->children.push_back(new Node("else", "Keyword"));
        $$->children.push_back($7);
    }
    ;

IfThenElseStatementNoShortIf : 
    k_if s_open_paren Expression s_close_paren StatementNoShortIf k_else StatementNoShortIf 
    {
        $$ = new Node("IfThenElseStatementNoShortIf");
        $$->children.push_back(new Node("if", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back($3);
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($5);
        $$->children.push_back(new Node("else", "Keyword"));
        $$->children.push_back($7);
    }
    ;


WhileStatement : 
    k_while s_open_paren Expression s_close_paren Statement 
    {
        $$ = new Node("WhileStatement");
        $$->children.push_back(new Node("while", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back($3);
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($5);
    }
    ;

WhileStatementNoShortIf : 
    k_while s_open_paren Expression s_close_paren StatementNoShortIf 
    {
        $$ = new Node("WhileStatementNoShortIf");
        $$->children.push_back(new Node("while", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back($3);
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($5);
    }
    ;

ForStatement:

	k_for s_open_paren s_semicolon s_semicolon s_close_paren Statement 
    {
        $$ = new Node("ForStatement");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($6);
    }
    | k_for s_open_paren s_semicolon s_semicolon ForUpdate s_close_paren Statement 
    {
        $$ = new Node("ForStatement");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($5);
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($7);
    }
    | k_for s_open_paren s_semicolon Expression s_semicolon s_close_paren Statement 
    {
        $$ = new Node("ForStatement");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($4);
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($6);
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($8);
    }
    | k_for s_open_paren s_semicolon Expression s_semicolon ForUpdate s_close_paren Statement 
    {
        $$ = new Node("ForStatement");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($4);
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($6);
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($8);
    }
    | k_for s_open_paren ForInit s_semicolon s_semicolon s_close_paren Statement
    {
        $$ = new Node("ForStatement");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back($4);
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($6);
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($8);
         
    } 
    | k_for s_open_paren ForInit s_semicolon s_semicolon ForUpdate s_close_paren Statement 
    {
    }
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

void traverse(Node* node, int &counter, std::ofstream &dotfile) {
  node->count = counter++;
  dotfile << "  node" << node->count << " [label=\"" << node->token << "\\n" << node->id << "\"];" << std::endl;
  for (int i=0;i<node->children.size();i++) {
    int child_id = counter;
    dotfile << "  node" << node->count << " -> node" << child_id << ";" << std::endl;
    traverse(node->children[i], counter, dotfile);
  }
}

void print_dot() {
  ofstream dotfile("parse_tree.dot");
  dotfile << "digraph PARSE_TREE {" << endl;
  int counter = 0;
  traverse(root, counter, dotfile);
  dotfile << "}" << endl;
  dotfile.close();
}

int main(){
    yyparse();
    if(root){
        //printf("ahbvhg");
        print_dot();
    }
    else printf("sjbckwjeb");
    return 0;
}