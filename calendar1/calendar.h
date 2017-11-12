#ifndef _CALENDAR_H_
#define _CALENDAR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "day.h"
#include "appt.h"

typedef struct 
{
  Day* days;
  int size;
  int count;
} Calendar;

void create(Calendar* calendar);

void readFile(Calendar* calendar);

void resize(Calendar* calendar);

void dateSearch(Calendar* calendar);

void getDate(int* month, int* day, int* year);

void subjectSearch(Calendar* calendar);

void destroy(Calendar* calendar);

#endif

