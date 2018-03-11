#ifndef REGISTER_H
#define REGISTER_H
#include "Line.h"
#include "UMap.h"
// #include "Cart.h"

// class Line;
// class Cart;
class Register
{
  public:
    void registerLine(Line *);//accept the reference of a Line object
    int getTotalTime();//return the total time
    void nextCart(int );//accept a time to process next cart
    int getNextAvaTime();//return the next available time
    void getMap(UMap *);//accept the reference of an unordered map
    void setNextAvaTime(int );//set the next available time
  private:
    Line *linePtr;//Line type pointer
    UMap * mapPtr;//unordered map pointer
    int totalTime = 0;
    int nextAvaTime = 0;
};
#endif
