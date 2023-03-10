%{
#include <bits/stdc++.h>
#include "Node.h"
using namespace std;
extern int yylex();
extern int yylineno;
extern FILE *yyin;

bool flag_verbose=false;
void yyerror(const char* s){
    if(flag_verbose){
        printf("Error %s in line %d\n",s,yylineno);
    }
    else{
        printf("Syntax error in line %d\n",yylineno);
    }
}
Node* root=NULL;
%}

%define parse.error verbose

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

%token<str> Identifier int_Literal bin_Literal deci_flo_Literal oct_Literal hex_flo_Literal string_Literal hex_Literal Text_Block_Literal char_Literal true_Literal false_Literal null_Literal

%token<str> s_open_paren s_close_paren s_open_curly_bracket s_close_curly_bracket s_open_square_bracket s_close_square_bracket s_semicolon s_comma s_dot s_varargs s_double_colon

%start Program

%type<node> Program CompilationUnit ImportDeclarations ImportDeclaration TypeDeclarations TypeDeclaration ClassDeclaration NormalClassDeclaration ClassBody PackageDeclaration Type PrimitiveType ReferenceType NumericType IntegralType FloatingPointType ClassOrInterfaceType ClassType InterfaceType ArrayType Name SimpleName QualifiedName ClassBodyDeclaration ClassMemberDeclaration FieldDeclaration MethodDeclaration MethodHeader MethodDeclarator FormalParameterList FormalParameter VariableDeclarator VariableDeclaratorId VariableInitializer ArrayInitializer Block BlockStatements BlockStatement LocalVariableDeclarationStatement LocalVariableDeclaration Statement StatementWithoutTrailingSubstatement StatementExpression IfThenStatement IfThenElseStatement WhileStatement ForStatement ReturnStatement Expression Assignment ConditionalExpression ConditionalOrExpression ConditionalAndExpression InclusiveOrExpression ExclusiveOrExpression AndExpression EqualityExpression RelationalExpression ShiftExpression AdditiveExpression MultiplicativeExpression UnaryExpression UnaryExpressionNotPlusMinus PostIncrementExpression PostDecrementExpression Primary PrimaryNoNewArray ArrayAccess FieldAccess MethodInvocation SingleTypeImportDeclaration TypeImportOnDemandDeclaration Modifiers Modifier Super Interfaces InterfaceTypeList ClassTypeList ClassBodyDeclarations VariableDeclaratorList VariableInitializerList Throws MethodBody StaticInitializer ConstructorDeclaration ConstructorDeclarator ConstructorBody ExplicitConstructorInvocation EnumDeclaration ClassImplements EnumBody EnumConstantList EnumBodyDeclarations
InterfaceDeclaration  InterfaceBody InterfaceMemberDeclaration ConstantDeclaration ExtendsInterfaces InterfaceMemberDeclarations 
AbstractMethodDeclaration StatementNoShortIf EmptyStatement ExpressionStatement BreakStatement ContinueStatement  ForStatementNoShortIf IfThenElseStatementNoShortIf LabeledStatement  ThrowStatement SynchronizedStatement TryStatement  WhileStatementNoShortIf LocalVariableType LabeledStatementNoShortIf ForInit ForUpdate StatementExpressionList Catches CatchClause Finally ClassInstanceCreationExpression ArrayCreationExpression ArgumentList DimExprs DimExpr Dims PostFixExpression PreIncrementExpression PreDecrementExpression CastExpression AssignmentOperator AssignmentExpression LeftHandSide BasicForStatement EnhancedForStatement BasicForStatementNoShortIf EnhancedForStatementNoShortIf EnumConstant

%%
// ------------------ Start -----------------------

Program : 
    {   
        root=new Node("Program");
        root->children.push_back(new Node("EOF","EOF"));
    }
    | CompilationUnit
    {
        root=new Node("Program"); 
        root->children.push_back($1);
        root->children.push_back(new Node("EOF","EOF"));
    } 


// -------------------------------- Production 4 -----------------------

Type: PrimitiveType 
    {
        $$=$1;
    }
    | ReferenceType 
    {
        $$=$1;
    }

PrimitiveType: NumericType 
               {
                $$=$1;
               }
             | k_boolean
             {
                $$ = new Node("boolean","Keyword");
             }

NumericType:IntegralType
            {
                $$=$1;
            }
            |FloatingPointType
            {
                $$=$1;
            }

IntegralType: k_byte
              {
                $$ = new Node("byte","Keyword");
              }
            |k_short
             {
                $$ = new Node("short","Keyword");
             }
            |k_int 
             {
                $$ = new Node("int","Keyword");
             }
            |k_long 
             {
                $$ = new Node("long","Keyword");
             }
            |k_char
             {
                $$ = new Node("char","Keyword");
             }

FloatingPointType: k_float 
                   {
                        $$ = new Node("float","Keyword");
                   }
                 | k_double
                   {
                        $$ = new Node("double","Keyword");
                   }

ReferenceType:ClassOrInterfaceType
              {
                $$=$1;
              }
	         |ArrayType
             {
                $$=$1;
             }

ClassOrInterfaceType:Name {
                            $$=$1;
                          }

ClassType:ClassOrInterfaceType {
                                 $$=$1;
                               }

InterfaceType:ClassOrInterfaceType {
                                    $$=$1;
                                   }

ArrayType: PrimitiveType s_open_square_bracket s_close_square_bracket
                {
                    $$=new Node("ArrayType"); 
                    $$->children.push_back($1);
                    $$->children.push_back(new Node("{","Separator"));
                    $$->children.push_back(new Node("}","Separator"));
                }
	| Name s_open_square_bracket s_close_square_bracket
                {
                    $$=new Node("ArrayType"); 
                    $$->children.push_back($1);
                    $$->children.push_back(new Node("{","Separator"));
                    $$->children.push_back(new Node("}","Separator"));
                }
	|ArrayType s_open_square_bracket s_close_square_bracket
                {
                    $$=new Node("ArrayType"); 
                    $$->children.push_back($1);
                    $$->children.push_back(new Node("{","Separator"));
                    $$->children.push_back(new Node("}","Separator"));
                }


// ------------------------------- Production 6 --------------------------

Name:SimpleName
     {
        $$=$1;
     }
	| QualifiedName
      {
        $$=$1;
      }

SimpleName: Identifier 
            {
                $$ = new Node($1,"Identifier");
            }

QualifiedName: Name s_dot Identifier 
                {
                    $$=new Node("QualifiedName"); 
                    $$->children.push_back($1);
                    $$->children.push_back(new Node(".","Separator"));
                    $$->children.push_back(new Node($3,"Identifier"));
                }

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
                    $$=new Node("TypeDeclarations"); 
                    $$->children.push_back($1);
                    $$->children.push_back($2);
                }

PackageDeclaration: k_package Name s_semicolon
                    {
                        $$=new Node("PackageDeclaration"); 
                        $$->children.push_back(new Node("package","Keyword"));
                        $$->children.push_back($2);
                        $$->children.push_back(new Node(";","Separator"));
                    }

ImportDeclaration: SingleTypeImportDeclaration
                   {
                    $$=$1;
                   }
	              |TypeImportOnDemandDeclaration
                  {
                    $$=$1;
                  }

SingleTypeImportDeclaration: k_import Name s_semicolon
                             {
                                $$=new Node("SingleImportTypeDeclaration"); 
                                $$->children.push_back(new Node("import","Keyword"));
                                $$->children.push_back($2);
                                $$->children.push_back(new Node(";","Separator"));
                             }


TypeImportOnDemandDeclaration: k_import Name s_dot o_multiply s_semicolon
                               {
                                $$=new Node("PackageDeclaration"); 
                                $$->children.push_back(new Node("import","Keyword"));
                                $$->children.push_back($2);
                                $$->children.push_back(new Node(".","Separator"));
                                $$->children.push_back(new Node("*","Operator"));
                                $$->children.push_back(new Node(";","Separator"));
                               }

TypeDeclaration: ClassDeclaration 
                {
                    $$=$1;
                }
	            |InterfaceDeclaration
                {
                    $$=$1;
                }
                | s_semicolon
                {
                $$ = new Node(";","Separator");
                }
// ---------------------------- Production 8 -----------------------

