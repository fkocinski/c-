#include <iostream>

using namespace std;

class Dwa
{
public:
  Dwa()
  {
  cout << "Kolejnosc ";
  }
  ~Dwa()
  {
  cout << "logiczna \n";
  }
};
class Trzy
{
public:
  Trzy()
  {
    cout << "i ";
  }
  ~Trzy()
  {
    cout << "obiektow ";
  }
};
class Cztery
{
 public:
  Cztery()
  {
    cout << "konstrukcji ";
  }
  ~Cztery()
  {
    cout << "jest ";
  }
};

class Raz:public Dwa
{
public:
    Raz()
    {
        Trzy trzy;
        cout << "destrukcji ";
    }
private:
    Cztery cztery;

};
int main()
{
  Raz raz;
  return 0;
}