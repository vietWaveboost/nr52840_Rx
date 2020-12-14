WaveBoost Sensor Board

1. Overview: 
This project is a part of WaveBoost power harvesting system. 
WaveBoost Sensor Board is including : 
  - Bluetooth low energy chip : nrf52840
  - Humidity + Pressure + Temperature sensor : BME280
  - Light sensors : (update later)
 
 The nrf52840 collect data from above sensors and advertise them periodically (the interval of advertising is configurable).
 The Bluetooth system works on Scan Active mode.
 
 2 Compile the project:
  - Step 1 : Download nordic sdk 	nRF5_SDK_15.2.0_9412b96.zip from the link https://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v15.x.x/
  - Step 2 : Check out or download this project.
  - Step 3 : unzip the downloaded files (nordic sdk and project), copy them and put them in same folder.
    NOTE : normally, unzip process will create one more level of folder. For example : abc.zip, after unzip, the folder path like : abc/abc/....
           so just copy the root folder.
  - Step 4 : Open the project by double click on the file : nr52840_Rx/targets/ruuvitag_b/ses/ruuvi.firmware.c.emProject , then compile the project.
  
  3 GPIO Connection: 
   - BME280 : 
   SCLK <--> 13
   
   MOSI <--> 15  
   
   MISO <--> 17
   
   SS   <--> 2
              
   - VEML6305 : 
   
   SCL <--> 7
   
   SDA <--> 8
  
  4 Change the interval advertising: 
   - go to the file application_config.h, and search for the macro : APPLICATION_ADVERTISING_INTERVAL and change its value
   (#define APPLICATION_ADVERTISING_INTERVAL              1010)
