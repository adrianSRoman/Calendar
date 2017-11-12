#include "weeklyappt.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;


WeeklyAppointment* WeeklyAppointment::clone() const
{
  WeeklyAppointment *copy = new WeeklyAppointment(*this);
  return copy;
} // clone()


WeeklyAppointment::WeeklyAppointment(const WeeklyAppointment &wappt) :
  Appointment(wappt), seriesCount(wappt.seriesCount)
{
  strcpy(series, wappt.series);
} // WeeklyAppointment() copy constructor


WeeklyAppointment::WeeklyAppointment() : Appointment(), seriesCount(0)
{} // WeeklyAppointment() default constructor


WeeklyAppointment::~WeeklyAppointment()
{} // ~WeeklyAppointment()


WeeklyAppointment* WeeklyAppointment::read(istream &is)
{
  this->Appointment::read(is);
  is.getline(series, 80, ',');
  char seriesAmount[10];
  is.getline(seriesAmount, 10);
  seriesCount = atoi(seriesAmount);
  return this;
} // read()

const char* WeeklyAppointment::getSeries() const
{
  return series;
} // getSeries()

int WeeklyAppointment::getSeriesCount() const
{
  return seriesCount;
} // getSeriesCount()

ostream& WeeklyAppointment::write(ostream &os) const
{
  Appointment::write(os);
  os << setw(8) << series << '(' << seriesCount << ')';
  return os;
} // write()
