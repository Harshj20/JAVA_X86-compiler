%{
#include <bits/stdc++.h>
#include "Node.h"
#include "SymTable.h"
#include "codeGen.h"
using namespace std;
extern int yylex();
extern int yylineno;
extern FILE *yyin;
extern map<unsigned long long int, symtab> symTables;
map<string, unsigned long long int> class_to_symboltable;
vector<string> enum_types = {"bin", "oct", "hex_float", "hex", "void", "function", "class", "interface", "enum", "union", "typedef", "unknown", "var", "_null", "byte", "short", "char", "int", "long", "float", "double", "string", "bool", "object"};
int currentSymTableId = 0;
int symTablescount = 1;
bool isDot = false, islocal = false;
vector<TYPE> vt; // vector used for types
TYPE t = VOID;
int sz = 0;
int fsize = 0;
int localoffset=0;
vector<int> vs;  // vector to store max size of dimensions of array
vector<int> vfs; // vector to store dimensions of function arguments
bool isarr = false;
int isArgument = -1;
int ArrayArgumentDepth = 0;
string reftype = "";
int tcounter = 1;
int lcounter = -1;
string isPrivate = "";
bool isreturn =false;
bool isstatic = false;
bool isfinal = false;
vector<string> threeAC;
vector<int> loopscope; // to store the scope of loops
string returnFunctionName = "";
string className = "";
int offset = 0;
int offsetVal[] = {8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
vector<string> arrinit;
string old_field = "";
string entryClass = "";
bool isMain = false;
bool flag_verbose = false;
void yyerror(const char *s)
{
    if (flag_verbose)
    {
        printf("Error %s in line %d\n", s, yylineno);
    }
    else
    {
        printf("Syntax error in line %d\n", yylineno);
    }
}
void initializeSymTable(int parentID)
{
    symtab *a = new symtab(symTablescount, parentID);
    currentSymTableId = symTablescount;
    symTablescount++;
    symTables[currentSymTableId] = *a;
}
Node *root = NULL;
TYPE widen(TYPE a, TYPE b);
%}

%define parse.error verbose

%code requires{
#include "Node.h"
}

%union {
    char *str;
    Node *node;
}

%token k_abstract k_assert k_boolean k_break k_byte k_case k_catch k_char k_class k_const k_continue k_default k_do k_double k_else k_enum k_extends k_final k_finally k_float k_for k_goto k_if k_implements k_import k_instanceof k_int k_interface k_long k_native k_new k_package k_private k_protected k_public k_return k_short k_static k_strictfp k_super k_switch k_synchronized k_this k_throw k_throws k_transient k_try k_void k_volatile k_while k_underscore
%token k_exports k_module k_non_sealed k_open k_opens k_permits k_provide k_record k_requires k_sealed k_to k_transitive k_uses k_var k_with k_yield k_String

%token o_assign o_add_assign o_subtract_assign o_multiply_assign o_divide_assign o_modulo_assign o_bitwise_and_assign o_bitwise_or_assign o_bitwise_xor_assign o_left_shift_assign o_right_shift_assign o_unsigned_right_shift_assign o_bitwise_and o_bitwise_or o_bitwise_xor o_left_shift o_right_shift o_unsigned_right_shift o_add o_subtract o_multiply o_divide o_modulo o_less_than o_less_than_or_equal o_greater_than o_greater_than_or_equal o_equals o_not_equals o_logical_and o_logical_not o_logical_or o_increment o_decrement o_bitwise_complement o_question_mark o_colon o_arrow 

%token<str> Identifier int_Literal bin_Literal deci_float_Literal oct_Literal hex_flo_Literal string_Literal hex_Literal Text_Block_Literal char_Literal true_Literal false_Literal null_Literal long_Literal deci_double_Literal

%token<str> s_open_paren s_close_paren s_open_curly_bracket s_close_curly_bracket s_open_square_bracket s_close_square_bracket s_semicolon s_comma s_dot s_varargs s_double_colon

%start Program

%type<node> Program CompilationUnit ImportDeclarations ImportDeclaration TypeDeclarations TypeDeclaration ClassDeclaration NormalClassDeclaration ClassBody PackageDeclaration Type PrimitiveType ReferenceType NumericType IntegralType FloatingPointType ClassOrInterfaceType ClassType InterfaceType ArrayType Name SimpleName QualifiedName ClassBodyDeclaration ClassMemberDeclaration FieldDeclaration MethodDeclaration MethodHeader MethodDeclarator FormalParameterList FormalParameter VariableDeclarator VariableDeclaratorId VariableInitializer ArrayInitializer Block BlockStatements BlockStatement LocalVariableDeclarationStatement LocalVariableDeclaration Statement StatementWithoutTrailingSubstatement StatementExpression IfThenStatement IfThenElseStatement WhileStatement ForStatement ReturnStatement Expression Assignment ConditionalExpression ConditionalOrExpression ConditionalAndExpression InclusiveOrExpression ExclusiveOrExpression AndExpression EqualityExpression RelationalExpression ShiftExpression AdditiveExpression MultiplicativeExpression UnaryExpression UnaryExpressionNotPlusMinus PostIncrementExpression PostDecrementExpression Primary PrimaryNoNewArray ArrayAccess FieldAccess MethodInvocation SingleTypeImportDeclaration TypeImportOnDemandDeclaration Modifiers Modifier Super Interfaces InterfaceTypeList ClassTypeList ClassBodyDeclarations VariableDeclaratorList VariableInitializerList Throws MethodBody StaticInitializer ConstructorDeclaration ConstructorDeclarator ConstructorBody ExplicitConstructorInvocation EnumDeclaration ClassImplements EnumBody EnumConstantList EnumBodyDeclarations
InterfaceDeclaration  InterfaceBody InterfaceMemberDeclaration ConstantDeclaration ExtendsInterfaces InterfaceMemberDeclarations 
AbstractMethodDeclaration StatementNoShortIf EmptyStatement ExpressionStatement BreakStatement ContinueStatement  ForStatementNoShortIf IfThenElseStatementNoShortIf LabeledStatement  ThrowStatement SynchronizedStatement TryStatement  WhileStatementNoShortIf LocalVariableType LabeledStatementNoShortIf ForInit ForUpdate StatementExpressionList Catches CatchClause Finally ClassInstanceCreationExpression ArrayCreationExpression ArgumentList DimExprs DimExpr Dims PostFixExpression PreIncrementExpression PreDecrementExpression CastExpression AssignmentOperator AssignmentExpression LeftHandSide BasicForStatement EnhancedForStatement BasicForStatementNoShortIf EnhancedForStatementNoShortIf EnumConstant key_class key_class_super if_invoke_paren invoke_else

%%
    // ------------------ Start -----------------------

Program:
{
    root = new Node("Program");
    root->children.push_back(new Node("EOF", "EOF", -1));
}
| CompilationUnit
{
    root = new Node("Program");
    root->children.push_back($1);
    root->children.push_back(new Node("EOF", "EOF", -1));
    if(!isDot){
        threeAC = $$->threeACCode;
    }
}

// -------------------------------- Production 4 -----------------------

Type : PrimitiveType
{
    $$ = $1;
}
| ReferenceType
{
    $$ = $1;
}

PrimitiveType : NumericType
{
    $$ = $1;
}
| k_boolean
{
    $$ = new Node("boolean", "Keyword", yylineno);
    if (!isDot)
    {
        $$->type = BOOL;
        t = BOOL;
    }
}
| k_String
{
    $$ = new Node("String", "Keyword", yylineno);
    if (!isDot)
    {
        $$->type = STRING;
        t = STRING;
    }
}

NumericType : IntegralType
{
    $$ = $1;
}
| FloatingPointType
{
    $$ = $1;
}

IntegralType : k_byte
{
    $$ = new Node("byte", "Keyword", INT, yylineno);
    t = INT;
}
| k_short
{
    $$ = new Node("short", "Keyword", INT, yylineno);
    t = INT;
}
| k_int
{
    $$ = new Node("int", "Keyword", INT, yylineno);
    t = INT;
}
| k_long
{
    $$ = new Node("long", "Keyword", LONG, yylineno);
    t = LONG;
}
| k_char
{
    $$ = new Node("char", "Keyword", CHAR, yylineno);
    t = CHAR;
}

FloatingPointType : k_float
{
    $$ = new Node("float", "Keyword", FLOAT, yylineno);
    t = FLOAT;
}
| k_double
{
    $$ = new Node("double", "Keyword", DOUBLE, yylineno);
    t = DOUBLE;
}

ReferenceType : ClassOrInterfaceType
{
    $$ = $1;
    if (!isDot)
    {
        $$->type = OBJECT;
        t = OBJECT;
        reftype = $1->id;
    }
}
| ArrayType
{
    $$ = $1;
}

ClassOrInterfaceType : Name
{
    $$ = $1;
}

ClassType : ClassOrInterfaceType
{
    $$ = $1;
}

InterfaceType : ClassOrInterfaceType
{
    $$ = $1;
}

ArrayType : PrimitiveType s_open_square_bracket s_close_square_bracket
{
    $$ = new Node("ArrayType");
    $$->children.push_back($1);
    $$->children.push_back(new Node("[", "Separator", yylineno));
    $$->children.push_back(new Node("]", "Separator", yylineno));
    if(!isDot){
        $$->sz++;
        $$->type = $1->type;
        isarr = true;
        ++sz;
        ++fsize;
    }
}
| Name s_open_square_bracket s_close_square_bracket
{
    $$ = new Node("ArrayType");

    if (!isDot)
    {
        if (!symTables[currentSymTableId].lookup($1->id))
        {
            string s1 = "Undeclared type " + $1->id;
            yyerror(s1.c_str());
            exit(0);
        }
        $$->type = (*symTables[currentSymTableId].getSymEntry($1->id))[0].type;
        $$->sz++;
        isarr = true;
        ++sz;
        ++fsize;
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("[", "Separator", yylineno));
    $$->children.push_back(new Node("]", "Separator", yylineno));
}
| ArrayType s_open_square_bracket s_close_square_bracket
{
    $$ = new Node("ArrayType");
    $$->children.push_back($1);
    $$->children.push_back(new Node("[", "Separator", yylineno));
    $$->children.push_back(new Node("]", "Separator", yylineno));
    if(!isDot){
        $$->sz = $1->sz + 1;
        ++sz;
        isarr = true;
        ++fsize;
        $$->type = $1->type;
    }
}

// ------------------------------- Production 6 --------------------------

Name : SimpleName
{
    $$ = $1;
}
| QualifiedName
{
    $$ = $1;
}

SimpleName : Identifier
{
    string lex($1);
    if (!isDot)
    {
        int t1 = symTables[currentSymTableId].grand_lookup(lex);
        if (!t1)
        {
            string s1 = "Undeclared variable " + lex;
            yyerror(s1.c_str());
            exit(0);
        }
        if (symTables[t1].entries[lex][0].isPrivate)
        {
            string s1 = "Private variable " + lex;
            yyerror(s1.c_str());
            exit(0);
        }
        if (islocal && isstatic && !symTables[t1].entries[lex][0].isStatic && !symTables[t1].name.empty())
        {
            string s1 = "Non-static variable " + lex + " cannot be referenced from a static context";
            yyerror(s1.c_str());
            exit(0);
        }
        $$ = new Node($1, "Identifier", symTables[t1].entries[lex][0].type, yylineno);

        if ($$->type == OBJECT)
        {
            vector<struct symEntry> v1 = (*symTables[t1].getSymEntry(lex));
            $$->symid = v1[0].symid;
        }
        else if ($$->type == CLASS)
        {
            $$->symid = class_to_symboltable[lex];
        }
        else
        {
            $$->symid = t1;
            if (!symTables[t1].entries[lex][0].isfunction && symTables[t1].entries[lex].size()>1)
            {
                isarr = true;
            }
        }
        $$->sz = symTables[t1].entries[lex].size() - 1;
        if(!symTables[t1].entries[lex][0].isfunction &&  !class_to_symboltable[lex]){
            if(!symTables[t1].name.empty()){
                    $$->threeACCode.push_back("\tt" + to_string(tcounter) + " = this + " + to_string(symTables[t1].entries[lex][0].offset));
                    // $$->field = "t" + to_string(tcounter++);
            }
            else{
                int temp = symTables[t1].entries[lex][0].offset;
                if(temp > 0)
                    //$$->threeACCode.push_back("\tt" + to_string(tcounter) + " = [%rbp+" + to_string(temp) + "]");
                     $$->field = "[%rbp+" + to_string(temp) + "]";
                else
                    //$$->threeACCode.push_back("\tt" + to_string(tcounter) + " = [%rbp" + to_string(temp) + "]");
                     $$->field = "[%rbp" + to_string(temp) + "]";
            }
        }
        $$->isfinal = symTables[t1].entries[lex][0].isfinal;
    }
    else
    {
        $$ = new Node($1, "Identifier", yylineno);
    }
}

QualifiedName : Name s_dot Identifier
{
    if (isDot)
        $$ = new Node("QualifiedName");
    else
        $$ = new Node($3, "QualifiedName", yylineno);
    $$->children.push_back($1);
    $$->children.push_back(new Node(".", "Separator", yylineno));
    $$->children.push_back(new Node($3, "Identifier", yylineno));
    if (!isDot)
    {
        string s($3);

        if (!symTables[$1->symid].grand_lookup(s))
        {
            string s1 = "Undeclared variable " + s;
            yyerror(s1.c_str());
            exit(0);
        }
        if (symTables[$1->symid].entries[s][0].isPrivate)
        {
            string s1 = "Private variable " + s;
            yyerror(s1.c_str());
            exit(0);
        }
        $$->type = symTables[$1->symid].entries[s][0].type;
        if ($$->type == OBJECT)
        {
            $$->symid = symTables[$1->symid].entries[s][0].symid;
        }
        else
        {
            $$->symid = $1->symid;
            if (!symTables[$1->symid].entries[s][0].isfunction && symTables[$1->symid].entries[s].size()>1)
            {
                isarr = true;
            }
        }  
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        if(!symTables[$1->symid].entries[s][0].isfunction){
            $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field);
            int temp = symTables[$1->symid].entries[s][0].offset;
            if(temp > 0)
                $$->threeACCode.push_back("\t" + $$->field + " = (" + $$->field +") + "+ to_string(temp));
            else
                $$->threeACCode.push_back("\t" + $$->field + " = (" + $$->field +") - "+ to_string(-temp));
            $$->field = "(" + $$->field + ")";  
        }
        else
            $$->field = $1->field;
        $$->isfinal = symTables[$1->symid].entries[s][0].isfinal;
    }
}

// --------------------------- Production 7 --------------------------

CompilationUnit : PackageDeclaration ImportDeclarations TypeDeclarations
{
    $$ = new Node("CompilationUnit");
    $$->children.push_back($1);
    $$->children.push_back($2);
    $$->children.push_back($3);
}
| PackageDeclaration ImportDeclarations
{
    $$ = new Node("CompilationUnit");
    $$->children.push_back($1);
    $$->children.push_back($2);
}
| PackageDeclaration TypeDeclarations
{
    $$ = new Node("CompilationUnit");
    $$->children.push_back($1);
    $$->children.push_back($2);

}
| PackageDeclaration
{
    $$ = $1;
}
| ImportDeclarations TypeDeclarations
{
    $$ = new Node("CompilationUnit");
    $$->children.push_back($1);
    $$->children.push_back($2);
}
| TypeDeclarations
{
    $$ = $1;
}
| ImportDeclarations
{
    $$ = $1;
}

ImportDeclarations : ImportDeclaration
{
    $$ = $1;
}
| ImportDeclarations ImportDeclaration
{
    $$ = new Node("ImportDeclarations");
    $$->children.push_back($1);
    $$->children.push_back($2);
}

TypeDeclarations : TypeDeclaration
{
    $$ = $1;
}
| TypeDeclarations TypeDeclaration
{
    $$ = new Node("TypeDeclarations");
    $$->children.push_back($1);
    $$->children.push_back($2);
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $1->threeACCode.clear();
        $2->threeACCode.clear();
    }   
}

