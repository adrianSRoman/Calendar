#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

#include "DayOfWeek.h"

using namespace std;

void DayOfWeek::read(int month, int day, int year)
{
  int index = 0;
  index = ((year - 1990) * 372) + ((month - 1) * 31) + (day - 1);
  ifstream infile;
  infile.open("DOW.dat", ios::binary);
  infile.seekg(index * sizeof(DayOfWeek));
  infile.read((char*) this, sizeof(DayOfWeek));
  infile.close();
  return;
} // binary file reader


void DayOfWeek::print()
{
  char dayOfWeek[80];
  char num[4];
  int unit = 0;
  int dec = 0;

  if ( day >= 10 )
  {
    dec = day / 10;
    unit = day % 10;
    num[0] = dec + '0';
    num[1] = unit + '0';
    num[2] = '\0';
  } // if day contains two digits

  else // only one digit
  {
    num[0] = day + '0';
    num[1] = '\0';
  } // is only one digit

  strcpy(dayOfWeek, dayName);
  strcat(dayOfWeek, ", ");
  strcat(dayOfWeek, monthName);
  strcat(dayOfWeek, " ");
  strcat(dayOfWeek, num);
  cout << left << setw(30) << dayOfWeek << right << setfill(' '); 
} // print()
