#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "time.h"

void read(Time* time) 
{
  char* tok;
  tok = strtok(NULL, ":");
  time->hour = atoi(tok);
  tok = strtok(NULL, ":");
  time->minute = atoi(tok);
  tok = strtok(NULL, ",");
  
  if (strcmp(tok, "00 PM") == 0 ) // if format is PM
  {
    time->hour += 12;
  } // change time format to 24hrs if case is valid
  
  return;
} // read()

void print(Time* time) 
{
  printf("%.2hi:%.2hi ", time->hour, time->minute);
  return;
} // print()

bool lessThan(Time* calTime, Time* newTime) 
{
  if (calTime->hour > newTime->hour) // if hour in calendar is greater
  {
    return false;
  } // if stored hour is greater
  else // if hour but not minutes 
  {
    if (calTime->hour >= newTime->hour && calTime->minute > newTime->minute) //
      return false;
  } // if hour is equal but not minutes
  
  return true; // return true if time in calendar is smaller than time of app
} // lessThan()
