#include<iostream>
#include "LispList.h"
#include <functional>
#include <string>
using namespace std;

int stringSize(string, int);//the function return the size of the string
string subString(string, int);//the substring function

int main()
{
  function<int(string, int)> stringg = stringSize;
  function<string(string, int)> substrr = subString;
  int num2 =0;
  int num1=4;

  LispList<string> string1;
  // string1.add("dog");
  // string1.add("cat");
  // string1.add("elephant");
  // string1.add("zebra");
  int times;
  string str1;
  cout<<"Enter the number of string you want to enter"<<endl;
  cin>>times;
  for(int i=0; i<times; i++)
  {
  cout<<"Enter a string"<<endl;
  cin>>str1;
  string1.add(str1);
  }

  cout<<"Here is a list of strings"<<endl;
  string1.print();
  cout<<endl;

  LispList<string> string2;
  // string2.add("Brooklyn");
  // string2.add("Queens");
  // string2.add("Manhattan");
  int times2;
  string str2;
  cout<<"Enter the number of string you want to enter"<<endl;
  cin>>times2;
  for(int i=0; i<times2; i++)
  {
  cout<<"Enter a string"<<endl;
  cin>>str2;
  string2.add(str2);
  }

  cout<<"Here is another list of strings"<<endl;
  string2.print();
  cout<<endl;

  LispList<string> string3;
  LispList<string> string4;
  LispList<int> ListInt4;

  string3= string1.append(string1, string2);

  string4=(string1.map(substrr, string1, num1));

  ListInt4=(string1.map(stringg, string3, num2));

  cout<<"After sub string, here are the strings "<<endl;
  string4.print();
  cout<<endl;

  cout<<"After append, here are the size of each string"<<endl;
  ListInt4.print();
  cout<<endl;

}


int stringSize(string str, int num)//takes string and int, return int
{
  return str.string::size();
}

string subString(string str, int num)//takes string and int, return int
{
  return str.substr(0, num);
}
