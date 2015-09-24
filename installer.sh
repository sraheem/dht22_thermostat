#/bin/bash

#Run installer to generate executables

arm-linux-gnueabihf-gcc source/dht_read_main.c source/common_dht_read.c source/Raspberry_Pi_2/pi_2_mmio.c source/Raspberry_Pi_2/pi_2_dht_read.c -o dht22_read -std=gnu99
