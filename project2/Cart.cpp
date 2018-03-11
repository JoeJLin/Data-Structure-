#include "Cart.h"
// #include "Customer.h"
#include <random>
#include <chrono>

using namespace std;

unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator1(seed1);
std::poisson_distribution<int> distribution1(6);
//this random number generator generates numbers with the mean of 6

//default constructor of a cart
Cart::Cart()
{
  departureTime = 0;//set departure time of the cart to 0
  arrivalTime = 0;//set arrival time of the cart to 0
  setNumItem(distribution1(generator1));//assign a random to the number of item
}

//return the number of items in cart
int Cart:: getNumItem()
{
  return numItem;
}

//return the departure time of cart
int Cart:: getDepartureTime()
{
  return departureTime;
}

//return the arrival time of cart
int Cart::getArrivalTime()
{
  return arrivalTime;
}

//return the time wait in line for cart
int Cart:: getWaitLineTime()
{
  return waitLineTime;
}

//return the loyalty of the customer in cart
//use the Customer pointer which is pointing to a customer object
//it ask that object to return the loyalty
int Cart:: returnCustomerLoyalty()
{
  return customer->getLoyalty();
}

//accept a integer and set it to the number of items
void Cart:: setNumItem(int item)
{
  numItem = item;
}

//accept a integer and set it to the departure time
void Cart:: setDepartureTime(int time)
{
  departureTime = time;
}

//accept a integer and set it to the arrival time
void Cart::setArrivalTime(int time)
{
  arrivalTime = time;
}

//accept a integer and set it to the wait line time
void Cart::setWaitLineTime(int time)
{
  waitLineTime = time;
}

//this function accept the address of a Customer object
//and the program assign pointer from private points the that object
void Cart:: getCustomer(Customer * cust)
{
  customer = cust;
}

//return the customer object from the cart
//This function dereference the customer pointer which will become a object
Customer Cart::returnCustomer()
{
  return *customer;
}
