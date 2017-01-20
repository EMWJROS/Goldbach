#include "SetOfPrimeNumbers.h"
#include <cmath>

// Initialize the set with the first (and most basic) prime
int SetOfPrimeNumbers::maximum = 1;
int one[] = {1};
std::set<int> SetOfPrimeNumbers::primes (one, one+1);

/**
 *  Checks if an integer is a member of the set of all prime numbers
 *
 *  @param a The integer to check
 *  @return True or false
 */
bool SetOfPrimeNumbers::isMember(int a)
{
  if (a >= maximum)
  {
    checkAndGenerate(a);
  }

  return (primes.find(a) != primes.end());
}

void SetOfPrimeNumbers::checkAndGenerate(int newHigh)
{
  if (newHigh > maximum)
  {
    for (int i=maximum+1; i<=newHigh; ++i)
      {
	if ( isPrime(i) )
	  {
	    primes.insert(i);
	  }
      }
    maximum = newHigh;
  }
}

/**
 *  Checks if a given integer is a prime using the Sieve of Eratosthenes
 *
 *  NB: The calculation is quite expensive and should only be done once
 *      per integer. Only for internal use.
 *
 *  @param a The integer to check
 *  @return True or false
 */
bool SetOfPrimeNumbers::isPrime(int a)
{
  // We only need to check up to the square root
  int limit = (int) sqrt(a);
  // Make sure that our internal data is fully stocked
  if (limit > maximum)
  {
    checkAndGenerate(limit);
  }
  
  // Check if any of the existing primes is a divisor
  std::set<int>::iterator it=primes.find(2);
  bool divisor = false;
  while ((*it)<=limit && it!=primes.end() && !divisor)
  {
    divisor = (a%(*(it++)) == 0);
  }

  return !divisor;
}

