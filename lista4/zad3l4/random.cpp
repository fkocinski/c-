#include <iostream>
#include "random.h"


int main()
{
    Random rnd;
    for(int i = 0; i < 10; i++)
       std::cout << rnd() << "\n";
}