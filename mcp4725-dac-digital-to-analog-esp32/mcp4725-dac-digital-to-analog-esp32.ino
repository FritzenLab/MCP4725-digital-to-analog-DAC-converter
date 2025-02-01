//   Created by Clovis Fritzen, FritzenLab.net 
// Based on work from: 
//    FILE: mcp4725_minimal.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: Minimal sketch MCP4725 (#29)
//     URL: https://github.com/RobTillaart/MCP4725


#include "Wire.h"
#include "MCP4725.h"

MCP4725 MCP(0x60);

long oldtime;
int rawAnalog;
int i= 0;

void setup()
{
  Serial.begin(115200);
 
  Wire.begin();
  MCP.begin();

  //analogReadResolution(12);
}
void loop()
{
  if(millis() - oldtime > 100){
    oldtime= millis();
    rawAnalog= analogRead(A0);
    MCP.setValue(rawAnalog);

    i++;
    if(i == 10){
      Serial.println(rawAnalog);
      i=0;
    }
  }
}