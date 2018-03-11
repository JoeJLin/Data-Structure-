#include "Store.h"
// #include "Customer.h"
// #include "Cart.h"
// #include "Line.h"
// #include "Register.h"
// #include "UMap.h"
#include <iostream>
#include <random>
using namespace std;

unsigned seed2 =
     std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator3 (seed2);
std::exponential_distribution<double> distribution3 (1/30.0);
//busy mode random number generator

unsigned seed3 =
     std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator4 (seed3);
std::exponential_distribution<double> distribution4 (1/120.0);
//slow mode random number generator

void Store:: startSlowMode()
{
  Line firstLine;//declare line
  Line secondLine;
  Register firstRegister;//declare register
  Register secondRegister;
  Cart arrCart[1000]={};//declare an array of cart
  Customer arrCustomer[1000]={};//declare an array of customer
  int secondCounter = 0;//delcare a second counter
  int i = 0;//the index of the array
  int temp = 0;
  firstRegister.registerLine(&firstLine);//put the reference of line inside the register
  secondRegister.registerLine(&secondLine);
  firstRegister.getMap(&slowMap);//put the reference of map inside the register
  secondRegister.getMap(&slowMap);

  for(int i = 0; i<1000; i++)//put the reference of customer inside the cart
  {
    arrCart[i].getCustomer(&arrCustomer[i]);
  }

  //4 hours of simulation
  //using a second counter
  //after each loop, the second counter increment by 1
  while(secondCounter != 14400)
  {
    //if the second counter equal the next available time
    //then set the next available time to 0
    if(secondCounter == firstRegister.getNextAvaTime())
    {
      firstRegister.setNextAvaTime(0);
    }
    if(secondCounter == secondRegister.getNextAvaTime())
    {
      secondRegister.setNextAvaTime(0);
    }

    //the time the customer come in
    //the current plus the random time
      if(secondCounter == (secondCounter + static_cast<int>(distribution4(generator4))))
      {
        //compare the size of the two line, the one with smaller add object
        if(firstLine.sizeOfQueue() < secondLine.sizeOfQueue())
        {
          firstLine.add(arrCart[i], secondCounter);
          i++;//increment the i
        }
        else
        {
          secondLine.add(arrCart[i], secondCounter);
          i++;
        }
      }
      //for idle time, if no one online or no one is paying, then increment the idle time
      if((firstLine.sizeOfQueue() == 0&& firstRegister.getNextAvaTime()>0)
      || (secondLine.sizeOfQueue()==0 && secondRegister.getNextAvaTime()>0))
      {
        idleTimeSlow++;
      }

      //if the size of the queue is greater than 0
    if(firstLine.sizeOfQueue() != 0)
    {
      //if the next available time is 0, then put the cart to the register
      if(firstRegister.getNextAvaTime() == 0)
      {
        //check if the customer is exists
        if(slowMap.checkCust((firstLine.returnFront()).returnCustomer()) != true)
        {
          //if not exists, add the customer
          slowMap.insert((firstLine.returnFront()).returnCustomer());
        }
          firstRegister.nextCart(secondCounter);//process next cart
      }

    }
    if(secondLine.sizeOfQueue() != 0)
    {
      if(secondRegister.getNextAvaTime() == 0)
      {
        if(slowMap.checkCust((secondLine.returnFront()).returnCustomer()) != true)
        {
          slowMap.insert((secondLine.returnFront()).returnCustomer());
        }
          secondRegister.nextCart(secondCounter);
      }
    }
      //increment the second counter
      secondCounter++;
      //check for the maximum size of the line
      temp = max(firstLine.sizeOfQueue(), secondLine.sizeOfQueue());
      if(temp > maxLineSizeSlow)
      maxLineSizeSlow = temp;
  }
}

//print the the report for slow mode
void Store::slowModeReport()
{
  cout<<endl;
  cout<<"-------------------------------------------------"<<endl;
  cout<<"The average wait time is "<<slowMap.calcWaitTime()<<endl;
  cout<<"The max wait time "<<slowMap.calcMaxWaitTime()<<endl;
  cout<<"The max line size "<<maxLineSizeSlow<<endl;
  cout<<"The idle time is "<<idleTimeSlow<<endl;
  cout<<"-------------------------------------------------"<<endl;
  cout<<endl;
}

