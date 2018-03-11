#include "Shopper.h"
#include <random>
#include<iostream>

using namespace std;

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1,10);

Shopper::Shopper()
{
  loyalty=distribution(generator);
  cartSize=distribution(generator);
  priority=0;
}

Shopper::Shopper(int x)
{

  loyalty=distribution(generator);
  cartSize=distribution(generator);
  priority=x;
}

bool operator<(const Shopper& left, const Shopper& right)
{
  if(left.priority<right.priority)
  return true;
  else
  return false;
}

bool operator>(const Shopper& left, const Shopper& right)
{
  if(left.priority>right.priority)
  return true;
  else
  return false;
}
