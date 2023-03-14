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
    bool isBlock = false;
    vector<Node*> children;
    TYPE literal_type = UNKNOWN;
    int lineno = -1;
    bool isArray = false;
    int size = 0;

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
        this->literal_type = type;
        this->lineno = lineno;
    }
};
#endif
