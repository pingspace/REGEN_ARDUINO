unsigned long Time;

void setup() {
  Serial.begin(115200);

}

void loop() {
  float ITemp1 = 0;
  float ITotal1 = 0;
  float IAct1 = 0;

  float ITemp2 = 0;
  float ITotal2 = 0;
  float IAct2 = 0;

  float VTemp1 = 0;
  float VTotal1 = 0;
  float VAct1 = 0;

  float VTemp2 = 0;
  float VTotal2 = 0;
  float VAct2 = 0;

  //CH2
  for (int i = 0; i < 5; i++)
  {
    ITemp1 = analogRead(A5);
    ITotal1 = ITotal1 + ITemp1;
  }
  // 1023 = 5V
  IAct1 = (((ITotal1 / 5)*(5.0 / 1023.0)) - 2.5) / 0.1 ;


  //CH3
  for (int i = 0; i < 5; i++)
  {
    ITemp2 = analogRead(A2);
    ITotal2 = ITotal2 + ITemp2;
  }
  // 1023 = 5V
  IAct2 = (((ITotal2 / 5)*(5.0 / 1023.0)) - 2.5) / 0.03 ;

  
  //CH4
  for (int i = 0; i < 5; i++)
  {
    VTemp1 = analogRead(A1);
    VTotal1 = VTotal1 + VTemp1;
  }
  // 1024 = 5V
  VAct1 = (VTotal1 / 5)*(5.0 / 1023.0) / 0.0435;
  
  
  //CH5
  for (int i = 0; i < 5; i++)
  {
    VTemp2 = analogRead(A0);
    VTotal2 = VTotal2 + VTemp2;
  }
  // 1024 = 5V
  VAct2 = (VTotal2 / 5)*(5.0 / 1023.0) / 0.0465;

  
  Time = millis();

  Serial.print(Time);
  Serial.print(",");
  Serial.print(IAct1);  //CH2
  Serial.print(",");
  Serial.print(IAct2);  //CH3
  Serial.print(",");
  Serial.print(VAct1);  //CH4
  Serial.print(",");
  Serial.print(VAct2);  //CH5
  Serial.println();

}