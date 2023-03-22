#ifndef THREEAC_H
#define THREEAC_H
#include <bits/stdc++.h>
#include "SymTable.h"
using namespace std;
struct threeACNode {
    string op="";
    string arg1="";
    string arg2="";
    string res="";
    threeACNode(const char* op, const char* arg1, const char* arg2, const char* res) {
        string s(op);
        this->op=s;
        string a1(arg1);
        this->arg1=a1;
        string a2(arg2);
        this->arg2=a2;
        string r(res);
        this->res=r;
    }
    threeACNode(const char* op, const char* arg1, const char* res) {
        string s(op);
        this->op=s;
        string a1(arg1);
        this->arg1=a1;
        string r(res);
        this->res=r;
    }
};
#endif
