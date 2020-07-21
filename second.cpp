#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <sstream>
using namespace std;
string interp(string);
vector<string> words_set(string);
string new_test(string);

int main(int argc,char *argv[])
{
    string statement = argv[1];
    string sentnece[10];
    string sentence = new_test(statement);   
    for(int i=0;i < sizeof(sentence);i++){
        cout << statement[i] << endl; 
    }

    return 0;
}

string interp(string statement){
    string str;
    for(auto x : statement){
        if(x == '(' || x == ')'){
            /* cout << str << endl; */
            str.erase();
        }
        else 
            str = str+x;
    }

    return str;
}

/* vector<string> words_set(string statement){ */
/*    vector<string> conditions; */ 
/*    for(auto 0 : 5){ */
/*        conditions.push_back(x); */
/*    } */ 
/*     return conditions; */
/* } */

string new_test(string statement){
    string arr;

    for(auto x : statement)
    {
        if(x==' ')
        {
            cout<<arr<<endl;
             arr.erase();
        }
        
        else
              arr=arr+x;
    }
    
    cout<<"arr: " << arr;
    return arr;
}
