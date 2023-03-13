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
    UNKNOWN,
    VAR,
    _NULL
};
struct symEntry{
    TYPE type;
    symEntry(TYPE type){
        this->type = type;
    }
};

class symtab {
public:
    int parentID;
    int ID;
    map<string, vector<struct symEntry>> entries;

    symtab(){
        this->ID = -1;
        this->parentID = -1;
    }

    symtab(int id, int parentID) {
        this->ID = id;
        this->parentID = parentID; 
    }

    void insertSymEntry(string lex, TYPE t){
        this->entries[lex].push_back(*(new symEntry(t))); 
    }

    bool lookup(string lex){
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
