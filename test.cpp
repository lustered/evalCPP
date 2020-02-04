#include <iostream>
#include <string>
using namespace std;
int logic_gate(int,int,int);
int interpreter(int[]);
/* checklist: */
    /* and */
    /* or */
int main(int argc, char** argv){

    /* int gate = (int)argv[0]; */
    /* int gate = atoi(argv[1]); */
    /* int a = atoi(argv[2]); */
    /* int b = atoi(argv[3]); */
    /* int output = logic_gate(gate,a,b); */

    /* cout << output << endl; */
    string arg_statement = argv[1];
    cout << arg_statement << endl; 
    //cout << statement << endl;

    return 0; 
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
        /* not */
        case 3:
            if (a == 1){
                ret = 0;
            }
            else if (a == 0)
                    ret = 1;

            break;
        /* nand */
        case 4:
            if (a + b < 2){
                ret = 1;
            }
            break;
        /* nor */
        case 5:
            if (a == 0 && b == 0){
                ret = 1;
            }

        }
    return ret;
                /* end of switch */
}


// planning:
// each buffer will have 3 parts
// [first statement] [logic gate] [second statement]
// statements can have gates within themselves:
// ex: [not p and q] [and] [p or q]
// statements can also have signs before them
// ex: not[not p and not q] [and] not[p or not q]
//

int interpreter(int statement[]){
   int state_count[10];  
   int size_of_state = sizeof(*statement);
   cout << size_of_state << endl;
   for(int i = 0;i < size_of_state;i++){
       if(statement[i] == '('){
       state_count[i] = statement[i-1]; 
       }
       else if(statement[i] == ')'){
        state_count[i] = statement[i-1];

        }
    } 
   return *state_count;
}








