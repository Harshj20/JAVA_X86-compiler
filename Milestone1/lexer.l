%{
    #include<bits/stdc++.h>
    using namespace std;
    unordered_map<string,pair<string,int>>m;
    vector<string>v;
    
%}
Keyword abstract|continue|for|new|switch|assert|default|if|package|synchronized|boolean|do|goto|private|this|break|double|implements|protected|throw|byte|else|import|public|throws|case|enum|instanceof|return|transient|catch|extends|int|short|try|char|final|interface|static|void|class|finally|long|strictfp|volatile|const|float|native|super|while|_|exports|opens|requires|uses
module|permits|sealed|var|non-sealed|provides|to|with|open|record|transitive|yield
Decimal [0-9]

Integer [1-9][lL]?|[1-9][0-9_]*[0-9]+[lL]?

deci_floats [0-9]*"."[0-9]+[fFdD]?|[0-9]+"."[0-9]*[fFdD]?|[0-9][0-9_]*[0-9]+"."[0-9]*[fFdD]?|[0-9]*"."[0-9][0-9_]*[0-9]+[fFdD]|[+-][0-9][0-9_]*[0-9]+"."[0-9][0-9_]*[0-9]+[fFdD]?

hex_floats 0[xX][0-9a-fA-F]*"."[0-9a-fA-F]+|0[xX][0-9a-fA-F]+"."[0-9a-fA-F]*|0[xX][0-9a-fA-F][0-9a-fA-F_]*[0-9a-fA-F]+"."[0-9a-fA-F]*|0[xX][0-9a-fA-F]*"."[0-9a-fA-F][0-9a-fA-F_]*[0-9a-fA-F]+|0[xX][0-9a-fA-F][0-9a-fA-F_]*[0-9a-fA-F]+"."[0-9a-fA-F][0-9a-fA-F_]*[0-9a-fA-F]+
line_terminators \n|\r|\r\n

%option noyywrap c++
%option yylineno

%%
"/*"[^*/]*"*/" 
"//".*\n
{Keyword}   {   string s =yytext ; 
                //cout<<" Keyword ";
                if(m.find(s)==m.end()){
                    v.push_back(s);
                    m[s]=make_pair("Keyword",1);
                }
                else
                    m[s]=make_pair("Keyword",m[s].second+1);
            }
            
[@]|[,]|[;]|"::"|"("|")"|"["|"]"|[.]|"..."|"{"|"}"      {   string s =yytext ;
                                                            //cout<<" Separator ";
                                                            if(m.find(s)==m.end()){
                                                                v.push_back(s);
                                                                m[s]=make_pair("Separator",1);
                                                            }
                                                            else
                                                                m[s]=make_pair("Separator",m[s].second+1);
                                                        }

"!"|"!="|"~"|"?"|":"|"&&"|"||"|"++"|"--"|"&"|"^"|"%"|"<<"|">>"|">>>"|"+="|"-="|"*="|"/="|"&="|"|="|"^="|"%="|"<<="|">>="|">>>="|"+"|"-"|"*"|"/"|"=="|"="|"->"|"<"|"<="|">"|">="     {   string s =yytext ; 
                                                    //cout<<yytext<<" Operator ";
                                                    if(m.find(s)==m.end()){
                                                        v.push_back(s);
                                                        m[s]=make_pair("Operator",1);
                                                    }
                                                    else
                                                        m[s]=make_pair("Operator",m[s].second+1);
                                                }

"true"|"false"|"null"  {   string s =yytext ; 
                //cout<<" Boolean ";
                if(m.find(s)==m.end()){
                    v.push_back(s);
                    m[s]=make_pair("Literal",1);
                }
                else
                    m[s]=make_pair("Literal",m[s].second+1);
                }

[a-zA-Z][a-zA-Z0-9_]*|[_]+[a-zA-Z0-9]+    {   string s =yytext ;
                            //cout<<" Identifier ";
                            if(m.find(s)==m.end()){
                                v.push_back(s);
                                m[s]=make_pair("Identifier",1);
                            }
                            else
                                m[s]=make_pair("Identifier",m[s].second+1);
                        }