PackageDeclaration : k_package Name s_semicolon
{
    $$ = new Node("PackageDeclaration");
    $$->children.push_back(new Node("package", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node(";", "Separator", yylineno));
}

ImportDeclaration : SingleTypeImportDeclaration
{
    $$ = $1;
}
| TypeImportOnDemandDeclaration
{
    $$ = $1;
}

SingleTypeImportDeclaration : k_import Name s_semicolon
{
    $$ = new Node("SingleImportTypeDeclaration");
    $$->children.push_back(new Node("import", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node(";", "Separator", yylineno));
}

TypeImportOnDemandDeclaration : k_import Name s_dot o_multiply s_semicolon
{
    $$ = new Node("PackageDeclaration");
    $$->children.push_back(new Node("import", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node(".", "Separator", yylineno));
    $$->children.push_back(new Node("*", "Operator", yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));
}

TypeDeclaration : ClassDeclaration
{
    $$ = $1;
}
| InterfaceDeclaration
{
    $$ = $1;
}
| s_semicolon
{
    $$ = new Node(";", "Separator", yylineno);
}
// ---------------------------- Production 8 -----------------------

Modifiers : Modifier
{
    $$ = $1;
}
| Modifiers Modifier
{
    $$ = new Node("Modifiers");
    $$->children.push_back($1);
    $$->children.push_back($2);
}

Modifier : k_public
{
    $$ = new Node("public", "Keyword", yylineno);
    if (isPrivate.size() != 0)
    {
        yyerror("Two modifiers not allowed");
        exit(0);
    }
    isPrivate = $$->id;
}
| k_protected
{
    $$ = new Node("protected", "Keyword", yylineno);
    if (isPrivate.size() != 0)
    {
        yyerror("Two modifiers not allowed");
        exit(0);
    }
    isPrivate = $$->id;
}
| k_private
{
    $$ = new Node("private", "Keyword", yylineno);
    if (isPrivate.size() != 0)
    {
        yyerror("Two modifiers not allowed");
        exit(0);
    }
    isPrivate = $$->id;
}
| k_static
{
    $$ = new Node("static", "Keyword", yylineno);
    if(!isDot){
        if(isstatic){
            yyerror("Two modifiers not allowed");
            exit(0);
        }
        isstatic = true;
    }
}
| k_abstract
{
    $$ = new Node("abstract", "Keyword", yylineno);
}
| k_final
{
    $$ = new Node("final", "Keyword", yylineno);
    if(!isDot){
        if(isfinal){
            yyerror("Two modifiers not allowed");
            exit(0);
        }
        isfinal = true;
    }
}
| k_native
{
    $$ = new Node("native", "Keyword", yylineno);
}
| k_synchronized
{
    $$ = new Node("synchronized", "Keyword", yylineno);
}
| k_transient
{
    $$ = new Node("transient", "Keyword", yylineno);
}
| k_volatile
{
    $$ = new Node("volatile", "Keyword", yylineno);
}

ClassDeclaration : NormalClassDeclaration
{
    $$ = $1;
    if(!isDot){
        symTables[currentSymTableId].entries[$1->id][0].offset = offset;
        offset = 0;
        className.clear();
    }
}
| EnumDeclaration
{
    $$ = $1;
}
key_class_super : k_class Identifier Super
{
    $$ = new Node($2, "key_class_super", yylineno);
    $$->children.push_back(new Node("class", "Keyword", yylineno));
    $$->children.push_back(new Node($2, "Identifier", yylineno));
    $$->children.push_back($3);
    if (!isDot)
    {
        string s($2);
        if (symTables[currentSymTableId].entries.find(s) != symTables[currentSymTableId].entries.end())
        {
            yyerror("Class already declared");
            exit(0);
        }
        else
        {
            symTables[currentSymTableId].insertSymEntry(s, CLASS, yylineno);
            isstatic = false;
        }
        initializeSymTable($3->symid);
        symTables[currentSymTableId].name = s;
        class_to_symboltable[s] = currentSymTableId;
        className = $2;
    }
    isPrivate.clear();
}
key_class : k_class Identifier
{
    $$ = new Node($2, "key_class", yylineno);
    $$->children.push_back(new Node("class", "Keyword", yylineno));
    $$->children.push_back(new Node($2, "Identifier", yylineno));
    if (!isDot)
    {
        string s($2);
        if (symTables[currentSymTableId].entries.find(s) != symTables[currentSymTableId].entries.end())
        {
            yyerror("Class already declared");
            exit(0);
        }
        else
        {
            symTables[currentSymTableId].insertSymEntry(s, CLASS, yylineno);
            isstatic = false;
        }
        initializeSymTable(currentSymTableId);
        symTables[currentSymTableId].name = s;
        class_to_symboltable[s] = currentSymTableId;
        className = $2;
    }
    isPrivate.clear();
}

NormalClassDeclaration : Modifiers key_class_super Interfaces ClassBody
{
    if(isDot)
        $$ = new Node("NormalClassDeclaration");
    else
    {
        $$ = new Node($2->id.c_str(), "NormalClassDeclaration", yylineno);
        currentSymTableId = 1;
        $$->threeACCode.insert($$->threeACCode.end(), $4->threeACCode.begin(), $4->threeACCode.end());
        $4->threeACCode.clear();
    }
    $$->children.push_back($1);
    $$->children.push_back($2->children[0]);
    $$->children.push_back($2->children[1]);
    $$->children.push_back($2->children[2]);
    $$->children.push_back($3);
    $$->children.push_back($4);
    
}
| Modifiers key_class_super ClassBody
{   
    if(isDot)
        $$ = new Node("NormalClassDeclaration");
    else{
        $$ = new Node($2->id.c_str(), "NormalClassDeclaration", yylineno);
        currentSymTableId = 1;
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
    }
    $$->children.push_back($1);
    $$->children.push_back($2->children[0]);
    $$->children.push_back($2->children[1]);
    $$->children.push_back($2->children[2]);
    $$->children.push_back($3);

}
| Modifiers key_class Interfaces ClassBody
{
    if(isDot)
        $$ = new Node("NormalClassDeclaration");
    else
    {
        $$ = new Node($2->id.c_str(), "NormalClassDeclaration", yylineno);
        currentSymTableId = 1;
        $$->threeACCode.insert($$->threeACCode.end(), $4->threeACCode.begin(), $4->threeACCode.end());
        $4->threeACCode.clear();
    }
    $$->children.push_back($1);
    $$->children.push_back($2->children[0]);
    $$->children.push_back($2->children[1]);
    $$->children.push_back($3);
    $$->children.push_back($4);
}
| Modifiers key_class ClassBody
{
    if(isDot)
        $$ = new Node("NormalClassDeclaration");
    else
    {
        $$ = new Node($2->id.c_str(), "NormalClassDeclaration", yylineno);
        currentSymTableId = 1;
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
    }
    $$->children.push_back($1);
    $$->children.push_back($2->children[0]);
    $$->children.push_back($2->children[1]);
    $$->children.push_back($3);
}
| key_class_super Interfaces ClassBody
{
    if(isDot)
        $$ = new Node("NormalClassDeclaration");
    else
    {
        $$ = new Node($1->id.c_str(), "NormalClassDeclaration", yylineno);
        currentSymTableId = 1;
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
    }
    $$->children.push_back($1->children[0]);
    $$->children.push_back($1->children[1]);
    $$->children.push_back($1->children[2]);
    $$->children.push_back($2);
    $$->children.push_back($3);
    
}
| key_class_super ClassBody
{
    if(isDot)
        $$ = new Node("NormalClassDeclaration");
    else
    {
        $$ = new Node($1->id.c_str(), "NormalClassDeclaration", yylineno);
        currentSymTableId = 1;
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
    }
    $$->children.push_back($1->children[0]);
    $$->children.push_back($1->children[1]);
    $$->children.push_back($1->children[2]);
    $$->children.push_back($2);
}
| key_class Interfaces ClassBody
{
    if(isDot)
        $$ = new Node("NormalClassDeclaration");
    else
    {
        $$ = new Node($1->id.c_str(), "NormalClassDeclaration", yylineno);
        currentSymTableId = 1;
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
    }
    $$->children.push_back($1->children[0]);
    $$->children.push_back($1->children[1]);
    $$->children.push_back($2);
    $$->children.push_back($3);
    
}
| key_class ClassBody
{
    if(isDot)
        $$ = new Node("NormalClassDeclaration");
    else
    {
        $$ = new Node($1->id.c_str(), "NormalClassDeclaration", yylineno);
        currentSymTableId = 1;
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
    }
    $$->children.push_back($1->children[0]);
    $$->children.push_back($1->children[1]);
    $$->children.push_back($2);
    
}

Super : k_extends ClassType
{
    $$ = new Node("Super");
    $$->children.push_back(new Node("extends", "Keyword", yylineno));
    $$->children.push_back($2);
    if(!isDot){
        $$->symid = class_to_symboltable[$2->id];
        offset += symTables[1].entries[$2->id][0].offset;
    }
}

Interfaces : k_implements InterfaceTypeList
{
    $$ = new Node("Interfaces");
    $$->children.push_back(new Node("implements", "Keyword", yylineno));
    $$->children.push_back($2);
}

InterfaceTypeList : InterfaceType
{
    $$ = $1;
}
| InterfaceTypeList s_comma InterfaceType
{
    $$ = new Node("InterfaceTypeList");
    $$->children.push_back($1);
    $$->children.push_back(new Node(",", "Separator", yylineno));
    $$->children.push_back($3);
}

ClassBody : s_open_curly_bracket ClassBodyDeclarations s_close_curly_bracket
{
    $$ = new Node("ClassBody");

    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node("}", "Separator", yylineno));
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
    }
}
| s_open_curly_bracket s_close_curly_bracket
{
    $$ = new Node("ClassBody");
    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back(new Node("}", "Separator", yylineno));
}

ClassBodyDeclarations : ClassBodyDeclaration
{
    $$ = $1;
}
| ClassBodyDeclarations ClassBodyDeclaration
{
    $$ = new Node("ClassBodyDeclarations");
    $$->children.push_back($1);
    $$->children.push_back($2);
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $1->threeACCode.clear();
        $2->threeACCode.clear();
    }
}

ClassBodyDeclaration : ClassMemberDeclaration
{
    $$ = $1;

}
| StaticInitializer
{
    $$ = $1;
    isPrivate.clear();
}
| ConstructorDeclaration
{
    $$ = $1;
    if (!isDot)
    {
        currentSymTableId = symTables[currentSymTableId].parentID;
        if(symTables[currentSymTableId].entries[$1->id.c_str()].empty())
            symTables[currentSymTableId].insertSymEntry($1->id.c_str(), vt[0], $1->lineno, fsize, true);
        vt.clear();
        vfs.clear();
        fsize = 0;
        isPrivate.clear();
        islocal = false;
    }
}

ClassMemberDeclaration : FieldDeclaration
{
    $$ = $1;
    isPrivate.clear();
}
| MethodDeclaration
{
    $$ = $1;
    if(!isDot){
        isPrivate.clear();
        islocal = false;
    }
}

FieldDeclaration : Modifiers Type VariableDeclaratorList s_semicolon
{
    $$ = new Node("FieldDeclaration");
    $$->children.push_back($1);
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back(new Node(";", "Separator", yylineno));
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        t = VOID;
        sz = 0;
        fsize = 0;
        isarr = false;
        tcounter = 0;
        isstatic = false;
        isfinal = false;
    }
}
| Type VariableDeclaratorList s_semicolon
{
    $$ = new Node("FieldDeclaration");
    $$->children.push_back($1);
    $$->children.push_back($2);
    $$->children.push_back(new Node(";", "Separator", yylineno));
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
    }
    t = VOID;
    sz = 0;
    fsize = 0;
    isarr = false;
    tcounter = 1;
    isstatic = false;
    isfinal = false;
}

VariableDeclaratorList : VariableDeclarator
{
    $$ = $1;
}
| VariableDeclaratorList s_comma VariableDeclarator
{
    $$ = new Node("VariableDeclaratorList");
    $$->children.push_back($1);
    $$->children.push_back(new Node(",", "Separator", yylineno));
    $$->children.push_back($3);
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $1->threeACCode.clear();
        $3->threeACCode.clear();
    }
}

VariableDeclarator : VariableDeclaratorId
{
    $$ = $1;
}
| VariableDeclaratorId o_assign VariableInitializer
{   
    if (!isDot)
    {
        $$ = new Node($1->id.c_str(), "VariableDeclarator", yylineno);
        if (widen(t, $3->type) != t)
        {
            yyerror("Type Mismatch in Variable Declarator");
            exit(0);
        }
        if ($3->sz != $1->sz)
        {   
            yyerror("Size Mismatch in Variable Declarator");
            exit(0);
        }
        if(islocal){
            $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
            $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
            if(t > $3->type){
                $$->threeACCode.push_back("\tt" + to_string(tcounter) + " = cast_to_" + enum_types[t] + " " + $3->field);
                $$->threeACCode.push_back("\t"+ $1->field + " = t" + to_string(tcounter++));
            }
            else
                $$->threeACCode.push_back("\t"+ $1->field + " = " + $3->field);
            if(isarr && arrinit.size()>0){
                for(int i=0;i<arrinit.size();i++){
                    $$->threeACCode.push_back("\tt" + to_string(tcounter) + " = " + $1->field);
                    $$->threeACCode.push_back("\tt"+ to_string(tcounter) + " = t" + to_string(tcounter) + " + " + to_string(i*offsetVal[t]));
                    $$->threeACCode.push_back("\t(t" + to_string(tcounter++) + ") = " + arrinit[i]);
                }
                arrinit.clear();
            }
        }
        $1->threeACCode.clear();
        $3->threeACCode.clear();
        vector<struct symEntry> *s = symTables[currentSymTableId].getSymEntry($1->id);
        if (!s)
        {
            yyerror("Variable not declared");
            exit(0);
        }
        if(vs.size() + 1 == (*s).size())
            for(int i=0;i<vs.size();i++){
                (*s)[i+1].dimsize = to_string(vs[i]);
            }

        if($3->arrdims.size() + 1 == (*s).size())
            for(int i=0;i< $3->arrdims.size();i++){
                (*s)[i+1].dimsize = $3->arrdims[i];
            }
        
        $3->arrdims.clear();
        vs.clear();
    }
    else
    {
        $$ = new Node("VariableDeclarator");
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("=", "Operator", yylineno));
    $$->children.push_back($3);
    
}

VariableDeclaratorId : Identifier
{
    $$ = new Node($1, "Identifier", yylineno);
    if (!isDot)
    {
        string s($1);
        if (islocal ? symTables[currentSymTableId].lookup(s) : symTables[currentSymTableId].grand_lookup(s))
        {   
            string s1 = "Variable " + s + " already declared in this scope";
            yyerror(s1.c_str());
            exit(0);
        }
        symTables[currentSymTableId].insertSymEntry(s, t, yylineno);
        if (!islocal){
            symTables[currentSymTableId].entries[s][0].isPrivate = (isPrivate == "private") ? true : false;
            symTables[currentSymTableId].entries[s][0].isStatic = isstatic;
            symTables[currentSymTableId].entries[s][0].isfinal = isfinal;
            symTables[currentSymTableId].entries[s][0].offset = offset;
            offset += offsetVal[t];
            symTables[1].entries[symTables[currentSymTableId].name][0].offset = offset;
        }
        else{
            $$->threeACCode.push_back("\tpush 0");
            localoffset += offsetVal[t]*isArgument;
            symTables[currentSymTableId].entries[s][0].offset = localoffset;
        }
        for (int i = 0; i < sz; i++)
        {
            symTables[currentSymTableId].insertSymEntry(s, t, yylineno, sz);
        }
        if (t == OBJECT)
        {
            vector<struct symEntry> *sentry = symTables[currentSymTableId].getSymEntry(s);
            (*sentry)[0].symid = class_to_symboltable[reftype];
            if(!islocal)
                offset += symTables[1].entries[reftype][0].offset;
            else{
                localoffset += symTables[1].entries[reftype][0].offset*isArgument;
                symTables[currentSymTableId].entries[s][0].offset = localoffset;
            }
        }
        int temp = symTables[currentSymTableId].entries[s][0].offset;
        if(temp > 0)
            $$->field = "[%rbp+" + to_string(temp) + "]";
        else
            $$->field = "[%rbp" + to_string(temp) + "]";
        $$->sz = sz;
        $$->type = t;
    }
}
| VariableDeclaratorId s_open_square_bracket s_close_square_bracket
{
    if (!isDot)
    {
        string s($1->id);
        $$ = new Node($1->id.c_str(), "VariableDeclaratorId", yylineno);
        symTables[currentSymTableId].insertSymEntry(s, t, yylineno);
        $$->sz = $1->sz + 1;
        $$->field = $1->field;
        ++sz;
        isarr = true;
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
    }
    else
        $$ = new Node("VariableDeclaratorId");
    $$->children.push_back($1);
    $$->children.push_back(new Node("[", "Separator", yylineno));
    $$->children.push_back(new Node("]", "Separator", yylineno));
}

VariableInitializer : Expression
{
    $$ = $1;
}
| ArrayInitializer
{
    $$ = $1;
    if(!isDot){
        if(ArrayArgumentDepth==0){
            arrinit.push_back($$->field);
            $$->threeACCode.push_back("\tt" + to_string(tcounter++) + " = " + to_string(arrinit.size()) + " * " + to_string(offsetVal[t]));
            $$->threeACCode.push_back("\tt" + to_string(tcounter) + " = allocate t" + to_string(tcounter-1));
            $$->field = "t" + to_string(tcounter);
        }
    }
}

MethodDeclaration : MethodHeader MethodBody
{
    $$ = new Node("MethodDeclaration");

    $$->children.push_back($1);
    $$->children.push_back($2);
    if (!isDot)
    {
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $$->threeACCode.push_back("");
        $1->threeACCode.clear();
        $2->threeACCode.clear();
        currentSymTableId = symTables[currentSymTableId].parentID;
        t = VOID;
        localoffset = 0;
        isstatic = false;
    }
}

