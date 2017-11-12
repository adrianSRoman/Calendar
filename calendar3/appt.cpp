// Author: Sean Davis
// Programmer: Adrian S Roman

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "appt.h"
#include "time.h"

using namespace std;

int Appointment::count = 0;

int Appointment::getCount()
{
  return count;
} // static counter

Appointment::Appointment()  
{
  subject = NULL;
  location = NULL;
} // default constructor

Appointment::Appointment(const Appointment &appointment2)
{
  if (appointment2.subject)
  {
    subject = new char[strlen(appointment2.subject) + 1];
    strcpy(subject, appointment2.subject);
  } // if there ecist an appointment

  else // if appointment doesnt exist
    subject = NULL;

  if (appointment2.location)
  {
    location = new char[strlen(appointment2.location) + 1];
    strcpy(location, appointment2.location);
  } // if location exist

  else // set location to NULL
    location = NULL;

  startTime = appointment2.startTime;
  endTime = appointment2.endTime;
} // Copy Constructor


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
  cout << left << setw(13) << subject << location << right << endl;
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
  count++;
} // read()


void Appointment::readAppt(const char* subjct, const char* loctn)
{ 
  char sTime[6], eTime[6];
  cout << "Start time (hh:mm) >> ";
  cin.getline(sTime, 6);
  cout << "End time (hh:mm) >> ";
  cin.getline(eTime, 6);
  subject = new char[strlen(subjct) + 1];
  strcpy(subject, subjct);
  startTime.readUsrTime(sTime);
  endTime.readUsrTime(eTime);
  location = new char[strlen(loctn) + 1];
  strcpy(location, loctn);
  count++;
} // readAppt()

Appointment::~Appointment()
{
  delete [] subject;
  delete [] location;
} // destructor
