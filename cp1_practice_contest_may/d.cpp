/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <climits>
#define N 1000005
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;

vb is_prime = vb(N, true);
void sieve_preprocess(int n){
	is_prime[1] = false;
	for(int i=2; i*i<=n; i++){
		if(is_prime[i]){
			for(int j=i*i; j<=n; j+=i)
				is_prime[j] = false;
		}
	}
}

int main(){


	int a, b, k;
	cin>>a>>b>>k;

	sieve_preprocess(b);
	vi primes_in_range = vi();
	int num_primes_in_range = 0;
	for(int i=a; i<=b; i++){
		if(is_prime[i]){
			primes_in_range.push_back(i);
			num_primes_in_range++;
		}
	}

	if(k>num_primes_in_range){
		cout<<"-1";
		return 0;
	}

	int i1 = a;
	int i2 = primes_in_range[k-1];
	int max_window = INT_MIN;
	int num_primes_in_window = k;
	while(i2<b){
		if(i2-i1+1>max_window)
			max_window = i2-i1+1;
		i2++;
		i1++;
		if(is_prime[i2])
			num_primes_in_window++;
		if(is_prime[i1-1])
			num_primes_in_window--;

		if(num_primes_in_window<k){
			i1--;
			num_primes_in_window++;
		}
	}
	if(i2-i1+1>max_window)
		max_window = i2-i1+1;
	cout<<max_window;

	return 0;
}