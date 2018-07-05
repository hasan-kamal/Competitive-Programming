/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

vll primes;

void generate_prime(ll limit){
	vll is_prime = vll(limit + 1, 1);
	is_prime[0] = is_prime[1] = 0;
	for(ll i = 2; i * i <= limit; i++){
		if(is_prime[i] == 0)
			continue;
		for(ll j = i * i; j <= limit; j += i){
			is_prime[j] = 0;
		}
	}

	primes = vll();
	for(ll i = 2; i <= limit; i++){
		if(is_prime[i])
			primes.pb(i);
	}
}

ll pow(ll base, ll exp){
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;

	ll temp = pow(base, exp / 2);
	if(exp % 2 == 0)
		return temp * temp;
	else
		return temp * temp * base;
}

ll get_extra_factor(ll x){
	for(ll &p : primes){
		if(x % p != 0)
			continue;
		int count = 0;
		while(x % p == 0){
			count++;
			x /= p;
		}
	}
	return x;
}

bool decompose(ll a, ll b){

	ll p1 = get_extra_factor(a);
	ll p2 = get_extra_factor(b);

	int num_added = 0;
	if(p1 > 1){
		primes.pb(p1);
		num_added++;
	}
	if(p2 > 1){
		primes.pb(p2);
		num_added++;
	}

	bool ans = true;
	
	for(ll &p : primes){
		if((a % p != 0) && (b % p != 0))
			continue;

		if((a % p != 0) && (b % p == 0)){
			ans = false;
			break;
		}

		if((a % p == 0) && (b % p != 0)){
			ans = false;
			break;
		}

		int count1 = 0;
		while(a % p == 0){
			count1++;
			a /= p;
		}

		int count2 = 0;
		while(b % p == 0){
			count2++;
			b /= p;
		}

		ll alpha = 2 * count1 - count2;
		if(alpha < 0 || (alpha % 3 != 0)){
			ans = false;
			break;
		}

		ll beta = 2 * count2 - count1;
		if(beta < 0 || (beta % 3 != 0)){
			ans = false;
			break;
		}
	}

	while(num_added--){
		primes.pop_back();
	}

	return ans;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	const int m = 32000;
	generate_prime(m);

	ll n;
	cin >> n;

	while(n--){
		ll a, b;
		cin >> a >> b;
		
		if(decompose(a, b)){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}

	return 0;
}