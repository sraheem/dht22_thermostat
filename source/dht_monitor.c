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


void main()
{
int sensor=22, pin=12, result,i=0;
float temperature=0, humidity=0;
char insert_stmt[128];

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


while (i<10)
{
  result = pi_2_dht_read(sensor, pin, &humidity, &temperature);
  //printf("%f, %f \n",temperature, humidity);
  snprintf(insert_stmt,128,"INSERT INTO thermostat VALUES (NOW(),%f,%f,0,0)",temperature,humidity);
  if (mysql_query(con, insert_stmt))
  {
    sql_error(con);
  }
  sleep (10);
  //i++;
}
mysql_close(con);
}
