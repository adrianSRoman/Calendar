// Author: Sean Davis 
// Created on April 2, 2017, 3:51 PM
#include <iostream>
#include "calendar.h"

using namespace std;

int getChoice()
{
  int choice;
  char line[80];
  
  while(true)
  {
    cout << "Calendar Menu" << endl;
    cout << "0. Done" << endl;
    cout << "1. Search for date." << endl;
    cout << "2. Search for subject" << endl;
    cout << endl << "Your choice >> ";
    cin >> choice;
    //printf("Calendar Menu\n");
    //printf("0. Done\n");
    //printf("1. Search for date.\n");
    //printf("2. Search for subject.\n");
    //printf("\nYour choice >> ");
    //scanf("%d", &choice);
    
    if(choice >= 0 && choice < 3)
      break;
    
    cout << "Choice must be between 0 and 2. Please try again." << endl << endl;
    // printf("Choice must be between 0 and 2.  Please try again.\n\n");
  }  // while invalid choice
  
  cin.getline(line, 80);
  return choice;
} // getChoice()


int main() 
{
  Calendar calendar;
  int choice;
  calendar.create();
  calendar.readFile();
  choice = getChoice();
  
  while(choice)
  {
    if(choice == 1)
      calendar.dateSearch();
    else // choice not 1
      calendar.subjectSearch();
  
    choice = getChoice();
  } // while choice not 0.

  calendar.destroy();
  return 0;
} // main())

