using namespace std;
#include <Arduino.h>
#include <Blynk.h>

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
//protos
int logic_gate(int,int,int);

// hotspot credential setup
char auth[] = "BBKE4i5rjIHcYOZkEaU6zQYUacGz2fXq";
char ssid[] = "antei";
char pass[] = "password";
// wdiget and libs init
WidgetTerminal terminal(V5);
BlynkTimer timer;

//global variables for readings
int gate_selected;
int A_val;
int B_val;

//terminal communication
BLYNK_WRITE(V5){
     // if you type "Marco" into Terminal Widget - it will respond: "Polo:"
  if (String("Marco") == param.asStr()) {
    terminal.println("You said: 'Marco'") ;
    terminal.println("I said: 'Polo'") ;
  } else {

    // Send it back
    terminal.print("You said:");
    terminal.write(param.getBuffer(), param.getLength());
    terminal.println();
  }

  // Ensure everything is sent
  terminal.flush();
}

//----------------------------------------------------------------------
//get data from buttons 
// A 
BLYNK_WRITE(V1){
    A_val= param.asInt();
    Serial.print(A_val);
}
// B
BLYNK_WRITE(V2){
    B_val = param.asInt();
    Serial.print(B_val);
}
//----------------------------------------------------------------------
//send the output
void output_result(){
int result = logic_gate(gate_selected,A_val,B_val);
Blynk.virtualWrite(V6,result);
}
//----------------------------------------------------------------------
// gates menu || only need to get current value of the menu
BLYNK_WRITE(V3) {
gate_selected = param.asInt();
}
//----------------------------------------------------------------------
// table  
void sendEvent() {
// [gate in order lister][index in order 0-3]
vector<vector<int>> gates{{ 0,0,0,1},// and
                          { 0,1,1,1},// or
                          { 1,0,1,0},// not
                          { 1,1,1,0},// nand
                          { 1,0,0,0} };//nor 

if(gate_selected > 0){
    int gate_index = gate_selected - 1;
    if(gate_index != 2){
    Blynk.virtualWrite(V4, "add", 1, "0         0",gates[gate_index][0]);
    Blynk.virtualWrite(V4, "add", 2, "0         1", gates[gate_index][1]);
    Blynk.virtualWrite(V4, "add", 3, "1         0", gates[gate_index][2]);
    Blynk.virtualWrite(V4, "add", 4, "1         1", gates[gate_index][3]);
}
else if(gate_index == 2){
   Blynk.virtualWrite(V4,"clr");
   Blynk.virtualWrite(V4, "add", 1, "1          ",0);
   Blynk.virtualWrite(V4, "add", 2, "0          ",1); 
}
else
    delay(1000);
 }
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);


  // terminal stuff
  terminal.println(F("This is a logic gate calculator"));
  terminal.println(F("Write down your statements"));
  terminal.flush();
  // put your setup code here, to run once:
 // -------------------------------------------------
 // table clear on start
 Blynk.virtualWrite(V4,"clr");
 timer.setInterval(1000L, sendEvent);
 // -------------------------------------------------
 // give result to output widget
 timer.setInterval(10L, output_result);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();
}

// logic gate calculation
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