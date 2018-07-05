/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll power(ll base, ll exp, ll m){

	if(exp == 0)
		return 1;
	else if(exp == 1){
		return base % m;
	}

	ll temp = power(base, exp / 2, m);

	if(exp % 2 == 0)
		return (temp * temp) % m;
	else{
		return ( (base % m) * ( ( temp * temp ) % m ) ) % m;
	}

}

void disp(map<int, int> m, vi primes){
	cout << "--start--" << endl;
	for(int prime : primes){
		cout << prime << ":" << m[prime] << endl;
	}
	cout << "--end--" << endl << endl;
}

int main(){

	vi primes = vi();

	vi is_prime(101, 1);
	is_prime[0] = is_prime[1] = 0;
	for(int i = 2; i < 101; i++){
		if(!is_prime[i]){
			continue;
		}
		primes.push_back(i);
		for(int j = i * i; j < 101; j+=i)
			is_prime[j] = false;
	}

	int n;
	cin >> n;

	vi a = vi(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	vector<map<int, int> > factorization = vector<map<int, int> >(n, map<int, int>());
	for(int i = 0; i < n; i++){
		for(int prime : primes){
			int count = 0;
			while(a[i]%prime==0){
				count++;
				a[i]/=prime;
			}
			factorization[i][prime] = count;
		}
	}

	vector<map<int, int> > running_factors = vector<map<int, int>>(n, map<int, int>());
	running_factors[0] = factorization[0];
	for(int i = 1; i < n; i++){
		for(int prime : primes){
			running_factors[i][prime] = factorization[i][prime] + running_factors[i-1][prime];
		}
	}

	int t, l, r, m;

	cin >> t;
	while(t--){
		cin >> l >> r >> m;
		l--;
		r--;

		vector<pair<int, int> > prime_freq = vector<pair<int, int> >();
		if(l==0){
			for(int prime : primes){
				prime_freq.push_back(make_pair(prime, running_factors[r][prime]));
			}
		}else{
			for(int prime : primes){
				prime_freq.push_back(make_pair(prime, running_factors[r][prime]-running_factors[l-1][prime]));
			}
		}

		ll ans = 1 % m;
		for(pair<int, int> &x : prime_freq){
			ans = ( ans * power(x.first, x.second, m) ) % m;
		}
		cout << ans << endl;
	}

	return 0;
}