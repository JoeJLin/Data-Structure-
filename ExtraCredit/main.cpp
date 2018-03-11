#include <iostream>
#include <math.h>
#include <chrono>
#include <random>

using namespace std;

int hashCode(int);

int main()
{
  //random number generator from std
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  std::uniform_int_distribution<int> distribution;
  //generate random positive ints with no range

  cout<<"Part 1: 1-256 in hash: "<<endl;
  int arr[256] ={};//initailize the array to 0
  for(int i = 1; i<=256; i++)
  {
    int y;
    y=hashCode(i);//use the hash function to convert the number into hash value
    arr[y]++;//use the array indexes as hash value, if the hash value appear,
            //increment by 1
  }

  for(int i = 0; i < 256; i++)
  {
    cout<<i+1<<": "<<arr[i]<<endl;//print out the array
  }

  cout<<"\n"<<" Part II, 4096 random numbers"<<"\n"<<endl;

  int array[256] ={};
  for(int i = 0; i < 4096; i++)
  {
    int y;
    y = hashCode(distribution(generator));//put random number into hash function
    array[y]++;
  }

  for(int i = 0; i < 256; i++)
  {
    cout<<i+1<<": "<<array[i]<<endl;
  }

  int min = array[0];
  int max = array[0];
  for(int i = 0; i< 256; i++)
  {
    if(array[i] < min)
    min = array[i];//compare throught the array to check for the min value
    if(array[i] > max)
    max = array[i];//check for the max value
  }
  cout<<"\n";
  cout<<"The min is: "<<min<<endl;
  cout<<"The max is:"<<max<<endl;

}

//hash function
int hashCode(int x) {
  long int z = 4102541685;
  int w = 32;
  int d = 8;
  return ((unsigned)(z * x) >> (w-d));
}
