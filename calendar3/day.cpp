// Author: Sean Davis
// Programmer: Adrian S Roman

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "day.h"
#include "appt.h"
#include "DayOfWeek.h"

using namespace std;

Day::Day()
{
  apptCount = 0;
} // Day()

Day::Day(int day1, int month1, int year1) 
{
  day = day1;
  month = month1;
  year = year1;
  apptCount = 0;
}  // day constructor()


Day& Day::operator=( const Day& d )
{
  if (&d == this) // if some garbage
    return *this;

  for (int i = 0; i < apptCount; i++)
  {
     delete appts[i]; // ->destroy();
  } // for appointments

  for (int i = 0; i < d.apptCount; i++)
    appts[i] = new Appointment(*d.appts[i]);

  day = d.day;
  month = d.month;
  year = d.year;
  apptCount = d.apptCount;
  return *this;
} // overloaded assignment operator

/*
bool Day::operator==(const Day &dayNew) const 
{
  return (*this == dayNew);
}
*/

bool Day::equal(const Day *day2) const
{
  return day == day2->day && month == day2->month 
    && year == day2->year;
} // equal()


bool Day::lessThan(const Day *day2) const
{
  return (year < day2->year)
    || (year == day2->year && month < day2->month)
    || (year == day2->year && month == day2->month 
      && day < day2->day); 
} // lessThan()


void Day::print() const
{
  cout << "Start End   Subject      Location\n";
  
  for(int i = 0; i < apptCount; i++)
   appts[i]->print();
  
  cout << endl;
} // print90

void Day::read()
{
  int pos;
  Appointment *appointment = new Appointment;
  appointment->read();
  
  for(pos = apptCount - 1; 
    pos >= 0 && appointment->lessThan(appts[pos]); pos--)
      appts[pos + 1] = appts[pos];
  
  appts[pos + 1] = appointment;
  apptCount++;
} // read()


void Day::subjectSearch(const char *subject) const
{

  for(int i = 0; i < apptCount; i++)
  {
    if(appts[i]->equal(subject))
    {
      DayOfWeek D;
      D.read(month, day, year);
      D.print();
      appts[i]->print();
    } // if appointment

  } // for appointment
      
} // subjectSearch()

void Day::readDay(const char* sub, const char* loc)
{
  int pos;
  Appointment *appointment = new Appointment;
  appointment->readAppt(sub, loc);

  for(pos = apptCount - 1;
    pos >= 0 && appointment->lessThan(appts[pos]); pos--)
      appts[pos + 1] = appts[pos];

  appts[pos + 1] = appointment;
  apptCount++;
  return;
} // readDay


Day::~Day()
{

  for (int i = 0; i < apptCount; i++)
  {
    delete appts[i];
  } // for appointment

} // for appointment
