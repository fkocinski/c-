#include <iostream>
#include <cmath>
#include <vector>

static std::vector<int> fibonacci = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};


int fibo1(int n) {

    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibo1(n - 1) + fibo1(n - 2);
}

double fibo2(int n) {

    return ((1 / sqrt(5)) * (pow((2 / (sqrt(5) - 1)), n) - pow((-2 / (sqrt(5) + 1)), n)));
}

int fibo3(int n) {

    return fibonacci[n];
}


int main() {
    for (int i = 1; i <= 48; i++) {
        std::cout << fibo1(i) << '\t';
        std::cout << fibo2(i) << '\t';
        std::cout << fibo3(i) << std::endl;
    }
    return 0;
}
