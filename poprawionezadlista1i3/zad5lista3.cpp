
#include <iostream>
#include <math.h>
#include <vector>
#include <cstdio>
#include <ctime>
//rekurencyjna wersja
int fibo1(int n)
{
    if (n<=2)
        return 1;
    return fibo1(n-1) + fibo1(n-2);            
}
//z podanego wzoru
int fibo2(int n)
{
    return (1/sqrt(5))*( pow(2/(sqrt(5)-1),n) - pow(-2/(sqrt(5)+1),n) )+1;
}
//definiowanie wektora statycznego
const int rozmiar = 47;
static std::vector<int> statyczny(rozmiar);

int fibo3(int n)
{
    if(n<=2)
        return 1;
    if(statyczny[n]==0)
        statyczny[n] = fibo3(n-1)+fibo3(n-2);
    return statyczny[n];
}

int main()
{
    std::clock_t start;
    double duration1,duration2,duration3;

    start = std::clock();

    std::cout<<"\nFibo1\n";
    for (int n = 1; n<47;n++)
    {
       std::cout<<fibo1(n)<<"\n"; 
    }

    duration1 = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    


    start = std::clock();

    std::cout<<"\nFibo2\n";
    for (int n = 1; n<47;n++)
    {
       std::cout<<fibo2(n)<<"\n"; 
    }

    duration2 = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;



    start = std::clock();

    std::cout<<"\nFibo3\n";
    for (int n = 1; n<47;n++)
    {
       std::cout<<fibo3(n)<<"\n"; 
    }

    duration3 = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"time fibo1: "<< duration1 <<'\n';
    std::cout<<"time fibo2: "<< duration2 <<'\n';
    std::cout<<"time fibo3: "<< duration3 <<'\n';
    
}

