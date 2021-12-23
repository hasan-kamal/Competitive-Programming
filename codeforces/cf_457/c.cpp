/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <set>
#define pb push_back
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
#define N ((ll)1e6)
#define VAL ((ll)1e9)

vll is_prime;

void sieve(){
	is_prime = vll(N, 1);
	is_prime[0] = is_prime[1] = 0;
	for(ll i = 2; i < N; i++){
		if(is_prime[i]){
			for(ll j = i * i; j < N; j += i)
				is_prime[j] = 0;
		}
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m;
	cin >> n >> m;

	if(n == 2){
		cout << 2 << " " << 2 << endl;
		cout << 1 << " " << 2 << " " << 2 << endl;
		return 0;
	}

	sieve();

	ll lprime;
	for(ll i = 1e5; i < N; i++){
		if(is_prime[i]){
			lprime = i;
			break;
		}
	}
	// cout << lprime << endl;

	cout << 2 << " " << lprime << endl;

	cout << 1 << " " << n << " " << 2 << endl;
	for(int i = 2; i <= n - 2; i++){
		cout << 1 << " " << i << " " << 1 << endl;
	}

	cout << 1 << " " << n - 1 << " " << lprime + 1 - n << endl;

	m -= (n - 1);
	for(int i = 2; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(m <= 0){
				break;
			}

			cout << i << " " << j << " " << VAL << endl;
			m--;
		}
		if(m <= 0)
			break;
	}

	return 0;
}