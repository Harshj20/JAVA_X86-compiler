#ifndef SYMTAB_H
#define SYMTAB_H
#include <bits/stdc++.h>
using namespace std;

enum TYPE{
    BIN,
    OCT,
    HEX_FLOAT,
    STRING,
    HEX,
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
    _NULL,
    BYTE,
    SHORT,
    CHAR,
    INT,
    LONG,
    FLOAT,
    DOUBLE
};
struct symEntry{
    TYPE type;
    int lineno;
    int size = 0;
    symEntry(TYPE type, int lineno){
        this->type = type;
        this->lineno = lineno;
    }
    symEntry(TYPE type, int lineno, int size){
        this->type = type;
        this->lineno = lineno;
        this->size = size;
    }
};

class symtab {
public:
    int parentID;
    int ID;
    map<string, vector<struct symEntry>> entries;

    symtab();

    symtab(int id, int parentID);

    void insertSymEntry(string lex, TYPE t, int line);
    void insertSymEntry(string lex, TYPE t, int line, int size);

    int lookup(string lex);

    int grand_lookup(string lex);

    vector<struct symEntry>* getSymEntry(string lex);

};
#endif
