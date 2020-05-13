#include <iostream>
#include "stos.h"

int main() {
    Stos stos;
    stos.push(2);
    stos.push(3);
    std::cout << stos.top() << " stos" << std::endl;
    Stos stos_kopia(stos); 
    std::cout << stos_kopia.top() << " stos kopia" << std::endl;
    stos_kopia.push(3);
    std::cout << stos_kopia.top() << " stos kopia" << std::endl;
    Stos stos_przypisanie = stos_kopia;
    std::cout << stos_przypisanie.top() << " stos przypis" << std::endl;
    stos_przypisanie.push(4);
    std::cout << stos_przypisanie.top() << " stos przypis" << std::endl;

    return 0;
}