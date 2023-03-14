#include "SymTable.h"
map<unsigned long long int, symtab> symTables; 

symtab::symtab(){
        this->ID = -1;
        this->parentID = -1;

    }

symtab::symtab(int id, int parentID) {
        this->ID = id;
        this->parentID = parentID; 
    }

void symtab::insertSymEntry(string lex, TYPE t, int line){
        this->entries[lex].push_back(*(new symEntry(t,line))); 
    }

int symtab::lookup(string lex){
    int scopeID = this->ID;
    while(scopeID){
        if(symTables[scopeID].entries.find(lex)==symTables[scopeID].entries.end()){
            scopeID =  symTables[scopeID].parentID;
        }
        else {
            return symTables[scopeID].entries[lex][0].lineno;
        }
    }
    return 0;
}

vector<struct symEntry>* symtab::getSymEntry(string lex){

        if(this->entries.find(lex)!=this->entries.end()){
            return &this->entries[lex];
        }
        return NULL;
    }
