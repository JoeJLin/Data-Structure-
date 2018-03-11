#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
  public:
    Customer();//default constructor, initialize data
    int getLoyalty();//return customer loyalty
    int getpurchasedItemCount();//return purchased item count
    int getTotalWaitTime();//return wait time
    int getRegisterCount();//return register count
    int getMaxWaitTime();//return the largest wait time
    void setMaxWaitTime(int );//set the largest wait time
    void setpurchasedItemCount(int);//set the count of purchased item
    void setTotalWaitTime(int); //set wait time at line
    void setRegisterCount(); //increment register count
    Customer& operator = (const Customer&); //equal operator

  private:
    int purchasedItemCount;
    int registerCount;
    int loyalty;
    int totalWaitTime;
    int maxWaitTime;
};


#endif
