#include <iostream>
#include "UMap.h"

using namespace std;

//find the customer object and return it
//accept the Customer object
//return a loyalty number from the customer object
//and use the loyalty number to find the customer
Customer UMap:: find(Customer cust)
{
  int loyalty = cust.getLoyalty();
  unordered_map<int, Customer>::const_iterator got = umap.find(loyalty);
  return got->second;
}

//insert the customer object into the map, becuase the map request two parameters
//first, get the loyalty number from the customer object
//then add both the loyalty number and customer object to the map
void UMap:: insert(Customer cust)
{
  int loyalty = cust.getLoyalty();
  umap.insert({loyalty, cust});
}

//check if the customer exists
//accept a customer object, get the loyalty number from the object
//use the loyalty number to go through the map to see if the objecy exists
bool UMap::checkCust(Customer cust)
{
  int loyalty = cust.getLoyalty();
  unordered_map<int, Customer>::const_iterator got = umap.find(loyalty);
  if ( got == umap.end() )
  {
    return false;
  }
  else
    return true;
}

//find the customer by using loyalty
//return the customer object
Customer UMap:: lookUp(int loyalty)
{
  unordered_map<int, Customer>::const_iterator got = umap.find(loyalty);
  return got->second;
}

//update the customer info with the same loyalty
//use the loyalty number to get customer object
//reassign the customer object in the map
void UMap:: update(Customer cust)
{
  int loyalty = cust.getLoyalty();
  umap.at(loyalty) = cust;
}

//calcuate the average wait time
//go through the map and add up the waitime and registerCount
//then return waitTime/registerCount
int UMap::calcWaitTime()
{

  int i=0;
  for ( auto it = umap.begin(); it != umap.end(); ++it )
  {
    Customer cust = it->second;
     waitTime += cust.getTotalWaitTime();
    registerCount +=cust.getRegisterCount();
    i++;
  }
  int result = waitTime/registerCount;
  return result;
}

//return the wait time
int UMap::returnWaitTime()
{
  return waitTime;
}

//return the register count
int UMap::returnRegisterCount()
{
  return registerCount;
}

//calculate the max wait time
//go through the map and compare each max wait time
//return the largest
int UMap::calcMaxWaitTime()
{
  int temp = 0;
  for ( auto it2 = umap.begin(); it2 != umap.end(); ++it2 )
  {
    Customer cust = it2->second;
    if(cust.getMaxWaitTime() > temp)
    {
      temp = cust.getMaxWaitTime();
    }
  }
  return temp;
}
