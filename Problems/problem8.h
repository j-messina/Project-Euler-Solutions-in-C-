// Problem 8: Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?

#include <iostream>
#include <fstream>
#include <string>

const int LENGTH = 1000;

void p8_brute(std::ifstream infile)
{
  // Read in file
  int num [LENGTH];
  num[0] = infile.get();
  for(int i = 1; i < LENGTH; i++)
  {
    if(i%50 != 0)
    {
      num[i] = infile.get();
    }
  }
  
  for(int i = 0; i < LENGTH; i++)
  {
    std:cout << num[i];
  }
  // Checking direction: Horizontal
  // Checking direction: Vertical
  // Checking direction: Diagonal / 
  // Checking direction: Diagonal \ 
}

void p8()
{
  ifstream infile ("p8_num.txt");
  if (infile.is_open())
  {
    p8_brute(infile);
    infile.close();
  }
  else
  {
    std::cout << "Problem 8: Unable to open file\n";
  }

}

/*
Plan:
Option 1:
 - Check each direction (horizontal, vertical, diagonal / , diagonal \) procedurally, tracking the largest value found.
*/