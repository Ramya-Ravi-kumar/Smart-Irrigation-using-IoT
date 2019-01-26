**SMART IRRIGATION USING IoT**

*__Inspiration__*
Irrigation is the most important agricultural input in a tropical monsoon country like India where rainfall is uncertain, unreliable and erratic India cannot achieve sustained progress in agriculture unless and until more than half of the cropped area is brought under assured irrigation.Intensive irrigation has lead to sharp rise in sub-soil water,leading to water-logging,soil salinity and alkalinity.It also leds to large wastage of human labour.Hence, crops are affected by the ill-effects of bad irrigation.Gas leaks and explosive fire harazrds can also pose a serious threat to the crops leading to destruction of large scale of plants.

*__Proposed solution__*
The aim of this project is to develop a smart irrigation monitoring system using arduino UNO. Focus area will be parameters such as temperature and soil moisture. An automated irrigation system is developed to optimize water use for different agricultural crops according to their VWC(volumetric water content). The objective of this project is to control the water pump automatically, using the readings of the temperature and soil moisture sensor and to notify the farmer about status of irrigation in the farm.

*__Tech/Framework used__*
- Arduino Uno Board
- GSM SIM900A module
- Soil moisture sensor
- DHT-11 Sensor
- Ultrasonic sensor
- Silicon Tubing
- Water Pump and motor
- Arduino IDE 1.8.8
- MQ2 Smoke detector 

*__Working principle__* 
Soil moisture sensor is inserted into the soil to detect the moisture percentage continously.
DTH11 sensor is used to monitor the temperature and humidity of the surroundings.
According to the above two criteria the plants will be watered automatically and the beginning of irrigation is notified to the farmer through GSM SIM900A module.
The automation of the water pump is done using motor connected through a relay which will pump water from the reserviour to the plants.
The water level in the reserviour is monitored using a ultrasonic sensor which will notify the farmer with a messgae if the water level is low through GSM SIM900A module.
The gaseous content of the surrounding is constantly is monitored by the smoke detector which alerts a alarm,if a gas leak is detected.

*__Software implementation__*
The sensors are intefaced with the arduino with their appropriate pin numbers to which they are connected.A baud rate of 9600 is used for communicating with the port channels.The moisture sensor and DHT11 sensor constantly display their readings through the serial monitor.When the moisture content for a particluar plant goes below its required water content,the water pump pin goes high and hence plant is watered.The temperature of the atmosphere is also monitored regularly,which, when detected very high causes the the pump to be triggered again.The monitoring of the water reserviour is done throough a ultrasonic sensor which intimates the farmer through a text message generated with a GSM module to refill the same.When the smoke reads a value greater than threshold,the buzzer is turned on.[Code Implementation for this project](Implementation.ino) 


*__Block diagram__*
- <a href="https://ibb.co/ncVtk04"><img src="https://i.ibb.co/Phb0CYJ/s-png.png" alt="s-png" border="2"></a>

**__Flow Chart__**
- <a href="https://ibb.co/znH0F1X"><img src="https://i.ibb.co/6nJf82H/hack.png" alt="hack" border="0"></a>

