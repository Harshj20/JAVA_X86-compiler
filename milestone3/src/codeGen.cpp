#include<bits/stdc++.h>

using namespace std;
vector<vector<string>> code_gen;

void generate_quadraple(vector<string>&threeAC){
    for(auto i : threeAC){
        if(i.empty())
            continue;
        stringstream ss(i);
        vector<string> words;

        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        code_gen.push_back(words);
        words.clear();
    }
}