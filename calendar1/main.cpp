#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calendar.h"
#include "day.h"

int getChoice()
{
  char endl[80];
  int result;
  printf("Calendar Menu\n");
  printf( "0. Done\n");
  printf("1. Search for date.\n");
  printf("2. Search for subject.\n");
  printf("\n");
  printf("Your choice >> ");
  scanf("%d", &result);
  fgets(endl, 80, stdin);
  return result;
} // getChoice() receives user input zero-one-two for searching in calendar

int main()
{
  Calendar calendar; // = (Calendar*)malloc(sizeof(Calendar))
  create(&calendar);
  readFile(&calendar);
  int choice = getChoice();
  
  while (true) 
  {   
    if (choice == 1) // one
    {
      printf("\n");
      dateSearch(&calendar);
      printf("\n");
    } // one runs search for dates
    
    if (choice == 2) // two
    {
      subjectSearch(&calendar);
    } // two runs search for subjects
    
    if (choice == 0) // zero
    {
      break;
    } // zero
    
    if (choice != 0 && choice != 1 && choice != 2) // if out of range 
    {
      printf ("Choice must be between 0 and 2.  Please try again.\n\n");
    } // other number
    
    choice = getChoice();
  
  } // iterate under constraint one-two-three
  
  destroy(&calendar);
  return 0;
} // main() function
    
  




