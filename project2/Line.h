#ifndef LINE_H
#define LINE_H
#include <queue>
#include "Cart.h"

class Line
{
  public:
    void add(Cart, int);//accept a Cart object, and time
    void remove();//remove the front of the queue
    Cart * front();//return a pointer of the front object in the queue
    int sizeOfQueue();//return the size of the queue
    Cart returnFront();//return the front cart object in the queue

  private:
    std::queue<Cart> line;//declare a queue with Cart type

};
#endif
