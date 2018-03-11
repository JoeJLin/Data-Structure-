 #include "PriorityQueueSort.h"
 #include "Shopper.h"
 #include "PQSearch.h"
#include <iostream>
#include <chrono>
#include <random>
#include "utils.h"

using namespace std;
using namespace ods;

int main()
{
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(1,10);

  PriorityQueueSort<Shopper> shopperSortArray;
  auto start4 = chrono::steady_clock::now();
  for(int i=0; i<10000; i++)
  {
    Shopper sortShopper(distribution(generator));
    shopperSortArray.add(sortShopper);

    //shopperSortArray.getPriority();
    //cout<<endl;
    //cout<<"after sorting"<<endl;
    //shopperSortArray.sorting();

    //shopperSortArray.getPriority();
    //cout<<endl;
    //cout<<endl;
  }
  //shopperSortArray.display();
  //cout<<endl;
  shopperSortArray.sorting();
  //shopperSortArray.display();
  //cout<<endl;
  //shopperSortArray.sorting();
  /*for(int i=0; i<5000; i++)
  {
  Shopper sortShopper(distribution(generator));
  cout<<shopperSortArray.getPriority(sortShopper)<<" ";
}*/
  auto end4 = chrono::steady_clock::now();
  auto diff4 = end4 - start4;
  cout <<"Priority Queue sort add shopper: "<< chrono::duration <double, milli> (diff4).count() << " ms" << endl;

  auto start5 = chrono::steady_clock::now();

  for(int i=0; i<10000; i++)
  {
    //cout<<"before remove is called"<<endl;
    //shopperSortArray.getPriority();
    //cout<<endl;
    //shopperSortArray.moveFront();
    shopperSortArray.remove();
    //cout<<"after remove is called"<<endl;
    //shopperSortArray.getPriority();
    //shopperSortArray.display();
    //cout<<endl;

  }
  cout<<"now"<<endl;
  //shopperSortArray.display();
  auto end5 = chrono::steady_clock::now();
  auto diff5 = end5 - start5;
  cout <<"Priority Queue sort remove shopper: "<< chrono::duration <double, milli> (diff5).count() << " ms" << endl;

}
