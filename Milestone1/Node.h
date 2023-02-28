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

    Node(string id) {
        this->id=id;
    }
    Node(string id, string token){
        this->id=id;
        this->token=token;
    }
};
#endif
