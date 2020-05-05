#include<iostream>

class Samochod
{
public:
    Samochod (int n)
    : _kola(n), _sruby(4*n)
    {
        std::cout << "Samochod z " << _kola << " kolami i "<<_sruby << " srubami\n";
    }
private:
    int _sruby;
    int _kola;
};
//w argumentach sruby dajemy zamiast kola*4 -- 4*n.
//sekcje pirvate dajemy na poczatek programu i zamioeniamy miejscami sruby z kolami 
int main()
{
    Samochod s4 (4);
    Samochod s12 (12);
}