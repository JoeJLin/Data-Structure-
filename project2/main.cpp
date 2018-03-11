#include<iostream>
#include "Store.h"
using namespace std;

int main()

{
  // //1000 times of simulation for busy mode
  Store arrStore[1000] = {}; //create a type Store array for 1000 times of simulation

  for(int i = 0; i<1000; i++)
  {
    arrStore[i].startBusyMode();//start a 4 hours of busy mode simulation
    arrStore[i].busyModeReport();//print out the report for busy mode simulation
  }

  //1000 times of simulation for slow mode
  Store arrStore2[1000] = {};
  for(int i = 0; i<1000; i++)
  {
    arrStore2[i].startSlowMode();//start a 4 hours of slow mode simulation
    arrStore2[i].slowModeReport();//print out the report for slow mode simulation
  }

}
