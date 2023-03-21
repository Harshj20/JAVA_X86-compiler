%{
#include <bits/stdc++.h>
#include "Node.h"
#include "SymTable.h"
using namespace std;
extern int yylex();
extern int yylineno;
extern FILE *yyin;
extern map<unsigned long long int, symtab> symTables; 
map<string, unsigned long long int> class_to_symboltable;

vector<string> enum_types = {"BIN", "OCT", "HEX_FLOAT", "HEX", "VOID", "FUNCTION", "CLASS", "INTERFACE", "ENUM", "UNION", "TYPEDEF", "UNKNOWN", "VAR", "_NULL", "BYTE", "SHORT", "CHAR", "INT", "LONG", "FLOAT", "DOUBLE", "STRING", "BOOL", "OBJECT"};

set<TYPE>add_set = {INT, BIN, FLOAT, OCT, HEX_FLOAT, HEX, CHAR, LONG, DOUBLE};

int currentSymTableId = 0;
int symTablescount = 1;
bool isDot = false, islocal=false;
vector<TYPE>vt;  // vector used for types
TYPE t = VOID;
int size = 0;
int fsize = 0;
vector<int>vs;  // vector to store max size of dimensions of array
vector<int>vfs; // vector to store dimensions of function arguments
bool isarr=false;
int ArrayArgumentDepth = 0;
string reftype = "";

bool flag_verbose=false;
void yyerror(const char* s){
    if(flag_verbose){
        printf("Error %s in line %d\n",s,yylineno);
    }
    else{
        printf("Syntax error in line %d\n",yylineno);
    }
}

void initializeSymTable(){
    symtab*a = new symtab(symTablescount, currentSymTableId);
    cout<<"Symbol Table Created with Parent ID "<<currentSymTableId<<" and current ID "<<symTablescount<<endl;
    currentSymTableId = symTablescount;
    symTablescount++;
    symTables[currentSymTableId] = *a;
}

Node* root=NULL;

TYPE widen(TYPE a, TYPE b);
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
AbstractMethodDeclaration StatementNoShortIf EmptyStatement ExpressionStatement BreakStatement ContinueStatement  ForStatementNoShortIf IfThenElseStatementNoShortIf LabeledStatement  ThrowStatement SynchronizedStatement TryStatement  WhileStatementNoShortIf LocalVariableType LabeledStatementNoShortIf ForInit ForUpdate StatementExpressionList Catches CatchClause Finally ClassInstanceCreationExpression ArrayCreationExpression ArgumentList DimExprs DimExpr Dims PostFixExpression PreIncrementExpression PreDecrementExpression CastExpression AssignmentOperator AssignmentExpression LeftHandSide BasicForStatement EnhancedForStatement BasicForStatementNoShortIf EnhancedForStatementNoShortIf EnumConstant key_class

%%
// ------------------ Start -----------------------

Program : 
    {   
        root=new Node("Program");
        root->children.push_back(new Node("EOF","EOF",-1));
    }
    | CompilationUnit
    {
        root=new Node("Program");
        root->children.push_back($1);
        root->children.push_back(new Node("EOF","EOF",-1));
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
                $$ = new Node("boolean","Keyword",yylineno);
                if(!isDot){
                $$->type = BOOL;
                t = BOOL;
                }
             }

NumericType:IntegralType
            {
                $$=$1;
            }
            |FloatingPointType
            {
                $$=$1;
            }

IntegralType: k_byte{
                $$ = new Node("byte","Keyword", INT, yylineno);
                t = INT;
            }
            |k_short{
                $$ = new Node("short","Keyword", INT, yylineno);
                t = INT;
            }
            |k_int {
                $$ = new Node("int","Keyword", INT, yylineno);
                t = INT;
            }
            |k_long {
                $$ = new Node("long","Keyword", LONG, yylineno);
                t = LONG;
            }
            |k_char {
                $$ = new Node("char","Keyword", CHAR, yylineno );
                t = CHAR;
            }

FloatingPointType: k_float {
                        $$ = new Node("float","Keyword", FLOAT, yylineno);
                        t = FLOAT;
                   }
                 | k_double
                   {
                        $$ = new Node("double","Keyword", DOUBLE, yylineno);
                        t = DOUBLE;
                   }

ReferenceType:ClassOrInterfaceType
              {
                $$=$1;
                if(!isDot){
                    $$->type=OBJECT;
                    t = OBJECT;
                    reftype=$1->id;
                }
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
                    $$->type = $1->type;
                    
                    $$->children.push_back($1);
                    $$->children.push_back(new Node("[","Separator", yylineno));
                    $$->children.push_back(new Node("]","Separator", yylineno));
                    $$->size++;
                    isarr = true;
                    ++size;
                    ++fsize;
                }
	| Name s_open_square_bracket s_close_square_bracket
                {
                    $$=new Node("ArrayType"); 
                    
                    if(!isDot){
                        if(!symTables[currentSymTableId].lookup($1->id)){
                            string s1 = "Undeclared type " + $1->id;
                            yyerror(s1.c_str());
                            exit(0);
                        }
                    $$->type = (*symTables[currentSymTableId].getSymEntry($1->id))[0].type;
                    }
                    $$->children.push_back($1);
                    $$->children.push_back(new Node("[","Separator", yylineno));
                    $$->children.push_back(new Node("]","Separator", yylineno));
                    
                    $$->size++;
                    isarr = true;
                    ++size;
                    ++fsize;
                }
	|ArrayType s_open_square_bracket s_close_square_bracket
                {
                    $$=new Node("ArrayType"); 
                    
                    $$->type = $1->type;
                    $$->children.push_back($1);
                    $$->children.push_back(new Node("[","Separator", yylineno));
                    $$->children.push_back(new Node("]","Separator", yylineno));
                    $$->size=$1->size+1;
                    ++size;
                    isarr = true;
                    ++fsize;
                }


// ------------------------------- Production 6 --------------------------

Name:SimpleName
     {
        $$=$1;
        if(!isDot && $1->type==CLASS){
            if(!symTables[$1->symid].grand_lookup($1->id)){
                string s1 = "Undeclared variable " + $1->id;
                yyerror(s1.c_str());
                exit(0);
            }
            $$->symid=class_to_symboltable[$1->id];
            //cout<<class_to_symboltable[$1->id]<<endl;
        }
     }
	| QualifiedName
      {
        $$=$1;
      }

SimpleName: Identifier 
            {   
                string lex($1);
                if(!isDot){
                    int t1=symTables[currentSymTableId].grand_lookup(lex);
                    //cout<<lex<<" "<<currentSymTableId<<endl;
                    // for(auto i = symTables[1].entries.begin(); i!=symTables[1].entries.end(); ++i){
                    //     cout<<i->first<<endl;
                    // }
                    if(!t1){
                        string s1 = "Undeclared variable " + lex;
                        cout<<t1<<endl;
                        cout<<currentSymTableId<<endl;
                        yyerror(s1.c_str());
                        exit(0);
                    }
                    $$ = new Node($1,"Identifier",symTables[t1].entries[lex][0].type,yylineno);
                    $$->symid=t1;
                    //$$->size=symTables[t1].entries[lex][0].size;
                }
                else {
                    $$ = new Node($1,"Identifier",yylineno);
                }
            }

QualifiedName: Name s_dot Identifier 
                {   
                    if(isDot)
                    $$=new Node("QualifiedName"); 
                    else $$=new Node($3,"QualifiedName",yylineno);
                    $$->children.push_back($1);
                    $$->children.push_back(new Node(".","Separator", yylineno));
                    $$->children.push_back(new Node($3,"Identifier",yylineno));
                    if(!isDot){
                        string s($3);

                        if(!symTables[$1->symid].grand_lookup(s)){
                            string s1 = "Undeclared variable " + s;
                            //cout<<$1->symid<<endl;
                            yyerror(s1.c_str());
                            exit(0);
                        }
                        $$->symid=$1->symid;
                    }

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
                        $$->children.push_back(new Node("package","Keyword", yylineno));
                        $$->children.push_back($2);
                        $$->children.push_back(new Node(";","Separator", yylineno));
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
                                $$->children.push_back(new Node("import","Keyword", yylineno));
                                $$->children.push_back($2);
                                $$->children.push_back(new Node(";","Separator", yylineno));
                             }


TypeImportOnDemandDeclaration: k_import Name s_dot o_multiply s_semicolon
                               {
                                $$=new Node("PackageDeclaration"); 
                                $$->children.push_back(new Node("import","Keyword", yylineno));
                                $$->children.push_back($2);
                                $$->children.push_back(new Node(".","Separator", yylineno));
                                $$->children.push_back(new Node("*","Operator", yylineno));
                                $$->children.push_back(new Node(";","Separator", yylineno));
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
                $$ = new Node(";","Separator", yylineno);
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
            $$ = new Node("public","Keyword", yylineno);
          }
        | k_protected 
          {
            $$ = new Node("protected","Keyword", yylineno);
          }
        | k_private
          {
            $$ = new Node("private","Keyword", yylineno);
          }
	    | k_static
          {
            $$ = new Node("static","Keyword", yylineno);
          }
	    | k_abstract 
          {
            $$ = new Node("abstract","Keyword", yylineno);
          }
        | k_final 
          {
            $$ = new Node("final","Keyword", yylineno);
          }
        | k_native 
          {
            $$ = new Node("native","Keyword", yylineno);
          }
        | k_synchronized 
          {
            $$ = new Node("synchronized","Keyword", yylineno);
          }
        | k_transient 
          {
            $$ = new Node("transient","Keyword", yylineno);
          }
        | k_volatile
          {
            $$ = new Node("volatile","Keyword", yylineno);
          }

ClassDeclaration : NormalClassDeclaration 
                   {
                    $$=$1;
                   }
                  |EnumDeclaration
                   {
                    $$=$1;
                   }
key_class : k_class Identifier
           {    
                $$ = new Node("abc","key_class", yylineno);
                $$->children.push_back(new Node("class","Keyword", yylineno));
                $$->children.push_back(new Node($2,"Identifier",yylineno));
                if(!isDot){
                    string s($2);
                    if(symTables[currentSymTableId].entries.find(s) != symTables[currentSymTableId].entries.end()){
                        yyerror("Class already declared");
                        exit(0);
                    }
                    else{
                        symTables[currentSymTableId].insertSymEntry(s, CLASS, yylineno);
                        cout<<currentSymTableId<<endl;
                    } 
                    initializeSymTable();
                    class_to_symboltable[s] = currentSymTableId;
                }
           }

NormalClassDeclaration:
	Modifiers key_class Super Interfaces ClassBody
    {   
        $$=new Node("NormalClassDeclaration"); 
        if(!isDot){
            currentSymTableId = symTables[currentSymTableId].parentID;
        }
        $$->children.push_back($1);
        $$->children.push_back($2->children[0]);
        $$->children.push_back($2->children[1]);
        $$->children.push_back($3);
        $$->children.push_back($4);
        $$->children.push_back($5);
    }
    | Modifiers key_class Super ClassBody
      {   
        $$=new Node("NormalClassDeclaration"); 
        //string s($3);
        // if(!isDot){
        //     class_to_symboltable[$3] = currentSymTableId;
        //     currentSymTableId = symTables[currentSymTableId].parentID;
        //     if(symTables[currentSymTableId].entries.find(s) != symTables[currentSymTableId].entries.end()){
        //         yyerror("Class already declared");
        //         exit(0);
        //     }
        //     else{
        //         symTables[currentSymTableId].insertSymEntry(s, CLASS, $2->lineno);
        //     }   
        // }
        if(!isDot){
            currentSymTableId = symTables[currentSymTableId].parentID;
        }
        $$->children.push_back($1);
        $$->children.push_back($2->children[0]);
        $$->children.push_back($2->children[1]);
        $$->children.push_back($3);
        $$->children.push_back($4);
      }
    | Modifiers key_class Interfaces ClassBody
      {   
        $$=new Node("NormalClassDeclaration"); 
        //string s($3);
        // if(!isDot){
        //     class_to_symboltable[$3] = currentSymTableId;
        //     currentSymTableId = symTables[currentSymTableId].parentID;
        //     if(symTables[currentSymTableId].entries.find(s) != symTables[currentSymTableId].entries.end()){
        //         yyerror("Class already declared");
        //         exit(0);
        //     }
        //     else{                    isarr = true;

        //         symTables[currentSymTableId].insertSymEntry(s, CLASS, $2->lineno);
        //     } 
            
        // }
        if(!isDot){
            currentSymTableId = symTables[currentSymTableId].parentID;
        }
        $$->children.push_back($1);
        $$->children.push_back($2->children[0]);
        $$->children.push_back($2->children[1]);
        $$->children.push_back($3);
        $$->children.push_back($4);
      }
    | Modifiers key_class ClassBody
      {   
        $$=new Node("NormalClassDeclaration"); 
        //string s($3);
        // if(!isDot){
        //     class_to_symboltable[$3] = currentSymTableId;
        //     currentSymTableId = symTables[currentSymTableId].parentID;
        //     if(symTables[currentSymTableId].entries.find(s) != symTables[currentSymTableId].entries.end()){
        //         yyerror("Class already declared");
        //         exit(0);
        //     }
        //     else{
        //         symTables[currentSymTableId].insertSymEntry(s, CLASS, $2->lineno);
        //     } 
        // }
        if(!isDot){
            currentSymTableId = symTables[currentSymTableId].parentID;
        }
        $$->children.push_back($1);
        $$->children.push_back($2->children[0]);
        $$->children.push_back($2->children[1]);
        $$->children.push_back($3);
      }
    | key_class Super Interfaces ClassBody
      {   
        $$=new Node("NormalClassDeclaration"); 
        // if(!isDot){
        //     class_to_symboltable[$2] = currentSymTableId;
        //     currentSymTableId = symTables[currentSymTableId].parentID;
        //         string s($2);
        //     if(symTables[currentSymTableId].entries.find(s) != symTables[currentSymTableId].entries.end()){
        //         yyerror("Class already declared");
        //         exit(0);
        //     }
        //     else{
        //         symTables[currentSymTableId].insertSymEntry(s, CLASS, $1->lineno);
        //     } 
            
        // }
        if(!isDot){
            currentSymTableId = symTables[currentSymTableId].parentID;
        }
        $$->children.push_back($1->children[0]);
        $$->children.push_back($1->children[1]);
        $$->children.push_back($2);
        $$->children.push_back($3);

      }
    | key_class Super ClassBody
        {   
            $$=new Node("NormalClassDeclaration"); 
        //     if(!isDot){
        //         class_to_symboltable[$2] = currentSymTableId;
        //     currentSymTableId = symTables[currentSymTableId].parentID;
        //     string s($2);
        //     if(symTables[currentSymTableId].entries.find(s) != symTables[currentSymTableId].entries.end()){
        //         yyerror("Class already declared");
        //         exit(0);
        //     }
        //     else{
        //         symTables[currentSymTableId].insertSymEntry(s, CLASS, $1->lineno);
        //     } 
        // }
        if(!isDot){
            currentSymTableId = symTables[currentSymTableId].parentID;
        }
            $$->children.push_back($1->children[0]);
            $$->children.push_back($1->children[1]);
            $$->children.push_back($2);
            $$->children.push_back($3);
        }
    | key_class Interfaces ClassBody
        {   
            $$=new Node("NormalClassDeclaration"); 
        //     if(!isDot){
        //         class_to_symboltable[$2] = currentSymTableId;
        //     currentSymTableId = symTables[currentSymTableId].parentID;
        //     string s($2);
        //     if(symTables[currentSymTableId].entries.find(s) != symTables[currentSymTableId].entries.end()){
        //         yyerror("Class already declared");
        //         exit(0);
        //     }
        //     else{
        //         symTables[currentSymTableId].insertSymEntry(s, CLASS, $1->lineno);
        //     } 
        // }
        if(!isDot){
            currentSymTableId = symTables[currentSymTableId].parentID;
        }
            $$->children.push_back($1->children[0]);
            $$->children.push_back($1->children[1]);
            $$->children.push_back($2);
            $$->children.push_back($3);
        }
    | key_class ClassBody 
       {
            $$=new Node("NormalClassDeclaration"); 
        //     if(!isDot){
        //         class_to_symboltable[$2] = currentSymTableId;
        //     currentSymTableId = symTables[currentSymTableId].parentID;
        //     string s($2);
        //     if(symTables[currentSymTableId].entries.find(s) != symTables[currentSymTableId].entries.end()){
        //         yyerror("Class already declared");
        //         exit(0);
        //     }
        //     else{
        //         symTables[currentSymTableId].insertSymEntry(s, CLASS, $1->lineno);
        //     }
        // }
        if(!isDot){
            currentSymTableId = symTables[currentSymTableId].parentID;
        }
            $$->children.push_back($1->children[0]);
            $$->children.push_back($1->children[1]);
            $$->children.push_back($2);
       }

/* S_open_curly_bracket: s_open_curly_bracket { 
                    if(!isDot){
                        initializeSymTable();
                    }
                } */

Super: k_extends ClassType
        {
            $$=new Node("Super");
            $$->children.push_back(new Node("extends","Keyword", yylineno));
            $$->children.push_back($2);
        }

Interfaces: k_implements InterfaceTypeList
            {
                $$=new Node("Interfaces");
                $$->children.push_back(new Node("implements","Keyword", yylineno));
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
                        $$->children.push_back(new Node(",","Separator", yylineno));
                        $$->children.push_back($3);
                    }

ClassBody: s_open_curly_bracket ClassBodyDeclarations s_close_curly_bracket 
{
    $$=new Node("ClassBody");
    
    $$->children.push_back(new Node("{","Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node("}","Separator", yylineno));
}
| s_open_curly_bracket s_close_curly_bracket 
{
    $$=new Node("ClassBody");
    $$->children.push_back(new Node("{","Separator", yylineno));
    $$->children.push_back(new Node("}","Separator", yylineno));
    //currentSymTableId = symTables[currentSymTableId].parentID;
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
                            if(!isDot){
                                currentSymTableId = symTables[currentSymTableId].parentID;
                                symTables[currentSymTableId].insertSymEntry($1->id.c_str(), vt[0], yylineno,fsize,true);
                                for(int i=1;i<vt.size();i++){
                                    symTables[currentSymTableId].insertSymEntry($1->id.c_str(), vt[i], yylineno, vfs[i-1]);
                                }
                                vt.clear();
                                vfs.clear();
                                fsize = 0;
                            }
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
                            $$->children.push_back(new Node(";","Separator", yylineno));
                            // if(!isDot){
                            //     if($2->type != $3->type){
                            //         if($3->type == VAR){
                            //             symTables[currentSymTableId].insertSymEntry($3->id, $2->type, yylineno);
                            //         }
                            //         cout<<"Type Mismatch in Field Declaration"<<endl;
                            //         exit(0);
                            //     }
                            // }
                            t = VOID;
                            size = 0;
                            isarr = false;
                        }
                        | Type VariableDeclaratorList s_semicolon     
                        {
                            $$=new Node("FieldDeclaration");
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                            $$->children.push_back(new Node(";","Separator", yylineno));
                            // if(!isDot){
                            //     if($1->type != $2->type){
                            //         cout<<"Type Mismatch in Field Declaration"<<endl;
                            //         exit(0);
                            //     }
                            // }
                            t = VOID;
                            size = 0;
                            isarr = false;
                        }

VariableDeclaratorList:VariableDeclarator     
                        {
                            $$=$1;
                        }
	                  |VariableDeclaratorList s_comma VariableDeclarator   
                        {
                            $$=new Node("VariableDeclaratorList");
                            $$->children.push_back($1);
                            $$->children.push_back(new Node(",","Separator", yylineno));
                            $$->children.push_back($3);
                            // if(!isDot){
                            //     if($1->type != $3->type){
                            //         cout<<"Type Mismatch in Variable Declarator List"<<endl;
                            //         exit(0);
                            //     }
                            //     $$->type = $1->type;
                            // }
                        }

VariableDeclarator: VariableDeclaratorId     
                        {
                            $$=$1;
                        }
	               |VariableDeclaratorId o_assign VariableInitializer     
                        {
                            if(!isDot){
                                // if(t != $3->type){
                                //     cout<<enum_types[t]<<" "<<enum_types[$3->type]<<endl;
                                //     cout<<"Type Mismatch in Variable Declarator"<<endl;
                                //     exit(0);
                                // }
                                if(widen(t,$3->type)!=t){
                                    yyerror("Type Mismatch in Variable Declarator");
                                    exit(0);
                                }
                                cout<<$1->size<<" "<<$3->size<<endl;
                                if($3->size!=$1->size){
                                    yyerror("Size Mismatch in Variable Declarator");
                                    exit(0);
                                }
                                    vector<struct symEntry> *s = symTables[currentSymTableId].getSymEntry($1->id);
                                    if(!s){
                                        yyerror("Variable not declared");
                                        exit(0);
                                    }
                                    for(int i = 0; i < vs.size(); i++){
                                        (*s)[i+1].size = vs[i];
                                    }
                                    vs.clear();
                                $$=new Node($1->id.c_str(), "VariableDeclarator", yylineno);
                            }
                            else{
                                $$=new Node("VariableDeclarator");
                            }
                            $$->children.push_back($1);
                            $$->children.push_back(new Node("=","Operator", yylineno));
                            $$->children.push_back($3);
                        }

VariableDeclaratorId: Identifier
                      {
                        $$ = new Node($1,"Identifier",yylineno);
                        if(!isDot){
                            string s($1);
                            if(islocal ? symTables[currentSymTableId].lookup(s) : symTables[currentSymTableId].grand_lookup(s)){
                                    cout<<"Variable "<<s<<" already declared in this scope"<<endl;
                                    exit(0);
                            }
                            symTables[currentSymTableId].insertSymEntry(s, t, yylineno);
                            for(int i=0;i<size;i++){
                                symTables[currentSymTableId].insertSymEntry(s, t, yylineno, size);
                            }
                            if(t==OBJECT){
                                vector<struct symEntry> *sentry = symTables[currentSymTableId].getSymEntry(s);
                                (*sentry)[0].symid = class_to_symboltable[reftype];
                            }
                            $$->size=size;
                                //cout<<size<<endl;
                                //cout<<enum_types[t]<<endl;
                        }
                      }
	                 |VariableDeclaratorId s_open_square_bracket s_close_square_bracket     
                        {   
                            if(!isDot){
                                string s($1->id);
                                $$=new Node($1->id.c_str(),"VariableDeclaratorId",yylineno);
                                symTables[currentSymTableId].insertSymEntry(s, t, yylineno);
                                $$->size = $1->size+1;
                                isarr = true;
                            }
                            else 
                            $$=new Node("VariableDeclaratorId");
                            $$->children.push_back($1);
                            $$->children.push_back(new Node("[","Separator", yylineno));
                            $$->children.push_back(new Node("]","Separator", yylineno));
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
                            if(!isDot){
                                currentSymTableId = symTables[currentSymTableId].parentID;
                            }
                        }

MethodHeader:   
	Modifiers Type MethodDeclarator Throws    {   
            if(isDot)
                $$=new Node("MethodHeader"); 
            else
                $$=new Node($3->id.c_str(),"MethodHeader",yylineno);
            $$->children.push_back($1);
            $$->children.push_back($2);
            $$->children.push_back($3);
            $$->children.push_back($4);
            t = $2->type;
        }
    | Modifiers Type MethodDeclarator {   
            if(isDot)
                $$=new Node("MethodHeader"); 
            else
                $$=new Node($3->id.c_str(),"MethodHeader",yylineno);
            $$->children.push_back($1);
            $$->children.push_back($2);
            $$->children.push_back($3);
            t = $2->type;
        }
    |  Type MethodDeclarator Throws {   
            if(isDot)
                $$=new Node("MethodHeader"); 
            else
                $$=new Node($2->id.c_str(),"MethodHeader",yylineno);
            $$->children.push_back($1);
            $$->children.push_back($2);
            $$->children.push_back($3);
            t = $1->type;
        }
    |  Type MethodDeclarator    {   
            if(isDot)
                $$=new Node("MethodHeader"); 
            else
            $$=new Node($2->id.c_str(),"MethodHeader",yylineno); 
            $$->children.push_back($1);
            $$->children.push_back($2);
            t = $1->type;
        }
	| Modifiers k_void MethodDeclarator Throws  {   
            if(isDot)
                $$=new Node("MethodHeader"); 
            else
            $$=new Node($3->id.c_str(),"MethodHeader",yylineno);
            $$->children.push_back($1);
            $$->children.push_back(new Node("void","Keyword", yylineno));
            $$->children.push_back($3);
            $$->children.push_back($4);
            t=VOID;
        }
    | Modifiers k_void MethodDeclarator {   
            if(isDot)
                $$=new Node("MethodHeader"); 
            else
            $$=new Node($3->id.c_str(),"MethodHeader",yylineno); 
            $$->children.push_back($1);
            $$->children.push_back(new Node("void","Keyword", yylineno));
            $$->children.push_back($3);
            t=VOID;
        }
    |  k_void MethodDeclarator Throws {  
            if(isDot)
                $$=new Node("MethodHeader"); 
            else 
            $$=new Node($2->id.c_str(),"MethodHeader",yylineno);
            $$->children.push_back(new Node("void","Keyword", yylineno));
            $$->children.push_back($2);
            $$->children.push_back($3);
            t=VOID;
        }
    |  k_void MethodDeclarator {   
            if(isDot)
                $$=new Node("MethodHeader"); 
            else
            $$=new Node($2->id.c_str(),"MethodHeader",yylineno);
            $$->children.push_back(new Node("void","Keyword", yylineno));
            $$->children.push_back($2);
            t=VOID;
        }
S_open_paren : s_open_paren {
        if(!isDot){
            vt.push_back(t);
            initializeSymTable();
            symTables[currentSymTableId].isfunction = true;
            islocal = true;
            size=0;
            isarr = 0;
        }
}
MethodDeclarator: 
	Identifier S_open_paren FormalParameterList s_close_paren {   
            if(isDot)
                $$=new Node("MethodDeclarator"); 
            else
                $$=new Node($1,"MethodDeclarator",yylineno); 
            $$->children.push_back(new Node($1,"Identifier",yylineno));
            $$->children.push_back(new Node("(","Separator", yylineno));
            $$->children.push_back($3);
            $$->children.push_back(new Node(")","Separator", yylineno));
            if(!isDot){
                //currentSymTableId = symTables[currentSymTableId].parentID;
                symTables[currentSymTableId].insertSymEntry($1, vt[0], yylineno, fsize,true);
                symTables[symTables[currentSymTableId].parentID].insertSymEntry($1, vt[0], yylineno,fsize,true);
                for(int i=1;i<vt.size();i++){
                    symTables[currentSymTableId].insertSymEntry($1, vt[i], yylineno, vfs[i-1]);
                    symTables[symTables[currentSymTableId].parentID].insertSymEntry($1, vt[i], yylineno, vfs[i-1]);
                    //cout<<"abs"<<vfs[i-1]<<endl;
                }
                vt.clear();
                vfs.clear();
                fsize = 0;
                islocal = false;
            }
        }
    | Identifier S_open_paren s_close_paren {  
            if(isDot)
                $$=new Node("MethodDeclarator"); 
            else 
                $$=new Node($1,"MethodDeclarator",yylineno); 
            $$->children.push_back(new Node($1,"Identifier",yylineno));
            $$->children.push_back(new Node("(","Separator", yylineno));
            $$->children.push_back(new Node(")","Separator", yylineno));
            if(!isDot){
                //currentSymTableId = symTables[currentSymTableId].parentID;
                symTables[currentSymTableId].insertSymEntry($1, vt[0], yylineno, fsize);
                symTables[symTables[currentSymTableId].parentID].insertSymEntry($1, vt[0], yylineno, fsize);
                for(int i=1;i<vt.size();i++){
                    symTables[currentSymTableId].insertSymEntry($1, vt[i], yylineno, vfs[i-1]);
                    symTables[symTables[currentSymTableId].parentID].insertSymEntry($1, vt[i], yylineno, vfs[i-1]);
                }
                vt.clear();
                vfs.clear();
                fsize = 0;
                islocal = false;
            }
        }
	| MethodDeclarator s_open_square_bracket s_close_square_bracket {  
            if(isDot)
                $$=new Node("MethodDeclarator"); 
            else 
                $$=new Node($1->id.c_str(),"MethodDeclarator",yylineno); 
            $$->children.push_back($1);
            $$->children.push_back(new Node("[","Separator", yylineno));
            $$->children.push_back(new Node("]","Separator", yylineno));
            if(!isDot){
                //currentSymTableId = symTables[currentSymTableId].parentID;
                symTables[currentSymTableId].insertSymEntry($1->id, vt[0], yylineno, fsize);
                symTables[symTables[currentSymTableId].parentID].insertSymEntry($1->id, vt[0], yylineno, fsize);
                for(int i=1;i<vt.size();i++){
                    symTables[currentSymTableId].insertSymEntry($1->id, vt[i], yylineno, vfs[i-1]);
                    symTables[symTables[currentSymTableId].parentID].insertSymEntry($1->id, vt[i], yylineno, vfs[i-1]);
                }
            }
        }

FormalParameterList: FormalParameter    
                        {
                            $$=$1;
                        }
	                |FormalParameterList s_comma FormalParameter   
                        {
                            $$=new Node("FormalParameterList");
                            $$->children.push_back($1);
                            $$->children.push_back(new Node(",","Separator", yylineno));
                            $$->children.push_back($3);
                        }

FormalParameter: Type VariableDeclaratorId   
                        {
                            $$=new Node("FormalParameter");
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                            //cout<<"size is "<<size<<endl;
                            vt.push_back(t);
                            t=VOID;
                            vfs.push_back(size);
                           // cout<<size<<endl;
                            fsize -= size;
                            size = 0;
                            isarr = false;
                        }
                | k_final Type VariableDeclaratorId     
                        {
                            $$=new Node("FormalParameter");
                            $$->children.push_back(new Node("final","Keyword", yylineno));
                            $$->children.push_back($2);
                            $$->children.push_back($3);
                            vt.push_back(t);
                            vfs.push_back(size);
                            cout<<size<<endl;
                            fsize -= size;
                            size = 0;
                            isarr = false;
                            t=VOID;
                        }

Throws: k_throws ClassTypeList  
                        {
                            $$=new Node("Throws");
                            $$->children.push_back(new Node("throws","Keyword", yylineno));
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
                            $$->children.push_back(new Node(",","Separator", yylineno));
                            $$->children.push_back($3);
                        }

MethodBody: Block  
                {
                    $$=$1;
                }
        
	| s_semicolon
    {
        $$ = new Node(";","Separator", yylineno);
    }

StaticInitializer: k_static Block 
                        {
                            $$=new Node("StaticInitializer");
                            $$->children.push_back(new Node("static","Keyword", yylineno));
                            $$->children.push_back($2);
                        }
	;

ConstructorDeclaration:

	Modifiers ConstructorDeclarator Throws ConstructorBody {  
            if(isDot)
                $$=new Node("ConstructorDeclaration"); 
            else{
                $$=new Node($2->id.c_str(),"ConstructorDeclaration", yylineno);
            }
            $$->children.push_back($1);
            $$->children.push_back($2);
            $$->children.push_back($3);
            $$->children.push_back($4);
            }
	| Modifiers ConstructorDeclarator ConstructorBody {  
            if(isDot)
                $$=new Node("ConstructorDeclaration"); 
            else
                $$=new Node($2->id.c_str(),"ConstructorDeclaration", yylineno);
            $$->children.push_back($1);
            $$->children.push_back($2);
            $$->children.push_back($3);
            }
	| ConstructorDeclarator Throws ConstructorBody {  
            if(isDot)
                $$=new Node("ConstructorDeclaration"); 
            else
                $$=new Node($1->id.c_str(),"ConstructorDeclaration", yylineno);
            $$->children.push_back($1);
            $$->children.push_back($2);
            $$->children.push_back($3);
            }
	| ConstructorDeclarator ConstructorBody {  
            if(isDot)
                $$=new Node("ConstructorDeclaration"); 
            else
                $$=new Node($1->id.c_str(),"ConstructorDeclaration", yylineno);
            $$->children.push_back($1);
            $$->children.push_back($2);
            }
	;

ConstructorDeclarator:
	SimpleName S_open_paren FormalParameterList s_close_paren   
            {  
            if(isDot)
            $$=new Node("ConstructorDeclarator"); 
            else
            $$=new Node($1->id.c_str(),"ConstructorDeclarator", yylineno);
            $$->children.push_back($1);
            $$->children.push_back(new Node("(","Separator", yylineno));
            $$->children.push_back($3);
            $$->children.push_back(new Node(")","Separator", yylineno));
            if(!isDot){
                //currentSymTableId = symTables[currentSymTableId].parentID;
                symTables[currentSymTableId].insertSymEntry($1->id, vt[0], yylineno, fsize,true);
                for(int i=1;i<vt.size();i++){
                    symTables[currentSymTableId].insertSymEntry($1->id, vt[i], yylineno, vfs[i-1]);
                    //cout<<"abs"<<vfs[i-1]<<endl;
                }
                islocal=false;
            }
            }
	|SimpleName S_open_paren s_close_paren {  
            if(isDot)
                $$=new Node("ConstructorDeclarator"); 
            else
                $$=new Node($1->id.c_str(), "ConstructorDeclarator", yylineno);  

            $$->children.push_back($1);
            $$->children.push_back(new Node("(","Separator", yylineno));
            $$->children.push_back(new Node(")","Separator", yylineno));
            if(!isDot){
                //currentSymTableId = symTables[currentSymTableId].parentID;
                symTables[currentSymTableId].insertSymEntry($1->id, vt[0], yylineno, fsize,true);
                for(int i=1;i<vt.size();i++){
                    symTables[currentSymTableId].insertSymEntry($1->id, vt[i], yylineno, vfs[i-1]);
                    //cout<<"abs"<<vfs[i-1]<<endl;
                }
                islocal=false;
            }
        }
	;

ConstructorBody:
	s_open_curly_bracket s_close_curly_bracket {  
            $$=new Node("ConstructorBody"); 
            $$->children.push_back(new Node("{","Separator", yylineno));
            $$->children.push_back(new Node("}","Separator", yylineno));
            }
	| s_open_curly_bracket BlockStatements s_close_curly_bracket {  
            $$=new Node("ConstructorBody"); 
            
            $$->children.push_back(new Node("{","Separator", yylineno));
            $$->children.push_back($2);
            $$->children.push_back(new Node("}","Separator", yylineno));
            }
	| s_open_curly_bracket ExplicitConstructorInvocation s_close_curly_bracket {  
            $$=new Node("ConstructorBody"); 
            $$->children.push_back(new Node("{","Separator", yylineno));
            $$->children.push_back($2);
            $$->children.push_back(new Node("}","Separator", yylineno));
            }
	| s_open_curly_bracket ExplicitConstructorInvocation BlockStatements s_close_curly_bracket {  
            $$=new Node("ConstructorBody"); 
            
            $$->children.push_back(new Node("{","Separator", yylineno));
            $$->children.push_back($2);
            $$->children.push_back($3);
            $$->children.push_back(new Node("}","Separator", yylineno));
            }
	;
ExplicitConstructorInvocation:
	k_this s_open_paren ArgumentList s_close_paren s_semicolon {  
            $$=new Node("ExplicitConstructorInvocation"); 
            $$->children.push_back(new Node("this","Keyword", yylineno));
            $$->children.push_back(new Node("(","Separator", yylineno));
            $$->children.push_back($3);
            $$->children.push_back(new Node(")","Separator", yylineno));
            $$->children.push_back(new Node(";","Separator", yylineno));
            }
	| k_this s_open_paren s_close_paren s_semicolon {  
            $$=new Node("ExplicitConstructorInvocation"); 
            $$->children.push_back(new Node("this","Keyword", yylineno));
            $$->children.push_back(new Node("(","Separator", yylineno));
            $$->children.push_back(new Node(")","Separator", yylineno));
            $$->children.push_back(new Node(";","Separator", yylineno));
            }
	| k_super s_open_paren ArgumentList s_close_paren s_semicolon {  
            $$=new Node("ExplicitConstructorInvocation"); 
            $$->children.push_back(new Node("super","Keyword", yylineno));
            $$->children.push_back(new Node("(","Separator", yylineno));
            $$->children.push_back($3);
            $$->children.push_back(new Node(")","Separator", yylineno));
            $$->children.push_back(new Node(";","Separator", yylineno));}
	| k_super s_open_paren s_close_paren s_semicolon {  
            $$=new Node("ExplicitConstructorInvocation"); 
            $$->children.push_back(new Node("super","Keyword", yylineno));
            $$->children.push_back(new Node("(","Separator", yylineno));
            $$->children.push_back(new Node(")","Separator", yylineno));
            $$->children.push_back(new Node(";","Separator", yylineno));
            }
	;

EnumDeclaration : Modifiers k_enum Identifier ClassImplements EnumBody {  
                    $$=new Node("EnumDeclaration"); 
                    $$->children.push_back($1);
                    $$->children.push_back(new Node("enum","Keyword", yylineno));
                    $$->children.push_back(new Node($3,"Identifier",yylineno));
                    $$->children.push_back($4);
                    $$->children.push_back($5);
                    }
                 |Modifiers k_enum Identifier EnumBody {  
                    $$=new Node("EnumDeclaration"); 
                    $$->children.push_back($1);
                    $$->children.push_back(new Node("enum","Keyword", yylineno));
                    $$->children.push_back(new Node($3,"Identifier",yylineno));
                    $$->children.push_back($4);
                    }
                 |k_enum Identifier ClassImplements EnumBody {  
                    $$=new Node("EnumDeclaration"); 
                    $$->children.push_back(new Node("enum","Keyword", yylineno));
                    $$->children.push_back(new Node($2,"Identifier",yylineno));
                    $$->children.push_back($3);
                    $$->children.push_back($4);
                    }
                 |k_enum Identifier EnumBody {  
                    $$=new Node("EnumDeclaration"); 
                    $$->children.push_back(new Node("enum","Keyword", yylineno));
                    $$->children.push_back(new Node($2,"Identifier",yylineno));
                    $$->children.push_back($3);
                    }

ClassImplements : k_implements InterfaceTypeList {  
                    $$=new Node("ClassImplements"); 
                    $$->children.push_back(new Node("implements","Keyword", yylineno));
                    $$->children.push_back($2);
                    }

EnumBody : s_open_curly_bracket EnumConstantList s_comma EnumBodyDeclarations s_close_curly_bracket {  
                    $$=new Node("EnumBody"); 
                    
                    $$->children.push_back(new Node("{","Separator", yylineno));
                    $$->children.push_back($2);
                    $$->children.push_back(new Node(",","Separator", yylineno));
                    $$->children.push_back($4);
                    $$->children.push_back(new Node("}","Separator", yylineno));
                    }
          |s_open_curly_bracket EnumConstantList s_comma s_close_curly_bracket  {  
                    $$=new Node("EnumBody"); 
                    
                    $$->children.push_back(new Node("{","Separator", yylineno));
                    $$->children.push_back($2);
                    $$->children.push_back(new Node("}","Separator", yylineno));
                    }
          |s_open_curly_bracket EnumConstantList EnumBodyDeclarations s_close_curly_bracket {  
                    $$=new Node("EnumBody");
                     
                    $$->children.push_back(new Node("{","Separator", yylineno));
                    $$->children.push_back($2);
                    $$->children.push_back($3);
                    $$->children.push_back(new Node("}","Separator", yylineno));
                    }
          |s_open_curly_bracket EnumConstantList s_close_curly_bracket {  
                    $$=new Node("EnumBody");
                     
                    $$->children.push_back(new Node("{","Separator", yylineno));
                    $$->children.push_back($2);
                    $$->children.push_back(new Node("}","Separator", yylineno));
                    }
          |s_open_curly_bracket s_comma EnumBodyDeclarations s_close_curly_bracket {  
                    $$=new Node("EnumBody");
                     
                    $$->children.push_back(new Node("{","Separator", yylineno));
                    $$->children.push_back(new Node(",","Separator", yylineno));
                    $$->children.push_back($3);
                    $$->children.push_back(new Node("}","Separator", yylineno));
                    }
          |s_open_curly_bracket s_comma s_close_curly_bracket {  
                    $$=new Node("EnumBody");
                     
                    $$->children.push_back(new Node("{","Separator", yylineno));
                    $$->children.push_back(new Node(",","Separator", yylineno));
                    $$->children.push_back(new Node("}","Separator", yylineno));
                    }
          |s_open_curly_bracket EnumBodyDeclarations s_close_curly_bracket {  
                    $$=new Node("EnumBody");
                     
                    $$->children.push_back(new Node("{","Separator", yylineno));
                    $$->children.push_back($2);
                    $$->children.push_back(new Node("}","Separator", yylineno));
                    }
          |s_open_curly_bracket s_close_curly_bracket {  
                    $$=new Node("EnumBody");
                     
                    $$->children.push_back(new Node("{","Separator", yylineno));
                    $$->children.push_back(new Node("}","Separator", yylineno));
                    }

EnumBodyDeclarations : s_semicolon  {  
                    $$=new Node(";","Separator", yylineno);
                    }
                    | s_semicolon ClassBodyDeclarations {  
                    $$=new Node("EnumBodyDeclarations"); 
                    $$->children.push_back(new Node(";","Separator", yylineno));
                    $$->children.push_back($2);
                    }

EnumConstantList : EnumConstant {$$=$1;}
                  | EnumConstantList s_comma EnumConstant 
                    {
                    $$=new Node("EnumConstantList");
                    $$->children.push_back($1);
                    $$->children.push_back(new Node(",","Separator", yylineno));
                    $$->children.push_back($3);
                    }

EnumConstant : Identifier s_open_paren ArgumentList s_close_paren ClassBody {  
                    $$=new Node("EnumConstant"); 
                    $$->children.push_back(new Node($1,"Identifier",yylineno));
                    $$->children.push_back(new Node("(","Separator", yylineno));
                    $$->children.push_back($3);
                    $$->children.push_back(new Node(")","Separator", yylineno));
                    $$->children.push_back($5);
                    }
                  |Identifier s_open_paren s_close_paren ClassBody {  
                    $$=new Node("EnumConstant"); 
                    $$->children.push_back(new Node($1,"Identifier",yylineno));
                    $$->children.push_back(new Node("(","Separator", yylineno));
                    $$->children.push_back(new Node(")","Separator", yylineno));
                    $$->children.push_back($4);
                    }
                  |Identifier s_open_paren ArgumentList s_close_paren {  
                    $$=new Node("EnumConstant"); 
                    $$->children.push_back(new Node($1,"Identifier",yylineno));
                    $$->children.push_back(new Node("(","Separator", yylineno));
                    $$->children.push_back($3);
                    $$->children.push_back(new Node(")","Separator", yylineno));
                    }
                  |Identifier s_open_paren s_close_paren {  
                    $$=new Node("EnumConstant"); 
                    $$->children.push_back(new Node($1,"Identifier",yylineno));
                    $$->children.push_back(new Node("(","Separator", yylineno));
                    $$->children.push_back(new Node(")","Separator", yylineno));
                    }
                  |Identifier ClassBody {  
                    $$=new Node("EnumConstant"); 
                    $$->children.push_back(new Node($1,"Identifier",yylineno));
                    $$->children.push_back($2);
                    }
                  |Identifier {  
                    $$=new Node($1,"Identifier",yylineno);
                    }
// ---------------------------- Production 9 -----------------------

InterfaceDeclaration:
	Modifiers k_interface Identifier ExtendsInterfaces InterfaceBody
    { $$=new Node("InterfaceDeclaration"); 
      $$->children.push_back($1);
      $$->children.push_back(new Node("interface","Keyword", yylineno));
      $$->children.push_back(new Node($3,"Identifier",yylineno));
      $$->children.push_back($4);
      $$->children.push_back($5);}
	| Modifiers k_interface Identifier InterfaceBody
    { $$=new Node("InterfaceDeclaration"); 
      $$->children.push_back($1);
      $$->children.push_back(new Node("interface","Keyword", yylineno));
      $$->children.push_back(new Node($3,"Identifier",yylineno));
      $$->children.push_back($4);}
	| k_interface Identifier ExtendsInterfaces InterfaceBody
    {
        $$=new Node("InterfaceDeclaration"); 
        $$->children.push_back(new Node("interface","Keyword", yylineno));
        $$->children.push_back(new Node($2,"Identifier",yylineno));
        $$->children.push_back($3);
        $$->children.push_back($4);
    }
	| k_interface Identifier InterfaceBody
    {
        $$=new Node("InterfaceDeclaration"); 
        $$->children.push_back(new Node("interface","Keyword", yylineno));
        $$->children.push_back(new Node($2,"Identifier",yylineno));
        $$->children.push_back($3);
    }
	;

ExtendsInterfaces:
	k_extends InterfaceType
    {
        $$=new Node("ExtendsInterfaces");
        $$->children.push_back(new Node("extends","Keyword", yylineno));
        $$->children.push_back($2);
    }
	| ExtendsInterfaces s_comma InterfaceType
    {
        $$=new Node("ExtendsInterfaces");
        $$->children.push_back($1);
        $$->children.push_back(new Node("comma","Separator", yylineno));
        $$->children.push_back($3);
    }
	;

InterfaceBody:
	s_open_curly_bracket InterfaceMemberDeclarations s_close_curly_bracket
    {
        $$=new Node("InterfaceBody");
        
        $$->children.push_back(new Node("{","Separator", yylineno));
        $$->children.push_back($2);
        $$->children.push_back(new Node("}","Separator", yylineno));
    }
	|s_open_curly_bracket s_close_curly_bracket
    {
        $$=new Node("InterfaceBody");
        $$->children.push_back(new Node("{","Separator", yylineno));
        $$->children.push_back(new Node("}","Separator", yylineno));
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
    $$->children.push_back(new Node(";","Separator", yylineno));
    if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        symTables[currentSymTableId].insertSymEntry($1->id.c_str(), vt[0], yylineno,fsize,true);
        for(int i=1;i<vt.size();i++){
            symTables[currentSymTableId].insertSymEntry($1->id.c_str(), vt[i], yylineno, vfs[i-1]);
        }
        vt.clear();
        vfs.clear();
        fsize = 0;
    }
}
	;


// ------------------------------- Production 10 ---------------------

ArrayInitializer:
	/*s_open_curly_bracket VariableInitializerList s_comma s_close_curly_bracket
    {
        $$=new Node("ArrayInitializer");
        $$->children.push_back(new Node("{","Separator", yylineno));
        $$->children.push_back($2);
        $$->children.push_back(new Node(",","Separator", yylineno));
        $$->children.push_back(new Node("}","Separator", yylineno));
    }
	|*/ array_s_open_curly_bracket VariableInitializerList  s_close_curly_bracket
    {
        $$=new Node("ArrayInitializer");
        
        $$->children.push_back(new Node("{","Separator", yylineno));
        $$->children.push_back($2);
        $$->children.push_back(new Node("}","Separator", yylineno));
        if(!isDot){
            if(vs[ArrayArgumentDepth-1] && (vs[ArrayArgumentDepth-1] != $2->size)){
                yyerror("Error in number of arguments for array");
                exit(0);
            }
            vs[ArrayArgumentDepth-1] = $2->size;
            ArrayArgumentDepth--;
        }   
    }
	/*| s_open_curly_bracket  s_comma s_close_curly_bracket
    {
        $$=new Node("ArrayInitializer");
        $$->children.push_back(new Node("{","Separator", yylineno));
        $$->children.push_back(new Node(",","Separator", yylineno));
        $$->children.push_back(new Node("}","Separator", yylineno));
    }
	*/| array_s_open_curly_bracket  s_close_curly_bracket
    {
        $$=new Node("ArrayInitializer");
        
        $$->children.push_back(new Node("{","Separator", yylineno));
        $$->children.push_back(new Node("{","Separator", yylineno));
        $$->children.push_back(new Node("}","Separator", yylineno));
        if(!isDot){
            if(vs[ArrayArgumentDepth-1]){
                yyerror("Error in number of arguments for array");
                exit(0);
            }
            vs[ArrayArgumentDepth-1] = 0;
            ArrayArgumentDepth--;
        }
    }
	;
array_s_open_curly_bracket : s_open_curly_bracket{
    if(!isDot){
        ArrayArgumentDepth++;
        if(ArrayArgumentDepth > size){
            yyerror("Excess Dimensions used");
            exit(0);
        }
        if(ArrayArgumentDepth > vs.size())
            vs.push_back(0);
    }
}
VariableInitializerList: VariableInitializer
{
    $$ = $1;
    $$->size = 1;
    if(!isDot && widen($1->type, t) != t ){
        yyerror("Type mismatch in VariableIntializer");
        exit(0);
    }
}
	| VariableInitializerList s_comma VariableInitializer
    {
        $$=new Node("VariableInitializerList");
        $$->children.push_back($1);
        $$->children.push_back(new Node(",","Separator", yylineno));
        $$->children.push_back($3);
        $$->size = $1->size + 1;
        if(!isDot && widen($3->type, t) != t ){
        yyerror("Type mismatch in VariableIntializer");
        exit(0);
        }
    }
	;


// ------------------------ Production 14 -------------------------------------

Block : s_open_curly_bracket s_close_curly_bracket 
    {
        $$=new Node("Block");
        $$->children.push_back(new Node("{","Separator", yylineno));
        $$->children.push_back(new Node("}","Separator", yylineno));
    }
    | s_open_curly_bracket BlockStatements s_close_curly_bracket
    {
        $$=new Node("Block");
        $$->children.push_back(new Node("{","Separator", yylineno));
        $$->children.push_back($2);
        $$->children.push_back(new Node("}","Separator", yylineno));
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
        $$->children.push_back(new Node(";", "Separator", yylineno));
        isarr=false;
        size=0;
        islocal=false;
    }
    ;

LocalVariableDeclaration : 
    k_final LocalVariableType VariableDeclaratorList
    {
        $$=new Node("LocalVariableDeclaration");
        $$->children.push_back(new Node("final","Keyword", yylineno));
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
        if(!isDot){
            islocal=true;
        }
    }
    | k_var
    {
        $$ = new Node("var", "Keyword", VAR);
        if(!isDot){
            islocal=true;
        }
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
    {$$ = new Node(";", "Separator", yylineno);}
	;

LabeledStatement:

	Identifier o_colon Statement
    {
        $$ = new Node("LabeledStatement");
        $$->children.push_back(new Node($1, "Identifier",yylineno));
        $$->children.push_back(new Node(":", "Operator", yylineno));
        $$->children.push_back($3);
    }
	;

LabeledStatementNoShortIf:

	Identifier o_colon StatementNoShortIf
    {
        $$ = new Node("LabeledStatementNoShortIf");
        $$->children.push_back(new Node($1, "Identifier",yylineno));
        $$->children.push_back(new Node(":", "Operator", yylineno));
        $$->children.push_back($3);
    }

ExpressionStatement:

	StatementExpression s_semicolon
    {
        $$ = new Node("ExpressionStatement");
        $$->children.push_back($1);
        $$->children.push_back(new Node(";", "Separator", yylineno));
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
    k_if invoke_paren Expression s_close_paren Statement 
    {
        $$ = new Node("IfThenStatement");
        
        $$->children.push_back(new Node("if", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back($3);
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($5);
        if(!isDot){
            currentSymTableId=symTables[currentSymTableId].parentID;  
        }
    }
    ;


IfThenElseStatement : 
    k_if invoke_paren Expression s_close_paren StatementNoShortIf k_else Statement 
    {
        $$ = new Node("IfThenElseStatement");
        
        $$->children.push_back(new Node("if", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back($3);
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($5);
        $$->children.push_back(new Node("else", "Keyword", yylineno));
        $$->children.push_back($7);
    }
    ;

IfThenElseStatementNoShortIf : 
    k_if invoke_paren Expression s_close_paren StatementNoShortIf k_else StatementNoShortIf 
    {
        $$ = new Node("IfThenElseStatementNoShortIf");
        
        $$->children.push_back(new Node("if", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back($3);
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($5);
        $$->children.push_back(new Node("else", "Keyword", yylineno));
        $$->children.push_back($7);
    }
    ;

invoke_paren : s_open_paren {
    if(!isDot)
    initializeSymTable();
}

WhileStatement : 
    k_while invoke_paren Expression s_close_paren Statement 
    {
        $$ = new Node("WhileStatement");
        
        $$->children.push_back(new Node("while", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back($3);
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($5);
        if(!isDot)
        currentSymTableId = symTables[currentSymTableId].parentID;
    }
    ;

WhileStatementNoShortIf : 
    k_while invoke_paren Expression s_close_paren StatementNoShortIf 
    {
        $$ = new Node("WhileStatementNoShortIf");
        
        $$->children.push_back(new Node("while", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back($3);
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($5);
        if(!isDot)
        currentSymTableId = symTables[currentSymTableId].parentID;
    }
    ;


ForStatement : BasicForStatement {$$=$1;}| EnhancedForStatement {$$=$1;}
ForStatementNoShortIf : BasicForStatementNoShortIf {$$=$1;}| EnhancedForStatementNoShortIf {$$=$1;}

BasicForStatement:
	k_for invoke_paren s_semicolon s_semicolon s_close_paren Statement 
    {
        $$ = new Node("BasicForStatement");
        
        $$->children.push_back(new Node("for", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($6);
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
    | k_for invoke_paren s_semicolon s_semicolon ForUpdate s_close_paren Statement 
    {
        $$ = new Node("BasicForStatement");
        
        $$->children.push_back(new Node("for", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back($5);
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($7);
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
    | k_for invoke_paren s_semicolon Expression s_semicolon s_close_paren Statement 
    {
        $$ = new Node("BasicForStatement");
        
        $$->children.push_back(new Node("for", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back($4);
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($7);
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
    | k_for invoke_paren s_semicolon Expression s_semicolon ForUpdate s_close_paren Statement 
    {
        $$ = new Node("BasicForStatement");
        
        $$->children.push_back(new Node("for", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back($4);
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back($6);
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($8);
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
    | k_for invoke_paren ForInit s_semicolon s_semicolon s_close_paren Statement 
    {
        $$ = new Node("BasicForStatement");
        
        $$->children.push_back(new Node("for", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back($3);
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($7);
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
    | k_for invoke_paren ForInit s_semicolon s_semicolon ForUpdate s_close_paren Statement 
    {
        $$ = new Node("BasicForStatement");
        
        $$->children.push_back(new Node("for", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back($3);
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back($6);
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($8);
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
    | k_for invoke_paren ForInit s_semicolon Expression s_semicolon s_close_paren Statement 
    {
        $$ = new Node("BasicForStatement");
        
        $$->children.push_back(new Node("for", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back($3);
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back($5);
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($8);
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
    | k_for invoke_paren ForInit s_semicolon Expression s_semicolon ForUpdate s_close_paren Statement 
    {
        $$ = new Node("BasicForStatement");
        
        $$->children.push_back(new Node("for", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back($3);
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back($5);
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back($7);
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($9);
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
    ;


BasicForStatementNoShortIf:
	k_for invoke_paren s_semicolon s_semicolon s_close_paren StatementNoShortIf
     {
        $$ = new Node("BasicForStatementNoShortIf");
        
        $$->children.push_back(new Node("for", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($6);
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
     }
    | k_for invoke_paren s_semicolon s_semicolon ForUpdate s_close_paren StatementNoShortIf
    {
        $$ = new Node("BasicForStatementNoShortIf");
        
        $$->children.push_back(new Node("for", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back($5);
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($7);
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
    | k_for invoke_paren s_semicolon Expression s_semicolon s_close_paren StatementNoShortIf
    {
        $$ = new Node("BasicForStatementNoShortIf");
        
        $$->children.push_back(new Node("for", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back($4);
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($7);
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
    | k_for invoke_paren s_semicolon Expression s_semicolon ForUpdate s_close_paren StatementNoShortIf
    {
        $$ = new Node("BasicForStatementNoShortIf");
        
        $$->children.push_back(new Node("for", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back($4);
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back($6);
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($8);
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
    | k_for invoke_paren ForInit s_semicolon s_semicolon s_close_paren StatementNoShortIf
    {
        $$ = new Node("BasicForStatementNoShortIf");
        
        $$->children.push_back(new Node("for", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back($3);
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($7);
        if(!isDot){
            currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
    | k_for invoke_paren ForInit s_semicolon s_semicolon ForUpdate s_close_paren StatementNoShortIf
    {
        $$ = new Node("BasicForStatementNoShortIf");
        
        $$->children.push_back(new Node("for", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back($3);
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back($6);
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($8);
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
    | k_for invoke_paren ForInit s_semicolon Expression s_semicolon s_close_paren StatementNoShortIf
    {
        $$ = new Node("BasicForStatementNoShortIf");
        
        $$->children.push_back(new Node("for", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back($3);
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back($5);
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($8);
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
    | k_for invoke_paren ForInit s_semicolon Expression s_semicolon ForUpdate s_close_paren StatementNoShortIf
    {
        $$ = new Node("BasicForStatementNoShortIf");
        
        $$->children.push_back(new Node("for", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back($3);
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back($5);
        $$->children.push_back(new Node(";", "Separator", yylineno));
        $$->children.push_back($7);
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($9);
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
    ;

EnhancedForStatementNoShortIf: k_for invoke_paren LocalVariableDeclaration o_colon Expression s_close_paren StatementNoShortIf 
{
    $$ = new Node("EnhancedForStatementNoShortIf");
    
    $$->children.push_back(new Node("for", "Keyword", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node(":", "Separator", yylineno));
    $$->children.push_back($5);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($7);
    if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
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

EnhancedForStatement: k_for invoke_paren LocalVariableDeclaration o_colon Expression s_close_paren Statement 
{
    $$ = new Node("EnhancedForStatement");
    
    $$->children.push_back(new Node("for", "Keyword", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node(":", "Separator", yylineno));
    $$->children.push_back($5);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($7);
}

StatementExpressionList:StatementExpression {$$ = $1;}
                       |StatementExpressionList s_comma StatementExpression
                       {
                            $$ = new Node("StatementExpressionList");
                            $$->children.push_back($1);
                            $$->children.push_back(new Node(",", "Separator", yylineno));
                            $$->children.push_back($3);
                       }

BreakStatement: k_break s_semicolon 
{ 
    $$ = new Node("BreakStatement");
    $$->children.push_back(new Node("break", "Keyword", yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));}
 | k_break Identifier s_semicolon
 {
    $$ = new Node("BreakStatement");
    $$->children.push_back(new Node("break", "Keyword", yylineno));
    $$->children.push_back(new Node($3, "Identifier",yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));}

ContinueStatement: k_continue s_semicolon
    {
        $$ = new Node("ContinueStatement");
        $$->children.push_back(new Node("continue", "Keyword", yylineno));
        $$->children.push_back(new Node(";", "Separator", yylineno));
    }
 | k_continue Identifier s_semicolon 
 {
    $$ = new Node("ContinueStatement");
    $$->children.push_back(new Node("continue", "Keyword", yylineno));
    $$->children.push_back(new Node($2, "Identifier",yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));
 }

ReturnStatement: k_return s_semicolon 
{
    $$ = new Node("ReturnStatement");
    $$->children.push_back(new Node("return", "Keyword", yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));
}
| k_return Expression s_semicolon 
{
    $$ = new Node("ReturnStatement");
    $$->children.push_back(new Node("return", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node(";", "Separator", yylineno));
}

ThrowStatement: k_throw s_semicolon
{
    $$ = new Node("ThrowStatement");
    $$->children.push_back(new Node("throw", "Keyword", yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));}
 | k_throw Expression s_semicolon 
 {
    $$ = new Node("ThrowStatement");
    $$->children.push_back(new Node("throw", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node(";", "Separator", yylineno));
 }

SynchronizedStatement:

	k_synchronized s_open_paren Expression s_close_paren Block
    {
        $$ = new Node("SynchronizedStatement");
        $$->children.push_back(new Node("synchronized", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back($3);
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($5);
    }

TryStatement: k_try Block Catches
    {
    $$ = new Node("TryStatement");
    $$->children.push_back(new Node("try", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back($3);
    }
	        | k_try Block Finally
            {
                $$ = new Node("TryStatement");
                $$->children.push_back(new Node("try", "Keyword", yylineno));
                $$->children.push_back($2);
                $$->children.push_back($3);
            }
            | k_try Block Catches Finally
            {
                $$ = new Node("TryStatement");
                $$->children.push_back(new Node("try", "Keyword", yylineno));
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
        $$->children.push_back(new Node("catch", "Keyword", yylineno));
        $$->children.push_back(new Node("(", "Separator", yylineno));
        $$->children.push_back($3);
        $$->children.push_back(new Node(")", "Separator", yylineno));
        $$->children.push_back($5);
    }

Finally: k_finally Block
    {
        $$ = new Node("Finally");
        $$->children.push_back(new Node("finally", "Keyword", yylineno));
        $$->children.push_back($2);
    }


// ------------------ Production 15 -------------------

Primary:
    PrimaryNoNewArray 
    {
        $$ = $1;
    }
    | ArrayCreationExpression 
    {
        $$ = $1;
    }
    ;

PrimaryNoNewArray:
    int_Literal {$$ = new Node($1,"Literal", INT,yylineno);}
    | bin_Literal {$$ = new Node($1,"Literal" , BIN, yylineno);} 
    | deci_flo_Literal {$$ = new Node($1,"Literal", FLOAT ,yylineno);} 
    | oct_Literal {$$ = new Node($1,"Literal", OCT, yylineno);} 
    | hex_flo_Literal {$$ = new Node($1,"Literal", HEX_FLOAT, yylineno);} 
    | string_Literal {$$ = new Node($1,"Literal", STRING, yylineno);} 
    | hex_Literal {$$ = new Node($1,"Literal", HEX, yylineno);}
    | k_this {
        $$ = new Node("this","Keyword", yylineno);
        if(!isDot){
        int x = currentSymTableId;
        while(!symTables[x].isfunction){
            x=symTables[x].parentID;
        }
        $$->symid=symTables[x].parentID;
        //cout<<"this symid: "<<$$->symid<<endl;
        }
    }
    | Text_Block_Literal {$$ = new Node("TextBlock","Literal",STRING, yylineno);}
    | char_Literal {$$ = new Node($1,"Literal", CHAR, yylineno);}
    | true_Literal {$$ = new Node("true","Keyword", BOOL, yylineno);}
    | false_Literal {$$ = new Node("false","Keyword", BOOL, yylineno);}
    | null_Literal {$$ = new Node("null","Keyword", BOOL, yylineno);}
    | s_open_paren Expression s_close_paren {
        $$ = new Node("PrimaryNoNewArray");
        $$->type = $2->type;
        $$->children.push_back(new Node("(","Separator", yylineno));
        $$->children.push_back($2);
        $$->children.push_back(new Node(")","Separator", yylineno));
    }
    | ClassInstanceCreationExpression 
    {
        $$ = $1;
    }
    | FieldAccess 
    {
        $$ = $1;
    }
    | MethodInvocation 
    {
        $$ = $1;
    }
    | ArrayAccess {$$ = $1;}
    ;

ClassInstanceCreationExpression:
    k_new ClassType s_open_paren s_close_paren
    { $$ = new Node("ClassInstanceCreationExpression");
       //$$->type = $2->type;
       $$->children.push_back(new Node("new","Keyword", yylineno));
       $$->children.push_back($2);
       $$->children.push_back(new Node("(","Separator", yylineno));
       $$->children.push_back(new Node(")","Separator", yylineno));
       if(!isDot){
            if(reftype!=$2->id){
                yyerror("ClassType mismatch");
                exit(0);
            }
       }
    }
    | k_new ClassType s_open_paren ArgumentList s_close_paren
        { 
        $$ = new Node("ClassInstanceCreationExpression");
        $$->type = $2->type;
        $$->children.push_back(new Node("new","Keyword", yylineno));
        $$->children.push_back($2);
        $$->children.push_back(new Node("(","Separator", yylineno));
        $$->children.push_back($4);
        $$->children.push_back(new Node(")","Separator", yylineno));
        if(!isDot){
            if(reftype!=$2->id){
                yyerror("ClassType mismatch");
                exit(0);
            }
            cout<<"this symid : "<<class_to_symboltable[$2->id]<<endl;
            vector<struct symEntry>* a = symTables[class_to_symboltable[$2->id]].getSymEntry($2->id);
            if((*a).size()!=vfs.size()+1 || !(*a)[0].isfunction){
                cout<<(*a).size()<<" "<<vfs.size()<<endl;
                yyerror("Constructor not found");
                exit(0);
            }
            $$->type=(*a)[0].type;
            cout<<vfs.size()<<" "<<vt.size()<<endl;
            for(int i=0;i<vfs.size();i++){
                cout<<vt[i]<<" "<<(*a)[i+1].type<<endl;
                if(vt[i]!=(*a)[i+1].type || vfs[i]!=(*a)[i+1].size){
                    yyerror("Argument type mismatch");
                    exit(0);
                }
            }
            vt.clear();
            vfs.clear();
        }
        }
    ;

ArgumentList:
    Expression
    {
        $$ = $1;
        if(!isDot){
            cout<<"vfs size: "<<vfs.size()<<endl;
            cout<<"vt size: "<<vt.size()<<endl;
            vt.push_back($1->type);
            vfs.push_back($1->size);
        }
    }
    | ArgumentList s_comma Expression
    {
        $$ = new Node("ArgumentList");
        $$->children.push_back($1);
        $$->children.push_back(new Node(",","Separator", yylineno));
        $$->children.push_back($3);
        if(!isDot){
            cout<<$3->type<<endl;
            cout<<"vfs size: "<<vfs.size()<<endl;
            cout<<"vt size: "<<vt.size()<<endl;
            vt.push_back($3->type);
            cout<<vt[vt.size() -1]<<endl;
            vfs.push_back($3->size);
        }
    }
    ;

ArrayCreationExpression:
    k_new PrimitiveType DimExprs 
     { 
       $$ = new Node("ArrayCreationExpression");
       $$->type = $2->type;
       $$->children.push_back(new Node("new","Keyword", yylineno));
       $$->children.push_back($2);
       $$->children.push_back($3);
       if(!isDot){
        if(t != $2->type){
                yyerror("Type mismatch in arrayCreationExpression rhs");
                exit(0);
        }
        $$->size = vs.size();
       }
     }
    | k_new PrimitiveType Dims ArrayInitializer
    { $$ = new Node("ArrayCreationExpression");
         $$->type= $2->type;
       $$->children.push_back(new Node("new","Keyword", yylineno));
       $$->children.push_back($2);
       $$->children.push_back($3);
       $$->children.push_back($4);
       if(!isDot){
            if(t != $2->type){
                    yyerror("Type mismatch in arrayCreationExpression rhs");
                    exit(0);
            }
            $$->size = vs.size();
       }
    }
    | k_new PrimitiveType DimExprs Dims
        { $$ = new Node("ArrayCreationExpression");
         $$->type= $2->type;
       $$->children.push_back(new Node("new","Keyword", yylineno));
       $$->children.push_back($2);
       $$->children.push_back($3);
       $$->children.push_back($4);
       if(!isDot){
        if(t != $2->type){
                yyerror("Type mismatch in ArrayCreationExpression rhs");
                exit(0);
        }
        $$->size = vs.size();
       }
    }
    | k_new Name DimExprs 
        { $$ = new Node("ArrayCreationExpression");
          $$->type= $2->type;
       $$->children.push_back(new Node("new","Keyword", yylineno));
       $$->children.push_back($2);
       $$->children.push_back($3);
       if(!isDot){
        if(t != $2->type){
                yyerror("Type mismatch in ArrayCreationExpression rhs");
                exit(0);
        }
        $$->size = vs.size();
       }
      }
    | k_new Name DimExprs Dims
        { $$ = new Node("ArrayCreationExpression");
            $$->type= $2->type;
       $$->children.push_back(new Node("new","Keyword", yylineno));
       $$->children.push_back($2);
       $$->children.push_back($3);
       $$->children.push_back($4);
         if(!isDot){
          if(t != $2->type){
                 yyerror("Type mismatch in ArrayCreationExpression rhs");
                 exit(0);
          }
          $$->size = vs.size();
       }
     }
    | k_new Name Dims ArrayInitializer
        { $$ = new Node("ArrayCreationExpression");
            $$->type= $2->type;
       $$->children.push_back(new Node("new","Keyword", yylineno));
       $$->children.push_back($2);
       $$->children.push_back($3);
       $$->children.push_back($4);
         if(!isDot){
          if(t != $2->type){
                 yyerror("Type mismatch in ArrayCreationExpression rhs");
                 exit(0);
          }
          $$->size = vs.size();
       }
      }
    ;


DimExprs:
    DimExpr
     {$$ = $1;}
    | DimExprs DimExpr
    {$$ = new Node("DimExprs");
    $$->children.push_back($1);
    $$->children.push_back($2);
    }
    ;

DimExpr:
    s_open_square_bracket Expression s_close_square_bracket
     {
        $$ = new Node("DimExpr");
        if(!isDot){
            if(widen($2->type, LONG) != LONG)
            {
                yyerror("Array index must be of type int");
                exit(0);
            }
            if(isarr){
                vs.push_back(vs.size()+1);
            }
        }
     $$->children.push_back(new Node("[","Separator", yylineno));
     $$->children.push_back($2);
     $$->children.push_back(new Node("]","Separator", yylineno));
     }
    ;


Dims:
    s_open_square_bracket s_close_square_bracket
    {
        $$ = new Node("Dims");
    $$->children.push_back(new Node("[","Separator", yylineno));
    $$->children.push_back(new Node("]","Separator", yylineno));
    if(isarr){
        vs.push_back(0);
    }
    }
    | Dims s_open_square_bracket s_close_square_bracket
    {$$ = new Node("Dims");
    $$->children.push_back($1);
    $$->children.push_back(new Node("[","Separator", yylineno));
    if(isarr){
        vs.push_back(0);
    }
    }
    ;

FieldAccess:
    Primary s_dot Identifier
    {   if(isDot)
        $$ = new Node("FieldAccess");
        else
        $$ = new Node($3,"FieldAccess",yylineno);
        $$->children.push_back($1);
        $$->children.push_back(new Node(".","Separator", yylineno));
        $$->children.push_back(new Node($3,"Identifier",yylineno));
    if(!isDot){
        if(!symTables[$1->symid].grand_lookup($3)){
            yyerror("Requested field not found");
            exit(0);
        }
        vector<struct symEntry>* a = symTables[$1->symid].getSymEntry($3);
        if(/*(*a).size()!=1 ||*/ (*a)[0].isfunction){
            yyerror("Requested field not found");
            exit(0);
        }
        $$->type=(*a)[0].type;
        $$->size=(*a).size()-1;
        $$->symid=$1->symid;
        // cout<<$$->size<<endl;
        // cout<<"jshkjwbjeb"<<endl;
    }
    }
    | k_super s_dot Identifier
    {$$ = new Node("FieldAccess");
    //$$->type= $3->type;
    $$->children.push_back(new Node("super","Keyword", yylineno));
    $$->children.push_back(new Node(".","Separator", yylineno));
    $$->children.push_back(new Node($3,"Identifier",yylineno));}
    ;

MethodInvocation:
    Name s_open_paren s_close_paren
    {$$ = new Node("MethodInvocation");
     //$$->type= $1->type;
    $$->children.push_back($1);
    $$->children.push_back(new Node("(","Separator", yylineno));
    $$->children.push_back(new Node(")","Separator", yylineno));
    if(!isDot){
        vector<struct symEntry>* a = symTables[$1->symid].getSymEntry($1->id);
        if((*a).size()!=1 || !(*a)[0].isfunction){
            yyerror("Method not found");
            exit(0);
        }
        $$->type=(*a)[0].type;
    }
    }
    | Name s_open_paren ArgumentList s_close_paren
     {$$ = new Node("MethodInvocation");
       // $$->type= $1->type;
     $$->children.push_back($1);
     $$->children.push_back(new Node("(","Separator", yylineno));
     $$->children.push_back($3);
     $$->children.push_back(new Node(")","Separator", yylineno));
        if(!isDot){
            vector<struct symEntry>* a = symTables[$1->symid].getSymEntry($1->id);
            if((*a).size()!=vfs.size()+1 || !(*a)[0].isfunction){
                yyerror("Method not found");
                exit(0);
            }
            $$->type=(*a)[0].type;
            cout<<vfs.size()<<" "<<vt.size()<<endl;
            for(int i=0;i<vfs.size();i++){
                cout<<vt[i]<<" "<<(*a)[i+1].type<<endl;
                if(vt[i]!=(*a)[i+1].type || vfs[i]!=(*a)[i+1].size){
                    yyerror("Argument type mismatch");
                    exit(0);
                }
            }
            vt.clear();
            vfs.clear();
        }
     }
    | Primary s_dot Identifier s_open_paren s_close_paren
    {$$ = new Node("MethodInvocation");
    //$$->type= $3->type;
    $$->children.push_back($1);
    $$->children.push_back(new Node(".","Separator", yylineno));
    $$->children.push_back(new Node($3,"Identifier",yylineno));
    $$->children.push_back(new Node("(","Separator", yylineno));
    $$->children.push_back(new Node(")","Separator", yylineno));
    if(!isDot){
        if(!symTables[$1->symid].grand_lookup($3)){
            yyerror("Method not found");
            exit(0);
        }
        vector<struct symEntry>* a = symTables[$1->symid].getSymEntry($3);
        if((*a).size()!=1 || !(*a)[0].isfunction){
            yyerror("Method not found");
            exit(0);
        }
        $$->type=(*a)[0].type;
    }
    }
    | Primary s_dot Identifier s_open_paren ArgumentList s_close_paren
    {$$ = new Node("MethodInvocation");
   // $$->type= $3->type;
    $$->children.push_back($1);
    $$->children.push_back(new Node(".","Separator", yylineno));
    $$->children.push_back(new Node($3,"Identifier",yylineno));
    $$->children.push_back(new Node("(","Separator", yylineno));
    $$->children.push_back($5);
    $$->children.push_back(new Node(")","Separator", yylineno));
    if(!isDot){
        if(!symTables[$1->symid].grand_lookup($3)){
            yyerror("Method not found");
            exit(0);
        }
        vector<struct symEntry>* a = symTables[$1->symid].getSymEntry($3);
        if((*a).size()!=vfs.size()+1 || !(*a)[0].isfunction){
            yyerror("Method not found");
            exit(0);
        }
        $$->type=(*a)[0].type;
        for(int i=0;i<vfs.size();i++){
            if(vt[i]!=(*a)[i+1].type || vfs[i]!=(*a)[i+1].size){
                yyerror("Argument type mismatch");
                exit(0);
            }
        }
        vt.clear();
        vfs.clear();
    }
    }
    | k_super s_dot Identifier s_open_paren s_close_paren
    {$$ = new Node("MethodInvocation");
    //$$->type= $3->type;
    $$->children.push_back(new Node("super","Keyword", yylineno));
    $$->children.push_back(new Node(".","Separator", yylineno));
    $$->children.push_back(new Node($3,"Identifier",yylineno));
    $$->children.push_back(new Node("(","Separator", yylineno));
    $$->children.push_back(new Node(")","Separator", yylineno));

    }
    | k_super s_dot Identifier s_open_paren ArgumentList s_close_paren
    {$$ = new Node("MethodInvocation");
    //$$->type= $3->type;
    $$->children.push_back(new Node("super","Keyword", yylineno));
    $$->children.push_back(new Node(".","Separator", yylineno));
    $$->children.push_back(new Node($3,"Identifier",yylineno));
    $$->children.push_back(new Node("(","Separator", yylineno));
    $$->children.push_back($5);
    $$->children.push_back(new Node(")","Separator", yylineno));
    }
    ;

ArrayAccess:
    Name s_open_square_bracket Expression s_close_square_bracket
    {
     if(isDot)
     $$ = new Node("ArrayAccess");
     else{
        $$ = new Node($1->id.c_str(),"ArrayAccess",yylineno);
        if(widen($3->type, LONG) != LONG)
        {
            yyerror("Array index must be of type int");
            exit(0);
        }
        vector<struct symEntry>* a = symTables[$1->symid].getSymEntry($1->id);
        if($3->size != 0){
            yyerror("Array index must be of type int");
            exit(0);
        }
        vs.push_back($3->size);
        if(size>(*a).size()-1 || (*a)[0].isfunction){
            yyerror("Array dimension mismatch");
            exit(0);
        }
        $$->type=(*a)[0].type;
        $$->size=(*a).size()-1-vs.size();
        $$->symid=$1->symid;
        cout<<"Size is "<<vs.size()<<" "<<(*a).size()<<endl;
     }
    $$->children.push_back($1);
    $$->children.push_back(new Node("[","Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node("]","Separator", yylineno));
    }
    | PrimaryNoNewArray s_open_square_bracket Expression s_close_square_bracket
    {   if(isDot)
        $$ = new Node("ArrayAccess");
        else{
            $$ = new Node($1->id.c_str(),"ArrayAccess",yylineno);
            if(widen($3->type, LONG) != LONG)
            {
                yyerror("Array index must be of type int");
                exit(0);
            }
            if($3->size != 0){
                yyerror("Array index must be of type int");
                exit(0);
            }
            vs.push_back($3->size);
            vector<struct symEntry>* a = symTables[$1->symid].getSymEntry($1->id);
            if((*a).size()-1<size || (*a)[0].isfunction){
                yyerror("Array dimension mismatch");
                exit(0);
            }
            $$->type=(*a)[0].type;
            $$->size=(*a).size()-vs.size()-1;
            $$->symid=$1->symid;
            cout<<"Size is "<<vs.size()<<" "<<(*a).size()<<" "<<$$->size<<endl;
     }
    $$->children.push_back($1);
    $$->children.push_back(new Node("[","Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node("]","Separator", yylineno));
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
     $$->type= $1->type;
     if(!isDot){
        if (widen($1->type, LONG) != LONG )
        {
            yyerror("Post increment can only be applied to int");
            exit(0);
        }
     }
    
    $$->children.push_back($1);
    $$->children.push_back(new Node("++","Separator", yylineno));}
    ;

PostDecrementExpression:
    PostFixExpression o_decrement
    {$$ = new Node("PostDecrementExpression");
        $$->type= $1->type;
        if(!isDot){
            if (widen($1->type, LONG) != LONG )
            {
                yyerror("Post decrement can only be applied to int");
                exit(0);
            }
        }
    $$->children.push_back($1);}
    ;

UnaryExpression:
    PreIncrementExpression
    {$$ = $1;}
    | PreDecrementExpression
    {$$ = $1;}
    | o_add UnaryExpression
    {$$ = new Node("UnaryExpression");
    $$->type= $2->type;
    if(!isDot){
        if (widen($2->type, DOUBLE) != DOUBLE)
        {
            yyerror("Unary plus can only be applied to int");
            exit(0);
        }
    }
    $$->children.push_back(new Node("+","Separator", yylineno));
    $$->children.push_back($2);}
    | o_subtract UnaryExpression
    {$$ = new Node("UnaryExpression");
    $$->type= $2->type;
    if(!isDot){
        if (widen($2->type, DOUBLE) != DOUBLE)
        {
            yyerror("Unary minus can only be applied to int");
            exit(0);
        }
    }    
    $$->children.push_back(new Node("-","Separator", yylineno));
    $$->children.push_back($2);}
    | UnaryExpressionNotPlusMinus
    {$$ = $1;}
    ;

PreIncrementExpression:
    o_increment UnaryExpression
    {$$ = new Node("PreIncrementExpression");
     $$->type= $2->type;
     if(!isDot){
        if (widen($2->type, LONG) != LONG )
        {
            yyerror("Pre increment can only be applied to int");
            exit(0);
        }
     }
    $$->children.push_back(new Node("++","Separator", yylineno));
    $$->children.push_back($2);}
    ;

PreDecrementExpression:
    o_decrement UnaryExpression
    {$$ = new Node("PreDecrementExpression");
        $$->type= $2->type;
        if(!isDot){
            if (widen($2->type, LONG) != LONG)
            {
                yyerror("Pre decrement can only be applied to int");
                exit(0);
            }
        }
    $$->children.push_back(new Node("--","Separator", yylineno));
    $$->children.push_back($2);}
    ;

UnaryExpressionNotPlusMinus:
   PostFixExpression
   {$$ = $1;}
    | o_bitwise_complement UnaryExpression
    {$$ = new Node("UnaryExpressionNotPlusMinus");
     $$->type= widen($2->type, INT);
     if(!isDot){
        if (widen($2->type, LONG) != LONG)
        {
            yyerror("Bitwise complement can only be applied to int");
            exit(0);
        }
     }
    $$->children.push_back(new Node("~","Separator", yylineno));
    $$->children.push_back($2);}
    | o_logical_not UnaryExpression
    {
        $$ = new Node("UnaryExpressionNotPlusMinus");
        $$->type= $2->type;
        if(!isDot){
            if ($2->type != BOOL)
            {
                yyerror("Logical not can only be applied to BOOL");
                exit(0);
            }
        }
    $$->children.push_back(new Node("!","Separator", yylineno));
    $$->children.push_back($2);}
    | CastExpression
    {$$ = $1;}
    ;

CastExpression:
    s_open_paren PrimitiveType s_close_paren UnaryExpression
    {$$ = new Node("CastExpression");
    if(!isDot){
        if (widen($2->type, DOUBLE) != DOUBLE || widen($4->type, DOUBLE) != DOUBLE)
        {
            yyerror("Cast can only be applied to integer types");
            exit(0);
        }
    }
     $$->type= $2->type;
    $$->children.push_back(new Node("(","Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node(")","Separator", yylineno));
    $$->children.push_back($4);
    }
    | s_open_paren PrimitiveType Dims s_close_paren UnaryExpression
    {
    $$ = new Node("CastExpression");
    if(!isDot){
        if (widen($2->type, DOUBLE) != DOUBLE || widen($5->type, DOUBLE) != DOUBLE)
        {
            yyerror("Cast can only be applied to integer types");
            exit(0);
        }
    }
    $$->type= $2->type;
    $$->children.push_back(new Node("(","Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back(new Node(")","Separator", yylineno));
    $$->children.push_back($5);
    }
    | s_open_paren Expression s_close_paren UnaryExpressionNotPlusMinus
    {
    $$ = new Node("CastExpression");
    if(!isDot){
        if (widen($2->type, DOUBLE) != DOUBLE || widen($4->type, DOUBLE) != DOUBLE)
        {
            yyerror("Cast can only be applied to integer types");
            exit(0);
        }
    }
    $$->children.push_back(new Node("(","Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node(")","Separator", yylineno));
    $$->children.push_back($4);
    }
    | s_open_paren Name Dims s_close_paren UnaryExpressionNotPlusMinus
    {
    $$ = new Node("CastExpression");
    $$->children.push_back(new Node("(","Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back(new Node(")","Separator", yylineno));
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
    if(!isDot){
        if (widen($1->type, DOUBLE) != DOUBLE || widen($3->type, DOUBLE) != DOUBLE)
        {
            yyerror("Multiplication can only be applied to int");
            exit(0);
        }
        $$->type = widen($1->type, $3->type);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("*","Separator", yylineno));
    $$->children.push_back($3);
    }
    | MultiplicativeExpression o_divide UnaryExpression
    {
    $$ = new Node("MultiplicativeExpression");
    if(!isDot){
        if (widen($1->type, DOUBLE) != DOUBLE || widen($3->type, DOUBLE) != DOUBLE)
        {
            yyerror("DIVISION can only be applied to int");
            exit(0);
        }
        $$->type = widen($1->type, $3->type);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("/","Separator", yylineno));
    $$->children.push_back($3);
    }
    | MultiplicativeExpression o_modulo UnaryExpression
    {
    $$ = new Node("MultiplicativeExpression");
    if(!isDot){
        if (widen($1->type, DOUBLE) != DOUBLE || widen($3->type, DOUBLE) != DOUBLE)
        {
            yyerror("Modulo can only be applied to int");
            exit(0);
        }
        $$->type = widen($1->type, $3->type);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("%","Separator", yylineno));
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
    if(!isDot){
        if (widen($1->type, STRING) != STRING || widen($3->type, STRING) != STRING)
        {
            yyerror("Addition can only be applied to int");
            exit(0);
        }
        $$->type = widen($1->type, $3->type);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("+","Separator", yylineno));
    $$->children.push_back($3);
    }
    | AdditiveExpression o_subtract MultiplicativeExpression
    {
    $$ = new Node("AdditiveExpression");
    if(!isDot){
        if (widen($1->type, DOUBLE) != DOUBLE || widen($3->type, DOUBLE) != DOUBLE)
        {
            yyerror("Addition can only be applied to int");
            exit(0);
        }
        $$->type = widen($1->type, $3->type);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("-","Separator", yylineno));
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
    if(!isDot){
        if(widen($1->type, LONG) != LONG || (widen($3->type, LONG) != LONG || $3->type == CHAR) )
        {
            yyerror("Shift Operation can only be applied to int");
            exit(0);
        }
        $$->type = widen($1->type, INT);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("<<","Separator", yylineno));
    $$->children.push_back($3);
    }
    | ShiftExpression o_right_shift AdditiveExpression
    {
    $$ = new Node("ShiftExpression");
    if(!isDot){
        if(widen($1->type, LONG) != LONG || (widen($3->type, LONG) != LONG || $3->type == CHAR) )
        {
            yyerror("Shift Operation can only be applied to int");
            exit(0);
        }
        $$->type = widen($1->type, INT);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node(">>","Separator", yylineno));
    $$->children.push_back($3);
    }
    | ShiftExpression o_unsigned_right_shift AdditiveExpression
    {
    $$ = new Node("ShiftExpression");
    if(!isDot){
        if(widen($1->type, LONG) != LONG || (widen($3->type, LONG) != LONG || $3->type == CHAR) )
        {
            yyerror("Shift Operation can only be applied to int");
            exit(0);
        }
        $$->type = widen($1->type, INT);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node(">>>","Separator", yylineno));
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
    if(!isDot){
        if(widen($1->type, $3->type) != $1->type || widen($3->type, $1->type) != $3->type)
        {
            yyerror("less than operator can only be applied to same common super type");
            exit(0);
        }
        $$->type = BOOL;
    }
    $$->children.push_back(new Node("<","Separator", yylineno));
    $$->children.push_back($3);
    }
    | RelationalExpression o_greater_than ShiftExpression
    {
    $$ = new Node("RelationalExpression");
    if(!isDot){
        if(widen($1->type, $3->type) != $1->type || widen($3->type, $1->type) != $3->type)
        {
            yyerror("less than operator can only be applied to same common super type");
            exit(0);
        }
        $$->type = BOOL;
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node(">","Separator", yylineno));
    $$->children.push_back($3);
    }
    | RelationalExpression o_less_than_or_equal ShiftExpression
    {
    $$ = new Node("RelationalExpression");
    if(!isDot){
        if(widen($1->type, $3->type) != $1->type || widen($3->type, $1->type) != $3->type)
        {
            yyerror("less than operator can only be applied to same common super type");
            exit(0);
        }
        $$->type = BOOL;
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("<=","Separator", yylineno));
    $$->children.push_back($3);
    }
    | RelationalExpression o_greater_than_or_equal ShiftExpression
    {
    $$ = new Node("RelationalExpression");
    if(!isDot){
        if(widen($1->type, $3->type) != $1->type || widen($3->type, $1->type) != $3->type)
        {
            yyerror("less than operator can only be applied to same common super type");
            exit(0);
        }
        $$->type = BOOL;
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node(">=","Separator", yylineno));
    $$->children.push_back($3);
    }
    | RelationalExpression k_instanceof ReferenceType
    {
    $$ = new Node("RelationalExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("instanceof","Separator", yylineno));
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
    if(!isDot){
        if(widen($1->type, $3->type) != $1->type || widen($3->type, $1->type) != $3->type)
        {
            yyerror("Equality can only be applied to same common super type");
            exit(0);
        }
        $$->type = widen($1->type, $3->type);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("==","Separator", yylineno));
    $$->children.push_back($3);
    }
    | EqualityExpression o_not_equals RelationalExpression
    {
    $$ = new Node("EqualityExpression");
    if(!isDot){
        if(widen($1->type, $3->type) != $1->type || widen($3->type, $1->type) != $3->type)
        {
            yyerror("Equality can only be applied to same common super type");
            exit(0);
        }
        $$->type = widen($1->type, $3->type);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("!=","Separator", yylineno));
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
    if(!isDot){
        if(widen($1->type, LONG) != LONG || widen($3->type, LONG) != LONG)
        {
            yyerror("Bitwise AND can only be applied to int");
            exit(0);
        }
        $$->type = widen($1->type, $3->type);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("&","Separator", yylineno));
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
    if(!isDot){
        if(widen($1->type, LONG) != LONG || widen($3->type, LONG) != LONG)
        {
            yyerror("Bitwise XOR can only be applied to int");
            exit(0);
        }
        $$->type = widen($1->type, $3->type);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("^","Separator", yylineno));
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
    if(!isDot){
        if(widen($1->type, LONG) != LONG || widen($3->type, LONG) != LONG)
        {
            yyerror("Bitwise OR can only be applied to int");
            exit(0);
        }
        $$->type = widen($1->type, $3->type);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("|","Separator", yylineno));
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
    if(!isDot){
        if($1->type != BOOL || $3->type != BOOL)
        {
            yyerror("Only Bools allowed");
            exit(0);
        }
        $$->type = BOOL; 
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("&&","Separator", yylineno));
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
    if(!isDot){
        if($1->type != BOOL || $3->type != BOOL)
        {
            yyerror("Only Bools allowed");
            exit(0);
        }
        $$->type = BOOL; 
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("||","Separator", yylineno));
    $$->children.push_back($3);
    }
    ;

ConditionalExpression:  
    ConditionalOrExpression
    {
        $$ = $1;
    }
    | ConditionalOrExpression o_question_mark Expression o_colon ConditionalExpression{
        $$ = new Node("ConditionalExpression");
        if(!isDot){
            if($1->type != BOOL){
                yyerror("Conditional Operation can only be applied to boolean");
                exit(0);
            }
            if(widen($3->type, $5->type) != $5->type || widen($3->type, $5->type) != $3->type){
                yyerror("Conditional Operation can only be applied to same type");
                exit(0);
            }
            $$->type = widen($5->type, $3->type);
        }
        $$->children.push_back($1);
        $$->children.push_back(new Node("?","Separator", yylineno));
        $$->children.push_back($3);
        $$->children.push_back(new Node(":","Separator", yylineno));
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
        if(!isDot){
            if(widen($1->type,$3->type) != $1->type){
                yyerror("Assignment Operation can only be applied to same type");
                exit(0);
            }
            cout<<$1->size<<" "<<$3->size<<endl;
            if($1->size != $3->size){
                yyerror("Assignment Operation can only be applied to same size");
                exit(0);
            }
            $$->type = $1->type;
        }
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
    size=0;
        vs.clear();
    }
    ;

AssignmentOperator:
    o_assign
    {
    $$ = new Node("=","Separator", yylineno);
    }
    | o_add_assign
    {
    $$ = new Node("+=","Separator", yylineno);
    }
    | o_subtract_assign
    {
    $$ = new Node("-=","Separator", yylineno);
    }
    | o_multiply_assign
    {
    $$ = new Node("*=","Separator", yylineno);
    }
    | o_divide_assign
    {
    $$ = new Node("/=","Separator", yylineno);
    }
    | o_modulo_assign
    {
    $$ = new Node("%=","Separator", yylineno);
    }
    | o_left_shift_assign
    {
    $$ = new Node("<<=","Separator", yylineno);
    }
    | o_right_shift_assign
    {
    $$ = new Node(">>=","Separator", yylineno);
    }
    | o_unsigned_right_shift_assign
    {
    $$ = new Node(">>>=","Separator", yylineno);
    }
    | o_bitwise_and_assign
    {
    $$ = new Node("&=","Separator", yylineno);
    }
    | o_bitwise_or_assign
    {
    $$ = new Node("|=","Separator", yylineno);
    }
    | o_bitwise_xor_assign
    {
    $$ = new Node("^=","Separator", yylineno);
    }
    ;

Expression:
    AssignmentExpression
    {
    $$ = $1;
    }
    ;
%%


TYPE widen(TYPE a, TYPE b){
    return (a > b)?a:b;
}

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

void symTab_csv(symtab* a){
    ofstream fout;
    string s= "symtab"+to_string(a->ID)+".csv";
    fout.open(s);
    fout<<"Lexeme,Tokens,Type,ArrayDimSize,LineNo,ScopeID"<<endl;
    for(auto i = a->entries.begin(); i != a->entries.end(); i++){
        for(auto j = i->second.begin(); j != i->second.end(); j++)
            fout<<i->first<<","<<"Identifier"<<","<<enum_types[j->type]<<","<<j->size<<","<<j->lineno<<","<<j->symid<<endl;
    }
    fout.close();
}

void check_semantics(){
    //int counter = 0;
    //traverse_semantics(root, counter);
    for(auto i = symTables.begin(); i != symTables.end(); i++){
        symTab_csv(&i->second);
    }
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
        else if(arg.find("--dot") == 0){
            isDot = true;
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
    if(!isDot){
        initializeSymTable();
    }
    yyparse();
    if(root){
        if(isDot){
            if(output_index)
                print_dot(argv[output_index]);
            else 
                print_dot("parse_tree.dot");
        }
        else{
            check_semantics();
        }
    }
    else printf("Error in generating the parse tree\nAborting...\n");
    return 0;
}
