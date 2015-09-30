#/bin/bash

#Run this script to launch thermostat application. 
#Modify GPIO PIN number as needed.
#After testing this should ideally added as a startup job.


# ./dht22_thermostat <GPIO_PIN> &

./dht22_thermostat 12 &
