#/bin/bash

#This script has to be run in an hourly cron job.
#Limits thermostat table to little over a day to keep the table manageable.

#mysql thermostat --password=raspberry -e "select count(*) from thermostat;"
mysql thermostat --password=raspberry -e "delete from thermostat where time < now() - INTERVAL 1500 MINUTE;"
