#ifndef _DAY_H_
#define _DAY_H_
 
#include "appt.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
  short day;
  short month;
  short year;
  Appointment* appts[8];
  short apptCount;
} Day;

void create(Day* Cday, short month, short day, short year);

bool equal(Day* day, Day* D);

bool lessThan(Day* day, Day* D);

void read(Day* day);

void print(Day* day);

void subjectSearch(Day* day, char* subjct);

void destroy(Day* day);

#endif
