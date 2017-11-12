#include <stdio.h>
#include <stdbool.h>

#include "day.h"
#include "appt.h"

void create(Day* Cday, short month, short day, short year) 
{
  Cday->month = month;
  Cday->day = day;
  Cday->year = year;
  Cday->apptCount = 0;
} // create()

bool equal(Day* day, Day* D) 
{
  bool eqmonth = day->month == D->month;
  bool eqday = day->day == D->day;
  bool eqyear = day->year == D->year;
  
  if (eqmonth && eqday && eqyear) // same date
    return true;
  
  return false;
} // equal()

bool lessThan(Day* day, Day* D)
{
  bool geyear = day->year >= D->year;
  bool gemonth = day->month >= D->month;
  bool gday = day->day > D->day;
  
  if (day->year > D->year) // if year in calendar is greater
  {
    return true;
  } // if year is greter
  
  if (day->year >= D->year && day->month > D->month) // if month greater 
  {  
    return true;
  } // if year and month are greater
  
  else // if appointment is latter
  {
    if ( geyear && gemonth && gday ) // ge-greater-or-equal...
    {
    return true;
    } // if date is greater
  } // if year month and year are greater
  
  return false;
} // lessThan()


void read(Day* day) 
{
  Appointment* appt = (Appointment*)malloc(sizeof(Appointment));
  read(appt);
 
  if (day->apptCount == 0) // if appointments are empty
  {
    day->appts[0] = appt;
    day->apptCount++;
  } // appointment stored in first index
  
  else // if not empty
  {
    
    for (int i = day->apptCount - 1; i > -2; i--) // for each appointment
    {
      
      if (i > -1 && !(lessThan( day->appts[i], appt ))) 
      {
        day->appts[i + 1] = day->appts[i];
        continue;
      } // store appointment
      
      day->appts[i + 1] = appt;
      day->apptCount++;
      break;
    } // loops through the appointments currently stored in a day -apptCount
  
  } // store day according to it's precedence in calendar
  
  return;
} // read()

void print(Day* day) 
{
  printf("Start End   Subject      Location\n");
  
  for ( int i = 0; i < day->apptCount; i++) // for each appointment in day
  {
    print(day->appts[i]);
  } // print infomation stored in day
  
  return;
} // print()

void subjectSearch(Day* day, char* subjct)
{
  
  for (int i = 0; i < day->apptCount; i++) // for each appointment in day
  {
    
    if (equal( day->appts[i], subjct ))
    {
      printf("%2hi/%2hi/%2hi ", day->month, day->day, day->year);
      print(day->appts[i]);
    } // if subject in appointment is equal to subejct
  
  } // for subjects in array
  
  return;
} // subjectSearch()

void destroy( Day* day )
{
  
  for (int i = 0; i < day->apptCount; i++) // for every appointment in day
  {
    destroy(day->appts[i]);
    free(day->appts[i]);
  } // delete appointment
  
} // destroy()

