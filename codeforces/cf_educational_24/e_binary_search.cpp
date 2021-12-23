/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

vi a;
vii factors;
int num_factors;
vvi table;

void factorise(int num){
	const int upper = sqrt(num) + 1;

	//sieve of eratosthenes
	vi is_prime = vi(upper, 1);
	is_prime[0] = is_prime[1] = 0;

	for(int i = 2; i * i <= upper; i++){
		if(!is_prime[i])
			continue;
		for(int j = i + i; j <= upper; j += i)
			is_prime[j] = 0;
	}

	//factorise num
	for(int i = 2; i <= upper; i++){
		if(!is_prime[i])
			continue;
		int cnt = 0;
		while(num % i == 0){
			cnt++;
			num /= i;
		}
		if(cnt != 0)
			factors.push_back(make_pair(i, cnt));
	}

	if(num != 1){
		//prime greater than square-root remains
		factors.push_back(make_pair(num, 1));
	}
}

void store_count(int index){
	//for all factors of k, see if they divide a[index]
	//and store corresponding count in table[index]
	//and prepare running sums alongside in table
	for(int i = 0; i < num_factors; i++){
		int factor = factors[i].first;

		int cnt = 0, temp = a[index];
		while(temp % factor == 0){
			cnt++;
			temp /= factor;
		}

		table[index][i] = cnt;
	}

	//store cumulative sums
	if(index > 1){
		for(int i = 0; i < num_factors; i++){
			table[index][i] += table[index - 1][i];
		}
	}
}

bool check_divisible(int start, int index){
		
	for(int i = 0; i < num_factors; i++){
		if(table[index][i] - table[start - 1][i] < factors[i].second)
			return false;
	}
	return true;

}

int bsearch_index(int start, int end){
	//remember to return return n + 1 if not found
	
	int lo = start, hi = end;
	int mid;
	while(lo < hi){
		mid = lo + (hi - lo) / 2;
		if(check_divisible(start, mid))
			hi = mid;
		else
			lo = mid + 1;
	}

	if(check_divisible(start, lo))
		return lo;
	else
		return end + 1;

}

int main(){

	int n, k;
	cin >> n >> k;

	a = vi(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	factors = vii();
	factorise(k);
	num_factors = factors.size();

	table = vvi(n + 1, vi(num_factors, 0));
	for(int i = 1; i <= n; i++){
		store_count(i);
	}

	ll ans = 0;
	for(int l = 1; l <= n; l++){
		int r = bsearch_index(l, n);

		if(r <= n){
			ans += (n - r + 1);
		}

	}

	cout << ans << endl;

	return 0;
}