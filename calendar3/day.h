// Author: Sean Davis
// Programmer: Adrian S Roman

#ifndef DAY_H
#define	DAY_H
#include "appt.h"

class Day
{
  short day;
  short month;
  short year;
  Appointment *appts[8];
  short apptCount;

public:
  Day();
  ~Day();
  Day(int day1, int month, int year);
  Day& operator = (const Day & d);
  void readDay(const char* sub, const char* loc);
  //bool Day::operator==(const Day &dayNew) const;
  bool equal(const Day *day2) const;
  bool lessThan(const Day *day2) const;
  void print() const;
  void read();
  void read(char* sub, char* loc);
  void subjectSearch(const char *subject) const;
}; // Day


#endif	// DAY_H 

