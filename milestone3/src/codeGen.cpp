#include<bits/stdc++.h>
#include "codeGen.h"
using namespace std;
map <string, string> reg_map;

set<string> reg_set = {"%r8", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15"};
bool isr9 = false;

string ebp_offset_to_string(const string &s) {
    int offset = std::stoi(s.substr(5, s.size() - 6)); // extract the integer value from the string
    return to_string(offset) + "(%rbp)";
}

bool is_integer(const string &s) {
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;
    char * p ;
    strtol(s.c_str(), &p, 10) ;
    return (*p == 0) ;
}

string extract(const string &s){
    if(s[0] == '(')
        return s.substr(1, s.size() - 2);
    return s;
}
bool isReg(const string &s){
    if(s[0] == '%' || s[0] == '[' && s[1] == '%')
        return true;
    return false;
}
bool istemp(const string &s) {
    if((s[0] == 't' && s[1] != 'h')|| (s[0] == '(' && s[1] == 't'))
        return true;
    return false;
}

bool isMemRem(const string &s) {
    int n = s.length();
    if(s[n-1] == ')')
        return true;
    return false;
}

string updatetemp(bool del, const string &s) {
    string ret = "";
    if(s[0]=='(' && s[1]== 't')
        ret = "(" + reg_map[extract(s)] + ")";
    else 
        ret = reg_map[s];
    if(del){
        reg_map.erase(extract(s));
    }
    return ret;
}

void generate_quadraple(vector<string> &threeAC){

    ofstream fout;
    fout.open("code.s");

    //--------------------------- Support println -----------------------------

    fout << ".LC0:" << endl;
	fout << "\t.string  \"%d\\n\"" << endl;
    fout << "\t.text" << endl;
    fout << "\t.globl main" << endl;
    fout << "System.println:" << endl;
    fout << "\tpushq\t%rbp" << endl;
    fout << "\tmovq\t%rsp, %rbp" << endl;
    fout << "\tmovq\t24(%rbp), %rsi" << endl;
	fout << "\tleaq\t.LC0(%rip), %rdi" << endl;
	fout << "\tmovq\t$0, %rax" << endl;
	fout << "\tcall printf@PLT" << endl;
	fout << "\tmovq\t$0, %rax" << endl;
    fout << "\tmovq\t%rbp, %rsp" << endl;
    fout << "\tpopq\t%rbp" << endl;
    fout << "\tret\n" << endl;

    //------------------------ 3AC Scan Start --------------------------------

    for(int i = 0; i != threeAC.size(); i++){

        if(threeAC[i].empty()){
            fout<<endl;
            continue;
        }

        stringstream ss(threeAC[i]);
        vector<string> words;   // to store the broken 3AC

        string word;    

        while (ss >> word) {
            if(word[0] == '[')
                words.push_back(ebp_offset_to_string(word));
            else if(is_integer(word))
                words.push_back("$" + word);
            else if(word[0] == 'L' && word[1] == '-'){
                word[1] = '.';
                words.push_back(word);
            }
            // else if(word[0] == '(' && reg_map[word].find("%rbp") != string::npos){
            //     fout << "\tmovq\t" << reg_map[word] << ", " << *(reg_set.begin()) << endl;
            //     reg_map[word] = *(reg_set.begin());
            //     reg_set.erase(reg_set.begin());
            // }
            else
                words.push_back(word);
        }

        // -----------------------------  Reg Alloc for size = 2 -----------------------------

        if(words.size() == 2){
            if(words[0][0] == 'p'){
                if(istemp(words[1])){
                    if(reg_map[extract(words[1])] == "%r9")
                        isr9 = false;
                    else
                        reg_set.insert(reg_map[extract(words[1])]);
                    words[1] = updatetemp(true, words[1]);
                }
            }
        }
        

        //----------------------- Reg alloc for size = 3 -----------------------

        else if(words.size()==3){
            if(istemp(words[0]) && istemp(words[2])){
                if(!isMemRem(words[0])){
                    // if(isMemRem(words[2])){   // t1 = (t2)
                    //     // if(isMemRem(reg_map[extract(words[2])])){ // t2 = (%rbp)
                    //     //     fout << "\tmovq\t" << reg_map[extract(words[2])] << ", " << *(reg_set.begin()) << endl;
                    //     //     reg_map[extract(words[2])] = *(reg_set.begin());
                    //     // }
                        reg_map[extract(words[0])] = reg_map[extract(words[2])];
                        words[2] = updatetemp(true, words[2]);
                    // }
                    // else{   // t1 = t2
                    //     // if(isMemRem(reg_map[extract(words[2])])){ // t2 = (%rbp)
                    //     //     fout << "\tmovq\t" << reg_map[extract(words[2])] << ", " << *(reg_set.begin()) << endl;
                    //     //     reg_map[extract(words[2])] = *(reg_set.begin());
                    //     // }
                    //     reg_map[extract(words[0])] = reg_map[extract(words[2])];
                    //     words[2] = updatetemp(true, words[2]);
                    // }
                }
                else{
                    if(isMemRem(words[2])){   // (t1) = (t2)
                        // if(isMemRem(reg_map[extract(words[2])])){ // t2 = (%rbp)
                        //     fout << "\tmovq\t" << reg_map[extract(words[2])] << ", " << *(reg_set.begin()) << endl;
                        //     reg_map[extract(words[2])] = *(reg_set.begin());
                        // }
                        string s1 = words[2];
                        if(reg_map[extract(words[2])] == "%r9")
                            isr9 = false;
                        else
                            reg_set.insert(reg_map[extract(words[2])]);
                        words[2] = updatetemp(false, words[2]);
                        fout << "\tmovq\t" << words[2] << ", " << reg_map[extract(s1)] << endl;
                        words[2] = extract(updatetemp(true, s1));
                    }
                    else{   // (t1) = t2
                        // if(isMemRem(reg_map[extract(words[2])])){ // t2 = (%rbp)
                        //     fout << "\tmovq\t" << reg_map[extract(words[2])] << ", " << *(reg_set.begin()) << endl;
                        //     reg_map[extract(words[2])] = *(reg_set.begin());
                        // }
                        if(reg_map[extract(words[2])] == "%r9")
                            isr9 = false;
                        else
                            reg_set.insert(reg_map[extract(words[2])]);
                        words[2] = updatetemp(true, words[2]);
                    }
                    if(reg_map[extract(words[0])] == "%r9")
                        isr9 = false;
                    else
                        reg_set.insert(reg_map[extract(words[0])]);
                    words[0] = updatetemp(true, words[0]);
                }
            }

            else if(istemp(words[0])){ 
                if(!isMemRem(words[0])){
                    //if(isMemRem(words[2])) // t1 = (%rbp){
                        if(reg_map.find(extract(words[0])) == reg_map.end()){  
                            if(words[2] == "%rax" && !isr9){
                                reg_map[extract(words[0])] = "%r9";
                                isr9 = true;
                            }
                            else{
                                reg_map[extract(words[0])] = *(reg_set.begin());
                                reg_set.erase(reg_set.begin());
                            }
                        }
                    //}
                    // else{  // t1 = $1
                    //     reg_map[extract(words[0])] = *(reg_set.begin());
                    //     reg_set.erase(reg_set.begin());
                    // }
                }
                else{
                    if(isMemRem(words[2])) { // (t1) = (%rbp)
                        fout << "\tmovq\t" << words[2] << ", " << *(reg_set.begin()) << endl;
                        words[2] = *(reg_set.begin());
                        // reg_set.erase(reg_set.begin());
                        if(reg_map[extract(words[0])] == "%r9")
                            isr9 = false;
                        else
                            reg_set.insert(reg_map[extract(words[0])]);
                        words[0] = updatetemp(true, words[0]);
                    }
                }
            }
            
            else if(istemp(words[2])){
                if(isMemRem(words[2])){ // ebp = (t)
                    string s1 = words[2];
                    if(reg_map[extract(words[1])] == "%r9")
                        isr9 = false;
                    else
                        reg_set.insert(reg_map[extract(words[2])]);
                    words[2] = updatetemp(false, words[2]);
                    fout << "\tmovq\t" << words[2] << ", " << reg_map[extract(s1)] << endl;
                    words[2] = extract(updatetemp(true, s1));
                }
                else{ // ebp = t
                    if(reg_map[extract(words[2])] == "%r9")
                        isr9 = false;
                    else
                        reg_set.insert(reg_map[extract(words[2])]);
                    words[2] = updatetemp(true, words[2]);
                }
            }

            else{
                if(isMemRem(words[2])){  // ebp = ebp
                    fout << "\tmovq\t" << words[2] << ", " << *(reg_set.begin()) << endl;
                    words[2] = *(reg_set.begin());
                }
            }
        }
        
        else if(words.size() == 4){
            if(istemp(words[0])){
                reg_map[extract(words[0])] = reg_map[extract(words[3])];
                words[3] = updatetemp(true, words[3]);
            }
        }
        

        //---------------------------- size = 5 ----------------------

        else if(words.size() == 5){
            if(isMemRem(words[2])){ // () + somthing
                if(istemp(words[2])){
                    string s1 = words[2];
                    if(reg_map[extract(words[2])] == "%r9")
                        isr9 = false;
                    else
                        reg_set.insert(reg_map[extract(words[2])]);
                    words[2] = updatetemp(false, words[2]);
                    fout << "\tmovq\t" << words[2] << ", " << reg_map[extract(s1)] << endl;
                    words[2] = extract(updatetemp(true, s1));
                }
                else{
                    fout << "\tmovq\t" << words[2] << ", " << *(reg_set.begin()) << endl;
                    words[2] = *(reg_set.begin());
                }
            }
            else{
                if(istemp(words[2])){
                    if(reg_map[extract(words[2])] == "%r9")
                        isr9 = false;
                    else
                        reg_set.insert(reg_map[extract(words[2])]);
                    words[2] = updatetemp(true, words[2]);
                }
                else if (words[2] == "%rsp"){
                    // rsp = rsp - constant
                }
                else{
                    fout << "\tmovq\t" << words[2] << ", " << *(reg_set.begin()) << endl;
                    words[2] = *(reg_set.begin());
                }
            }
            //------------by now words 2 is just a normal register like %r10 and its mapping is lost

            if(istemp(words[4])){ // c + (t) or t
                if(reg_map[extract(words[4])] == "%r9")
                        isr9 = false;
                else
                    reg_set.insert(reg_map[extract(words[4])]);
                words[4] = updatetemp(true, words[4]);
            }
            //----------by now mapping of words[4] is lost and words 4 is just a normal register or a (register) or a some constant
            if(istemp(words[0])){ // 
                if(isMemRem(words[0])){ // (t) = 
                    if(reg_map[extract(words[0])] == "%r9")
                        isr9 = false;
                    else
                        reg_set.insert(reg_map[extract(words[0])]);
                    words[0] = updatetemp(true, words[0]);
                }
                else if(reg_map.find(extract(words[0])) == reg_map.end()){
                    reg_map[extract(words[0])] = words[2];
                    reg_set.erase(words[2]);
                }
            }
        }
        cout<<reg_set.size() << " "
        for(int i = 0; i < words.size(); i++){
            if(reg_map.find(extract(words[i])) != reg_map.end())
                words[i] = updatetemp(false, words[i]);
        }

        //---------------------------------------------------

        if(words.size() == 4){
            if(words[0] == "if"){
                fout << "\ttest\t" << words[1] <<", " << words[1]<<endl;
                fout << "\tjnz\t" << words[3] << endl;
            }
            else if(words[2] == "allocate"){
                fout << "\tmovq\t" << words[3] << ", %rdi" << endl;
                fout << "\tcall\tmalloc@PLT" << endl;
                fout << "\tmovq\t%rax, " << words[0] << endl;
            }
        }

        //---------------------------------------------------------

        else if(words[0] == "goto"){
            fout << "\tjmp\t" << words[1] << endl; 
        }

        //----------------------------------------------------------

        else if(words.size() == 3){
            if(words[0] != words[2])
            fout << "\tmovq\t" << words[2] << ", " << words[0] << endl;
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
                if(!isReg(words[4])){
                    fout << "\tmovq\t" << words[4] << ", %rbx" << endl;
                    words[4] = "%rbx";
                }
                fout << "\tmovq\t" << words[2] << ", %rax" << endl;
                fout << "\tcqto\t" << endl;
                fout << "\tidivq\t" << words[4] << endl;
                fout << "\tmovq\t" << "%rax" << ", " << words[0] << endl;
            }

            else if(words[3][0] == '%') {
                if(!isReg(words[4])){
                    fout << "\tmovq\t" << words[4] << ", %rbx" << endl;
                    words[4] = "%rbx";
                }
                fout << "\tmovq\t" << words[2] << ", %rax" << endl;
                fout << "\tcqto\t" << endl;
                fout << "\tidivq\t" << words[4] << endl;
                fout << "\tmovq\t" << "%rdx" << ", " << words[0] << endl;
            }

            else if(words[3] == ">"){
                if(!isReg(words[2])){
                    fout << "\tmovq\t" << words[2] << ", %rcx" << endl;
                    words[2] = "%rcx";
                }
                if(!isReg(words[4])){
                    fout << "\tmovq\t" << words[4] << ", %rdx" << endl;
                    words[4] = "%rdx";
                }
                fout << "\tcmp\t" << words[2] << ", " << words[4] << endl;
                fout << "\tsetl\t%al" << endl;
                fout << "\tmovzbq\t" << "%al, " << words[0] << endl;
            }

            else if(words[3] == "<"){
                if (!isReg(words[2]))
                {
                    fout << "\tmovq\t" << words[2] << ", %rcx" << endl;
                    words[2] = "%rcx";
                }
                if (!isReg(words[4]))
                {
                    fout << "\tmovq\t" << words[4] << ", %rdx" << endl;
                    words[4] = "%rdx";
                }
                fout << "\tcmp\t" << words[2] << ", " << words[4] << endl;
                fout << "\tsetg\t%al" << endl;
                fout << "\tmovzbq\t" << "%al, " << words[0] << endl;
            }

            else if(words[3] == "<="){
                if (!isReg(words[2]))
                {
                    fout << "\tmovq\t" << words[2] << ", %rcx" << endl;
                    words[2] = "%rcx";
                }
                if (!isReg(words[4]))
                {
                    fout << "\tmovq\t" << words[4] << ", %rdx" << endl;
                    words[4] = "%rdx";
                }
                fout << "\tcmp\t" << words[2] << ", " << words[4] << endl;
                fout << "\tsetge\t%al" << endl;
                fout << "\tmovzbq\t" << "%al, " << words[0] << endl;
            }

            else if(words[3] == ">="){
                if (!isReg(words[2]))
                {
                    fout << "\tmovq\t" << words[2] << ", %rcx" << endl;
                    words[2] = "%rcx";
                }
                if (!isReg(words[4]))
                {
                    fout << "\tmovq\t" << words[4] << ", %rdx" << endl;
                    words[4] = "%rdx";
                }
                fout << "\tcmp\t" << words[2] << ", " << words[4] << endl;
                fout << "\tsetle\t%al" << endl;
                fout << "\tmovzbq\t" << "%al, " << words[0] << endl;
            }

            else if(words[3] == "!="){
                if (!isReg(words[2]))
                {
                    fout << "\tmovq\t" << words[2] << ", %rcx" << endl;
                    words[2] = "%rcx";
                }
                if (!isReg(words[4]))
                {
                    fout << "\tmovq\t" << words[4] << ", %rdx" << endl;
                    words[4] = "%rdx";
                }
                fout << "\tcmp\t" << words[2] << ", " << words[4] << endl;
                fout << "\tsetne\t%al" << endl;
                fout << "\tmovzbq\t" << "%al, " << words[0] << endl;
            }

            else if(words[3] == "=="){
                if (!isReg(words[2]))
                {
                    fout << "\tmovq\t" << words[2] << ", %rcx" << endl;
                    words[2] = "%rcx";
                }
                if (!isReg(words[4]))
                {
                    fout << "\tmovq\t" << words[4] << ", %rdx" << endl;
                    words[4] = "%rdx";
                }
                fout << "\tcmp\t" << words[2] << ", " << words[4] << endl;
                fout << "\tsete\t%al" << endl;
                fout << "\tmovzbq\t" << "%al, " << words[0] << endl;
            }

            else if(words[3][0] == '&'){
                if(!isReg(words[2])){
                    fout << "\tmovq\t" << words[2] << ", %rcx" << endl;
                    words[2] = "%rcx";
                }
                if(!isReg(words[4])){
                    fout << "\tmovq\t" << words[4] << ", %rdx" << endl;
                    words[4] = "%rdx";
                }
                fout << "\tandq\t" << words[2] << ", " << words[4] << endl;
                if(words[4] != words[0])
                fout << "\tmovq\t" << words[4] << ", " << words[0] << endl;
            }

            else if(words[3][0] == '|'){
                if(!isReg(words[2])){
                    fout << "\tmovq\t" << words[2] << ", %rcx" << endl;
                    words[2] = "%rcx";
                }
                if(!isReg(words[4])){
                    fout << "\tmovq\t" << words[4] << ", %rdx" << endl;
                    words[4] = "%rdx";
                }
                fout << "\torq\t" << words[2] << ", " << words[4] << endl;
                if(words[4] != words[0])
                fout << "\tmovq\t" << words[4] << ", " << words[0] << endl;
            }

            else if(words[3][0] == '^'){
                if(!isReg(words[2])){
                    fout << "\tmovq\t" << words[2] << ", %rcx" << endl;
                    words[2] = "%rcx";
                }
                if(!isReg(words[4])){
                    fout << "\tmovq\t" << words[4] << ", %rdx" << endl;
                    words[4] = "%rdx";
                }
                fout << "\txorq\t" << words[2] << ", " << words[4] << endl;
                if(words[4] != words[0])
                fout << "\tmovq\t" << words[4] << ", " << words[0] << endl;
            }

        }
        else if(words.size() == 2){
            fout << "\t" << words[0] << "\t" << words[1] << endl;
        }
        else if (words.size() == 1){
            if(words[0] == "ret")
                fout<< "\t" << words[0]<<endl;
            else
                fout << words[0] << endl;
        }
        else{
            fout << threeAC[i] << endl;
        }
        // for(int i = 0; i < words.size(); i++){
        //     fout << words[i] << " ";
        // }
        // fout<<endl;

        words.clear();
    }
}