 
#define RANDOM_H__
#include<ctime>
#include<assert.h>

class Random
{
   private:
      int fn;
   public:
      Random(int f1 = time(0));
      double operator()();           
   };

   inline Random::Random(int f1)
   :fn(f1)
   { 
      assert( ( 0 < f1 ) && ( f1 < 2147483647 ) ); 
   }
   inline double Random::operator()()
   {
      long long m = fn;
      m *= 16807;
      m %= 2147483647; 
      fn = static_cast<int>(m);
      return m / 2147483646.0; 
}
