#ifndef _APPT_H_
#define _APPT_H_

#include <stdio.h>
#include <stdbool.h>
#include "time.h"

typedef struct 
{
  Time startTime;
  Time endTime;
  char* subject;
  char* location;
} Appointment;


void print(Appointment* appt);

bool lessThan(Appointment* appt, Appointment* B);

void read(Appointment* appt);

bool equal(Appointment* appt, char* subjct);

void destroy(Appointment* appt);

#endif
