 
#include <cstdlib>     

class Wektor
{
private:
    size_t rozmiar;
    int *  tab;
public:
    Wektor(size_t n);                
    Wektor()
    {
        delete [] tab; 
    }
      
    size_t size() const              
    { 
        return rozmiar; 
    }
    int &  operator [](int n)        
    {
         return tab[n]; 
    }
    int    operator [](int n) const
    { 
        return tab[n]; 
    }
    
    void   operator= (Wektor const& wek);  
};

inline Wektor::Wektor(size_t n)
: rozmiar(n), tab(new int[n])
{ }