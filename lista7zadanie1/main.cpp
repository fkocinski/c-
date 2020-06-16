#include <iostream>
#include <string>
#include <sstream>

int charint(char x [])
{
    std::stringstream str(x);
    int zwroc;
    str >> zwroc;
    return zwroc;
}

int main()
{
    char x[]="18";
    std::cout << "typ char na int:  " << charint(x)<<"\n";
    char y[]="67x";
    std::cout << "typ char na int:  " << charint(y)<<"\n";

}
