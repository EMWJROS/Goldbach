#include <ostream>
#include <iostream>
#include <cmath>
#include <set>
#include "SetOfPrimeNumbers.h"

#define MAX_NUM 10000

using namespace std;

bool isOdd(int x)
{
  return x & 1;
}

bool isGoldbachNumber(int x)
{
    int maxSquare = (int) sqrt(x/2.0);
    bool goldbachNumber = false;
    // Test possible squares
    int s = 1;
    while ((s <= maxSquare) && !goldbachNumber)
    {
      // Check if the remainder is a prime
      // If it is, we have found a Goldbach number
      goldbachNumber = SetOfPrimeNumbers::isMember(x - 2*s*s);
       // Check next square
      ++s;
    }
    return goldbachNumber;
}

int main()
{
  int i = 1;
  bool found = false;
  while ((i < MAX_NUM) && !found)
  {
    // Check odd composite number
    if ( isOdd(i) && !SetOfPrimeNumbers::isMember(i) )
    {
      // We have found it if it isn't a Goldbach number
      found = !isGoldbachNumber(i);
    }
    ++i;
  }
  if (i != MAX_NUM)
  {
    cout << "The smallest odd composite number that isn't a Goldbach"
            " number is " << i - 1 << endl;
  }
  else
  {
    cout << "No odd composite number that isn't a Goldbach number "
            "was found below " << MAX_NUM << endl;
  }

  return 0;
}

