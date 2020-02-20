#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
vector<string> protos(string statement);
vector<int> parser(vector<string> &conds);

int main(int argc, char** argv){
    // this will be the logic statement
    string l_statement = ("not ( p and q ) and ( q and p )");
    string l_statement2 = ("not ( not p and not q )");
    string from_arg = argv[1]; 
    /* splitting logic statement into separate characters */
    vector<string> conds = protos(from_arg);
    vector<int> test = parser(conds);

    for(int i = 0; i < test.size();i++){
        cout << test[i] << endl;
    }

    return 0;
}

vector<string> protos(string statement){
    string buffer;
    stringstream ss(statement);
    vector<string> words;

    while(ss >> buffer)
        words.push_back(buffer);

    /* int words_size = static_cast<int>(words.size()); */
   return words; 
}

vector<int> parser(vector<string> &conds){
    vector<int> ret;
    /* we dont need a counter since we can just get the size of gates */
    vector<int> gates;
    bool not_before_paren = false;

    for(int i = 0; i < conds.size();i++){
        /* first we will check for NOTs before paren */
        if(conds[i] == "not" && conds[i+1] == "("){
            not_before_paren = true;
            cout << "found a distributive not" << endl;
        }
        /* first get conditional statements with their values eg:1/0 */
        if(conds[i] == "p" || conds[i] == "q"){
            ret.push_back(1);
            cout << "found : " << conds[i] << endl;
            /* TODO:
               implement gates and nested conditions */

            /* note: */ 
            /*     since "not(not p)" returns 1 and 1 is the default */ 
            /*     value we input if we find p or q, then we don't */ 
            /*     change anything in that case */


           /* if p or q have a not in front then flip their value */
            if(conds[i-1] == "not" && not_before_paren == false){
                ret.at(ret.size() - 1) = 1 - ret.back();
            }
            /* if there is distributive negation */
            /*     eg. not(p and q) */
            if(conds[i-1] != "not" && not_before_paren){
                ret.at(ret.size() - 1) = 1 - ret.back();
            }
        }
    }  
    return ret;
}
