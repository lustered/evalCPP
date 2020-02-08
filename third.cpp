#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
vector<string> protos(string statement);
vector<string> split_parenth(vector<string> &vecty);

int main(){
    // this will be the logic statement
    string stringy = ("not ( p and q ) and ( q and p )");

    vector<string> vecty = protos(stringy);
    /* cout << vecty.size()<< vecty[1]; */

    /* vector<string> vectant = split_parenth(vecty); */
    /* cout << vectant[0] << endl; */
    /* /1* displayer *1/ */
    for(int i = 0;i < 10;i++){
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

vector<string> split_parenth(vector<string> &vecty){
    vector<string> ret;
    int not_counts = 0;
    int from;
    int until;
    /* for(int i = 0; i < vecty.size();i++){ */
    /*     if( */ 
    /* } */

   return ret; 
}