MethodHeader : Modifiers Type MethodDeclarator Throws
{
    if (isDot)
        $$ = new Node("MethodHeader");
    else
        $$ = new Node($3->id.c_str(), "MethodHeader", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back($4);
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
    }
}
| Modifiers Type MethodDeclarator
{
    if (isDot)
        $$ = new Node("MethodHeader");
    else
        $$ = new Node($3->id.c_str(), "MethodHeader", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
    $$->children.push_back($3);
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        //t = $2->type;
    }
}
| Type MethodDeclarator Throws
{
    if (isDot)
        $$ = new Node("MethodHeader");
    else
        $$ = new Node($2->id.c_str(), "MethodHeader", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
    $$->children.push_back($3);
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
    }
}
| Type MethodDeclarator
{
    if (isDot)
        $$ = new Node("MethodHeader");
    else
        $$ = new Node($2->id.c_str(), "MethodHeader", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
    }
}
| Modifiers k_void MethodDeclarator Throws
{
    if (isDot)
        $$ = new Node("MethodHeader");
    else
        $$ = new Node($3->id.c_str(), "MethodHeader", yylineno);
    $$->children.push_back($1);
    $$->children.push_back(new Node("void", "Keyword", yylineno));
    $$->children.push_back($3);
    $$->children.push_back($4);
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        t = VOID;
    }
}
| Modifiers k_void MethodDeclarator
{
    if (isDot)
        $$ = new Node("MethodHeader");
    else
        $$ = new Node($3->id.c_str(), "MethodHeader", yylineno);
    $$->children.push_back($1);
    $$->children.push_back(new Node("void", "Keyword", yylineno));
    $$->children.push_back($3);
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        t = VOID;
    }
}
| k_void MethodDeclarator Throws
{
    if (isDot)
        $$ = new Node("MethodHeader");
    else
        $$ = new Node($2->id.c_str(), "MethodHeader", yylineno);
    $$->children.push_back(new Node("void", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back($3);
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
        t = VOID;
    }
}
| k_void MethodDeclarator
{
    if (isDot)
        $$ = new Node("MethodHeader");
    else
        $$ = new Node($2->id.c_str(), "MethodHeader", yylineno);
    $$->children.push_back(new Node("void", "Keyword", yylineno));
    $$->children.push_back($2);
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
        t = VOID;
    }
}
S_open_paren : s_open_paren
{
    if (!isDot)
    {
        vt.push_back(t);
        initializeSymTable(currentSymTableId);
        symTables[currentSymTableId].isfunction = true;
        islocal = true;
        sz = 0;
        isarr = 0;
        localoffset = 8;
        isArgument = 1;
    }
}
MethodDeclarator : Identifier S_open_paren FormalParameterList s_close_paren
{
    if (isDot)
        $$ = new Node("MethodDeclarator");
    else
        $$ = new Node($1, "MethodDeclarator", yylineno);
    $$->children.push_back(new Node($1, "Identifier", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    if (!isDot)
    {
        if (symTables[currentSymTableId].grand_lookup($1))
        {
            yyerror("Function already declared");
            exit(0);
        }
        symTables[currentSymTableId].insertSymEntry($1, vt[0], yylineno, fsize, true);
        symTables[currentSymTableId].entries[$1][0].isPrivate = (isPrivate == "private") ? true : false;
        symTables[currentSymTableId].entries[$1][0].isStatic = isstatic;
        symTables[symTables[currentSymTableId].parentID].insertSymEntry($1, vt[0], yylineno, fsize, true);
        symTables[symTables[currentSymTableId].parentID].entries[$1][0].isPrivate = (isPrivate == "private") ? true : false;
        symTables[symTables[currentSymTableId].parentID].entries[$1][0].isStatic = isstatic;
        for (int i = 1; i < vt.size(); i++)
        {
            symTables[currentSymTableId].insertSymEntry($1, vt[i], yylineno, vfs[i - 1]);
            symTables[symTables[currentSymTableId].parentID].insertSymEntry($1, vt[i], yylineno, vfs[i - 1]);
        }
        vt.clear();
        vfs.clear();
        fsize = 0;
        localoffset = 0;
        isArgument = -1;
        returnFunctionName = $1;
        if(symTables[symTables[currentSymTableId].parentID].name == entryClass && returnFunctionName == "main"){
            $$->threeACCode.push_back("main:");
            isMain = true;
        }
        else
            $$->threeACCode.push_back(className + "." + returnFunctionName + ":");
        $$->threeACCode.push_back("\tpush\t%rbp");
        $$->threeACCode.push_back("\t%rbp = %rsp");
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
    }
}
| Identifier S_open_paren s_close_paren
{
    if (isDot)
        $$ = new Node("MethodDeclarator");
    else
        $$ = new Node($1, "MethodDeclarator", yylineno);
    $$->children.push_back(new Node($1, "Identifier", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back(new Node(")", "Separator", yylineno));
    if (!isDot)
    {
        if (symTables[currentSymTableId].grand_lookup($1))
        {
            yyerror("Function already declared");
            exit(0);
        }
        symTables[currentSymTableId].insertSymEntry($1, vt[0], yylineno, fsize, true);
        symTables[currentSymTableId].entries[$1][0].isPrivate = (isPrivate == "private") ? true : false;
        symTables[currentSymTableId].entries[$1][0].isStatic = isstatic;
        symTables[symTables[currentSymTableId].parentID].insertSymEntry($1, vt[0], yylineno, fsize, true);
        symTables[symTables[currentSymTableId].parentID].entries[$1][0].isPrivate = (isPrivate == "private") ? true : false;
        symTables[symTables[currentSymTableId].parentID].entries[$1][0].isStatic = isstatic;
        for (int i = 1; i < vt.size(); i++)
        {
            symTables[currentSymTableId].insertSymEntry($1, vt[i], yylineno, vfs[i - 1]);
            symTables[symTables[currentSymTableId].parentID].insertSymEntry($1, vt[i], yylineno, vfs[i - 1]);
        }
        vt.clear();
        vfs.clear();
        fsize = 0;
        localoffset = 0;
        isArgument = -1;
        returnFunctionName = $1;
        if(symTables[symTables[currentSymTableId].parentID].name == entryClass && returnFunctionName == "main"){
            $$->threeACCode.push_back("main:");
            isMain = true;
        }
        else
            $$->threeACCode.push_back(className + "." + returnFunctionName + ":");
        $$->threeACCode.push_back("\tpush\t%rbp");
        $$->threeACCode.push_back("\t%rbp = %rsp");
    }
}
| MethodDeclarator s_open_square_bracket s_close_square_bracket
{
    if (isDot)
        $$ = new Node("MethodDeclarator");
    else
        $$ = new Node($1->id.c_str(), "MethodDeclarator", yylineno);
    $$->children.push_back($1);
    $$->children.push_back(new Node("[", "Separator", yylineno));
    $$->children.push_back(new Node("]", "Separator", yylineno));
    if (!isDot)
    {
        if (symTables[currentSymTableId].grand_lookup($1->id))
        {
            yyerror("Function already declared");
            exit(0);
        }
        symTables[currentSymTableId].insertSymEntry($1->id, vt[0], yylineno, fsize, true);
        symTables[currentSymTableId].entries[$1->id][0].isPrivate = (isPrivate == "private") ? true : false;
        symTables[currentSymTableId].entries[$1->id][0].isStatic = isstatic;
        symTables[symTables[currentSymTableId].parentID].insertSymEntry($1->id, vt[0], yylineno, fsize, true);
        symTables[symTables[currentSymTableId].parentID].entries[$1->id][0].isPrivate = (isPrivate == "private") ? true : false;
        symTables[symTables[currentSymTableId].parentID].entries[$1->id][0].isStatic = isstatic;
        for (int i = 1; i < vt.size(); i++)
        {
            symTables[currentSymTableId].insertSymEntry($1->id, vt[i], yylineno, vfs[i - 1]);
            symTables[symTables[currentSymTableId].parentID].insertSymEntry($1->id, vt[i], yylineno, vfs[i - 1]);
        }
        returnFunctionName = $1->id;
        if(symTables[symTables[currentSymTableId].parentID].name == entryClass && returnFunctionName == "main"){
            $$->threeACCode.push_back("main:");
            isMain = true;
        }
        else
            $$->threeACCode.push_back(className + "." + returnFunctionName + ":");
        $$->threeACCode.push_back("\tpush\t%rbp");
        $$->threeACCode.push_back("\t%rbp = %rsp");
    }
}

FormalParameterList : FormalParameter
{
    $$ = $1;
}
| FormalParameterList s_comma FormalParameter
{
    $$ = new Node("FormalParameterList");
    $$->children.push_back($1);
    $$->children.push_back(new Node(",", "Separator", yylineno));
    $$->children.push_back($3);
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $1->threeACCode.clear();
        $3->threeACCode.clear();
    }
}

FormalParameter : Type VariableDeclaratorId
{
    $$ = new Node("FormalParameter");
    $$->children.push_back($1);
    $$->children.push_back($2);
    if(!isDot){
        t = VOID;
        vt.push_back($1->type);
        vfs.push_back(sz);
        fsize -= sz;
        sz = 0;
        isarr = false;
    }
}
| k_final Type VariableDeclaratorId
{
    $$ = new Node("FormalParameter");
    $$->children.push_back(new Node("final", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back($3);
    if(!isDot){
        vt.push_back($2->type);
        vfs.push_back(sz);
        fsize -= sz;
        sz = 0;
        isarr = false;
        t = VOID;
    }
}

Throws : k_throws ClassTypeList
{
    $$ = new Node("Throws");
    $$->children.push_back(new Node("throws", "Keyword", yylineno));
    $$->children.push_back($2);
}

ClassTypeList : ClassType
{
    $$ = $1;
}
| ClassTypeList s_comma ClassType
{
    $$ = new Node("ClassTypeList");
    $$->children.push_back($1);
    $$->children.push_back(new Node(",", "Separator", yylineno));
    $$->children.push_back($3);
}

MethodBody : Block
{
    $$ = $1;
    if(!isDot){
        if(symTables[currentSymTableId].entries[returnFunctionName][0].type != VOID && !isreturn){
            yyerror("Function must return a value");
            exit(0);
        }
        if(!isreturn){
            $$->threeACCode.push_back("\t%rsp = %rbp");
            $$->threeACCode.push_back("\tpopq\t%rbp");
            $$->threeACCode.push_back("\tret");
        }
        isreturn = false;
    }
}

| s_semicolon
{
    $$ = new Node(";", "Separator", yylineno);
    if(!isDot){
        if(!isreturn){
            $$->threeACCode.push_back("\t%rsp = %rbp");
            $$->threeACCode.push_back("\tpopq\t%rbp");
            $$->threeACCode.push_back("\tret");
        }
        isreturn = false;
    }
}

StaticInitializer : k_static Block
{
    $$ = new Node("StaticInitializer");
    $$->children.push_back(new Node("static", "Keyword", yylineno));
    $$->children.push_back($2);
};

ConstructorDeclaration :

    Modifiers ConstructorDeclarator Throws ConstructorBody
{
    if (isDot)
        $$ = new Node("ConstructorDeclaration");
    else
    {
        $$ = new Node($2->id.c_str(), "ConstructorDeclaration", $2->lineno);
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $$->threeACCode.insert($$->threeACCode.end(), $4->threeACCode.begin(), $4->threeACCode.end());
        $$->threeACCode.push_back("");
        $2->threeACCode.clear();
        $4->threeACCode.clear();
        localoffset = 0;
        isstatic = 0;
    }
    $$->children.push_back($1);
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back($4);
}
| Modifiers ConstructorDeclarator ConstructorBody
{
    if (isDot)
        $$ = new Node("ConstructorDeclaration");
    else{
        $$ = new Node($2->id.c_str(), "ConstructorDeclaration", $2->lineno);
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $$->threeACCode.push_back("");
        $2->threeACCode.clear();
        $3->threeACCode.clear();
        localoffset = 0;
        isstatic = 0;
    }
    $$->children.push_back($1);
    $$->children.push_back($2);
    $$->children.push_back($3);
}
| ConstructorDeclarator Throws ConstructorBody
{
    if (isDot)
        $$ = new Node("ConstructorDeclaration");
    else{
        $$ = new Node($1->id.c_str(), "ConstructorDeclaration", $2->lineno);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $$->threeACCode.push_back("");
        $1->threeACCode.clear();
        $3->threeACCode.clear();
        localoffset = 0;
        isstatic = 0;
    }
    $$->children.push_back($1);
    $$->children.push_back($2);
    $$->children.push_back($3);
}
| ConstructorDeclarator ConstructorBody
{
    if (isDot)
        $$ = new Node("ConstructorDeclaration");
    else{
        $$ = new Node($1->id.c_str(), "ConstructorDeclaration", $2->lineno);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $$->threeACCode.push_back("");
        $1->threeACCode.clear();
        $2->threeACCode.clear();
        localoffset = 0;
        isstatic = 0;
    }
    $$->children.push_back($1);
    $$->children.push_back($2);
};

ConstructorDeclarator : SimpleName S_open_paren FormalParameterList s_close_paren
{
    if (isDot)
        $$ = new Node("ConstructorDeclarator");
    else
        $$ = new Node($1->id.c_str(), "ConstructorDeclarator", yylineno);
    $$->children.push_back($1);
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    if (!isDot)
    {
        if(className != $1->id)
        {
            yyerror("Constructor name does not match class name");
            exit(0);
        }
        symTables[currentSymTableId].insertSymEntry($1->id, vt[0], yylineno, fsize, true);
        symTables[currentSymTableId].entries[$1->id][0].isPrivate = (isPrivate == "private") ? true : false;
        symTables[currentSymTableId].entries[$1->id][0].isStatic = isstatic;
        symTables[symTables[currentSymTableId].parentID].insertSymEntry($1->id, vt[0], yylineno, fsize, true);
        symTables[symTables[currentSymTableId].parentID].entries[$1->id][0].isPrivate = (isPrivate == "private") ? true : false;
        symTables[symTables[currentSymTableId].parentID].entries[$1->id][0].isStatic = isstatic;
        for (int i = 1; i < vt.size(); i++)
        {
            symTables[currentSymTableId].insertSymEntry($1->id, vt[i], yylineno, vfs[i - 1]);
            symTables[symTables[currentSymTableId].parentID].insertSymEntry($1->id, vt[i], yylineno, vfs[i - 1]);
        }
        vt.clear();
        vfs.clear();
        fsize = 0;
        localoffset = 0;
        isArgument = -1;
        returnFunctionName = $1->id;
        $$->threeACCode.push_back(className + ".ctor" + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $$->threeACCode.push_back("\tpush\t%rbp");
        $$->threeACCode.push_back("\t%rbp = %rsp");
        $3->threeACCode.clear();
    }
}
| SimpleName S_open_paren s_close_paren
{
    if (isDot)
        $$ = new Node("ConstructorDeclarator");
    else
        $$ = new Node($1->id.c_str(), "ConstructorDeclarator", yylineno);

    $$->children.push_back($1);
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back(new Node(")", "Separator", yylineno));
    if (!isDot)
    {
        if(className != $1->id)
        {
            yyerror("Constructor name does not match class name");
            exit(0);
        }
        symTables[currentSymTableId].insertSymEntry($1->id, vt[0], yylineno, fsize, true);
        symTables[currentSymTableId].entries[$1->id][0].isPrivate = (isPrivate == "private") ? true : false;
        symTables[currentSymTableId].entries[$1->id][0].isStatic = isstatic;
        symTables[symTables[currentSymTableId].parentID].insertSymEntry($1->id, vt[0], yylineno, fsize, true);
        symTables[symTables[currentSymTableId].parentID].entries[$1->id][0].isPrivate = (isPrivate == "private") ? true : false;
        symTables[symTables[currentSymTableId].parentID].entries[$1->id][0].isStatic = isstatic;
        for (int i = 1; i < vt.size(); i++)
        {
            symTables[currentSymTableId].insertSymEntry($1->id, vt[i], yylineno, vfs[i - 1]);
            symTables[symTables[currentSymTableId].parentID].insertSymEntry($1->id, vt[i], yylineno, vfs[i - 1]);
        }
        vt.clear();
        vfs.clear();
        fsize = 0;
        localoffset = 0;
        isArgument = -1;
        returnFunctionName = $1->id;
        $$->threeACCode.push_back(className + ".ctor" + ":");
        $$->threeACCode.push_back("\tpush\t%rbp");
        $$->threeACCode.push_back("\t%rbp = %rsp");
    }

};

ConstructorBody : s_open_curly_bracket s_close_curly_bracket
{
    $$ = new Node("ConstructorBody");
    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back(new Node("}", "Separator", yylineno));
    if(!isDot){
        if(!isreturn){
            $$->threeACCode.push_back("\t%rsp = %rbp");
            $$->threeACCode.push_back("\tpopq\t%rbp");
            $$->threeACCode.push_back("\tret");
        }
        isreturn = false;
    }
}
| s_open_curly_bracket BlockStatements s_close_curly_bracket
{
    $$ = new Node("ConstructorBody");
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
        if(!isreturn){
           $$->threeACCode.push_back("\t%rsp = %rbp");
            $$->threeACCode.push_back("\tpopq\t%rbp");
            $$->threeACCode.push_back("\tret");
        }
        isreturn = false;
    }
    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node("}", "Separator", yylineno));
}
| s_open_curly_bracket ExplicitConstructorInvocation s_close_curly_bracket
{
    $$ = new Node("ConstructorBody");
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
        if(!isreturn){
            $$->threeACCode.push_back("\t%rsp = %rbp");
            $$->threeACCode.push_back("\tpopq\t%rbp");
            $$->threeACCode.push_back("\tret");
        }
        isreturn = false;
    }
    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node("}", "Separator", yylineno));
}
| s_open_curly_bracket ExplicitConstructorInvocation BlockStatements s_close_curly_bracket
{
    $$ = new Node("ConstructorBody");
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        if(!isreturn){
            $$->threeACCode.push_back("\t%rsp = %rbp");
            $$->threeACCode.push_back("\tpopq\t%rbp");
            $$->threeACCode.push_back("\tret");
        }
        isreturn = false;
    }
    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back(new Node("}", "Separator", yylineno));
};
ExplicitConstructorInvocation : k_this s_open_paren ArgumentList s_close_paren s_semicolon
{
    $$ = new Node("ExplicitConstructorInvocation");
    $$->children.push_back(new Node("this", "Keyword", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));
}
| k_this s_open_paren s_close_paren s_semicolon
{
    $$ = new Node("ExplicitConstructorInvocation");
    $$->children.push_back(new Node("this", "Keyword", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));
}
| k_super s_open_paren ArgumentList s_close_paren s_semicolon
{
    $$ = new Node("ExplicitConstructorInvocation");
    $$->children.push_back(new Node("super", "Keyword", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));
}
| k_super s_open_paren s_close_paren s_semicolon
{
    $$ = new Node("ExplicitConstructorInvocation");
    $$->children.push_back(new Node("super", "Keyword", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));
};

EnumDeclaration : Modifiers k_enum Identifier ClassImplements EnumBody
{
    $$ = new Node("EnumDeclaration");
    $$->children.push_back($1);
    $$->children.push_back(new Node("enum", "Keyword", yylineno));
    $$->children.push_back(new Node($3, "Identifier", yylineno));
    $$->children.push_back($4);
    $$->children.push_back($5);
}
| Modifiers k_enum Identifier EnumBody
{
    $$ = new Node("EnumDeclaration");
    $$->children.push_back($1);
    $$->children.push_back(new Node("enum", "Keyword", yylineno));
    $$->children.push_back(new Node($3, "Identifier", yylineno));
    $$->children.push_back($4);
}
| k_enum Identifier ClassImplements EnumBody
{
    $$ = new Node("EnumDeclaration");
    $$->children.push_back(new Node("enum", "Keyword", yylineno));
    $$->children.push_back(new Node($2, "Identifier", yylineno));
    $$->children.push_back($3);
    $$->children.push_back($4);
}
| k_enum Identifier EnumBody
{
    $$ = new Node("EnumDeclaration");
    $$->children.push_back(new Node("enum", "Keyword", yylineno));
    $$->children.push_back(new Node($2, "Identifier", yylineno));
    $$->children.push_back($3);
}

ClassImplements : k_implements InterfaceTypeList
{
    $$ = new Node("ClassImplements");
    $$->children.push_back(new Node("implements", "Keyword", yylineno));
    $$->children.push_back($2);
}

EnumBody : s_open_curly_bracket EnumConstantList s_comma EnumBodyDeclarations s_close_curly_bracket
{
    $$ = new Node("EnumBody");

    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node(",", "Separator", yylineno));
    $$->children.push_back($4);
    $$->children.push_back(new Node("}", "Separator", yylineno));
}
| s_open_curly_bracket EnumConstantList s_comma s_close_curly_bracket
{
    $$ = new Node("EnumBody");

    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node("}", "Separator", yylineno));
}
| s_open_curly_bracket EnumConstantList EnumBodyDeclarations s_close_curly_bracket
{
    $$ = new Node("EnumBody");

    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back(new Node("}", "Separator", yylineno));
}
| s_open_curly_bracket EnumConstantList s_close_curly_bracket
{
    $$ = new Node("EnumBody");

    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node("}", "Separator", yylineno));
}
| s_open_curly_bracket s_comma EnumBodyDeclarations s_close_curly_bracket
{
    $$ = new Node("EnumBody");

    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back(new Node(",", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node("}", "Separator", yylineno));
}
| s_open_curly_bracket s_comma s_close_curly_bracket
{
    $$ = new Node("EnumBody");

    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back(new Node(",", "Separator", yylineno));
    $$->children.push_back(new Node("}", "Separator", yylineno));
}
| s_open_curly_bracket EnumBodyDeclarations s_close_curly_bracket
{
    $$ = new Node("EnumBody");

    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node("}", "Separator", yylineno));
}
| s_open_curly_bracket s_close_curly_bracket
{
    $$ = new Node("EnumBody");

    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back(new Node("}", "Separator", yylineno));
}

