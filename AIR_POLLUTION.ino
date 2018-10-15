
/***********************************************************************
*  NodeMCU and OLED display "Hello World"
*  Based on original code developed by: Makerbro at https://acrobotic.com/
*  MJRoBot 12Oct16
************************************************************************/

#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>

const int MQ_PIN = A0; // ANALOG PIN 
int gasLevel = 0;
String quality = "";


void setup()
{
  Wire.begin();  
  oled.init();                      // Initialze SSD1306 OLED display
  oled.clearDisplay();              // Clear screen
  oled.setTextXY(0,0);              // Set cursor position, start of line 0
  oled.putString(" AIR CHECKER ");
  oled.setTextXY(2,0);
  oled.putString("MONITORING ...");
  delay(2000);
  oled.setTextXY(4,2);
  oled.putString("AQI:");
   oled.setTextXY(6,2);
  oled.putString("AIR QUALITY:");
  pinMode(MQ_PIN,INPUT);  
  Serial.begin(9600);
}

void loop()
{
  int gasLevel = analogRead(MQ_PIN);
  Serial.println("MQ 135 value");    
  Serial.println(gasLevel,DEC);
  if (gasLevel < 50 ) {
    quality = "GOOD !";
  }
  else if (gasLevel > 50 && gasLevel < 100)
  {
    quality = "SATISFACTORY";
  }
  else if (gasLevel > 100 && gasLevel < 200) {
    quality = "MODERATE";
  }
  else if (gasLevel > 200 && gasLevel < 300) {
      quality = "POOR";
  }

 else if (gasLevel > 300 & gasLevel < 400 ) {
   quality = "VERY POOR";
 }
 else {
  quality = "SEVERE";
 }
  clearDisplay();
  oled.setTextXY(4,7);
  oled.putString(String(gasLevel));
  oled.setTextXY(7,1);
  oled.putString(String(quality));
  delay(1000);
}

void clearDisplay() {  
  oled.setTextXY(4,7); oled.putString("                ");
  oled.setTextXY(7,1); oled.putString("                ");
  

}