Modifiers:Modifier 
          {
            $$ = $1;
          }
         |Modifiers Modifier
         {
            $$=new Node("Modifiers"); 
            $$->children.push_back($1);
            $$->children.push_back($2);
         }

Modifier: k_public 
          {
            $$ = new Node("public","Keyword");
          }
        | k_protected 
          {
            $$ = new Node("protected","Keyword");
          }
        | k_private
          {
            $$ = new Node("private","Keyword");
          }
	    | k_static
          {
            $$ = new Node("static","Keyword");
          }
	    | k_abstract 
          {
            $$ = new Node("abstract","Keyword");
          }
        | k_final 
          {
            $$ = new Node("final","Keyword");
          }
        | k_native 
          {
            $$ = new Node("native","Keyword");
          }
        | k_synchronized 
          {
            $$ = new Node("synchronized","Keyword");
          }
        | k_transient 
          {
            $$ = new Node("transient","Keyword");
          }
        | k_volatile
          {
            $$ = new Node("volatile","Keyword");
          }

ClassDeclaration : NormalClassDeclaration 
                   {
                    $$=$1;
                   }
                  |EnumDeclaration
                   {
                    $$=$1;
                   }

NormalClassDeclaration:
	Modifiers k_class Identifier Super Interfaces ClassBody
    {   
        $$=new Node("NormalClassDeclaration"); 
        $$->children.push_back($1);
        $$->children.push_back(new Node("class","Keyword"));
        $$->children.push_back(new Node($3,"Identifier"));
        $$->children.push_back($4);
        $$->children.push_back($5);
        $$->children.push_back($6);
    }
    | Modifiers k_class Identifier Super ClassBody
      {   
        $$=new Node("NormalClassDeclaration"); 
        $$->children.push_back($1);
        $$->children.push_back(new Node("class","Keyword"));
        $$->children.push_back(new Node($3,"Identifier"));
        $$->children.push_back($4);
        $$->children.push_back($5);
      }
    | Modifiers k_class Identifier Interfaces ClassBody
      {   
        $$=new Node("NormalClassDeclaration"); 
        $$->children.push_back($1);
        $$->children.push_back(new Node("class","Keyword"));
        $$->children.push_back(new Node($3,"Identifier"));
        $$->children.push_back($4);
        $$->children.push_back($5);
      }
    | Modifiers k_class Identifier ClassBody
      {   
        $$=new Node("NormalClassDeclaration"); 
        $$->children.push_back($1);
        $$->children.push_back(new Node("class","Keyword"));
        $$->children.push_back(new Node($3,"Identifier"));
        $$->children.push_back($4);
      }
    | k_class Identifier Super Interfaces ClassBody
      {   
        $$=new Node("NormalClassDeclaration"); 
        $$->children.push_back(new Node("class","Keyword"));
        $$->children.push_back(new Node($2,"Identifier"));
        $$->children.push_back($3);
        $$->children.push_back($4);
        $$->children.push_back($5);
      }
    | k_class Identifier Super ClassBody
        {   
            $$=new Node("NormalClassDeclaration"); 
            $$->children.push_back(new Node("class","Keyword"));
            $$->children.push_back(new Node($2,"Identifier"));
            $$->children.push_back($3);
            $$->children.push_back($4);
        }
    | k_class Identifier Interfaces ClassBody
        {   
            $$=new Node("NormalClassDeclaration"); 
            $$->children.push_back(new Node("class","Keyword"));
            $$->children.push_back(new Node($2,"Identifier"));
            $$->children.push_back($3);
            $$->children.push_back($4);
        }
    | k_class Identifier ClassBody 
       {
            $$=new Node("NormalClassDeclaration"); 
            $$->children.push_back(new Node("class","Keyword"));
            $$->children.push_back(new Node($2,"Identifier"));
            $$->children.push_back($3);
       }



Super: k_extends ClassType
        {
            $$=new Node("Super");
            $$->children.push_back(new Node("extends","Keyword"));
            $$->children.push_back($2);
        }

Interfaces: k_implements InterfaceTypeList
            {
                $$=new Node("Interfaces");
                $$->children.push_back(new Node("implements","Keyword"));
                $$->children.push_back($2);
            }

InterfaceTypeList:InterfaceType
                    {
                        $$=$1;
                    }
	            |InterfaceTypeList s_comma InterfaceType
                    {
                        $$=new Node("InterfaceTypeList");
                        $$->children.push_back($1);
                        $$->children.push_back(new Node(",","Separator"));
                        $$->children.push_back($3);
                    }

ClassBody: s_open_curly_bracket ClassBodyDeclarations s_close_curly_bracket 
{
    $$=new Node("ClassBody", true);
    $$->children.push_back(new Node("{","Separator"));
    $$->children.push_back($2);
    $$->children.push_back(new Node("}","Separator"));
}
| s_open_curly_bracket s_close_curly_bracket 
{
    $$=new Node("ClassBody");
    $$->children.push_back(new Node("{","Separator"));
    $$->children.push_back(new Node("}","Separator"));
}

ClassBodyDeclarations:ClassBodyDeclaration  
                        {
                            $$=$1;
                        }
	                |ClassBodyDeclarations ClassBodyDeclaration
                        {
                            $$=new Node("ClassBodyDeclarations");
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                        }

ClassBodyDeclaration:ClassMemberDeclaration  
                        {
                            $$=$1;
                        }
                    |StaticInitializer  
                        {
                            $$=$1;
                        }
                    |ConstructorDeclaration     
                        {
                            $$=$1;
                        }

ClassMemberDeclaration:FieldDeclaration     
                        {
                            $$=$1;
                        }
                      |MethodDeclaration     
                        {
                            $$=$1;
                        }

FieldDeclaration: Modifiers Type VariableDeclaratorList s_semicolon     
                        {
                            $$=new Node("FieldDeclaration");
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                            $$->children.push_back($3);
                            $$->children.push_back(new Node(";","Separator"));
                        }
                        | Type VariableDeclaratorList s_semicolon     
                        {
                            $$=new Node("FieldDeclaration");
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                            $$->children.push_back(new Node(";","Separator"));
                        }

VariableDeclaratorList:VariableDeclarator     
                        {
                            $$=$1;
                        }
	                  |VariableDeclaratorList s_comma VariableDeclarator   
                        {
                            $$=new Node("VariableDeclaratorList");
                            $$->children.push_back($1);
                            $$->children.push_back(new Node(",","Separator"));
                            $$->children.push_back($3);
                        }

VariableDeclarator: VariableDeclaratorId     
                        {
                            $$=$1;
                        }
	               |VariableDeclaratorId o_assign VariableInitializer     
                        {
                            $$=new Node("VariableDeclarator");
                            $$->children.push_back($1);
                            $$->children.push_back(new Node("=","Operator"));
                            $$->children.push_back($3);
                        }

VariableDeclaratorId: Identifier
                      {
                        $$ = new Node($1,"Identifier");
                      }
	                 |VariableDeclaratorId s_open_square_bracket s_close_square_bracket     
                        {
                            $$=new Node("VariableDeclaratorId");
                            $$->children.push_back($1);
                            $$->children.push_back(new Node("[","Separator"));
                            $$->children.push_back(new Node("]","Separator"));
                        }

VariableInitializer:Expression     
                        {
                            $$=$1;
                        }
	               |ArrayInitializer     
                        {
                            $$=$1;
                        }

MethodDeclaration: MethodHeader MethodBody     
                        {
                            $$=new Node("MethodDeclaration");
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                        }

