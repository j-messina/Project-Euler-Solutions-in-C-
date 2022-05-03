#include <iostream>
void p2();

int main()
{
    p2();

    return 0;
}

void p2()
{
    // Summing even Fibonacci sequence numbers under 4 million
    int older = 1,
        younger = 1,
        newest,
        sum = 0;
    
    // one cycle: adding older and younger and then updating all three
    // ex) older(1) + younger(1) --> newest = 2 --> older = younger, younger = newest
    for (int i = 0; newest < 4000000 ; i++)
    {
        newest = older + younger;
        older = younger;
        younger = newest;
        if(i % 3 == 0)
        {
            sum += newest;
        }
    }
    
    std::cout << "The sum is " << sum << std::endl;
}
