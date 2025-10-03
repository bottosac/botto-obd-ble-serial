**Serial interface for ELMduino using BLE**

Fork of original project https://github.com/vdvornichenko/obd-ble-serial/tree/main (thank you vdvornichenko) 
and updated project https://github.com/adlerre/obd-ble-serial (thank you adlerre)

I started from adlerre project because the original discover function of vdvornichenko was unable to find my ELM327 v.1.5 with BLE support.

I changed the prototype of begin function for a compile error of library BLEUUID.

Now after a brief search the discover function recognize and connect my ELM327 (OBDBLE).

I updated the example function with new calls
