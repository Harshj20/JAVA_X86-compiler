#ifndef SYMTAB_H
#define SYMTAB_H
#include <bits/stdc++.h>
using namespace std;

enum TYPE{
    BIN,
    OCT,
    HEX_FLOAT,
    HEX,
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
    DOUBLE,
    STRING,
    BOOL,
    OBJECT
};
struct symEntry{
    TYPE type;
    int lineno;
    int sz = 0;
    bool isfunction = false;
    int symid = 0;
    bool isPrivate = false;
    bool isStatic = false;
    int offset = 0;
    string dimsize = "";
    symEntry(TYPE type, int lineno){
        this->type = type;
        this->lineno = lineno;
    }
    symEntry(TYPE type, int lineno, int sz){
        this->type = type;
        this->lineno = lineno;
        this->sz = sz;
    }
    symEntry(TYPE type, int lineno, int sz, bool isfunction){
        this->type = type;
        this->lineno = lineno;
        this->sz = sz;
        this->isfunction = isfunction;
    }
};

class symtab {
public:
    int parentID;
    int ID;
    bool isfunction = false;
    string name = "";
    map<string, vector<struct symEntry>> entries;

    symtab();

    symtab(int id, int parentID);

    void insertSymEntry(string lex, TYPE t, int line);
    void insertSymEntry(string lex, TYPE t, int line, int sz);
    void insertSymEntry(string lex, TYPE t, int line, int sz, bool isfunction);

    int lookup(string lex);

    int grand_lookup(string lex);

    vector<struct symEntry>* getSymEntry(string lex);

};
#endif
