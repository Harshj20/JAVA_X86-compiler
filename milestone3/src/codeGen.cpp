#include<bits/stdc++.h>
#include "codeGen.h"
using namespace std;
// vector<vector<string>> code_gen;

string ebp_offset_to_string(const std::string& s) {
    int offset = std::stoi(s.substr(4, s.size() - 5)); // extract the integer value from the string
    if (offset >= 0) {
        return std::to_string(offset) + "(%ebp)"; // format the new string for positive offset
    } else {
        return std::to_string(offset) + "(%ebp)"; // format the new string for negative offset
    }
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
                fout << "\tadd\t" << words[2] << ", " << words[4] << endl;
                fout << "\tmov\t" << words[0] << ", " << words[4] << endl;
            }
            else if(words[3][0] == '-'){
                fout << "\tsub\t" << words[2] << ", " << words[4] << endl;
                fout << "\tmov\t" << words[0] << ", " << words[4] << endl;
            }
            else if(words[3][0] == '*'){
                fout << "\timul\t" << words[2] << ", " << words[4] << endl;
                fout << "\tmov\t" << words[0] << ", " << words[4] << endl;
            }
            else if(words[3][0] == '/'){
                fout << "\tmov\t" << "%eax, " << words[2] << endl;
                fout << "\tmov\t" << "%ebx, " << words[4] << endl;
                fout << "\tcdq" << endl;
                fout << "\tidiv\t" << "%ebx" << endl;
                fout << "\tmov\t" << words[0] << ", " << "%eax" << endl;
            }
            else if(words[3][0] == '%'){
                fout << "\tmov\t" << "%eax, " << words[2] << endl;
                fout << "\tmov\t" << "%ebx, " << words[4] << endl;
                fout << "\tcdq" << endl;
                fout << "\tidiv\t" << "%ebx" << endl;
                fout << "\tmov\t" << words[0] << ", " << "%edx" << endl;
            }
            else if(words[3] == "=="){
                fout << "\tcmp\t" << words[2] << ", " << words[4] << endl;
                fout << "\tje\t" << words[0] << endl;
            }
            else if(words[3] == "!="){
                fout << "\tcmp\t" << words[2] << ", " << words[4] << endl;
                fout << "\tjne\t" << words[0] << endl;
            }
        }
        else{
            fout << i << endl;
        }

        // code_gen.push_back(words);
        words.clear();
    }
}