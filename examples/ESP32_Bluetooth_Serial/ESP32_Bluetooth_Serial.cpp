#include <Arduino.h>
#include "ELMduino.h"
#include <BLEClientSerial.h>

BLEClientSerial BLESerial;


#define DEBUG_PORT Serial
#define ELM_PORT   BLESerial

ELM327 myELM327;


uint32_t rpm = 0;


void setup()
{

  DEBUG_PORT.begin(115200);
  //ESP32-C3 is local BLE
  //"FFF0", "FFF1", "FFF2" are target services
  ELM_PORT.begin("ESP32-C3", "FFF0", "FFF1", "FFF2");
  
  //OBDBLE is target BLE
  if (!ELM_PORT.connect("OBDBLE"))
  {
    DEBUG_PORT.println("Couldn't connect to OBD scanner - Phase 1");
    while(1);
  }

  if (!myELM327.begin(ELM_PORT, true, 2000))
  {
    Serial.println("Couldn't connect to OBD scanner - Phase 2");
    while (1);
  }

  Serial.println("Connected to ELM327");
}

void loop()
{
  float tempRPM = myELM327.rpm();

  if (myELM327.nb_rx_state == ELM_SUCCESS)
  {
    rpm = (uint32_t)tempRPM;
    Serial.print("RPM: "); Serial.println(rpm);
  }
  else if (myELM327.nb_rx_state != ELM_GETTING_MSG)
    myELM327.printError();

}