EnumBodyDeclarations : s_semicolon
{
    $$ = new Node(";", "Separator", yylineno);
}
| s_semicolon ClassBodyDeclarations
{
    $$ = new Node("EnumBodyDeclarations");
    $$->children.push_back(new Node(";", "Separator", yylineno));
    $$->children.push_back($2);
}

EnumConstantList : EnumConstant { $$ = $1; }
| EnumConstantList s_comma EnumConstant
{
    $$ = new Node("EnumConstantList");
    $$->children.push_back($1);
    $$->children.push_back(new Node(",", "Separator", yylineno));
    $$->children.push_back($3);
}

EnumConstant : Identifier s_open_paren ArgumentList s_close_paren ClassBody
{
    $$ = new Node("EnumConstant");
    $$->children.push_back(new Node($1, "Identifier", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($5);
}
| Identifier s_open_paren s_close_paren ClassBody
{
    $$ = new Node("EnumConstant");
    $$->children.push_back(new Node($1, "Identifier", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($4);
}
| Identifier s_open_paren ArgumentList s_close_paren
{
    $$ = new Node("EnumConstant");
    $$->children.push_back(new Node($1, "Identifier", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node(")", "Separator", yylineno));
}
| Identifier s_open_paren s_close_paren
{
    $$ = new Node("EnumConstant");
    $$->children.push_back(new Node($1, "Identifier", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back(new Node(")", "Separator", yylineno));
}
| Identifier ClassBody
{
    $$ = new Node("EnumConstant");
    $$->children.push_back(new Node($1, "Identifier", yylineno));
    $$->children.push_back($2);
}
| Identifier
{
    $$ = new Node($1, "Identifier", yylineno);
}
// ---------------------------- Production 9 -----------------------

InterfaceDeclaration : Modifiers k_interface Identifier ExtendsInterfaces InterfaceBody
{
    $$ = new Node("InterfaceDeclaration");
    $$->children.push_back($1);
    $$->children.push_back(new Node("interface", "Keyword", yylineno));
    $$->children.push_back(new Node($3, "Identifier", yylineno));
    $$->children.push_back($4);
    $$->children.push_back($5);
}
| Modifiers k_interface Identifier InterfaceBody
{
    $$ = new Node("InterfaceDeclaration");
    $$->children.push_back($1);
    $$->children.push_back(new Node("interface", "Keyword", yylineno));
    $$->children.push_back(new Node($3, "Identifier", yylineno));
    $$->children.push_back($4);
}
| k_interface Identifier ExtendsInterfaces InterfaceBody
{
    $$ = new Node("InterfaceDeclaration");
    $$->children.push_back(new Node("interface", "Keyword", yylineno));
    $$->children.push_back(new Node($2, "Identifier", yylineno));
    $$->children.push_back($3);
    $$->children.push_back($4);
}
| k_interface Identifier InterfaceBody
{
    $$ = new Node("InterfaceDeclaration");
    $$->children.push_back(new Node("interface", "Keyword", yylineno));
    $$->children.push_back(new Node($2, "Identifier", yylineno));
    $$->children.push_back($3);
};

ExtendsInterfaces : k_extends InterfaceType
{
    $$ = new Node("ExtendsInterfaces");
    $$->children.push_back(new Node("extends", "Keyword", yylineno));
    $$->children.push_back($2);
}
| ExtendsInterfaces s_comma InterfaceType
{
    $$ = new Node("ExtendsInterfaces");
    $$->children.push_back($1);
    $$->children.push_back(new Node("comma", "Separator", yylineno));
    $$->children.push_back($3);
};

InterfaceBody : s_open_curly_bracket InterfaceMemberDeclarations s_close_curly_bracket
{
    $$ = new Node("InterfaceBody");

    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node("}", "Separator", yylineno));
}
| s_open_curly_bracket s_close_curly_bracket
{
    $$ = new Node("InterfaceBody");
    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back(new Node("}", "Separator", yylineno));
};

InterfaceMemberDeclarations : InterfaceMemberDeclaration
{
    $$ = new Node("InterfaceMemberDeclarations");
    $$->children.push_back($1);
}
| InterfaceMemberDeclarations InterfaceMemberDeclaration
{
    $$ = new Node("InterfaceMemberDeclarations");
    $$->children.push_back($1);
    $$->children.push_back($2);
};

InterfaceMemberDeclaration : ConstantDeclaration
{
    $$ = new Node("InterfaceMemberDeclaration");
    $$->children.push_back($1);
}
| AbstractMethodDeclaration
{
    $$ = new Node("InterfaceMemberDeclaration");
    $$->children.push_back($1);
};

ConstantDeclaration : FieldDeclaration
{
    $$ = new Node("ConstantDeclaration");
    $$->children.push_back($1);
};

AbstractMethodDeclaration : MethodHeader s_semicolon
{
    $$ = new Node("AbstractMethodDeclaration");
    $$->children.push_back($1);
    $$->children.push_back(new Node(";", "Separator", yylineno));
    if (!isDot)
    {
        currentSymTableId = symTables[currentSymTableId].parentID;
        symTables[currentSymTableId].insertSymEntry($1->id.c_str(), vt[0], yylineno, fsize, true);
        for (int i = 1; i < vt.size(); i++)
        {
            symTables[currentSymTableId].insertSymEntry($1->id.c_str(), vt[i], yylineno, vfs[i - 1]);
        }
        vt.clear();
        vfs.clear();
        fsize = 0;
    }
};

// ------------------------------- Production 10 ---------------------

ArrayInitializer : array_s_open_curly_bracket VariableInitializerList s_close_curly_bracket
{
    $$ = new Node("ArrayInitializer");
    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node("}", "Separator", yylineno));
    if (!isDot)
    {
        if (vs[ArrayArgumentDepth - 1] && (vs[ArrayArgumentDepth - 1] != $2->sz))
        {
            yyerror("Error in number of arguments for array");
            exit(0);
        }
        vs[ArrayArgumentDepth - 1] = $2->sz;
        ArrayArgumentDepth--;
        $$->sz = vs.size();
        $$->field = arrinit.back();
        $$->type = t;
        arrinit.pop_back();
    }
}
| array_s_open_curly_bracket s_close_curly_bracket
{
    $$ = new Node("ArrayInitializer");

    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back(new Node("}", "Separator", yylineno));
    if (!isDot)
    {
        if (vs[ArrayArgumentDepth - 1])
        {
            yyerror("Error in number of arguments for array");
            exit(0);
        }
        vs[ArrayArgumentDepth - 1] = 0;
        ArrayArgumentDepth--;
        $$->type = t;
        $$->sz = vs.size();
    }
};
array_s_open_curly_bracket : s_open_curly_bracket
{
    if (!isDot)
    {
        ArrayArgumentDepth++;
        if (ArrayArgumentDepth > sz)
        {
            yyerror("Excess Dimensions used");
            exit(0);
        }
        if (ArrayArgumentDepth > vs.size())
            vs.push_back(0);
    }
}
VariableInitializerList : VariableInitializer
{
    $$ = $1;
    $$->sz = 1;
    if (!isDot )
    {   
        if(widen($1->type,t)!=t){
            yyerror("Type mismatch in VariableIntializer");
            exit(0);
        }
        if(isarr){
            arrinit.push_back($1->field);
        }
        $$->type = t;
    }
}
| VariableInitializerList s_comma VariableInitializer
{
    $$ = new Node("VariableInitializerList");
    $$->children.push_back($1);
    $$->children.push_back(new Node(",", "Separator", yylineno));
    $$->children.push_back($3);
    $$->sz = $1->sz + 1;
    if (!isDot)
    {   
        if(widen($3->type, t) != t){
            yyerror("Type mismatch in VariableIntializer");
            exit(0);
        }
        if(isarr){
            arrinit.push_back($3->field);
        }
        $$->type = t;
    }
};

// ------------------------ Production 14 -------------------------------------

Block : s_open_curly_bracket s_close_curly_bracket
{
    $$ = new Node("Block");
    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back(new Node("}", "Separator", yylineno));
}
| s_open_curly_bracket BlockStatements s_close_curly_bracket
{
    $$ = new Node("Block");
    $$->children.push_back(new Node("{", "Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node("}", "Separator", yylineno));
    $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
    threeAC.insert(threeAC.end(), $2->threeACCode.begin(), $2->threeACCode.end());
    $2->threeACCode.clear();
    $$->field = $2->field;
};

BlockStatements : BlockStatement
{
    $$ = $1;
}
| BlockStatements BlockStatement
{
    $$ = new Node("BlockStatements");
    $$->children.push_back($1);
    $$->children.push_back($2);
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
        $$->field = $2->field;
    }
};

BlockStatement : LocalVariableDeclarationStatement
{
    $$ = $1;
}
| Statement
{
    $$ = $1;
};

LocalVariableDeclarationStatement : LocalVariableDeclaration s_semicolon
{
    $$ = new Node("LocalVariableDeclarationStatement");
    $$->children.push_back($1);
    $$->children.push_back(new Node(";", "Separator", yylineno));
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        isarr = false;
        sz = 0;
        fsize = 0;
        t = VOID;
        tcounter = 0;
    }
};

LocalVariableDeclaration : k_final LocalVariableType VariableDeclaratorList
{
    $$ = new Node("LocalVariableDeclaration");
    $$->children.push_back(new Node("final", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back($3);
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
    }
}
| LocalVariableType VariableDeclaratorList
{
    $$ = new Node("LocalVariableDeclaration");
    $$->children.push_back($1);
    $$->children.push_back($2);
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
    }
};

LocalVariableType : Type
{
    $$ = $1;
}
| k_var
{
    $$ = new Node("var", "Keyword", VAR);
}

Statement : StatementWithoutTrailingSubstatement
{
    $$ = $1;
}
| LabeledStatement
{
    $$ = $1;
}
| IfThenStatement
{
    $$ = $1;
}
| IfThenElseStatement
{
    $$ = $1;
}
| WhileStatement
{
    $$ = $1;
}
| ForStatement
{
    $$ = $1;
};

StatementNoShortIf : StatementWithoutTrailingSubstatement
{
    $$ = $1;
}
| LabeledStatementNoShortIf
{
    $$ = $1;
}
| IfThenElseStatementNoShortIf
{
    $$ = $1;
}
| WhileStatementNoShortIf
{
    $$ = $1;
}
| ForStatementNoShortIf
{
    $$ = $1;
};

StatementWithoutTrailingSubstatement : Block
{
    $$ = $1;
}
| EmptyStatement
{
    $$ = $1;
}
| ExpressionStatement
{
    $$ = $1;
}
| BreakStatement
{
    $$ = $1;
}
| ContinueStatement
{
    $$ = $1;
}
| ReturnStatement
{
    $$ = $1;
}
| SynchronizedStatement
{
    $$ = $1;
}
| ThrowStatement
{
    $$ = $1;
}
| TryStatement
{
    $$ = $1;
};

EmptyStatement : s_semicolon
{
    $$ = new Node(";", "Separator", yylineno);
};

LabeledStatement :

    Identifier o_colon Statement
{
    $$ = new Node("LabeledStatement");
    $$->children.push_back(new Node($1, "Identifier", yylineno));
    $$->children.push_back(new Node(":", "Operator", yylineno));
    $$->children.push_back($3);
};

LabeledStatementNoShortIf :

    Identifier o_colon StatementNoShortIf
{
    $$ = new Node("LabeledStatementNoShortIf");
    $$->children.push_back(new Node($1, "Identifier", yylineno));
    $$->children.push_back(new Node(":", "Operator", yylineno));
    $$->children.push_back($3);
}

ExpressionStatement : StatementExpression s_semicolon
{
    $$ = new Node("ExpressionStatement");
    $$->children.push_back($1);
    $$->children.push_back(new Node(";", "Separator", yylineno));
    if(!isDot){
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->field = $1->field;
        tcounter = 0;
    }
};

StatementExpression : Assignment
{
    $$ = $1;
}
| PreIncrementExpression
{
    $$ = $1;
}
| PreDecrementExpression
{
    $$ = $1;
}
| PostIncrementExpression
{
    $$ = $1;
}
| PostDecrementExpression
{
    $$ = $1;
}
| MethodInvocation
{
    $$ = $1;
}
| ClassInstanceCreationExpression
{
    $$ = $1;
};

if_invoke_paren : k_if s_open_paren
{
    $$ = new Node("if_invoke_paren");
    $$->children.push_back(new Node("if", "Keyword", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    if (!isDot)
    {
        initializeSymTable(currentSymTableId);
    }
}

IfThenStatement : if_invoke_paren Expression s_close_paren Statement
{
    $$ = new Node("IfThenStatement");
    $$->children.push_back($1->children[0]);
    $$->children.push_back($1->children[1]);
    $$->children.push_back($2);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($4);
    if (!isDot)
    {   
        if ($2->type != BOOL)
        {
            yyerror("If statement expression must have the type boolean");
            exit(0);
        }
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
        $$->threeACCode.push_back("\tif " + $2->field + " goto L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(lcounter-1));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $4->threeACCode.begin(), $4->threeACCode.end());
        $4->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("L" + to_string(lcounter-1) + ":");
        lcounter -= 2;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
    }
}

IfThenElseStatement : if_invoke_paren Expression s_close_paren StatementNoShortIf invoke_else Statement
{
    $$ = new Node("IfThenElseStatement");
    $$->children.push_back($1->children[0]);
    $$->children.push_back($1->children[1]);
    $$->children.push_back($2);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($4);
    $$->children.push_back(new Node("else", "Keyword", yylineno));
    $$->children.push_back($6);
    if (!isDot)
    {
        if ($2->type != BOOL)
        {
            yyerror("If statement expression must have the type boolean");
            exit(0);
        }
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
        $$->threeACCode.push_back("\tif " + $2->field + " goto L" + to_string(lcounter));
        $$->threeACCode.insert($$->threeACCode.end(), $6->threeACCode.begin(), $6->threeACCode.end());
        $6->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(lcounter-1));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $4->threeACCode.begin(), $4->threeACCode.end());
        $6->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(),$5->threeACCode.begin(), $5->threeACCode.end());
        $5->threeACCode.clear();
        $$->threeACCode.push_back("L" + to_string(lcounter-1) + ":");
        lcounter -= 2;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
    }
}

invoke_else : k_else {
    $$ = new Node("invoke_else");
    if (!isDot)
    {   
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        initializeSymTable(currentSymTableId);
    }
}

IfThenElseStatementNoShortIf : if_invoke_paren Expression s_close_paren StatementNoShortIf invoke_else StatementNoShortIf
{
    $$ = new Node("IfThenElseStatementNoShortIf");
    $$->children.push_back($1->children[0]);
    $$->children.push_back($1->children[1]);
    $$->children.push_back($2);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($4);
    $$->children.push_back(new Node("else", "Keyword", yylineno));
    $$->children.push_back($6);
    if (!isDot)
    {
        if ($2->type != BOOL)
        {
            yyerror("If statement expression must have the type boolean");
            exit(0);
        }
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
        $$->threeACCode.push_back("\tif " + $2->field + " goto L" + to_string(lcounter));
        $$->threeACCode.insert($$->threeACCode.end(), $6->threeACCode.begin(), $6->threeACCode.end());
        $6->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(lcounter-1));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $4->threeACCode.begin(), $4->threeACCode.end());
        $4->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(),$5->threeACCode.begin(), $5->threeACCode.end());
        $5->threeACCode.clear();
        $$->threeACCode.push_back("L" + to_string(lcounter-1) + ":");
        lcounter -= 2;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
    }
}

invoke_paren : s_open_paren
{
    if (!isDot)
    {
        initializeSymTable(currentSymTableId);
        loopscope.push_back(currentSymTableId);
        loopscope.push_back(lcounter);
        lcounter--;
    }
}

WhileStatement : k_while invoke_paren Expression s_close_paren Statement
{
    $$ = new Node("WhileStatement");
    $$->children.push_back(new Node("while", "Keyword", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($5);
    if (!isDot)
    {
        if ($3->type != BOOL)
        {
            yyerror("While statement expression must have the type boolean");
            exit(0);
        }
        $$->threeACCode.push_back("L" + to_string(currentSymTableId) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("\tif " + $3->field + " goto " + "L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $5->threeACCode.begin(), $5->threeACCode.end());
        $5->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(currentSymTableId));
        $$->threeACCode.push_back("L" + to_string(loopscope.back()) + ":");
        lcounter -= 1;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        loopscope.pop_back();
        loopscope.pop_back();
    }
};

WhileStatementNoShortIf : k_while invoke_paren Expression s_close_paren StatementNoShortIf
{
    $$ = new Node("WhileStatementNoShortIf");
    $$->children.push_back(new Node("while", "Keyword", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($5);
    if (!isDot)
    {
        if ($3->type != BOOL)
        {
            yyerror("While statement expression must have the type boolean");
            exit(0);
        }
        $$->threeACCode.push_back("L" + to_string(currentSymTableId) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("\tif " + $3->field + " goto " + "L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $5->threeACCode.begin(), $5->threeACCode.end());
        $5->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(currentSymTableId));
        $$->threeACCode.push_back("L" + to_string(loopscope.back()) + ":");
        lcounter -= 1;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        loopscope.pop_back();  
        loopscope.pop_back();  
    }
};

ForStatement : BasicForStatement { $$ = $1; }
| EnhancedForStatement { $$ = $1; }
ForStatementNoShortIf : BasicForStatementNoShortIf { $$ = $1; }
| EnhancedForStatementNoShortIf { $$ = $1; }

BasicForStatement : k_for invoke_paren s_semicolon s_semicolon s_close_paren Statement
{
    $$ = new Node("BasicForStatement");

    $$->children.push_back(new Node("for", "Keyword", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($6);
    if (!isDot)
    {
        $$->threeACCode.push_back("L" + to_string(currentSymTableId) + ":");
        $$->threeACCode.push_back("\tif 1 goto L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $6->threeACCode.begin(), $6->threeACCode.end());
        $6->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(currentSymTableId));
        $$->threeACCode.push_back("L" + to_string(loopscope.back()) + ":");
        lcounter -= 1;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        loopscope.pop_back();
        loopscope.pop_back();
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
    if (!isDot)
    {
        $$->threeACCode.push_back("L" + to_string(currentSymTableId) + ":");
        $$->threeACCode.push_back("\tif 1 goto L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $7->threeACCode.begin(), $7->threeACCode.end());
        $7->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(currentSymTableId));
        $$->threeACCode.push_back("L" + to_string(loopscope.back()) + ":");
        lcounter -= 1;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        loopscope.pop_back();
        loopscope.pop_back();
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
    if (!isDot)
    {
        if ($4->type != BOOL)
        {
            yyerror("Expression in for loop must be of type bool");
            exit(0);
        }
        if ($4->sz != 0)
        {
            yyerror("Expression in for loop must be of size 0");
            exit(0);
        }
        $$->threeACCode.push_back("L" + to_string(currentSymTableId) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $4->threeACCode.begin(), $4->threeACCode.end());
        $4->threeACCode.clear();
        $$->threeACCode.push_back("\tif " + $4->field + " goto L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $7->threeACCode.begin(), $7->threeACCode.end());
        $7->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(currentSymTableId));
        $$->threeACCode.push_back("L" + to_string(loopscope.back()) + ":");
        lcounter -= 1;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        loopscope.pop_back();
        loopscope.pop_back();

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
    if (!isDot)
    {
        if ($4->type != BOOL)
        {
            yyerror("Expression in for loop must be of type bool");
            exit(0);
        }
        if ($4->sz != 0)
        {
            yyerror("Expression in for loop must be of size 0");
            exit(0);
        }
        $$->threeACCode.push_back("L" + to_string(currentSymTableId) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $4->threeACCode.begin(), $4->threeACCode.end());
        $4->threeACCode.clear();
        $$->threeACCode.push_back("\tif " + $4->field + " goto L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $8->threeACCode.begin(), $8->threeACCode.end());
        $8->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $6->threeACCode.begin(), $6->threeACCode.end());
        $6->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(currentSymTableId));
        $$->threeACCode.push_back("L" + to_string(loopscope.back()) + ":");
        lcounter -= 1;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        loopscope.pop_back();
        loopscope.pop_back();
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
    if (!isDot)
    {
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("L" + to_string(currentSymTableId) + ":");
        $$->threeACCode.push_back("\tif 1 goto L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $7->threeACCode.begin(), $7->threeACCode.end());
        $7->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(currentSymTableId));
        $$->threeACCode.push_back("L" + to_string(loopscope.back()) + ":");
        lcounter -= 1;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        loopscope.pop_back();
        loopscope.pop_back();
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
    if (!isDot)
    {
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("L" + to_string(currentSymTableId) + ":");
        $$->threeACCode.push_back("\tif 1 goto L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $8->threeACCode.begin(), $8->threeACCode.end());
        $8->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $6->threeACCode.begin(), $6->threeACCode.end());
        $6->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(currentSymTableId));
        $$->threeACCode.push_back("L" + to_string(loopscope.back()) + ":");
        lcounter -= 1;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        loopscope.pop_back();
        loopscope.pop_back();
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
    if (!isDot)
    {
        if ($5->type != BOOL)
        {
            yyerror("Expression in for loop must be of type bool");
            exit(0);
        }
        if ($5->sz != 0)
        {
            yyerror("Expression in for loop must be of size 0");
            exit(0);
        }
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("L" + to_string(currentSymTableId) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $5->threeACCode.begin(), $5->threeACCode.end());
        $5->threeACCode.clear();
        $$->threeACCode.push_back("\tif " + $5->field + " goto L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $8->threeACCode.begin(), $8->threeACCode.end());
        $8->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(currentSymTableId));
        $$->threeACCode.push_back("L" + to_string(loopscope.back()) + ":");
        lcounter -= 1;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        loopscope.pop_back();
        loopscope.pop_back();
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
    if (!isDot)
    {
        if ($5->type != BOOL)
        {
            yyerror("Expression in for loop must be of type bool");
            exit(0);
        }
        if ($5->sz != 0)
        {
            yyerror("Expression in for loop must be of size 0");
            exit(0);
        }
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("L" + to_string(currentSymTableId) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $5->threeACCode.begin(), $5->threeACCode.end());
        $5->threeACCode.clear();
        $$->threeACCode.push_back("\tif " + $5->field + " goto L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $9->threeACCode.begin(), $9->threeACCode.end());
        $9->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $7->threeACCode.begin(), $7->threeACCode.end());
        $7->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(currentSymTableId));
        $$->threeACCode.push_back("L" + to_string(loopscope.back()) + ":");
        lcounter -= 1;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        loopscope.pop_back();
        loopscope.pop_back();
    }
}

BasicForStatementNoShortIf : k_for invoke_paren s_semicolon s_semicolon s_close_paren StatementNoShortIf
{
    $$ = new Node("BasicForStatementNoShortIf");

    $$->children.push_back(new Node("for", "Keyword", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($6);
    if (!isDot)
    {
        $$->threeACCode.push_back("L" + to_string(currentSymTableId) + ":");
        $$->threeACCode.push_back("\tif 1 goto L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $6->threeACCode.begin(), $6->threeACCode.end());
        $6->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(currentSymTableId));
        $$->threeACCode.push_back("L" + to_string(loopscope.back()) + ":");
        lcounter -= 1;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        loopscope.pop_back();
        loopscope.pop_back();
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
    if (!isDot)
    {
        $$->threeACCode.push_back("L" + to_string(currentSymTableId) + ":");
        $$->threeACCode.push_back("\tif 1 goto L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $7->threeACCode.begin(), $7->threeACCode.end());
        $7->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(currentSymTableId));
        $$->threeACCode.push_back("L" + to_string(loopscope.back()) + ":");
        lcounter -= 1;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        loopscope.pop_back();
        loopscope.pop_back();
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
    if (!isDot)
    {
        if ($4->type != BOOL)
        {
            yyerror("Expression in for loop must be of type bool");
            exit(0);
        }
        if ($4->sz != 0)
        {
            yyerror("Expression in for loop must be of size 0");
            exit(0);
        }
        $$->threeACCode.push_back("L" + to_string(currentSymTableId) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $4->threeACCode.begin(), $4->threeACCode.end());
        $4->threeACCode.clear();
        $$->threeACCode.push_back("\tif " + $4->field + " goto L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $7->threeACCode.begin(), $7->threeACCode.end());
        $7->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(currentSymTableId));
        $$->threeACCode.push_back("L" + to_string(loopscope.back()) + ":");
        lcounter -= 1;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        loopscope.pop_back();
        loopscope.pop_back();

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
    if (!isDot)
    {
        if ($4->type != BOOL)
        {
            yyerror("Expression in for loop must be of type bool");
            exit(0);
        }
        if ($4->sz != 0)
        {
            yyerror("Expression in for loop must be of size 0");
            exit(0);
        }
        $$->threeACCode.push_back("L" + to_string(currentSymTableId) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $4->threeACCode.begin(), $4->threeACCode.end());
        $4->threeACCode.clear();
        $$->threeACCode.push_back("\tif " + $4->field + " goto L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $8->threeACCode.begin(), $8->threeACCode.end());
        $8->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $6->threeACCode.begin(), $6->threeACCode.end());
        $6->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(currentSymTableId));
        $$->threeACCode.push_back("L" + to_string(loopscope.back()) + ":");
        lcounter -= 1;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        loopscope.pop_back();
        loopscope.pop_back();
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
    if (!isDot)
    {
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("L" + to_string(currentSymTableId) + ":");
        $$->threeACCode.push_back("\tif 1 goto L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $7->threeACCode.begin(), $7->threeACCode.end());
        $7->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(currentSymTableId));
        $$->threeACCode.push_back("L" + to_string(loopscope.back()) + ":");
        lcounter -= 1;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        loopscope.pop_back();
        loopscope.pop_back();
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
    if (!isDot)
    {
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("L" + to_string(currentSymTableId) + ":");
        $$->threeACCode.push_back("\tif 1 goto L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $8->threeACCode.begin(), $8->threeACCode.end());
        $8->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $6->threeACCode.begin(), $6->threeACCode.end());
        $6->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(currentSymTableId));
        $$->threeACCode.push_back("L" + to_string(loopscope.back()) + ":");
        lcounter -= 1;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        loopscope.pop_back();
        loopscope.pop_back();
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
    if (!isDot)
    {
        if ($5->type != BOOL)
        {
            yyerror("Expression in for loop must be of type bool");
            exit(0);
        }
        if ($5->sz != 0)
        {
            yyerror("Expression in for loop must be of size 0");
            exit(0);
        }
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("L" + to_string(currentSymTableId) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $5->threeACCode.begin(), $5->threeACCode.end());
        $5->threeACCode.clear();
        $$->threeACCode.push_back("\tif " + $5->field + " goto L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $8->threeACCode.begin(), $8->threeACCode.end());
        $8->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(currentSymTableId));
        $$->threeACCode.push_back("L" + to_string(loopscope.back()) + ":");
        lcounter -= 1;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        loopscope.pop_back();
        loopscope.pop_back();
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
    if (!isDot)
    {
        if ($5->type != BOOL)
        {
            yyerror("Expression in for loop must be of type bool");
            exit(0);
        }
        if ($5->sz != 0)
        {
            yyerror("Expression in for loop must be of size 0");
            exit(0);
        }
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("L" + to_string(currentSymTableId) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $5->threeACCode.begin(), $5->threeACCode.end());
        $5->threeACCode.clear();
        $$->threeACCode.push_back("\tif " + $5->field + " goto L" + to_string(lcounter));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $9->threeACCode.begin(), $9->threeACCode.end());
        $9->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $7->threeACCode.begin(), $7->threeACCode.end());
        $7->threeACCode.clear();
        int tempoffset = 0;
        for(auto i = symTables[currentSymTableId].entries.begin(); i != symTables[currentSymTableId].entries.end(); i++){
            tempoffset += offsetVal[i->second[0].type];
        }
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(currentSymTableId));
        $$->threeACCode.push_back("L" + to_string(loopscope.back()) + ":");
        lcounter -= 1;
        currentSymTableId = symTables[currentSymTableId].parentID;
        localoffset -= isArgument * tempoffset;
        loopscope.pop_back();
        loopscope.pop_back();
    }
}

EnhancedForStatementNoShortIf : k_for invoke_paren LocalVariableDeclaration o_colon Expression s_close_paren StatementNoShortIf
{
    $$ = new Node("EnhancedForStatementNoShortIf");

    $$->children.push_back(new Node("for", "Keyword", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node(":", "Separator", yylineno));
    $$->children.push_back($5);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($7);
    if (!isDot)
    {
        currentSymTableId = symTables[currentSymTableId].parentID;
        loopscope.pop_back();
        loopscope.pop_back();
    }
}

ForInit : StatementExpressionList
{
    $$ = $1;
}
| LocalVariableDeclaration
{
    $$ = $1;
};

ForUpdate : StatementExpressionList
{
    $$ = $1;
};

EnhancedForStatement : k_for invoke_paren LocalVariableDeclaration o_colon Expression s_close_paren Statement
{
    $$ = new Node("EnhancedForStatement");
    $$->children.push_back(new Node("for", "Keyword", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node(":", "Separator", yylineno));
    $$->children.push_back($5);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($7);
    if (!isDot)
    {
        currentSymTableId = symTables[currentSymTableId].parentID;
        loopscope.pop_back();
        loopscope.pop_back();
    }
}

StatementExpressionList : StatementExpression { $$ = $1; }
| StatementExpressionList s_comma StatementExpression
{
    $$ = new Node("StatementExpressionList");
    $$->children.push_back($1);
    $$->children.push_back(new Node(",", "Separator", yylineno));
    $$->children.push_back($3);
}

BreakStatement : k_break s_semicolon
{
    $$ = new Node("BreakStatement");
    $$->children.push_back(new Node("break", "Keyword", yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));
    if (!isDot)
    {
        if (loopscope.size() == 0)
        {
            yyerror("Break statement outside loop");
            exit(0);
        }
        int tempoffset = 0, x = currentSymTableId, y = loopscope[loopscope.size()-2];
        while(x > 1){
            for(auto i = symTables[x].entries.begin(); i != symTables[x].entries.end(); i++){
                tempoffset += offsetVal[i->second[0].type];
            }
            if(x == y){
                break;
            }
            x = symTables[x].parentID;
        }   
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope.back()));
    }
}
| k_break Identifier s_semicolon
{
    $$ = new Node("BreakStatement");
    $$->children.push_back(new Node("break", "Keyword", yylineno));
    $$->children.push_back(new Node($3, "Identifier", yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));
}

ContinueStatement : k_continue s_semicolon
{
    $$ = new Node("ContinueStatement");
    $$->children.push_back(new Node("continue", "Keyword", yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));
    if (!isDot)
    {
        if (loopscope.size() == 0)
        {
            yyerror("Continue statement outside loop");
            exit(0);
        }
        int tempoffset = 0, x = currentSymTableId, y = loopscope[loopscope.size()-2];
        while(x > 1){
            for(auto i = symTables[x].entries.begin(); i != symTables[x].entries.end(); i++){
                tempoffset += offsetVal[i->second[0].type];
            }
            if(x == y)
                break;
            x = symTables[x].parentID;
        }   
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string(tempoffset));
        $$->threeACCode.push_back("\tgoto L" + to_string(loopscope[loopscope.size()-2]));
    }
}
| k_continue Identifier s_semicolon
{
    $$ = new Node("ContinueStatement");
    $$->children.push_back(new Node("continue", "Keyword", yylineno));
    $$->children.push_back(new Node($2, "Identifier", yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));
}

ReturnStatement : k_return s_semicolon
{
    $$ = new Node("ReturnStatement");
    $$->children.push_back(new Node("return", "Keyword", yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));
    if(!isDot){
    int t1 = symTables[currentSymTableId].lookup(returnFunctionName);
        if (!t1)
    {
        yyerror("Function associated with this return statement not found");
        exit(0);
    }
    if (symTables[t1].entries[returnFunctionName][0].type != VOID)
    {
        yyerror("Return type of function does not match return statement");
        exit(0);
    }
    if (symTables[t1].entries[returnFunctionName][0].size != 0)
    {
        yyerror("Return size of function does not match return statement");
        exit(0);
    }   
        $$->threeACCode.push_back("\t%rsp = %rbp");
        $$->threeACCode.push_back("\tpopq\t%rbp");
        $$->threeACCode.push_back("\tret");
        if(islocal){
            if(!symTables[symTables[currentSymTableId].parentID].name.empty())
                isreturn = true;
        }
    }
}
| k_return Expression s_semicolon
{
    $$ = new Node("ReturnStatement");
    $$->children.push_back(new Node("return", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node(";", "Separator", yylineno));
    if(!isDot){
        int t1 = symTables[currentSymTableId].lookup(returnFunctionName);
    if (!t1)
    {
        yyerror("Function associated with this return statement not found");
        exit(0);
    }
    if (symTables[t1].entries[returnFunctionName][0].type != $2->type)
    {
        yyerror("Return type of function does not match return statement");
        exit(0);
    }
    if (symTables[t1].entries[returnFunctionName][0].size != $2->sz)
    {
        yyerror("Return size of function does not match return statement");
        exit(0);
    }
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
        $$->threeACCode.push_back("\t%rax = " + $2->field);
        $$->threeACCode.push_back("\t%rsp = %rbp");
        $$->threeACCode.push_back("\tpopq\t%rbp");
        $$->threeACCode.push_back("\tret");
        if(islocal){
            if(!symTables[symTables[currentSymTableId].parentID].name.empty())
                isreturn = true;
        }
    }
}

ThrowStatement : k_throw s_semicolon
{
    $$ = new Node("ThrowStatement");
    $$->children.push_back(new Node("throw", "Keyword", yylineno));
    $$->children.push_back(new Node(";", "Separator", yylineno));
}
| k_throw Expression s_semicolon
{
    $$ = new Node("ThrowStatement");
    $$->children.push_back(new Node("throw", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node(";", "Separator", yylineno));
}

SynchronizedStatement :
    k_synchronized s_open_paren Expression s_close_paren Block
{
    $$ = new Node("SynchronizedStatement");
    $$->children.push_back(new Node("synchronized", "Keyword", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($5);
}

TryStatement : k_try Block Catches
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
    $$->children.push_back($4);
}

Catches : CatchClause
{
    $$ = new Node("Catches");
    $$->children.push_back($1);
}
| Catches CatchClause
{
    $$ = new Node("Catches");
    $$->children.push_back($1);
    $$->children.push_back($2);
}

CatchClause : k_catch s_open_paren FormalParameter s_close_paren Block
{
    $$ = new Node("CatchClause");
    $$->children.push_back(new Node("catch", "Keyword", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($5);
}

Finally : k_finally Block
{
    $$ = new Node("Finally");
    $$->children.push_back(new Node("finally", "Keyword", yylineno));
    $$->children.push_back($2);
}

// ------------------ Production 15 -------------------

Primary : PrimaryNoNewArray
{
    $$ = $1;
}
| ArrayCreationExpression
{
    $$ = $1;
};

PrimaryNoNewArray : int_Literal
{
    $$ = new Node($1, "Literal", INT, yylineno);
    $$->field = $$->id;
}
| long_Literal
{
    $$ = new Node($1, "Literal", LONG, yylineno);
    $$->field = $$->id;
}

| bin_Literal
{
    $$ = new Node($1, "Literal", BIN, yylineno);
    $$->field = $$->id;
}
| deci_float_Literal
{
    $$ = new Node($1, "Literal", FLOAT, yylineno);
    $$->field = $$->id;
}
| deci_double_Literal
{
    $$ = new Node($1, "Literal", DOUBLE, yylineno);
    $$->field = $$->id;
}
| oct_Literal
{
    $$ = new Node($1, "Literal", OCT, yylineno);
    $$->field = $$->id;
}
| hex_flo_Literal
{
    $$ = new Node($1, "Literal", HEX_FLOAT, yylineno);
    $$->field = $$->id;
}
| string_Literal
{
    $$ = new Node($1, "Literal", STRING, yylineno);
    $$->field = $$->id;
}
| hex_Literal
{
    $$ = new Node($1, "Literal", HEX, yylineno);
    $$->field = $$->id;
}
| k_this
{
    $$ = new Node("this", "Keyword", yylineno);
    if (!isDot)
    {
        int x = currentSymTableId;
        while (!symTables[x].isfunction)
        {
            x = symTables[x].parentID;
        }
        $$->symid = symTables[x].parentID;
        $$->field = "this";
    }
}
| Text_Block_Literal 
{ 
    $$ = new Node("TextBlock", "Literal", STRING, yylineno); 
    if(!isDot)
        $$->field = $1;
}
| char_Literal
{
    $$ = new Node($1, "Literal", CHAR, yylineno);
    $$->field = $$->id;
}
| true_Literal
{
    $$ = new Node("true", "Keyword", BOOL, yylineno);
    $$->field = $$->id;
}
| false_Literal
{
    $$ = new Node("false", "Keyword", BOOL, yylineno);
    $$->field = $$->id;
}
| null_Literal
{
    $$ = new Node("null", "Keyword", BOOL, yylineno);
    $$->field = $$->id;
}
| s_open_paren Expression s_close_paren
{
    $$ = new Node("PrimaryNoNewArray");
    $$->type = $2->type;
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->field = $2->field;
    $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
    $2->threeACCode.clear();
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
| ArrayAccess { $$ = $1;};

ClassInstanceCreationExpression : k_new ClassType s_open_paren s_close_paren
{
    $$ = new Node("ClassInstanceCreationExpression");
    $$->children.push_back(new Node("new", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back(new Node(")", "Separator", yylineno));
    if (!isDot)
    {
        if (reftype != $2->id)
        {
            yyerror("ClassType mismatch");
            exit(0);
        }
        $$->field = "t" + to_string(tcounter++);
        $$->type = OBJECT;
        if(islocal){
            // $$->threeACCode.push_back("ClassInstanceCreation :" );
            $$->threeACCode.push_back("\t" + $$->field + " = " + to_string(symTables[1].entries[reftype][0].offset));
            $$->threeACCode.push_back("\tt" + to_string(tcounter) + " = allocate " + $$->field);
            $$->threeACCode.push_back("\tpush t" + to_string(tcounter));
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\tCall " + reftype + ".ctor");
        }
    }
}
| k_new ClassType s_open_paren ArgumentList s_close_paren
{
    $$ = new Node("ClassInstanceCreationExpression");
    $$->type = $2->type;
    $$->children.push_back(new Node("new", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($4);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    if (!isDot)
    {
        if (reftype != $2->id)
        {
            yyerror("ClassType mismatch");
            exit(0);
        }
        vector<struct symEntry> *a = symTables[class_to_symboltable[$2->id]].getSymEntry($2->id);
        if ((*a).size() != vfs.size() + 1 || !(*a)[0].isfunction)
        {
            yyerror("Constructor not found");
            exit(0);
        }
        $$->type = (*a)[0].type;
        for (int i = 0; i < vfs.size(); i++)
        {
            if (widen(vt[i],(*a)[i + 1].type) != (*a)[i + 1].type || vfs[i] != (*a)[i + 1].size)
            {
                yyerror("Argument type mismatch");
                exit(0);
            }
        }
        vt.clear();
        vfs.clear();
        $$->field = "t" + to_string(tcounter++);
        $$->type = OBJECT;
        if(islocal){
            // $$->threeACCode.push_back("ClassInstanceCreation :" );
            $$->threeACCode.push_back("\t" + $$->field + " = " + to_string(symTables[1].entries[reftype][0].offset));
            $$->threeACCode.push_back("\tt" + to_string(tcounter) + " = allocate " + $$->field);
            $$->threeACCode.insert($$->threeACCode.end(), $4->threeACCode.begin(), $4->threeACCode.end());
            $4->threeACCode.clear();
            $$->threeACCode.push_back("\tpush t" + to_string(tcounter));
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\tCall " + reftype + ".ctor");
            $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string($4->sz));
        }
    }
};

ArgumentList : Expression
{
    $$ = $1;
    if (!isDot)
    {
        vt.push_back($1->type);
        vfs.push_back($1->sz);
        $$->threeACCode.push_back("\tpush " + $1->field);
        $$->sz = offsetVal[$1->type];
    }
}
| ArgumentList s_comma Expression
{
    $$ = new Node("ArgumentList");
    $$->children.push_back($1);
    $$->children.push_back(new Node(",", "Separator", yylineno));
    $$->children.push_back($3);
    if (!isDot)
    {
        vt.push_back($3->type);
        vfs.push_back($3->sz);
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("\tpush " + $3->field);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->sz = $1->sz + offsetVal[$3->type];
    }
};

ArrayCreationExpression : k_new PrimitiveType DimExprs
{
    $$ = new Node("ArrayCreationExpression");
    $$->children.push_back(new Node("new", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back($3);
    if (!isDot)
    {
        if (t != $2->type)
        {
            yyerror("Type mismatch in ArrayCreationExpression rhs");
            exit(0);
        }
        $$->sz = $3->arrdims.size();
        $$->arrdims = $3->arrdims;
        $$->type = $2->type;
        $3->arrdims.clear();
        $$->field = "t" + to_string(tcounter++);
        if(islocal){
            // $$->threeACCode.push_back("ArrayDeclaration :" );
            $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
            $3->threeACCode.clear();
            $$->threeACCode.push_back("\t" + $$->field + " = " + $3->field + " * " + to_string(offsetVal[t]));
            $$->threeACCode.push_back("\tt" + to_string(tcounter) + " = allocate " + $$->field);
            $$->field = "t" + to_string(tcounter++);
        }
    }
}
| k_new PrimitiveType Dims ArrayInitializer
{
    $$ = new Node("ArrayCreationExpression");
    $$->children.push_back(new Node("new", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back($4);
    if (!isDot)
    {
        if (t != $2->type)
        {
            yyerror("Type mismatch in arrayCreationExpression rhs");
            exit(0);
        }
        $$->type = $2->type;
        $$->sz = vs.size();
    }
}
| k_new PrimitiveType DimExprs Dims
{
    $$ = new Node("ArrayCreationExpression");
    $$->children.push_back(new Node("new", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back($4);
    if (!isDot)
    {
        if (t != $2->type)
        {
            yyerror("Type mismatch in ArrayCreationExpression rhs");
            exit(0);
        }
        $$->sz = $3->arrdims.size() + $4->arrdims.size();
        $$->arrdims = $3->arrdims;
        $$->type = $2->type;
        $$->arrdims.insert($$->arrdims.end(), $4->arrdims.begin(), $4->arrdims.end());
        $3->arrdims.clear();
        $4->arrdims.clear();
    }
}
| k_new Name DimExprs
{
    $$ = new Node("ArrayCreationExpression");
    $$->children.push_back(new Node("new", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back($3);
    if (!isDot)
    {
        if (t != $2->type)
        {
            yyerror("Type mismatch in ArrayCreationExpression rhs");
            exit(0);
        }
        $$->sz = $3->arrdims.size();
        $$->arrdims = $3->arrdims;
        $3->arrdims.clear();
        $$->type = $2->type;
        $$->field = "t" + to_string(tcounter++);
        if(islocal){
            // $$->threeACCode.push_back("ArrayDeclaration :" );
            $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
            $3->threeACCode.clear();
            $$->threeACCode.push_back("\t" + $$->field + " = allocate " + $3->field);
        }
    }
}
| k_new Name DimExprs Dims
{
    $$ = new Node("ArrayCreationExpression");
    $$->children.push_back(new Node("new", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back($4);
    if (!isDot)
    {
        if (t != $2->type)
        {
            yyerror("Type mismatch in ArrayCreationExpression rhs");
            exit(0);
        }
        $$->sz = $3->arrdims.size() + $4->arrdims.size();
        $$->arrdims = $3->arrdims;
        $$->type = $2->type;
        $$->arrdims.insert($$->arrdims.end(), $4->arrdims.begin(), $4->arrdims.end());
        $3->arrdims.clear();
        $4->arrdims.clear();
    }
}
| k_new Name Dims ArrayInitializer
{
    $$ = new Node("ArrayCreationExpression");
    $$->children.push_back(new Node("new", "Keyword", yylineno));
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back($4);
    if (!isDot)
    {
        if (t != $2->type)
        {
            yyerror("Type mismatch in ArrayCreationExpression rhs");
            exit(0);
        }
        $$->type = $2->type;
        $$->sz = vs.size();
    }
};

DimExprs : DimExpr
{
    $$ = $1;
}
| DimExprs DimExpr
{
    $$ = new Node("DimExprs");
    $$->children.push_back($1);
    $$->children.push_back($2);
    if (!isDot)
    {  
       $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
       $1->threeACCode.clear();
       $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
       $2->threeACCode.clear();
       $$->field = "t" + to_string(tcounter);
       $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " * " + $2->field);
       $$->arrdims.insert($$->arrdims.end(), $1->arrdims.begin(), $1->arrdims.end());
       $1->arrdims.clear();
       $$->arrdims.insert($$->arrdims.end(), $2->arrdims.begin(), $2->arrdims.end());
       $2->arrdims.clear();
    }
};

DimExpr : s_open_square_bracket Expression s_close_square_bracket
{
    $$ = new Node("DimExpr");
    if (!isDot)
    {
        if (widen($2->type, LONG) != LONG)
        {
            yyerror("Array index must be of type int");
            exit(0);
        }
        $$->field = $2->field;
        $$->arrdims.push_back($2->field);
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
    }
    $$->children.push_back(new Node("[", "Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node("]", "Separator", yylineno));
};

Dims : s_open_square_bracket s_close_square_bracket
{
    $$ = new Node("Dims");
    $$->children.push_back(new Node("[", "Separator", yylineno));
    $$->children.push_back(new Node("]", "Separator", yylineno));
    if (isarr)
    {
        $$->arrdims.push_back("0");
    }
}
| Dims s_open_square_bracket s_close_square_bracket
{
    $$ = new Node("Dims");
    $$->children.push_back($1);
    $$->children.push_back(new Node("[", "Separator", yylineno));
    if (isarr)
    {
        $$->arrdims.push_back("0");
    }
};

FieldAccess : Primary s_dot Identifier
{
    if (isDot)
        $$ = new Node("FieldAccess");
    else
        $$ = new Node($3, "FieldAccess", yylineno);
    $$->children.push_back($1);
    $$->children.push_back(new Node(".", "Separator", yylineno));
    $$->children.push_back(new Node($3, "Identifier", yylineno));
    if (!isDot)
    {
        if (!symTables[$1->symid].grand_lookup($3))
        {
            yyerror("Requested field not found");
            exit(0);
        }
        vector<struct symEntry> *a = symTables[$1->symid].getSymEntry($3);
        if ((*a)[0].isfunction)
        {
            yyerror("Requested field not found");
            exit(0);
        }
        if(islocal && isstatic && !(*a)[0].isStatic)
        {
            yyerror("Static-Nonstatic mismatch");
            exit(0);
        }
        $$->type = (*a)[0].type;
        $$->sz = (*a).size() - 1;
        $$->symid = $1->symid;
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field);
        $$->threeACCode.push_back("\t" + $$->field + " = " + $$->field +" + "+ to_string((*a)[0].offset));
        $$->field = "(" + $$->field + ")";
    }
}
| k_super s_dot Identifier
{
    $$ = new Node("FieldAccess");
    $$->children.push_back(new Node("super", "Keyword", yylineno));
    $$->children.push_back(new Node(".", "Separator", yylineno));
    $$->children.push_back(new Node($3, "Identifier", yylineno));
};

MethodInvocation : Name s_open_paren s_close_paren
{
    $$ = new Node("MethodInvocation");
    $$->children.push_back($1);
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back(new Node(")", "Separator", yylineno));
    if (!isDot)
    {
        vector<struct symEntry> *a = symTables[$1->symid].getSymEntry($1->id);
        if ((*a).size() != 1 || !(*a)[0].isfunction)
        {
            yyerror("Method not found");
            exit(0);
        }
        $$->symid = (*a)[0].symid;
        $$->type = (*a)[0].type;
        $$->sz = (*a)[0].size;
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        // if(symTables[$1->symid].grand_lookup(returnFunctionName))
        //     $$->threeACCode.push_back("\tpush this");
        // else $$->threeACCode.push_back("\tpush " + $1->field);
        $$->threeACCode.push_back("\tcall " + symTables[$1->symid].name + "." + $1->id);
        if ($$->type != VOID){
            $$->threeACCode.push_back("\t" + $$->field + " = %rax");
        }
    }
}
| Name s_open_paren ArgumentList s_close_paren
{
    $$ = new Node("MethodInvocation");
    $$->children.push_back($1);
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    if (!isDot)
    {
        vector<struct symEntry> *a = symTables[$1->symid].getSymEntry($1->id);
        if ((*a).size() != vfs.size() + 1 || !(*a)[0].isfunction)
        {
            yyerror("Method not found");
            exit(0);
        }
        $$->type = (*a)[0].type;
        $$->symid = (*a)[0].symid;
        $$->sz = (*a)[0].size;
        $$->field = "t" + to_string(tcounter++);
        for (int i = 0; i < vfs.size(); i++)
        {
            if (widen(vt[i], (*a)[i + 1].type)!= (*a)[i + 1].type || vfs[i] != (*a)[i + 1].size)
            {   
                yyerror("Argument type mismatch");
                exit(0);
            }
        }
        vt.clear();
        vfs.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        // if(symTables[$1->symid].grand_lookup(returnFunctionName))
        //     $$->threeACCode.push_back("\tpush this");
        // else $$->threeACCode.push_back("\tpush " + $1->field);
        $$->threeACCode.push_back("\tcall " + symTables[$1->symid].name + "." + $1->id);
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string($3->sz));
        if($$->type != VOID){
            $$->threeACCode.push_back("\t" + $$->field + " = %rax");
        }
        $3->threeACCode.clear();
    }
}
| Primary s_dot Identifier s_open_paren s_close_paren
{
    $$ = new Node("MethodInvocation");
    $$->children.push_back($1);
    $$->children.push_back(new Node(".", "Separator", yylineno));
    $$->children.push_back(new Node($3, "Identifier", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back(new Node(")", "Separator", yylineno));
    if (!isDot)
    {
        if (!symTables[$1->symid].grand_lookup($3))
        {
            yyerror("Method not found");
            exit(0);
        }
        vector<struct symEntry> *a = symTables[$1->symid].getSymEntry($3);
        if ((*a).size() != 1 || !(*a)[0].isfunction)
        {
            yyerror("Method not found");
            exit(0);
        }
        $$->type = (*a)[0].type;
        $$->symid = (*a)[0].symid;
        $$->sz = (*a)[0].size;
        $$->field = "t" + to_string(tcounter++);
        string s($3);
        // if(symTables[$1->symid].grand_lookup(returnFunctionName))
        //     $$->threeACCode.push_back("\tpush this");
        // else $$->threeACCode.push_back("\tpush " + $1->field);
        $$->threeACCode.push_back("\tcall " + $1->id + "." + s);
        if ($$->type != VOID){
            $$->threeACCode.push_back("\t" + $$->field + " = %rax");
        }
    }
}
| Primary s_dot Identifier s_open_paren ArgumentList s_close_paren
{
    $$ = new Node("MethodInvocation");
    $$->children.push_back($1);
    $$->children.push_back(new Node(".", "Separator", yylineno));
    $$->children.push_back(new Node($3, "Identifier", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($5);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    if (!isDot)
    {
        if (!symTables[$1->symid].grand_lookup($3))
        {
            yyerror("Method not found");
            exit(0);
        }
        vector<struct symEntry> *a = symTables[$1->symid].getSymEntry($3);
        if ((*a).size() != vfs.size() + 1 || !(*a)[0].isfunction)
        {
            yyerror("Method not found");
            exit(0);
        }
        $$->type = (*a)[0].type;
        $$->symid = (*a)[0].symid;
        $$->sz = (*a)[0].size;
        $$->field = "t" + to_string(tcounter++);
        for (int i = 0; i < vfs.size(); i++)
        {
            if (vt[i] != (*a)[i + 1].type || vfs[i] != (*a)[i + 1].size)
            {
                yyerror("Argument type mismatch");
                exit(0);
            }
        }
        vt.clear();
        vfs.clear();
        $5->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $5->threeACCode.begin(), $5->threeACCode.end());
        string s($3);
        // if(symTables[$1->symid].grand_lookup(returnFunctionName))
        //     $$->threeACCode.push_back("\tpush this");
        // else $$->threeACCode.push_back("\tpush " + $1->field);
        $$->threeACCode.push_back("\tcall " + $1->id + "." + s);
        $$->threeACCode.push_back("\t%rsp = %rsp + " + to_string($5->sz));
        if ($$->type != VOID){
            $$->threeACCode.push_back("\t" + $$->field + " = %rax");
        }
    }
}
| k_super s_dot Identifier s_open_paren s_close_paren
{
    $$ = new Node("MethodInvocation");
    $$->children.push_back(new Node("super", "Keyword", yylineno));
    $$->children.push_back(new Node(".", "Separator", yylineno));
    $$->children.push_back(new Node($3, "Identifier", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back(new Node(")", "Separator", yylineno));
}
| k_super s_dot Identifier s_open_paren ArgumentList s_close_paren
{
    $$ = new Node("MethodInvocation");
    $$->children.push_back(new Node("super", "Keyword", yylineno));
    $$->children.push_back(new Node(".", "Separator", yylineno));
    $$->children.push_back(new Node($3, "Identifier", yylineno));
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($5);
    $$->children.push_back(new Node(")", "Separator", yylineno));
};

ArrayAccess : Name s_open_square_bracket Expression s_close_square_bracket
{
    if (isDot)
        $$ = new Node("ArrayAccess");
    else
    {
        $$ = new Node($1->id.c_str(), "ArrayAccess", yylineno);
        if (widen($3->type, LONG) != LONG)
        {
            yyerror("Array index must be of type int");
            exit(0);
        }
        vector<struct symEntry> *a = symTables[$1->symid].getSymEntry($1->id);
        if ($3->sz != 0)
        {
            yyerror("Array index must be of type int");
            exit(0);
        }
        $$->arrdims.push_back($3->field);
        $3->arrdims.clear();
        if ($$->arrdims.size() > (*a).size() - 1 || (*a)[0].isfunction)
        {
            yyerror("Array dimension mismatch");
            exit(0);
        }
        $$->type = (*a)[0].type;
        $$->sz = (*a).size() - 1 - $$->arrdims.size();
        $$->symid = $1->symid;
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field);
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        string s1 = "t" + to_string(tcounter++);
        $$->threeACCode.push_back("\t" + s1 + " = " + $3->field);
        for (int i = $$->arrdims.size() + 1; i < (*a).size(); i++){
                $$->threeACCode.push_back("\t" + s1 + " = " + s1 + " * " + (*a)[i].dimsize);
        }
        $$->threeACCode.push_back("\t" + s1 + " = " + s1 + " * " + to_string(offsetVal[$1->type]));
        $$->threeACCode.push_back("\t" + $$->field + " = " + $$->field + " + " + s1);
        if((*a).size() == 2){
            $$->field = "(" + $$->field + ")";
        }
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("[", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node("]", "Separator", yylineno));
}
| PrimaryNoNewArray s_open_square_bracket Expression s_close_square_bracket
{
    if (isDot)
        $$ = new Node("ArrayAccess");
    else
    {
        $$ = new Node($1->id.c_str(), "ArrayAccess", yylineno);
        if (widen($3->type, LONG) != LONG)
        {
            yyerror("Array index must be of type int");
            exit(0);
        }
        if ($3->sz != 0)
        {
            yyerror("Array index must be of type int");
            exit(0);
        }
        $$->arrdims = $1->arrdims;
        $$->arrdims.push_back($3->field);
        $3->arrdims.clear();
        $1->arrdims.clear();
        vector<struct symEntry> *a = symTables[$1->symid].getSymEntry($1->id);
        if ((*a).size() - 1 < $$->arrdims.size() || (*a)[0].isfunction)
        {
            yyerror("Array dimension mismatch");
            exit(0);
        }
        $$->type = (*a)[0].type;
        $$->sz = (*a).size() - $$->arrdims.size() - 1;
        $$->symid = $1->symid;
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field);
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        string s1 = "t" + to_string(tcounter++);
        $$->threeACCode.push_back("\t" + s1 + " = " + $3->field);
        for (int i = $$->arrdims.size() + 1; i < (*a).size(); i++){
                $$->threeACCode.push_back("\t" + s1 + " = " + s1 + " * " + (*a)[i].dimsize);
        }
        $$->threeACCode.push_back("\t" + s1 + " = " + s1 + " * " + to_string(offsetVal[$1->type]));
        $$->threeACCode.push_back("\t" + $$->field + " = " + $$->field + " + " + s1);
        if((*a).size() == $$->arrdims.size() + 1){
            $$->field = "(" + $$->field + ")";
        }
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("[", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node("]", "Separator", yylineno));
};

PostFixExpression : Primary
{
    $$ = $1;
}
| Name
{
    $$ = $1;
}
| PostIncrementExpression
{
    $$ = $1;
}
| PostDecrementExpression
{
    $$ = $1;
};

PostIncrementExpression : PostFixExpression o_increment
{
    $$ = new Node("PostIncrementExpression");
    $$->type = $1->type;
    if (!isDot)
    {
        if (widen($1->type, LONG) != LONG)
        {
            yyerror("Post increment can only be applied to int");
            exit(0);
        }
        if ($1->sz != 0)
        {
            yyerror("Post increment can only be applied to int");
            exit(0);
        }
        if($1->isfinal){
            cout << "Cannot reset a final variable" << endl;
            exit(0);
        }
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field);
        $$->threeACCode.push_back("\t" + $1->field + " = " + $1->field + " + 1");
    }

    $$->children.push_back($1);
    $$->children.push_back(new Node("++", "Separator", yylineno));
};

PostDecrementExpression : PostFixExpression o_decrement
{
    $$ = new Node("PostDecrementExpression");
    $$->type = $1->type;
    if (!isDot)
    {
        if (widen($1->type, LONG) != LONG)
        {
            yyerror("Post decrement can only be applied to int");
            exit(0);
        }
        if ($1->sz != 0)
        {
            yyerror("Post decrement can only be applied to int");
            exit(0);
        }
        if($1->isfinal){
            cout << "Cannot reset a final variable" << endl;
            exit(0);
        }
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field);
        $$->threeACCode.push_back("\t" + $1->field + " = " + $$->field + " - 1");
    }
    $$->children.push_back($1);
};

UnaryExpression : PreIncrementExpression
{
    $$ = $1;
}
| PreDecrementExpression
{
    $$ = $1;
}
| o_add UnaryExpression
{
    $$ = new Node("UnaryExpression");
    $$->type = $2->type;
    if (!isDot)
    {
        if (widen($2->type, DOUBLE) != DOUBLE)
        {
            yyerror("Unary plus can only be applied to int");
            exit(0);
        }
        if ($2->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
        $$->field = $2->field;
    }
    $$->children.push_back(new Node("+", "Separator", yylineno));
    $$->children.push_back($2);
}
| o_subtract UnaryExpression
{
    $$ = new Node("UnaryExpression");
    $$->type = $2->type;
    if (!isDot)
    {
        if (widen($2->type, DOUBLE) != DOUBLE)
        {
            yyerror("Unary minus can only be applied to int");
            exit(0);
        }
        if ($2->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.push_back("\t" + $$->field + " = -" + $2->field);
    }
    $$->children.push_back(new Node("-", "Separator", yylineno));
    $$->children.push_back($2);
}
| UnaryExpressionNotPlusMinus
{
    $$ = $1;
};

PreIncrementExpression : o_increment UnaryExpression
{
    $$ = new Node("PreIncrementExpression");
    $$->type = $2->type;
    if (!isDot)
    {
        if (widen($2->type, LONG) != LONG)
        {
            yyerror("Pre increment can only be applied to int");
            exit(0);
        }
        if ($2->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        if($2->isfinal)
        {
            yyerror("Cannot increment a final variable");
            exit(0);
        }
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
        $$->threeACCode.push_back("\tt" + to_string(tcounter) + " = " + $2->field + " + 1");
        tcounter++;
        $$->threeACCode.push_back("\t" + $2->field + " = " + "t" + to_string(tcounter - 1));
        $$->field = $2->field;
    }
    $$->children.push_back(new Node("++", "Separator", yylineno));
    $$->children.push_back($2);
};

PreDecrementExpression : o_decrement UnaryExpression
{
    $$ = new Node("PreDecrementExpression");
    $$->type = $2->type;
    if (!isDot)
    {
        if (widen($2->type, LONG) != LONG)
        {
            yyerror("Pre decrement can only be applied to int");
            exit(0);
        }
        if ($2->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        if($2->isfinal)
        {
            yyerror("Cannot decrement a final variable");
            exit(0);
        }
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
        $$->threeACCode.push_back("\tt" + to_string(tcounter++) + " = " + $2->field + " - 1");
        $$->threeACCode.push_back("\t" + $2->field + " = " + "t" + to_string(tcounter - 1));
        $$->field = $2->field;
    }
    $$->children.push_back(new Node("--", "Separator", yylineno));
    $$->children.push_back($2);
};

UnaryExpressionNotPlusMinus : PostFixExpression
{
    $$ = $1;
}
| o_bitwise_complement UnaryExpression
{
    $$ = new Node("UnaryExpressionNotPlusMinus");
    if (!isDot)
    {
        if (widen($2->type, LONG) != LONG)
        {
            yyerror("Bitwise complement can only be applied to int");
            exit(0);
        }
        if ($2->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->type = widen($2->type, INT);
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
        $$->threeACCode.push_back("\t" + $$->field + " = " + "~ " + $2->field);
    }
    $$->children.push_back(new Node("~", "Separator", yylineno));
    $$->children.push_back($2);
}
| o_logical_not UnaryExpression
{
    $$ = new Node("UnaryExpressionNotPlusMinus");
    if (!isDot)
    {
        if ($2->type != BOOL)
        {
            yyerror("Logical not can only be applied to BOOL");
            exit(0);
        }
        if ($2->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->type = $2->type;
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $2->threeACCode.begin(), $2->threeACCode.end());
        $2->threeACCode.clear();
        $$->threeACCode.push_back("\t" + $$->field + " = " + "not " + $2->field);
    }
    $$->children.push_back(new Node("!", "Separator", yylineno));
    $$->children.push_back($2);
}
| CastExpression
{
    $$ = $1;
};

CastExpression : s_open_paren PrimitiveType s_close_paren UnaryExpression
{
    $$ = new Node("CastExpression");
    if (!isDot)
    {
        if (widen($2->type, DOUBLE) != DOUBLE || widen($4->type, DOUBLE) != DOUBLE)
        {
            yyerror("Cast can only be applied to integer types");
            exit(0);
        }
        $$->type = $2->type;
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $4->threeACCode.begin(), $4->threeACCode.end());
        $4->threeACCode.clear();
        $$->threeACCode.push_back("\t" + $$->field + " = cast_to_" + enum_types[$2->type] + " " + $4->field);
    }
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($4);
}
| s_open_paren PrimitiveType Dims s_close_paren UnaryExpression
{
    $$ = new Node("CastExpression");
    if (!isDot)
    {
        if (widen($2->type, DOUBLE) != DOUBLE || widen($5->type, DOUBLE) != DOUBLE)
        {
            yyerror("Cast can only be applied to integer types");
            exit(0);
        }
    }
    $$->type = $2->type;
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($5);
}
| s_open_paren Expression s_close_paren UnaryExpressionNotPlusMinus
{
    $$ = new Node("CastExpression");
    if (!isDot)
    {
        if (widen($2->type, DOUBLE) != DOUBLE || widen($4->type, DOUBLE) != DOUBLE)
        {
            yyerror("Cast can only be applied to integer types");
            exit(0);
        }
    }
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($4);
}
| s_open_paren Name Dims s_close_paren UnaryExpressionNotPlusMinus
{
    $$ = new Node("CastExpression");
    $$->children.push_back(new Node("(", "Separator", yylineno));
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back(new Node(")", "Separator", yylineno));
    $$->children.push_back($5);
};

MultiplicativeExpression : UnaryExpression
{
    $$ = $1;
}
| MultiplicativeExpression o_multiply UnaryExpression
{
    $$ = new Node("MultiplicativeExpression");
    if (!isDot)
    {
        if (widen($1->type, DOUBLE) != DOUBLE || widen($3->type, DOUBLE) != DOUBLE)
        {
            yyerror("Multiplication can only be applied to int");
            exit(0);
        }
        $$->type = widen($1->type, $3->type);
        if ($1->sz != 0 || $3->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        if($1->type<$$->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$$->type] + " " + $1->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + old_field + " *" + enum_types[$$->type] + " " + $3->field);
        }
        else if($3->type<$$->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$$->type] + " " + $3->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " *" + enum_types[$$->type] + " "+ old_field);
        }
        else
            $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " *" + enum_types[$$->type] + " " + $3->field);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("*", "Separator", yylineno));
    $$->children.push_back($3);
}
| MultiplicativeExpression o_divide UnaryExpression
{
    $$ = new Node("MultiplicativeExpression");
    if (!isDot)
    {
        if (widen($1->type, DOUBLE) != DOUBLE || widen($3->type, DOUBLE) != DOUBLE)
        {
            yyerror("DIVISION can only be applied to int");
            exit(0);
        }
        $$->type = widen($1->type, $3->type);
        if ($1->sz != 0 || $3->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        if($1->type<$$->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$$->type] + " " + $1->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + old_field + " /" + enum_types[$$->type] + " " + $3->field);
        }
        else if($3->type<$$->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$$->type] + " " + $3->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " /" + enum_types[$$->type] + " "+ old_field);
        }
        else
            $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " /" + enum_types[$$->type] + " " + $3->field);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("/", "Separator", yylineno));
    $$->children.push_back($3);
}
| MultiplicativeExpression o_modulo UnaryExpression
{
    $$ = new Node("MultiplicativeExpression");
    if (!isDot)
    {
        if (widen($1->type, DOUBLE) != DOUBLE || widen($3->type, DOUBLE) != DOUBLE)
        {
            yyerror("Modulo can only be applied to int");
            exit(0);
        }
        $$->type = widen($1->type, $3->type);
        if ($1->sz != 0 || $3->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        if($1->type<$$->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$$->type] + " " + $1->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + old_field + " %" + enum_types[$$->type] + " " + $3->field);
        }
        else if($3->type<$$->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$$->type] + " " + $3->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " %" + enum_types[$$->type] + " "+ old_field);
        }
        else
            $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " %" + enum_types[$$->type] + " " + $3->field);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("%", "Separator", yylineno));
    $$->children.push_back($3);
};

AdditiveExpression : MultiplicativeExpression
{
    $$ = $1;
}
| AdditiveExpression o_add MultiplicativeExpression
{
    $$ = new Node("AdditiveExpression");
    if (!isDot)
    {
        if (widen($1->type, STRING) != STRING || widen($3->type, STRING) != STRING)
        {
            yyerror("Addition can only be applied to int");
            exit(0);
        }
        $$->type = widen($1->type, $3->type);
        if ($1->sz != 0 || $3->sz != 0)
        {   
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        if($1->type<$$->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$$->type] + " " + $1->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + old_field + " +" + enum_types[$$->type] + " " + $3->field);
        }
        else if($3->type<$$->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$$->type] + " " + $3->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " +" + enum_types[$$->type] + " "+ old_field);
        }
        else $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " +" + enum_types[$$->type] + " " + $3->field);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("+", "Separator", yylineno));
    $$->children.push_back($3);
}
| AdditiveExpression o_subtract MultiplicativeExpression
{
    $$ = new Node("AdditiveExpression");
    if (!isDot)
    {
        if (widen($1->type, DOUBLE) != DOUBLE || widen($3->type, DOUBLE) != DOUBLE)
        {
            yyerror("Subtraction can only be applied to int");
            exit(0);
        }
        $$->type = widen($1->type, $3->type);
        if ($1->sz != 0 || $3->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        if($1->type<$$->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$$->type] + " " + $1->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + old_field + " -" + enum_types[$$->type] + " " + $3->field);
        }
        else if($3->type<$$->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$$->type] + " " + $3->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " -" + enum_types[$$->type] + " "+ old_field);
        }
        else $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " -" + enum_types[$$->type] + " " + $3->field);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("-", "Separator", yylineno));
    $$->children.push_back($3);
};

ShiftExpression : AdditiveExpression
{
    $$ = $1;
}
| ShiftExpression o_left_shift AdditiveExpression
{
    $$ = new Node("ShiftExpression");
    if (!isDot)
    {
        if (widen($1->type, LONG) != LONG || (widen($3->type, LONG) != LONG || $3->type == CHAR))
        {
            yyerror("Shift Operation can only be applied to int");
            exit(0);
        }
        $$->type = widen($1->type, INT);
        if ($1->sz != 0 || $3->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " << " + $3->field);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("<<", "Separator", yylineno));
    $$->children.push_back($3);
}
| ShiftExpression o_right_shift AdditiveExpression
{
    $$ = new Node("ShiftExpression");
    if (!isDot)
    {
        if (widen($1->type, LONG) != LONG || (widen($3->type, LONG) != LONG || $3->type == CHAR))
        {
            yyerror("Shift Operation can only be applied to int");
            exit(0);
        }
        $$->type = widen($1->type, INT);
        if ($1->sz != 0 || $3->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " >> " + $3->field);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node(">>", "Separator", yylineno));
    $$->children.push_back($3);
}
| ShiftExpression o_unsigned_right_shift AdditiveExpression
{
    $$ = new Node("ShiftExpression");
    if (!isDot)
    {
        if (widen($1->type, LONG) != LONG || (widen($3->type, LONG) != LONG || $3->type == CHAR))
        {
            yyerror("Shift Operation can only be applied to int");
            exit(0);
        }

        $$->type = widen($1->type, INT);
        if ($1->sz != 0 || $3->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " >>> " + $3->field);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node(">>>", "Separator", yylineno));
    $$->children.push_back($3);
};

RelationalExpression : ShiftExpression
{
    $$ = $1;
}
| RelationalExpression o_less_than ShiftExpression
{
    $$ = new Node("RelationalExpression");
    $$->children.push_back($1);
    if (!isDot)
    {
        if (widen($1->type, DOUBLE) != DOUBLE || widen($3->type, DOUBLE) != DOUBLE)
        {
            yyerror("Less than operator can only be applied to same common super type");
            exit(0);
        }
        if ($1->sz != 0 || $3->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->type = BOOL;
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        if($1->type<$3->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$3->type] + " " + $1->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + old_field + " < " + $3->field);
        }
        else if($3->type<$1->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$1->type] + " " + $3->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " < " + old_field);
        }
        else $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " < " + $3->field);
    }
    $$->children.push_back(new Node("<", "Separator", yylineno));
    $$->children.push_back($3);
}
| RelationalExpression o_greater_than ShiftExpression
{
    $$ = new Node("RelationalExpression");
    if (!isDot)
    {
        if (widen($1->type, DOUBLE) != DOUBLE || widen($3->type, DOUBLE) != DOUBLE)
        {
            yyerror("Greater than operator can only be applied to same common super type");
            exit(0);
        }
        if ($1->sz != 0 || $3->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->type = BOOL;
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        if($1->type<$3->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$3->type] + " " + $1->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + old_field + " > " + $3->field);
        }
        else if($3->type<$1->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$1->type] + " " + $3->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " > " + old_field);
        }
        else $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " > " + $3->field);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node(">", "Separator", yylineno));
    $$->children.push_back($3);
}
| RelationalExpression o_less_than_or_equal ShiftExpression
{
    $$ = new Node("RelationalExpression");
    if (!isDot)
    {
        if (widen($1->type, DOUBLE) != DOUBLE || widen($3->type, DOUBLE) != DOUBLE)
        {
            yyerror("Less than or equals operator can only be applied to same common super type");
            exit(0);
        }
        if ($1->sz != 0 || $3->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->type = BOOL;
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        if($1->type<$3->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$3->type] + " " + $1->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + old_field + " <= " + $3->field);
        }
        else if($3->type<$1->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$1->type] + " " + $3->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " <= " + old_field);
        }
        else $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " <= " + $3->field);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("<=", "Separator", yylineno));
    $$->children.push_back($3);
}
| RelationalExpression o_greater_than_or_equal ShiftExpression
{
    $$ = new Node("RelationalExpression");
    if (!isDot)
    {
        if (widen($1->type, DOUBLE) != DOUBLE || widen($3->type, DOUBLE) != DOUBLE)
        {
            yyerror("Greater than or equals operator can only be applied to same common super type");
            exit(0);
        }
        if ($1->sz != 0 || $3->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->type = BOOL;
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        if($1->type<$3->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$3->type] + " " + $1->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + old_field + " >= " + $3->field);
        }
        else if($3->type<$1->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$1->type] + " " + $3->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " >= " + old_field);
        }
        else $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " >= " + $3->field);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node(">=", "Separator", yylineno));
    $$->children.push_back($3);
}
| RelationalExpression k_instanceof ReferenceType
{
    $$ = new Node("RelationalExpression");
    $$->children.push_back($1);
    $$->children.push_back(new Node("instanceof", "Separator", yylineno));
    $$->children.push_back($3);
};

EqualityExpression : RelationalExpression
{
    $$ = $1;
}
| EqualityExpression o_equals RelationalExpression
{
    $$ = new Node("EqualityExpression");
    if (!isDot)
    {
        if ((widen($1->type, DOUBLE) != DOUBLE || widen($3->type, DOUBLE) != DOUBLE) && !($1->type == $3->type && ($1->type == STRING || $1->type ==BOOL)))
        {
            yyerror("Equality can only be applied to same common super type");
            exit(0);
        }
        if ($1->sz != $3->sz)
        {
            yyerror("Equality can only be applied to same size");
            exit(0);
        }
        $$->type = BOOL;
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        if($1->type<$3->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$3->type] + " " + $1->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + old_field + " == " + $3->field);
        }
        else if($3->type<$1->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$1->type] + " " + $3->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " == " + old_field);
        }
        else $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " == " + $3->field);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("==", "Separator", yylineno));
    $$->children.push_back($3);
}
| EqualityExpression o_not_equals RelationalExpression
{
    $$ = new Node("EqualityExpression");
    if (!isDot)
    {
        if ((widen($1->type, DOUBLE) != DOUBLE || widen($3->type, DOUBLE) != DOUBLE) && !($1->type == $3->type && ($1->type == STRING || $1->type ==BOOL)))
        {
            yyerror("Non-Equality can only be applied to same common super type");
            exit(0);
        }
        if ($1->sz != $3->sz)
        {
            yyerror("Size mismatch");
            exit(0);
        }
        $$->type = BOOL;
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        if($1->type<$3->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$3->type] + " " + $1->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + old_field + " != " + $3->field);
        }
        else if($3->type<$1->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$1->type] + " " + $3->field);
            old_field = $$->field;
            $$->field = "t" + to_string(tcounter++);
            $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " != " + old_field);
        }
        else $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " != " + $3->field);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("!=", "Separator", yylineno));
    $$->children.push_back($3);
};

