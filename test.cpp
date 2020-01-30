#include <iostream>
using namespace std;
int logic_gate(int,int,int);
/* checklist: */
    /* and */
    /* or */
int main(int argc, char** argv){

    /* int gate = (int)argv[0]; */
    int gate = atoi(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    int output = logic_gate(gate,a,b);

    cout << output << endl;

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

