#ifndef SYMTAB_H
#define SYMTAB_H
#include <bits/stdc++.h>
using namespace std;

enum TYPE{
    INT,
    BIN,
    FLOAT,
    OCT,
    HEX_FLOAT,
    STRING,
    HEX,
    CHAR,
    BOOL,
    VOID,
    FUNCTION,
    CLASS,
    INTERFACE,
    ENUM,
    UNION,
    TYPEDEF,
    UNKNOWN
};
struct symEntry{
    TYPE type;
    symEntry(TYPE type){
        this->type = type;
    }
};

class symtab {
public:
    int parentID = -1;
    int ID = -1;
    map<string, vector<struct symEntry>> entries;

    symtab(int id, int parentID) {
        this->ID = id;
        this->parentID = parentID; 
    }

    void insertSymEntry(const char*lexeme, int count, ...){
        string lex(lexeme);

        va_list args;          
        va_start(args, count); 

        for (int i = 0; i < count; i++) {
            struct symEntry *a = new symEntry(va_arg(args, TYPE));
            this->entries[lex].push_back(*a); 
        }

        va_end(args);
    }

    bool lookup(const char*lexeme){
        string lex(lexeme);
        if(this->entries.find(lex)!=this->entries.end()){
            return true;
        }
        return false;
    }

    vector<struct symEntry>* getSymEntry(const char*lexeme){
        string lex(lexeme);
        if(this->entries.find(lex)!=this->entries.end()){
            return &this->entries[lex];
        }
        return NULL;
    }

};
#endif
