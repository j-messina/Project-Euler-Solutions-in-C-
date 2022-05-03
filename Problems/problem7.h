#include <iostream>

bool p7_isPrime(long num)
{
    // edge case: argument is even
    if (num % 2 == 0)
    {
        return false;
    }
    
    for (long i = 3; i < num/3; i+=2)
    {
      if(num % i == 0) // if the input is evenly divisible by i
      {
        return false;
      }
    }
    return true;
}

void p7()
{
  int counter = 2;
  long i;
  for (i = 3; counter <= 10002; i+=2)
  {
    if(p7_isPrime(i))
    {
      std::cout<< "Found " << counter << "th Prime: " << i << std::endl; 
      counter++;
    }
  }
}