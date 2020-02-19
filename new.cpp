#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
/* prototypes */
vector<string> protos(string);
int main(){
    // this will be the logic statement
    string stringy = ("not ( p and q ) and ( p and q )");
    /* dividing logic_statement into separate words */
    vector<string> vecty = protos(stringy);
    /* getting statement inside the parenthesis */
    for(int i = 0;i < vecty.size();i++){
        cout << vecty[i] << endl; 
    }
    return 0;
}
/* splits long string statement into words with a space in between */
vector<string> protos(string statement){
    string buffer;
    stringstream ss(statement);
    vector<string> words;

    while(ss >> buffer)
        words.push_back(buffer);
       
    /* int words_size = static_cast<int>(words.size()); */

   return words; 
}

vector<string> parser(vector<string> &vecty){
    vector<int> ret;
    for(int i = 0;i < vecty.size();i++){
        if(vecty[i] == "p"){

        }
    }

    return ret;
}
