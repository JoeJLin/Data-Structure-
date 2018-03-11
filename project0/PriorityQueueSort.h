#ifndef PRIORITYQUEUESORT_H_
#define PRIORITYQUEUESORT_H_

#include "ArrayQueue.h"
using namespace std;
namespace ods {

template <class T>
  class PriorityQueueSort : public ArrayQueue<T>
  {
  public:
    PriorityQueueSort();
    void getPriority();
    void sorting();
    //virtual T removeMin();
    //void display();
    int getSize();
    int getIndex();
  protected:
      int size;
      int firstIndex;
    };

template<class T>
void PriorityQueueSort<T>::getPriority()
{
  for (int k=ArrayQueue<T>::j; k<ArrayQueue<T>::n+ArrayQueue<T>::j; k++)
  std::cout<<ArrayQueue<T>::a[k].priority<<" ";
}


template<class T>
PriorityQueueSort<T>::PriorityQueueSort()
{
  int size=getSize();
  int firstIndex=getIndex();
}

template<class T>
int PriorityQueueSort<T>::getSize()
{
  return ArrayQueue<T>::n;
}

template<class T>
int PriorityQueueSort<T>::getIndex()
{
  return ArrayQueue<T>::j;
}
template<class T>
void PriorityQueueSort<T>:: sorting()
{
int gap,i,j;
T temp;

for(gap=this->n/2;gap>0;gap/=2)
{
    for(i=gap;i<this->n;i+=1)
    {
        temp=this->a[i];
        for(j=i;j>=gap&&this->a[j-gap]>temp;j-=gap)
            this->a[j]=this->a[j-gap];

        this->a[j]=temp;
    }
}
}
/*
template<class T>
void PriorityQueueSort<T>::display(){
  for (int k=this->j; k<this->n+this->j; k++)
  {
   std::cout<<ArrayQueue<T>::a[k]<<" ";
  }
}
*/
/*
template<class T>
void PriorityQueueSort<T>::sorting()
{
  for(int i=0; i <(this->n-1); i++)
      for(int j=0; j <(this->n-i-1); j++)
    {
        T temp;
        if(this->a[j]>this->a[j+1])
        {
            temp=this->a[j];
            this->a[j]=this->a[j+1];
            this->a[j+1]=temp;
        }
    }
}
*/
/*
template<class T>
T PriorityQueueSort<T>::removeMin() {
 T x = ArrayQueue<T>::a[ArrayQueue<T>::j];
 ArrayQueue<T>::j = (ArrayQueue<T>::j + 1) % ArrayQueue<T>::a.length;
 ArrayQueue<T>::n--;
 if (ArrayQueue<T>::a.length >= 3*ArrayQueue<T>::n)
   ArrayQueue<T>::resize();
 return x;
}
*/
}
  #endif
