#include <iostream>
#include "stos.h"

int main() {
    Stos stos;
    stos.push(1);
    stos.push(2);
    stos.push(3);
    std::cout << stos << std::endl;
    stos.reverse();
    std::cout << stos << std::endl;

    return 0;
}