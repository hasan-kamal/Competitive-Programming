#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;

typedef vector<int> 	vi;
typedef vector<vi>		vvi;
typedef long long int 	ll;
typedef set<int> si;

vi primes;
vi is_prime;

void sieve(){
	int N = 1000005;
	is_prime = vi(N, 1);
	is_prime[0] = is_prime[1] = 0;
	for(ll i = 2; i < N; i++){
		if(!is_prime[i])
			continue;
		for(ll j = i * i; j < N; j += i)
			is_prime[j] = 0;
	}

	for(ll i = 0; i < N; i++)
		if(is_prime[i])
			primes.push_back(i);
}

int num_div(ll x){
	int ans = 0;
	for(int i = 1; i <= x; i++)
		if(x % i == 0)
			ans++;
	return ans;
}

si pf_(int a){
	// cout << "HAHA " << a << endl;
	si prms;
	for(int pr : primes)
		if(a % pr == 0){
			// cout << "dfd " << pr << endl;
			prms.insert(pr);
		}
	return prms;
}

int p(int a, int p){
	int ans = 0;
	while(a % p == 0){
		a /= p;
		ans++;
	}
	return ans;
}

// num divisors of product a * b
ll num_div_2(int a, int b){
	si pf_a = pf_(a);
	si pf_b = pf_(b);

	for(si::iterator it = pf_a.begin(); it != pf_a.end(); it++){
		pf_b.insert(*it);
		// cout << *it << " dfd" << endl;
	}

	vi x;
	for(si::iterator it = pf_b.begin(); it != pf_b.end(); it++){
		int prime = *it;
		x.push_back(p(a, prime) + p(b, prime));
	}

	ll ans = 1;
	for(int y : x)
		ans = ans * (y + 1);
	return ans;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	sieve();
	// for(int i = 0; i < 10; i++)
	// 	cout << primes[i] << endl;

	int t;
	cin >> t;

	int n;
	while(t--){
		cin >> n;
		vi a(n);
		int largest = -1;
		int smallest = INT_MAX;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(a[i] > largest)
				largest = a[i];
			if(smallest > a[i])
				smallest = a[i];
		}

		int ans = 2 * largest;
		int over = 0;
		for(int i = 0; i < n; i++){
			if(ans % a[i] != 0){
				over = 1;
				break;
			}
		}

		// if even
		if(!over && n == num_div(ans) - 2){
			cout << ans << endl;
			continue;
		}

		// must be odd
		over = 0;
		for(int i = 0; i < n; i++){
			if(a[i] % 2 == 0){
				cout << -1 << endl;
				over = 1;
				break;
			}
		}
		if(over)
			continue;

		// all divisors are odd
		ll ans2 = ((ll)smallest) * largest;
		over = 0;
		for(int i = 0; i < n; i++){
			if(ans2 % a[i] != 0){
				over = 1;
				break;
			}
		}
		if(over){
			cout << -1 << endl;
			continue;
		}
		// cout << ans2 << " " << num_div_2(smallest, largest) << endl;
		if(n == num_div_2(smallest, largest) - 2){
			cout << ans2 << endl;
		}else{
			cout << -1 << endl;
		}
	}	

	return 0;
}