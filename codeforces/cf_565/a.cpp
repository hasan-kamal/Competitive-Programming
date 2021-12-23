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

	int q;
	cin >> q;

	ll n;
	while(q--){
		cin >> n;
		int ans = 0;
		while(n % 3 == 0){
			n = (2 * n) / 3;
			ans++;
		}
		while(n % 5 == 0){
			n = (4 * n) / 5;
			ans++;
		}
		while(n % 2 == 0){
			n = n / 2;
			ans++;
		}
		if(n != 1){
			cout << "-1" << endl;
		}else{
			cout << ans << endl;
		}
	}

	return 0;
}