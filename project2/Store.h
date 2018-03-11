#ifndef STORE_H
#define STORE_H
// #include "Cart.h"
// #include "Line.h"
#include "Register.h"
#include "UMap.h"

class Store
{
public:
  void startSlowMode();//start the slow mode simulation
  void slowModeReport();//print out a report for slow mode
  void startBusyMode();//start the busy mode simulation
  void busyModeReport();//print out a report for busy mode
  int smallestSize(int, int, int);//this function find the smallest value among all
private:
  UMap slowMap;//initialize a unordered_map for slow mode
  UMap busyMap;//initialize a unordered_map for busy mode
  int maxLineSizeSlow = 0;//initialize data
  int idleTimeSlow = 0;
  int maxLineSizeBusy = 0;
  int idleTimeBusy = 0;
};
#endif
