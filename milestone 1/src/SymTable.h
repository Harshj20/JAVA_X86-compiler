#ifndef SYMTAB_H
#define SYMTAB_H
#include <bits/stdc++.h>
using namespace std;

struct symEntry{
    string type;
    symEntry(const char* type){
        string t(type);
        this->type=t;
    }
}

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
    void insertSymEntry(const char*lexeme, const char*type){
        struct symEntry* entry = new symEntry(type);
        this->entries
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