MethodHeader:   
	Modifiers Type MethodDeclarator Throws    {   
            $$=new Node("MethodHeader"); 
            $$->children.push_back($1);
            $$->children.push_back($2);
            $$->children.push_back($3);
            $$->children.push_back($4);
        }
    | Modifiers Type MethodDeclarator {   
            $$=new Node("MethodHeader"); 
            $$->children.push_back($1);
            $$->children.push_back($2);
            $$->children.push_back($3);
        }
    |  Type MethodDeclarator Throws {   
            $$=new Node("MethodHeader"); 
            $$->children.push_back($1);
            $$->children.push_back($2);
            $$->children.push_back($3);
        }
    |  Type MethodDeclarator    {   
            $$=new Node("MethodHeader"); 
            $$->children.push_back($1);
            $$->children.push_back($2);
        }
	| Modifiers k_void MethodDeclarator Throws  {   
            $$=new Node("MethodHeader"); 
            $$->children.push_back($1);
            $$->children.push_back(new Node("void","Keyword"));
            $$->children.push_back($3);
            $$->children.push_back($4);
        }
    | Modifiers k_void MethodDeclarator {   
            $$=new Node("MethodHeader"); 
            $$->children.push_back($1);
            $$->children.push_back(new Node("void","Keyword"));
            $$->children.push_back($3);
        }
    |  k_void MethodDeclarator Throws {   
            $$=new Node("MethodHeader"); 
            $$->children.push_back(new Node("void","Keyword"));
            $$->children.push_back($2);
            $$->children.push_back($3);
        }
    |  k_void MethodDeclarator {   
            $$=new Node("MethodHeader"); 
            $$->children.push_back(new Node("void","Keyword"));
            $$->children.push_back($2);
            }

MethodDeclarator: 
	Identifier s_open_paren FormalParameterList s_close_paren {   
            $$=new Node("MethodDeclarator"); 
            $$->children.push_back(new Node($1,"Identifier"));
            $$->children.push_back(new Node("(","Separator"));
            $$->children.push_back($3);
            $$->children.push_back(new Node(")","Separator"));
        }
    | Identifier s_open_paren s_close_paren {   
            $$=new Node("MethodDeclarator"); 
            $$->children.push_back(new Node($1,"Identifier"));
            $$->children.push_back(new Node("(","Separator"));
            $$->children.push_back(new Node(")","Separator"));
        }
	| MethodDeclarator s_open_square_bracket s_close_square_bracket {   
            $$=new Node("MethodDeclarator"); 
            $$->children.push_back($1);
            $$->children.push_back(new Node("[","Separator"));
            $$->children.push_back(new Node("]","Separator"));
            }

FormalParameterList: FormalParameter    
                        {
                            $$=$1;
                        }
	                |FormalParameterList s_comma FormalParameter   
                        {
                            $$=new Node("FormalParameterList");
                            $$->children.push_back($1);
                            $$->children.push_back(new Node(",","Separator"));
                            $$->children.push_back($3);
                        }

FormalParameter: Type VariableDeclaratorId   
                        {
                            $$=new Node("FormalParameter");
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                        }
                | k_final Type VariableDeclaratorId     
                        {
                            $$=new Node("FormalParameter");
                            $$->children.push_back(new Node("final","Keyword"));
                            $$->children.push_back($2);
                            $$->children.push_back($3);
                        }

Throws: k_throws ClassTypeList  
                        {
                            $$=new Node("Throws");
                            $$->children.push_back(new Node("throws","Keyword"));
                            $$->children.push_back($2);
                        }

ClassTypeList:ClassType  
                        {
                            $$=$1;
                        }
	        | ClassTypeList s_comma ClassType  
                        {
                            $$=new Node("ClassTypeList");
                            $$->children.push_back($1);
                            $$->children.push_back(new Node(",","Separator"));
                            $$->children.push_back($3);
                        }

MethodBody: Block  
                {
                    $$=$1;
                }
        
	| s_semicolon
    {
        $$ = new Node(";","Separator");
    }

StaticInitializer: k_static Block 
                        {
                            $$=new Node("StaticInitializer");
                            $$->children.push_back(new Node("static","Keyword"));
                            $$->children.push_back($2);
                        }
	;

ConstructorDeclaration:

	Modifiers ConstructorDeclarator Throws ConstructorBody {  
            $$=new Node("ConstructorDeclaration"); 
            $$->children.push_back($1);
            $$->children.push_back($2);
            $$->children.push_back($3);
            $$->children.push_back($4);
            }
	| Modifiers ConstructorDeclarator ConstructorBody {  
            $$=new Node("ConstructorDeclaration"); 
            $$->children.push_back($1);
            $$->children.push_back($2);
            $$->children.push_back($3);
            }
	| ConstructorDeclarator Throws ConstructorBody {  
            $$=new Node("ConstructorDeclaration"); 
            $$->children.push_back($1);
            $$->children.push_back($2);
            $$->children.push_back($3);
            }
	| ConstructorDeclarator ConstructorBody {  
            $$=new Node("ConstructorDeclaration"); 
            $$->children.push_back($1);
            $$->children.push_back($2);
            }
	;

ConstructorDeclarator:

	SimpleName s_open_paren FormalParameterList s_close_paren   
            {  
            $$=new Node("ConstructorDeclarator"); 
            $$->children.push_back($1);
            $$->children.push_back(new Node("(","Separator"));
            $$->children.push_back($3);
            $$->children.push_back(new Node(")","Separator"));
            }
	|SimpleName s_open_paren s_close_paren {  
            $$=new Node("ConstructorDeclarator"); 
            $$->children.push_back($1);
            $$->children.push_back(new Node("(","Separator"));
            $$->children.push_back(new Node(")","Separator"));
            }
	;

ConstructorBody:
	s_open_curly_bracket s_close_curly_bracket {  
            $$=new Node("ConstructorBody"); 
            $$->children.push_back(new Node("{","Separator"));
            $$->children.push_back(new Node("}","Separator"));
            }
	| s_open_curly_bracket BlockStatements s_close_curly_bracket {  
            $$=new Node("ConstructorBody", true); 
            $$->children.push_back(new Node("{","Separator"));
            $$->children.push_back($2);
            $$->children.push_back(new Node("}","Separator"));
            }
	| s_open_curly_bracket ExplicitConstructorInvocation s_close_curly_bracket {  
            $$=new Node("ConstructorBody"); 
            $$->children.push_back(new Node("{","Separator"));
            $$->children.push_back($2);
            $$->children.push_back(new Node("}","Separator"));
            }
	| s_open_curly_bracket ExplicitConstructorInvocation BlockStatements s_close_curly_bracket {  
            $$=new Node("ConstructorBody", true); 
            $$->children.push_back(new Node("{","Separator"));
            $$->children.push_back($2);
            $$->children.push_back($3);
            $$->children.push_back(new Node("}","Separator"));
            }
	;

ExplicitConstructorInvocation:

	k_this s_open_paren ArgumentList s_close_paren s_semicolon {  
            $$=new Node("ExplicitConstructorInvocation"); 
            $$->children.push_back(new Node("this","Keyword"));
            $$->children.push_back(new Node("(","Separator"));
            $$->children.push_back($3);
            $$->children.push_back(new Node(")","Separator"));
            $$->children.push_back(new Node(";","Separator"));
            }
	| k_this s_open_paren s_close_paren s_semicolon {  
            $$=new Node("ExplicitConstructorInvocation"); 
            $$->children.push_back(new Node("this","Keyword"));
            $$->children.push_back(new Node("(","Separator"));
            $$->children.push_back(new Node(")","Separator"));
            $$->children.push_back(new Node(";","Separator"));
            }
	| k_super s_open_paren ArgumentList s_close_paren s_semicolon {  
            $$=new Node("ExplicitConstructorInvocation"); 
            $$->children.push_back(new Node("super","Keyword"));
            $$->children.push_back(new Node("(","Separator"));
            $$->children.push_back($3);
            $$->children.push_back(new Node(")","Separator"));
            $$->children.push_back(new Node(";","Separator"));}
	| k_super s_open_paren s_close_paren s_semicolon {  
            $$=new Node("ExplicitConstructorInvocation"); 
            $$->children.push_back(new Node("super","Keyword"));
            $$->children.push_back(new Node("(","Separator"));
            $$->children.push_back(new Node(")","Separator"));
            $$->children.push_back(new Node(";","Separator"));
            }
	;

