#ifndef CART_H
#define CART_H
#include "Customer.h"

class Cart
{
  public:
    Cart();//a default constructor that initialize all the variables
    int getNumItem();//return the number of items in cart
    int getDepartureTime();//return the departure time of cart
    int getArrivalTime();//return the arrival time of cart
    int getWaitLineTime();//return the time wait in line for cart
    void setWaitLineTime(int );//set wait line time
    void setNumItem(int);//set the number of items
    void setDepartureTime(int);//set the departure time
    void setArrivalTime(int);//set the arrival time
    void getCustomer(Customer *);//points to the address of the customer
    int returnCustomerLoyalty();//return the loyalty of the customer in cart
    Customer returnCustomer();//return the customer object from the cart

  private:
    Customer * customer;//a customer type pointer
    int numItem;
    int departureTime;
    int arrivalTime;
    int waitLineTime;
};

#endif
