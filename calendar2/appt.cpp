// Author: Sean Davis

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "appt.h"
#include "time.h"

using namespace std;

void Appointment::destroy() 
{
  delete [] subject;
  delete [] location;
}  // destroy()


bool Appointment::equal(const char *subjectInput) const
{
  return strstr(subject, subjectInput) != NULL;
}  // equal()


bool Appointment::lessThan(const Appointment *appointment2) const
{
  return startTime.lessThan(&appointment2->startTime); 
}  // lessThan()


void Appointment::print() const
{
  startTime.print();
  endTime.print();
  cout << left << setw(13) << setfill (' ') << subject << location 
          << right << endl;
  //printf("%-13s%s\n", subject, location);
} // print()


void Appointment::read()
{
  char *ptr;
  ptr = strtok(NULL, ",");
  subject = new char[strlen(ptr) + 1];
  strcpy(subject, ptr);
  startTime.read();
  endTime.read();
  ptr = strtok(NULL, "\n");
  location = new char[strlen(ptr) + 1];
  strcpy(location, ptr);
} // read()