EnumDeclaration : Modifiers k_enum Identifier ClassImplements EnumBody {  
                    $$=new Node("EnumDeclaration"); 
                    $$->children.push_back($1);
                    $$->children.push_back(new Node("enum","Keyword"));
                    $$->children.push_back(new Node($3,"Identifier"));
                    $$->children.push_back($4);
                    $$->children.push_back($5);
                    }
                 |Modifiers k_enum Identifier EnumBody {  
                    $$=new Node("EnumDeclaration"); 
                    $$->children.push_back($1);
                    $$->children.push_back(new Node("enum","Keyword"));
                    $$->children.push_back(new Node($3,"Identifier"));
                    $$->children.push_back($4);
                    }
                 |k_enum Identifier ClassImplements EnumBody {  
                    $$=new Node("EnumDeclaration"); 
                    $$->children.push_back(new Node("enum","Keyword"));
                    $$->children.push_back(new Node($2,"Identifier"));
                    $$->children.push_back($3);
                    $$->children.push_back($4);
                    }
                 |k_enum Identifier EnumBody {  
                    $$=new Node("EnumDeclaration"); 
                    $$->children.push_back(new Node("enum","Keyword"));
                    $$->children.push_back(new Node($2,"Identifier"));
                    $$->children.push_back($3);
                    }

ClassImplements : k_implements InterfaceTypeList {  
                    $$=new Node("ClassImplements"); 
                    $$->children.push_back(new Node("implements","Keyword"));
                    $$->children.push_back($2);
                    }

EnumBody : s_open_curly_bracket EnumConstantList s_comma EnumBodyDeclarations s_close_curly_bracket {  
                    $$=new Node("EnumBody", true); 
                    $$->children.push_back(new Node("{","Separator"));
                    $$->children.push_back($2);
                    $$->children.push_back(new Node(",","Separator"));
                    $$->children.push_back($4);
                    $$->children.push_back(new Node("}","Separator"));
                    }
          |s_open_curly_bracket EnumConstantList s_comma s_close_curly_bracket  {  
                    $$=new Node("EnumBody", true); 
                    $$->children.push_back(new Node("{","Separator"));
                    $$->children.push_back($2);
                    $$->children.push_back(new Node(",","Separator"));
                    $$->children.push_back(new Node("}","Separator"));
                    }
          |s_open_curly_bracket EnumConstantList EnumBodyDeclarations s_close_curly_bracket {  
                    $$=new Node("EnumBody"m true); 
                    $$->children.push_back(new Node("{","Separator"));
                    $$->children.push_back($2);
                    $$->children.push_back($3);
                    $$->children.push_back(new Node("}","Separator"));
                    }
          |s_open_curly_bracket EnumConstantList s_close_curly_bracket {  
                    $$=new Node("EnumBody", true); 
                    $$->children.push_back(new Node("{","Separator"));
                    $$->children.push_back($2);
                    $$->children.push_back(new Node("}","Separator"));
                    }
          |s_open_curly_bracket s_comma EnumBodyDeclarations s_close_curly_bracket {  
                    $$=new Node("EnumBody", true); 
                    $$->children.push_back(new Node("{","Separator"));
                    $$->children.push_back(new Node(",","Separator"));
                    $$->children.push_back($3);
                    $$->children.push_back(new Node("}","Separator"));
                    }
          |s_open_curly_bracket s_comma s_close_curly_bracket {  
                    $$=new Node("EnumBody", true); 
                    $$->children.push_back(new Node("{","Separator"));
                    $$->children.push_back(new Node(",","Separator"));
                    $$->children.push_back(new Node("}","Separator"));
                    }
          |s_open_curly_bracket EnumBodyDeclarations s_close_curly_bracket {  
                    $$=new Node("EnumBody", true); 
                    $$->children.push_back(new Node("{","Separator"));
                    $$->children.push_back($2);
                    $$->children.push_back(new Node("}","Separator"));
                    }
          |s_open_curly_bracket s_close_curly_bracket {  
                    $$=new Node("EnumBody", true); 
                    $$->children.push_back(new Node("{","Separator"));
                    $$->children.push_back(new Node("}","Separator"));
                    }

EnumBodyDeclarations : s_semicolon  {  
                    $$=new Node(";","Separator");
                    }
                    | s_semicolon ClassBodyDeclarations {  
                    $$=new Node("EnumBodyDeclarations"); 
                    $$->children.push_back(new Node(";","Separator"));
                    $$->children.push_back($2);
                    }

EnumConstantList : EnumConstant {$$=$1;}
                  | EnumConstantList s_comma EnumConstant 
                    {
                    $$=new Node("EnumConstantList");
                    $$->children.push_back($1);
                    $$->children.push_back(new Node(",","Separator"));
                    $$->children.push_back($3);
                    }

EnumConstant : Identifier s_open_paren ArgumentList s_close_paren ClassBody {  
                    $$=new Node("EnumConstant"); 
                    $$->children.push_back(new Node($1,"Identifier"));
                    $$->children.push_back(new Node("(","Separator"));
                    $$->children.push_back($3);
                    $$->children.push_back(new Node(")","Separator"));
                    $$->children.push_back($5);
                    }
                  |Identifier s_open_paren s_close_paren ClassBody {  
                    $$=new Node("EnumConstant"); 
                    $$->children.push_back(new Node($1,"Identifier"));
                    $$->children.push_back(new Node("(","Separator"));
                    $$->children.push_back(new Node(")","Separator"));
                    $$->children.push_back($4);
                    }
                  |Identifier s_open_paren ArgumentList s_close_paren {  
                    $$=new Node("EnumConstant"); 
                    $$->children.push_back(new Node($1,"Identifier"));
                    $$->children.push_back(new Node("(","Separator"));
                    $$->children.push_back($3);
                    $$->children.push_back(new Node(")","Separator"));
                    }
                  |Identifier s_open_paren s_close_paren {  
                    $$=new Node("EnumConstant"); 
                    $$->children.push_back(new Node($1,"Identifier"));
                    $$->children.push_back(new Node("(","Separator"));
                    $$->children.push_back(new Node(")","Separator"));
                    }
                  |Identifier ClassBody {  
                    $$=new Node("EnumConstant"); 
                    $$->children.push_back(new Node($1,"Identifier"));
                    $$->children.push_back($2);
                    }
                  |Identifier {  
                    $$=new Node($1,"Identifier");
                    }
// ---------------------------- Production 9 -----------------------

InterfaceDeclaration:
	Modifiers k_interface Identifier ExtendsInterfaces InterfaceBody
    { $$=new Node("InterfaceDeclaration"); 
      $$->children.push_back($1);
      $$->children.push_back(new Node("interface","Keyword"));
      $$->children.push_back(new Node($3,"Identifier"));
      $$->children.push_back($4);
      $$->children.push_back($5);}
	| Modifiers k_interface Identifier InterfaceBody
    { $$=new Node("InterfaceDeclaration"); 
      $$->children.push_back($1);
      $$->children.push_back(new Node("interface","Keyword"));
      $$->children.push_back(new Node($3,"Identifier"));
      $$->children.push_back($4);}
	| k_interface Identifier ExtendsInterfaces InterfaceBody
    {
        $$=new Node("InterfaceDeclaration"); 
        $$->children.push_back(new Node("interface","Keyword"));
        $$->children.push_back(new Node($2,"Identifier"));
        $$->children.push_back($3);
        $$->children.push_back($4);
    }
	| k_interface Identifier InterfaceBody
    {
        $$=new Node("InterfaceDeclaration"); 
        $$->children.push_back(new Node("interface","Keyword"));
        $$->children.push_back(new Node($2,"Identifier"));
        $$->children.push_back($3);
    }
	;

ExtendsInterfaces:
	k_extends InterfaceType
    {
        $$=new Node("ExtendsInterfaces");
        $$->children.push_back(new Node("extends","Keyword"));
        $$->children.push_back($2);
    }
	| ExtendsInterfaces s_comma InterfaceType
    {
        $$=new Node("ExtendsInterfaces");
        $$->children.push_back($1);
        $$->children.push_back(new Node("comma","Separator"));
        $$->children.push_back($3);
    }
	;

InterfaceBody:
	s_open_curly_bracket InterfaceMemberDeclarations s_close_curly_bracket
    {
        $$=new Node("InterfaceBody", true);
        $$->children.push_back(new Node("{","Separator"));
        $$->children.push_back($2);
        $$->children.push_back(new Node("}","Separator"));
    }
	|s_open_curly_bracket s_close_curly_bracket
    {
        $$=new Node("InterfaceBody");
        $$->children.push_back(new Node("{","Separator"));
        $$->children.push_back(new Node("}","Separator"));
    }
	;

