// Author: Sean Davis

#include <iostream>
#include <iomanip>
#include <string.h>
#include "appt.h"
#include "time.h"

using namespace std;

int Appointment::count = 0;

Appointment::Appointment() : subject(NULL), location(NULL)
{
  count++;
} // Appointment()


Appointment::Appointment(const Appointment &appt) : startTime(appt.startTime),
  endTime(appt.endTime), subject(NULL), location(NULL)
{
  if(appt.subject)
  {
    subject = new char[strlen(appt.subject) + 1];
    strcpy(subject, appt.subject);
  }  // if appt.subject not NULL
  
  if(appt.location)
  {
    location = new char[strlen(appt.location) + 1];
    strcpy(location, appt.location);
  } // if appt.location not NULL

  count++;
}  // Appointment copy constructor


Appointment::~Appointment()
{
  count--;

  if(subject)
    delete [] subject;
    
  if(location)
    delete [] location;
}  // ~Appointment()


void Appointment::addAppointment()
{
  char line[1000];
  cout << "Subject >> ";
  cin.getline(line, 1000);
  subject = new char[strlen(line) + 1];
  strcpy(subject, line);
  cout << "Location >> ";
  cin.getline(line, 1000);
  location = new char[strlen(line) + 1];
  strcpy(location, line);
  cout << "Start time (hh:mm) >> ";
  startTime.getTime();
  cout << "End time (hh:mm) >> ";
  endTime.getTime();
}  // addAppointment()


int Appointment::getCount()
{
  return count;
}  // getCount()


bool Appointment::operator== (const char *subject2)const
{
  return strstr(subject, subject2) != NULL;
}  // operator==()


bool Appointment::operator< (const Appointment &appointment2) const
{
  return startTime < appointment2.startTime; 
}  // operator< ()


ostream& operator<< (ostream &os, const Appointment &appointment)
{
  return appointment.write(os);
} // operator<< ()

istream& operator>> (istream &is, Appointment &appointment)
{
  char line[80];
  is.getline(line, 80, ',');
  appointment.subject = new char[strlen(line) + 1];
  strcpy(appointment.subject, line);
  is >> appointment.startTime;
  is >> appointment.endTime;
  is.getline(line, 80);
  appointment.location = new char[strlen(line) + 1];
  strcpy(appointment.location, line);
  return is;
} // operator>>()


Appointment* Appointment::clone() const
{
  Appointment *copy = new Appointment(*this);
  return copy;
} // clone()


Appointment* Appointment::read(istream &is)
{
  char line[80];
  is.getline(line, 80, ',');
  subject = new char[strlen(line) + 1];
  strcpy(subject, line);
  is >> startTime;
  is >> endTime;
  is.getline(line, 80, ',');
  location = new char[strlen(line) + 1];
  strcpy(location, line);
  return this;
} // read()


ostream& Appointment::write(ostream &os) const
{
  os << startTime << endTime << left << setw(13) 
  << subject << setw(26) << location;
  return os;
} // write()
