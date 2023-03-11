#ifndef SYMTAB_H
#define SYMTAB_H
#include <bits/stdc++.h>
using namespace std;

enum TYPE{
    INT,
    FLOAT,
    CHAR,
    BOOL,
    VOID,
    STRING,
    ARRAY,
    STRUCT,
    FUNCTION,
    CLASS,
    INTERFACE,
    ENUM,
    UNION,
    TYPEDEF,
    UNKNOWN
}
struct symEntry{
    TYPE type;
    symEntry(TYPE type){
        this->type = type;
    }
};

class symtab {
public:
    string parentID = "";
    string ID = "";
    map<string, vector<struct symEntry>> entries;

    symtab(const char* id, const char* parentID) {
        string a(id);
        this->ID = a;
        string b(parentID);
        this->parentID = b; 
    }

    void insertSymEntry(const char*lexeme, int count, ...){
        string lex(lexeme);

        va_list args;          
        va_start(args, count); 

        for (int i = 0; i < count; i++) {
            this->entries[lex].push_back(*(new sumEntry(va_arg(args, TYPE)))); 
        }

        va_end(args);
    }

    bool lookup(const char*lexeme){
        string lex(lexeme)
        if(this->entries.find(lex)!=this->entries.end()){
            return true;
        }
        return false;
    }
    
    vector<struct symEntry> getSymEntry(const char*lexeme){
        string lex(lexeme)
        if(this->entries.find(lex)!=this->entries.end()){
            return this->entries[lex];
        }
        return NULL;
    }

};
#endif
