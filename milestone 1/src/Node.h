#ifndef NODE_H
#define NODE_H
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    string id;
    unsigned int count=0;
    string token="";
    vector<Node*> children;

    Node(const char* id) {
        string s(id);
        this->id=s;
    }
    Node(const char* id,const char* token){
        string s(id);
        this->id=s;
        string t(token);
        this->token=t;
    }
};
#endif