AndExpression : EqualityExpression
{
    $$ = $1;
}
| AndExpression o_bitwise_and EqualityExpression
{
    $$ = new Node("AndExpression");
    if (!isDot)
    {
        if (widen($1->type, LONG) != LONG || widen($3->type, LONG) != LONG)
        {
            yyerror("Bitwise AND can only be applied to int");
            exit(0);
        }
        if ($1->sz != 0 || $3->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->type = widen($1->type, $3->type);
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " & " + $3->field);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("&", "Separator", yylineno));
    $$->children.push_back($3);
};

ExclusiveOrExpression : AndExpression
{
    $$ = $1;
}
| ExclusiveOrExpression o_bitwise_xor AndExpression
{
    $$ = new Node("ExclusiveOrExpression");
    if (!isDot)
    {
        if (widen($1->type, LONG) != LONG || widen($3->type, LONG) != LONG)
        {
            yyerror("Bitwise XOR can only be applied to int");
            exit(0);
        }
        if ($1->sz != 0 || $3->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->type = widen($1->type, $3->type);
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " ^ " + $3->field);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("^", "Separator", yylineno));
    $$->children.push_back($3);
};

InclusiveOrExpression : ExclusiveOrExpression
{
    $$ = $1;
}
| InclusiveOrExpression o_bitwise_or ExclusiveOrExpression
{
    $$ = new Node("InclusiveOrExpression");
    if (!isDot)
    {
        if (widen($1->type, LONG) != LONG || widen($3->type, LONG) != LONG)
        {
            yyerror("Bitwise OR can only be applied to int");
            exit(0);
        }
        if ($1->sz != 0 || $3->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->type = widen($1->type, $3->type);
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " | " + $3->field);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("|", "Separator", yylineno));
    $$->children.push_back($3);
};

