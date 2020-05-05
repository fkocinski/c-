#include <iostream>
#include "wektor.h"

int main()
{
    Wektor w(5);
    
    std::cout << w.size() << "\n";
    for(int i =0; i<w.size();i++)
    {
        std::cout << w[i] << std::endl;
    }
    
}