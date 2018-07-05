/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

vi a;
vii factors_k;
vi primes_count_array;

void factorize(int k){
	int n = sqrt(k);
	vi is_prime = vi(n + 1, 1);

	//sieve of eratosthenes
	is_prime[0] = is_prime[1] = 0;
	for(int i = 2; i * i <= n; i++){
		if(is_prime[i]){
			for(int j = i + i; j <= n; j += i)
				is_prime[j] = 0;
		}
	}

	//factorize
	for(int i = 2; i <= n; i++){
		if(!is_prime[i])
			continue;
		int count = 0;
		while(k % i == 0){
			count++;
			k /= i;
		}
		if(count != 0)
			factors_k.push_back(make_pair(i, count));
	}

	if(k != 1){
		//factor greater than sqrt remains
		factors_k.push_back(make_pair(k, 1));
	}
}

bool is_divisible_check(vi &a, int k){
	
	//check if divisible
	int n = factors_k.size();
	bool is_divisible = true;

	for(int i = 0; i < n; i++){
		if(a[i] < factors_k[i].second){
			is_divisible = false;
			break;
		}
	}

	return is_divisible;
}

bool is_divisible_remove(int lo, int k, bool should_remove){

	int num_factors_k = factors_k.size();
	vi copy_count_arr = vi(primes_count_array);

	for(int i = 0; i < num_factors_k; i++){
		int temp = a[lo];

		int count = 0;
		while(temp % factors_k[i].first == 0){
			count++;
			temp /= factors_k[i].first;
		}

		if(count != 0)
			copy_count_arr[i] -= count;
	}

	if(should_remove)
		primes_count_array = copy_count_arr;

	return is_divisible_check(copy_count_arr, k);
}

bool is_divisible_add(int hi, int k, bool should_remove){
	
	int num_factors_k = factors_k.size();
	vi copy_count_arr = vi(primes_count_array);

	for(int i = 0; i < num_factors_k; i++){
		int temp = a[hi];

		int count = 0;
		while(temp % factors_k[i].first == 0){
			count++;
			temp /= factors_k[i].first;
		}

		if(count != 0){
			
			// if(should_remove)
			// cout << "cnt hi=" << hi << " prime=" << factors_k[i].first << " count=" << count << endl;
			
			copy_count_arr[i] += count;
		}
	}

	if(should_remove)
		primes_count_array = copy_count_arr;

	return is_divisible_check(copy_count_arr, k);

}

int main(){

	int n, k;
	cin >> n >> k;

	a = vi(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	//factorize k
	factors_k = vii();
	factorize(k);

	int num_factors_k = factors_k.size();
	primes_count_array = vi(num_factors_k, 0);

	ll ans = 0;

	// cout << "factors" << endl;
	// for(ii& p : factors_k)
	// 	cout << p.first << " " << p.second << endl;
	// cout << "---" << endl;

	if(k == 1){
		ans = ((ll) n) * (n + 1) / 2;
		cout << ans;
		return 0;
	}

	//two-pointer mechanism
	int lo = 1;
	int hi = 1;
	while(hi <= n && !is_divisible_add(hi, k, false)){
		is_divisible_add(hi, k, true);
		hi++;
	}
	if(hi <= n)
		is_divisible_add(hi, k, true);
	else{
		cout << "0";
		return 0;
	}

	// cout << lo << " " << hi << endl;

	// cout << "primes count array" << endl;
	// for(int x : primes_count_array)
	// 	cout << x << endl;
	// cout << endl;

	ans += ( ( (ll)1 ) * (n - hi + 1));

	while(hi < n){

		while(lo <= hi && is_divisible_remove(lo, k, false)){
			is_divisible_remove(lo, k, true);
			lo++;
		}
		is_divisible_remove(lo, k, true);
		lo++;

		hi++;
		while(hi <= n && !is_divisible_add(hi, k, false)){
			is_divisible_add(hi, k, true);
			hi++;
		}
		if(hi <= n)
			is_divisible_add(hi, k, true);
		else
			break;

		ans += ( ( (ll)1 ) * (n - hi + 1));
	}
	
	cout << ans << endl;

	return 0;
}