#ifndef PQSEARCH_H
#define PQSEARCH_H

#include "ArrayQueue.h"
#include <algorithm>


namespace ods{
  template<class T>
  class PQSearch : public ArrayQueue<T>
  {
  public:
    void display();
    virtual int searching();
    //void removeMin();
    void moveFront();
  protected:
    T minNumber;
    int minIndex;
  };

   template<class T>
   int PQSearch<T>::searching()
   {
     minNumber=this->a[this->j];
     minIndex=this->j;
     for(int index=this->j; index<this->n+this->j; index++)
       {
         if(this->a[index]<minNumber)
         {
           minNumber=this->a[index];
           minIndex=index;
         }
       }
       return minIndex;
   }


   template<class T>
   void PQSearch<T>::moveFront()
   {
     minNumber=searching();
     if(minNumber!=this->j)
     {
       T temp=this->a[this->j];
       this->a[this->j]=this->a[minNumber];
       this->a[minNumber]=temp;
     }
   }
/*
//divide into half and shift left or right
template<class T>
   void PQSearch<T>::removeMin()
   {
     int index=searching();
     if(index<(this->n/2))
     {
     for(int Nindex=index; Nindex>0; Nindex--)
     {
       this->a[(Nindex+this->j)%this->a.length]
       =this->a[(Nindex+this->j-1)%this->a.length];
     }
       this->j=(this->j+1)%this->a.length;

     }
     else
     {
       for(int Nindex=index; Nindex<this->n-1; Nindex++)
       {
         ArrayQueue<T>::a[(this->j+Nindex)%this->a.length]=
         ArrayQueue<T>::a[(this->j+Nindex+1)%this->a.length];
       }
     }
       this->n--;
       if (this->a.length >= 3*this->n)
         this->resize();
   }
*/
/*
//shift to the right using std::copy
template<class T>
void PQSearch<T>::removeMin()
{
  int index=searching();
  std::copy(this->a+index+1,this->a+this->n, this->a+index);
  this->n--;
  if (this->a.length >= 3*this->n)
    this->resize();
}
*/

/*
template<class T>
   void PQSearch<T>::removeMin()
   {
     int index=searching();
     if(index<(this->n/2))
     {
       std::copy(this->a+this->j,this->a+index, this->a+this->j+1);
       this->j=(this->j+1)%this->a.length;
     }


     else
     {
       std::copy(this->a+index+1,this->a+this->n, this->a+index);
     }
       this->n--;
       if (this->a.length >= 3*this->n)
         this->resize();
 }
*/
   template<class T>
   void PQSearch<T>::display(){
     /*int n=ArrayQueue<T>::n;
     int k=ArrayQueue<T>::j;
     do
     {
       std::cout<<ArrayQueue<T>::a[k]<<" ";
       k++;
       n--;
     }
     while(n!=0);
     */
     for (int k=ArrayQueue<T>::j; k<ArrayQueue<T>::n+ArrayQueue<T>::j; k++)
     {
      std::cout<<ArrayQueue<T>::a[k]<<" ";

   }
 }

}
#endif
