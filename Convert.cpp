#include <iostream>
#include <vector>
#include <math.h> 
using namespace std;

int dec_to_base(int a, int base, std::vector<char> & digits)
{

    char alphanum[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

digits.clear();
if ((base < 2) || (base > 16)) return 1; // fail
if (a < 0) return 1; // fail
if (a == 0) {
    digits.push_back(alphanum[0]);
    return 0;
}
while (a > 0) {
    int rem = a % base;
    char c = alphanum[rem];
    digits.push_back(c);
    a /= base;
}
std::reverse(digits.begin(), digits.end()); // reverse the digits

for (int i = 0; i < (int) digits.size(); ++i) {
    std::cout << digits[i];
}
    std::cout << std::endl;

return 0;
}

vector<char> digits;

int main(){
cout<<dec_to_base(106, 16, digits)<<" because of return\n";
cout<<dec_to_base(106, 2, digits)<<" because of return\n";


}