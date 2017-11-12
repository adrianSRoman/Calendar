#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "time.h"
#include "appt.h"
using namespace std;

void read(Appointment* appt)
{
  char* tok;
  tok = strtok(NULL, ",");	
  appt->subject = (char*)malloc(strlen(tok) + 1);
  strcpy(appt->subject, tok);
  read(&(appt->startTime));
  read(&(appt->endTime));
  tok = strtok(NULL, "\n");
  appt->location = (char*)malloc(strlen(tok) + 1);
  strcpy(appt->location, tok);
  return;
} // read()
	

void print(Appointment* appt) 
{
  print(&(appt->startTime));
  print(&(appt->endTime));
  printf("%-13s", appt->subject);
  cout << left << appt->location << right << endl;
  //for (int i = 0; i < strlen(appt->location); i++)
  //{
    //printf("%-c\n", appt->location[i]);
 // }
  return;
} // print()

bool lessThan(Appointment* appt, Appointment* B) 
{
  return lessThan(&appt->startTime, &B->startTime);
} // lessThan()

bool equal(Appointment* appt, char* subjct)
{
  char* str;
  str = strstr(appt->subject, subjct);
  
  if (str) // if string is found 
    return true;
  
  return false;
} // equal()

void destroy(Appointment* appt)
{
  free(appt->subject);
  free(appt->location);
  return;
}  // destroy