InterfaceMemberDeclarations: InterfaceMemberDeclaration
{ $$=new Node("InterfaceMemberDeclarations"); $$->children.push_back($1);}
	| InterfaceMemberDeclarations InterfaceMemberDeclaration
    { $$=new Node("InterfaceMemberDeclarations"); $$->children.push_back($1); $$->children.push_back($2);}
	;

InterfaceMemberDeclaration: ConstantDeclaration
{
    $$=new Node("InterfaceMemberDeclaration");
    $$->children.push_back($1);
}
	| AbstractMethodDeclaration
    {
        $$=new Node("InterfaceMemberDeclaration");
        $$->children.push_back($1);
    }
	;

ConstantDeclaration: FieldDeclaration
{
    $$=new Node("ConstantDeclaration");
    $$->children.push_back($1);
}
	;

AbstractMethodDeclaration: MethodHeader s_semicolon 
{
    $$=new Node("AbstractMethodDeclaration");
    $$->children.push_back($1);
    $$->children.push_back(new Node(";","Separator"));
}
	;


// ------------------------------- Production 10 ---------------------

ArrayInitializer:
	s_open_curly_bracket VariableInitializerList s_comma s_close_curly_bracket
    {
        $$=new Node("ArrayInitializer");
        $$->children.push_back(new Node("{","Separator"));
        $$->children.push_back($2);
        $$->children.push_back(new Node(",","Separator"));
        $$->children.push_back(new Node("}","Separator"));
    }
	| s_open_curly_bracket VariableInitializerList  s_close_curly_bracket
    {
        $$=new Node("ArrayInitializer");
        $$->children.push_back(new Node("{","Separator"));
        $$->children.push_back($2);
        $$->children.push_back(new Node("}","Separator"));
    }
	| s_open_curly_bracket  s_comma s_close_curly_bracket
    {
        $$=new Node("ArrayInitializer");
        $$->children.push_back(new Node("{","Separator"));
        $$->children.push_back(new Node(",","Separator"));
        $$->children.push_back(new Node("}","Separator"));
    }
	| s_open_curly_bracket  s_close_curly_bracket
    {
        $$=new Node("ArrayInitializer");
        $$->children.push_back(new Node("{","Separator"));
        $$->children.push_back(new Node("}","Separator"));
    }
	;

VariableInitializerList: VariableInitializer
{
    $$=new Node("VariableInitializerList");
    $$->children.push_back($1);
}
	| VariableInitializerList s_comma VariableInitializer
    {
        $$=new Node("VariableInitializerList");
        $$->children.push_back($1);
        $$->children.push_back(new Node(",","Separator"));
        $$->children.push_back($3);
    }
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
        $$=new Node("Block", true);
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
        $$ = $1;
    }
    ;

LocalVariableDeclarationStatement : LocalVariableDeclaration s_semicolon
    {
        $$ = new Node("LocalVariableDeclarationStatement");
        $$->children.push_back($1);
        $$->children.push_back(new Node(";", "Separator"));
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
        $$->children.push_back(new Node($1, "Identifier"));
        $$->children.push_back(new Node(":", "Operator"));
        $$->children.push_back($3);
    }
	;

