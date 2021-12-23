#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef set<int> si;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	vi primes;
	for(int i = 2	; i <= 100; i++){
		bool prime = true;
		for(int j = 2; j * j <= i; j++){
			if(i % j == 0){
				prime = false;
				break;
			}
		}
		if(prime)
			primes.push_back(i);
	}

	map<int, int> p_count;
	for(int i = 0; i < n; i++){
		int val = a[i];
		while(val > 1){
			for(int p : primes){
				int count  = 0;
				while(val % p == 0){
					count++;
					val /= p;
				}
				if(p_count.find(p) == p_count.end())
					p_count[p] = count;
				else
					p_count[p] += count;
			}
		}
	}

	vi c;
	for(int p : primes){
		if(p_count.find(p) == p_count.end())
			continue;
		for(int i = 0; i < p_count[p]; i++)
			c.push_back(p);
	}


	vi a_f(n, 1);
	int num_p = c.size();
	for(int i = 0; i < num_p; i++){
		a_f[i % n] *= c[i];
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		// cout << a_f[i] << " ";
		ans += a_f[i];
	}

	// cout << endl;	

	cout << ans;

	// bool stop = false;
	// while(!stop){
	// 	bool changed = false;
	// 	int smallest = *a.begin();
	// 	for(si::iterator it = a.rbegin(); it != a.end(); it++){
	// 		// try *it with smallest
	// 		int 
	// 		for(si::iterator div = divisors[*it].begin(); div != divisors[*it].end(); div++){
	// 			int val = *it;
	// 			int divs = *div;
	// 		}
	// 	}

	// 	if(!changed){
	// 		stop = true;
	// 	}
	// }

	// int sum = 0;
	// for(si::iterator it = a.rbegin(); it != a.end(); it++){
	// 	sum += *it;
	// }
	// cout << sum;

	return 0;
}