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
void symtab::insertSymEntry(string lex, TYPE t, int line, int size){
        this->entries[lex].push_back(*(new symEntry(t,line, size))); 
    }
void symtab::insertSymEntry(string lex, TYPE t, int line, int size, bool isfunction){
        this->entries[lex].push_back(*(new symEntry(t,line,size,isfunction))); 
    }

int symtab::lookup(string lex){
    int scopeID = this->ID;
    while(symTables[scopeID].isfunction){
        if(symTables[scopeID].entries.find(lex)==symTables[scopeID].entries.end()){
            scopeID =  symTables[scopeID].parentID;
        }
        else {
            return scopeID;
        }
    }
    if(symTables[scopeID].entries.find(lex)!=symTables[scopeID].entries.end()){
            return scopeID; 
    }
    return 0;
}

int symtab::grand_lookup(string lex){
    int scopeID = this->ID;
    while(symTables[scopeID].parentID>=0){
        if(symTables[scopeID].entries.find(lex)==symTables[scopeID].entries.end()){
            scopeID =  symTables[scopeID].parentID;
            if(scopeID==0)
                return 0;
        }
        else {
            return scopeID;
        }
    }
    return 0;
}


vector<struct symEntry>* symtab::getSymEntry(string lex){
    int scopeID = this->ID;
    while(scopeID){
        if(symTables[scopeID].entries.find(lex)==symTables[scopeID].entries.end()){
            scopeID =  symTables[scopeID].parentID;
        }
        else {
            return &symTables[scopeID].entries[lex];
        }
    }
    return NULL;
}
