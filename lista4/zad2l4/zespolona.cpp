 
#include <iostream>
#include "liczbazespolona.h"

int main()
{

    Zespolona liczba1 = {1,2};
    Zespolona liczba2 = {4,5};
    Zespolona liczba3;
    std::cout <<liczba1-liczba2<<"-----\n\n";
    std::cout <<liczba1+liczba2<<"-----\n\n";
    std::cout <<liczba1*liczba2<<"-----\n\n";
    std::cout <<liczba1/liczba2<<"-----\n\n";
    std::cin>>liczba3;
    std::cout <<liczba3<<"\n";
}