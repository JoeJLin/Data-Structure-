#include "ArrayDeque.h"
//#include "SmartArrayDeque.h"
#include <iostream>
#include "utils.h"
#include <chrono>

using namespace ods;
using namespace std;
int main()
{
ArrayDeque <int> a;
auto start = chrono::steady_clock::now();

for(int i=0; i<10; i++)
{
a.add(i,i);
cout<<"position"<<a.get(i)<<endl;
}
cout<<"array size" <<a.size()<<endl;
a.add(0,12);
a.add(1,20);
a.add(2,21);
for(int i=0; i<15; i++)
{
  cout<<"position"<<a.get(i)<<endl;
}

cout<<"array size" <<a.size()<<endl;
/*
for(int i=5000; i>2500; i--)
{
a.remove(i);
}
cout<<"array size" <<a.size()<<endl;

for(int i=2500; i<7500; i++){

a.add(i,i);
}
cout<<"array size" <<a.size()<<endl;

for(int i=0; i<7500; i++)
{
a.remove(i);
}
*/
auto end = chrono::steady_clock::now();
  auto diff = end - start;
  cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
return 0;
}
