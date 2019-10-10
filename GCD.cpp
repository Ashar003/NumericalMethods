#include <iostream>

#include <math.h> 
using namespace std;

long gcd_euclid(long a, long b)
{
    if(a <= 0 || b <= 0) {return 0;}; //Obviously if a = b = 0 then gcd = 0
        if (a < b) {
        return gcd_euclid(b,a);

}
if( a == 0){ return b;};
if( b == 0) { return a;};
long c = (a%b);
if (c == 0)
    return b;
else if (c == 1)
    return 1;

return gcd_euclid(b,c);
}//1.1

long LCM(long a, long b){
  //  LCM(a, b) × GCD(a, b) = ab . so GCD(a, b)/ ab = 1/LCM(a,b)
  if(a <= 0 || b <= 0) {return 0;}; //Obviously if a = b = 0 then gcd = 0
  double GC = gcd_euclid(a,b);
  return (1/(GC / (a*b)));
}//1.1