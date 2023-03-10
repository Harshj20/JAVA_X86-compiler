#ifndef NODE_H
#define NODE_H
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    string id;
    unsigned int count=0;
    string token="";
    bool isBool = false;
    vector<Node*> children;

    Node(const char* id, bool isBool = false) {
        string s(id);
        this->id=s;
        this->isBool = isBool
    }
    Node(const char* id,const char* token, bool isBool = false){
        string s(id);
        this->id=s;
        string t(token);
        this->token=t;
        this->isBool = isBool;
    }
};
#endif
