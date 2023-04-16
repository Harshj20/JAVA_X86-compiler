#include<bits/stdc++.h>
#include "codeGen.h"
using namespace std;
map <string, string> reg_map;

set<string> reg_set = {"%r8", "%r9", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15"};

string ebp_offset_to_string(const string &s) {
    int offset = std::stoi(s.substr(4, s.size() - 5)); // extract the integer value from the string
    return to_string(offset) + "(%rbp)";
}

bool is_integer(const string &s) {
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;
    char * p ;
    strtol(s.c_str(), &p, 10) ;
    return (*p == 0) ;
}

bool istemp(const string &s) {
    if(s[0] == 't' || (s[0] == '(' && s[1] == 't'))
        return true;
    return false;
}

string updatetemp(const string &s) {
    if(s[0]=='(' && s[1]=='t')
        return  "(" + reg_map[s] + ")";
    else 
        return reg_map[s];
}

void generate_quadraple(vector<string> &threeAC){
    ofstream fout;
    fout.open("code.s");
    for(auto i : threeAC){
        if(i.empty())
            continue;
        stringstream ss(i);
        vector<string> words;

        string word;
        while (ss >> word) {
            if(word[0] == '[')
                words.push_back(ebp_offset_to_string(word));
            else
                words.push_back(word);
        }
        if(words.size()==3){
            if(istemp(words[0]) && istemp(words[2]) && reg_map.find(words[0]) == reg_map.end()){
                reg_map[words[0]] = reg_map[words[2]];
                words[2] = updatetemp(words[2]);
                reg_map.erase(words[2]);
            }
            else if(istemp(words[0])){
                reg_map[words[0]] = *reg_set.begin();
                reg_set.erase(reg_set.begin());
            }
            else if(istemp(words[2])){
                reg_set.insert(reg_map[words[2]]);
                words[2] = updatetemp(words[2]);
                reg_map.erase(words[2]);
            }
        }
        else if(words.size()==5){
            if(istemp(words[2]) && istemp(words[4])){
                if(reg_map.find(words[0]) != reg_map.end()){
                    if(words[0] != words[2]){
                        reg_set.insert(reg_map[words[2]]);
                        words[2] = updatetemp(words[2]);
                        reg_map.erase(words[2]);
                    }
                    if(words[0] != words[4]){
                        reg_set.insert(reg_map[words[4]]);
                        words[4] = updatetemp(words[4]);
                        reg_map.erase(words[4]);
                    }
                }
                else{
                    reg_map[words[0]] = reg_map[words[2]];
                    words[2] = updatetemp(words[2]);
                    reg_map.erase(words[2]);
                    reg_set.insert(reg_map[words[4]]);
                    words[4] = updatetemp(words[4]);
                    reg_map.erase(words[4]);
                }
            }
            else if(istemp(words[2])){
                if(words[0] != words[2]){
                    reg_map[words[0]] = reg_map[words[2]];
                    words[2] = updatetemp(words[2]);
                    reg_map.erase(words[2]);
                    words[4] = "$" + words[4];
                }
            }
            else if(istemp(words[4])){
                if(words[0] != words[4]){
                    reg_map[words[0]] = reg_map[words[4]];
                    words[4] = updatetemp(words[4]);
                    reg_map.erase(words[4]);
                    words[2] = "$" + words[2];
                    swap(words[2],words[4]);
                }
            }
            else{
                fout << "\tmovq\t" << "$" + words[2] << ", " << *reg_set.begin() << endl;
                reg_map[words[0]] = *reg_set.begin();
                words[4] = "$" + words[4];
                words[2] = reg_map[words[0]];
                reg_set.erase(reg_set.begin());
            }
        }

        for(int i = 0; i < words.size(); i++){
            if(reg_map.find(words[i]) != reg_map.end())
                words[i] = updatetemp(words[i]);
            else if(words[i][0] == '('){
                string s = words[i].substr(1, words[i].size() - 2);
                if(reg_map.find(s) != reg_map.end())
                    words[i] = updatetemp(s);
            }
        }

        if(words[0] == "if"){
            fout << "\ttest " << words[1] <<", " << words[1]<<endl;
            fout << "\tjz " << words[3] << endl;
        }
        else if(words[0] == "goto"){
            fout << "\tjmp " << words[1] << endl; 
        }
        else if(words.size() == 3){
            fout << "\tmov\t" << words[2] << ", " << words[0] << endl;
        }
        else if(words.size() == 5){
            if(words[3][0] == '+'){
                fout << "\taddq\t" << words[4] << ", " << words[2] << endl;
                if(words[0] != words[2])
                fout << "\tmovq\t" << words[2] << ", " << words[0] << endl;
            }
            else if(words[3][0] == '-'){
                fout << "\tsubq\t" << words[4] << ", " << words[2] << endl;
                if(words[0] != words[2])
                fout << "\tmovq\t" << words[2] << ", " << words[0] << endl;
            }
            else if(words[3][0] == '*'){
                fout << "\timulq\t" << words[4] << ", " << words[2] << endl;
                if(words[0] != words[2])
                fout << "\tmovq\t" << words[2] << ", " << words[0] << endl;
            }
            else if(words[3][0] == '/') {
                fout << "\tmovq\t" << words[2] << ", %rax" << endl;
                fout << "\tcqto" << endl;
                fout << "\tidivq\t" << words[4] << endl;
                fout << "\tmovq\t" << "%rax" << ", " << words[0] << endl;
            }
            else if(words[3][0] == '%') {
                fout << "\tmovq\t" << words[2] << ", %rax" << endl;
                fout << "\tcqto" << endl;
                fout << "\tidivq\t" << words[4] << endl;
                fout << "\tmovq\t" << "%rdx" << ", " << words[0] << endl;
            }
        }
        else{
            fout << i << endl;
        }

        words.clear();
    }
}