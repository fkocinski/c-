#include <iostream>


class Zespolona
{
    friend std::istream& operator >> (std::istream &L , Zespolona &arg);
    friend std::ostream& operator << (std::ostream &L , Zespolona const&arg);

    private:
    double urojona,rzeczywista;

    public:
    Zespolona(double r = 0, double i = 0)
    {
        rzeczywista = r;
        urojona = i;
    }

    
    Zespolona operator - (Zespolona const &arg)
    {
        Zespolona ret;
        ret.rzeczywista = rzeczywista - arg.rzeczywista;
        ret.urojona = urojona - arg.urojona;
        return ret;
    }

    Zespolona operator + (Zespolona const &arg)
    {
        Zespolona ret;
        ret.rzeczywista = rzeczywista + arg.rzeczywista;
        ret.urojona = urojona + arg.urojona;
        return ret;
    }

    Zespolona operator * (Zespolona const &arg)
    {
        Zespolona ret;
        ret.rzeczywista = rzeczywista*arg.rzeczywista - urojona*arg.urojona;
        ret.urojona = rzeczywista*arg.urojona + urojona*arg.rzeczywista;
        return ret;
    }

    Zespolona operator / (Zespolona const &arg)
    {
        if(arg.rzeczywista!=0 || arg.urojona!=0)
        {
            Zespolona ret;
            ret.rzeczywista = (rzeczywista*arg.rzeczywista + urojona*arg.urojona)/(arg.rzeczywista*arg.rzeczywista + arg.urojona*arg.urojona);
            ret.urojona = (urojona*arg.rzeczywista - rzeczywista*arg.urojona)/(arg.rzeczywista*arg.rzeczywista + arg.urojona*arg.urojona);
            return ret;
        }
        else
        {
            throw std::runtime_error("Error: Attempted to divide by Zero! \n");
        }
    }
};  
std::ostream& operator << (std::ostream & L, Zespolona const& arg)
{
        return L << arg.rzeczywista << " + " << arg.urojona<<"i"; 
}
std::istream& operator >> (std::istream & L, Zespolona &arg)
{
        std::cout<<"Rzeczywista: ";
        L >> arg.rzeczywista;
        std::cout<<"Urojona: ";
        L >> arg.urojona;
        return L;
}