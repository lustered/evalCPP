/* this is working properly */
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
vector<int> truth_table(vector<vector<int>> &default_table);
int logic_gate(int gate,int a,int b);

int main(){
    /* p and q */
    vector<vector<int>> default_table{{1,1,0,0}, //p
                             {1,0,1,0}}; //q

    /* cout << default_table[1][1] << endl; */
    vector<int> results = truth_table(default_table);
    for(int x = 0;x < results.size(); x++){
        cout << results[x] << endl;
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
