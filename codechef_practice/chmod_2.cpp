/*

@author Hasan Kamal

*/

#include <iostream>
using namespace std;

#define N 100000
#define NUM_PRIMES 25

typedef long long int ll;

struct node{
	int val;
	int count[NUM_PRIMES];
};

node a[N];
int primes[NUM_PRIMES] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

// ll power(ll base, ll exp, ll m, ll base_m){

// 	if(exp == 0)
// 		return 1;
// 	else if(exp == 1){
// 		return base_m;
// 	}

// 	ll temp = power(base, exp / 2, m, base_m);

// 	if(exp % 2 == 0)
// 		return (temp * temp) % m;
// 	else{
// 		return ( (base_m) * ( ( temp * temp ) % m ) ) % m;
// 	}

// }

ll power(ll base, ll exp, ll m) { // faster exponentiation, non-recursive
    
    ll res=1;
    while(exp > 0) {
       
       if(exp % 2 == 1)
       		res = ( res * base ) % m;
       
       base = ( base * base ) % m;
       exp /= 2;

    }

    return res;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> a[i].val;

		for(int x = 0; x < NUM_PRIMES; x++){
			a[i].count[x] = 0;
			while(a[i].val % primes[x] == 0){
				a[i].count[x]++;
				a[i].val /= primes[x];
			}

			if(i > 0)
				a[i].count[x] += a[i-1].count[x];
		}

	}

	int t, l, r, m;
	cin >> t;

	int prime_count[NUM_PRIMES];
	while(t--){

		cin >> l >> r >> m;
		l--;
		r--;

		if(l == 0){

			for(int i = 0; i < NUM_PRIMES; i++)
				prime_count[i] = a[r].count[i];

		}else{
			
			for(int i = 0; i < NUM_PRIMES; i++)
				prime_count[i] = a[r].count[i] - a[l-1].count[i];

		}

		ll ans = 1 % m;
		for(int i = 0; i < NUM_PRIMES; i++){
			ans = ( ans * power(primes[i], prime_count[i], m) ) % m;
		}
		cout << ans << endl;

	}

	return 0;
}