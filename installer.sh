#/bin/bash

#Run installer to generate executables

rm -f dht22_monitor

arm-linux-gnueabihf-gcc source/dht_monitor.c source/common_dht_read.c source/Raspberry_Pi_2/pi_2_mmio.c source/Raspberry_Pi_2/pi_2_dht_read.c -o dht22_monitor -std=gnu99 `mysql_config --cflags --libs`