//busy mode simulation
void Store::startBusyMode()
{
  Line firstLine;//delcare line
  Line secondLine;
  Line thirdLine;
  Register firstRegister;//delcare register
  Register secondRegister;
  Register thirdRegister;
  Cart arrCart[1000]={};
  Customer arrCustomer[1000]={};
  int secondCounter = 0;
  int i = 0;
  int temp = 0;
  int tempSize = 0;
  firstRegister.registerLine(&firstLine);
  secondRegister.registerLine(&secondLine);
  thirdRegister.registerLine(&thirdLine);
  firstRegister.getMap(&busyMap);
  secondRegister.getMap(&busyMap);
  thirdRegister.getMap(&busyMap);
  for(int i = 0; i<1000; i++)
  {
    arrCart[i].getCustomer(&arrCustomer[i]);
  }


  while(secondCounter != 14400)
  {
    if(secondCounter == firstRegister.getNextAvaTime())
    {
      firstRegister.setNextAvaTime(0);
    }
    if(secondCounter == secondRegister.getNextAvaTime())
    {
      secondRegister.setNextAvaTime(0);
    }
    if(secondCounter == thirdRegister.getNextAvaTime())
    {
      thirdRegister.setNextAvaTime(0);
    }
      if(secondCounter == (secondCounter + static_cast<int>(distribution3(generator3))))
      {
        //find out which line has less customer, and put it in
        tempSize = smallestSize(firstLine.sizeOfQueue(), secondLine.sizeOfQueue(), thirdLine.sizeOfQueue());
        if(tempSize == 1)
        {
          firstLine.add(arrCart[i], secondCounter);
          i++;
        }
        else if(tempSize == 2)
        {
          secondLine.add(arrCart[i], secondCounter);
          i++;
        }
        else if(tempSize == 3)
        {
          thirdLine.add(arrCart[i], secondCounter);
          i++;
        }
        else
        {
          firstLine.add(arrCart[i], secondCounter);
          i++;
        }

      }
      if((firstLine.sizeOfQueue() == 0&& firstRegister.getNextAvaTime()>0)
      || (secondLine.sizeOfQueue()==0 && secondRegister.getNextAvaTime()>0)
      || (thirdLine.sizeOfQueue() == 0 && thirdRegister.getNextAvaTime()>0 ))
      {
        idleTimeBusy++;
      }
    if(firstLine.sizeOfQueue() != 0)
    {
      if(firstRegister.getNextAvaTime() == 0)
      {
        if(busyMap.checkCust((firstLine.returnFront()).returnCustomer()) != true)
        {
          busyMap.insert((firstLine.returnFront()).returnCustomer());
        }
          firstRegister.nextCart(secondCounter);
      }

    }
    if(secondLine.sizeOfQueue() != 0)
    {
      if(secondRegister.getNextAvaTime() == 0)
      {
        if(busyMap.checkCust((secondLine.returnFront()).returnCustomer()) != true)
        {
          busyMap.insert((secondLine.returnFront()).returnCustomer());
        }
          secondRegister.nextCart(secondCounter);
      }
    }
    if(thirdLine.sizeOfQueue() != 0)
    {
      if(thirdRegister.getNextAvaTime() == 0)
      {
        if(busyMap.checkCust((thirdLine.returnFront()).returnCustomer()) != true)
        {
          busyMap.insert((thirdLine.returnFront()).returnCustomer());
        }
          thirdRegister.nextCart(secondCounter);
      }
    }
      secondCounter++;
      temp = max({firstLine.sizeOfQueue(), secondLine.sizeOfQueue(), thirdLine.sizeOfQueue()});
      if(temp > maxLineSizeBusy)
      maxLineSizeBusy = temp;
  }

}

//accept three integers, and find out the smallest, and return it
int Store::smallestSize(int a, int b, int c)
{
  int i = min({a, b, c});
  if(i == a)
    return 1;
  else if(i == b)
    return 2;
  else if(i == c)
    return 3;
  return 0;
}

//print out the busy mode report
void Store::busyModeReport()
{
  cout<<endl;
  cout<<"-------------------------------------------------"<<endl;
  cout<<"The average wait time is "<<busyMap.calcWaitTime()<<endl;
  cout<<"The max wait time "<<busyMap.calcMaxWaitTime()<<endl;
  cout<<"The max line size "<<maxLineSizeBusy<<endl;
  cout<<"The idle time is "<<idleTimeBusy<<endl;
  cout<<"-------------------------------------------------"<<endl;
  cout<<endl;
}
