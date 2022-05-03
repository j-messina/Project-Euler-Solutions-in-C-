#include <iostream>
#include <string>

// Problem 4: Find the largest palindromic number that is the product of two three digit numbers

/* Contents:
bool isPalindrome(~)
void largest_3Dig_Palindrome()
void largest_2Dig_Palindrome()
void p4()
*/

bool isPalindrome (int num)
{
  std::string num_as_str = std::to_string(num);
  int length = num_as_str.length();
  std::string flipped = "";

  for (int i = length-1; i >= 0; i--)
  {
    flipped+=num_as_str[i];
  }

  if(num_as_str.compare(flipped) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

/*
Plan:
1) Proof of concept: Make a function for finding the largest palindrome product of two 2-digit numbers, since it's given: 9009

I see multiple routes:
Option 1: Brute force it, going through each product starting from 99 x 99, as if running throught a giant times-table, and checking to see if the product is palindromic

Big O = n logn --BUT-- since we know that the answer is 99 x 91, itc it's actually going to iterate only 9 times EXCEPT we still need to check until there is no possibility of encountering a larger number, which means more than 9 checks
--> in short, we'd be making a slightly "smarter" brute force approach


Option 2 (maybe faster): Start from the upper limit of the largest product of two 2-digit numbers, and, going down by one...
  - Check if the number is composite
  - If yes, check if it is divisible by a number between 99 and 10
  - If yes again, check if that factor's partner is also between 99 and 10

Big O = ?

2) Implement for two 3-digit numbers...
*/

void largest_3Dig_Palindrome()
{
    /*
    Option 1: Brute Force
    _____________________
    -- Essentially copy pasted from the 2-digit version
    */
    int largestPalindrome = 0,
      factor1 = 0,
      factor2 = 0;

  for (int i = 999; i >= 100 && i*i > largestPalindrome; i--)
  {
    for (int j = 999; j >= 100 && i*j > largestPalindrome; j--)
    {
      if (isPalindrome(i*j))
      {
        largestPalindrome = i*j;
        factor1 = i;
        factor2 = j;
      }
    }
  }

  std::cout << "The largest palindrome of two 3-digit numbers is " << factor1 << " x " << factor2
            << " = " << largestPalindrome << std::endl;
}

// Proof of concept: working with two 2-digit numbers
// Status: Working
void largest_2Dig_Palindrome()
{
  // Option 1: Brute Force
    // using a nested loop, I will just check products to be a palindrome
    // This is the skeleton of the brute force approach:
  /*  
  for (int i = 99; i >= 10; i--)
  {
    for (int j = 99; j >= 10; j--)
    {
      if (isPalindrome(i*j))
      {
        // finished
      }
    }
  }
  */
  // however we are now going to keep track of some extra values:
  // the highest known palindrome; the potential of the current row (i) for a larger palindrome

  int largestPalindrome = 0,
      factor1 = 0,
      factor2 = 0;

  for (int i = 99; i >= 10 && i*i > largestPalindrome; i--)
  {
    for (int j = 99; j >= 10 && i*j > largestPalindrome; j--)
    {
      if (isPalindrome(i*j))
      {
        largestPalindrome = i*j;
        factor1 = i;
        factor2 = j;
      }
    }
  }

  std::cout << "The largest palindrome of two 2-digit numbers is " << factor1 << " x " << factor2
            << " = " << largestPalindrome << std::endl;
}

void p4()
{
  //largest_2Dig_Palindrome();
  largest_3Dig_Palindrome();
}