// Author: Sean Davis
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "time.h"

using namespace std;

bool Time::lessThan(const Time *time2) const
{
  return hour < time2->hour 
    || (hour == time2->hour && minute < time2->minute);
} // lessThan()


void Time::print() const
{
  cout << setfill ('0') << setw(2) << hour << ":" <<
          left << setw(2) << setfill ('0') << minute << " ";
  //printf("%02d:%02d ", hour, minute);
} // print()


void Time::read()
{
  char *ptr;
  
  hour = atoi(strtok(NULL, ":"));
  minute = atoi(strtok(NULL, ":"));
  ptr = strtok(NULL, ",");
  
  if(strchr(ptr, 'P'))
  {
    if (hour < 12)
      hour += 12;
  }
  else {
    if (hour == 12)
      hour -= 12;
  }
    
  
} // read()
