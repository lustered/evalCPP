#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
vector<string> protos(string statement);
int logic_gate(int gate,int a,int b);
vector<int> parser(vector<string> &conds);
vector<vector<int>> build_table(int gate,int p,int q);
void table_displayer(vector<vector<int>> &truth_table);
void handle_stack(vector<vector<int>> &values, int &gate);

int main(int argc, char** argv){
    // this will be the logic statement
    string l_statement = ("not ( p and q ) and ( q and p )");
    string l_statement2 = ("not ( not p and not q )");
    string from_arg = argv[1]; 
    /* splitting logic statement into separate characters */
    vector<string> conds = protos(from_arg);
    vector<int> test = parser(conds);


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

/* logic gate */
int logic_gate(int gate,int a,int b){
    int ret = 0;
    switch(gate){
        /* and */
        case 1:
            if (a == b){
                ret = a;
            }
            break;
        /* or */
        case 2:
            if (a == 1 || b == 1){
                ret = 1;
            }
            break;
    }

    return ret;
}

/* this will build p, q and the output through gate */
vector<vector<int>> build_table(int gate,int p,int q){
    /* default truth table hard coded */
    vector<vector<int>> default_table{{1,1,0,0},//p
                                      {1,0,1,0},//q
                                      {0,0,0,0}};// comparison with gate
    vector<vector<int>> ret = default_table;

    for(int x=0; x < 4;x++){
        if(p == 0)
            ret[0][x] = 1 - ret[0][x];

        if(q == 0)
            ret[1][x] = 1 - ret[1][x];

        /* adding the result of the current index P and Q to the gated val table */
        ret[2][x] = logic_gate(gate,ret[0][x],ret[1][x]);

    }

    return ret;
}

void table_displayer(vector<vector<int>> &truth_table){
    cout << "P \tQ \tP0Q" << endl;


    for(int i = 0;i < 4;i++){
    cout << truth_table[0][i] << "\t" <<
            truth_table[1][i] << "\t" <<
            truth_table[2][i] << endl;

    }
}
vector<int> parser(vector<string> &conds){
    vector<int> ret;
    /* vector<int> gates; */
    /* int gate; */
    /* gate between the 2 conds */
    /* int link_gate; */
    vector<int> gates;
    vector<vector<int>> values; 
    vector<vector<int>> truth_table;
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
        if(conds[i] == ")"){
            not_before_paren = false;
        }
        /* latest modification */
        /* gate implementation */

        /* add table to stack */
        if(conds[i] == "and"){gates.push_back(1);}
        if(conds[i] == "or"){gates.push_back(2);}
        /* need to clean this up to be more dynamic^^ */ 

        if(gates.size() > 0 && ret.size() == 2){
            /* first we build the standard table with */ 
            /*     p q and the output */
          truth_table = build_table(gates.back(),ret[0],ret[1]);  
          ret.clear();

          table_displayer(truth_table);
          values.push_back(truth_table[2]);
          truth_table.clear();

        
        }

    }  
    if(values.size() == 2){
            cout << "gate: " << gates[gates.size() - 2]<< endl;
            handle_stack(values, gates[gates.size() - 2]);
        }

    return ret;
}

/* rebuild the truth table to handle multiple conditional statements */
void handle_stack(vector<vector<int>> &values, int &gate){
    vector<vector<int>> ret;
    cout << "final " << endl;

    for(int x = 0; x < 4;x++){
       cout << logic_gate(gate,values[0][x],values[1][x]) << endl;;
    }
    /* for(auto i = ret.begin(); i != ret.end();++i){ */
    /*     cout << *i << endl; */
    /* } */ 
}

