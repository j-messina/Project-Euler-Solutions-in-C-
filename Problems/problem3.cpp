#include <iostream>

// Problem 3: Find the largest prime factor of the number 600851475143
void largestPrimeFactorOfOdd(long input);
bool isPrime(long num);

int main()
{
    long p3_input = 600851475143;
    largestPrimeFactorOfOdd(p3_input);
    return 0;
}

void largestPrimeFactorOfOdd(long input)
{
    // Find largest prime factor of 600851475143
        // make/use isPrime() for checking
        /* 
        to find largest prime factor, we should work backwards from an upper limit
        in this case, the largest potential factor would be what is left after dividing by three
         - if it is prime --> then yay, we are done
         - if not, then we will work our way down, dividing by greater odd numbers until it is found
          (i.e: 3, 5, 7, ... )
        */
        
    long lpf,        // lpf        = largest prime factor
        potentialF; // potentialF = potential factor
    for (long i = 3; i <= input/3; i+=2)
    {
        if (input % i == 0) // if a valid factor
        {
            potentialF = input/i;
        }
        else
        {
            continue;
        }
        //--------------------
        // below only runs if the above if was true
        //--------------------
        
        std::cout << "Trying " << potentialF << "..." << std::endl;
        
        if (isPrime(potentialF))
        {
            lpf = potentialF;
            break; // end for loop, as we have found our lpf
        }
    }
    
    std::cout << "The largest prime factor of " << input << std::endl << "is " << lpf << std::endl;
}

bool isPrime(long num)
{
    // edge case: argument is even
    if (num % 2 == 0)
    {
        return false;
    }
    
    for (long i = 3; i < num/3; i+=2)
    {
      std::cout<<num<<" is divisible by " << i << "? --> ";
      if(num % i == 0) // if the input is evenly divisible by i
      {
        std::cout << "Yes!\n";
        return false;
      }
      else
      {
        std::cout << "No...\n";
      }
    }
    
    // otherwise, return true
    return true;
}
