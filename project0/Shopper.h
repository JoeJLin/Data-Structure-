#ifndef SHOPPER_H
#define SHOPPER_H

  class Shopper
  {
  private:
    long int loyalty;
    int cartSize;

  public:
    Shopper();
    Shopper(int);
    friend bool operator< (const Shopper&, const Shopper&);
    friend bool operator>(const Shopper&, const Shopper&);
    int priority;
    template<class T>
    friend class PriorityQueueSort;




  };

#endif
