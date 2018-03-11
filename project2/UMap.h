#ifndef UMAP_H
#define UMAP_H
#include "Customer.h"
#include <unordered_map>
using namespace std;

class UMap
{
public:
  Customer find(Customer);//find the customer object and return it
  Customer lookUp(int);//find the object by using the loyalty
  bool checkCust(Customer);//check if the customer exists
  void insert(Customer);//insert the customer to the map
  void update(Customer);//update the customer info with the same loyalty
  int calcWaitTime();//calculate the wait time, find out the average wait time
  int returnWaitTime();//return the wait time
  int returnRegisterCount();//return the register count
  int calcMaxWaitTime();//calculate the max wait time
private:
  unordered_map<int, Customer> umap;//declare a unordere map with type int and customer
  int waitTime =0;
  int registerCount = 0;
};
#endif
