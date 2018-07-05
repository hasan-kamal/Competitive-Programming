/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

typedef vector<int> vi;
vi is_prime;
vi first_prime_factor;

int maximum(int a, int b){
	return a > b ? a : b;
}

void preprocess_sieve(int m){
	is_prime[0] = is_prime[1] = 0;
	first_prime_factor[1] = 1;
	for(int i = 2; i * i <= m; i++){
		if(!is_prime[i])
			continue;
		for(int j = i * i; j <= m; j += i){
			is_prime[j] = 0;
			if(first_prime_factor[j] == -1)
				first_prime_factor[j] = i;
		}
	}

	for(int i = 2; i <= m; i++){
		if(is_prime[i])
			first_prime_factor[i] = i;
	}
}

void get_distinct_prime_factors(int value, vi& factors){

	// cout << "prime factors of " << value << " are ";

	int last_factor = first_prime_factor[value];
	factors.pb(last_factor);
	value /= last_factor;

	while(value > 1){
		if(first_prime_factor[value] > last_factor){
			factors.pb(first_prime_factor[value]);
			last_factor = first_prime_factor[value];
		}

		value /= first_prime_factor[value];
	}

	// for(int factor : factors)
	// 	cout << factor << " ";
	// cout << endl;

}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	const int m = 1e7 + 1;
	is_prime = vi(m, 1);
	first_prime_factor = vi(m, -1);
	preprocess_sieve(m);

	int t;
	cin >> t;

	int n;
	while(t--){
		cin >> n;

		vi a = vi(n + 1);
		for(int i = 1; i <= n; i++)
			cin >> a[i];

		vi latest_prime_seen = vi(m, -1);
		vi ans = vi(n + 1);
		vi factors;

		for(int i = n; i >= 1; i--){

			if(a[i] == 1){
				ans[i] = 1;
				continue;
			}

			factors = vi();
			get_distinct_prime_factors(a[i], factors);
			int cur_ans = 1;
			for(int factor : factors){
				if(latest_prime_seen[factor] >= 0)
					cur_ans = maximum(cur_ans, ans[latest_prime_seen[factor]] + 1);
				latest_prime_seen[factor] = i;
			}
			ans[i] = cur_ans;

		}

		// //show a
		// for(int i = 1; i <= n; i++)
		// 	cout << a[i] << " ";
		// cout << endl;

		// //show ans
		// for(int i = 1; i <= n; i++)
		// 	cout << ans[i] << " ";
		// cout << endl;

		int max = ans[1];
		for(int i = 2; i <= n; i++){
			if(ans[i] > max)
				max = ans[i];
		}

		cout << max << endl;
	}

	return 0;
}