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

	ll q;
	cin >> q;

	ll k, n, a, b;
	while(q--){
		cin >> k >> n >> a >> b;
		if(k - n * b <= 0){
			cout << -1 << endl;
			continue;
		}

		ll ans;
		if((k - n * b) % (a - b) == 0)
			ans = ((k - n * b) / (a - b)) - 1;
		else
			ans = ((k - n * b) / (a - b));
		cout << min(ans, n) << endl;
	}		

	return 0;
}