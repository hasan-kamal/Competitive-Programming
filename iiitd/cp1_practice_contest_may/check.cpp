#include <iostream>
using namespace std;

#define PRIME 1000000007        // Or any prime
 
// Returns (x^n) % PRIME
long long int binary_exp(long long int x, long long int n)
{
    long long int ans;
    if (n == 0) {
        ans = 1;
    } else if (n == 1) {
        ans = x % PRIME;
    } else {
        long long int temp = binary_exp(x, n / 2);
        temp = (temp * temp) % PRIME;
         
        if (n % 2 == 0) {
            ans = temp;
        } else {
            ans = ((x % PRIME) * temp) % PRIME;
        }
    }

    cout<<x<<"^"<<n<<"="<<ans<<endl;
    return ans;
}

int main(){

    cout<<binary_exp(4, PRIME-2)<<endl;
    long long int alpha = 268435456;
    cout<<alpha*alpha<<endl;

    return 0;
}