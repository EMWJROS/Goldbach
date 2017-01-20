#include <set>

/**
 *  Class that represents the set of all prime numbers
 *
 *  Has one method to check if a number is a prime.
 *  The class keeps an internal tally of already checked
 *  primes to avoid wasting execution time.
 */
class SetOfPrimeNumbers
{
  private:
    static int maximum;
    static std::set<int> primes;
    static void checkAndGenerate(int newHigh);
    static bool isPrime(int a);
    SetOfPrimeNumbers() {};

  public:
    static bool isMember(int a);
};

