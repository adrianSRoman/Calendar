#include "calendar.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "appt.h"
#include "time.h"
#include "day.h"


void create(Calendar* calendar) 
{
  calendar->days = (Day*)malloc(sizeof(Day) * 30);
  calendar->size = 30;
  calendar->count = 0;
} // create()


void readFile(Calendar* calendar)
{
  Day dayTemp;
  char buffer[80];
  short month, day, year;
  FILE* fp = fopen("appts.csv", "r");
  fgets(buffer, 80, fp);
  
  while (fgets(buffer, 80, fp))
  {
    bool flag = true;
    month = atoi(strtok(buffer, "/"));
    day = atoi(strtok(NULL, "/"));
    year = atoi(strtok(NULL, ","));
    create(&dayTemp, month, day, year); 
    
    if (calendar->count == 0) 
    {
      calendar->days[0] = dayTemp;
      read(&calendar->days[0]); //
      calendar->count++;
      continue;
    } // if calendar is empty we assign the fist day in index zero
    
    if (calendar->count == calendar->size) 
    {
      resize(calendar);
    } // check size of array before to start storing information in it
    
    for (int i = calendar->count-1; i >= 0; i--)
    {
      
      if (equal(&calendar->days[i], &dayTemp)) 
      {
        read(&calendar->days[i]); //
        flag = false;
        break;
      } // new day is not created introduces information to dayr
    } // for day stored
    
    if (flag)
      
      for (int i = calendar->count-1; i > -2; i--)
      {     
        if (i > -1 && lessThan(&calendar->days[i], &dayTemp))
        {
          calendar->days[i + 1] = calendar->days[i];
          continue;
        }//switching array of days for sorting in order
        
        calendar->days[i + 1] = dayTemp;
        read(&calendar->days[i + 1]);
        calendar->count++;
        break;
      } // pretty interesting, spent more than three days
  } // while loop, reads each line, fgets safely ends iterations
  
  fclose(fp);
  return;
} // readFile()


void resize(Calendar* calendar)
{
  int nSize = calendar->size * 2;
  Day* tempArray = (Day*)malloc(sizeof(Day)*(nSize));

  for (int i = 0; i < calendar->count; i++)
  {  
    tempArray[i] = calendar->days[i];
  } // assigning information to the days array
  
  free(calendar->days);  
  calendar->days = tempArray;
  calendar->size = nSize;
  return;
} // resize()


void dateSearch(Calendar* calendar)
{
  Day userDay;
  int day;
  int month;
  int year;
  getDate(&month, &day, &year);
  create(&userDay, month, day, year);
  
  for (int i = 0; i < calendar->count; i++)
  {
    
    if (equal(&calendar->days[i], &userDay))
    {
      print(&calendar->days[i]);
        return;    
    } // if day equal
  
  } // for every day in calendar
 
  printf("That date was not found.");
  return;
} // dateSearch()

void subjectSearch(Calendar* calendar)
{
  char buffer[80];
  char* subjct;
  
  while (true)
  {
    printf("Please enter the subject >> ");
    fgets(buffer, 80, stdin);
    subjct = strtok(buffer, "\n");
    printf("Date       Start End   Subject      Location\n");
    
    for (int i = 0; i < calendar->count; i++) // find subject in days  
    {
      subjectSearch(&calendar->days[i], subjct);
    } // for every day in the array
    
    printf("\n");
    return;
  } // while subjects are being searched
  
  return;
} // subjectSearch()



void getDate(int* month, int* day, int* year) 
{
  char buffer[80], onlyTwo[80];
  char* m, *d, *y;
  
  while (true)
  {
    printf("Please enter the month, day, and year (mm/dd/yyyy) >> ");
    fgets(buffer, 80, stdin);
    strcpy(onlyTwo, buffer);
    m = strtok(buffer, "/");
    d = strtok(NULL, "/");
    y = strtok(NULL, "\n");
    
    if (d == NULL || y == NULL) // if strtok doesn't read one of month-day-year
    {
      strtok(onlyTwo, "\n");
      printf("%s is not a valid date.\n", onlyTwo);
      printf("Please try again.\n\n");
    } // look for somethin
    
    else // if input are numbers
    {
      *month = atoi(m), *day = atoi(d), *year = atoi(y);
      bool yearrange = *year >= 1000 && *year <= 2017;
      bool dayrrange = *day > 0 && *day <= 31;
      bool monthrange = *month >= 0 && *month <= 12;
     
     if (yearrange && dayrrange && monthrange) // date in correct range
      {
        return;
      } // if day in range
      
      else // correct input but date not in range of calendar
      {
        printf("%d/%d/%d is not a valid date.\n", *month, *day, *year);
        printf("Please try again.\n\n");
      } // correct input
    
    } // check input
  
  } // while input is not correct
  
  return;
} // getDate()

void destroy(Calendar* calendar)
{
  
  for (int i = 0; i < calendar->count; i++) 
  {
    destroy(&calendar->days[i]);
  } // for every day stored in array
  
  free(calendar->days);
} // destroy()

    

  


