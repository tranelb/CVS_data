//Global Variables
int pot = A3;      //Potentiometer(pot) is connected to pin A3.
int ldr = A4;      //LDR is connected to pin A4.

String dataLabel1 = "Potentiometer";
String dataLabel2 = "Photoresistor";
bool label  = true;
bool dataOutput = true;

int data1, data2;


void setup() {
  // put your setup code here, to run once:
  pinMode(pot, INPUT);        //Intialize POT & LDR pins as INPUTS. (Input Sensors)
  pinMode(ldr, INPUT);        

  Serial.begin(9600);         //Initialize Serial Monitor with BAUD Rate 9600.
}


void csvOutput(int count){
  data1 = analogRead(pot);
  data2 = analogRead(ldr);
  
  for(int i = 1; i<= count; i++){
    Serial.print(data1);
    Serial.print(",");
    Serial.println(data2);
    delay(1000);
  }
  dataOutput = false;
}


void loop() {
  // put your main code here, to run repeatedly:
  while(label){
    Serial.print(dataLabel1);
    Serial.print(",");
    Serial.println(dataLabel2);
    label = false;
  }
  if(dataOutput){
    csvOutput(10);
  }
      
  }

