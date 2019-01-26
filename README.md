
PROJECT TITLE:Smart irrigation using Iot

Inspiration: Irrigation is the most important agricultural input in a tropical monsoon country like India where rainfall is uncertain, unreliable and erratic India cannot achieve sustained progress in agriculture unless and until more than half of the cropped area is brought under assured irrigation.Intensive irrigation has lead to sharp rise in sub-soil water,leading to water-logging,soil salinity and alkalinity.It also leds to large wastage of human labour.Hence, crops are affected by the ill-effects of bad irrigation.

PROPOSED SOLUTION : The aim of this project is to develop a smart irrigation monitoring system using arduino UNO. Focus area will be parameters such as temperature and soil moisture. An automated irrigation system is developed to optimize water use for different agricultural crops according to their VWC(volumetric water content). The objective of this project is to control the water pump automatically, using the readings of the temperature and soil moisture sensor and to notify the farmer about status of irrigation in the farm.

TECH/FRAMEWORK USED:

Arduino Uno Board
GSM SIM900A module
Soil moisture sensor
DHT-11 Sensor
Ultrasonic sensor
Silicon Tubing
Water Pump and motor
Arduino IDE 1.8.8
WORKING PRINCIPLE :

Soil moisture sensor is inserted into the soil to detect the moisture percentage continously.
DTH11 sensor is used to monitor the temperature and humidity of the surroundings.
According to the above two criteria the plants will be watered automatically and the beginning of irrigation is notified to the farmer through GSM SIM900A module.
The automation of the water pump is done using motor connected through a relay which will pump water from the reserviour to the plants.
The water level in the reserviour is monitored using a ultrasonic sensor which will notify the farmer with a messgae if the water level is low through GSM SIM900A module.
DESCRIPTION OF THE CODE: sensors.ino - This code implements reading the values of soil moisture and DHT11 Sensor. It triggers the water pump motor which is connected through a relay when the moisture value goes below a specific limit. GSM.ino - This code is used to monitor the water reservoir which supplies water to the field and when the tank is almost empty, a message is sent to the farmer using GSM SIM900A Module.

BLOCK DIAGRAM:s-png






FLOW CHART:hack
