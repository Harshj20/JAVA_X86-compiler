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
    bool isBool = false;
    vector<Node*> children;
    TYPE literal_type;

    Node(const char* id, bool isBool = false, TYPE type = UNKNOWN) {
        string s(id);
        this->id=s;
        this->isBool = isBool
        this->literal_type = type;
    }
    Node(const char* id,const char* token, bool isBool = false, TYPE type = UNKNOWN){
        string s(id);
        this->id=s;
        string t(token);
        this->token=t;
        this->isBool = isBool;
        this->literal_type = type;
    }
};
#endif
