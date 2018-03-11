#include "Customer.h"
#include <random>
#include <cstdlib>
#include <chrono>

using namespace std;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator(seed);
std::uniform_int_distribution<int> distribution(0,9999);
//generate a random number between 0 to 9999 for customer loyalty

//Customer constructor: initialize all the variables in private
Customer::Customer()
{
  purchasedItemCount = 0;
  registerCount = 0;
  loyalty = distribution(generator);//accpet a random value
  totalWaitTime = 0;
  maxWaitTime = 0;
}

//return a customer loyalty
int Customer::getLoyalty()
{
  return loyalty;
}

//return a count of purchased item
int Customer::getpurchasedItemCount()
{
  return purchasedItemCount;
}

//return a total wait time
int Customer::getTotalWaitTime()
{
  return totalWaitTime;
}

//return a count of how many the customer been to a register
int Customer::getRegisterCount()
{
  return registerCount;
}

//accept a integer parameter, and add it to existing purchased item count
void Customer::setpurchasedItemCount(int newItemCount)
{
  purchasedItemCount += newItemCount;//add up
}

//accept a integer parameter, and add it to existing wait time
void Customer::setTotalWaitTime(int newTime)
{
  totalWaitTime += newTime;
}

//increment the register count
void Customer::setRegisterCount()
{
  registerCount++;
}

//Customer equal operator
Customer& Customer:: operator = (const Customer& other)
{
  this->purchasedItemCount= other.purchasedItemCount;
  this->registerCount=other.registerCount;
  this->loyalty=other.loyalty;
  this->totalWaitTime=other.totalWaitTime;
  this->maxWaitTime=other.maxWaitTime;
  return *this;
}

//return the largest wait time for customer
int Customer:: getMaxWaitTime()
{
  return maxWaitTime;
}

//set the largest wait time
void Customer::setMaxWaitTime(int time)
{
    if(maxWaitTime <= time)//check if the existing time is larger than the new time
    {
      maxWaitTime = time;//if the existing time is smaller, overwrite the maxWaitTime
    }
}
