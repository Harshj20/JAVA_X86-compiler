#include<bits/stdc++.h>
#include "codeGen.h"
using namespace std;
// vector<vector<string>> code_gen;
map <string, string> reg_map;

string ebp_offset_to_string(const string &s) {
    int offset = std::stoi(s.substr(4, s.size() - 5)); // extract the integer value from the string
    return to_string(offset) + "(%rbp)";
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
                fout << "\taddq\t" << words[2] << ", " << words[4] << endl;
                fout << "\tmovq\t" << words[0] << ", " << words[4] << endl;
            }
            else if(words[3][0] == '-'){
                fout << "\tsubq\t" << words[2] << ", " << words[4] << endl;
                fout << "\tmovq\t" << words[0] << ", " << words[4] << endl;
            }
            else if(words[3][0] == '*'){
                fout << "\timulq\t" << words[2] << ", " << words[4] << endl;
                fout << "\tmovq\t" << words[0] << ", " << words[4] << endl;
            }
            else if(words[3][0] == '/'){
                fout << "\tmovq\t" << words[2] << ", %rax" << endl;
                fout << "\tcqo" << endl;
                fout << "\tidivq\t" << words[4] << endl;
                fout << "\tmovq\t" << words[0] << ", %rax" << endl;
            }
            else if(words[3][0] == '%'){
                fout << "\tmovq\t" << words[2] << ", %rax" << endl;
                fout << "\tcqo" << endl;
                fout << "\tidivq\t" << words[4] << endl;
                fout << "\tmovq\t" << words[0] << ", %rdx" << endl;
            }
        }
        else{
            fout << i << endl;
        }

        // code_gen.push_back(words);
        words.clear();
    }
}