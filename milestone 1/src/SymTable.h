#ifndef SYMTAB_H
#define SYMTAB_H
#include <bits/stdc++.h>
using namespace std;

public enum TYPE{
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
    map<string, struct symEntry> entries;
    symtab(const char* id, const char* parentID) {
        string a(id);
        this->ID = a;
        string b(parentID);
        this->parentID = b; 
    }
    void insertSymEntry(const char*lexeme, TYPE type){
        string lex(lexeme);
        struct symEntry* entry = new symEntry(type);
        this->entries[lex] = *entry;
    }
    bool lookup(const char*lexeme){
        string lex(lexeme)
        if(this->entries.find(lex)!=this->entries.end()){
            return true;
        }
        return false;
    }
    symEntry getSymEntry(const char*lexeme){
        string lex(lexeme)
        if(this->entries.find(lex)!=this->entries.end()){
            return this->entries[lex];
        }
        return NULL;
    }

};
#endif
