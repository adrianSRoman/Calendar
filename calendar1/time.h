#ifndef _TIME_H_
#define _TIME_H_

#include <stdio.h>

typedef struct 
{
  short hour;
  short minute;
} Time;

void read(Time* time);

void print(Time* time);

bool lessThan(Time* calTime, Time* newTime);

#endif


