#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;

ll gcd(ll a, ll b){
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;

	ll a, b;
	ll one_val;
	cin >> a >> b;
	one_val = a;
	ll g = a * b;
	n--;

	while(n--){
		cin >> a >> b;
		g = gcd(g, a * b);
	}

	if(g == 1){
		cout << -1;
		return 0;
	}

	// cout << g << endl;

	// pf g
	vi sieve(45001, 1);
	
	sieve[0] = sieve[1] = 0;
	for(int i = 2; i < 45000; i++){
		if(sieve[i] == 0)
			continue;
		for(int j = 2 * i; j < 45000; j += i){
			sieve[j] = 0;
		}
	}

	for(int i = 0; i < 45000; i++){
		if(sieve[i]){
			if(g % i == 0){
				cout << i;
				return 0;
			}
		}
	}

	if(g <= 2000000000)
		cout << g;
	else{
		// g = p1 * p2 where both p1, p2 are primes greater than root(2 * 10^9) and less than (2 * 10^9)
		// output either p1 or p2

		for(int i = 0; i < 45000; i++){
			if(sieve[i]){
				while(one_val % i == 0){
					one_val /= i;
				}
			}
		}

		cout << one_val;
	}


	return 0;
}