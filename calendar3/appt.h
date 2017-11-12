// Author: Sean Davis
// Programmer: Adrian S Roman


#ifndef APPT_H
#define	APPT_H
#include "time.h"

class Appointment
{
  Time startTime;
  Time endTime;
  char *subject;
  char *location;
  static int count;
public:
  Appointment();
  ~Appointment();
  Appointment(const Appointment &appointment2);
  static int getCount();
  void readAppt(const char* subjct, const char* loctn);
  bool equal(const char *subject) const;
  bool lessThan(const Appointment *appointment2) const;
  void print() const;
  void read();
}; // Appointment

#endif	// APPT_H 
