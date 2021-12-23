#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

typedef vector<int>			vi;
typedef vector<vi>			vvi;
typedef vector<vvi>			vvvi;
typedef long long int 		ll;
typedef vector<ll>			vll;
typedef vector<vll>			vvll;
typedef vector<vvll>		vvvll;

typedef pair<int, int>		ii;
typedef vector<ii>			vii;
typedef set<int> 			si;


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a(n + 1, 0);
	vi is_prime(n + 1, 1);
	int counter = 0;
	for(ll i = 2; i <= n; i++){
		if(!is_prime[i])
			continue;
		counter++;
		a[i] = counter;
		for(ll j = i * i; j <= n; j += i){
			is_prime[j] = 0;
			if(a[j] == 0)
				a[j] = counter;
		}
	}

	for(int i = 2; i <= n; i++)
		cout << a[i] << " ";

	return 0;
}