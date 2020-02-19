#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
vector<string> protos(string statement);
vector<string> split_parenth(vector<string> &vecty);
/* globals */
vector<int> gates;
int main(){
    // this will be the logic statement
    string stringy = ("not ( p and q ) and ( q and p )");
    /* dividing logic_statement into separate words */
    vector<string> vecty = protos(stringy);
    /* getting statement inside the parenthesis */
    vector<string> vectant = split_parenth(vecty);

    /* displayer */
    for(int i = 0;i < vecty.size();i++){
        /* cout << vectant[i] << endl; */
        cout << vecty[i] << endl;
    }

    return 0;
}

vector<string> protos(string statement){
    string buffer;
    stringstream ss(statement);
    vector<string> words;

    while(ss >> buffer)
        words.push_back(buffer);
       
    int words_size = static_cast<int>(words.size());

   return words; 
}
/* gates order in a vector [planning to support this for now]: */
/*     gate ( cond gate cond ) gate gate ( cond gate ) */ 
vector<string> split_parenth(vector<string> &vecty){
    vector<string> ret;
    int not_counts = 0;
     
    for(int i = 0; i < vecty.size();i++){
        if(vecty[i] == "("){
            ret.push_back(vecty[i+1]);
        }
        if(vecty[i] == ")"){
            ret.push_back(vecty[i-1]);
        }
    }

   return ret; 
}



