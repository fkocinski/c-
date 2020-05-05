#include "wektor.h"                 

void Wektor::operator= (Wektor const& vecto)
{
    if (this == &vecto)                
        return;
       
    delete [] tab;                 

    rozmiar = vecto._rozmiar;        
    tab = new int [rozmiar];      
    
    for (size_t i = 0; i < rozmiar; i++)  
        {
            tab[i] = 0; 
        }
}