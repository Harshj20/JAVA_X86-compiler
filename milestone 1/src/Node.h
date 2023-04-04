#ifndef NODE_H
#define NODE_H
#include <bits/stdc++.h>
#include "SymTable.h"
using namespace std;
class Node {
public:
    string id;
    unsigned int count=0;
    string token="";    
    vector<Node*> children;
    TYPE type = UNKNOWN;
    int lineno = -1;
    int sz = 0;
    int symid=1;
    string field="";
    vector<string>threeACCode;
    vector<string> arrdims;

    Node(const char* id) {
        string s(id);
        this->id=s;
    }
    // Node(const char*id, TYPE type){
    //     string s(id);
    //     this->id=s;
    //     this->literal_type = type;
    // }
    Node(const char* id,const char* token, int lineno){
        string s(id);
        this->id=s;
        string t(token);
        this->token=t;
        this->lineno = lineno;
    }
    Node(const char*id, const char* token, TYPE type, int lineno){
        string s(id);
        this->id=s;
        string t(token);
        this->token=t;
        this->type = type;
        this->lineno = lineno;
    }
};
#endif