LabeledStatementNoShortIf:

	Identifier o_colon StatementNoShortIf
    {
        $$ = new Node("LabeledStatementNoShortIf");
        $$->children.push_back(new Node($1, "Identifier"));
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


ForStatement : BasicForStatement {$$=$1;}| EnhancedForStatement {$$=$1;}
ForStatementNoShortIf : BasicForStatementNoShortIf {$$=$1;}| EnhancedForStatementNoShortIf {$$=$1;}

BasicForStatement:
	k_for s_open_paren s_semicolon s_semicolon s_close_paren Statement 
    {
        $$ = new Node("BasicForStatement");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($6);
    }
    | k_for s_open_paren s_semicolon s_semicolon ForUpdate s_close_paren Statement 
    {
        $$ = new Node("BasicForStatement");
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
        $$ = new Node("BasicForStatement");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($4);
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($7);
    }
    | k_for s_open_paren s_semicolon Expression s_semicolon ForUpdate s_close_paren Statement 
    {
        $$ = new Node("BasicForStatement");
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
        $$ = new Node("BasicForStatement");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back($3);
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($7);
    }
    | k_for s_open_paren ForInit s_semicolon s_semicolon ForUpdate s_close_paren Statement 
    {
        $$ = new Node("BasicForStatement");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back($3);
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($6);
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($8);
    }
    | k_for s_open_paren ForInit s_semicolon Expression s_semicolon s_close_paren Statement 
    {
        $$ = new Node("BasicForStatement");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back($3);
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($5);
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($8);
    }
    | k_for s_open_paren ForInit s_semicolon Expression s_semicolon ForUpdate s_close_paren Statement 
    {
        $$ = new Node("BasicForStatement");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back($3);
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($5);
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($7);
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($9);
    }
    ;


BasicForStatementNoShortIf:
	k_for s_open_paren s_semicolon s_semicolon s_close_paren StatementNoShortIf
     {
        $$ = new Node("BasicForStatementNoShortIf");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($6);
     }
    | k_for s_open_paren s_semicolon s_semicolon ForUpdate s_close_paren StatementNoShortIf
    {
        $$ = new Node("BasicForStatementNoShortIf");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($5);
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($7);
    }
    | k_for s_open_paren s_semicolon Expression s_semicolon s_close_paren StatementNoShortIf
    {
        $$ = new Node("BasicForStatementNoShortIf");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($4);
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($7);
    }
    | k_for s_open_paren s_semicolon Expression s_semicolon ForUpdate s_close_paren StatementNoShortIf
    {
        $$ = new Node("BasicForStatementNoShortIf");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($4);
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($6);
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($8);
    }
    | k_for s_open_paren ForInit s_semicolon s_semicolon s_close_paren StatementNoShortIf
    {
        $$ = new Node("BasicForStatementNoShortIf");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back($3);
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($7);
    }
    | k_for s_open_paren ForInit s_semicolon s_semicolon ForUpdate s_close_paren StatementNoShortIf
    {
        $$ = new Node("BasicForStatementNoShortIf");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back($3);
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($6);
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($8);
    }
    | k_for s_open_paren ForInit s_semicolon Expression s_semicolon s_close_paren StatementNoShortIf
    {
        $$ = new Node("BasicForStatementNoShortIf");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back($3);
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($5);
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($8);
    }
    | k_for s_open_paren ForInit s_semicolon Expression s_semicolon ForUpdate s_close_paren StatementNoShortIf
    {
        $$ = new Node("BasicForStatementNoShortIf");
        $$->children.push_back(new Node("for", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back($3);
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($5);
        $$->children.push_back(new Node(";", "Separator"));
        $$->children.push_back($7);
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($9);
    }
    ;

EnhancedForStatementNoShortIf: k_for s_open_paren LocalVariableDeclaration o_colon Expression s_close_paren StatementNoShortIf 
{
    $$ = new Node("EnhancedForStatementNoShortIf");
    $$->children.push_back(new Node("for", "Keyword"));
    $$->children.push_back(new Node("(", "Separator"));
    $$->children.push_back($3);
    $$->children.push_back(new Node(":", "Separator"));
    $$->children.push_back($5);
    $$->children.push_back(new Node(")", "Separator"));
    $$->children.push_back($7);
}

ForInit : 
    StatementExpressionList
    {
       $$ = $1;
    } 
    | LocalVariableDeclaration 
    {
        $$ = $1;
    }
    ;

ForUpdate : 
	StatementExpressionList 
    {
        $$ = $1;
    }
	;

EnhancedForStatement: k_for s_open_paren LocalVariableDeclaration o_colon Expression s_close_paren Statement 
{
    $$ = new Node("EnhancedForStatement");
    $$->children.push_back(new Node("for", "Keyword"));
    $$->children.push_back(new Node("(", "Separator"));
    $$->children.push_back($3);
    $$->children.push_back(new Node(":", "Separator"));
    $$->children.push_back($5);
    $$->children.push_back(new Node(")", "Separator"));
    $$->children.push_back($7);
}

StatementExpressionList:StatementExpression {$$ = $1;}
                       |StatementExpressionList s_comma StatementExpression
                       {
                            $$ = new Node("StatementExpressionList");
                            $$->children.push_back($1);
                            $$->children.push_back(new Node(",", "Separator"));
                            $$->children.push_back($3);
                       }

BreakStatement: k_break s_semicolon 
{ 
    $$ = new Node("BreakStatement");
    $$->children.push_back(new Node("break", "Keyword"));
    $$->children.push_back(new Node(";", "Separator"));}
 | k_break Identifier s_semicolon
 {
    $$ = new Node("BreakStatement");
    $$->children.push_back(new Node("break", "Keyword"));
    $$->children.push_back(new Node($3, "Identifier"));
    $$->children.push_back(new Node(";", "Separator"));}

ContinueStatement: k_continue s_semicolon
    {
        $$ = new Node("ContinueStatement");
        $$->children.push_back(new Node("continue", "Keyword"));
        $$->children.push_back(new Node(";", "Separator"));
    }
 | k_continue Identifier s_semicolon 
 {
    $$ = new Node("ContinueStatement");
    $$->children.push_back(new Node("continue", "Keyword"));
    $$->children.push_back(new Node($2, "Identifier"));
    $$->children.push_back(new Node(";", "Separator"));
 }

ReturnStatement: k_return s_semicolon 
{
    $$ = new Node("ReturnStatement");
    $$->children.push_back(new Node("return", "Keyword"));
    $$->children.push_back(new Node(";", "Separator"));
}
| k_return Expression s_semicolon 
{
    $$ = new Node("ReturnStatement");
    $$->children.push_back(new Node("return", "Keyword"));
    $$->children.push_back($2);
    $$->children.push_back(new Node(";", "Separator"));
}

ThrowStatement: k_throw s_semicolon
{
    $$ = new Node("ThrowStatement");
    $$->children.push_back(new Node("throw", "Keyword"));
    $$->children.push_back(new Node(";", "Separator"));}
 | k_throw Expression s_semicolon 
 {
    $$ = new Node("ThrowStatement");
    $$->children.push_back(new Node("throw", "Keyword"));
    $$->children.push_back($2);
    $$->children.push_back(new Node(";", "Separator"));
 }

SynchronizedStatement:

	k_synchronized s_open_paren Expression s_close_paren Block
    {
        $$ = new Node("SynchronizedStatement");
        $$->children.push_back(new Node("synchronized", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back($3);
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($5);
    }

TryStatement: k_try Block Catches
    {
    $$ = new Node("TryStatement");
    $$->children.push_back(new Node("try", "Keyword"));
    $$->children.push_back($2);
    $$->children.push_back($3);
    }
	        | k_try Block Finally
            {
                $$ = new Node("TryStatement");
                $$->children.push_back(new Node("try", "Keyword"));
                $$->children.push_back($2);
                $$->children.push_back($3);
            }
            | k_try Block Catches Finally
            {
                $$ = new Node("TryStatement");
                $$->children.push_back(new Node("try", "Keyword"));
                $$->children.push_back($2);
                $$->children.push_back($3);
                $$->children.push_back($4);}

Catches: CatchClause
    {
        $$ = new Node("Catches");
        $$->children.push_back($1);
    }
        |Catches CatchClause
        {
            $$ = new Node("Catches");
            $$->children.push_back($1);
            $$->children.push_back($2);
        }

CatchClause: k_catch s_open_paren FormalParameter s_close_paren Block
    {
        $$ = new Node("CatchClause");
        $$->children.push_back(new Node("catch", "Keyword"));
        $$->children.push_back(new Node("(", "Separator"));
        $$->children.push_back($3);
        $$->children.push_back(new Node(")", "Separator"));
        $$->children.push_back($5);
    }

Finally: k_finally Block
    {
        $$ = new Node("Finally");
        $$->children.push_back(new Node("finally", "Keyword"));
        $$->children.push_back($2);
    }


// ------------------ Production 15 -------------------

Primary:
    PrimaryNoNewArray {$$ = $1;}
    | ArrayCreationExpression {$$ = $1;}
    ;

PrimaryNoNewArray:
    int_Literal {$$ = new Node($1,"Literal");}
    | bin_Literal {$$ = new Node($1,"Literal");} 
    | deci_flo_Literal {$$ = new Node($1,"Literal");} 
    | oct_Literal {$$ = new Node($1,"Literal");} 
    | hex_flo_Literal {$$ = new Node($1,"Literal");} 
    | string_Literal {$$ = new Node($1,"Literal");} 
    | hex_Literal {$$ = new Node($1,"Literal");}
    | k_this {$$ = new Node("this","Keyword");}
    | Text_Block_Literal {$$ = new Node("TextBlock","Literal");}
    | char_Literal {$$ = new Node($1,"Literal");}
    | true_Literal {$$ = new Node("true","Keyword");}
    | false_Literal {$$ = new Node("false","Keyword");}
    | null_Literal {$$ = new Node("null","Keyword");}
    | s_open_paren Expression s_close_paren {
        $$ = new Node("PrimaryNoNewArray");
        $$->children.push_back(new Node("(","Separator"));
        $$->children.push_back($2);
        $$->children.push_back(new Node(")","Separator"));
    }
    | ClassInstanceCreationExpression {$$ = $1;}
    | FieldAccess {$$ = $1;}
    | MethodInvocation {$$ = $1;}
    | ArrayAccess {$$ = $1;}
    ;

ClassInstanceCreationExpression:
    k_new ClassType s_open_paren s_close_paren
     { $$ = new Node("ClassInstanceCreationExpression");
       $$->children.push_back(new Node("new","Keyword"));
       $$->children.push_back($2);
       $$->children.push_back(new Node("(","Separator"));
       $$->children.push_back(new Node(")","Separator"));}
    | k_new ClassType s_open_paren ArgumentList s_close_paren
        { $$ = new Node("ClassInstanceCreationExpression");
        $$->children.push_back(new Node("new","Keyword"));
        $$->children.push_back($2);
        $$->children.push_back(new Node("(","Separator"));
        $$->children.push_back($4);
        $$->children.push_back(new Node(")","Separator"));}
    ;

ArgumentList:
    Expression
    {$$ = $1;}
    | ArgumentList s_comma Expression
    {$$ = new Node("ArgumentList");
    $$->children.push_back($1);
    $$->children.push_back(new Node(",","Separator"));
    $$->children.push_back($3);}
    ;

ArrayCreationExpression:
    k_new PrimitiveType DimExprs 
     { $$ = new Node("ArrayCreationExpression");
       $$->children.push_back(new Node("new","Keyword"));
       $$->children.push_back($2);
       $$->children.push_back($3);}
    | k_new PrimitiveType Dims ArrayInitializer
        { $$ = new Node("ArrayCreationExpression");
       $$->children.push_back(new Node("new","Keyword"));
       $$->children.push_back($2);
       $$->children.push_back($3);
       $$->children.push_back($4);}
    | k_new PrimitiveType DimExprs Dims
        { $$ = new Node("ArrayCreationExpression");
       $$->children.push_back(new Node("new","Keyword"));
       $$->children.push_back($2);
       $$->children.push_back($3);
       $$->children.push_back($4);}
    | k_new Name DimExprs 
        { $$ = new Node("ArrayCreationExpression");
       $$->children.push_back(new Node("new","Keyword"));
       $$->children.push_back($2);
       $$->children.push_back($3);}
    | k_new Name DimExprs Dims
        { $$ = new Node("ArrayCreationExpression");
       $$->children.push_back(new Node("new","Keyword"));
       $$->children.push_back($2);
       $$->children.push_back($3);
       $$->children.push_back($4);}
    | k_new Name Dims ArrayInitializer
        { $$ = new Node("ArrayCreationExpression");
       $$->children.push_back(new Node("new","Keyword"));
       $$->children.push_back($2);
       $$->children.push_back($3);
       $$->children.push_back($4);}
    ;


DimExprs:
    DimExpr
     {$$ = $1;}
    | DimExprs DimExpr
    {$$ = new Node("DimExprs");
    $$->children.push_back($1);
    $$->children.push_back($2);}
    ;

DimExpr:
    s_open_square_bracket Expression s_close_square_bracket
     {$$ = new Node("DimExpr");
     $$->children.push_back(new Node("[","Separator"));
     $$->children.push_back($2);
     $$->children.push_back(new Node("]","Separator"));}
    ;


Dims:
    s_open_square_bracket s_close_square_bracket
    {$$ = new Node("Dims");
    $$->children.push_back(new Node("[","Separator"));
    $$->children.push_back(new Node("]","Separator"));}
    | Dims s_open_square_bracket s_close_square_bracket
    {$$ = new Node("Dims");
    $$->children.push_back($1);
    $$->children.push_back(new Node("[","Separator"));}
    ;

FieldAccess:
    Primary s_dot Identifier
    {$$ = new Node("FieldAccess");
    $$->children.push_back($1);
    $$->children.push_back(new Node(".","Separator"));
    $$->children.push_back(new Node($3,"Identifier"));}
    | k_super s_dot Identifier
    {$$ = new Node("FieldAccess");
    $$->children.push_back(new Node("super","Keyword"));
    $$->children.push_back(new Node(".","Separator"));
    $$->children.push_back(new Node($3,"Identifier"));}
    ;

MethodInvocation:
    Name s_open_paren s_close_paren
    {$$ = new Node("MethodInvocation");
    $$->children.push_back($1);
    $$->children.push_back(new Node("(","Separator"));
    $$->children.push_back(new Node(")","Separator"));
    }
    | Name s_open_paren ArgumentList s_close_paren
     {$$ = new Node("MethodInvocation");
     $$->children.push_back($1);
     $$->children.push_back(new Node("(","Separator"));
     $$->children.push_back($3);
     $$->children.push_back(new Node(")","Separator"));
     }
    | Primary s_dot Identifier s_open_paren s_close_paren
    {$$ = new Node("MethodInvocation");
    $$->children.push_back($1);
    $$->children.push_back(new Node(".","Separator"));
    $$->children.push_back(new Node($3,"Identifier"));
    $$->children.push_back(new Node("(","Separator"));
    $$->children.push_back(new Node(")","Separator"));
    }
    | Primary s_dot Identifier s_open_paren ArgumentList s_close_paren
    {$$ = new Node("MethodInvocation");
    $$->children.push_back($1);
    $$->children.push_back(new Node(".","Separator"));
    $$->children.push_back(new Node($3,"Identifier"));
    $$->children.push_back(new Node("(","Separator"));
    $$->children.push_back($5);
    $$->children.push_back(new Node(")","Separator"));
    }
    | k_super s_dot Identifier s_open_paren s_close_paren
    {$$ = new Node("MethodInvocation");
    $$->children.push_back(new Node("super","Keyword"));
    $$->children.push_back(new Node(".","Separator"));
    $$->children.push_back(new Node($3,"Identifier"));
    $$->children.push_back(new Node("(","Separator"));
    $$->children.push_back(new Node(")","Separator"));
    }
    | k_super s_dot Identifier s_open_paren ArgumentList s_close_paren
    {$$ = new Node("MethodInvocation");
    $$->children.push_back(new Node("super","Keyword"));
    $$->children.push_back(new Node(".","Separator"));
    $$->children.push_back(new Node($3,"Identifier"));
    $$->children.push_back(new Node("(","Separator"));
    $$->children.push_back($5);
    $$->children.push_back(new Node(")","Separator"));
    }
    ;

ArrayAccess:
    Name s_open_square_bracket Expression s_close_square_bracket
    {$$ = new Node("ArrayAccess");
    $$->children.push_back($1);
    $$->children.push_back(new Node("[","Separator"));
    $$->children.push_back($3);
    $$->children.push_back(new Node("]","Separator"));
    }
    | PrimaryNoNewArray s_open_square_bracket Expression s_close_square_bracket
    {$$ = new Node("ArrayAccess");
    $$->children.push_back($1);
    $$->children.push_back(new Node("[","Separator"));
    $$->children.push_back($3);
    $$->children.push_back(new Node("]","Separator"));
    }
    ;

PostFixExpression:
    Primary
    {$$ = $1;}
    | Name
    {$$ = $1;}
    | PostIncrementExpression
    {$$ = $1;}
    | PostDecrementExpression
    {$$ = $1;}
    ;

PostIncrementExpression:
    PostFixExpression o_increment
    {$$ = new Node("PostIncrementExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("++","Separator"));}
    ;

PostDecrementExpression:
    PostFixExpression o_decrement
    {$$ = new Node("PostDecrementExpression");
    $$->children.push_back($1);}
    ;

UnaryExpression:
    PreIncrementExpression
    {$$ = $1;}
    | PreDecrementExpression
    {$$ = $1;}
    | o_add UnaryExpression
    {$$ = new Node("UnaryExpression");
    $$->children.push_back(new Node("+","Separator"));
    $$->children.push_back($2);}
    | o_subtract UnaryExpression
    {$$ = new Node("UnaryExpression");
    $$->children.push_back(new Node("-","Separator"));
    $$->children.push_back($2);}
    | UnaryExpressionNotPlusMinus
    {$$ = $1;}
    ;

PreIncrementExpression:
    o_increment UnaryExpression
    {$$ = new Node("PreIncrementExpression");
    $$->children.push_back(new Node("++","Separator"));
    $$->children.push_back($2);}
    ;

PreDecrementExpression:
    o_decrement UnaryExpression
    {$$ = new Node("PreDecrementExpression");
    $$->children.push_back(new Node("--","Separator"));
    $$->children.push_back($2);}
    ;

UnaryExpressionNotPlusMinus:
   PostFixExpression
   {$$ = $1;}
    | o_bitwise_complement UnaryExpression
    {$$ = new Node("UnaryExpressionNotPlusMinus");
    $$->children.push_back(new Node("~","Separator"));
    $$->children.push_back($2);}
    | o_logical_not UnaryExpression
    {$$ = new Node("UnaryExpressionNotPlusMinus");
    $$->children.push_back(new Node("!","Separator"));
    $$->children.push_back($2);}
    | CastExpression
    {$$ = $1;}
    ;

CastExpression:
    s_open_paren PrimitiveType s_close_paren UnaryExpression
    {$$ = new Node("CastExpression");
    $$->children.push_back(new Node("(","Separator"));
    $$->children.push_back($2);
    $$->children.push_back(new Node(")","Separator"));
    $$->children.push_back($4);
    }
    | s_open_paren PrimitiveType Dims s_close_paren UnaryExpression
    {
    $$ = new Node("CastExpression");
    $$->children.push_back(new Node("(","Separator"));
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back(new Node(")","Separator"));
    $$->children.push_back($5);
    }
    | s_open_paren Expression s_close_paren UnaryExpressionNotPlusMinus
    {
    $$ = new Node("CastExpression");
    $$->children.push_back(new Node("(","Separator"));
    $$->children.push_back($2);
    $$->children.push_back(new Node(")","Separator"));
    $$->children.push_back($4);
    }
    | s_open_paren Name  Dims s_close_paren UnaryExpressionNotPlusMinus
    {
    $$ = new Node("CastExpression");
    $$->children.push_back(new Node("(","Separator"));
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back(new Node(")","Separator"));
    $$->children.push_back($5);
    }
    ;

MultiplicativeExpression:
    UnaryExpression
    {
    $$ = $1;
    }
    | MultiplicativeExpression o_multiply UnaryExpression
    {
    $$ = new Node("MultiplicativeExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("*","Separator"));
    $$->children.push_back($3);
    }
    | MultiplicativeExpression o_divide UnaryExpression
    {
    $$ = new Node("MultiplicativeExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("/","Separator"));
    $$->children.push_back($3);
    }
    | MultiplicativeExpression o_modulo UnaryExpression
    {
    $$ = new Node("MultiplicativeExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("%","Separator"));
    $$->children.push_back($3);
    }
    ;

AdditiveExpression:
    MultiplicativeExpression
    {
    $$ = $1;
    }
    | AdditiveExpression o_add MultiplicativeExpression
    {
    $$ = new Node("AdditiveExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("+","Separator"));
    $$->children.push_back($3);
    }
    | AdditiveExpression o_subtract MultiplicativeExpression
    {
    $$ = new Node("AdditiveExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("-","Separator"));
    $$->children.push_back($3);
    }
    ;

ShiftExpression:   
    AdditiveExpression
    {
    $$ = $1;
    }
    | ShiftExpression o_left_shift AdditiveExpression
    {
    $$ = new Node("ShiftExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("<<","Separator"));
    $$->children.push_back($3);
    }
    | ShiftExpression o_right_shift AdditiveExpression
    {
    $$ = new Node("ShiftExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node(">>","Separator"));
    $$->children.push_back($3);
    }
    | ShiftExpression o_unsigned_right_shift AdditiveExpression
    {
    $$ = new Node("ShiftExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node(">>>","Separator"));
    $$->children.push_back($3);
    }
    ;

RelationalExpression:
    ShiftExpression
    {
    $$ = $1;
    }
    | RelationalExpression o_less_than ShiftExpression
    {
    $$ = new Node("RelationalExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("<","Separator"));
    $$->children.push_back($3);
    }
    | RelationalExpression o_greater_than ShiftExpression
    {
    $$ = new Node("RelationalExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node(">","Separator"));
    $$->children.push_back($3);
    }
    | RelationalExpression o_less_than_or_equal ShiftExpression
    {
    $$ = new Node("RelationalExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("<=","Separator"));
    $$->children.push_back($3);
    }
    | RelationalExpression o_greater_than_or_equal ShiftExpression
    {
    $$ = new Node("RelationalExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node(">=","Separator"));
    $$->children.push_back($3);
    }
    | RelationalExpression k_instanceof ReferenceType
    {
    $$ = new Node("RelationalExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("instanceof","Separator"));
    $$->children.push_back($3);
    }
    ;

EqualityExpression:
    RelationalExpression
    {
    $$ = $1;
    }
    | EqualityExpression o_equals RelationalExpression
    {
    $$ = new Node("EqualityExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("==","Separator"));
    $$->children.push_back($3);
    }
    | EqualityExpression o_not_equals RelationalExpression
    {
    $$ = new Node("EqualityExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("!=","Separator"));
    $$->children.push_back($3);
    }
    ;

AndExpression:  
    EqualityExpression
    {
    $$ = $1;
    }
    | AndExpression o_bitwise_and EqualityExpression
    {
    $$ = new Node("AndExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("&","Separator"));
    $$->children.push_back($3);
    }
    ;

ExclusiveOrExpression:  
    AndExpression
    {
        $$ = $1;
    }
    | ExclusiveOrExpression o_bitwise_xor AndExpression
    {
    $$ = new Node("ExclusiveOrExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("^","Separator"));
    $$->children.push_back($3);
    }
    ;

InclusiveOrExpression:  
    ExclusiveOrExpression
    {
    $$ = $1;
    }
    | InclusiveOrExpression o_bitwise_or ExclusiveOrExpression
    {
    $$ = new Node("InclusiveOrExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("|","Separator"));
    $$->children.push_back($3);
    }
    ;

ConditionalAndExpression:
    InclusiveOrExpression
    {
    $$ = $1;
    }
    | ConditionalAndExpression o_logical_and InclusiveOrExpression
    {
    $$ = new Node("ConditionalAndExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("&&","Separator"));
    $$->children.push_back($3);
    }
    ;

ConditionalOrExpression:
    ConditionalAndExpression
    {
    $$ = $1;
    }
    | ConditionalOrExpression o_logical_or ConditionalAndExpression
    {
    $$ = new Node("ConditionalOrExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("||","Separator"));
    $$->children.push_back($3);
    }
    ;

ConditionalExpression:  
    ConditionalOrExpression
    {
    $$ = $1;
    }
    | ConditionalOrExpression o_question_mark Expression o_colon ConditionalExpression
    {
    $$ = new Node("ConditionalExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("?","Separator"));
    $$->children.push_back($3);
    $$->children.push_back(new Node(":","Separator"));
    $$->children.push_back($5);
    }
    ;

AssignmentExpression:
    ConditionalExpression
    {
    $$ = $1;
    }
    | Assignment
    {
    $$ = $1;
    }
    ;   

Assignment:
    LeftHandSide AssignmentOperator Expression
    {
    $$ = new Node("Assignment");
    $$->children.push_back($1);
    $$->children.push_back($2);
    $$->children.push_back($3);
    }
    ;

LeftHandSide:   
    Name
    {
    $$ = $1;
    }
    | FieldAccess
    {
    $$ = $1;
    }
    | ArrayAccess
    {
    $$ = $1;
    }
    ;

AssignmentOperator:
    o_assign
    {
    $$ = new Node("=","Separator");
    }
    | o_add_assign
    {
    $$ = new Node("+=","Separator");
    }
    | o_subtract_assign
    {
    $$ = new Node("-=","Separator");
    }
    | o_multiply_assign
    {
    $$ = new Node("*=","Separator");
    }
    | o_divide_assign
    {
    $$ = new Node("/=","Separator");
    }
    | o_modulo_assign
    {
    $$ = new Node("%=","Separator");
    }
    | o_left_shift_assign
    {
    $$ = new Node("<<=","Separator");
    }
    | o_right_shift_assign
    {
    $$ = new Node(">>=","Separator");
    }
    | o_unsigned_right_shift_assign
    {
    $$ = new Node(">>>=","Separator");
    }
    | o_bitwise_and_assign
    {
    $$ = new Node("&=","Separator");
    }
    | o_bitwise_or_assign
    {
    $$ = new Node("|=","Separator");
    }
    | o_bitwise_xor_assign
    {
    $$ = new Node("^=","Separator");
    }
    ;

Expression:
    AssignmentExpression
    {
    $$ = $1;
    }
    ;
%%

void traverse(Node* node, int &counter, ofstream &dotfile) {
  node->count = counter++;
  dotfile << "  node" << node->count << " [label=\"" << node->token << "\\n" << node->id << "\"];" << endl;
  for (int i=0;i<node->children.size();i++) {
    int child_id = counter;
    dotfile << "  node" << node->count << " -> node" << child_id << ";" << endl;
    traverse(node->children[i], counter, dotfile);
  }
}

void print_dot(const char* filename) {
  ofstream dotfile(filename);
  dotfile << "digraph PARSE_TREE {" << endl;
  int counter = 0;
  traverse(root, counter, dotfile);
  dotfile << "}" << endl;
  dotfile.close();
}

int main(int argc, char**argv){
    if(argc==1){
        cout<<"No input file specified"<<endl;
        return 0;
    }
    
    int input_index = 0;
    int output_index = 0;
    bool flag_help=false;
    int t = 1;

    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg.find("--output=") == 0) {
            argv[i] = argv[i]+9;
            output_index = i;
            t++;
            continue;
        }
        else if(arg.find("--input=") == 0){
            argv[i] = argv[i]+8;
            input_index = i;
            t++;
            continue;
        }
        else if(arg.find("--help") == 0){
            flag_help = true;
            t++;
            continue;
        }
        else if(arg.find("--verbose")==0){
            flag_verbose=true;
            t++;
            continue;
        }
        if(i == t && !input_index)
            input_index = i;
        if(i == t+1 && !output_index)
            output_index = i;
    }

    if(flag_help){
        cout<<endl<<"Usage: ./myASTGenerator [options] [input_file]}"<<endl;
        cout<<"Generates a Dot file for the AST representation for an input JAVA file"<<endl<<endl;
        cout<<"Debugging : "<<endl;
        cout<<"\t--verbose\tsupports debugging of the input file"<<endl<<endl;
        cout<<"Files : "<<endl;
        cout<<"\t--output=FILE\tspecify output filename"<<endl;
        cout<<"\t--input=FILE\tspecify input filename"<<endl<<endl;
        cout<<"Miscellaneous : "<<endl;
        cout<<"\t--help\t\tproduces this help message"<<endl<<endl;
        cout<<"By default the first argument will be treated as the input file and the second argument as the output file unless specified otherwise.\nIf there is only one argument, then it will be taken as the input file and the default name of the output file will be parse_tree.dot."<<endl<<endl;
        return 0;
    }

    if (argc > 1) {
        if(input_index)
            yyin = fopen(argv[input_index], "r");
        if (!yyin) {
            fprintf(stderr, "error: could not open file %s\n", argv[input_index]);
            return 1;
        }
    }
    else {
        yyin = stdin;
    }

    yyparse();

    if(root){
        if(output_index)
            print_dot(argv[output_index]);
        else 
            print_dot("parse_tree.dot");
    }
    else printf("Error in generating the parse tree\nAborting...\n");
    return 0;
}