ConditionalAndExpression : InclusiveOrExpression
{
    $$ = $1;
}
| ConditionalAndExpression o_logical_and InclusiveOrExpression
{
    $$ = new Node("ConditionalAndExpression");
    if (!isDot)
    {
        if ($1->type != BOOL || $3->type != BOOL)
        {
            yyerror("Only Bools allowed");
            exit(0);
        }
        if ($1->sz != 0 || $3->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->type = BOOL;
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " && " + $3->field);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("&&", "Separator", yylineno));
    $$->children.push_back($3);
};

ConditionalOrExpression : ConditionalAndExpression
{
    $$ = $1;
}
| ConditionalOrExpression o_logical_or ConditionalAndExpression
{
    $$ = new Node("ConditionalOrExpression");
    if (!isDot)
    {
        if ($1->type != BOOL || $3->type != BOOL)
        {
            yyerror("Only Bools allowed");
            exit(0);
        }
        if ($1->sz != 0 || $3->sz != 0)
        {
            yyerror("Arrays not allowed");
            exit(0);
        }
        $$->type = BOOL;
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("\t" + $$->field + " = " + $1->field + " || " + $3->field);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("||", "Separator", yylineno));
    $$->children.push_back($3);
};

ConditionalExpression : ConditionalOrExpression
{
    $$ = $1;
}
| ConditionalOrExpression o_question_mark Expression o_colon ConditionalExpression
{
    $$ = new Node("ConditionalExpression");
    if (!isDot)
    {
        if ($1->type != BOOL)
        {
            yyerror("Conditional Operation can only be applied to boolean");
            exit(0);
        }
        if ($5->sz != $3->sz)
        {
            yyerror("Conditional Operation can only be applied to same type");
            exit(0);
        }
        if ((widen($3->type, DOUBLE) != DOUBLE || widen($5->type, DOUBLE) != DOUBLE) && !($3->type == $5->type && ($3->type == STRING || $3->type ==BOOL)))
        {
            yyerror("Conditional Operation can only be applied to same type");
            exit(0);
        }
        $$->field = "t" + to_string(tcounter);
        $$->type = widen($5->type, $3->type);
        $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
        $1->threeACCode.clear();
        if($3->type<$5->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$5->type] + " " + $3->field);
            $3->field = $$->field;
        }
        else if($5->type<$3->type){
            $$->threeACCode.push_back("\t" + $$->field + " = " + "cast_to_" + enum_types[$3->type] + " " + $5->field);
            $5->field = $$->field;
        }
        old_field = $$->field;
        $$->field = "t" + to_string(tcounter++);
        $$->threeACCode.push_back("\tif " + $1->field + " goto " + "L" + to_string(lcounter));
        $$->threeACCode.insert($$->threeACCode.end(), $5->threeACCode.begin(), $5->threeACCode.end());
        $5->threeACCode.clear();
        $$->threeACCode.push_back("\tt" + to_string(tcounter) + " = " + $5->field);
        $$->threeACCode.push_back("\tgoto L" + to_string(lcounter-1));
        $$->threeACCode.push_back("L" + to_string(lcounter) + ":");
        $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
        $3->threeACCode.clear();
        $$->threeACCode.push_back("\tt" + to_string(tcounter) + " = " + $3->field);
        $$->threeACCode.push_back("L" + to_string(lcounter-1) + ":");
        lcounter -= 2;
        $$->sz = $3->sz;
        $$->field = "t" + to_string(tcounter++);
    }
    $$->children.push_back($1);
    $$->children.push_back(new Node("?", "Separator", yylineno));
    $$->children.push_back($3);
    $$->children.push_back(new Node(":", "Separator", yylineno));
    $$->children.push_back($5);
};

