#include <iostream>
void bruteForceIt();

int main()
{
    bruteForceIt();

    return 0;
}

void bruteForceIt()
{
    int sum = 0;
    // sum all multiples of 3 or 5 under 1000
    for (int counter = 1; counter < 1000; counter++)
    {
         if (counter % 3 == 0 || counter % 5 == 0)
         {
             sum += counter;
         }
    }
    
    std::cout<<"The sum is " << sum << std::endl;
}
