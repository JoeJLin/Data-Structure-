#include "SLList.h"
#include <iostream>

using namespace std;
using namespace ods;

int main()
{
  SLList<int> list;
  for(int i=0; i<5; i++)
  {
    cout<<list.add(i)<<" ";
  }
  cout<<endl;

  list.reverse();

  for(int i=0; i<5; i++)
  {
    cout<<list.remove()<<" ";
  }
}
