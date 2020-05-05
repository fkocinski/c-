#include <iostream>
#include <math.h>
using namespace std;
void przyklada(int x)
{
    long double lpi=1/sqrt(3),lpiplus,licznik;
    for(int i =0;i<=x;i++)
    {
        licznik = sqrt((lpi*lpi)+1)-1;
        lpiplus = licznik/lpi;
        cout.precision(30);
        cout<<(6*pow(2,i))*lpi<<"  Dla i = "<<i<<"\n";
        cout<<"\tRoznica: "<<M_PI-((6*pow(2,i))*lpi)<<"\n\n\n";
        lpi=lpiplus;
    }
}
void przykladb(int x)
{
    long double lpi=1/sqrt(3),lpiplus,mianownik;
    for(int i =0;i<=x;i++)
    {
        mianownik = sqrt((lpi*lpi)+1)+1;
        lpiplus = lpi/mianownik;
        cout.precision(30);
        cout<<(6*pow(2,i))*lpi<<"  Dla i = "<<i<<"\n";
        cout<<"\tRoznica: "<<M_PI-((6*pow(2,i))*lpi)<<"\n\n\n";
        lpi=lpiplus;
    }
} 
int main()
{
    przyklada(30);
    cout<<"--------------------------------------------\n\n";
    przykladb(30);
    return 0;
}