AssignmentExpression : ConditionalExpression
{
    $$ = $1;
}
| Assignment
{
    $$ = $1;
};

Assignment : LeftHandSide AssignmentOperator Expression
{
    $$ = new Node("Assignment");
    if (!isDot)
    {
        if (widen($1->type, $3->type) != $1->type)
        {
            yyerror("Assignment Operation can only be applied to same type");
            exit(0);
        }
        if ($1->sz != $3->sz)
        {
            yyerror("Assignment Operation can only be applied to same size");
            exit(0);
        }
        if($1->isfinal){
            yyerror("Cannot re-assign a final variable");
            exit(0);
        }
        $$->type = $1->type;
        if($1->type > $3->type){
            $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
            $3->threeACCode.clear();
            $$->threeACCode.push_back("\tt" + to_string(tcounter) + " = " + "cast_to_" + enum_types[$1->type] + " " + $3->field);
            $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
            $1->threeACCode.clear();
            if ($2->field.size() > 1)
            {
                $$->threeACCode.push_back("\tt" + to_string(tcounter) + " = " + $1->field + " " + $2->field.substr(0, $2->field.size() - 1) + " t" + to_string(tcounter));
                $$->threeACCode.push_back("\t" + $1->field + " = " + "t" + to_string(tcounter));
            }
            else
            {
                $$->threeACCode.push_back("\t" + $1->field + " = t" + to_string(tcounter));
            }
        }
        else {
            $$->threeACCode.insert($$->threeACCode.end(), $3->threeACCode.begin(), $3->threeACCode.end());
            $3->threeACCode.clear();
            $$->threeACCode.insert($$->threeACCode.end(), $1->threeACCode.begin(), $1->threeACCode.end());
            $1->threeACCode.clear();
            if ($2->field.size() > 1)
            {
                $$->threeACCode.push_back("\tt" + to_string(tcounter) + " = " + $1->field + " " + $2->field.substr(0, $2->field.size() - 1) + " " + $3->field);
                $$->threeACCode.push_back("\t" + $1->field + " = " + "t" + to_string(tcounter));
            }
            else
            {
                $$->threeACCode.push_back("\t" + $1->field + " = " + $3->field);
            }
        }
        tcounter = 1;
        $$->field = $1->field;
        $$->sz = $1->sz;
        $3->arrdims.clear();
        $1->arrdims.clear();
    }
    $$->children.push_back($1);
    $$->children.push_back($2);
    $$->children.push_back($3);
};