\"\"\"{line_terminators}+.*\"\"\"   {cout<<"text Block";}

{Integer}"..."            { string s=yytext;
                            string s1;
                            int i=0;
                            while(s[i]>='0' && s[i]<='9'){
                                s1.push_back(s[i]);
                                i++;
                            }
                            if(m.find(s1)==m.end()){
                                v.push_back(s1);
                                m[s1]=make_pair("Literal",1);
                            }       
                            else
                                m[s1]=make_pair("Literal",m[s1].second+1);
                            if(m.find("...")==m.end()){
                                v.push_back("...");
                                m["..."]=make_pair("Literal",1);
                            }       
                            else
                                m["..."]=make_pair("Literal",m["..."].second+1);
                        }

{Integer}   {   string s =yytext ; 
                //cout<<" Integer ";
                if(m.find(s)==m.end()){
                    v.push_back(s);
                    m[s]=make_pair("Literal",1);
                }       
                else
                    m[s]=make_pair("Literal",m[s].second+1);
            }

{deci_floats}|{deci_floats}[eE]{deci_floats}|{Integer}[eE]{deci_floats}|{deci_floats}[eE]{Integer}|{Integer}[eE]{Integer}    {   string s =yytext ; 
                //cout<<" Decimal Float ";
                if(m.find(s)==m.end()){
                    v.push_back(s);
                    m[s]=make_pair("Literal",1);
                }
                else
                    m[s]=make_pair("Literal",m[s].second+1);
            }
                                                            
0[xX][0-9a-fA-F]|0[xX][0-9a-fA-F][0-9a-fA-F_]*[0-9a-fA-F]   {   string s =yytext ; 
                                                                //cout<<" Hexadecimal ";
                                                                if(m.find(s)==m.end()){
                                                                    v.push_back(s);
                                                                    m[s]=make_pair("Literal",1);
                                                                }
                                                                else
                                                                    m[s]=make_pair("Literal",m[s].second+1);
                                                            }

{hex_floats}|{hex_floats}[pP]{Integer}      {   string s =yytext ; 
                                                //cout<<" Hexadecimal Float ";
                                                if(m.find(s)==m.end()){
                                                    v.push_back(s);
                                                    m[s]=make_pair("Literal",1);
                                                }
                                                else
                                                    m[s]=make_pair("Literal",m[s].second+1);
                                            }


0[bB][01]|0[bB][01][01_]*[01]+  {   string s =yytext ; 
                                    //cout<<" Binary ";
                                    if(m.find(s)==m.end()){
                                        v.push_back(s);
                                        m[s]=make_pair("Literal",1);
                                    }
                                    else
                                        m[s]=make_pair("Literal",m[s].second+1);
                                }

0|0[0-9_]*[0-9]+  {   string s =yytext ; 
                    //cout<<" Octal ";
                    if(m.find(s)==m.end()){
                        v.push_back(s);
                        m[s]=make_pair("Literal",1);
                    }
                    else
                        m[s]=make_pair("Literal",m[s].second+1);
                }

\"[^\"]*\"       {   string s =yytext ; 
                    //cout<<" String ";
                    if(m.find(s)==m.end()){
                        v.push_back(s);
                        m[s]=make_pair("Literal",1);
                    }
                    else
                        m[s]=make_pair("Literal",m[s].second+1);
                }
\'[^\']\' {cout<<"char ";}
\b|\n|\t|\r|\r\n|" "

. {cout<<"Unidentified character "<<yytext<<" in line "<<yylineno<<endl;}
%%

int main(){
    ofstream fout; ifstream fin;
    v.clear();
    m.clear();
    fin.open("BubbleSort.java"); // Enter the test-file name here 
    FlexLexer* lexer=new yyFlexLexer(fin,fout);
    lexer->yylex();
    fin.close();
    int n=v.size();
    fout.open("JAVA_Token_File.csv"); // Output file
    fout<<"Lexeme,Tokens,Count"<<endl;
    for(int i=0;i<n;i++)
        fout<<v[i]<<","<<m[v[i]].first<<","<<m[v[i]].second<<endl;
    fout.close();
    return 0;
}
