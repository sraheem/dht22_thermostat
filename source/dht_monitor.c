#include "Raspberry_Pi_2/pi_2_dht_read.h"
#include <stdio.h>
#include <mysql/mysql.h>
#include <unistd.h>
#include <stdlib.h>
#include "cred_mysql.h"

void sql_error(MYSQL *con)
{
  //fprintf(stderr, "%s\n", mysql_error(con));
  printf("%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}


void main(int argc, char **argv)
{
int sensor=22; //Sensor type DHT22 (this is the only fully supported sensor. Other Sensors source library can be found with Adafruit's parent library.
int  pin; //To be externalized.
float temp_setpoint=22.5; //Default setpoint for temperature.
int result,i=0;
float temperature=0, humidity=0;
char insert_stmt[128];
int agression=0;

//Argument validation
if (argc != 2)
{
  printf("\nInvalid arguments. Please use as below:\n./dht22_thermostat GPIO_PIN \n");
  exit(1);
}
else
{
  printf("\nStarting DHT22 Thermostat on PIN %d ...",pin);
  pin=atoi(argv[1]);
}


//Initializa DB connection
MYSQL *con = mysql_init(NULL);

if (con == NULL)
{
  //fprintf(stderr, "%s\n", mysql_error(con));
  printf("%s\n", mysql_error(con));
  exit(1);
}

if (mysql_real_connect(con, "localhost", MYSQLUSER, MYSQLPASS, "thermostat", 0, NULL, 0) == NULL)
{
  sql_error(con);
}

//Attempt to grab setpoint always
/*
while(1)
{
  printf("\nEnter setpoint: ");
  scanf("%f",&temp_setpoint);
}
*/
while (i<10)
{
  result = pi_2_dht_read(sensor, pin, &humidity, &temperature);
  if (result<0)
  {
    //printf("Some weird error! ignore reading");
    continue;
  }

  snprintf(insert_stmt,128,"INSERT INTO thermostat VALUES (NOW(),%f,%f,%f,b'0')",temperature,humidity,temp_setpoint);
  if (mysql_query(con, insert_stmt))
  {
    sql_error(con);
  }
  sleep (30);
  //Increment statement below for dev purposes. Should be commented during normal operations.
  i++;
}
mysql_close(con);
}
