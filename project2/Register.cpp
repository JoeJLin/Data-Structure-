#include <iostream>
#include "Register.h"
// #include "Line.h"
// #include "UMap.h"
// #include "Cart.h"

using namespace std;

//this function accept the reference of a Line object
//use the line pointer point to this object, which linked them together
void Register::registerLine(Line *line1)
{
  linePtr = line1;//assign the pointer to the reference
}


//accpet an second counter
//get the first Cart object from the line
//return the time to the Cart object
//which may return the time to the customer object
void Register::nextCart(int arrRegisTime)
{
  //the line pointer return a reference of a Cart object
  //the Cart pointer assign to the reference of a cart object
  Cart * cartPtr = linePtr->front();

  int item = cartPtr->getNumItem();//return the number of item to item
  int arrLineTime = cartPtr->getArrivalTime();//return the arrival time
  totalTime = item * 9 + 60;//calculate the total time of register processing
  nextAvaTime = (item * 9 + 60 + arrRegisTime);
  //set next available time by add the arrival time with the total time

  int loyalty=cartPtr->returnCustomerLoyalty();//return the customer loyalty
  Customer cust = mapPtr->lookUp(loyalty);
  //the lookup function in the map class return a customer object
  //then assign the return object to cust
  //if the return object already have data inside, then the program will update the data

  cust.setRegisterCount();//update the register count
  cust.setTotalWaitTime(arrRegisTime - arrLineTime);//update the wait time in line
  cust.setpurchasedItemCount(item);//update purchased item count
  cust.setMaxWaitTime(arrRegisTime - arrLineTime);//update the maximim time
  mapPtr->update(cust);//put back the updated cust object to the map
  linePtr->remove();//remove the front object in the line
}

//return the total time
int Register::getTotalTime()
{
  return totalTime;
}

//return the next available time
int Register::getNextAvaTime()
{
  return nextAvaTime;
}

//accept the reference of an unordered map
//use the map pointer point to this object, which connected them together
void Register::getMap(UMap* umap)
{
  mapPtr = umap;
}

//set the next available time
void Register::setNextAvaTime(int time)
{
  nextAvaTime = time;
}