LeftHandSide : Name
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
};

AssignmentOperator : o_assign
{
    $$ = new Node("=", "Separator", yylineno);
    $$->field = "=";
}
| o_add_assign
{
    $$ = new Node("+=", "Separator", yylineno);
    $$->field = "+=";
}
| o_subtract_assign
{
    $$ = new Node("-=", "Separator", yylineno);
    $$->field = "-=";
}
| o_multiply_assign
{
    $$ = new Node("*=", "Separator", yylineno);
    $$->field = "*=";
}
| o_divide_assign
{
    $$ = new Node("/=", "Separator", yylineno);
    $$->field = "/=";
}
| o_modulo_assign
{
    $$ = new Node("%=", "Separator", yylineno);
    $$->field = "%=";
}
| o_left_shift_assign
{
    $$ = new Node("<<=", "Separator", yylineno);
    $$->field = "<<=";
}
| o_right_shift_assign
{
    $$ = new Node(">>=", "Separator", yylineno);
    $$->field = ">>=";
}
| o_unsigned_right_shift_assign
{
    $$ = new Node(">>>=", "Separator", yylineno);
    $$->field = ">>>=";
}
| o_bitwise_and_assign
{
    $$ = new Node("&=", "Separator", yylineno);
    $$->field = "&=";
}
| o_bitwise_or_assign
{
    $$ = new Node("|=", "Separator", yylineno);
    $$->field = "|=";
}
| o_bitwise_xor_assign
{
    $$ = new Node("^=", "Separator", yylineno);
    $$->field = "^=";
};

Expression : AssignmentExpression
{
    $$ = $1;
};
%%

TYPE widen(TYPE a, TYPE b)
{
    return (a > b) ? a : b;
}

void traverse(Node *node, int &counter, ofstream &dotfile)
{
    node->count = counter++;
    dotfile << "  node" << node->count << " [label=\"" << node->token << "\\n"
            << node->id << "\"];" << endl;
    for (int i = 0; i < node->children.size(); i++)
    {
        int child_id = counter;
        dotfile << "  node" << node->count << " -> node" << child_id << ";" << endl;
        traverse(node->children[i], counter, dotfile);
    }
}

void print_dot(const char *filename)
{
    ofstream dotfile(filename);
    dotfile << "digraph PARSE_TREE {" << endl;
    int counter = 0;
    traverse(root, counter, dotfile);
    dotfile << "}" << endl;
    dotfile.close();
}

void symTab_csv(symtab *a)
{
    ofstream fout;
    string s = "symtab" + to_string(a->ID) + ".csv";
    fout.open(s);
    fout << "Lexeme,Tokens,ReturnType,ReturnDimensions,NumberofArguments,LineNo,Offset" << endl;
    for (auto i = a->entries.begin(); i != a->entries.end(); i++)
    {
        auto j = (i->second); 
        fout << i->first << ","<< "Identifier"<< "," << enum_types[j[0].type] << "," << j[0].size << "," << (j.size()-1) <<","<<j[0].lineno << "," << j[0].offset << endl;
    }
    fout.close();
}

void generate_3AC(string filename)
{
    ofstream fout;
    fout.open(filename);
    for (int i = 0; i < threeAC.size(); i++)
    {
        fout << threeAC[i] << endl;
    }
}

void check_semantics(string filename)
{
    for (auto i = symTables.begin(); i != symTables.end(); i++)
    {
        symTab_csv(&i->second);
    }
    generate_3AC(filename);
    if(!isMain){
        cout << "Error: No main function found" << endl;
        exit(0);
    }
    generate_quadraple(threeAC);
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "No input file specified" << endl;
        return 0;
    }

    int input_index = 0;
    int output_index = 0;
    bool flag_help = false;
    int t1 = 1;

    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];
        if (arg.find("--output=") == 0)
        {
            argv[i] = argv[i] + 9;
            output_index = i;
            t1++;
            continue;
        }
        else if (arg.find("--input=") == 0)
        {
            argv[i] = argv[i] + 8;
            input_index = i;
            t1++;
            continue;
        }
        else if (arg.find("--help") == 0)
        {
            flag_help = true;
            t1++;
            continue;
        }
        else if (arg.find("--verbose") == 0)
        {
            flag_verbose = true;
            t1++;
            continue;
        }
        else if (arg.find("--dot") == 0)
        {
            isDot = true;
            t1++;
            continue;
        }
        if (i == t1 && !input_index)
            input_index = i;
        if (i == t1 + 1 && !output_index)
            output_index = i;
    }

    if (flag_help)
    {
        cout << endl
             << "Usage: ./myASTGenerator [options] [input_file]}" << endl;
        cout << "Generates a Dot file for the AST representation for an input JAVA file" << endl
             << endl;
        cout << "Debugging : " << endl;
        cout << "\t--verbose\tsupports debugging of the input file" << endl
             << endl;
        cout << "Files : " << endl;
        cout << "\t--output=FILE\tspecify output filename" << endl;
        cout << "\t--input=FILE\tspecify input filename" << endl
             << endl;
        cout << "Miscellaneous : " << endl;
        cout << "\t--help\t\tproduces this help message" << endl
             << endl;
        cout << "By default the first argument will be treated as the input file and the second argument as the output file unless specified otherwise.\nIf there is only one argument, then it will be taken as the input file and the default name of the output file will be parse_tree.dot." << endl
             << endl;
        return 0;
    }

    if (!isDot)
    {
        initializeSymTable(currentSymTableId);
        yyin = fopen("System.java", "r");
        yyparse();
        yylineno = 1;
    }
    string file_name(argv[input_index]);
    file_name = file_name.substr(file_name.find_last_of("/\\") + 1);
    entryClass = file_name.substr(0, file_name.find_last_of("."));
    file_name.clear();

    if (argc > 1)
    {
        if (input_index)
            yyin = fopen(argv[input_index], "r");
        if (!yyin)
        {
            fprintf(stderr, "error: could not open file %s\n", argv[input_index]);
            return 1;
        }
    }
    else
    {
        yyin = stdin;
    }
    yyparse();
    if (root)
    {
        if (isDot)
        {
            if (output_index)
                print_dot(argv[output_index]);
            else
                print_dot("parse_tree.dot");
        }
        else
        {   
            if(output_index){
                check_semantics(argv[output_index]);
            }
            else{
                check_semantics("../tests/" + entryClass + ".3ac");
            }
        }
    }
    else
        printf("Error in generating the parse tree\nAborting...\n");
    return 0;
}