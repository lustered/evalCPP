int logic_gate(int, int, int);
/* switch takes an int which equates to one of the */
/* need 2 buttons and 3 leds */ 
const int a_button = 2;
const int b_button = 3;
//leds
const int a_led = 5; 
const int b_led = 6;
const int output_led = 7;
/* button state */
int a_state = 0;
int b_state = 0;

void setup(){
    Serial.begin(9600);
    /* init leds */
    pinMode(a_led,OUTPUT);
    pinMode(b_led,OUTPUT);
    pinMode(output_led,OUTPUT);
    /* init buttons */
    pinMode(a_button,INPUT)
    pinMode(b_button,INPUT)

}
void loop(){
    a_state = digitalRead(ones_button);
    b_state = digitalRead(zeros_button);
    /* TODO: */ 
    /* think of a way to get gate */
    int output = logic_gate(1,a_state,b_state);
    Serial.println(output);

}
/* gates dictionary: */
/*     1 - and */ 
/*     2 - or */ 
/*     3 - not */ 
/*     4 - nand */ 
/*     5 - nor */ 

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

