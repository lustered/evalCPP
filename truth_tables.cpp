/* this is working properly */
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
vector<int> truth_table(vector<vector<int>> &default_table);
vector<vector<int>> build_table(int gate,int p,int q);
int logic_gate(int gate,int a,int b);

int main(){
    /* p and q */
    vector<vector<int>> default_table{{1,1,0,0}, //p
                             {1,0,1,0}}; //q

    /* cout << default_table[1][1] << endl; */
    vector<int> results = truth_table(default_table);
    /* values to pass */
    int gate = 1;
    int p = 1; 
    int q = 0;
    vector<vector<int>> truth_tab = build_table(gate,p,q); // gate, P, Q || 0 for not, 1 for T eg. not p = 0
    int counter = 0;
    cout << gate << p << q << endl;
    for(int x = 0;x < 3; x++){
        /* cout << results[x] << endl; */
        for(int y = 0; y < 4; y++){
        cout << truth_tab[x][y] << endl;;
        counter++; 
        if(counter == 4){
            cout << "**************" << endl;
            counter = 0;
        }
    }
    }


    
    return 0;
}

vector<int> truth_table(vector<vector<int>> &default_table){
    vector<int> ret;
    int temp_a;
    int temp_b;

    for(int i = 0;i < 4;i++){
        temp_a = default_table[0][i];
        temp_b = default_table[1][i];
        ret.push_back(logic_gate(1,temp_a,temp_b));
        /* cout << ret[i]; */

    }
    return ret;
}

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
/* this will build p, q and filter through gate */
vector<vector<int>> build_table(int gate,int p,int q){
    /* default truth table hard coded */
    vector<vector<int>> default_table{{1,1,0,0},//p
                                      {1,0,1,0},//q
                                      {0,0,0,0}};// comparison with gate 

    vector<vector<int>> ret = default_table;
    
/* TODO: */
/*     finish this */ 
    for(int x=0; x < 4;x++){
        if(p == 1 && q == 1)
            ;

        if(p == 0)
            ret[0][x] = 1 - ret[0][x]; 
        
        if(q == 0)
            ret[1][x] = 1 - ret[1][x]; 

        /* adding the result of the current index P and Q to the gated val table */
        ret[2][x] = logic_gate(gate,ret[0][x],ret[1][x]); 
        
    }

    return ret;
}