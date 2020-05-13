#include <iostream>
#include "stos.h"

int main() {
    Stos stos;
    stos.push(3);
    stos.push(4);

    Stos stos_kopia(stos);
    stos_kopia.push(6);

    Stos stos_przypisanie = stos_kopia;
    stos_przypisanie.push(7);

    std::cout << stos << std::endl;
    std::cout << stos_kopia << std::endl;
    std::cout << stos_przypisanie << std::endl;

    return 0;
}