#include "Line.h"
#include <iostream>
#include <queue>

using namespace std;

//this function accept a Cart object, and  arrival time
//push the Cart object into the queue
//set the arrival time in the cart
void Line::add(Cart cart, int time)
  {
    cart.setArrivalTime(time);
    line.push(cart);
  }

//remove the front of the queue
void Line::remove()
  {
    line.pop();
  }

//return the size of the queue
int Line:: sizeOfQueue()
  {
    return line.size();
  }

//return a pointer of the front object in the queue
Cart* Line:: front()
  {
    return &line.front();
  }

//return the front cart object in the queue
Cart Line:: returnFront()
  {
    return line.front();
  }
